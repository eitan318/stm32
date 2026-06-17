#include "btn.h"
#include "gpio.h"
#include "led.h"
#include "rcc.h"
#include <stdint.h>

void delay(volatile uint32_t cycles) {
  while (cycles--) {
  }
}

void reset_handler() {
  gpio_pin_t pin_led_green = {.idx = 0, .gpio = GPIOB};
  gpio_pin_t pin_led_yellow = {.idx = 1, .gpio = GPIOE};
  gpio_pin_t pin_led_red = {.idx = 14, .gpio = GPIOB};
  gpio_pin_t pin_user_btn = {.idx = 13, .gpio = GPIOC};

  // Enable clocks
  //
  // clang-format off
  RCC->AHB4ENR |=
      RCC_AHB4ENR_GPIOAEN |
      RCC_AHB4ENR_GPIOBEN |
      RCC_AHB4ENR_GPIOCEN |
      RCC_AHB4ENR_GPIOEEN;
  // clang-format on

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
