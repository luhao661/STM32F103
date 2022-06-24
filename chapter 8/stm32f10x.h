#ifndef _STM32F10X_H//���ƿ�������ȡ��һ��ȡ�ļ����ơ� ǰ����»������������û������һ��ĺ꣬������ҵϰ�ߡ�
#define _STM32F10X_H//��׶�Ҫд#endif


#define PERIPHERAL_BASE        ((unsigned int)0x40000000)
#define APB1PERIPHERAL_BASE    PERIPHERAL_BASE
#define APB2PERIPHERAL_BASE    (PERIPHERAL_BASE+0x10000)
#define AHBPERIPHERAL_BASE    (PERIPHERAL_BASE+0x20000)//��λ��DMA1����RCCʱ����

#define RCC_BASE                (AHBPERIPHERAL_BASE+0x1000)
#define GPIOB_BASE              (APB2PERIPHERAL_BASE+0x0c00)

#define RCC_APB2ENR            *(unsigned int*)(RCC_BASE+0x18)//ָ��ǿ������ת��Ϊ32λ
//#define GPIOB_CRL              *(unsigned int*)(GPIOB_BASE+0x00)
//#define GPIOB_CRH              *(unsigned int*)(GPIOB_BASE+0x04)
//#define GPIOB_ODR              *(unsigned int*)(GPIOB_BASE+0x0c)
//#define GPIOB_BSRR				*(unsigned int*)(GPIOB_BASE+0x10)
//#define GPIOB_BRR				*(unsigned int*)(GPIOB_BASE+0x14)

typedef unsigned int      uint32_t;
typedef unsigned short    uint16_t;

typedef struct
{
uint32_t CRL;
uint32_t CRH;
uint32_t IDR;
uint32_t ODR;
uint32_t BSRR;
uint32_t BRR;
uint32_t LCKR;

}GPIO_TypeDef;
	
#define GPIOB ((GPIO_TypeDef*)GPIOB_BASE)


typedef struct
{
uint32_t CR;
uint32_t CFGR;
uint32_t CIR;
uint32_t APB2RSTR;
uint32_t APB1RSTR;
uint32_t AHBENR;
uint32_t APB2ENR;
uint32_t APB1ENR;
uint32_t BDCR;
uint32_t CSR;
	
}RCC_TypeDef;
	
#define RCC ((RCC_TypeDef*)RCC_BASE )

#endif /*_STM32F10X_H*/
