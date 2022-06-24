//#include "stm32f10x.h"  //由于STM32F10x_GPIO.h的文件里还有#include "stm32f10x.h"，所以会造成此句被重复调用，会报错。
#include "stm32f10x.h"  
#include "STM32F10x_GPIO.h"                                  //方法一是注释掉此句。最好的解决方法是#ifndef  #define

void SystemInit (void)
{

}

//寄存器结构体指针法 点亮LED
#if 0

int main (void)
{
	RCC_APB2ENR |=(1<<3);//用指针
	GPIOB->CRL |=(1<<4*0);//用结构体
	GPIOB->ODR &=~(1<<0);
}
#endif


//作业：实现RCC寄存器的结构体声明
#if 0
int main (void)
{
	RCC->APB2ENR |=(1<<3);//用结构体
	GPIOB->CRL |=(1<<4*0);//用结构体
	GPIOB->ODR &=~(1<<0);
}
#endif


//用置位复位函数操纵寄存器的位，好处：即看即明白意思
#if 0
int main (void)
{
	RCC->APB2ENR |=(1<<3);//用结构体，但仍有改进空间。
	GPIOB->CRL |=(1<<4*0);//用结构体
	//GPIOB->ODR &=~(1<<0);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);//两个实参写入，用于操纵BSRR寄存器
    GPIO_RestBits(GPIOB, GPIO_Pin_0);//操纵BRR
}

#endif


//定义初始化结构体
#if 1
void Delay(uint32_t nCount); 

int main (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//声明一个结构体，名字是GPIO_InitStructure，结构体原型由GPIO_InitTypeDef 确定
	RCC->APB2ENR |=(1<<3);//用结构体，但仍有改进空间。
//	GPIOB->CRL |=(1<<4*0);//用结构体
//	GPIOB->ODR &=~(1<<0);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);//值都写入寄存器
	while(1)
	{		
	GPIO_SetBits(GPIOB,GPIO_Pin_0);//两个实参写入，用于操纵BSRR寄存器
	Delay(1000);
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);//操纵BRR
	Delay(1000);
	}
}

void Delay(uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--)
	;
}

#endif


//作业：使用固件库的方式点亮剩下的两个LED
#if 0
int main (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//声明一个结构体，名字是GPIO_InitStructure，结构体原型由GPIO_InitTypeDef 确定
	RCC->APB2ENR |=(1<<3);//用结构体，但仍有改进空间。

	//点亮绿色
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB,&GPIO_InitStructure);//值都写入寄存器
//	GPIO_SetBits(GPIOB,GPIO_Pin_0);//两个实参写入，用于操纵BSRR寄存器
//    GPIO_RestBits(GPIOB, GPIO_Pin_0);//操纵BRR
	//点亮红色
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);//值都写入寄存器
	GPIO_SetBits(GPIOB,GPIO_Pin_5);//两个实参写入，用于操纵BSRR寄存器
    //GPIO_RestBits(GPIOB, GPIO_Pin_5);//操纵BRR
	//点亮蓝色
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_RestBits(GPIOB, GPIO_Pin_1);
}
#endif


