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
    output reg rfWriteEnable, //! Register Write Enable 
    output reg memWrite, //! Memory Write 
    output reg memRead, //! Memory Read
    output reg aluSrc, //! ALU source (decide si viene del registro o del offset en lw o sw)
    output reg [2:0] aluFunc, //! ALU operation (operacion de la alu)
    output reg bitXtend, //! Bit extension, 0 = sign extend, 1 = zero extend
    output reg invOpcode //! Invalid opcode or function
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

            case (func)
                `MIPS_ADD:begin
                    rfWriteAddrSel = `ON_1b;
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
                default: invOpcode = `ON_1b;
            endcase
        end
    end

endmodule

