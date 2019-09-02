/*
 * BOMB_input.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: maged & adly
 */

#ifndef BOMB_INPUT_H_
#define BOMB_INPUT_H_

enum phases{
	intiate_bomb,
	countdown,
	deactivated,
	boom
};
//enum phases g_phase;

void BMB_input_time(void);
void BMB_input_password(void);

#endif /* BOMB_INPUT_H_ */
