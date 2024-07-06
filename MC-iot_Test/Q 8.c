// 8.	Write a C program to display 4 lines of Text on LCD.

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

int main(void)
{
  Initial_panel();
  clr_all_panel();
  print_lcd(0, "Text 1");
  print_lcd(1, "Text 2");
  print_lcd(2, "Text 3");
  print_lcd(3, "Text 4");
}
