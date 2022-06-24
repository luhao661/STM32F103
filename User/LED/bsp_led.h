#ifndef _BSP_LED_H//��ֹ���ظ�����
#define _BSP_LED_H



#include "stm32f10x.h"//Ҫ�õ��Ĵ�����ӳ��
#define LED_G_GPIO_PIN   GPIO_Pin_0   //0x0001
#define LED_G_GPIO_PORT   GPIOB
#define LED_G_GPIO_CLK    RCC_APB2Periph_GPIOB//rcc.c 1084��

#define LED_R_GPIO_PIN   GPIO_Pin_5
#define LED_R_GPIO_PORT   GPIOB


#define ON 1
#define OFF 0

//  \�����������治�����κζ���
#define LED_G(a)    if(a)  \
	       GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);\
           else  GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);




void LED_GPIO_Config(void);
															//GPIOB->ODR  ^=  0x0001
#define LED_G_TOGGLE   {LED_G_GPIO_PORT->ODR^=LED_G_GPIO_PIN;}//^���ͬΪ0����Ϊ1����0���ֵ���䣬��1���ֵ�䷴\
                                                                 һ��ʼODR���λ��λֵ��0                        \
																Ȼ��0��1�����1������������1��򡣡���
#define LED_R_TOGGLE   {LED_R_GPIO_PORT->ODR^=LED_R_GPIO_PIN;}	



#endif  // _BSP_LED_H
