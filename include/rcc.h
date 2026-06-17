#include <stdint.h>

/* RCC base addresses */
#define RCC_BASE 0x58024400

typedef struct {
  volatile uint32_t CR;
  volatile uint32_t HSICFGR;
  volatile uint32_t CRRCR;
  volatile uint32_t CSICFGR;
  volatile uint32_t CFGR;
  volatile uint32_t RESERVED1;
  volatile uint32_t D1CFGR;
  volatile uint32_t D2CFGR;
  volatile uint32_t D3CFGR;
  volatile uint32_t RESERVED2;
  volatile uint32_t PLLCKSELR;
  volatile uint32_t PLLCFGR;
  volatile uint32_t PLL1DIVR;
  volatile uint32_t PLL1FRACR;
  volatile uint32_t PLL2DIVR;
  volatile uint32_t PLL2FRACR;
  volatile uint32_t PLL3DIVR;
  volatile uint32_t PLL3FRACR;
  volatile uint32_t RESERVED3;
  volatile uint32_t D1CCIPR;
  volatile uint32_t D2CCIP1R;
  volatile uint32_t D2CCIP2R;
  volatile uint32_t D3CCIPR;
  volatile uint32_t RESERVED4;
  volatile uint32_t CIER;
  volatile uint32_t CIFR;
  volatile uint32_t CICR;
  volatile uint32_t RESERVED5;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
  volatile uint32_t RESERVED6;
  volatile uint32_t AHB3RSTR;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR;
  volatile uint32_t AHB4RSTR;
  volatile uint32_t APB3RSTR;
  volatile uint32_t APB1LRSTR;
  volatile uint32_t APB1HRSTR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB4RSTR;
  volatile uint32_t GCR;
  volatile uint32_t RESERVED7;
  volatile uint32_t D3AMR;
  volatile uint32_t RESERVED8[9];
  volatile uint32_t RSR;
  volatile uint32_t AHB3ENR;
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR;
  volatile uint32_t AHB4ENR;
  volatile uint32_t APB3ENR;
  volatile uint32_t APB1LENR;
  volatile uint32_t APB1HENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB4ENR;
} rcc_regs_t;

#define RCC ((rcc_regs_t *)RCC_BASE)
