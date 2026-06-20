#include "gpio.h"
#include "rcc.h"

void gpio_clock_enable(gpio_regs_t *gpio) {
  uint32_t idx = ((uintptr_t)gpio - GPIOA_BASE) / 0x400U;
  RCC->AHB4ENR |= (1U << idx);
  (void)RCC->AHB4ENR;
}
