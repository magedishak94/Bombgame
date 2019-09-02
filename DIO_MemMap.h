#ifndef DIO_MEMMAP_H_
#define DIO_MEMMAP_H_

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PORTA_REG (*(volatile u8*)(0x3B))
#define PORTB_REG (*(volatile u8*)(0x38))
#define PORTC_REG (*(volatile u8*)(0x35))
#define PORTD_REG (*(volatile u8*)(0x32))

#define DDRA_REG (*(volatile u8*)(0x3A))
#define DDRB_REG (*(volatile u8*)(0x37))
#define DDRC_REG (*(volatile u8*)(0x34))
#define DDRD_REG (*(volatile u8*)(0x31))

#define PINA_REG (*(volatile u8*)(0x39))
#define PINB_REG (*(volatile u8*)(0x36))
#define PINC_REG (*(volatile u8*)(0x33))
#define PIND_REG (*(volatile u8*)(0x30))

#endif
