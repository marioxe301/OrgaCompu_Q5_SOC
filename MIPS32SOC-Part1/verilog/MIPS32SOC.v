/* verilator lint_off UNUSED */
module MIPS32SOC (
    input clk, // Clock signal
    input rst  // Reset signal
);
    wire [31:0] inst /*verilator public*/;
    reg  [31:0] nextPC; // Should be 'reg' because it used in a always block
    reg  [31:0] PC /*verilator public*/; // The PC (Program Counter) register
    wire [31:0] pcPlus4;
    wire [5:0] func;
    wire [4:0] rd /*verilator public*/;
    wire [4:0] rt /*verilator public*/;
    wire [4:0] rs /*verilator public*/;
    wire [5:0] opcode;
    wire aluSrc;
    wire rfWriteEnable; // Register File Write Enable
    wire rfWriteAddrSel; // Register File Write Address Select
    wire [1:0] rfWriteDataSel; // Register File Write Data Select
    wire [4:0] rfWriteAddr; // Register File Write Address
    reg  [31:0] rfWriteData; // Register File Write Data
    wire [31:0] rfData1 /*verilator public*/;
    wire [31:0] rfData2 /*verilator public*/;
    wire [31:0] imm32;
    wire [15:0] imm16;
    wire [7:0] memAddr;
    wire memWrite;
    wire memRead;
    wire [31:0] memData;
    wire [2:0] aluFunc;
    wire [31:0] aluOperand2;
    wire [31:0] aluResult;
    wire [31:0] branchTargetAddr;
    wire [31:0] jmpTarget32;
    wire isJmp /*verilator public*/;
    wire isBeq /*verilator public*/;
    wire isBne /*verilator public*/;
    wire isZero /*verilator public*/;
    wire bitXtend;
    wire invalidOpcode /*verilator public*/;
  
    assign func = inst[5:0];
    assign rd = inst[15:11];
    assign rt = inst[20:16];
    assign rs = inst[25:21];
    assign opcode = inst[31:26];
    assign imm16 = inst[15:0];
    assign memAddr = aluResult[9:2];

    assign pcPlus4 = PC + 32'd4;
    assign jmpTarget32 = {pcPlus4[31:28], inst[25:0], 2'b00}; // los 26 bits se toman y se multiplica con 4 sll y se rellena con 4 bits del pc + 4
    assign branchTargetAddr = pcPlus4 + {imm32[29:0], 2'b00}; // se agarra el opset y se le suma el pc + 4 

    assign rfWriteAddr = rfWriteAddrSel? rd : rt; // MUX
    assign aluOperand2 = aluSrc? imm32 : rfData2; // MUX
    assign rfWriteData = rfWriteDataSel[0]? memData : aluResult; // MUX

    // Next PC value
    always @ (*) begin
        if(isJmp)
            nextPC = jmpTarget32;
        else if(isBeq && isZero)
            nextPC = branchTargetAddr;
        else if(isBne && !isZero)
            nextPC = branchTargetAddr;
        else
            nextPC =pcPlus4;
    end
  
    // PC
    always @ (posedge clk) begin
        if (rst)
            PC <= 32'd0;
        else
            PC <= nextPC;
    end
  
    // Instruction Memory
    InstMemory instMem (
        .addr( PC[9:2] ),
        .en( 1'b1 ),
        .readData( inst )
    );

    // Data Memory
    DataMemory dataMem (
        .addr( memAddr ),
        .writeData( rfData2 ),
        .memWrite( memWrite ),
        .clk( clk ),
        .memRead ( memRead ),
        .readData ( memData )
    );

    //Register File
    RegisterFile regFile (
        .ra1( rs ),
        .ra2( rt ),
        .wa( rfWriteAddr ),
        .wd( rfWriteData ),
        .we( rfWriteEnable ),
        .clk( clk ),
        .rd1( rfData1 ),
        .rd2( rfData2 )
    );

  // ALU
  ALU alu (
    .a( rfData1 ),
    .b( aluOperand2 ),
    .func( aluFunc ),
    .res( aluResult ),
    .isZero( isZero )
  );

  // BitExtender
  BitExtender BitExtender_i12 (
    .extend( bitXtend ),
    .in( imm16 ),
    .out( imm32 )
  );

  // Control Unit
  ControlUnit controlUnit (
    .opc( opcode ),
    .func( func ),
    .isJmp( isJmp ),
    .isBeq( isBeq ),
    .isBne( isBne ),
    .rfWriteDataSel( rfWriteDataSel ),
    .rfWriteAddrSel( rfWriteAddrSel ),
    .rfWriteEnable( rfWriteEnable ),
    .memWrite( memWrite ),
    .memRead( memRead ),
    .aluSrc( aluSrc ),    
    .aluFunc( aluFunc ),
    .bitXtend( bitXtend ),
    .invOpcode( invalidOpcode )
  );
endmodule
