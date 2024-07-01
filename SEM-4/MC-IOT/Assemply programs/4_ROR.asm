	PRESERVE8 ; Indicate the code here preserve  
	; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY		   
              EXPORT __main			 
	; Start of CODE area 
__main
		LDR r0,=0x80000001;
		MOVS r2,#31;32-1
		RORS r0,r2
		LDR r0,=0x80000001;
		MOVS r2,#30
		RORS r0,r2
stop B stop
    END	   	
