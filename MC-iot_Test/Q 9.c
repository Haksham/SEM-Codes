// 9.	Write a C program to enable External Interrupt pin to trigger interrupt on GPB15 and buzz.

#include <stdio.h>
#include "NUC1xx.h"
#include "DrvGPIO.h"
#include "DrvUART.h"
#include "DrvSYS.h"

void EINT1Callback(void)
{
  DrvGPIO_ClrBit(E_GPB, 11); // GPB11 = 0 to turn on Buzzer
  DrvSYS_Delay(100000);      // Delay
  DrvGPIO_SetBit(E_GPB, 11); // GPB11 = 1 to turn off Buzzer
}

int main(void)
{
  DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT1Callback); // configure external interrupt
  while (1)
  {}
}