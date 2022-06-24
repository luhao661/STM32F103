#include "stm32f10x.h"
#include "bsp_led.h"

#if 0
void delay (uint32_t count);

int main (void)
{
LED_GPIO_Config();

	while(1)
	{
		GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);//灭
		delay(0xfffff);
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);//亮
		delay(0xfffff);//若此句不加，则不闪烁。
	}
	//法二
//	while(1)
//	{
//		LED_G(OFF);//灭
//		delay(0xfffff);
//		LED_G(ON);//亮
//		delay(0xfffff);//若此句不加，则不闪烁。
//	}
}

void delay (uint32_t count)
{
for(;count!=0;count--)
	;
}
#endif


//作业：使用固件库的方式点亮剩下的两个LED，并实现流水灯。
#if 1
void delay (uint32_t count);

int main (void)
{
	LED_GPIO_Config();

	while(1)
	{
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_R_GPIO_PIN);//亮
		delay(0xfffff);
		GPIO_SetBits(LED_G_GPIO_PORT, LED_R_GPIO_PIN);//灭
		delay(0xfffff);
		
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);//亮
		delay(0xfffff);
		GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);//灭
		delay(0xfffff);
		
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_B_GPIO_PIN);//亮
		delay(0xfffff);
		GPIO_SetBits(LED_G_GPIO_PORT, LED_B_GPIO_PIN);//灭
		delay(0xfffff);
	}

}

void delay (uint32_t count)
{
	uint32_t i;
for(;count!=0;count--)
	{
		for(i=0x08;i!=0;i--)
		;	
	}
	
}
#endif
