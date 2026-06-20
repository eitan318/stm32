#include "tim.h"
#include "gpio.h"
#include "rcc.h"
#include <stdint.h>

void tim3_pwm_init(uint32_t desired_freq_hz, uint32_t apb_clock_freq_hz) {
  RCC->APB1LENR |= RCC_APB1LENR_TIM3EN;
  (void)RCC->APB1LENR;

  gpio_clock_enable(GPIOB);

  GPIOB->MODER &= ~(3U << (0 * 2));
  GPIOB->MODER |= (GPIO_MODER_AF << (0 * 2));

  GPIOB->AFR[0] &= ~(0xF << (0 * 4));
  GPIOB->AFR[0] |= (2U << (0 * 4));

  uint32_t ticks = apb_clock_freq_hz / desired_freq_hz;
  uint32_t psc = 0;
  while (ticks > 0xFFFFFFFFUL) { // only matters for extremely low freqs
    psc++;
    ticks = apb_clock_freq_hz / (desired_freq_hz * (psc + 1));
  }
  TIM3->PSC = psc;
  TIM3->ARR = ticks - 1;

  // Output compare | Mode preload enable | PWM mode 1
  TIM3->CCMR2 = TIM_CCMR2_CC3S_OC | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3M_PWM1;

  // Enable channel 3 output
  TIM3->CCER |= TIM_CCER_CC3E;

  // Initial duty cycle 0
  TIM3->CCR3 = 0;

  // Enable update event generation
  TIM3->EGR = TIM_EGR_UG;

  // Enable auto reload preload and counter
  TIM3->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN;
}

void tim3_pwm_set_duty_cycle(uint32_t precent) {
  // precent = 100 * (ARR / CCR)
  // CCR = 100 * (ARR / precent)
  if (precent > 100)
    precent = 100;
  TIM3->CCR3 = (TIM3->ARR * precent) / 100;
}

/*
 * calc: clock = psc
 *
 */
void tim2_init(uint32_t desired_freq_hz, uint32_t apb_clock_freq_hz) {
  RCC->APB1LENR |= RCC_APB1LENR_TIM2EN;
  (void)RCC->APB1LENR;

  uint32_t ticks = apb_clock_freq_hz / desired_freq_hz;
  uint32_t psc = 0;
  while (ticks > 0xFFFFFFFFUL) { // only matters for extremely low freqs
    psc++;
    ticks = apb_clock_freq_hz / (desired_freq_hz * (psc + 1));
  }
  TIM2->PSC = psc;
  TIM2->ARR = ticks - 1;

  // Generate update event to load prescalar
  TIM2->EGR = TIM_EGR_UG;

  // Clear interrupt flag
  TIM2->SR = 0;

  // Enable the update interrupt
  TIM2->DIER |= TIM_DIER_UIE;

  // Enable the counter
  TIM2->CR1 |= TIM_CR1_CEN;
}

void tim2_delay(uint32_t ticks) {
  for (uint32_t i = 0; i < ticks; i++) {
    while (!(TIM2->SR & TIM_SR_UIF))
      ;
    TIM2->SR &= ~TIM_SR_UIF;
  }
}
