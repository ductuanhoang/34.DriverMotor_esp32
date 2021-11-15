/*
 * plan_task.c
 *
 *  Created on: Jan 7, 2021
 *      Author: ductu
 */
/***********************************************************************************************************************
* Pragma directive
***********************************************************************************************************************/

/***********************************************************************************************************************
* Includes <System Includes>
***********************************************************************************************************************/
#include "plan_task.h"
#include "../../Common.h"
#include "driver/gpio.h"
#include "../user_driver/user_vibration_motor.h"
#include "../user_driver/user_leds.h"
/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Typedef definitions
***********************************************************************************************************************/
/***********************************************************************************************************************
* Private global variables and functions
***********************************************************************************************************************/
static void vibration_run_process(void);
static void PlantControl_Task(void *pvParameters);
/***********************************************************************************************************************
* Exported global variables and functions (to be accessed by other files)
***********************************************************************************************************************/
extern void flash_erase_all_partions(void);
/***********************************************************************************************************************
* Imported global variables and functions (from other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: 
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void plan_task(void)
{
	xTaskCreatePinnedToCore(PlantControl_Task, "plant_task", 6 * 1024, NULL, 2 | portPRIVILEGE_BIT, NULL, 1);
}

bool mqtt_start_first_time = false;
/***********************************************************************************************************************
* Static Functions
***********************************************************************************************************************/
static void PlantControl_Task(void *pvParameters)
{
	power_enable(true);
	led_green(true);
	led_red(true);
	vTaskDelay(100 / portTICK_PERIOD_MS);

	while (1)
	{
		// vibration process
		vibration_run_process();
		vTaskDelay(10 / portTICK_PERIOD_MS);
	}
}
/***********************************************************************************************************************
* Function Name: vibration_run_process
* Description  : vibration will run with duration 1s
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
uint32_t time_vibration_run = 0;
uint8_t vibration_state = 0;
static void vibration_run_process(void)
{
	switch (vibration_state)
	{
	case 0:
		vibration_state = 1;
		time_vibration_run = usertimer_gettick();
		motor_enable(true);
		drv_motor_1(true);
		vibration_set_duty(duty_pwm);
		break;
	case 1:
		if (usertimer_gettick() - time_vibration_run > 1000)
		{
			vibration_set_duty(0);
			vTaskDelay(20 / portTICK_PERIOD_MS);
			motor_enable(false);
			drv_motor_1(false);
			vibration_state = 2;
			time_vibration_run = usertimer_gettick();
		}
		break;
	case 2:
		if (usertimer_gettick() - time_vibration_run > 2000)
		{
			vibration_state = 0;
		}
		break;
	default:
		break;
	}
}
/***********************************************************************************************************************
* End of file
***********************************************************************************************************************/
