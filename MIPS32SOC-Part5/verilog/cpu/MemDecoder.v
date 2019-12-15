module MemDecoder(
    input [31:0] virtualAddr, // señal de la alu
    input memWrite, //señales del control unit
    input memRead, // señal del control unit
    output reg [31:0] physicalAddr, // salida para el Data memory
    output reg [2:0]memEnable, // seleciona el enable del vga o IO o Datamemory
    output reg [1:0]memBank, // se utiliza en un mux
    output reg invalidAddr // se utiliza para error
    
); 
    wire [31:0]StackTmp,VGATmp,IOTmp;

    assign StackTmp = virtualAddr- 32'h7FFFEFFC;
    assign VGATmp = virtualAddr - 32'h0000B800;
    assign IOTmp = virtualAddr - 32'hFFFF0000;

    //global pointer address = 0x10010000 hasta 0x10010FFF  0 a 1023 se toman 12 bits los 12 primeros
    //stack pointer address =  0x7FFFF000 hasta 0x7FFFFFFF 1024 a 2047 
    
    always@(*)begin
        physicalAddr = 32'b0;
        memEnable = 3'b000;
        memBank = 2'b00;
        invalidAddr = 1'b0;

        if(memWrite || memRead )begin
            // global
            if(virtualAddr >= 32'h10010000 && virtualAddr <= 32'h10010FFF)begin
                physicalAddr = virtualAddr;
                memEnable = 3'b001;
                memBank = 2'b00;
                invalidAddr = 1'b0;
            //stack
            end else if( virtualAddr >= 32'h7FFFEFFC && virtualAddr <= 32'h7FFFFFFB )begin
                physicalAddr = StackTmp + 32'd4096;
                memEnable = 3'b001;
                memBank = 2'b00;
                invalidAddr = 1'b0;
            //vga
            end else if( virtualAddr >= 32'h0000B800 && virtualAddr <= 32'h0000CACF)begin
                physicalAddr = VGATmp;
                memEnable = 3'b010;
                memBank = 2'b01;
                invalidAddr = 1'b0;
            //IO
            end else if(virtualAddr >= 32'hFFFF0000 && virtualAddr <=32'hFFFF000C)begin
                physicalAddr = IOTmp;
                memEnable = 3'b100;
                memBank = 2'b10;
                invalidAddr = 1'b0;
            end else begin
                invalidAddr = 1'b1;
                memEnable = 3'b0;
            end

        end else begin
            invalidAddr = 1'b0;
            memEnable = 3'b0;
        end
    end



endmodule