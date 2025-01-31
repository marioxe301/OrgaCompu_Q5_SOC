module DataMemory (
  input [10:0] addr, // 2^11 = 2048
  input [31:0] writeData,
  input memWrite,
  input clk,
  input memRead,
  output [31:0] readData
);
  reg [31:0] memory[0:2047] /*verilator public*/;

  assign readData = memRead? memory[addr] : 32'hz;

  always @ (posedge clk) begin
    if (memWrite)
      memory[addr] <= writeData;
  end

  initial begin
`ifndef NO_INIT_MEM
    $readmemh("data.mif", memory, 0, 2047); // 1024 para el global pointer y 1024 para el stack = 2048
`endif
  end
endmodule 
