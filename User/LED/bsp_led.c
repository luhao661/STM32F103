#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;//����һ���ṹ�壬������GPIO_InitStructure���ṹ��ԭ����GPIO_InitTypeDef ȷ����

	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);//rcc.h��693�У������Ҽ����������������
	GPIO_InitStruct.GPIO_Pin=LED_G_GPIO_PIN;
	//��ҵ��
//	GPIO_InitStruct.GPIO_Pin=LED_R_GPIO_PIN;//�������ﲻ��
//	GPIO_InitStruct.GPIO_Pin=LED_B_GPIO_PIN;
	//
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_PORT,  &GPIO_InitStruct);//gpio.h ��351��
												  //����GPIO_InitStruct��ָ���Ĳ�����ʼ��GPIOx���衣GPIOx: x������(A..G)��ѡ��GPIO���衣GPIO_InitStruct:ָ��GPIO_InitTypeDef�ṹ���ָ�����ָ��GPIO�����������Ϣ��

	GPIO_InitStruct.GPIO_Pin=LED_R_GPIO_PIN;
	GPIO_Init(LED_G_GPIO_PORT,  &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin=LED_B_GPIO_PIN;
	GPIO_Init(LED_G_GPIO_PORT,  &GPIO_InitStruct);	//��Ĵ���д����������ڳ�ʼ��GPIOB����������GPIO_InitStructure\
	                                                  ��������ݺ�,��������������ĵڶ������
}
