#include "led.h"

void led_init(gpio_pin_t *pin) {
  gpio_clock_enable(pin->gpio);

  // Clear moder
  pin->gpio->MODER &= ~(0x3U << (pin->idx * 2));

  // Set mode to output
  pin->gpio->MODER |= (GPIO_MODER_GPOUTPUT << (pin->idx * 2));

  // Set output type to push-pull (default)
  pin->gpio->OTYPER |= (GPIO_OTYPE_PUSHPULL << pin->idx);
}

void led_on(gpio_pin_t *pin) {
  // Set the pin of the LED
  pin->gpio->BSRR = (1U << pin->idx);
}

void led_off(gpio_pin_t *pin) {
  // Reset the pin of the LED
  pin->gpio->BSRR = (1U << (pin->idx + 16));
}
