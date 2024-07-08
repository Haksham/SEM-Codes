// 7.	Write a C program to Light LEDs connected to port C12-15 using macros.

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"

int main(void)
{
	clr_all_panel();
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