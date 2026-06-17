#pragma once
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
} gpio_regs_t;

/* GPIO base addresses */
#define GPIOA_BASE 0x58020000
#define GPIOB_BASE 0x58020400
#define GPIOC_BASE 0x58020800
#define GPIOD_BASE 0x58020c00
#define GPIOE_BASE 0x58021000
#define GPIOF_BASE 0x58021400
#define GPIOG_BASE 0x58021800
#define GPIOH_BASE 0x58021c00
#define GPIOI_BASE 0x58022000
#define GPIOJ_BASE 0x58022400
#define GPIOK_BASE 0x58022800

#define GPIOA ((gpio_regs_t *)GPIOA_BASE)
#define GPIOB ((gpio_regs_t *)GPIOB_BASE)
#define GPIOC ((gpio_regs_t *)GPIOC_BASE)
#define GPIOD ((gpio_regs_t *)GPIOD_BASE)
#define GPIOE ((gpio_regs_t *)GPIOE_BASE)
#define GPIOF ((gpio_regs_t *)GPIOF_BASE)
#define GPIOG ((gpio_regs_t *)GPIOG_BASE)
#define GPIOH ((gpio_regs_t *)GPIOH_BASE)
#define GPIOI ((gpio_regs_t *)GPIOI_BASE)
#define GPIOJ ((gpio_regs_t *)GPIOJ_BASE)
#define GPIOK ((gpio_regs_t *)GPIOK_BASE)

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

typedef struct {
  gpio_regs_t *gpio;
  uint8_t idx;
} gpio_pin_t;
