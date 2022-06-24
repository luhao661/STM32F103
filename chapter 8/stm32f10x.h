#ifndef _STM32F10X_H//名称可以随意取，一般取文件名称。 前面的下划线用于区分用户定义的一般的宏，这是行业习惯。
#define _STM32F10X_H//最底端要写#endif


#define PERIPHERAL_BASE        ((unsigned int)0x40000000)
#define APB1PERIPHERAL_BASE    PERIPHERAL_BASE
#define APB2PERIPHERAL_BASE    (PERIPHERAL_BASE+0x10000)
#define AHBPERIPHERAL_BASE    (PERIPHERAL_BASE+0x20000)//定位在DMA1，算RCC时好算

#define RCC_BASE                (AHBPERIPHERAL_BASE+0x1000)
#define GPIOB_BASE              (APB2PERIPHERAL_BASE+0x0c00)

#define RCC_APB2ENR            *(unsigned int*)(RCC_BASE+0x18)//指针强制类型转换为32位
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
