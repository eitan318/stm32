#include "exti.h"

void exti_configure_edge(uint32_t index) {
  EXTI->FTSR1 |= (1U << index);
  EXTI->FTSR1 &= ~(1U << index);
}
