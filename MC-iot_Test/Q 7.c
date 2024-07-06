// 7.	Write a C program to Light LEDs connected to port C12-15 using macros.

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"

void Init_LED() // Initialize GPIO pins
{
	DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT); // GPC12 pin set to output mode
	DrvGPIO_SetBit(E_GPC, 15);						// Goutput Hi to turn off LED

	DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT); // GPC12 pin set to output mode
	DrvGPIO_SetBit(E_GPC, 14);

	DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT); // GPC12 pin set to output mode
	DrvGPIO_SetBit(E_GPC, 13);
	
	DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT); // GPC12 pin set to output mode
	DrvGPIO_SetBit(E_GPC, 12);
}

int main(void)
{
		while (1) // forever loop to keep flashing four LEDs one at a time
	{
		DrvGPIO_ClrBit(E_GPC, 15); // output Low to turn on LED
		DrvSYS_Delay(300000);			 // delay
		DrvGPIO_SetBit(E_GPC, 15); // output Hi to turn off LED
		DrvSYS_Delay(300000);			 // delay

		DrvGPIO_ClrBit(E_GPC, 14); // output Low to turn on LED
		DrvSYS_Delay(300000);			 // delay
		DrvGPIO_SetBit(E_GPC, 14); // output Hi to turn off LED
		DrvSYS_Delay(300000);

		DrvGPIO_ClrBit(E_GPC, 13); // output Low to turn on LED
		DrvSYS_Delay(300000);			 // delay
		DrvGPIO_SetBit(E_GPC, 13); // output Hi to turn off LED
		DrvSYS_Delay(300000);

		DrvGPIO_ClrBit(E_GPC, 12); // output Low to turn on LED
		DrvSYS_Delay(300000);			 // delay
		DrvGPIO_SetBit(E_GPC, 12); // output Hi to turn off LED
		DrvSYS_Delay(300000);
	}
}