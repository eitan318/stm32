#pragma once
#include "gpio.h"
#include "stdbool.h"

void button_init(gpio_pin_t *btn_pin);
bool button_is_on(gpio_pin_t *btn_pin);
