//
// Smpl_GPIO_RGBled : GPA12,13,14 output control RGB LED
//                    output low to enable LEDs
#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvUART.h"
#include "Driver\DrvSYS.h"

// Initial GPIO pins (GPA 12,13,14) to Output mode  
void Init_LED()
{
	// initialize GPIO pins
	DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT); // GPA12 pin set to output mode
	DrvGPIO_Open(E_GPA, 13, E_IO_OUTPUT); // GPA13 pin set to output mode
	DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT); // GPA14 pin set to output mode
	// set GPIO pins output Hi to disable LEDs
	DrvGPIO_SetBit(E_GPA, 12); // GPA12 pin output Hi to turn off Blue  LED
	DrvGPIO_SetBit(E_GPA, 13); // GPA13 pin output Hi to turn off Green LED
	DrvGPIO_SetBit(E_GPA, 14); // GPA14 pin output Hi to turn off Red   LED
}    

int main (void)
{
	UNLOCKREG();			   // unlock register for programming
    DrvSYS_Open(48000000);     // set System Clock to run at 48MHz (PLL with 12MHz crystal input)
	LOCKREG();				   // lock register from programming

	Init_LED();
						   
	while (1)
	{		 
	// GPA12 = Blue,  0 : on, 1 : off
	// GPA13 = Green, 0 : on, 1 : off
	// GPA14 = Red,   0 : on, 1 : off

	// set RGBled to Blue
    DrvGPIO_ClrBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 
	DrvSYS_Delay(1000000); 		   

	// set RGBled to Green
    DrvGPIO_SetBit(E_GPA,12); 
    DrvGPIO_ClrBit(E_GPA,13); // GPA13 = Green, 0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,14); 
	DrvSYS_Delay(1000000);			  

	// set RGBled to Red
    DrvGPIO_SetBit(E_GPA,12); 
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_ClrBit(E_GPA,14); // GPA14 = Red,   0 : on, 1 : off
	DrvSYS_Delay(1000000);			  
	
	// set RGBled to off	 
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); // GPA13 = Green, 0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,14); // GPA14 = Red,   0 : on, 1 : off
	DrvSYS_Delay(1000000);

	}
}




