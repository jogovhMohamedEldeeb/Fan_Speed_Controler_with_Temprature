/* 
 * File:   hal_adc.c
 * Author: m7md
 *
 * Created on 11 September 2023, 18:20
 */

#include "hal_adc.h"

static Std_ReturnType ADC_Configure_Channel_pin(const adc_analog_channel_t channel);

Std_ReturnType ADC_intialize(const adc_config_t *_adc){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _adc){
        ret = E_OK;
        ADC_MODULE_DISABLE();
        
        ADC_SELECT_ACQUISITION_TIME(_adc->aquisition_time);
        ADC_SELECT_CONVERSION_CLOCK(_adc->conversion_clock);
        
        if(ENABLE_VOLTAGE_REFERENCE == _adc->voltage_refrence){
            ADC_ENABLE_VOLTAGE_REFERENCE();
        }
        else{
            ADC_DISABLE_VOLTAGE_REFERENCE();
        }
        
        if(REAULT_FORAMT_RIGHT_JUSTIFIED == _adc->format_justification){
            ADC_REAULT_FORAMT_RIGHT_JUSTIFIED();
        }
        else{
            ADC_REAULT_FORAMT_LEFT_JUSTIFIED();
        }
        
        ADC_SELECT_CHANNEL(_adc->channel);
        ret = ADC_Configure_Channel_pin(_adc->channel);
        
        ADC_MODULE_ENABLE();
    }
    return ret;
}

Std_ReturnType ADC_selectChannel(const adc_config_t *_adc, adc_analog_channel_t channel){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _adc){
        ret = E_OK;
        ADC_SELECT_CHANNEL(_adc->channel);
        ret = ADC_Configure_Channel_pin(_adc->channel);
    }
    return ret;
}

Std_ReturnType ADC_startConversion(const adc_config_t *_adc){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL != _adc){
        ret = E_OK;
        ADC_START_CONVERSION();
    }
    return ret;
}

Std_ReturnType ADC_getConversionResult(const adc_config_t *_adc, converion_result_t *result){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL != _adc) && (NULL != result)){
        if(REAULT_FORAMT_RIGHT_JUSTIFIED == _adc->format_justification){
            *result = (converion_result_t)(ADRESL + (ADRESH << 8));
        }
        else if(REAULT_FORAMT_LEFT_JUSTIFIED == _adc->format_justification){
            *result = (converion_result_t)((ADRESL >> 6) + (ADRESH << 2)); 
        }
        else{
            *result = 0;
            ret = E_NOT_OK;
        }
    }
    return ret;
}

Std_ReturnType ADC_getConversionBlocking(const adc_config_t *_adc, adc_analog_channel_t channel ,
        converion_result_t *result){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL != _adc) && (NULL != result)){
        ret = E_OK;
        ret = ADC_selectChannel(_adc,channel);
        ret = ADC_startConversion(_adc);
        /* Wait until conversion is done */
        while(ADCON0bits.GO_nDONE);
        ret = ADC_getConversionResult(_adc,result);
    }
    return ret;
}

static Std_ReturnType ADC_Configure_Channel_pin(const adc_analog_channel_t channel){
    Std_ReturnType ret = E_OK;
    switch(channel){
        case ANALOG_CHANNEL_AN0: SET_BIT(TRISA, _TRISA_RA0_POSN); break;
        case ANALOG_CHANNEL_AN1: SET_BIT(TRISA, _TRISA_RA1_POSN); break;
        case ANALOG_CHANNEL_AN2: SET_BIT(TRISA, _TRISA_RA2_POSN); break;
        case ANALOG_CHANNEL_AN3: SET_BIT(TRISA, _TRISA_RA3_POSN); break;
        case ANALOG_CHANNEL_AN4: SET_BIT(TRISA, _TRISA_RA5_POSN); break;
        case ANALOG_CHANNEL_AN5: SET_BIT(TRISE, _TRISE_RE0_POSN); break;
        case ANALOG_CHANNEL_AN6: SET_BIT(TRISE, _TRISE_RE1_POSN); break;
        case ANALOG_CHANNEL_AN7: SET_BIT(TRISE, _TRISE_RE2_POSN); break;
        case ANALOG_CHANNEL_AN8: SET_BIT(TRISB, _TRISB_RB2_POSN); break;
        case ANALOG_CHANNEL_AN9: SET_BIT(TRISB, _TRISB_RB3_POSN); break;
        case ANALOG_CHANNEL_AN10: SET_BIT(TRISB, _TRISB_RB1_POSN); break;
        case ANALOG_CHANNEL_AN11: SET_BIT(TRISB, _TRISB_RB4_POSN); break;
        case ANALOG_CHANNEL_AN12: SET_BIT(TRISB, _TRISB_RB0_POSN); break;
        default :  ret = E_NOT_OK;
    }
    return ret;

}