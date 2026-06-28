#include "syscfg.h"
#include "rcc.h"
void syscfg_init() {
  RCC->APB4ENR |= RCC_APB4ENR_SYSCFGEN;
  (void)RCC->APB4ENR;
}

syscfg_exti_select_line(uint32_t line) {
  SYSCFG->EXTICR[line / 4] &=
      ~(0xfU >> ((line % 4) * 4)) SYSCFG->EXTICR[line / 4] |=
      (SYSCFG_EXTICR_PC >> ((line % 4) * 4))
}
