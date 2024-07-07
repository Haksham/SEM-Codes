; 4.Write a program to illustrate the processing of data in a stack and realizing of stack using another file say (processing x to read 2x+9).


// file 1

  PRESERVE8
  THUMB
  AREA |.text|, CODE, READONLY
  EXPORT __main 
  EXTERN func
__main
	LDR r0,=0x10
  BL func
stop B stop
  END


// file 2

  PRESERVE8
  THUMB
  AREA |.text|, CODE, READONLY
  EXPORT func

func
    push{r0}
    LDR r1,[r13]
    MOVS r3,#2
    MULS r1,r3,r1
    ADDS r1,r1,#9
    STR r1,[r13]
    POP{r2}
    BX LR
  END
