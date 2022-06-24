#include "stm32f10x.h"
void SystemInit (void)
{

}

//直接操作内存地址法 点亮绿色LED
//int main (void)
//{
//	//打开GPIOB端口的时钟
//*(unsigned int *)0x40021018|=((1)<<3);                       //（unsigned int*）是一个强制类型转换，首先把指针强制转换成（unsigned int*）型，然后再取值
															//比如 int *addr，那么就需要强制转换，因为有的编译器编译会有警告，如果加上(unsigned int *)，警告就会消失
//	//配置IO口为输出模式									//*(unsigned int *)(a) = (v) 的作用是什么？ 地址a之后的sizeof(unsigned int)个字节的内存赋值为v。
//*(unsigned int *)0x40010C00 |=((1)<<(4*0));				//更改指针类型，就是更改指针所能操作的内存单位长度，(unsigned int *)(a)意思就是只能操作a指向的4个字节的长度内存。

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



#if (0)
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
#endif

//寄存器映射法
#define PERIPHERAL_BASE        ((unsigned int)0x40000000)
#define APB1PERIPHERAL_BASE    PERIPHERAL_BASE
#define APB2PERIPHERAL_BASE    (PERIPHERAL_BASE+0x10000)
#define AHBPERIPHERAL_BASE    (PERIPHERAL_BASE+0x20000)//定位在DMA1，算RCC时好算

#define RCC_BASE                (AHBPERIPHERAL_BASE+0x1000)
#define GPIOB_BASE              (APB2PERIPHERAL_BASE+0x0c00)

#define RCC_APB2ENR            *(unsigned int*)(RCC_BASE+0x18)//指针强制类型转换为32位
#define GPIOB_CRL              *(unsigned int*)(GPIOB_BASE+0x00)
#define GPIOB_CRH              *(unsigned int*)(GPIOB_BASE+0x04)
#define GPIOB_ODR              *(unsigned int*)(GPIOB_BASE+0x0c)
#define GPIOB_BSRR				*(unsigned int*)(GPIOB_BASE+0x10)
#define GPIOB_BRR				*(unsigned int*)(GPIOB_BASE+0x14)


int delay (int);
int main (void)
{
	RCC_APB2ENR|=(1<<3);
	GPIOB_CRL |=(1<<(4*0));
	while(1)
	{
		//GPIOB_ODR &=~(1<<0);
		//GPIOB_BSRR |=(1<<16);
		GPIOB_BRR |=(1<<0);
		delay(1000);
//GPIOB_ODR |=(1<<0);
//GPIOB_BSRR |=(1<<0);
		delay(1000);
	}
}
int delay(int num)
{
  int i,j;
  for(i=0;i<num;i++)
   { for(j=0;j<100;j++)
	;
   }
}



