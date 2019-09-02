#include <stdio.h>
#include <stdlib.h>
#include "StdTypes.h"
#include "DIO_MemMap.h"
#include "DIO_Interface.h"
#include "Utils.h"
#include <String.h>
#include "LCD_4bit.h"
#include <util/delay.h>

void LCD_vidWriteCommand(u8 command)
{
	DIO_vidWritePin(COMMAND_PORT,RS,0);//command
	DIO_vidWritePin(COMMAND_PORT,RW,0);//write
	DIO_vidWritePin(DATAPORT,DB7,((command>>7)& 1));
	DIO_vidWritePin(DATAPORT,DB6,((command>>6)& 1));
	DIO_vidWritePin(DATAPORT,DB5,((command>>5)& 1));
	DIO_vidWritePin(DATAPORT,DB4,((command>>4)& 1));
	PULSE();
	DIO_vidWritePin(DATAPORT,DB7,((command>>3)& 1));
	DIO_vidWritePin(DATAPORT,DB6,((command>>2)& 1));
	DIO_vidWritePin(DATAPORT,DB5,((command>>1)& 1));
	DIO_vidWritePin(DATAPORT,DB4,((command>>0)& 1));
	PULSE();
}
void LCD_vidWriteData(u8 data)
{
	DIO_vidWritePin(COMMAND_PORT,RS,1);//data
	DIO_vidWritePin(COMMAND_PORT,RW,0);//write
	DIO_vidWritePin(DATAPORT,DB7,((data>>7)& 1));
	DIO_vidWritePin(DATAPORT,DB6,((data>>6)& 1));
	DIO_vidWritePin(DATAPORT,DB5,((data>>5)& 1));
	DIO_vidWritePin(DATAPORT,DB4,((data>>4)& 1));
	PULSE();
	DIO_vidWritePin(DATAPORT,DB7,((data>>3)& 1));
	DIO_vidWritePin(DATAPORT,DB6,((data>>2)& 1));
	DIO_vidWritePin(DATAPORT,DB5,((data>>1)& 1));
	DIO_vidWritePin(DATAPORT,DB4,((data>>0)& 1));
	PULSE();
	_delay_us(50);
}
void LCD_vidInit(void)
{
	DIO_vidSetPinDirection(COMMAND_PORT,RS,OUTPUT);
	DIO_vidSetPinDirection(COMMAND_PORT,RW,OUTPUT);
	DIO_vidSetPinDirection(COMMAND_PORT,EN,OUTPUT);
	DIO_vidSetPinDirection(DATAPORT,DB4,OUTPUT);
	DIO_vidSetPinDirection(DATAPORT,DB5,OUTPUT);
	DIO_vidSetPinDirection(DATAPORT,DB6,OUTPUT);
	DIO_vidSetPinDirection(DATAPORT,DB7,OUTPUT);
	_delay_ms(50);
	DIO_vidWritePin(COMMAND_PORT,RS,0);//command
	DIO_vidWritePin(COMMAND_PORT,RW,0);//write
	DIO_vidWritePin(DATAPORT,DB7,0);
	DIO_vidWritePin(DATAPORT,DB6,0);
	DIO_vidWritePin(DATAPORT,DB5,1);
	DIO_vidWritePin(DATAPORT,DB4,0);
	PULSE();
	LCD_vidWriteCommand(0b00101000);//function set [4bit-2 lines -5*7 dot font]
	_delay_us(40);
	LCD_vidWriteCommand(0b00001100);//display control [display on-cursor off-blinking off]
	_delay_us(40);
	LCD_vidWriteCommand(0b00000001);//clear display
	_delay_us(1600);
	LCD_vidWriteCommand(0b00000110);//entry mode set[cursor increment-display shift off]
	_delay_us(40);

}
void LCD_vidClear(void)
{
	LCD_vidWriteCommand(0b00000001);//[display clear]
	_delay_us(1600);
}
void LCD_vidSetDisplayAdrr(u8 addr)
{

	LCD_vidWriteCommand(0b10000000 | addr);//[set DDRAM address]
	_delay_us(40);
}
void LCD_vidSetCGRamAdrr(u8 addr)
{
	LCD_vidWriteCommand(0b01000000 | addr);//[set CGRAM address]
		_delay_us(40);
}
extern void LCD_vidSetCustomChar(u8 charnum,u8 pattern[8])
{
	u8 j=0;
	switch(charnum)
	{
	case 0:LCD_vidSetCGRamAdrr(0b00000000);break;
	case 1:LCD_vidSetCGRamAdrr(0x08);break;
	case 2:LCD_vidSetCGRamAdrr(0b00010000);break;
	case 3:LCD_vidSetCGRamAdrr(0b00011000);break;
	case 4:LCD_vidSetCGRamAdrr(0b00100000);break;
	case 5:LCD_vidSetCGRamAdrr(0b00101000);break;
	case 6:LCD_vidSetCGRamAdrr(0b00110000);break;
	case 7:LCD_vidSetCGRamAdrr(0b00111000);break;

	}

		for(j=0;j<8;j++)
		{
	LCD_vidWriteData(pattern[j]);

	}
		LCD_vidSetDisplayAdrr(0x00);
}
extern void LCD_IncCursor(u8 step)
{
	u8 i=0;
	for(i=0;i<step;i++){
	LCD_vidWriteCommand(0b00010100);//[increment cursor]
		_delay_ms(40);
	}

}
extern void LCD_DecCursor(u8 step)
{
	u8 i=0;
		for(i=0;i<step;i++){
		LCD_vidWriteCommand(0b00010000);//[decrement cursor]
			_delay_us(40);
		}
}
void LCD_DelChar(void)
{
	LCD_DecCursor(1);
	LCD_vidWriteData(' ');
	LCD_DecCursor(1);
}
void LCD_vidWriteString(u8*string)
{
	while(*string)
	{
		LCD_vidWriteData(*string++);
	}
}
extern void LCD_vidWriteInt(int data)
{
	u8 buffer[12];
	itoa(data,buffer,10);
	LCD_vidWriteString(buffer);

}
void LCD_vidWriteFloat(float data)
{
	u8 buffer[12];
	int d=(int)data;
	itoa(d,buffer,10);
	LCD_vidWriteString(buffer);
	buffer[0]=0;
	LCD_vidWriteData('.');
	float f=data-d;
	f*=10000;
	f=(int)f;
	itoa(f,buffer,10);
	LCD_vidWriteString(buffer);
}
