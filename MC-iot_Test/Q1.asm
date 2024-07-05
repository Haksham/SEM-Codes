; 1.	Use Labels to calculate the sum of say 10 numbers.

     
	PRESERVE8     
			THUMB 
		AREA |.text|, CODE, READONLY
	EXPORT __main			 
              
__main
	LDR r0,=DataIn            ; Get the address of variable 'DataIn'
	MOVS r1, #10              ; loop counter
	MOVS r2, #0               ; Result - starting from 0
add_loop
	LDM r0!,{r3}              ; Load result and increment address
	ADDS r2, r3               ; add to result
	SUBS r1, #1               ; increment loop counter
	BNE add_loop
	LDR r0,=Sum               ; Get the address of variable 'Sum'
	STR r2,[r0]               ; Save result to Sum

stop b stop
  END
