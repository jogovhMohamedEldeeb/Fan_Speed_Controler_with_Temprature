/* 
 * File:   app.c
 * Author: m7md
 *
 * Created on 11 September 2023, 00:50
 */

#include "app.h"
lcd_8bit_t lcd = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = GPIO_PIN6,
    .lcd_rs.direction = GPIO_direction_output,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_enable.port = PORTC_INDEX,
    .lcd_enable.pin = GPIO_PIN7,
    .lcd_enable.direction = GPIO_direction_output,
    .lcd_enable.logic = GPIO_LOW,
    
    .data_lines[0].port = PORTD_INDEX,
    .data_lines[0].pin = GPIO_PIN0,
    .data_lines[0].direction = GPIO_direction_output,
    .data_lines[0].logic = GPIO_LOW,
    .data_lines[1].port = PORTD_INDEX,
    .data_lines[1].pin = GPIO_PIN1,
    .data_lines[1].direction = GPIO_direction_output,
    .data_lines[1].logic = GPIO_LOW,
    .data_lines[2].port = PORTD_INDEX,
    .data_lines[2].pin = GPIO_PIN2,
    .data_lines[2].direction = GPIO_direction_output,
    .data_lines[2].logic = GPIO_LOW,
    .data_lines[3].port = PORTD_INDEX,
    .data_lines[3].pin = GPIO_PIN3,
    .data_lines[3].direction = GPIO_direction_output,
    .data_lines[3].logic = GPIO_LOW,
    .data_lines[4].port = PORTD_INDEX,
    .data_lines[4].pin = GPIO_PIN4,
    .data_lines[4].direction = GPIO_direction_output,
    .data_lines[4].logic = GPIO_LOW,
    .data_lines[5].port = PORTD_INDEX,
    .data_lines[5].pin = GPIO_PIN5,
    .data_lines[5].direction = GPIO_direction_output,
    .data_lines[5].logic = GPIO_LOW,
    .data_lines[6].port = PORTD_INDEX,
    .data_lines[6].pin = GPIO_PIN6,
    .data_lines[6].direction = GPIO_direction_output,
    .data_lines[6].logic = GPIO_LOW,
    .data_lines[7].port = PORTD_INDEX,
    .data_lines[7].pin = GPIO_PIN7,
    .data_lines[7].direction = GPIO_direction_output,
    .data_lines[7].logic = GPIO_LOW
};

motor_t motor = {
    .motor_pin[0].port = PORTC_INDEX,
    .motor_pin[0].pin = GPIO_PIN0,
    .motor_pin[0].direction = GPIO_direction_output,
    .motor_pin[0].logic = GPIO_LOW,
    .motor_pin[1].port = PORTC_INDEX,
    .motor_pin[1].pin = GPIO_PIN1,
    .motor_pin[1].direction = GPIO_direction_output,
    .motor_pin[1].logic = GPIO_LOW
};

adc_config_t adc = {
    .aquisition_time = ADC_12_TAD,
    .conversion_clock = ADC_FOSC_DIV_16,
    .channel = ANALOG_CHANNEL_AN0,
    .format_justification = REAULT_FORAMT_RIGHT_JUSTIFIED,
    .voltage_refrence = DISABLE_VOLTAGE_REFERENCE
};
pwm_t pwm = {
    .pwm_frequency = 5000,
    .timer2_postscaler_value = CCP1_TIMER2_POSTSCALER_DIV_1,
    .timer2_prescaler_value = CCP1_TIMER2_PRESCALER_DIV_1
};

timer2_t timer2 = {
    .postscaler_value = TIMER2_POSTSCALER_DIV_1,
    .prescaler_value = TIMER2_PRESCALER_DIV_1,
    .preload_value = 0
};

uint16 lm35_value, lm35_value_in_celsuis;
uint8 lm35_value_text[4];

uint8 temperature_level;

int main() {
    Std_ReturnType ret = E_OK;
    app_init();
    
    ret = lcd_8bit_send_string(&lcd,"FAN OFF -LEVEL  ");
    ret = lcd_8bit_send_string_pos(&lcd,2,4,"TEMP: ");
    ret = lcd_8bit_send_char_pos(&lcd,2,13,'C');
    
    ret = motor_move(&motor);
    while(1){
        /* Reading AD0 channel "Temperature sensor value" */
        ret = ADC_getConversionBlocking(&adc,ANALOG_CHANNEL_AN0,&lm35_value);
        /* Convert output of LM35 to Celsuis [(step_size = Vref/resolution) -> (5/2^10 = 4.88)] */
        lm35_value_in_celsuis = lm35_value * 4.88f;
        lm35_value_in_celsuis = round(lm35_value_in_celsuis / 10.0);
        /* Converting the number into string and Display the temperature on the screen */
        ret = lcd_convert_byte_to_string(lm35_value_in_celsuis,lm35_value_text);
        ret = lcd_8bit_send_string_pos(&lcd,2,10,lm35_value_text);
        /* Setting duty cycle to control the speed of fan with respect to temperature value */
        if(lm35_value_in_celsuis > 120){
            temperature_level = '5';
            ret = CCP1_PWM_Set_Duty(100);
        }
        else if(lm35_value_in_celsuis > 90){
            temperature_level = '4';
            ret = CCP1_PWM_Set_Duty(80);
        }
        else if(lm35_value_in_celsuis > 70){
            temperature_level = '3';
            ret = CCP1_PWM_Set_Duty(60);
        }
        else if(lm35_value_in_celsuis > 50){
            temperature_level = '2';
            ret = CCP1_PWM_Set_Duty(40);
        }
        else if(lm35_value_in_celsuis > 25){
            temperature_level = '1';
            ret = CCP1_PWM_Set_Duty(25);
        }
        else{
            temperature_level = '0';
            ret = CCP1_PWM_Set_Duty(0);
            ret = lcd_8bit_send_string_pos(&lcd,1,5,"OFF");
        }
        if('0' != temperature_level){
            ret = lcd_8bit_send_string_pos(&lcd,1,5,"ON");
        }
        /* Displaying Temperature level */
        ret = lcd_8bit_send_char_pos(&lcd, 1, 16, temperature_level);

    }
    return (EXIT_SUCCESS);
}

void app_init(void){
    Std_ReturnType ret = E_OK;
    ret = lcd_8bit_intialize(&lcd);
    ret = ADC_intialize(&adc);
    ret = CCP1_PWM_Intialize(&pwm);
    ret = timer2_intialize(&timer2);
    ret = motor_intialize(&motor);
}
