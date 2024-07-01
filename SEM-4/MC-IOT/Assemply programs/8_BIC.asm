	PRESERVE8 ; Indicate the code here preserve  
; 8 byte stack alignment         
                     THUMB     ; Indicate THUMB code is used       
                 AREA    |.text|, CODE, READONLY
			   
              EXPORT __main			 
; Start of CODE area 

__main   
    ldr r1,=0xffffffff
	movs r2, #0xff
	lsls r2,r2,#16
	bics r1,r1,r2
	movs r2, #0xc0 
	 lsls r2,r2,#16
	 orrs r1,r1,r2
	 str r1,[r0]
stop b stop
      end         
