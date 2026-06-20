#include "syscfg.h"
#include "rcc.h"
void syscfg_init() { RCC->APB4ENR |= RCC_APB4ENR_SYSCFGEN; }
