#include <stdint.h>
volatile uint32_t FAKE_AFR = 0;

void ex4_set_pin_af7() {
  FAKE_AFR &= ~(0xfU << 3 * 4);
  FAKE_AFR |= 7U << 3 * 4;
}

volatile uint32_t FAKE_SPI_CFG = 0;

void ex7_combine_settings(void) {
  FAKE_SPI_CFG = (0 & ~((7U << 3) | (7U << 8))) | (4U << 3) | (5U << 8);
}
