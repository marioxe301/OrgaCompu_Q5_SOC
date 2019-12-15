#include <cstdio>
#include <iostream>
#include <verilated.h>
#include "VGATextWindow.h"

#ifdef USE_ACTIVE_LOW_KEYS

inline void setKey(uint8_t& keyst, uint8_t pos) {
    keyst &= ~(1u << pos);
}

inline void unsetKey(uint8_t& keyst, uint8_t pos) {
    keyst |= (1u << pos);
}

#else

inline void setKey(uint8_t& keyst, uint8_t pos) {
    keyst |= (1u << pos);
}

inline void unsetKey(uint8_t& keyst, uint8_t pos) {
    keyst &= (~(1u << pos));
}

#endif

void VGAFontSymbol::loadFromBitmap(const uint8_t *arr) {
    int point_y = 0;

    for (int i = 0; i < SYMB_HEIGHT; i++) {
        uint8_t line_data = *arr;
        uint8_t mask = 1 << ROW_MSB;

        int point_x = 0;
        for (int j = 0; j < SYMB_WIDTH; j++) {
            if ((line_data & mask) != 0) {
                points.emplace_back(point_x, point_y);
            }            
            point_x ++;
            mask >>= 1;
        }
        arr += BYTES_PER_ROW;
        point_y++;
    }    
}

void VGAFontSymbol::draw(SDL_Renderer *renderer, int x, int y, const VGAColor &fc, const VGAColor &bc) const {
    SDL_Rect r;

    r.x = x; r.y = y; r.w = SYMB_WIDTH; r.h = SYMB_HEIGHT;
    SDL_SetRenderDrawColor(renderer, bc.red, bc.green, bc.blue, 255);
    SDL_RenderFillRect(renderer, &r);
    if (points.size() > 0) {
        std::vector<SDL_Point> spoints(points.size());

        for (int i = 0; i < points.size(); i++) {
            spoints[i].x = x + points[i].first;
            spoints[i].y = y + points[i].second;
        }
        SDL_SetRenderDrawColor(renderer, fc.red, fc.green, fc.blue, 255);
        SDL_RenderDrawPoints(renderer, spoints.data(), points.size());
    }
}

void VGAColorPalette::loadFromRomData(uint8_t romColors[], int count) {
    colors.resize(count);

    for (int i = 0; i < count; i++) {
        colors[i] = romColors[i];
    }
}

void VGAFont::loadFromRomData(const uint8_t romData[], size_t symbSizeBytes, int count) {
    symbols.resize(count);

    for (int i = 0; i < count; i++) {
        const uint8_t *symbBmp = &romData[i * symbSizeBytes];
        symbols[i].loadFromBitmap(symbBmp);
    }
}

VGATextWindow::~VGATextWindow() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

bool VGATextWindow::initDisplay(uint32_t *vgafb, uint8_t *vgarom, uint8_t *vgapal) {

    int res = SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window, &renderer);
    if (res < 0) {
        std::cerr << "Could not create window: '" << SDL_GetError() << "\n";
        return false;        
    }
    SDL_SetWindowTitle(window, "VGA Display 80x30");

    this->vgafb = vgafb;

    vgaPal.loadFromRomData(vgapal, VGA_NUM_COLORS);
    vgaFontSymbs.loadFromRomData(vgarom, SYMB_SIZE_BYTES, VGA_NUM_SYMBOLS);

    return true;
}

void VGATextWindow::drawVGASymbol(int row, int col, uint16_t symb) {
    int index = (uint8_t)(symb & 0xff);
    uint8_t fgi = (symb & 0x0f00) >> 8;
    uint8_t bgi = (symb & 0xf000) >> 12;

    VGAColor fc = vgaPal[fgi];
    VGAColor bc = vgaPal[bgi];
    const VGAFontSymbol& s = vgaFontSymbs[index];

    s.draw(renderer, col * SYMB_WIDTH, row * SYMB_HEIGHT, fc, bc);
}

void VGATextWindow::drawVGAContent() {
    if (vgaFontSymbs.size() == 0 || vgafb == nullptr) {
        return;
    }

    uint32_t *pvga = vgafb;
    
    for (int row = 0; (row < VGA_ROWS) && repainting; row++) {
        int col = 0;

        while ((col < VGA_COLS) && repainting) {
            drawVGASymbol(row, col, *pvga >> 16);
            col++;
            drawVGASymbol(row, col, *pvga & 0xffff);
            col++;
            pvga++;
        }
    }
}

void VGATextWindow::postRepaintEvent() {
    SDL_Event e;
    e.type = SDL_WINDOWEVENT;
    e.window.event = SDL_WINDOWEVENT_EXPOSED;
    e.window.windowID = SDL_GetWindowID(window);
    SDL_PushEvent(&e);
}

bool VGATextWindow::isRepainting() { 
    return repainting; 
}

void VGATextWindow::redraw() {
    repainting = true;
    drawVGAContent();

    if (repainting) {
        SDL_RenderPresent(renderer);
        repainting = false;
    }
}

void VGATextWindow::saveScreenshot(const char *filename) {
    SDL_Surface *pScreenShot;

    pScreenShot = SDL_CreateRGBSurface(0, width, height, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

    if(pScreenShot != nullptr) {
        SDL_RenderReadPixels(renderer, nullptr, SDL_GetWindowPixelFormat(window), pScreenShot->pixels, pScreenShot->pitch);
        SDL_SaveBMP(pScreenShot, filename);
        SDL_FreeSurface(pScreenShot);
    }
}

void VGATextWindow::run() {
    bool running = true;
    SDL_Event e;

    while (running) {
        SDL_WaitEvent(&e);

        switch (e.type) {
            case SDL_QUIT:
                Verilated::gotFinish(true);
                running = false;
                break;
            case SDL_WINDOWEVENT:
                if (e.window.event == SDL_WINDOWEVENT_EXPOSED) {
                    redraw();
                }
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT: setKey(keypadStateMap, 0); break;
                    case SDLK_RIGHT:setKey(keypadStateMap, 1); break;
                    case SDLK_DOWN: setKey(keypadStateMap, 2); break;
                    case SDLK_UP: setKey(keypadStateMap, 3); break;
                    case SDLK_p: setKey(keypadStateMap, 5); break;
                    case SDLK_q: setKey(keypadStateMap, 4); break;
                    case SDLK_r: resetKeyState = KeyState::Pressed; break;
                    case SDLK_s: stopKeyState = KeyState::Pressed; break;
                    case SDLK_b: setKey(keypadStateMap, 6); break;
                    case SDLK_SPACE:setKey(keypadStateMap, 7); break;
                }
                break;
            case SDL_KEYUP:
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT: unsetKey(keypadStateMap, 0); break;
                    case SDLK_RIGHT:unsetKey(keypadStateMap, 1); break;
                    case SDLK_DOWN: unsetKey(keypadStateMap, 2); break;
                    case SDLK_UP: unsetKey(keypadStateMap, 3); break;
                    case SDLK_p: unsetKey(keypadStateMap, 5); break;
                    case SDLK_q: unsetKey(keypadStateMap, 4); break;
                    case SDLK_r: resetKeyState = KeyState::Released; break;
                    case SDLK_s: stopKeyState = KeyState::Released; break;
                    case SDLK_b: unsetKey(keypadStateMap, 6); break;
                    case SDLK_SPACE: unsetKey(keypadStateMap, 7); break;
                }
                break;
        }
    }
}