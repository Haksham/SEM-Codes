// 9.	Write a C program to enable External Interrupt pin to trigger interrupt on GPB15 and buzz.

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvUART.h"
#include "Driver\DrvSYS.h"

void EINT1Callback(void)
{
  DrvGPIO_ClrBit(E_GPB, 11); // GPB11 = 0 to turn on Buzzer
  DrvSYS_Delay(100000);      // Delay
  DrvGPIO_SetBit(E_GPB, 11); // GPB11 = 1 to turn off Buzzer
  DrvSYS_Delay(100000);      // Delay
}

int main(void)
{
  DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT); // initial GPIO pin GPB11 for controlling Buzzer
  DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);                             // configure external interrupt pin GPB15
  DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT1Callback); // configure external interrupt
  while (1)
  {}
}