	PRESERVE8 ; Indicate the code here preserve  
; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY		   
              EXPORT __main			 
; Start of CODE area 
__main 	
			LDR	R0,=0X00000001
			LDR	R1,=0X00000002
strt3			cmp r0,#10
			ble start2
			movs r0,#0
			b stop
start2		adds r0,r0,#1			
			b strt3
			
stop	      B	   stop		 		;stop program
	          END      
