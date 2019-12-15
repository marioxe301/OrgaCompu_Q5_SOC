#ifndef _VGA_DISPLAY_H

#define _VGA_DISPLAY_H

#include <cstdint>
#include <vector>
#include <SDL.h>

#define SYMB_WIDTH      8
#define SYMB_HEIGHT     16
#define SYMB_SIZE_BYTES ((BYTES_PER_ROW) * (SYMB_HEIGHT))
#define BYTES_PER_ROW   ((SYMB_WIDTH + 7) / 8)
#define ROW_MSB         7
#define VGA_COLS        80
#define VGA_ROWS        30
#define VGA_NUM_COLORS  16
#define VGA_NUM_SYMBOLS 256

enum class KeyState {
    Pressed,
    Released
};

class VGAColor {
public:
    VGAColor() {}
    VGAColor(const VGAColor& other) { setFromVGAColor(other); }
    VGAColor(uint8_t color) { setFromColor(color); }

    VGAColor& operator=(const VGAColor& rhs) {
        setFromVGAColor(rhs);
        return *this;
    }

    VGAColor& operator=(uint8_t color) { setFromColor(color); return *this; }

private:
    void setFromVGAColor(const VGAColor& rhs) {
        red = rhs.red;
        green = rhs.green;
        blue = rhs.blue;
    }

    void setFromColor(uint8_t color) {
        red = color & 0xe0;
        green = (color & 0x1c) * 8;
        blue = (color & 0x03) * 64;
    }

public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class VGAColorPalette {
public:
    VGAColorPalette() {}
    VGAColorPalette(uint8_t romColors[], int count) { loadFromRomData(romColors, count); }

    void loadFromRomData(uint8_t romColors[], int count);

    VGAColor operator[](size_t index) {
        return colors[index];
    }

private:
    std::vector<VGAColor> colors;
};

class VGAFontSymbol {
public:
    using Point = std::pair<int, int>;
    
    VGAFontSymbol() {}
    VGAFontSymbol(const uint8_t *arr) { loadFromBitmap(arr); }

    void loadFromBitmap(const uint8_t *arr);
    void draw(SDL_Renderer *r, int x, int y, const VGAColor &fc, const VGAColor &bc) const;
    size_t getNumOfPoints() const { return points.size(); }

private:
    std::vector<Point> points;
};

// VGA Fixed Sized Font
class VGAFont {
public:
    VGAFont() {}

    void loadFromRomData(const uint8_t romData[], size_t symbSizeBytes, int count);

    const VGAFontSymbol& operator[](size_t index) {
        return symbols[index];
    }

    size_t size() { return symbols.size(); }

private:
    std::vector<VGAFontSymbol> symbols;
};

class VGATextWindow {
public:
    VGATextWindow(int width, int height):
        window(nullptr),
        renderer(nullptr),
        vgafb(nullptr),
        keypadStateMap(0),
        resetKeyState(KeyState::Released),
        stopKeyState(KeyState::Released),
        repainting(false),
        width(width),
        height(height) {}

    ~VGATextWindow();

    bool initDisplay(uint32_t *vgafb, uint8_t *vgarom, uint8_t *vgapal);
    void saveScreenshot(const char *filename);
    void redraw();
    void run();
    void postRepaintEvent();
    void stopRepaint() { repainting = false; }
    bool isRepainting();
    int getWidth() { return width; }
    int getHeight() { return height; }
    uint32_t *getVgaFb() { return vgafb; }
    uint8_t getKeypadState() { return keypadStateMap; }
    bool stopKeyPressed() { return (stopKeyState == KeyState::Pressed); }
    bool resetKeyPressed() { return (resetKeyState == KeyState::Pressed); }

private:
    void drawVGAContent();
    void drawVGASymbol(int row, int col, uint16_t symb);

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    VGAColorPalette vgaPal; // Color palette
    VGAFont vgaFontSymbs; // Fixed size VGA font
    uint32_t *vgafb;
    uint8_t keypadStateMap;
    KeyState resetKeyState;
    KeyState stopKeyState;
    bool repainting;
    int width, height;      // Screen resolution
};

#endif
