#pragma once
#include "btn.h"
#include "gpio.h"
#include "led.h"
#include "nvic.h"
#include "rcc.h"
#include "syscfg.h"
#include "tim.h"
#include <stdint.h>

void pwm_test() {
  tim3_pwm_init(1000, CLOCK_FREQ_HZ);
  tim2_init(1000, CLOCK_FREQ_HZ);
  /* Breathing LED effect */
  for (;;) {
    /* Fade in */
    for (uint8_t i = 0; i <= 100; i++) {
      tim3_pwm_set_duty_cycle(i);
      tim2_delay(10);
    }

    /* Fade out */
    for (uint8_t i = 100; i > 0; i--) {
      tim3_pwm_set_duty_cycle(i);
      tim2_delay(10);
    }
  }
}
