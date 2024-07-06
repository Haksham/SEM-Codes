// 10.	Write a C program to take input from 3x3 keypad and output to LCD display.

#include <stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "scankey.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

int32_t main(void)
{
  int8_t number;
  char TEXT[16] = "Keypad:        ";

  OpenKeyPad();       // initialize 3x3 keypad
  Initial_panel();
  clr_all_panel();

  while (1)
  {
    number = Scankey();               // scan keypad to input
    sprintf(TEXT + 8, "%d", number); // print scankey input to string
    print_lcd(0, TEXT);              // display string on LCD
  }
}
