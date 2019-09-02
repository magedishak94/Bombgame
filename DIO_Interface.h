#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define LOW_VOLTAGE 0
#define HIGH_VOLTAGE 1
#define OUTPUT 1
#define INFREE 2
#define INPULLUP 3

extern void DIO_vidSetPinDirection(u8 PortIdCopy,u8 PinIdCopy,u8 direction);
extern void DIO_vidSetPortDirection(u8 PortIdCopy,u8 directionMask);

extern void DIO_vidWritePin(u8 PortIdCopy,u8 PinIdCopy,u8 v);
extern void DIO_vidWritePort(u8 PortIdCopy,u8 v);

extern u8 DIO_u8ReadPin(u8 PortIdCopy,u8 PinIdCopy);
extern u8 DIO_u8ReadPort(u8 PortIdCopy);

extern void DIO_vidTogglePin(u8 PortIdCopy,u8 PinIdCopy);

#endif
