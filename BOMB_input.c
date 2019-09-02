/*
 * BOMB_input.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sa
 */
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Utils.h"
#include <util/delay.h>
#include "TIM0_INT.h"
#include "DIO_MemMap.h"
#include "TIM0_CFG.h"
#include "LCD_4bit.h"
#include "keypad.h"
#include "BOMB_input.h"
extern u8 bombtime;
extern u16 password;
void BMB_input_time(void)
{
	u8 inchar;
	u8 tim=0;
	LCD_vidWriteString("Enter Time:");
	inchar=keypad_u8getkey();
	while(inchar!='*')
	{
		_delay_ms(100);

		if(inchar!='e')
		{
			LCD_vidWriteInt(inchar);
			tim*=10;
			tim+=inchar;
			//LCD_vidWriteInt(tim);
			//_delay_ms(500);

		}
		inchar=keypad_u8getkey();
	}
	//LCD_vidClear();
	//LCD_vidWriteInt(tim);
	//_delay_ms(500);

	bombtime=tim;
	LCD_vidClear();

}
void BMB_input_password(void)
{
	_delay_ms(200);
	u8 inchar;
		u16 pass=0;
		LCD_vidWriteString("Password:");
		inchar=keypad_u8getkey();
		while(inchar!='*')
		{
			_delay_ms(100);

			if(inchar!='e')
			{
				LCD_vidWriteInt(inchar);
				pass*=10;
				pass+=inchar;
			}
			inchar=keypad_u8getkey();
		}
		password=pass;
		LCD_vidClear();
}
