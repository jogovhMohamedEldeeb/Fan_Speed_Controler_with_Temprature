/* 
 * File:   ecu_motor.h
 * Author: m7md
 *
 * Created on 11 September 2023, 21:36
 */

#ifndef ECU_MOTOR_H
#define	ECU_MOTOR_H
/*************************** Includes ********************/
#include "../../Mcal_layer/GPIO/hal_gpio.h"

/*************************** Macros declaration  ********************/
#define MOTOR_OFF   0x00
#define MOTOR_ON    0x01

#define MOTOR_PIN_1  0x00
#define MOTOR_PIN_2  0x01

/*************************** Macros declaration function  ********************/


/*************************** Types declaration  ********************/
typedef struct{
    pin_config_t motor_pin[2];
}motor_t;


/*************************** Software interface  ********************/
Std_ReturnType motor_intialize(const motor_t* motor);
Std_ReturnType motor_move(const motor_t* motor);


#endif	/* ECU_MOTOR_H */

