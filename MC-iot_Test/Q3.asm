; 3.	Write a program to illustrate ASR and LSLS instruction.

  PRESERVE8    
      THUMB       
    AREA |.text|, CODE, READONLY
  EXPORT __main			 
  
__main

	LDR r2,=0x00000080;
	ASRS r0,r2,#04                    ;00000001000
	LDR r2,=0x80000000;
	ASRS r0,r2,#04                    ;0xF8000000
  LDR r2,=0xFFFFFFF8
  ASRS r0,r2,#05                    ;0xFFFFFFFF
	LDR r2,=0x00000080;
	LSLS r0,r2,#04                    ;0x00000800
	LDR r2,=0x80000000                ;0x00000000
	LSLS r0,r2,#04                    ;0x
  LDR r2,=0xFFFFFFF8
  LSLS r0,r2,#05                    ;0xFFFFFF00
   	
stop B stop
   END
