/*
 ============================================================================
 Name        : main.c
 Author      : samy ibrahem
 Description : Integrate the Keypad and LCD drivers to make a Calculator.
 Date        : 14/2/2022
 ============================================================================
 */
#include "lcd.h"
#include "keypad.h"
#include <util/delay.h>/* For the delay functions */
int main (void){
LCD_init();

uint8 key=0;/* variable to hold the pressed key value */
uint8 num=0;/* variable to hold the first number value*/
uint8 num1=0;/* variable to hold the second number value*/
sint16 result=0;/* variable to hold the result value & signed short to hold values from -32768 .. +32767*/
uint8 op=0;/* variable to hold the operation*/
	    while(1)
	    {
	    	LCD_displayString("Samy KEYPAD");/*calculator start display string*/

	    	key=KEYPAD_getPressedKey();/*get the value of the pressed key*/
	    	LCD_moveCursor(2,0);/*move the cursor to the next line to display numbers*/
	    	while((key>= 0) && (key<=9)){/*while a number is getting pressed the while loop are looping until an operation pressed on
	    	                              then the while loop exits */
	    	  LCD_intgerToString(key); /*the LCD Prints the pressed key*/
	    	  num=num*10+key;/* the number pressed is mult by *10 and add to key to hold the next digit
	    	    		               ex: num =2 and you pressed 3 then num=2*10 =20 +3 = 23 */
	    	  _delay_ms(300);/* delay 300ms to enter the value of number only once ex: if 2 is pressed display only 2 not 2222222 */
	    	  key=KEYPAD_getPressedKey();/*check the pressed key again if number continue looping else exit the loop to get
	    	    		operation*/
	    	    	}
	    	LCD_displayCharacter(key); /* display the operation selected */
	    		    	op=key; /*put the selected operation in op variable */
	    		    	_delay_ms(300);/* delay 300ms to enter the operation button only once*/

	        key=KEYPAD_getPressedKey();/*get the value of the pressed key*/
	        while((key>= 0) && (key<=9)){ /*while a number is getting pressed the while loop are looping until an operation pressed on
	    	                              then the while loop exits */
	    	  LCD_intgerToString(key);/*the LCD Prints the pressed key*/
	    	  num1=num1*10+key;/* the number pressed is mult by *10 and add to key to hold the next digit
	    	    		               ex: num =2 and you pressed 3 then num=2*10 =20 +3 = 23 */
	    	  _delay_ms(300);/* delay 300ms to enter the value of number only once ex: if 2 is pressed display only 2 not 2222222 */
	          key=KEYPAD_getPressedKey();/*check the pressed key again if number continue looping else exit the loop to get
	    	    		result of the operation*/
	    		    	    	}
	    LCD_moveCursor(3,0);/*move cursor to the next line to display the result in new line */
	    LCD_displayCharacter(key);/*display the (=) */
	   	_delay_ms(300);/* delay 300ms to enter the result once*/


	switch(op){ /* switch to apply the selected operation */
	     case '+':/*in case of + */
         result=num+num1; /*the result equal the add of two numbers */
	 break;/* break out of switch */
	     case '-':/* in case of -*/
		 result=num-num1;/*the result equal the sub of two numbers */
    break;
 	     case '*':/*in case of X */

	     result=num*num1;/*the result equal the mult of two numbers */
	break;
	     case '/':/*in case of / */

	   	result=num/num1;/*the result equal the div of two numbers */
	break;
	}
	LCD_intgerToString(result);/* print the result of the operation on the LCD*/
	key=0;/* reset all the variables and wait for new operation*/
	num=0;
    num1=0;
    result=0;
	LCD_moveCursor(4,0);/*move the cursor on new line */
	LCD_displayString("PRESS ON FOR NEW");/*notify the user to press on button to get new operation */

	    	if((KEYPAD_getPressedKey()) ==13){ /* if user pressed the on button clear the screen and start new operation */
	    	LCD_clearScreen();


	    	}
	    	_delay_ms(300);
	    }
}
