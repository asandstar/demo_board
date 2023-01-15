/*!
    \file    main.c
    \brief   led spark with systick

    \version 2016-08-15, V1.0.0, firmware for GD32F4xx
    \version 2018-12-12, V2.0.0, firmware for GD32F4xx
    \version 2020-09-30, V2.1.0, firmware for GD32F4xx
    \version 2022-03-09, V3.0.0, firmware for GD32F4xx
*/

/*
    Copyright (c) 2022, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"

/*!
    \brief    main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{

    systick_config();
	
		led_gpio_config();//led初始化
	
		//gpio_bit_set(GPIOD,GPIO_PIN_7);//设置高电平，点亮LED2
	
		//gpio_bit_reset(GPIOD,GPIO_PIN_7);//设置低电平，熄灭LED2
	
		//gpio_bit_write(GPIOD,GPIO_PIN_7,RESET);//设置低电平，熄灭LED2
	
		//gpio_bit_write(PORT_LED,PIN_LED,SET);//设置高电平，点亮指定LED
	
		//gpio_bit_write(PORT_LED,PIN_LED,RESET);//设置低电平，熄灭指定LED
	
		//gpio_bit_write(PORT_LED1,PIN_LED1,SET);//设置高电平，点亮指定LED
		//gpio_bit_write(PORT_LED2,PIN_LED2,SET);//设置高电平，点亮指定LED
		//gpio_bit_write(PORT_LED3,PIN_LED3,SET);//设置高电平，点亮指定LED
		//gpio_bit_write(PORT_LED4,PIN_LED4,SET);//设置高电平，点亮指定LED
		
    while(1) {
			gpio_bit_write(PORT_LED1,PIN_LED1,SET);
			delay_1ms(500);
			gpio_bit_write(PORT_LED1,PIN_LED1,RESET);
			delay_1ms(500);
			
			gpio_bit_write(PORT_LED2,PIN_LED2,SET);
			delay_1ms(500);
			gpio_bit_write(PORT_LED2,PIN_LED2,RESET);
			delay_1ms(500);
			
			gpio_bit_write(PORT_LED3,PIN_LED3,SET);
			delay_1ms(500);
			gpio_bit_write(PORT_LED3,PIN_LED3,RESET);
			delay_1ms(500);
			
			gpio_bit_write(PORT_LED4,PIN_LED4,SET);
			delay_1ms(500);
			gpio_bit_write(PORT_LED4,PIN_LED4,RESET);
			delay_1ms(500);
			
    }
}
