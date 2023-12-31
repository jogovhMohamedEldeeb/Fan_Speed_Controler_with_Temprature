/* 
 * File:   ecu_lcd.h
 * Author: m7md
 *
 * Created on 11 September 2023, 01:09
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H
/*************************** Includes ********************/
#include "../../Mcal_layer/GPIO/hal_gpio.h"

/*************************** Macros declaration  ********************/
#define LCD_CLEAR                                   0x01
#define LCD_CURSOR_HOME                             0x02

#define LCD_DECREMENT_SHIFT_OFF                     0x04
#define LCD_DECREMENT_SHIFT_ON                      0x05
#define LCD_INCREMENT_SHIFT_OFF                     0x06
#define LCD_INCREMENT_SHIFT_ON                      0x07

#define LCD_DISPLAY_OFF_UNDERLINE_OFF_CURSOR_OFF    0x08    
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF     0x0C 
#define LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON      0x0D 
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF      0x0E 
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON       0x0F 

#define LCD_MOVE_CURSOR_SHIFT_LEFT                  0x10
#define LCD_MOVE_CURSOR_SHIFT_RIGHT                 0x14
#define LCD_SHIFT_DISPLAY_SHIFT_LEFT                0x18
#define LCD_SHIFT_DISPLAY_SHIFT_RIGHT               0x1C

#define LCD_4BIT_MODE_2LINES                        0x28
#define LCD_8BIT_MODE_2LINES                        0x38

#define LCD_CGRAM_START                             0x40
#define LCD_DDRAM_START                             0x80

#define NUMBER_OF_ROWS          2
#define NUMBER_OF_COLOMNS       16

#define ROW1    1
#define ROW2    2
/*************************** Macros declaration function  ********************/


/***************************  Types declaration  ********************/
typedef struct{         
    pin_config_t lcd_rs;
    pin_config_t lcd_enable;
    pin_config_t data_lines[8];
} lcd_8bit_t;


/***************************  Software interface  ********************/
Std_ReturnType lcd_8bit_intialize(const lcd_8bit_t *lcd);
Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd, uint8 command);
Std_ReturnType lcd_8bit_send_char(const lcd_8bit_t *lcd, uint8 data);
Std_ReturnType lcd_8bit_send_char_pos(const lcd_8bit_t *lcd, uint8 row, uint8 colomn, uint8 data);
Std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd, uint8 *string);
Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd, uint8 row, uint8 colomn, uint8 *string);

Std_ReturnType lcd_convert_byte_to_string(uint8 value, uint8 *str);

#endif	/* ECU_LCD_H */

