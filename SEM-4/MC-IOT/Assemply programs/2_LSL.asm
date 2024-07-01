	PRESERVE8 ; Indicate the code here preserve  
	; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY		   
              EXPORT __main			 
	; Start of CODE area 
__main
		LDR r0,=0x80000001;
		LSLS r2,r0,#01
		LDR r0,=0x80000001;
		LSLS r2,r0,#02
stop B stop
		END
