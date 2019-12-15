module BranchResolver (
    input [2:0]branch, // viene del control unit
    input zero, // viene del zero de la Alu
    input sign, // viene del readData1 el ultimo bit
    output reg branchTaken
);

    always @(*) begin
        case(branch)
            // no branch
            3'b000:begin
                branchTaken = 1'b0;
            end
            // beq
            3'b001:begin
                if(zero)
                    branchTaken = 1'b1;
                else
                    branchTaken = 1'b0;
            end
            //bne
            3'b010:begin
                if(!zero)
                    branchTaken = 1'b1;
                else
                    branchTaken = 1'b0;
            end
            //bgez
            3'b011:begin
                if(!sign && ( !zero || zero ))
                    branchTaken = 1'b1;
                else
                    branchTaken = 1'b0;
            end
            //bgtz
            3'b100:begin
                if(!sign && !zero )
                    branchTaken = 1'b1;
                else
                    branchTaken = 1'b0;
            end
            //blez
            3'b101:begin
                if( ( sign &&  !zero ) || zero )
                    branchTaken = 1'b1;
                else
                    branchTaken = 1'b0;
            end
            //bltz
            3'b110:begin
                if( sign && !zero )
                    branchTaken = 1'b1;
                else
                    branchTaken = 1'b0;
            end
            default: branchTaken = 1'bx;
        endcase
    end

endmodule // 