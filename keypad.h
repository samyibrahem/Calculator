/*
 * keypad.h
 *
 *  Created on: Feb 11, 2022
 *      Author: Samy
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include"std_types.h"

#define N_COL 4
#define N_ROW 4
#define KEYPAD_PORT PORTA_ID
#define KEYPAD_ROW PIN0_ID
#define KEYPAD_COL PIN4_ID

#define BUTTON_PRESSED LOGIC_HIGH
#define BUTTON_RELEASED LOGIC_LOW

uint8 KEYPAD_getPressedKey(void);
#endif /* KEYPAD_H_ */
