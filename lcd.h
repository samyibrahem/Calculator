/*[
 * lcd.h
 *
 *  Created on: Feb 11, 2022
 *      Author: Samy
 */

#ifndef LCD_H_
#define LCD_H_
#include "std_types.h"
#define LCD_4BITS_MODE TRUE

#define LCD_RS_PORT PORTB_ID
#define LCD_RS_PIN PIN1_ID
#define LCD_RW_PORT PORTB_ID
#define LCD_RW_PIN PIN2_ID
#define LCD_E_PORT PORTB_ID
#define LCD_E_PIN PIN3_ID

#define LCD_DATA_PORT PORTD_ID
#if(LCD_4BITS_MODE == TRUE)
#define FIRST_4_BITS
#ifdef FIRST_4_BITS
#define LCD_DATA_PIN PIN0_ID
#else
#define LCD_DATA_PIN PIN4_ID
#endif
#endif

#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define CLEAR_DISPLAY 0x01
#define DISPLAY_ON_CURSOR_ON 0x0E
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_SET_CURSOR_LOCATION        0x80


void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 character);
void LCD_displayString(uint8 *str);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,uint8 *str);
void LCD_clearScreen(void);
void LCD_intgerToString(int data);

#endif /* LCD_H_ */
