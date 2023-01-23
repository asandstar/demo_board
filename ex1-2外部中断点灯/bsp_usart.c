#include "bsp_usart.h"
#include "stdio.h"

void usart_gpio_config(uint32_t band_rate)
{
	//����ʱ��
	rcu_periph_clock_enable(BSP_USART_TX_RCU);
	rcu_periph_clock_enable(BSP_USART_RX_RCU);
	rcu_periph_clock_enable(BSP_USART_RCU);
	
	//����GPIO���ù���
	gpio_af_set(BSP_USART_TX_PORT,BSP_USART_AF,BSP_USART_TX_PIN);
	gpio_af_set(BSP_USART_RX_PORT,BSP_USART_AF,BSP_USART_RX_PIN);
	
	//����GPIOģʽ
	//����TXΪ����ģʽ ����ģʽ
	gpio_mode_set(BSP_USART_TX_PORT,GPIO_MODE_AF,GPIO_PUPD_PULLUP,BSP_USART_TX_PIN);
	//����RXΪ����ģʽ ����ģʽ
	gpio_mode_set(BSP_USART_RX_PORT, GPIO_MODE_AF,GPIO_PUPD_PULLUP,BSP_USART_RX_PIN);

	//����GPIO�����
	//����TXΪ������� 50MHZ
	gpio_output_options_set(BSP_USART_TX_PORT,GPIO_OTYPE_PP,GPIO_OSPEED_50MHZ,BSP_USART_TX_PIN);
	//����RXΪ������� 50MHZ
	gpio_output_options_set(BSP_USART_RX_PORT,GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_USART_RX_PIN);

	//���ô��ڲ���
	usart_deinit(BSP_USART);//��λ���ڣ������¿�ʼ����
	usart_baudrate_set(BSP_USART,band_rate);//���ò�����
	usart_parity_config(BSP_USART,USART_PM_NONE);//����У�鷽ʽ
	usart_word_length_set(BSP_USART,USART_WL_8BIT);//���ô�������λ����
	usart_stop_bit_set(BSP_USART,USART_STB_1BIT);//����ֹͣλλ��
	
	//ʹ�ܴ���
	usart_enable(BSP_USART);//����ʹ�ܴ���
	usart_transmit_config(BSP_USART,USART_TRANSMIT_ENABLE);//���ô��ڷ���
	
}

//���ͺ���
void usart_send_data(uint8_t ucch)
{
	usart_data_transmit(BSP_USART,(uint8_t)ucch);
	while(RESET == usart_flag_get(BSP_USART,USART_FLAG_TBE));     
	// �ȴ��������ݻ�������־��λ

}
//���ڷ����ַ���
void usart_send_string(uint8_t *ucstr)
{
	while(ucstr&&*ucstr){
	usart_send_data (*ucstr++);
	}
}
int fputc(int ch, FILE *f)
{
		usart_send_data(ch);
     // �ȴ��������ݻ�������־��λ
     return ch;
}
