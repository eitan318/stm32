#pragma once

// READ: https://www.pjrc.com/teensy/DDI0403Ee_arm_v7m_ref_manual.pdf

/* NVIC Register Addresses */
#define NVIC_ISER_BASE 0xE000E100UL /* Interrupt Set-Enable Registers */
#define NVIC_ICER_BASE 0xE000E180UL /* Interrupt Clear-Enable Registers */
#define NVIC_ISPR_BASE 0xE000E200UL /* Interrupt Set-Pending Registers */
#define NVIC_ICPR_BASE 0xE000E280UL /* Interrupt Clear-Pending Registers */
#define NVIC_IABR_BASE 0xE000E300UL /* Interrupt Active Bit Registers */
#define NVIC_IPR_BASE 0xE000E400UL  /* Interrupt Priority Registers */

/* System Control Block */
#define SCB_BASE 0xE000ED00UL
#define SCB_AIRCR (*(volatile uint32_t *)(SCB_BASE + 0x0C))

/* NVIC register arrays */
#define NVIC_ISER ((volatile uint32_t *)NVIC_ISER_BASE)
#define NVIC_ICER ((volatile uint32_t *)NVIC_ICER_BASE)
#define NVIC_ISPR ((volatile uint32_t *)NVIC_ISPR_BASE)
#define NVIC_ICPR ((volatile uint32_t *)NVIC_ICPR_BASE)
#define NVIC_IABR ((volatile uint32_t *)NVIC_IABR_BASE)
#define NVIC_IPR ((volatile uint8_t *)NVIC_IPR_BASE)
