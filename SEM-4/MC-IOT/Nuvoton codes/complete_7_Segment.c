//
// Smpl_7seg : counting from 0 to 9999 and display on 7-segment LEDs
//
#include <stdio.h>																											 
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Seven_Segment.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"

// display an integer on four 7-segment LEDs
void seg_display(int16_t value)
{
  int8_t digit;
	digit = value / 1000;
	close_seven_segment();
	show_seven_segment(3,digit);
	DrvSYS_Delay(5000);
			
	value = value - digit * 1000;
	digit = value / 100;
	close_seven_segment();
	show_seven_segment(2,digit);
	DrvSYS_Delay(5000);

	value = value - digit * 100;
	digit = value / 10;
	close_seven_segment();
	show_seven_segment(1,digit);
	DrvSYS_Delay(5000);

	value = value - digit * 10;
	digit = value;
	close_seven_segment();
	show_seven_segment(0,digit);
	DrvSYS_Delay(5000);
}

int32_t main (void)
{
	char TEXT1[16];
				   int val;
				   val=0000;
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();			 	

 	while(1) 
	{	DrvSYS_Delay(500);	 
	 val=val++ ;
	
	seg_display(val);			     // write 1 to clear the flag
	 
	}
}
