; 5.Write a program to clear and extract the bits with starting position P and width of the bits W.

  PRESERVE8
  THUMB
  AREA |.text|, CODE, READONLY
  EXPORT __main

__main

	LDR r0,=0xFFC0FFFF      ;extracting
	LSLS r0,r0,#8
	LSRS r0,r0,#24

	LDR r0,=0xFFC0FFFF      ;clearing
	MOVS r1,#16
	MOVS R2,#08
	MOVS r3,#08
	RORS r0,r0,r1
	LSRS r0,r0,r2
	RORS r0,r0,r3
stop B stop
  END
