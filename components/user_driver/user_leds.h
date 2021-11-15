#pragma once


#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "../../Common.h"
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***         Exported global functions                                     ***/
/****************************************************************************/
void power_enable(bool _status);
void motor_enable(bool _status);

void leds_gpio_init(void);


void led_red(bool _status);


void led_green(bool _status);

void drv_motor_1(bool _status);

void drv_motor_2(bool _status);

void drv_motor_3(bool _status);

void drv_motor_4(bool _status);

#ifdef __cplusplus
}
#endif
