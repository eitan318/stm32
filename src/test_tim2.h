#include "btn.h"
#include "gpio.h"
#include "led.h"
#include "nvic.h"
#include "rcc.h"
#include "syscfg.h"
#include "tim.h"
#include <stdint.h>

static gpio_pin_t g_pin_led_red = {.idx = 14, .gpio = GPIOB};
static int counter = 0;

void tim2_handler() {
  TIM2->SR &= ~TIM_SR_UIF;
  if (counter == -1) {
    return;
  }
  counter++;
  if (counter >= 10) {
    led_off(&g_pin_led_red);
    counter = -1;
  }
}

void timer_test() {
  gpio_pin_t pin_user_btn = {.idx = 13, .gpio = GPIOC};

  led_init(&g_pin_led_red);
  button_init(&pin_user_btn);
  nvic_irq_enable(TIM2_IRQn);
  tim2_init(1, 64 * 1000000);

  for (;;) {
    if (button_is_on(&pin_user_btn)) {
      counter = 0;
      led_on(&g_pin_led_red);
    }
  }
}
