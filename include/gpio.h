#include <stdint.h>

/* Created based on "GPIO register map" table in the Reference Manual */
typedef struct {
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2];
} GPIO_Registers;

/* GPIO base addresses */
#define GPIOA_BASE 0x58020000
#define GPIOB_BASE 0x58020400
#define GPIOC_BASE 0x58020800

#define GPIOA ((GPIO_Registers *)GPIOA_BASE)
#define GPIOB ((GPIO_Registers *)GPIOB_BASE)
#define GPIOC ((GPIO_Registers *)GPIOC_BASE)

/* GPIO OTYPER values (2 bits per pin) */
#define GPIO_MODER_INPUT 0U
#define GPIO_MODER_GPOUTPUT 1U
#define GPIO_MODER_AF 2U
#define GPIO_MODER_ANALOG 3U

/* GPIO OTYPER values (1 bit per pin) */
#define GPIO_OTYPE_PUSHPULL 0U
#define GPIO_OTYPE_OPENDRAIN 1U

/* GPIO PUPDR values (2 bits per pin) */
#define GPIO_PUPDR_NONE 0U
#define GPIO_PUPDR_PULLUP 1U
#define GPIO_PUPDR_PULLDOWN 2U
#define GPIO_PUPDR_RESERVED 3U
