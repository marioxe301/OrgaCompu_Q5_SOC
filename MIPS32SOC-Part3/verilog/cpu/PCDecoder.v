module PCDecoder (
    input [31:0]virtualPC,
    output [11:0]physicalPC,
    output [0:0]invalidPC
);
   
    //descartar los 2 bits mas significativos
    assign physicalPC = virtualPC[11:0]; // daria la direccion fisica de la direccion virtual
    assign invalidPC = ( virtualPC < 32'h00400000 || virtualPC > 32'h00400FFF ) ; // daria el error si es una direccion invalida

endmodule
