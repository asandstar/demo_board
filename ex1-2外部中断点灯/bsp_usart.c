#include "bsp_usart.h"
#include "stdio.h"

void usart_gpio_config(uint32_t band_rate)
{
	//开启时钟
	rcu_periph_clock_enable(BSP_USART_TX_RCU);
	rcu_periph_clock_enable(BSP_USART_RX_RCU);
	rcu_periph_clock_enable(BSP_USART_RCU);
	
	//配置GPIO复用功能
	gpio_af_set(BSP_USART_TX_PORT,BSP_USART_AF,BSP_USART_TX_PIN);
	gpio_af_set(BSP_USART_RX_PORT,BSP_USART_AF,BSP_USART_RX_PIN);
	
	//配置GPIO模式
	//配置TX为复用模式 上拉模式
	gpio_mode_set(BSP_USART_TX_PORT,GPIO_MODE_AF,GPIO_PUPD_PULLUP,BSP_USART_TX_PIN);
	//配置RX为复用模式 上拉模式
	gpio_mode_set(BSP_USART_RX_PORT, GPIO_MODE_AF,GPIO_PUPD_PULLUP,BSP_USART_RX_PIN);

	//配置GPIO的输出
	//配置TX为推挽输出 50MHZ
	gpio_output_options_set(BSP_USART_TX_PORT,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,BSP_USART_TX_PIN);
	//配置RX为推挽输出 50MHZ
	gpio_output_options_set(BSP_USART_RX_PORT,GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_USART_RX_PIN);

	//配置串口参数
	usart_deinit(BSP_USART);//复位串口，即重新开始配置
	usart_baudrate_set(BSP_USART,band_rate);//设置波特率
	usart_parity_config(BSP_USART,USART_PM_NONE);//设置校验方式
	usart_word_length_set(BSP_USART,USART_WL_8BIT);//设置串口数据位长度
	usart_stop_bit_set(BSP_USART,USART_STB_1BIT);//设置停止位位数
	
	//使能串口
	usart_enable(BSP_USART);//开启使能串口
	usart_transmit_config(BSP_USART,USART_TRANSMIT_ENABLE);//配置串口发送
	
}

//发送函数
void usart_send_data(uint8_t ucch)
{
	usart_data_transmit(BSP_USART,(uint8_t)ucch);
	while(RESET == usart_flag_get(BSP_USART,USART_FLAG_TBE));     
	// 等待发送数据缓冲区标志置位

}
//串口发送字符串
void usart_send_string(uint8_t *ucstr)
{
	while(ucstr&&*ucstr){
	usart_send_data (*ucstr++);
	}
}
int fputc(int ch, FILE *f)
{
		usart_send_data(ch);
     // 等待发送数据缓冲区标志置位
     return ch;
}
