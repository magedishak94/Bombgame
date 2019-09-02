#include "StdTypes.h"
#include "DIO_MemMap.h"
#include "DIO_Interface.h"
#include "Utils.h"
void DIO_vidSetPinDirection(u8 PortIdCopy,u8 PinIdCopy,u8 direction)
{
	if((PortIdCopy<=PORTD)&&(PinIdCopy<=PIN7))
	{
		if(direction==OUTPUT)
		{
			switch(PortIdCopy)
			{
				case 0:SET_BIT(DDRA_REG,PinIdCopy); break;
				case 1:SET_BIT(DDRB_REG,PinIdCopy); break;
				case 2:SET_BIT(DDRC_REG,PinIdCopy); break;
				case 3:SET_BIT(DDRD_REG,PinIdCopy); break;
			}
		}
		else if(direction==INFREE)
		{
			switch(PortIdCopy)
			{
				case 0:CLR_BIT(DDRA_REG,PinIdCopy); break;
				case 1:CLR_BIT(DDRB_REG,PinIdCopy); break;
				case 2:CLR_BIT(DDRC_REG,PinIdCopy); break;
				case 3:CLR_BIT(DDRD_REG,PinIdCopy); break;
			}
		}
		else{
			switch(PortIdCopy)
			{
				case 0:CLR_BIT(DDRA_REG,PinIdCopy);
				       SET_BIT(PORTA_REG,PinIdCopy);
				       break;
				case 1:CLR_BIT(DDRB_REG,PinIdCopy);
				       SET_BIT(PORTB_REG,PinIdCopy);
				       break;
				case 2:CLR_BIT(DDRC_REG,PinIdCopy);
				       SET_BIT(PORTC_REG,PinIdCopy);
				       break;
				case 3:CLR_BIT(DDRD_REG,PinIdCopy);
				       SET_BIT(PORTD_REG,PinIdCopy);
				       break;
			}
		}
	}
}
void DIO_vidSetPortDirection(u8 PortIdCopy,u8 directionMask)
{
	if(PortIdCopy<=PORTD)
	{
	  switch(PortIdCopy)
	  {
		  case PORTA:DDRA_REG=directionMask;break;
		  case PORTB:DDRB_REG=directionMask;break;
		  case PORTC:DDRC_REG=directionMask;break;
		  case PORTD:DDRD_REG=directionMask;break;
	  }
	}
else{
	//do nothing
}
}
void DIO_vidWritePin(u8 PortIdCopy,u8 PinIdCopy,u8 v)
{
	if((PortIdCopy<=PORTD)&&(PinIdCopy<=PIN7))
	{
		if(v==HIGH_VOLTAGE)
		{
			switch(PortIdCopy)
			{
				case PORTA:SET_BIT(PORTA_REG,PinIdCopy);break;
				case PORTB:SET_BIT(PORTB_REG,PinIdCopy);break;
				case PORTC:SET_BIT(PORTC_REG,PinIdCopy);break;
				case PORTD:SET_BIT(PORTD_REG,PinIdCopy);break;
			}
		}
		else{
			switch(PortIdCopy)
			{
				case PORTA:CLR_BIT(PORTA_REG,PinIdCopy);break;
				case PORTB:CLR_BIT(PORTB_REG,PinIdCopy);break;
				case PORTC:CLR_BIT(PORTC_REG,PinIdCopy);break;
				case PORTD:CLR_BIT(PORTD_REG,PinIdCopy);break;
			}
		}
	}
	else{
		//do nothing
	}
}
void DIO_vidWritePort(u8 PortIdCopy,u8 v)
{
	if(PortIdCopy<=PORTD)
	{
	switch(PortIdCopy)
			{
				case PORTA:PORTA_REG=v;break;
				case PORTB:PORTB_REG=v;break;
				case PORTC:PORTC_REG=v;break;
				case PORTD:PORTD_REG=v;break;
			}
	}
}
u8 DIO_u8ReadPin(u8 PortIdCopy,u8 PinIdCopy)
{
	u8 u8localresult;
	if((PortIdCopy<=PORTD)&&(PinIdCopy<=PIN7))
	{
		switch(PortIdCopy)
					{
						case PORTA:u8localresult=GET_BIT(PINA_REG,PinIdCopy);break;
						case PORTB:u8localresult=GET_BIT(PINB_REG,PinIdCopy);break;
						case PORTC:u8localresult=GET_BIT(PINC_REG,PinIdCopy);break;
						case PORTD:u8localresult=GET_BIT(PIND_REG,PinIdCopy);break;
					}
		return u8localresult;

	}
	else return 0xff;//error
}
u8 DIO_u8ReadPort(u8 PortIdCopy)
{
	u8 u8localresult;
	if(PortIdCopy<=PORTD)
		{
		switch(PortIdCopy)
				{
		                case PORTA:u8localresult=PINA_REG;break;
						case PORTB:u8localresult=PINB_REG;break;
						case PORTC:u8localresult=PINC_REG;break;
						case PORTD:u8localresult=PIND_REG;break;
				}
		return u8localresult;
		}
	//else return 0x00;//error
}

void DIO_vidTogglePin(u8 PortIdCopy,u8 PinIdCopy)
{
	if((PortIdCopy<=PORTD)&&(PinIdCopy<=PIN7))
			{
			switch(PortIdCopy)
					{
			                case PORTA:TOG_BIT(PORTA_REG,PinIdCopy);break;
							case PORTB:TOG_BIT(PORTB_REG,PinIdCopy);break;
							case PORTC:TOG_BIT(PORTC_REG,PinIdCopy);break;
							case PORTD:TOG_BIT(PORTD_REG,PinIdCopy);break;
					}
            }
}
