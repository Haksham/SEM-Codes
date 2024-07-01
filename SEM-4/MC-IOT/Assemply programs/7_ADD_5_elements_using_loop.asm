	PRESERVE8 ; Indicate the code here preserve  
; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY		   
              EXPORT __main			 
; Start of CODE area 
__main 	
		MOVS R0, #0 ; Total = 0
		MOVS R1, #0 ; i = 0
loop
		ADDS R0, R0, R1 ; Total = Total + i
		ADDS R1, R1, #1 ; i= i + 1
		CMP R1, #5 ; compare i to 5			
		BLT loop ; if less than then branch to loop
	        END      
