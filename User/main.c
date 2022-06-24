#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

//LED 绿灯+红灯
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

//作业：把KEY2的代码也写一次，要求用到LED_R_TOGGLE    （已完成）
#endif


//GPIO的位带操作
#define GPIOB_ODR_Addr   (GPIOB_BASE+0X0C)  //GPIOB的ODR寄存器所在的地址
#define PBout(n)    *(unsigned int *)((GPIOB_ODR_Addr&0xf0000000)+0x2000000+((GPIOB_ODR_Addr&0x00ffffff)<<5)+(n<<2))
					//第一个*意思是后面是个指针，第二个*指对后面这个机器看来是立即数的值进行强制类型转换，变成指向32位的指针
					//找到GPIOB的ODR的位带别名区的地址
#define GPIOA_IDR_Addr   (GPIOA_BASE+0X08) //PA口连有一个按键，故找GPIOA的IDR的地址 
#define PAin(n)    *(unsigned int *)((GPIOA_IDR_Addr&0xf0000000)+0x2000000+((GPIOA_IDR_Addr&0x00ffffff)<<5)+(n<<2))

#define GPIOC_IDR_Addr   (GPIOC_BASE+0X08) //PC口连有一个按键，故找GPIOC的IDR的地址 
#define PCin(n)    *(unsigned int *)((GPIOC_IDR_Addr&0xf0000000)+0x2000000+((GPIOC_IDR_Addr&0x00ffffff)<<5)+(n<<2))

void delay (uint32_t count);

int main (void)
{
	LED_GPIO_Config();//绿灯+红灯初始化配置
	KEY_GPIO_Config();

#if 0	
	while(1)
	{
		PBout(0)=1;//置位
		delay (0xfffff);
		PBout(0)=0;
		delay (0xfffff);
	}
#endif
	while(1)
	{
		if(PAin(0)==KEY_ON)
		{
		while(PAin(0)==KEY_ON)//按下的状态时，一直循环
		continue;
		LED_G_TOGGLE;//松手后，执行
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

//作业：用位带操作的方法点亮剩下的两个LED灯
