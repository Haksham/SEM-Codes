; 3.Write a program to illustrate ASR and LSLS instruction.

  PRESERVE8
      THUMB
    AREA |.text|, CODE, READONLY
  EXPORT __main

__main
  LDR r2,=0x00000080;
  ASRS r0,r2,#04                    ;00000001000
  
  LDR r2,=0x00000080;
  LSLS r0,r2,#04                    ;0x00000800
  
stop B stop
  END
