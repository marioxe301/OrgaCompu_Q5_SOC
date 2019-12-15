/* verilator lint_off UNUSED */
module MIPS32SOC (
    input clk, // Clock signal
    input resetIn,  // Reset signal
    input [7:0]keypadIn,
    output [2:0]red,
    output [2:0]green,
    output [1:0]blue,
    output hsync,
    output vsync,
    output invalidPC,
    output invalidOpcode,
    output invalidAddr
);
    wire reset;
    wire [7:0]keypad;
    `ifdef SYNTHESIS
        assign reset = ~resetIn;
        assign keypad = ~keypadIn;
    `else
        assign reset = resetIn;
        assign keypad = keypadIn;
    `endif


    wire [31:0] inst /*verilator public*/;
    reg  [31:0] nextPC; // Should be 'reg' because it used in a always block
    reg  [31:0] PC /*verilator public*/; // The PC (Program Counter) register
    wire [31:0] pcPlus4;
    wire [5:0] func;
    wire [4:0] shiftam /*verilator public*/;
    wire [4:0] rd /*verilator public*/;
    wire [4:0] rt /*verilator public*/;
    wire [4:0] rs /*verilator public*/;
    wire [5:0] opcode;
    wire [1:0]aluSrc; // cambia de 2 bits, es 0 si viene de RD2, es 1 si viene del immediate32 y 2 si es una constante 
    wire rfWriteEnable; // Register File Write Enable
    wire rfWriteAddrSel; // Register File Write Address Select
    wire [1:0] rfWriteDataSel; // Register File Write Data Select
    wire [4:0] rfWriteAddr; // Register File Write Address
    reg  [31:0] rfWriteData; // Register File Write Data
    wire [31:0] rfData1 /*verilator public*/;
    wire [31:0] rfData2 /*verilator public*/;
    wire [31:0] imm32;
    wire [15:0] imm16;
    wire [31:0] memAddr; // cambio a 13 bits
    wire memWrite /*verilator public*/; // cambio a 1 bits
    wire memRead;
    wire [31:0] memData;
    wire [3:0] aluFunc; // cambio a 4 bits
    reg [31:0] aluOperand2;
    wire [31:0] aluResult /*verilator public*/;
    wire [31:0] branchTargetAddr;
    wire [31:0] jmpTarget32;
    wire isJmp /*verilator public*/;
    wire [2:0]wireBranch /*verilator public*/ ;
    wire isBranch /*verilator public*/; 
    wire isZero /*verilator public*/;
    wire bitXtend;
    
    //wire invalidOpcode /*verilator public*/;

    //nuevos wires
    wire rfLuiSelector;
    wire [31:0]rfWriteData2;
    wire [31:0]luiValue;

    //nuevas conexiones
    wire [31:0] phyAddrPc; // cambio
    
    //wire invalidPC /*verilator public*/;

    //wire invalidAddr /*verilator public*/;

    wire [2:0]wireMemEn /*verilator public*/;
    wire [1:0]wireMemBank;
    wire [31:0]wireOutDataEncoder;
    wire [3:0]wireEncMW;
    wire [1:0] wireDataSize;
    wire wireMemBitExtend;
    wire [31:0]wireReadDataMem;
    wire [31:0]wireOutDataReadMem;
    wire [31:0]wireReadDataVGA;

 

    wire [31:0]MuxDataReadSelect;
    wire [31:0]shiftam32;
    wire [31:0]aluRD1;
    wire isShift;
    wire isJal;
    wire isJr;
    wire [4:0]rfWriteAddrJal;
    wire ResetEnable;

    assign ResetEnable  = reset ? 1'b0 : rfWriteEnable;
   
  
    assign func = inst[5:0];
    assign rd = inst[15:11];
    assign rt = inst[20:16];
    assign rs = inst[25:21];
    assign opcode = inst[31:26];
    assign imm16 = inst[15:0];
    assign shiftam = inst[10:6]; // es la cantidad de shift que se le hara


    assign shiftam32 = {27'b0,shiftam};

    //modificado y cambiado a 11 bits
    //assign memAddr = aluResult[9:2];

    assign pcPlus4 = PC + 32'd4;
    assign jmpTarget32 = {pcPlus4[31:28], inst[25:0], 2'b00}; // los 26 bits se toman y se multiplica con 4 sll y se rellena con 4 bits del pc + 4
    assign branchTargetAddr = pcPlus4 + {imm32[29:0], 2'b00}; // se agarra el opset y se le suma el pc + 4
     

    assign rfWriteAddr = rfWriteAddrSel? rd : rt; // MUX
    // segundo mux por si es jal;
    assign rfWriteAddrJal = isJal ? 5'd31 : rfWriteAddr;
    
    // intercambio de RD1 debido al shift amount
    assign aluRD1 = isShift ? shiftam32 : rfData1;

    //Mux para determinar el operando de la alu
    always @(*) begin
        case (aluSrc)
            2'b0: aluOperand2 = rfData2;
            2'b1: aluOperand2 = imm32;
            2'b10: aluOperand2 = 32'b0; // constante para branches que hacen comparacion con zero
            default: aluOperand2 = 32'bx;
        endcase
    end

    assign MuxDataReadSelect = (wireMemBank == 2'b0) ? wireReadDataMem: 
                               (wireMemBank == 2'b1) ? wireReadDataVGA: 
                               (wireMemBank == 2'b10) ? IOdata : 32'b0; 

    assign rfWriteData = (rfWriteDataSel == 2'b0) ? aluResult :
                         (rfWriteDataSel == 2'b1) ? wireOutDataReadMem : pcPlus4 ; // MUX

    //nuevos assigns
    //lui assign
    assign luiValue = {imm16,16'b0};

    assign rfWriteData2 = rfLuiSelector ? luiValue : rfWriteData;
    // nextPcprime
    reg[31:0]nextPCpm;


    // Next PC value
    always @ (*) begin
        if(isJmp || isJal )
            nextPCpm = jmpTarget32;
        else if( isBranch )
            nextPCpm = branchTargetAddr;
        else if( isJr )
            nextPCpm = rfData1;
        else
            nextPCpm = pcPlus4;
    end
    
    always @(*) begin
        if(reset)
            nextPC = 32'h00400000; 
        else
            nextPC = nextPCpm;
    end

    // PC
    always @ (posedge clkInstMem) begin
        if (reset)
            PC <= 32'h00400000; // posicion inicial = 32'h00400000 posicion final = 32'h00400FFF 
        else if(invalidOpcode || invalidAddr || invalidPC)
            PC <= PC;
        else
            PC <= nextPC;
    end
    // PC Decoder
    PCDecoder pcdec (
        .virtualPC( nextPC ), // 32 bits
        .physicalPC( phyAddrPc ), // 32 bits
        .invalidPC( invalidPC ) // 1 bit
    );

    // Instruction Memory
    InstMemory instMem (
        .clk( clkInstMem ),
        .addr( phyAddrPc[12:2]), //PC[12:2]
        .en( 1'b1 ),
        .rdata( inst )
    );

    //Memory Decoder
    MemDecoder memdec(
        .virtualAddr( aluResult ), // 32 bits
        .memWrite( memWrite),
        .memRead( memRead),
        .physicalAddr( memAddr ), // 32 bits
        .memEnable( wireMemEn ), // 3 bits
        .memBank( wireMemBank ), // 2 bits y se usa en un mux
        .invalidAddr( invalidAddr )  // 1 bit
    );

    //MemWriteEncoder
    MemWriteDataEncoder mwde(
        .inData( rfData2 ),
        .ofsset(  aluResult[1:0]  ), // los ultimos 2 bits del address
        .memWrite ( memWrite ),
        .dataSize( wireDataSize ), // nueva señal del control unit
        .outData( wireOutDataEncoder ),
        .encMW( wireEncMW )
    );

    // Data Memory
    DataMem dataMem (
        .en( wireMemEn[0] ), // si es memoria
        .addr( memAddr[12:2] ), // se descartan los dos menos significativos
        .wdata( wireOutDataEncoder ),
        .memWrite( wireEncMW ),
        .clk( clkDataMem ), // clk
        .rdata (  wireReadDataMem /*memData*/)
    );

    //vga memory
    VGATextCard vgaTextCard(
        .vclk(clkVGA ),
        .clk( clkDataMem ),
        .reset( reset ),
        .en( wireMemEn[1]),
        .memWrite( wireEncMW ),
        .addr( memAddr[12:2] ),
        .wdata( wireOutDataEncoder ),
        .rdata( wireReadDataVGA ),
        .red( red ),
        .green( green ),
        .blue( blue ),
        .hsync( hsync ),
        .vsync( vsync )
    );

    //MemReadDataDecoder
    MemReadDataDecoder mrdd (
        .inData( MuxDataReadSelect ),
        .ofsset( aluResult[1:0] ),
        .dataSize( wireDataSize ),
        .bitExt( wireMemBitExtend ),
        .outData( wireOutDataReadMem )
    );

    //Register File
    RegisterFile regFile (
        .ra1( rs ),
        .ra2( rt ),
        .wa( rfWriteAddrJal ),
        .wd( rfWriteData2 ),
        .we( ResetEnable ),
        .clk( clkInstMem ),
        .rd1( rfData1 ),
        .rd2( rfData2 )
    );

  // ALU
  ALU alu (
    .a( aluRD1 ),
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
    .bgezOrbltz(rt[0]),
    .opc( opcode ),
    .func( func ),
    .isJmp( isJmp ),
    .branch( wireBranch ),
    .rfWriteDataSel( rfWriteDataSel ),
    .rfWriteAddrSel( rfWriteAddrSel ),
    .rfWriteEnable( rfWriteEnable ),
    .memWrite( memWrite ),
    .memRead( memRead ),
    .aluSrc( aluSrc ),    
    .aluFunc( aluFunc ),
    .bitXtend( bitXtend ),
    .invOpcode( invalidOpcode ),
    .rfLuiSel( rfLuiSelector ),
    .memDataSize( wireDataSize ),
    .memBitExtend( wireMemBitExtend ),
    .isShift( isShift ),
    .isJal( isJal ),
    .isJr( isJr )
  );

  BranchResolver bres( 
      .branch( wireBranch ), // input 3 bits Control unit
      .zero( isZero ), // viene del alu
      .sign( rfData1[31] ), // viene del rd1 
      .branchTaken( isBranch ) // salida para el if
  );
  
  wire clkDataMem,clkInstMem,clkVGA;
  wire [31:0]msCount;
  wire [31:0]IOdata;
    
  ClockGenerator clkgen(
      .clkIn( clk ),
      .fastClk( clkDataMem ),
      .vgaClk( clkVGA ),
      .slowClk( clkInstMem )
  );

  MillisCounter mlls (
      .clk( clkDataMem ),
      .reset( reset ),
      .counter( msCount )
  );

  IOmemory memIO(
      .keypad( keypad ),
      .msCount( msCount ),
      .en( wireMemEn[2] ),
      .addr( memAddr[12:2] ),
      .outputIO( IOdata )
  );

endmodule
