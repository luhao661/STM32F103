#ifndef _BSP_LED_H//防止被重复编译
#define _BSP_LED_H



#include "stm32f10x.h"//要用到寄存器的映射
#define LED_G_GPIO_PIN   GPIO_Pin_0
#define LED_G_GPIO_PORT   GPIOB
#define LED_G_GPIO_CLK    RCC_APB2Periph_GPIOB//rcc.c 1084行

#define ON 1
#define OFF 0

//  \续航符，后面不能有任何东西
#define LED_G(a)    if(a)  \
	       GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);\
           else  GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);

//作业：
#define LED_R_GPIO_PIN   GPIO_Pin_5
#define LED_B_GPIO_PIN   GPIO_Pin_1



void LED_GPIO_Config(void);
	

#endif  // _BSP_LED_H
