#pragma once
#include <stdbool.h>
#include <stdint.h>

// NVIC Register Addresses
#define NVIC_ISER_BASE 0xe000e100 // Interrupt Set-Enable Registers
#define NVIC_ICER_BASE 0xe000e180 // Interrupt Clear-Enable Registers
#define NVIC_ISPR_BASE 0xe000e200 // Interrupt Set-Pending Registers
#define NVIC_ICPR_BASE 0xe000e280 // Interrupt Clear-Pending Registers
#define NVIC_IABR_BASE 0xe000e300 // Interrupt Active Bit Registers
#define NVIC_IPR_BASE 0xe000e400  // Interrupt Priority Registers

// System Control Block
#define SCB_BASE 0xe000ed00
#define SCB_AIRCR (*(volatile uint32_t *)(SCB_BASE + 0x0C))

// NVIC register arrays
#define NVIC_ISER ((volatile uint32_t *)NVIC_ISER_BASE)
#define NVIC_ICER ((volatile uint32_t *)NVIC_ICER_BASE)
#define NVIC_ISPR ((volatile uint32_t *)NVIC_ISPR_BASE)
#define NVIC_ICPR ((volatile uint32_t *)NVIC_ICPR_BASE)
#define NVIC_IABR ((volatile uint32_t *)NVIC_IABR_BASE)
#define NVIC_IPR ((volatile uint8_t *)NVIC_IPR_BASE)

// STM32 IRQs
#define WWDG_IRQn 0
#define PVD_AVD_IRQn 1
#define RTC_TAMP_STAMP_IRQn 2
#define RTC_WKUP_IRQn 3
#define FLASH_IRQn 4
#define RCC_IRQn 5
#define EXTI0_IRQn 6
#define EXTI1_IRQn 7
#define EXTI2_IRQn 8
#define EXTI3_IRQn 9
#define EXTI4_IRQn 10
#define DMA1_Stream0_IRQn 11
#define DMA1_Stream1_IRQn 12
#define DMA1_Stream2_IRQn 13
#define DMA1_Stream3_IRQn 14
#define DMA1_Stream4_IRQn 15
#define DMA1_Stream5_IRQn 16
#define DMA1_Stream6_IRQn 17
#define ADC_IRQn 18
#define TIM1_BRK_IRQn 23
#define TIM1_UP_IRQn 24
#define TIM1_TRG_COM_IRQn 25
#define TIM1_CC_IRQn 26
#define TIM2_IRQn 28
#define TIM3_IRQn 29
#define TIM4_IRQn 30
#define I2C1_EV_IRQn 31
#define I2C1_ER_IRQn 32
#define SPI1_IRQn 35
#define USART1_IRQn 37
#define USART2_IRQn 38
#define USART3_IRQn 39
#define EXTI15_10_IRQn 40
#define TIM5_IRQn 50
#define SPI2_IRQn 51
#define UART4_IRQn 52
#define TIM6_DAC_IRQn 54
#define TIM7_IRQn 55
#define DMA2_Stream0_IRQn 56
#define I2C3_EV_IRQn 72
#define I2C3_ER_IRQn 73

void nvic_irq_enable(uint8_t irq);
void nvic_irq_disable(uint8_t irq);
/*
 * Set the priority of an IRQ in the nvic
 * @note: prioriry range 0-15
 */
void nvic_irq_set_priority(uint8_t irq, uint8_t priority);
bool nvic_irq_is_pending(uint8_t irq);
void nvic_irq_clear_pending(uint8_t irq);
