; 2.Write an Assembly level program to copy multiple data at a time say 128 bytes of data in two iterations.


	PRESERVE8
  THUMB 
  AREA |.text|, CODE, READONLY
  EXPORT __main

__main
	LDR r0,=0x20000000              ; Source address
	LDR r1,=0x20000120              ; Destination address
	LDR r2,=128                     ; number of bytes to copy, also
copy_loop                         ; acts as loop counter
	LDMIA r0!,{r4-r7}               ; Read 4 words and increment r0
	STMIA r1!,{r4-r7}               ; Store 4 words and increment r1
	LDMIA r0!,{r4-r7}               ; Read 4 words and increment r0
	STMIA r1!,{r4-r7}               ; Store 4 words and increment r1
	LDMIA r0!,{r4-r7}               ; Read 4 words and increment r0
	STMIA r1!,{r4-r7}               ; Store 4 words and increment r1
	LDMIA r0!,{r4-r7}               ; Read 4 words and increment r0
	STMIA r1!,{r4-r7}               ; Store 4 words and increment r1
	SUBS r2, r2, #64                ; Each time 64 bytes are copied
	BNE copy_loop                   ; loop until all data copied
stop B stop
  END
