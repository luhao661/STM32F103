#include "stm32f10x.h"
void SystemInit (void)
{

}

//������ɫLED
//int main (void)
//{
//	//��GPIOB�˿ڵ�ʱ��
//*(unsigned int *)0x40021018|=((1)<<3);
//	//����IO��Ϊ���ģʽ
//*(unsigned int *)0x40010C00 |=((1)<<(4*0));
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




