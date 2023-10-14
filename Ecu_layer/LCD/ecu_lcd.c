/* 
 * File:   ecu_lcd.h
 * Author: m7md
 *
 * Created on 11 September 2023, 01:09
 */

#include "ecu_lcd.h"

static Std_ReturnType send_8bit_enable_signal(const lcd_8bit_t *lcd);
static Std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t *lcd, uint8 row, uint8 colomn);
static void *my_memset(void *StartAddress, uint8 Value, uint8 Length );

Std_ReturnType lcd_8bit_intialize(const lcd_8bit_t *lcd){
    Std_ReturnType ret = E_NOT_OK;
    uint8 l_counter = 0;
    if(NULL != lcd){
        ret = E_OK;
        ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_enable));
        for(l_counter = 0; l_counter < 8; l_counter++){
            ret = gpio_pin_intialize(&(lcd->data_lines[l_counter]));
        }
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        
        ret = lcd_8bit_send_command(lcd, LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd, LCD_CURSOR_HOME);
        ret = lcd_8bit_send_command(lcd, LCD_INCREMENT_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd, LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_8bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        ret = lcd_8bit_send_command(lcd, LCD_DDRAM_START);
    }
    
    return ret ;
}
Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd, uint8 command){
    Std_ReturnType ret = E_NOT_OK;
    uint8 l_counter = 0;
    if(NULL != lcd){
        ret = E_OK;
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
         
        for(l_counter = 0; l_counter < 8; l_counter++){
            ret = gpio_pin_write_logic(&(lcd->data_lines[l_counter]),(command >> l_counter) & 0x01);
        }
        ret = send_8bit_enable_signal(lcd);
    }
    return ret ;
}
Std_ReturnType lcd_8bit_send_char(const lcd_8bit_t *lcd, uint8 data){
    Std_ReturnType ret = E_NOT_OK;
    uint8 l_counter = 0;
    if(NULL != lcd){
        ret = E_OK;
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
         
        for(l_counter = 0; l_counter < 8; l_counter++){
            ret = gpio_pin_write_logic(&(lcd->data_lines[l_counter]),(data >> l_counter) & 0x01);
        }
        ret = send_8bit_enable_signal(lcd);
    }
    return ret ;
}
Std_ReturnType lcd_8bit_send_char_pos(const lcd_8bit_t *lcd, uint8 row, uint8 colomn, uint8 data){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != lcd){
        ret = E_OK;
        ret = lcd_8bit_set_cursor(lcd, row, colomn);
        ret = lcd_8bit_send_char(lcd, data);
    }
    return ret;

}
Std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd, uint8 *string){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != lcd && NULL != string){
        ret = E_OK;
        do{
            lcd_8bit_send_char(lcd, *string);
        } while(*(++string));
    }
    return ret;

}
Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd, uint8 row, uint8 colomn, uint8 *string){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != lcd){
        ret = E_OK;
        ret = lcd_8bit_set_cursor(lcd, row, colomn);
        ret = lcd_8bit_send_string(lcd, string);
    }
    return ret;

}

Std_ReturnType lcd_convert_byte_to_string(uint8 value, uint8 *str){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != str){
        ret = E_OK;
        my_memset(str, '\0', 4);
        sprintf(str, "%i", value);
        
        /* ['2', '3', '\0', '\0'] -> ['2', '3', ' ', '\0'] */
        /* To clear the previous data on screen if it has less digits */
        uint8 index = 0;
        while(++index < 3){
            if('\0' == str[index]){ str[index] = ' '; }
        }
    }

}


static Std_ReturnType send_8bit_enable_signal(const lcd_8bit_t *lcd){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != lcd){
        ret = E_OK;
        ret = gpio_pin_write_logic(&(lcd->lcd_enable), GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_enable), GPIO_LOW);
    }
    return ret;
}

static Std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t *lcd, uint8 row, uint8 colomn){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != lcd && row <= NUMBER_OF_ROWS && colomn <= NUMBER_OF_COLOMNS){
        colomn--; 
        switch(row){
            case ROW1: ret = lcd_8bit_send_command(lcd, (0x80 + colomn));  break;
            case ROW2: ret = lcd_8bit_send_command(lcd, (0xc0 + colomn));  break;
            default:                                                       break;
        }
    }
    return ret; 
}

static void *my_memset(void *StartAddress, uint8 Value, uint8 Length )
{
    uint8 *Ret_val = 0;
    uint8 *TempPtr = StartAddress;

    if(NULL == StartAddress)
    {
        Ret_val = 0;
    }
    else
    {
        while(Length--)
        {
            *TempPtr = Value;
            TempPtr++;
        }
        Ret_val = 1;
    }
    return StartAddress;
}