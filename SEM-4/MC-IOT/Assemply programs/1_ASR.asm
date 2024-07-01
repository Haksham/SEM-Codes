	PRESERVE8 ; Indicate the code here preserve  
	; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY		   
              EXPORT __main			 
	; Start of CODE area 
__main
	LDR r2,=0x00000080
	ASRS r0,r2,#04
	LDR r2,=0x80000000
	ASRS r0,r2,#04
stop B stop
     END
