#include "stm32f10x.h"
void SystemInit (void)
{

}

//ֱ�Ӳ����ڴ��ַ�� ������ɫLED
//int main (void)
//{
//	//��GPIOB�˿ڵ�ʱ��
//*(unsigned int *)0x40021018|=((1)<<3);                       //��unsigned int*����һ��ǿ������ת�������Ȱ�ָ��ǿ��ת���ɣ�unsigned int*���ͣ�Ȼ����ȡֵ
															//���� int *addr����ô����Ҫǿ��ת������Ϊ�еı�����������о��棬�������(unsigned int *)������ͻ���ʧ
//	//����IO��Ϊ���ģʽ									//*(unsigned int *)(a) = (v) ��������ʲô�� ��ַa֮���sizeof(unsigned int)���ֽڵ��ڴ渳ֵΪv��
//*(unsigned int *)0x40010C00 |=((1)<<(4*0));				//����ָ�����ͣ����Ǹ���ָ�����ܲ������ڴ浥λ���ȣ�(unsigned int *)(a)��˼����ֻ�ܲ���aָ���4���ֽڵĳ����ڴ档

//	//����ODR
//*(unsigned int *)0x40010C0C &=~(1<<0);
//}

//������ɫLED
//int main (void)
//{
//*(unsigned int *)0x40021018|=(1<<3);
//*(unsigned int *)0x40010C00 |=(1<<(4*5));
//*(unsigned int *)0x40010C0C &=~(1<<5);
//}

//������ɫLED
//int main (void)
//{
//*(unsigned int *)0x40021018|=(1<<3);
//*(unsigned int *)0x40010C00 |=(1<<(4*1));
//*(unsigned int *)0x40010C0C &=~(1<<1);
//}



#if (0)
//LED��˸
void delay(int num);
int main (void)
{
	while(1)
	{	//��GPIOB�˿ڵ�ʱ��
		*(unsigned int *)0x40021018|=((1)<<3);
			//����IO��Ϊ���ģʽ  CRL
		*(unsigned int *)0x40010C00 |=((1)<<(4*0));
			//����ODR
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

//�Ĵ���ӳ�䷨
#define PERIPHERAL_BASE        ((unsigned int)0x40000000)
#define APB1PERIPHERAL_BASE    PERIPHERAL_BASE
#define APB2PERIPHERAL_BASE    (PERIPHERAL_BASE+0x10000)
#define AHBPERIPHERAL_BASE    (PERIPHERAL_BASE+0x20000)//��λ��DMA1����RCCʱ����

#define RCC_BASE                (AHBPERIPHERAL_BASE+0x1000)
#define GPIOB_BASE              (APB2PERIPHERAL_BASE+0x0c00)

#define RCC_APB2ENR            *(unsigned int*)(RCC_BASE+0x18)//ָ��ǿ������ת��Ϊ32λ
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



