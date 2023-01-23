#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "gd32f4xx.h"
#include "systick.h"

/*
LED1 PE3
LED2 PD7
LED3 PG3
LED4 PA5
*/

#define BSP_KEY_RCU RCU_GPIOA
#define BSP_KEY_PORT GPIOA
#define BSP_KEY_PIN GPIO_PIN_0

#define BSP_KEY_EXIT_IRQN 				EXTI0_IRQn
#define BSP_KEY_EXIT_PORT_SOURCE	EXTI_SOURCE_GPIOA
#define BSP_KEY_EXIT_PIN_SOURCE		EXTI_SOURCE_PIN0
#define BSP_KEY_EXIT_LINE 				EXTI_0
#define BSP_KEY_EXIT_IRQHANDLER		EXTI0_IRQHandler


void key_gpio_config(void);
void key_scan(void);
	
#endif