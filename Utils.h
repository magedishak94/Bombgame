#ifndef UTILS_H_
#define UTILS_H_
#define SET_BIT(Reg,Bit) (Reg |=(1<<Bit))
#define CLR_BIT(Reg,Bit) (Reg &=~(1<<Bit))
#define GET_BIT(Reg,Bit) ((Reg &(1<<Bit))>>Bit)
#define TOG_BIT(Reg,Bit) (Reg ^=(1<<Bit))

#define SET_REG(Reg) (Reg=0xff)
#define CLR_REG(Reg) (Reg=0x00)
#define TOG_REG(Reg) (Reg^=0xff)

#define CLR_LNIBBLE(Reg) (Reg &=0xf0)
#define CLR_HNIBBLE(Reg) (Reg &=0x0f)
#define SET_HNIBBLE(Reg) (Reg |=0xf0)
#define SET_LNIBBLE(Reg) (Reg |=0x0f)

#endif
