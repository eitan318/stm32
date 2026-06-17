#pragma once
#include "stdint.h"

typedef struct {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
} tim_regs_t;

#define TIM2_BASE 0x40000000UL
#define TIM3_BASE 0x40000400UL

#define TIM2 ((tim_regs_t *)TIM2_BASE)
#define TIM3 ((tim_regs_t *)TIM3_BASE)

#define RCC_APB1LENR_TIM2EN (1U << 0)

void set_timer(uint32_t secs);
