/*
 * keypad.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Samy
 */
#include "gpio.h"
#include "keypad.h"
#include "common_macros.h"
static uint8 KEYPAD_4X4_ADJUST(uint8 button_number);

uint8 KEYPAD_getPressedKey(void){
uint8 row,col;
uint8 keypad_port=0;
while(1){
for(col=0;col<N_COL;col++){
	GPIO_setupPortDirection(KEYPAD_PORT,PORT_INPUT);
GPIO_setupPinDirection(KEYPAD_PORT,KEYPAD_COL+col,PIN_OUTPUT);
keypad_port = (1<<(KEYPAD_COL+col));
GPIO_writePort(KEYPAD_PORT,keypad_port);
for(row=0;row<N_ROW;row++){
	if(GPIO_readPin(KEYPAD_PORT,KEYPAD_ROW+row) == BUTTON_PRESSED){
	return KEYPAD_4X4_ADJUST((row*N_COL)+col+1);
	}
}
}
}
}
static uint8 KEYPAD_4X4_ADJUST(uint8 button_number){
uint8 keypad_button=0;
switch(button_number){
case 1: keypad_button = 7;
				break;
		case 2: keypad_button = 8;
				break;
		case 3: keypad_button = 9;
				break;
		case 4: keypad_button = '/';
				break;
		case 5: keypad_button = 4;
				break;
		case 6: keypad_button = 5;
				break;
		case 7: keypad_button = 6;
				break;
		case 8: keypad_button = '*';
				break;
		case 9: keypad_button = 1;
				break;
		case 10: keypad_button = 2;
				break;
		case 11: keypad_button = 3;
				break;
		case 12: keypad_button = '-';
				break;
		case 13: keypad_button = 13;
				break;
		case 14: keypad_button = 0;
				break;
		case 15: keypad_button = '=';
				break;
		case 16: keypad_button = '+';
				break;
		default: keypad_button = button_number;
						break;

}
return keypad_button;
}

