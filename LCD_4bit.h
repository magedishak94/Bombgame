#ifndef LCD_4bit_h_
#define LCD_4bit_h_


/* DDRAM addresses:
0x00---------------0x0f
0x40---------------0x4f
*/
#define COMMAND_PORT PORTC
#define RS PIN0
#define RW PIN1
#define EN PIN2
#define DATAPORT PORTC// data lines are pin4 5 6 7
#define DB4 PIN4
#define DB5 PIN5
#define DB6 PIN6
#define DB7 PIN7
#define LINE2 0x40
#define CC0 0x00
#define CC1 0x01
#define CC2 0x02
#define CC3 0x03
#define CC4 0x04
#define CC5 0x05
#define CC6 0x06
#define CC7 0x07
#define PULSE() {DIO_vidWritePin(COMMAND_PORT,EN,0);\
	            DIO_vidWritePin(COMMAND_PORT,EN,1);\
	            _delay_us(1);\
	            DIO_vidWritePin(COMMAND_PORT,EN,0);}


extern void LCD_vidInit(void);
extern void LCD_vidWriteCommand(u8 command);
extern void LCD_vidWriteData(u8 data);
extern void LCD_vidWriteString(u8*string);
extern void LCD_vidWriteInt(int data);
extern void LCD_vidWriteFloat(float data);
extern void LCD_vidClear(void);
extern void LCD_IncCursor(u8 step);
extern void LCD_DecCursor(u8 step);
extern void LCD_DelChar(void);
extern void LCD_vidSetDisplayAdrr(u8 addr);
extern void LCD_vidSetCGRamAdrr(u8 addr);
extern void LCD_vidSetCustomChar(u8 charnum,u8 pattern[8]);





#endif
