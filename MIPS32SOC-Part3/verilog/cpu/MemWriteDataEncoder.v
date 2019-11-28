module MemWriteDataEncoder (
    input [31:0]inData, // lo agarra del readData2
    input [1:0]ofsset, // los tomo los menos significativos del physical adrres del memDecoder
    input memWrite, // control unit
    input [1:0]dataSize, // control unit
    output reg [31:0] outData, // es lo que entra al write data del data memry
    output reg [3:0] encMW // es lo que entra al memEnable del data memory
);

    always @(*) begin
        if(memWrite)begin
            if(dataSize == 2'b00)begin // es una palabra
                // el offset se descarta en una palabra
                outData = inData;
                encMW = 4'b1111;
            end else if(dataSize == 2'b01)begin // es una media palabra
                if(ofsset== 2'b0)begin
                    outData = { inData[15:0] ,16'b0  };
                    encMW = 4'b0011;
                end else if(ofsset == 2'b10)begin
                    outData = { 16'b0 , inData[15:0] };
                    encMW = 4'b1100;
                end else begin
                    outData = 32'b0;
                    encMW = 4'b0000;
                end
            end else if(dataSize == 2'b10)begin //  solo toma 1 byte
                if(ofsset == 2'b0)begin
                    outData = { inData[7:0],  24'b0 };
                    encMW = 4'b0001;
                end else if(ofsset == 2'b1)begin
                    outData = { 8'b0 ,inData[7:0], 16'b0};
                    encMW = 4'b0010;
                end else if(ofsset == 2'b10)begin
                    outData = { 16'b0 ,inData[7:0], 8'b0};
                    encMW = 4'b0100;
                end else if(ofsset == 2'b11)begin
                    outData = { 24'b0 ,inData[7:0]};
                    encMW = 4'b1000;
                end else begin
                    outData = 32'b0;
                    encMW = 4'b0000;
                end 
            end
        end else begin
           outData = 32'b0;
           encMW = 4'b0000; 
        end
    end

endmodule // 