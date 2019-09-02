/*
 * TIM0_prog.c
 *
 *  Created on: 28 Jun 2019
 *      Author: maged
 */

#include "StdTypes.h"
#include "Utils.h"
#include "TIM0_priv.h"
#include "TIM0_CFG.h"
#include "TIM0_INT.h"

void TIM0_vidInit(void)
{
	if(TIMER_MODE==NORMAL_MODE)
	{
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		SET_BIT(TIMSK,TOIE0);
	}
	else if(TIMER_MODE==CTC_MODE)
			{
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TIMSK,OCIE0);
			}
	TCCR0 |=PRESCALER_SELECT;
}

void TIM0_vidSetTimerval(u8 u8CNT)
{
	TCNT0=u8CNT;
}

void TIM0_vidSetTimerCmpVal(u8 u8CNT)
{
	OCR0=u8CNT;
}
