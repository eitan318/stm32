#include "btn.h"
#include "gpio.h"
#include "rcc.h"

void button_init(gpio_pin_t *pin) {
  RCC->AHB4ENR |= RCC_AHB4ENR_GPIOCEN;
  (void)RCC->AHB4ENR;

  // Clear MODER
  pin->gpio->MODER &= ~(3U << (pin->idx * 2));

  // Set MODER to input
  pin->gpio->MODER |= GPIO_MODER_INPUT << (pin->idx * 2);

  // Clear PUPDR
  pin->gpio->PUPDR &= ~(3U << (pin->idx * 2));

  // None - there is an external Pull-Down on the board (1 is pressed, 0 is not)
  GPIOC->PUPDR |= GPIO_PUPDR_NONE << (pin->idx * 2);
}

bool button_is_on(gpio_pin_t *pin) {
  return (pin->gpio->IDR & (1U << pin->idx)) != 0;
}
