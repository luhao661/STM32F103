#include "stm32f10x.h"
#include "bsp_led.h"

#if 0
void delay (uint32_t count);

int main (void)
{
LED_GPIO_Config();

	while(1)
	{
		GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);//��
		delay(0xfffff);
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);//��
		delay(0xfffff);//���˾䲻�ӣ�����˸��
	}
	//����
//	while(1)
//	{
//		LED_G(OFF);//��
//		delay(0xfffff);
//		LED_G(ON);//��
//		delay(0xfffff);//���˾䲻�ӣ�����˸��
//	}
}

void delay (uint32_t count)
{
for(;count!=0;count--)
	;
}
#endif


//��ҵ��ʹ�ù̼���ķ�ʽ����ʣ�µ�����LED����ʵ����ˮ�ơ�
#if 1
void delay (uint32_t count);

int main (void)
{
	LED_GPIO_Config();

	while(1)
	{
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_R_GPIO_PIN);//��
		delay(0xfffff);
		GPIO_SetBits(LED_G_GPIO_PORT, LED_R_GPIO_PIN);//��
		delay(0xfffff);
		
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);//��
		delay(0xfffff);
		GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);//��
		delay(0xfffff);
		
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_B_GPIO_PIN);//��
		delay(0xfffff);
		GPIO_SetBits(LED_G_GPIO_PORT, LED_B_GPIO_PIN);//��
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
