/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sa
 */
#define F_CPU 8000000UL
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Utils.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "TIM0_INT.h"
#include "DIO_MemMap.h"
#include "TIM0_CFG.h"
#include "LCD_4bit.h"
#include "keypad.h"
#include "BOMB_input.h"
#define BUZZER_PORT PORTB
#define LEDS_PORT PORTD
#define KEYPAD_PORT PORTA
enum phases g_phase=intiate_bomb;
u16 gsec=0;
u16 counter=0;
u8 bombtime=8;
u8 rem=5;
u16 password=0;
int main(void)
{
	u8 lednum;
	u8 ledmask=0xff;
	u8 key_press=0;
	u16 pass_try=0;
	u8 f=0;
	DIO_vidSetPinDirection(BUZZER_PORT,PIN0,OUTPUT);
	DIO_vidSetPortDirection(LEDS_PORT,0xff);
	DIO_vidSetPinDirection(PORTA,PIN0,INPULLUP);
		DIO_vidSetPinDirection(PORTA,PIN1,INPULLUP);
			DIO_vidSetPinDirection(PORTA,PIN2,INPULLUP);
			DIO_vidSetPinDirection(PORTA,PIN3,INPULLUP);
			DIO_vidSetPinDirection(PORTA,PIN4,OUTPUT);
			DIO_vidSetPinDirection(PORTA,PIN5,OUTPUT);
			DIO_vidSetPinDirection(PORTA,PIN6,OUTPUT);
			DIO_vidSetPinDirection(PORTA,PIN7,OUTPUT);
	TIM0_vidInit();
	TIM0_vidSetTimerval(192);
	LCD_vidInit();
	LCD_vidWriteString("Start counter :");
	_delay_ms(500);
	LCD_vidClear();
	//LCD_vidWriteString("Hour:Minute:Second");
	sei();

	while(1)
	{
		switch(g_phase)
		{
		case intiate_bomb:BMB_input_time();
					 BMB_input_password();
					 //bombtime=10;
					 //password=12;
					 g_phase=countdown;
					 break;
		case countdown	:if(f==0){
							gsec=0;
							f=1;
						}
			          rem=bombtime-gsec;
					 if(rem==0){
						 g_phase=boom;
						 break;
					 }
						lednum=(u8)(((u16)rem*8)/bombtime);
						DIO_vidWritePort(LEDS_PORT,(ledmask>>(lednum)));

					if(rem<3)
					{
						DIO_vidWritePin(BUZZER_PORT,PIN0,1);
						_delay_ms(500);
						DIO_vidWritePin(BUZZER_PORT,PIN0,0);
						LCD_vidSetDisplayAdrr(LINE2);
						LCD_vidWriteString("!!!!!WARNING!!!!");
					}
					LCD_vidSetDisplayAdrr(0x00);
					LCD_vidWriteInt(rem);
					if(rem>1)
					LCD_vidWriteString(" Secs Left ");
					else LCD_vidWriteString(" Sec Left");
					LCD_vidSetDisplayAdrr(LINE2);
					key_press=keypad_u8getkey();
					if(key_press!='e' && key_press!='*' )
						{

						pass_try*=10;
						pass_try+=key_press;
						LCD_vidWriteInt(pass_try);
						LCD_vidWriteString("   ");
						}
					else if(key_press=='*')
					{
						if(pass_try==password)
						{
							g_phase=deactivated;
							break;
						}
						else{
							pass_try=0;
							LCD_vidSetDisplayAdrr(LINE2);
							LCD_vidWriteString("    ");
						}
					}
					_delay_ms(100);
					break;
		case deactivated:
					_delay_ms(300);
					LCD_vidClear();
					LCD_vidWriteString("BOMB DEACTIVATED ");
					break;
		case boom:		DIO_vidWritePin(BUZZER_PORT,PIN0,1);
		         LCD_vidClear();
		         LCD_vidWriteString("MISSION ACCOMPLISHED");
		        ledmask^=0xff;
				DIO_vidWritePort(LEDS_PORT,ledmask);
				_delay_ms(300);
				break;
		}


	}
	return 0;
}
ISR(TIMER0_OVF_vect)
{
	counter++;
	if(counter==3907)
	{
		gsec++;
		counter=0;
		TIM0_vidSetTimerval(192);
	}
}
