#pragma once


#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
void vibration_init(void);
void vibration_set_duty(uint8_t _duty);
#ifdef __cplusplus
}
#endif