/* 
 * File:   hal_gpio.h
 * Author: m7md
 *
 * Created on 11 September 2023, 00:52
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*************************** Includes ********************/
#include "../../device_config.h"

/*************************** Macros declaration  ********************/
#define BIT_MASK    (uint8)  1
#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      5


/*************************** Macros declaration function  ********************/
#define     SET_BIT(REG, BIT_POS)       (REG |=  (BIT_MASK << BIT_POS))   
#define     CLEAR_BIT(REG, BIT_POS)     (REG &= ~(BIT_MASK << BIT_POS))   
#define     TOGGLE_BIT(REG, BIT_POS)    (REG ^=  (BIT_MASK << BIT_POS))
#define     READ_BIT(REG, BIT_POS)      ((REG >> BIT_POS) & BIT_MASK)

/***************************  Types declaration  ********************/
typedef enum{
   GPIO_LOW = 0,
   GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_direction_output = 0,
    GPIO_direction_input
}direction_t;

typedef enum{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,       
}pin_index_t;

typedef enum{
    PORTA_INDEX = 0, 
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8 port      : 3; 
    uint8 pin       : 3;     
    uint8 direction : 1;   
    uint8 logic     : 1;     
}pin_config_t;



/***************************  Software interface  ********************/
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config);


#endif	/* HAL_GPIO_H */

