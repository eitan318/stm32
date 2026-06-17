#include "user_btn.h"
#include "gpio.h"

void user_button_init() {
  // Clear MODER
  GPIOC->MODER &= ~(3U << (USER_BUTTON_PIN * 2));

  // Set MODER to input
  GPIOC->MODER |= GPIO_MODER_INPUT << (USER_BUTTON_PIN * 2);

  // Clear PUPDR
  GPIOC->PUPDR &= ~(3U << (USER_BUTTON_PIN * 2));

  // None - there is an external Pull-Down on the board (1 is pressed, 0 is not)
  GPIOC->PUPDR |= GPIO_PUPDR_NONE << (USER_BUTTON_PIN * 2);
}

int user_button_get() { return GPIOC->IDR & (1U << USER_BUTTON_PIN); }
