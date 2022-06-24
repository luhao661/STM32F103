#ifndef _STM32F10x_GPIO_H//���ƿ�������ȡ��һ��ȡ�ļ����ơ�
#define _STM32F10x_GPIO_H

#include "stm32f10x.h"
#define GPIO_Pin_0 ((uint16_t)0x0001)
#define GPIO_Pin_1 ((uint16_t)0x0002)
#define GPIO_Pin_2 ((uint16_t)0x0004)//ת��Ϊ2������00000000 0000100b
#define GPIO_Pin_3 ((uint16_t)0x0008)//ת��Ϊ2������00000000 0001000b
#define GPIO_Pin_4 ((uint16_t)0x0010)
#define GPIO_Pin_5 ((uint16_t)0x0020)
#define GPIO_Pin_6 ((uint16_t)0x0040)
#define GPIO_Pin_7 ((uint16_t)0x0080)
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */



typedef enum//ʹ��ö�ٶ���Ľṹ��
{
GPIO_Speed_10MHz = 1,
GPIO_Speed_2MHz,//����Ļ��Զ�=2,=3
GPIO_Speed_50MHz
	
}GPIOSpeed_TypeDef;

typedef enum
{ GPIO_Mode_AIN = 0x0,           // ģ������
  GPIO_Mode_IN_FLOATING = 0x04,  // ��������
  GPIO_Mode_IPD = 0x28,          // ��������
  GPIO_Mode_IPU = 0x48,          // ��������
  GPIO_Mode_Out_OD = 0x14,       // ��©���
  GPIO_Mode_Out_PP = 0x10,       // �������
  GPIO_Mode_AF_OD = 0x1C,        // ���ÿ�©���
  GPIO_Mode_AF_PP = 0x18         // �����������
}GPIOMode_TypeDef;

typedef struct
{
	uint16_t           GPIO_Pin;
	GPIOSpeed_TypeDef  GPIO_Speed;
	GPIOMode_TypeDef   GPIO_Mode;
} GPIO_InitTypeDef;


void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);//������Ҫ�ӷֺš�
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);//�˾��������ڽṹ�嶨��ǰ����ᱨ��
																		//δ�ҵ�GPIO_InitTypeDef


#endif
