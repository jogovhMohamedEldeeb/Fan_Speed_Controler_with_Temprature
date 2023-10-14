/* 
 * File:   hal_timer2.c
 * Author: m7md
 *
 * Created on 11 September 2023, 21:02
 */

#include "hal_timer2.h"

static uint8 tmr2_preload_value; 

Std_ReturnType timer2_intialize(const timer2_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _timer){
        ret = E_OK;
        
        /* Disable timer2 */
        TIMER2_MODULE_DISABLE();
        /* Set prescaler */
        TIMER2_PRESCALER_WRITE_VALUE(_timer->prescaler_value);
        /* Set postscaler*/
        TIMER2_POSTSCALER_WRITE_VALUE(_timer->postscaler_value);
        /* write preloaded value*/
        TIMER2_WRITE_VALUE(_timer->preload_value);
        tmr2_preload_value = _timer->preload_value;
        /* Enable timer2*/
        TIMER2_MODULE_ENABLE();
    }
    return ret;
}