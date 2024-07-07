; 3.Write a program to illustrate ASR and LSLS instruction.

  PRESERVE8
  THUMB
  AREA |.text|, CODE, READONLY
  EXPORT __main

__main
  LDR r1,=0x00000080;
  ASRS r1,r1,#04                    ;0x00000008
  
  LDR r2,=0x00000080;
  LSLS r2,r2,#04                    ;0x00000800
  
stop B stop
  END
