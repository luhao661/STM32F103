#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

//LED �̵�+���
#if 0
void delay (uint32_t count);

int main (void)
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
	
	while(1)
	{
		
		if(Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN)==KEY_ON)
		{
		LED_G_TOGGLE;
		}
		if(Key_Scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN)==KEY_ON)
		{
		LED_R_TOGGLE;
		}

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

//��ҵ����KEY2�Ĵ���Ҳдһ�Σ�Ҫ���õ�LED_R_TOGGLE    ������ɣ�
#endif


//GPIO��λ������
#define GPIOB_ODR_Addr   (GPIOB_BASE+0X0C)  //GPIOB��ODR�Ĵ������ڵĵ�ַ
#define PBout(n)    *(unsigned int *)((GPIOB_ODR_Addr&0xf0000000)+0x2000000+((GPIOB_ODR_Addr&0x00ffffff)<<5)+(n<<2))
					//��һ��*��˼�Ǻ����Ǹ�ָ�룬�ڶ���*ָ�Ժ������������������������ֵ����ǿ������ת�������ָ��32λ��ָ��
					//�ҵ�GPIOB��ODR��λ���������ĵ�ַ
#define GPIOA_IDR_Addr   (GPIOA_BASE+0X08) //PA������һ������������GPIOA��IDR�ĵ�ַ 
#define PAin(n)    *(unsigned int *)((GPIOA_IDR_Addr&0xf0000000)+0x2000000+((GPIOA_IDR_Addr&0x00ffffff)<<5)+(n<<2))

#define GPIOC_IDR_Addr   (GPIOC_BASE+0X08) //PC������һ������������GPIOC��IDR�ĵ�ַ 
#define PCin(n)    *(unsigned int *)((GPIOC_IDR_Addr&0xf0000000)+0x2000000+((GPIOC_IDR_Addr&0x00ffffff)<<5)+(n<<2))

void delay (uint32_t count);

int main (void)
{
	LED_GPIO_Config();//�̵�+��Ƴ�ʼ������
	KEY_GPIO_Config();

#if 0	
	while(1)
	{
		PBout(0)=1;//��λ
		delay (0xfffff);
		PBout(0)=0;
		delay (0xfffff);
	}
#endif
	while(1)
	{
		if(PAin(0)==KEY_ON)
		{
		while(PAin(0)==KEY_ON)//���µ�״̬ʱ��һֱѭ��
		continue;
		LED_G_TOGGLE;//���ֺ�ִ��
		}
		if(PCin(13)==KEY_ON)
		{
		while(PCin(13)==KEY_ON)
		continue;
		LED_R_TOGGLE;
		}
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

//��ҵ����λ�������ķ�������ʣ�µ�����LED��
