	PRESERVE8 ; Indicate the code here preserve  
; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY		   
              EXPORT __main			 
; Start of CODE area 
__main
       movs r2,#1
       movs r0,#5
	   cmp r0,#0
	   beq result
	   movs r1,r0
loop   muls r2,r1,r2
       subs r1,r1,#1
	   cmp r1,#0
	   bgt loop
result b result
       END
