/* 
 * File:   hal_adc.h
 * Author: m7md
 *
 * Created on 11 September 2023, 18:20
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H
/*************************** Includes ********************/
#include "../../Mcal_layer/GPIO/hal_gpio.h"

/*************************** Macros declaration  ********************/
#define ADC_ALL_ANALOG           0X00
#define ADC_AN12_DIGITAL         0X03
#define ADC_AN11_DIGITAL         0X04
#define ADC_AN10_DIGITAL         0X05
#define ADC_AN9_DIGITAL          0X06
#define ADC_AN8_DIGITAL          0X07
#define ADC_AN7_DIGITAL          0X08
#define ADC_AN6_DIGITAL          0X09
#define ADC_AN5_DIGITAL          0X0A
#define ADC_AN4_DIGITAL          0X0B
#define ADC_AN3_DIGITAL          0X0C
#define ADC_AN2_DIGITAL          0X0D
#define ADC_AN1_DIGITAL          0X0E
#define ADC_ALL_DIGITAL          0X0F

#define REAULT_FORAMT_RIGHT_JUSTIFIED       1
#define REAULT_FORAMT_LEFT_JUSTIFIED        0

#define ENABLE_VOLTAGE_REFERENCE            1
#define DISABLE_VOLTAGE_REFERENCE           0
/*************************** Macros declaration function  ********************/
#define ADC_MODULE_ENABLE()     (ADCON0bits.ADON = 1)
#define ADC_MODULE_DISABLE()    (ADCON0bits.ADON = 0)

#define ADC_GET_CONVERSION_STATUS()     (ADCON0bits.GO_nDONE)
#define ADC_START_CONVERSION()          (ADCON0bits.GO_nDONE = 1)

#define ADC_ENABLE_VOLTAGE_REFERENCE()      do{ADCON1bits.VCFG1 = 1;\
                                                ADCON1bits.VCFG0 = 1;\
                                                }while(0);

#define ADC_DISABLE_VOLTAGE_REFERENCE()      do{ADCON1bits.VCFG1 = 0;\
                                                ADCON1bits.VCFG0 = 0;\
                                                }while(0);

#define ADC_REAULT_FORAMT_RIGHT_JUSTIFIED()     (ADCON2bits.ADFM = 1)
#define ADC_REAULT_FORAMT_LEFT_JUSTIFIED()      (ADCON2bits.ADFM = 0)

#define ADC_SELECT_CHANNEL(selected_channel)    (ADCON0bits.CHS = selected_channel)
#define ADC_ANALOG_DIGITAL_CONFIGURATION(selected_config)   (ADCON1bits.PCFG = selected_config)

#define ADC_SELECT_ACQUISITION_TIME(acquisition_time)       (ADCON2bits.ACQT = acquisition_time)
#define ADC_SELECT_CONVERSION_CLOCK(conversion_clock)        (ADCON2bits.ADCS = conversion_clock)
/***************************  Types declaration  ********************/
typedef enum{
    ANALOG_CHANNEL_AN0 = 0,
    ANALOG_CHANNEL_AN1,
    ANALOG_CHANNEL_AN2,
    ANALOG_CHANNEL_AN3,
    ANALOG_CHANNEL_AN4,
    ANALOG_CHANNEL_AN5,
    ANALOG_CHANNEL_AN6,
    ANALOG_CHANNEL_AN7,
    ANALOG_CHANNEL_AN8,
    ANALOG_CHANNEL_AN9,
    ANALOG_CHANNEL_AN10,
    ANALOG_CHANNEL_AN11,
    ANALOG_CHANNEL_AN12
} adc_analog_channel_t;

typedef enum{
    ADC_0_TAD = 0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD
} adc_aquisition_time_t;

typedef enum{
    ADC_FOSC_DIV_2 = 0,
    ADC_FOSC_DIV_8,
    ADC_FOSC_DIV_32,
    ADC_FOSC_DIV_FRC,
    ADC_FOSC_DIV_4,
    ADC_FOSC_DIV_16,
    ADC_FOSC_DIV_64
} adc_conversion_clock_t;

typedef struct{
    adc_aquisition_time_t  aquisition_time;
    adc_conversion_clock_t  conversion_clock;
    adc_analog_channel_t  channel;
    uint8 format_justification  :1;
    uint8 voltage_refrence      :1;
    uint8 adc_reserved          :6;
} adc_config_t;

typedef uint16 converion_result_t;
/***************************  Software interface  ********************/
Std_ReturnType ADC_intialize(const adc_config_t *_adc);
Std_ReturnType ADC_selectChannel(const adc_config_t *_adc, adc_analog_channel_t channel);
Std_ReturnType ADC_startConversion(const adc_config_t *_adc);
Std_ReturnType ADC_getConversionResult(const adc_config_t *_adc, converion_result_t *result);
Std_ReturnType ADC_getConversionBlocking(const adc_config_t *_adc, adc_analog_channel_t channel , converion_result_t *result);


#endif	/* HAL_ADC_H */

