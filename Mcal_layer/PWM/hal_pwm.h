/* 
 * File:   hal_pwm.h
 * Author: m7md
 *
 * Created on 12 September 2023, 00:02
 */

#ifndef HAL_PWM_H
#define	HAL_PWM_H
/*************************** Includes ********************/
#include "../../Mcal_layer/GPIO/hal_gpio.h"

/*************************** Macros declaration  ********************/
#define CCP1_MODULE_DISABLE              0x00
#define CCP1_PWM_MODE                    0x0F

/*************************** Macros declaration function  ********************/
#define CCP1_SELECT_MODE(_MODE)     (CCP1CONbits.CCP1M = _MODE)

/***************************  Types declaration  ********************/
typedef enum{
    CCP1_TIMER2_PRESCALER_DIV_1 = 1,
    CCP1_TIMER2_PRESCALER_DIV_4 = 4,
    CCP1_TIMER2_PRESCALER_DIV_16 = 16
} ccp1_prescaler_value_t;

typedef enum{
    CCP1_TIMER2_POSTSCALER_DIV_1 = 1,
    CCP1_TIMER2_POSTSCALER_DIV_2,
    CCP1_TIMER2_POSTSCALER_DIV_3,
    CCP1_TIMER2_POSTSCALER_DIV_4,
    CCP1_TIMER2_POSTSCALER_DIV_5,
    CCP1_TIMER2_POSTSCALER_DIV_6,
    CCP1_TIMER2_POSTSCALER_DIV_7,
    CCP1_TIMER2_POSTSCALER_DIV_8,
    CCP1_TIMER2_POSTSCALER_DIV_9,
    CCP1_TIMER2_POSTSCALER_DIV_10,
    CCP1_TIMER2_POSTSCALER_DIV_11,
    CCP1_TIMER2_POSTSCALER_DIV_12,
    CCP1_TIMER2_POSTSCALER_DIV_13,
    CCP1_TIMER2_POSTSCALER_DIV_14,
    CCP1_TIMER2_POSTSCALER_DIV_15,
    CCP1_TIMER2_POSTSCALER_DIV_16
} ccp1_postscaler_value_t;

typedef struct{
    uint32 pwm_frequency;
    ccp1_postscaler_value_t timer2_postscaler_value;
    ccp1_prescaler_value_t timer2_prescaler_value;
} pwm_t;

/***************************  Software interface  ********************/
Std_ReturnType CCP1_PWM_Intialize(const pwm_t *pwm);
Std_ReturnType CCP1_PWM_Set_Duty(uint8 duty);


#endif	/* HAL_PWM_H */

