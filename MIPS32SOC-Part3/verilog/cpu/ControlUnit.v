`include "alu_defines.vh"
`include "mips32_opcodes.vh" 
`include "constants_defines.vh"

module ControlUnit(
    input [5:0] opc, //! Opcode
    input [5:0] func, //! Function
    output reg isJmp, //! Jump signal
    output reg isBeq, //! BEQ signal
    output reg isBne, //! BNE signal
    output reg [1:0] rfWriteDataSel, //! Register File Write Data Select (Seleciona si lo que se va escribir viene del memory o del alu)
    output reg rfWriteAddrSel, //! Register File Write Address Select (Decide la direccion dependiendo de la instuccion)
    output reg rfLuiSel,
    output reg rfWriteEnable, //! Register Write Enable 
    output reg memWrite, //! Memory Write 
    output reg memRead, //! Memory Read
    output reg aluSrc, //! ALU source (decide si viene del registro o del offset en lw o sw)
    output reg [2:0] aluFunc, //! ALU operation (operacion de la alu)
    output reg bitXtend, //! Bit extension, 0 = sign extend, 1 = zero extend
    output reg invOpcode, //! Invalid opcode or function
    output reg [1:0]memDataSize, // 0 = word 1 = half 2= byte
    output reg memBitExtend
);

    always @(*) begin
        if(opc == 6'b0)begin // para las instrucciones de formato R y se usas func para operaciones del alu
            //señales por default

            isJmp  = `OFF_1b;
            isBeq = `OFF_1b;
            isBne = `OFF_1b;
            rfWriteDataSel = `OFF_2b;
            rfWriteAddrSel = `OFF_1b;
            rfWriteEnable = `OFF_1b;
            memWrite = `OFF_1b;
            memRead = `OFF_1b;
            aluSrc = `OFF_1b;
            aluFunc = `OFF_3b;
            bitXtend = `OFF_1b;
            invOpcode = `OFF_1b;
            memDataSize = `OFF_2b;
            memBitExtend = `OFF_1b;
            rfLuiSel = `OFF_1b;

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

                default: invOpcode = `ON_1b;
            endcase
        end else begin // para las instrucciones de formato I y J y se usa opc 
            // set de las señales por default
            isJmp  = `OFF_1b;
            isBeq = `OFF_1b;
            isBne = `OFF_1b;
            rfWriteDataSel = `OFF_2b;
            rfWriteAddrSel = `OFF_1b;
            rfWriteEnable = `OFF_1b;
            memWrite = `OFF_1b;
            memRead = `OFF_1b;
            aluSrc = `OFF_1b;
            aluFunc = `OFF_3b;
            bitXtend = `OFF_1b;
            invOpcode = `OFF_1b;
            rfLuiSel = `OFF_1b;
            memDataSize = `OFF_2b;
            memBitExtend = `OFF_1b;

            case (opc)
                `MIPS_LW: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;

                end 
                `MIPS_SW: begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    memWrite = `ON_1b;

                end
                `MIPS_BEQ: begin
                    isBeq = `ON_1b;
                    aluFunc = `ALU_SUB;
                end 
                `MIPS_BNE: begin
                    isBne = `ON_1b;
                    aluFunc = `ALU_SUB;
                end
                `MIPS_JUMP: begin
                    isJmp = `ON_1b;
                end

                `MIPS_ADDI: begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                end
                `MIPS_ADDIU: begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                end
                `MIPS_ANDI: begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_AND;
                    rfWriteEnable = `ON_1b;
                    bitXtend = `ON_1b;
                end
                `MIPS_ORI: begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_OR;
                    rfWriteEnable = `ON_1b;
                    bitXtend = `ON_1b;
                end
                
                `MIPS_LUI: begin
                    rfWriteEnable = `ON_1b;
                    rfLuiSel = `ON_1b;
                end
                `MIPS_XORI: begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_XOR;
                    rfWriteEnable = `ON_1b;
                    bitXtend = `ON_1b;
                end
                `MIPS_SLTI:begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_SLT;
                    rfWriteEnable = `ON_1b;
                end
                `MIPS_SLTIU:begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_SLTU;
                    rfWriteEnable = `ON_1b;
                end
                `MIPS_LH: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;
                    memDataSize = 2'b1;

                end
                `MIPS_LHU: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;
                    memDataSize = 2'b1;
                    memBitExtend = 1'b1;
                end
                `MIPS_LB: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;
                    memDataSize = 2'b10;
                    
                end
                `MIPS_LBU: begin
                    rfWriteDataSel = `ON_2b;
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    rfWriteEnable = `ON_1b;
                    memRead = `ON_1b;
                    memDataSize = 2'b10;
                    memBitExtend = 1'b1;
                end
                `MIPS_SH:begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    memWrite = `ON_1b;
                    memDataSize = 2'b1;

                end
                `MIPS_SB:begin
                    aluSrc = `ON_1b;
                    aluFunc = `ALU_ADD;
                    memWrite = `ON_1b;
                    memDataSize = 2'b10;

                end
                default: invOpcode = `ON_1b;
            endcase
        end
    end

endmodule

