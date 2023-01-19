#include "bsp_key.h"
#include "sys.h"
#include "bsp_led.h"
#include "stdio.h"

void key_gpio_config(void)
{
	/* 开启时钟 */
	rcu_periph_clock_enable(BSP_KEY_RCU);
	
	/* 配置GPIO模式 */
	gpio_mode_set(BSP_KEY_PORT,GPIO_MODE_INPUT,GPIO_PUPD_PULLDOWN,BSP_KEY_PIN);

}

void key_scan(void)
{
	//int count=0;
	//int count1=0;
	/* 获取按键引脚的电平状态 */
	if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)
	{
		delay_1ms(20);
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)
		{
						/* 执行对应的功能 */
			if(PDout1(3)==0&&PDout2(7)==0&&PDout3(3)==0&&PDout4(5)==0)
				{
					gpio_bit_toggle(PORT_LED1,PIN_LED1);
					printf("key press!\r\n");
					while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
					printf("key release!\r\n");
				}
			else if(PDout1(3)==1&&PDout2(7)==0&&PDout3(3)==0&&PDout4(5)==0) 
				{
					gpio_bit_toggle(PORT_LED2,PIN_LED2);
					printf("key press!\r\n");
					while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
					printf("key release!\r\n");
				}
			else if(PDout1(3)==1&&PDout2(7)==1&&PDout3(3)==0&&PDout4(5)==0) 
				{
					gpio_bit_toggle(PORT_LED3,PIN_LED3);
					printf("key press!\r\n");
					while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
					printf("key release!\r\n");
				}
			else if(PDout1(3)==1&&PDout2(7)==1&&PDout3(3)==1&&PDout4(5)==0) 
				{
					gpio_bit_toggle(PORT_LED4,PIN_LED4);
					printf("key press!\r\n");
					while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
					printf("key release!\r\n");
				}
			else if(PDout1(3)==1&&PDout2(7)==1&&PDout3(3)==1&&PDout4(5)==1) 
				{
					gpio_bit_toggle(PORT_LED1,PIN_LED1);
					printf("key press!\r\n");
					while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
					printf("key release!\r\n");
				}
			else if(PDout1(3)==0&&PDout2(7)==1&&PDout3(3)==1&&PDout4(5)==1) 
				{
					gpio_bit_toggle(PORT_LED2,PIN_LED2);
					printf("key press!\r\n");
					while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
					printf("key release!\r\n");
				}
			else if(PDout1(3)==0&&PDout2(7)==0&&PDout3(3)==1&&PDout4(5)==1) 
				{
					gpio_bit_toggle(PORT_LED3,PIN_LED3);
					printf("key press!\r\n");
					while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
					printf("key release!\r\n");
				}
			else if(PDout1(3)==0&&PDout2(7)==0&&PDout3(3)==0&&PDout4(5)==1) 
				{
					gpio_bit_toggle(PORT_LED4,PIN_LED4);
					printf("key press!\r\n");
					while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
					printf("key release!\r\n");
				}
/*
LED1 PE3
LED2 PD7
LED3 PG3
LED4 PA5
*/			
		}
	}
}

/*
PDout1(3)=1;
			printf("key press!\r\n");
			while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
			printf("key release!\r\n");

if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)
		{
			PDout2(7)=1;
			printf("key press!\r\n");
			while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
			printf("key release!\r\n");
		}
		
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)
		{
			PDout3(3)=1;
			printf("key press!\r\n");
			while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
			printf("key release!\r\n");
		}
		
			if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)
		{
			PDout4(5)=1;
			printf("key press!\r\n");
			while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
			printf("key release!\r\n");			
		}

*/

