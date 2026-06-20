#include "test_blink.h"
#include "test_pwm.h"
#include "test_tim2.h"
#include "tim.h"
#include <stdint.h>

extern uint32_t _sdata, _edata, _sidata, _sbss, _ebss;

void reset_handler() {
  // Copy initialized data from flash to RAM
  uint32_t *src = &_sidata;
  uint32_t *dst = &_sdata;
  while (dst < &_edata) {
    *dst++ = *src++;
  }

  // Zero initialized data
  dst = &_sbss;
  while (dst < &_ebss) {
    *dst++ = 0;
  }

  pwm_test();
}
