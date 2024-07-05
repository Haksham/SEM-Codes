//
// Smpl_LCD_Text: display 4 lines of Text on LCD
//
#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

int main(void)
{
	UNLOCKREG();
	DrvSYS_Open(48000000); // set to 48MHz
	LOCKREG(); 

	Initial_panel(); 
	clr_all_panel();
	
	print_lcd(0, "Smpl_LCD_Text   ");	  
	print_lcd(1, "Nu-LB-NUC140    ");
	print_lcd(2, "Test LCD Display");
	print_lcd(3, "Nuvoton NuMicro ");    	  	 	  		
}

