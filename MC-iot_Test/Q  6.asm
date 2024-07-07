; 6.	Write a program to use switch case.
  PRESERVE8
  THUMB 
  AREA |.text|, CODE, READONLY
  EXPORT __main
  
__main
  LDR R0, =0
  CMP R0, #3                                ; Compare input to maximum valid choice
  BHI default_case                          ; Branch to default case if higher than 3 
  MOVS R2, #4                               ; Multiply branch table offset by 4 
  MULS R0, R2, R0                           ; (size of each entry) 
  LDR R1, =BranchTable                      ; Get base address of branch table(0x284)
  LDR R2,[R1,R0]                            ; Get the actual branch destination 
  BX R2                                     ; Branch to destination 
  ALIGN 4                                     ; Alignment control. The table has
BranchTable                                 ; to be word aligned to prevent unaligned read 
  DCD Dest0                                 ;table of each destination address
  DCD Dest1
  DCD Dest2
  DCD Dest3

default_case
stop B stop                                 ; Instructions for default case
Dest0 ldr r0, =10 
stop1 B stop1                               ; Instructions for case ‘0’
Dest1 ldr r0, =20  
stop2 B stop2                               ; Instructions for case ‘1’
Dest2 ldr r0, =30  
stop3 B stop3                               ; Instructions for case ‘2’
Dest3 ldr r0, =40  
stop4 B stop4                               ; Instructions for case ‘3’
  END