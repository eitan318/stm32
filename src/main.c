#include "btn.h"
#include "gpio.h"
#include "led.h"
#include "rcc.h"
#include "syscfg.h"
#include "tim.h"
#include <stdint.h>

void delay(volatile uint32_t cycles) {
  while (cycles--) {
  }
}

void enable_clocks() {
  // Enable gpio clocks
  // clang-format off
  RCC->AHB4ENR |=
      RCC_AHB4ENR_GPIOAEN |
      RCC_AHB4ENR_GPIOBEN |
      RCC_AHB4ENR_GPIOCEN |
      RCC_AHB4ENR_GPIOEEN;
  // clang-format on

  // Enable SYSCFG clock (for EXTI)
  RCC->APB4ENR |= RCC_APB4ENR_SYSCFGEN;

  // Enable TIM2 clock
  RCC->AHB1ENR |= RCC_APB1LENR_TIM2EN;
}

void reset_handler() {
  gpio_pin_t pin_led_green = {.idx = 0, .gpio = GPIOB};
  gpio_pin_t pin_led_yellow = {.idx = 1, .gpio = GPIOE};
  gpio_pin_t pin_led_red = {.idx = 14, .gpio = GPIOB};
  gpio_pin_t pin_user_btn = {.idx = 13, .gpio = GPIOC};

  enable_clocks();
  led_init(&pin_led_red);
  led_init(&pin_led_green);
  led_init(&pin_led_yellow);
  button_init(&pin_user_btn);

  for (;;) {
    if (button_get(&pin_user_btn)) {
      // blink
      led_on(&pin_led_red);
      led_on(&pin_led_green);
      led_on(&pin_led_yellow);
      delay(1000000);
      led_off(&pin_led_red);
      led_off(&pin_led_green);
      led_off(&pin_led_yellow);
      delay(1000000);
    }
  }
}
