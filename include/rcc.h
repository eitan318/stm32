#include <stdint.h>

/* RCC base addresses */
#define RCC_BASE 0x58024400
#define RCC_AHB4ENR_OFFSET 0xe0

typedef struct {
  char placeholder[RCC_AHB4ENR_OFFSET];
  volatile uint32_t AHB4ENR;
} rcc_regs_t;

#define RCC ((rcc_regs_t *)RCC_BASE)

/* RCC Clock Enable for GPIO */
#define RCC_AHB4ENR_GPIOAEN (1U << 0)
#define RCC_AHB4ENR_GPIOBEN (1U << 1)
#define RCC_AHB4ENR_GPIOCEN (1U << 2)
#define RCC_AHB4ENR_GPIODEN (1U << 3)
#define RCC_AHB4ENR_GPIOEEN (1U << 4)
#define RCC_AHB4ENR_GPIOFEN (1U << 5)
#define RCC_AHB4ENR_GPIOGEN (1U << 6)
#define RCC_AHB4ENR_GPIOHEN (1U << 7)
#define RCC_AHB4ENR_GPIOIEN (1U << 8)
#define RCC_AHB4ENR_GPIOJEN (1U << 9)
#define RCC_AHB4ENR_GPIOKEN (1U << 10)
