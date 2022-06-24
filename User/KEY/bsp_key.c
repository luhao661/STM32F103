#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;//声明一个结构体，名字是GPIO_InitStructure，结构体原型由GPIO_InitTypeDef 确定

	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);//第一步要开时钟。rcc.h第693行，可以右键看函数定义的内容
		GPIO_InitStruct.GPIO_Pin=KEY1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY1_GPIO_PORT,  &GPIO_InitStruct);//gpio.h 第351行
	
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin=KEY2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY2_GPIO_PORT,  &GPIO_InitStruct);

}

//检测按键状态的函数
uint8_t Key_Scan(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin)
{
if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==KEY_ON)//gpio.h 353行
	{
	    //松手检测
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==KEY_ON)
			;
		return KEY_ON;
	}
else
	return KEY_OFF;
}

