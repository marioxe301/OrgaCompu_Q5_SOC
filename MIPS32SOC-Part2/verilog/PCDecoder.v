module PCDecoder (
    input [31:0]virtualPC,
    output [9:0]physicalPC,
    output invalidPC
);
    wire [31:0] tempPC;

    //cable temporal
    assign tempPC = virtualPC >> 2;

    //descartar los 2 bits mas significativos
    assign physicalPC = tempPC[9:0]; // daria la direccion fisica de la direccion virtual
    assign invalidPC = ~( virtualPC >= 32'h00400000 && virtualPC <= 32'h00400FFF ) ; // daria el error si es una direccion invalida

endmodule