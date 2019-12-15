module InstMemory(
    input clk,
    input en,
    input [10:0] addr,
    output reg [31:0] rdata
    );

    reg [31:0] memory[0:2047] /*verilator public*/;

    //assign rdata = memory[addr];
    always @ (posedge clk)
    begin
        if (en)
            rdata <= memory[addr];
    end

    initial begin
`ifndef NO_INIT_MEM
        $readmemh("code.mif", memory, 0, 2047);
`endif
    end
endmodule
