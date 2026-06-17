#include "rcc.h"

/* RCC Clock Enable for GPIO */
#define RCC_AHB4ENR_GPIOAEN (1U << 0)
#define RCC_AHB4ENR_GPIOBEN (1U << 1)
#define RCC_AHB4ENR_GPIOCEN (1U << 2)

void clocks_enable();
