module AsyncROM (
  input [9:0] addr, // solo ocuparemos los primeros 10 bits para la direccion
  input en,
  output [31:0] readData
);
  reg [31:0] memory[0:1023] /*verilator public*/;

  assign readData = en? memory[addr] : 32'hz;
  
  initial begin
`ifndef NO_INIT_MEM
    $readmemh("code.mif", memory, 0, 1023);
`endif
  end
endmodule 
 
