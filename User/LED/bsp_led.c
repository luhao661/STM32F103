#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef    GPIO_InitStruct;//声明一个结构体，名字是GPIO_InitStructure，结构体原型由GPIO_InitTypeDef 确定，

	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);//rcc.h第693行，可以右键看函数定义的内容
	GPIO_InitStruct.GPIO_Pin=LED_G_GPIO_PIN;
	//作业：
//	GPIO_InitStruct.GPIO_Pin=LED_R_GPIO_PIN;//加在这里不行
//	GPIO_InitStruct.GPIO_Pin=LED_B_GPIO_PIN;
	//
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_PORT,  &GPIO_InitStruct);//gpio.h 第351行
												  //根据GPIO_InitStruct中指定的参数初始化GPIOx外设。GPIOx: x可以是(A..G)，选择GPIO外设。GPIO_InitStruct:指向GPIO_InitTypeDef结构体的指针包含指定GPIO外设的配置信息。

	GPIO_InitStruct.GPIO_Pin=LED_R_GPIO_PIN;
	GPIO_Init(LED_G_GPIO_PORT,  &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin=LED_B_GPIO_PIN;
	GPIO_Init(LED_G_GPIO_PORT,  &GPIO_InitStruct);	//向寄存器写入参数，用于初始化GPIOB。设置完了GPIO_InitStructure\
	                                                  里面的内容后,此语句会在括号里的第二项调用
}
