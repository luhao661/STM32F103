#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;//����һ���ṹ�壬������GPIO_InitStructure���ṹ��ԭ����GPIO_InitTypeDef ȷ��

	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);//��һ��Ҫ��ʱ�ӡ�rcc.h��693�У������Ҽ����������������
		GPIO_InitStruct.GPIO_Pin=KEY1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY1_GPIO_PORT,  &GPIO_InitStruct);//gpio.h ��351��
	
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin=KEY2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY2_GPIO_PORT,  &GPIO_InitStruct);

}

//��ⰴ��״̬�ĺ���
uint8_t Key_Scan(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin)
{
if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==KEY_ON)//gpio.h 353��
	{
	    //���ּ��
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==KEY_ON)
			;
		return KEY_ON;
	}
else
	return KEY_OFF;
}

