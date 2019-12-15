module PCDecoder (
    input [31:0]virtualPC,
    output [31:0]physicalPC,
    output [0:0]invalidPC
);
   
    //descartar los 2 bits mas significativos
    assign physicalPC = virtualPC; // daria la direccion fisica de la direccion virtual
    assign invalidPC = ( virtualPC < 32'h00400000 || virtualPC > 32'h00401FFF ) ; // daria el error si es una direccion invalida

endmodule
