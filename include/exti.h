#pragma once
#include "stdint.h"

typedef struct {
  volatile uint32_t RTSR1;
  volatile uint32_t FTSR1; // Falling Trigger Selection Registe
  volatile uint32_t SWIER1;
  volatile uint32_t D3PMR1;
  volatile uint32_t D3PCR1L;
  volatile uint32_t D3PCR1H;
  volatile uint32_t RESERVED1[2];
  volatile uint32_t RTSR2;
  volatile uint32_t FTSR2;
  volatile uint32_t SWIER2;
  volatile uint32_t D3PMR2;
  volatile uint32_t D3PCR2L;
  volatile uint32_t D3PCR2H;
  volatile uint32_t RESERVED2[2];
  volatile uint32_t RTSR3;
  volatile uint32_t FTSR3;
  volatile uint32_t SWIER3;
  volatile uint32_t D3PMR3;
  volatile uint32_t D3PCR3L;
  volatile uint32_t D3PCR3H;
  volatile uint32_t RESERVED3[10];
  volatile uint32_t IMR1;
  volatile uint32_t EMR1;
  volatile uint32_t PR1;
  volatile uint32_t RESERVED4;
  volatile uint32_t IMR2;
  volatile uint32_t EMR2;
  volatile uint32_t PR2;
  volatile uint32_t RESERVED5;
  volatile uint32_t IMR3;
  volatile uint32_t EMR3;
  volatile uint32_t PR3;
} exti_regs_t;

// Extended Interrupt/Event Controller
#define EXTI_BASE 0x58000000UL
#define EXTI ((exti_regs_t *)EXTI_BASE)

void exti_configure_edge(uint32_t index);
