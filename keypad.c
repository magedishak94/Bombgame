#include "StdTypes.h"
#include "DIO_MemMap.h"
#include "DIO_Interface.h"
#include "Utils.h"
/*
 r1  a0    c1 a4
 r2  a1    c2 a5
 r3  a2    c3 a6
 r4  a3    c4 a7
 */
u8 keypad_u8getkey(void)
{
	//check colomn 1
	DIO_vidWritePin(PORTA,PIN4,0);
	DIO_vidWritePin(PORTA,PIN5,1);
	DIO_vidWritePin(PORTA,PIN6,1);
	DIO_vidWritePin(PORTA,PIN7,1);
	if((DIO_u8ReadPin(PORTA,PIN0))==0)
		return 1;
	else if((DIO_u8ReadPin(PORTA,PIN1))==0)
		return 4;
	else if((DIO_u8ReadPin(PORTA,PIN2))==0)
		return 7;
	else if((DIO_u8ReadPin(PORTA,PIN3))==0)
		return '*';
	//check colomn 2
	DIO_vidWritePin(PORTA,PIN4,1);
	DIO_vidWritePin(PORTA,PIN5,0);
	DIO_vidWritePin(PORTA,PIN6,1);
	DIO_vidWritePin(PORTA,PIN7,1);
		if((DIO_u8ReadPin(PORTA,PIN0))==0)
			return 2;
		else if((DIO_u8ReadPin(PORTA,PIN1))==0)
			return 5;
		else if((DIO_u8ReadPin(PORTA,PIN2))==0)
			return 8;
		else if((DIO_u8ReadPin(PORTA,PIN3))==0)
			return 0;
	//check colomn 3
	DIO_vidWritePin(PORTA,PIN4,1);
	DIO_vidWritePin(PORTA,PIN5,1);
	DIO_vidWritePin(PORTA,PIN6,0);
	DIO_vidWritePin(PORTA,PIN7,1);
		if(DIO_u8ReadPin(PORTA,PIN0)==0)
					return 3;
		else if((DIO_u8ReadPin(PORTA,PIN1))==0)
					return 6;
		else if((DIO_u8ReadPin(PORTA,PIN2))==0)
					return 9;
		else if((DIO_u8ReadPin(PORTA,PIN3))==0)
					return '#';
	//check colomn 4
	DIO_vidWritePin(PORTA,PIN4,1);
	DIO_vidWritePin(PORTA,PIN5,1);
	DIO_vidWritePin(PORTA,PIN6,1);
	DIO_vidWritePin(PORTA,PIN7,0);
		if(DIO_u8ReadPin(PORTA,PIN0)==0)
					return 'a';
		else if((DIO_u8ReadPin(PORTA,PIN1))==0)
					return 'b';
		else if((DIO_u8ReadPin(PORTA,PIN2))==0)
					return 'c';
		else if((DIO_u8ReadPin(PORTA,PIN3))==0)
					return 'd';
		return'e';
}
