module PCDecoder (
    input [31:0]virtualPC,
    output [9:0]physicalPC,
    output [0:0]invalidPC
);
    wire [9:0] tempPC;

    //cable temporal
    assign tempPC = virtualPC[9:0] >> 2;

    //descartar los 2 bits mas significativos
    assign physicalPC = tempPC; // daria la direccion fisica de la direccion virtual
    assign invalidPC = ( virtualPC < 32'h00400000 || virtualPC > 32'h00400FFF ) ; // daria el error si es una direccion invalida

endmodule
