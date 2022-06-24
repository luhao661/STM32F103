#ifndef _BSP_LED_H//防止被重复编译
#define _BSP_LED_H



#include "stm32f10x.h"//要用到寄存器的映射
#define LED_G_GPIO_PIN   GPIO_Pin_0   //0x0001
#define LED_G_GPIO_PORT   GPIOB
#define LED_G_GPIO_CLK    RCC_APB2Periph_GPIOB//rcc.c 1084行

#define LED_R_GPIO_PIN   GPIO_Pin_5
#define LED_R_GPIO_PORT   GPIOB


#define ON 1
#define OFF 0

//  \续航符，后面不能有任何东西
#define LED_G(a)    if(a)  \
	       GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);\
           else  GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);




void LED_GPIO_Config(void);
															//GPIOB->ODR  ^=  0x0001
#define LED_G_TOGGLE   {LED_G_GPIO_PORT->ODR^=LED_G_GPIO_PIN;}//^异或：同为0，异为1，与0异或值不变，与1异或值变反\
                                                                 一开始ODR最低位复位值是0                        \
																然后0与1异或是1，后来不断与1异或。。。
#define LED_R_TOGGLE   {LED_R_GPIO_PORT->ODR^=LED_R_GPIO_PIN;}	



#endif  // _BSP_LED_H
