#include "clock.h"
#include "led.h"
#include <stdint.h>

void delay(volatile uint32_t cycles) {
  while (cycles--) {
  }
}

void reset_handler() {
  clocks_enable();
  led1_init();
  for (;;) {
    led1_on();
    delay(1000000);
    led1_off();
    delay(1000000);
  }
}
