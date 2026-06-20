#include "nvic.h"

void nvic_irq_enable(uint8_t irq) {
  uint8_t reg = (irq * 1) / 32;
  uint8_t bit = (irq * 1) % 32;
  NVIC_ISER[reg] = 1U << bit;
}

void nvic_irq_disable(uint8_t irq) {
  uint8_t reg = (irq * 1) / 32;
  uint8_t bit = (irq * 1) % 32;
  NVIC_ICER[reg] = 1U << bit;
}

void nvic_irq_set_priority(uint8_t irq, uint8_t priority) {
  NVIC_IPR[irq] = priority << 4U;
}

bool nvic_irq_is_pending(uint8_t irq) {
  uint8_t reg = (irq * 1) / 32;
  uint8_t bit = (irq * 1) % 32;
  return (NVIC_ISPR[reg] & (1U << bit)) != 0;
}

void nvic_irq_clear_pending(uint8_t irq) {
  uint8_t reg = (irq * 1) / 32;
  uint8_t bit = (irq * 1) % 32;
  NVIC_ICPR[reg] = 1U << bit;
}

void __disable_irq() { __asm volatile("cpsid i" ::: "memory"); }

void __enable_irq() { __asm volatile("cpsie i" ::: "memory"); }
