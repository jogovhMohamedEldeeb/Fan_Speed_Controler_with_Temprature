/* 
 * File:   device_config.h
 * Author: m7md
 *
 * Created on 11 September 2023, 00:56
 */

#ifndef DEVICE_CONFIG_H
#define	DEVICE_CONFIG_H
 
/*************************** Includes ********************/
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*************************** Macros declaration  ********************/
#define _XTAL_FREQ  4000000UL

#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x00

/*************************** Macros declaration function  ********************/


/***************************  Types declaration  ********************/
typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned long   uint32;
typedef signed char     sint8;
typedef signed short    sint16;
typedef signed long     sint32;

typedef uint8   Std_ReturnType;

/***************************  Software interface  ********************/

#endif	/* DEVICE_CONFIG_H */

