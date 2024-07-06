// 11.	Write a C program to count from 0 to 99 and display them on 7-segment LEDs.

// THE BEST OPTIMISIED CODE

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Seven_Segment.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"

void seg_display(int16_t value)
{
  int8_t digit;

  digit = value / 1000;
  close_seven_segment();
  show_seven_segment(3, digit);
  DrvSYS_Delay(5000);

  value = value - digit * 1000;

  digit = value / 100;
  close_seven_segment();
  show_seven_segment(2, digit);
  DrvSYS_Delay(5000);

  value = value - digit * 100;

  digit = value / 10;
  close_seven_segment();
  show_seven_segment(1, digit);
  DrvSYS_Delay(5000);

  value = value - digit * 10;

  digit = value;
  close_seven_segment();
  show_seven_segment(0, digit);
  DrvSYS_Delay(5000);
}

int32_t main(void)
{
  int val;
  val = 0000;

  while (1)
  {
    DrvSYS_Delay(500);
    val = val++;
    seg_display(val);
    if (val == 99)
    {
      close_seven_segment();
      show_seven_segment(0, 9);
      show_seven_segment(1, 9);
      break;
    }
  }
}

// 7 segment ends with 99 on LCD display