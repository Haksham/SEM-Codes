//
// smpl_GPIO_Interrupt
//
// GPA15 to input interrupt
// GPD15 to input interrupt

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvUART.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"
#include "LCD_Driver.h"

volatile uint32_t irqA_counter = 0;
volatile uint32_t irqE_counter = 0;

void GPIOAB_INT_CallBack(uint32_t GPA_IntStatus, uint32_t GPB_IntStatus)
{
	 if ((GPA_IntStatus>>15) & 0x01) irqA_counter++;
	 print_lcd(3,"GPA interrupt !!");
}

void GPIOCDE_INT_CallBack(uint32_t GPC_IntStatus, uint32_t GPD_IntStatus, uint32_t GPE_IntStatus)
{  
	 if ((GPE_IntStatus>>15) & 0x01) irqE_counter++;
	 print_lcd(3,"GPC interrupt !!");
}

int32_t main()
{
	char TEXT[16];

	UNLOCKREG();
	SYSCLK->PWRCON.XTL12M_EN=1;
	DrvSYS_Delay(5000);					// Waiting for 12M Xtal stalble
	SYSCLK->CLKSEL0.HCLK_S=0;
	LOCKREG();

  // setup GPA15 & GPD15 to get interrupt input
	DrvGPIO_Open(E_GPA,15,E_IO_INPUT);
	DrvGPIO_Open(E_GPE,15,E_IO_INPUT);
  DrvGPIO_EnableInt(E_GPA, 15, E_IO_RISING, E_MODE_EDGE);
  DrvGPIO_EnableInt(E_GPE, 15, E_IO_RISING, E_MODE_EDGE);
  DrvGPIO_SetDebounceTime(5, 1);
	DrvGPIO_EnableDebounce(E_GPA, 15);
	DrvGPIO_EnableDebounce(E_GPE, 15);	
	
  DrvGPIO_SetIntCallback(GPIOAB_INT_CallBack, GPIOCDE_INT_CallBack);

  Initial_panel();
	clr_all_panel();
    				
	print_lcd(0,"Smpl_GPIO_Intr");
	
	while(1)
	{
		sprintf(TEXT,"IRQ_A: %d",irqA_counter);
		print_lcd(1, TEXT);
		sprintf(TEXT,"IRQ_E: %d",irqE_counter);
		print_lcd(2, TEXT);
	}
}
































































