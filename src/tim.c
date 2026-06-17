#include "tim.h"
#include <stdint.h>

void set_timer(uint32_t secs) { TIM2->ARR = secs; }
