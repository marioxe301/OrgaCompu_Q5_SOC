module MemoryDecoder(
    input [31:0] virtualAddr,
    output reg [10:0] physicalAddr,
    output reg invalidAddr
);  
    wire [31:0]TempValueGlobalP;
    wire [31:0]TempValueStackP;

    assign TempValueGlobalP = virtualAddr >> 2;
    assign TempValueStackP = virtualAddr >> 2;

    //global pointer address = 0x10010000 hasta 0x10010FFF  0 a 1023 se toman 12 bits los 12 primeros
    //stack pointer address =  0x7FFFF000 hasta 0x7FFFFFFF 1024 a 2047 
    
    always@(*)begin
        if( virtualAddr >= 32'h10010000 && virtualAddr <= 32'h10010FFF ) begin
                physicalAddr =  TempValueGlobalP[10:0];
                invalidAddr = 1'b0;
        end else if (virtualAddr >= 32'h7FFFF000 &&  virtualAddr <= 32'h7FFFFFFF) begin
                physicalAddr = TempValueStackP[10:0];
                invalidAddr = 1'b0;
        end else begin
                invalidAddr = 1'b1;
        end
    end



endmodule