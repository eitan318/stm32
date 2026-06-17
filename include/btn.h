#pragma once
#include "gpio.h"

void button_init(gpio_pin_t* btn_pin);
int button_get(gpio_pin_t* btn_pin);
