/*
 * main.c
 *
 *  Created on: Sep 9, 2022
 *      Author: hp
 */
# include "STD_TYPES.h"
# include "DIO_interface.h"
# include "TIMER_interface.h"
# include "EXTI_interface.h"
# include "GIE_interface.h"
# include "LCD_interface.h"


static u16 PeriodTicks=0;
static u16 ONTicks=0;

void ICU_HW (void);
int main ()
{
//---------------------------------------------------------------------------------------------------------------------------------------------
	/*Set LCD Ports Direction*/
	DIO_VidSetPortDirection(Port_A,0b00000111); // LCD CMD Pins  : Port_A {2,1,0--->OutPut} RS,RW,E respectively only
	DIO_VidSetPortDirection(Port_C,0b11111111); // LCD DATA Pins : Port_C {7,6,5,4,3,2,1,0--->OutPut}
//---------------------------------------------------------------------------------------------------------------------------------------------
	/*Set Timer0 FPWM Pin (OC0) as Output*/
	DIO_VidSetPinDirection(Port_B,Pin3,Output);
//---------------------------------------------------------------------------------------------------------------------------------------------
	/*Set Input Capture Pin (ICP) as Input*/
	DIO_VidSetPinDirection(Port_D,Pin6,Input);
//---------------------------------------------------------------------------------------------------------------------------------------------
	ICU_u8SetCallBack(&ICU_HW);
	ICU_VidInit();

	LCD_VidInit();

	TIMER1_VidNormalInit();
	TIMER0_VidFPWMInit();
	Timer0_VidSetDuty(25);

	GIE_VidEnable();

	while(1)
	{
		/*Wait until PeriodTicks and ONTicks are Measured*/
		while ( (PeriodTicks==0) && (ONTicks==0) );

		LCD_VidGotoXY(0,0);
		LCD_VidSendString("PeriodTicks: ");
		LCD_VidSendValue(PeriodTicks);

		LCD_VidGotoXY(1,0);
		LCD_VidSendString("  ONTicks  : ");
		LCD_VidSendValue(ONTicks);
		while(1);
	}




}
void ICU_HW (void)
{
	static u16 Reading1,Reading2,Reading3;
	static u8 Local_u8Counter=0;
	Local_u8Counter++;

	if (Local_u8Counter==1)
	{
		/*First Rising Edge*/
		Reading1=ICU_u16GetICUValue();
	}
	else if (Local_u8Counter==2)
	{
		/*Second Rising Edge*/
		Reading2=ICU_u16GetICUValue();
		PeriodTicks=Reading2-Reading1;

		/*Change the Triggering to FALLING_EDGE*/
		ICU_VidSetSenseControl(ICU_HW_FALLING);
	}
	else if (Local_u8Counter==3)
	{
		Reading3=ICU_u16GetICUValue();
		ONTicks=Reading3-Reading2;
		ICU_VidInturruptControl(ICU_HW_INT_DISABLE);
	}

}


