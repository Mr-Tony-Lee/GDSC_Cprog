`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/18 00:47:56
// Design Name: 
// Module Name: ex2
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module ex2(output I3 , I2 , I1 , I0 , input O3, O2 , O1 , P3 , O0, P2, P1 );

wire C1 , C2 , C3 ;

xor(C3 , O3 , O2 , O1 , P3 ) ;
xor(C2 , O3 , O2 , O0 , P2 ) ;
xor(C1 , O3 , O1 , O0 , P1 ) ; 

wire D3 , D5 , D6 , D7 ; 
and(D3 , ~C3 , C2 , C1 ) ;
and(D5 , C3 , ~C2 , C1 ) ;
and(D6 , C3 , C2 , ~C1 ) ;
and(D7 , C3 , C2 , C1 ) ;

xor(I0 , O0 , D3 ) ; 
xor(I1 , O1 , D5 ) ;
xor(I2 , O2 , D6 ) ;
xor(I3 , O3 , D7 ) ;

endmodule


`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/11/18 00:54:01
// Design Name: 
// Module Name: testbench_ex2
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module testbench_ex2();
    wire I3 , I2 , I1 , I0 ; 
    reg O3, O2 , O1 , P3 , O0, P2, P1  ; 
    ex2 U1 ( I3 , I2 , I1 , I0 , O3 , O2 , O1 , P3 , O0, P2, P1 );
    initial begin
        {O3, O2 , O1 , P3 , O0, P2, P1} = 7'b0010101;
        #10;
        
        {O3, O2 , O1 , P3 , O0, P2, P1} = 7'b1110101;
        #10;
        
        {O3, O2 , O1 , P3 , O0, P2, P1} = 7'b1000101;
        #10;
        
        {O3, O2 , O1 , P3 , O0, P2, P1} = 7'b1010001;
        #10;
        $finish;
    end 
endmodule
