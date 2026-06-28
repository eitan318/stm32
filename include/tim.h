#pragma once
#include "stdint.h"

#define CLOCK_FREQ_HZ 64 * 1000000

typedef struct {
  volatile uint32_t CR1; // Control Register 1
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER; // DMA/Interrupt enable register
  volatile uint32_t SR;   // Status Register

  volatile uint32_t EGR;   // Event generation register
  volatile uint32_t CCMR1; // Capture/Compare mode register 1
  volatile uint32_t CCMR2; // Capture/Compare mode register 2
  volatile uint32_t CCER;  // Capture/Compare enable register
  volatile uint32_t CNT;   // Counter
  volatile uint32_t PSC;   // Prescalar
  volatile uint32_t ARR;   // Auto-reload register
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
} tim_regs_t;

#define TIM2_BASE 0x40000000UL
#define TIM3_BASE 0x40000400UL

#define TIM2 ((tim_regs_t *)TIM2_BASE)
#define TIM3 ((tim_regs_t *)TIM3_BASE)

// TIMx enabling
#define RCC_APB1LENR_TIM2EN (1U << 0)
#define RCC_APB1LENR_TIM3EN (1U << 1)

#define TIM_CR1_CEN (1U << 0)  // Counter enable
#define TIM_CR1_ARPE (1U << 7) // Auto-reload preload enable

#define TIM_DIER_UIE (1U << 0) // Update interrupt enable

#define TIM_SR_UIF (1U << 0) // Update interrupt flag

#define TIM_EGR_UG (1U << 0) // Update generation

// Pulse Width Modulation Mode
#define PWM_MODE1 6U
#define PWM_MODE2 7U

/* CCMR1 (chnnels 1-2) */

// Capture/Compare 1 Set
#define TIM_CCMR1_CC1S_OC (0U << 0) // Output compare
// Output Compare 1 Preload enable
#define TIM_CCMR1_OC1PE (1U << 3)
// Output Compare 1 Mode
#define TIM_CCMR1_OC1M_PWM1 (PWM_MODE1 << 4)

// Capture/Compare 2 Set
#define TIM_CCMR1_CC2S_OC (0U << 8) // Output compare
// Output Compare 2 Preload enable
#define TIM_CCMR1_OC2PE (1U << 11)
// Output Compare 2 Mode
#define TIM_CCMR1_OC2M_PWM1 (PWM_MODE1 << 12)

/* CCMR2 (chnnels 3-4)*/

// Capture/Compare 3 Set
#define TIM_CCMR2_CC3S_OC (0U << 0) // Output compare
// Output Compare 3 Preload enable
#define TIM_CCMR2_OC3PE (1U << 3)
// Output Compare 3 Mode
#define TIM_CCMR2_OC3M_PWM1 (PWM_MODE1 << 4)

// Capture/Compare 4 Set
#define TIM_CCMR2_CC4S_OC (0U << 8) // Output compare
// Output Compare 4 Preload enable
#define TIM_CCMR2_OC4PE (1U << 11)
// Output Compare 4 Mode
#define TIM_CCMR2_OC4M_PWM1 (PWM_MODE1 << 12)

/*CCER*/
// Output Compare 3 Enable
#define TIM_CCER_CC3E (1U << 8)

/*  Timer Frequency = APB Clock / (PSC + 1)
 *
 *  Overflow Time = (ARR + 1) × (PSC + 1) / APB Clock
 */

void tim2_init(uint32_t desired_freq_hz, uint32_t apb_clock_freq_hz);
void tim2_delay(uint32_t ticks);
void tim3_pwm_init(uint32_t desired_freq_hz, uint32_t apb_clock_freq);
void tim3_pwm_set_duty_cycle(uint32_t precent);
