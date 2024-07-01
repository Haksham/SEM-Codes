;copy 10 locations between a and b        
	PRESERVE8 ; Indicate the code here preserve  
; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY
			   
              EXPORT __main			 
; Start of CODE area 
__main
		ldr r0,=0x20000000
		ldr r1,=0x20000020
		movs r2,#10
loop    ldrb r3,[r0]
		strb r3,[r1]
		adds r0,r0,#1
		adds r1,r1,#1
		subs r2,r2,#1
		bne loop
stop    b stop
        END
