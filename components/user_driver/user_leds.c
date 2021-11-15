/*
 * led_driver.c
 *
 *  Created on: Jan 9, 2021
 *      Author: ductu
 */
/***********************************************************************************************************************
* Pragma directive
***********************************************************************************************************************/

/***********************************************************************************************************************
* Includes <System Includes>
***********************************************************************************************************************/
#include "user_leds.h"
/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Private global variables and functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
* Imported global variables and functions (from other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: 
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void leds_gpio_init(void)
{    
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
    // if (error != ESP_OK)
    // {
    //     APP_LOGE("error configuring outputs\n");
    // }
}

void power_enable(bool _status)
{
    gpio_set_level(GPIO_USER_POWER_ENABLE, _status);
}

void motor_enable(bool _status)
{
    // gpio_set_level(GPIO_USER_MOTOR_1_ENABLE, _status);
    // gpio_set_level(GPIO_USER_MOTOR_2_ENABLE, _status);
    // gpio_set_level(GPIO_USER_MOTOR_3_ENABLE, _status);
    // gpio_set_level(GPIO_USER_MOTOR_4_ENABLE, _status);
}

void led_red(bool _status)
{
    gpio_set_level(GPIO_USER_LED_RED, _status);
}

void led_green(bool _status)
{
    gpio_set_level(GPIO_USER_LED_GREEN, _status);
}

void drv_motor_1(bool _status)
{
    gpio_set_level(GPIO_DRV1_EN, _status);
}

void drv_motor_2(bool _status)
{
    gpio_set_level(GPIO_DRV2_EN, _status);
}

void drv_motor_3(bool _status)
{
    gpio_set_level(GPIO_DRV3_EN, _status);
}

void drv_motor_4(bool _status)
{
    gpio_set_level(GPIO_DRV4_EN, _status);
}
/***********************************************************************************************************************
* Static Functions
***********************************************************************************************************************/
/***********************************************************************************************************************
* Function Name:
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/

/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/
