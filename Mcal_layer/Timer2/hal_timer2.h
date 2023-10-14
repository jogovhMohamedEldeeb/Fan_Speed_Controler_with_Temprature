/* 
 * File:   hal_timer2.h
 * Author: m7md
 *
 * Created on 11 September 2023, 21:02
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

/*************************** Includes ********************/
#include "../../Mcal_layer/GPIO/hal_gpio.h"

/*************************** Macros declaration  ********************/


/*************************** Macros declaration function  ********************/
#define TIMER2_MODULE_ENABLE()      (T2CONbits.TMR2ON = 1)
#define TIMER2_MODULE_DISABLE()      (T2CONbits.TMR2ON = 0)

#define TIMER2_PRESCALER_WRITE_VALUE(prescaler_value)       (T2CONbits.T2CKPS = prescaler_value)
#define TIMER2_POSTSCALER_WRITE_VALUE(postscaler_value)     (T2CONbits.TOUTPS = postscaler_value)

#define TIMER2_WRITE_VALUE(value)   (TMR2 = value)

/***************************  Types declaration  ********************/
typedef enum{
    TIMER2_PRESCALER_DIV_1 = 0,
    TIMER2_PRESCALER_DIV_4,
    TIMER2_PRESCALER_DIV_16
} timer2_prescaler_value_t;


typedef enum{
    TIMER2_POSTSCALER_DIV_1 = 0,
    TIMER2_POSTSCALER_DIV_2,
    TIMER2_POSTSCALER_DIV_3,
    TIMER2_POSTSCALER_DIV_4,
    TIMER2_POSTSCALER_DIV_5,
    TIMER2_POSTSCALER_DIV_6,
    TIMER2_POSTSCALER_DIV_7,
    TIMER2_POSTSCALER_DIV_8,
    TIMER2_POSTSCALER_DIV_9,
    TIMER2_POSTSCALER_DIV_10,
    TIMER2_POSTSCALER_DIV_11,
    TIMER2_POSTSCALER_DIV_12,
    TIMER2_POSTSCALER_DIV_13,
    TIMER2_POSTSCALER_DIV_14,
    TIMER2_POSTSCALER_DIV_15,
    TIMER2_POSTSCALER_DIV_16
} timer2_postscaler_value_t;

typedef struct{
    uint8 preload_value;
    timer2_postscaler_value_t postscaler_value;
    timer2_prescaler_value_t prescaler_value;
} timer2_t;

/***************************  Software interface  ********************/
Std_ReturnType timer2_intialize(const timer2_t *_timer);
#endif	/* HAL_TIMER2_H */

