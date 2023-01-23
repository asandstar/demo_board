#include "bsp_key.h"
#include "sys.h"
#include "bsp_led.h"
#include "stdio.h"

void key_gpio_config(void)
{
	/* 开启时钟 */
	rcu_periph_clock_enable(BSP_KEY_RCU);
	rcu_periph_clock_enable(RCU_SYSCFG);

	/* 配置GPIO模式 */
	gpio_mode_set(BSP_KEY_PORT,GPIO_MODE_INPUT,GPIO_PUPD_PULLDOWN,BSP_KEY_PIN);

	nvic_irq_enable(BSP_KEY_EXIT_IRQN,3U,3U);//使能
	/*配置中断优先级*/
	//连接对应中断线
	syscfg_exti_line_config(BSP_KEY_EXIT_PORT_SOURCE,BSP_KEY_EXIT_PIN_SOURCE);
	/*初始化外部中断*/
	//配置中断模式、上升沿和下降沿均触发
	exti_init(BSP_KEY_EXIT_LINE,EXTI_INTERRUPT,EXTI_TRIG_BOTH);
	/*使能中断*/
	exti_interrupt_enable(BSP_KEY_EXIT_LINE);
	/*清除中断标志位*/
	exti_interrupt_flag_clear(BSP_KEY_EXIT_LINE);
	
}

//中断服务函数
void BSP_KEY_EXIT_IRQHANDLER(void)
{
	if(exti_interrupt_flag_get(BSP_KEY_EXIT_LINE)==SET)
	{
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)
		{
			/*按键按下操作的功能*/
			gpio_bit_toggle(PORT_LED1,PIN_LED1);
					printf("key press!\r\n");
		}else{
			/*按键松开操作的功能*/
			printf("key release!\r\n");
		}
		exti_interrupt_flag_clear(BSP_KEY_EXIT_LINE);
	}
	
}

void key_scan(void)
{

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

