`include "alu_defines.vh"
`include "opcodes.vh" 
`include "constants_defines.vh"

module ControlUnit(
    input bgezOrbltz, //señal que diferencia el BGEZ con BLTZ
    input [5:0] opc, //! Opcode
    input [5:0] func, //! Function
    output reg isJmp, //! Jump signal
    output reg [2:0]branch,
    output reg [1:0] rfWriteDataSel, //! Register File Write Data Select (Seleciona si lo que se va escribir viene del memory o del alu)
    output reg rfWriteAddrSel, //! Register File Write Address Select (Decide la direccion dependiendo de la instuccion)
    output reg rfLuiSel,
    output reg rfWriteEnable, //! Register Write Enable 
    output reg memWrite, //! Memory Write 
    output reg memRead, //! Memory Read
    output reg [1:0]aluSrc, // cambiar a 2 bits
    output reg [3:0] aluFunc, //! ALU operation (operacion de la alu) // se cambio para agregar mas operaciones
    output reg bitXtend, //! Bit extension, 0 = sign extend, 1 = zero extend
    output reg invOpcode, //! Invalid opcode or function
    output reg [1:0]memDataSize, // 0 = word 1 = half 2= byte
    output reg memBitExtend,
    output reg isShift,
    output reg isJal,
    output reg isJr
);

    always @(*) begin
        if(opc == 6'b0)begin // para las instrucciones de formato R y se usas func para operaciones del alu
            //señales por default

            isJmp  = `OFF_1b;
            rfWriteDataSel = `OFF_2b;
            rfWriteAddrSel = `OFF_1b;
            rfWriteEnable = `OFF_1b;
            memWrite = `OFF_1b;
            memRead = `OFF_1b;
            aluSrc = 2'b0;
            aluFunc = 4'b0;
            bitXtend = `OFF_1b;
            invOpcode = `OFF_1b;
            memDataSize = `OFF_2b;
            memBitExtend = `OFF_1b;
            rfLuiSel = `OFF_1b;
            branch = 3'b0;
            isShift = 1'b0;
            isJal = 1'b0;
            isJr = 1'b0;

            case (func)
                `MIPS_ADD:begin
                    rfWriteAddrSel = `ON_1b; //Reg Dst
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_ADD;
                end
                `MIPS_SUB:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SUB;
                end
                `MIPS_AND:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_AND;
                end
                `MIPS_OR:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_OR;
                end
                `MIPS_SLT:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SLT;
                end
                `MIPS_ADDU:begin
                    rfWriteAddrSel = `ON_1b; //Reg Dst
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_ADD;
                end
                `MIPS_SUBU:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SUB;
                end

                `MIPS_XOR: begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_XOR;
                end
                `MIPS_SLTU: begin
                    rfWriteEnable = `ON_1b;
                    rfWriteAddrSel = `ON_1b;
                    aluFunc = `ALU_SLTU;
                end
                `MIPS_SLL:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SLL;
                    isShift = 1'b1;
                end
                `MIPS_SRL:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SRL;
                    isShift = 1'b1;
                end
                `MIPS_SLLV:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SLL;
                end
                `MIPS_SRLV:begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SRL;
                end
                `MIPS_SRA: begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SRA;
                    isShift = 1'b1;
                end
                `MIPS_SRAV: begin
                    rfWriteAddrSel = `ON_1b;
                    rfWriteEnable = `ON_1b;
                    aluFunc = `ALU_SRA;
                end
                `MIPS_JR: begin
                    isJr = 1'b1;
                end
                default: invOpcode = `ON_1b;
            endcase
        end else begin // para las instrucciones de formato I y J y se usa opc 
            // set de las señales por default
            isJmp  = `OFF_1b;
            rfWriteDataSel = `OFF_2b;
            rfWriteAddrSel = `OFF_1b;
            rfWriteEnable = `OFF_1b;
            memWrite = `OFF_1b;
            memRead = `OFF_1b;
            aluSrc = 2'b0;
            aluFunc = 4'b0;
            bitXtend = `OFF_1b;
            invOpcode = `OFF_1b;
            rfLuiSel = `OFF_1b;
            memDataSize = `OFF_2b;
            memBitExtend = `OFF_1b;
            branch = 3'b0;
            isShift = 1'b0;
            isJal = 1'b0;
            isJr = 1'b0;

            case (opc)
                `MIPS_LW: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;

                end 
                `MIPS_SW: begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    memWrite = `ON_1b;

                end
                `MIPS_BEQ: begin
                    branch = 3'b001;
                    aluFunc = `ALU_SUB;
                end 
                `MIPS_BNE: begin
                    branch = 3'b010;
                    aluFunc = `ALU_SUB;
                end
                `MIPS_JUMP: begin
                    isJmp = `ON_1b;
                end

                `MIPS_ADDI: begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                end
                `MIPS_ADDIU: begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                end
                `MIPS_ANDI: begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_AND;
                    rfWriteEnable = `ON_1b;
                    bitXtend = `ON_1b;
                end
                `MIPS_ORI: begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_OR;
                    rfWriteEnable = `ON_1b;
                    bitXtend = `ON_1b;
                end
                
                `MIPS_LUI: begin
                    rfWriteEnable = `ON_1b;
                    rfLuiSel = `ON_1b;
                end
                `MIPS_XORI: begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_XOR;
                    rfWriteEnable = `ON_1b;
                    bitXtend = `ON_1b;
                end
                `MIPS_SLTI:begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_SLT;
                    rfWriteEnable = `ON_1b;
                end
                `MIPS_SLTIU:begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_SLTU;
                    rfWriteEnable = `ON_1b;
                end
                `MIPS_LH: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;
                    memDataSize = 2'b1;

                end
                `MIPS_LHU: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;
                    memDataSize = 2'b1;
                    memBitExtend = 1'b1;
                end
                `MIPS_LB: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;
                    memDataSize = 2'b10;
                    
                end
                `MIPS_LBU: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;
                    memDataSize = 2'b10;
                    memBitExtend = 1'b1;
                end
                `MIPS_SH:begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    memWrite = `ON_1b;
                    memDataSize = 2'b1;

                end
                `MIPS_SB:begin
                    aluSrc = 2'b1;
                    aluFunc = `ALU_ADD;
                    memWrite = `ON_1b;
                    memDataSize = 2'b10;
                end
                `MIPS_BGEZ_BLTZ:begin
                    // si es 1 es bgez sino es bltz
                    if(bgezOrbltz)begin
                        aluFunc = `ALU_SUB;
                        branch = 3'b011;
                        aluSrc = 2'b10;
                    end else begin
                        aluFunc = `ALU_SUB;
                        branch = 3'b110;
                        aluSrc = 2'b10;
                    end
                end
                `MIPS_BGTZ:begin
                    aluFunc = `ALU_SUB;
                    aluSrc = 2'b10;
                    branch = 3'b100;
                end
                `MIPS_BLEZ:begin
                    aluFunc = `ALU_SUB;
                    aluSrc = 2'b10;
                    branch = 3'b101;
                end
                `MIPS_JAL:begin
                    isJal = 1'b1;
                    rfWriteEnable =1'b1;
                    rfWriteDataSel = 2'b10;
                end
                default: invOpcode = `ON_1b;
            endcase
        end
    end

endmodule

