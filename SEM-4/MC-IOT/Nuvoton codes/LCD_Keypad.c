//                                                                                                         */
// Smpl_LCD_Keypad : input 3x3 keypad, output to LCD display
//
#include <stdio.h>																											 
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "scankey.h"
#include "NUC1xx-LB_002\LCD_Driver.h"


int32_t main (void)
{
	int8_t number;
	char TEXT0[16]="Smpl_LCD_Keypad";
	char TEXT1[16]="Keypad:        ";
	
	UNLOCKREG();
    DrvSYS_Open(48000000); // set MCU to run at 48MHz
	LOCKREG();

	Initial_panel(); 
	clr_all_panel();

	OpenKeyPad();	    // initialize 3x3 keypad
	print_lcd(0,TEXT0); // print title
	 
	while(1)
	{
	    number = Scankey(); 	      // scan keypad to input
		sprintf(TEXT1+8,"%d",number); // print scankey input to string			  
		print_lcd(1, TEXT1);          // display string on LCD
		DrvSYS_Delay(5000); 		  // delay 																	 
	}
}

