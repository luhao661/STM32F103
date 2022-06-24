//#include "stm32f10x.h"  //����STM32F10x_GPIO.h���ļ��ﻹ��#include "stm32f10x.h"�����Ի���ɴ˾䱻�ظ����ã��ᱨ��
#include "stm32f10x.h"  
#include "STM32F10x_GPIO.h"                                  //����һ��ע�͵��˾䡣��õĽ��������#ifndef  #define

void SystemInit (void)
{

}

//�Ĵ����ṹ��ָ�뷨 ����LED
#if 0

int main (void)
{
	RCC_APB2ENR |=(1<<3);//��ָ��
	GPIOB->CRL |=(1<<4*0);//�ýṹ��
	GPIOB->ODR &=~(1<<0);
}
#endif


//��ҵ��ʵ��RCC�Ĵ����Ľṹ������
#if 0
int main (void)
{
	RCC->APB2ENR |=(1<<3);//�ýṹ��
	GPIOB->CRL |=(1<<4*0);//�ýṹ��
	GPIOB->ODR &=~(1<<0);
}
#endif


//����λ��λ�������ݼĴ�����λ���ô���������������˼
#if 0
int main (void)
{
	RCC->APB2ENR |=(1<<3);//�ýṹ�壬�����иĽ��ռ䡣
	GPIOB->CRL |=(1<<4*0);//�ýṹ��
	//GPIOB->ODR &=~(1<<0);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);//����ʵ��д�룬���ڲ���BSRR�Ĵ���
    GPIO_RestBits(GPIOB, GPIO_Pin_0);//����BRR
}

#endif


//�����ʼ���ṹ��
#if 1
void Delay(uint32_t nCount); 

int main (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//����һ���ṹ�壬������GPIO_InitStructure���ṹ��ԭ����GPIO_InitTypeDef ȷ��
	RCC->APB2ENR |=(1<<3);//�ýṹ�壬�����иĽ��ռ䡣
//	GPIOB->CRL |=(1<<4*0);//�ýṹ��
//	GPIOB->ODR &=~(1<<0);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);//ֵ��д��Ĵ���
	while(1)
	{		
	GPIO_SetBits(GPIOB,GPIO_Pin_0);//����ʵ��д�룬���ڲ���BSRR�Ĵ���
	Delay(1000);
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);//����BRR
	Delay(1000);
	}
}

void Delay(uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--)
	;
}

#endif


//��ҵ��ʹ�ù̼���ķ�ʽ����ʣ�µ�����LED
#if 0
int main (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//����һ���ṹ�壬������GPIO_InitStructure���ṹ��ԭ����GPIO_InitTypeDef ȷ��
	RCC->APB2ENR |=(1<<3);//�ýṹ�壬�����иĽ��ռ䡣

	//������ɫ
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB,&GPIO_InitStructure);//ֵ��д��Ĵ���
//	GPIO_SetBits(GPIOB,GPIO_Pin_0);//����ʵ��д�룬���ڲ���BSRR�Ĵ���
//    GPIO_RestBits(GPIOB, GPIO_Pin_0);//����BRR
	//������ɫ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);//ֵ��д��Ĵ���
	GPIO_SetBits(GPIOB,GPIO_Pin_5);//����ʵ��д�룬���ڲ���BSRR�Ĵ���
    //GPIO_RestBits(GPIOB, GPIO_Pin_5);//����BRR
	//������ɫ
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_RestBits(GPIOB, GPIO_Pin_1);
}
#endif


