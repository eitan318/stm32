#include "led.h"
#include "gpio.h"

void led1_init() {
  // Clear moder
  GPIOB->MODER &= ~(0x3U << (PIN_LED1 * 2));

  // Set mode to output
  GPIOB->MODER |= (GPIO_MODER_GPOUTPUT << (PIN_LED1 * 2));

  // Set output type to push-pull (default)
  GPIOB->OTYPER |= (GPIO_OTYPE_PUSHPULL << PIN_LED1);
}

void led1_on() {
  // Set the pin of the LED
  GPIOB->BSRR = (1U << PIN_LED1);
}

void led1_off() {
  // Reset the pin of the LED
  GPIOB->BSRR = (1U << (PIN_LED1 + 16));
}
