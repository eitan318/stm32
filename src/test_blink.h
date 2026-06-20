#include "btn.h"
#include "gpio.h"
#include "led.h"
#include "tim.h"
#include <stdint.h>

void blink_test() {
  gpio_pin_t pin_led_green = {.idx = 0, .gpio = GPIOB};
  gpio_pin_t pin_led_yellow = {.idx = 1, .gpio = GPIOE};
  gpio_pin_t pin_led_red = {.idx = 14, .gpio = GPIOB};
  gpio_pin_t pin_user_btn = {.idx = 13, .gpio = GPIOC};

  tim2_init(1000, CLOCK_FREQ_HZ);

  led_init(&pin_led_red);
  led_init(&pin_led_green);
  led_init(&pin_led_yellow);
  button_init(&pin_user_btn);

  for (;;) {
    if (button_is_on(&pin_user_btn)) {
      // blink
      led_on(&pin_led_red);
      led_on(&pin_led_green);
      led_on(&pin_led_yellow);
      tim2_delay(100);
      led_off(&pin_led_red);
      led_off(&pin_led_green);
      led_off(&pin_led_yellow);
      tim2_delay(100);
    }
  }
}
