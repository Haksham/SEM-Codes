//
// Smpl_GPIO_Buzzer : GPB11 low-active output control Buzzer
// Note: Nu-LB-NUC140 R1 should be 0 ohm
//
#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvADC.h"

int main (void)
{					   
	UNLOCKREG();			   // unlock register for programming
  DrvSYS_Open(48000000);     // set System Clock to run at 48MHz
	LOCKREG();				   // lock register from programming

	DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT); // initial GPIO pin GPB11 for controlling Buzzer

	while(1) {
  DrvGPIO_ClrBit(E_GPB,11); // GPB11 = 0 to turn on Buzzer
	DrvSYS_Delay(100000);	    // Delay 
	DrvGPIO_SetBit(E_GPB,11); // GPB11 = 1 to turn off Buzzer	
	DrvSYS_Delay(100000);	    // Delay 		
	}
}
