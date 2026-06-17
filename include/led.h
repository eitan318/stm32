#pragma once
#include "gpio.h"

void led_init(gpio_pin_t *pin);
void led_on(gpio_pin_t *pin);
void led_off(gpio_pin_t *pin);
