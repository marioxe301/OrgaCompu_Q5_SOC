module MemReadDataDecoder (
    input [31:0] inData, // es la salida del datamemory read nota:  Agregar mux porque la otra memoria es de el vga
    input [1:0]ofsset, // los dos menos significativos del physical
    input [1:0]dataSize, // señal del control unit
    input bitExt,
    output reg[31:0] outData // va un mux que va a registro Nota: pasa por un mux
);
        always @(*) begin
            if(dataSize == 2'b00)begin // es una palabra
                // el offset se descarta en una palabra
                outData = inData;
            end else if(dataSize == 2'b01)begin // es una media palabra
                if(ofsset== 2'b0)begin
                    if(bitExt)
                        outData = { 16'b0 ,inData[31:16] };

                    else
                        outData = { {16{inData[31]}} , inData[31:16]};

                end else if(ofsset == 2'b10)begin
                    if(bitExt)
                        outData = { 16'b0 ,inData[15:0] };

                    else
                        outData = { {16{inData[15]}} ,inData[15:0] };

                end else begin
                    outData = 32'b0;
                end
            end else if(dataSize == 2'b10)begin //  solo toma 1 byte
                if(ofsset == 2'b0)begin
                    if(bitExt)
                        outData = { 24'b0 ,inData[31:24]};
                    else
                        outData = { {24{inData[31]}} ,inData[31:24]};

                end else if(ofsset == 2'b1)begin
                    if(bitExt)
                        outData = { 24'b0 ,inData[23:16]};
                    else
                        outData = { {24{inData[23]}} ,inData[23:16]};

                end else if(ofsset == 2'b10)begin
                    if(bitExt)
                        outData = { 24'b0 ,inData[15:8]};
                    else
                        outData = { {24{inData[15]}} ,inData[15:8]};

                end else if(ofsset == 2'b11)begin
                    if(bitExt)
                        outData = { 24'b0 ,inData[7:0]};
                    else
                        outData = { {24{inData[7]}} ,inData[7:0]};

                end else begin
                    outData = 32'b0;
                end 
            end
        end
endmodule 