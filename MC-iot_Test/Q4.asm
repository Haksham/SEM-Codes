; 4.	Write a program to illustrate the processing of data in a stack and realizing of stack using another file say (processing x to read 2x+9).


// file 1

  PRESERVE8  
    THUMB      
      AREA |.text|, CODE, READONLY
    EXPORT __main 
    EXTERN  func
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
    EXTERN func2

func
	push{LR}
	MOVS R1,#08
	BL func2
	pop{PC}
  END


// file 3

  PRESERVE8
    THUMB
      AREA |.text|, CODE, READONLY
    EXPORT func2
	
func2
	MOVS r2,#08
	BX LR
  END
