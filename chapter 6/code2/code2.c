#include "stm32f10x.h"
void SystemInit (void)
{

}

//点亮绿色LED
//int main (void)
//{
//	//打开GPIOB端口的时钟
//*(unsigned int *)0x40021018|=((1)<<3);
//	//配置IO口为输出模式
//*(unsigned int *)0x40010C00 |=((1)<<(4*0));
//	//控制ODR
//*(unsigned int *)0x40010C0C &=~(1<<0);
//}

//点亮红色LED
//int main (void)
//{
//*(unsigned int *)0x40021018|=(1<<3);
//*(unsigned int *)0x40010C00 |=(1<<(4*5));
//*(unsigned int *)0x40010C0C &=~(1<<5);
//}

//点亮蓝色LED
//int main (void)
//{
//*(unsigned int *)0x40021018|=(1<<3);
//*(unsigned int *)0x40010C00 |=(1<<(4*1));
//*(unsigned int *)0x40010C0C &=~(1<<1);
//}

//LED闪烁
void delay(int num);
int main (void)
{
	while(1)
	{	//打开GPIOB端口的时钟
		*(unsigned int *)0x40021018|=((1)<<3);
			//配置IO口为输出模式  CRL
		*(unsigned int *)0x40010C00 |=((1)<<(4*0));
			//控制ODR
		*(unsigned int *)0x40010C0C &=~(1<<0);
		delay (10000);
//*(unsigned int *)0x40021018|=(0<<3);
		*(unsigned int *)0x40010C00&=~(1<<(4*0));
//		*(unsigned int *)0x40010C0C &=~(1<<5);
		
	}
}
void delay(int num)
{
  int i,j;
  for(i=0;i<num;i++)
   { for(j=0;j<100;j++)
	;
   }
}




