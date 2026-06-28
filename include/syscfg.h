#pragma once
#include "stdint.h"

typedef struct {
  volatile uint32_t RESERVED1;
  volatile uint32_t PMCR;
  volatile uint32_t EXTICR[4];
  // more ....
} syscfg_regs_t;

// System configuration controlle
#define SYSCFG_BASE 0x58000400UL
#define SYSCFG ((syscfg_regs_t *)SYSCFG_BASE)

// External Interrupt Configuration Register
#define SYSCFG_EXTICR_PC 2

#define RCC_APB4ENR_SYSCFGEN (1U << 1)

void syscfg_init();
