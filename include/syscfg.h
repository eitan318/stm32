#pragma once
#include "stdint.h"

typedef struct {
  volatile uint32_t RESERVED1;
  volatile uint32_t PMCR;
  volatile uint32_t EXTICR[4];
} syscfg_regs_t;

#define SYSCFG_BASE 0x58000400UL
#define SYSCFG ((syscfg_regs_t *)SYSCFG_BASE)

#define RCC_APB4ENR_SYSCFGEN (1U << 1)
