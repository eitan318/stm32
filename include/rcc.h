#include <stdint.h>

/* RCC base addresses */
#define RCC_BASE 0x58024400

#define RCC_AHB4ENR_OFFSET 0xe0

typedef struct {
  char placeholder[RCC_AHB4ENR_OFFSET];
  volatile uint32_t AHB4ENR;
} RCC_Registers;

#define RCC ((RCC_Registers *)RCC_BASE)
