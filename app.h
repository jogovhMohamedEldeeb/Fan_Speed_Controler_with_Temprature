/* 
 * File:   app.h
 * Author: m7md
 *
 * Created on 11 September 2023, 00:51
 */

#ifndef APP_H
#define	APP_H
#include "Mcal_layer/GPIO/hal_gpio.h"
#include "Ecu_layer/LCD/ecu_lcd.h"
#include "Mcal_layer/ADC/hal_adc.h"
#include "Mcal_layer/Timer2/hal_timer2.h"
#include "Ecu_layer/Motor/ecu_motor.h"
#include "Mcal_layer/PWM/hal_pwm.h"
void app_init(void);

#endif	/* APP_H */


