#include <stdint.h>

extern uint32_t _estack; // end of stack -> initial SP
extern void reset_handler(void);

void default_handler(void) {
  while (1) {
  }
}

#define WEAK_HANDLER __attribute__((weak, alias("default_handler")))

// Cortex-M7 core exceptions
void nmi_handler(void) WEAK_HANDLER;
void hardfault_handler(void) WEAK_HANDLER;
void memmanage_handler(void) WEAK_HANDLER;
void busfault_handler(void) WEAK_HANDLER;
void usagefault_handler(void) WEAK_HANDLER;
void svc_handler(void) WEAK_HANDLER;
void debugmon_handler(void) WEAK_HANDLER;
void pendsv_handler(void) WEAK_HANDLER;
void systick_handler(void) WEAK_HANDLER;

// STM32 peripheral IRQs (see nvic.h for IRQn numbers)
void wwdg_handler(void) WEAK_HANDLER;
void pvd_avd_handler(void) WEAK_HANDLER;
void rtc_tamp_stamp_handler(void) WEAK_HANDLER;
void rtc_wkup_handler(void) WEAK_HANDLER;
void flash_handler(void) WEAK_HANDLER;
void rcc_handler(void) WEAK_HANDLER;
void exti0_handler(void) WEAK_HANDLER;
void exti1_handler(void) WEAK_HANDLER;
void exti2_handler(void) WEAK_HANDLER;
void exti3_handler(void) WEAK_HANDLER;
void exti4_handler(void) WEAK_HANDLER;
void dma1_stream0_handler(void) WEAK_HANDLER;
void dma1_stream1_handler(void) WEAK_HANDLER;
void dma1_stream2_handler(void) WEAK_HANDLER;
void dma1_stream3_handler(void) WEAK_HANDLER;
void dma1_stream4_handler(void) WEAK_HANDLER;
void dma1_stream5_handler(void) WEAK_HANDLER;
void dma1_stream6_handler(void) WEAK_HANDLER;
void adc_handler(void) WEAK_HANDLER;
void tim1_brk_handler(void) WEAK_HANDLER;
void tim1_up_handler(void) WEAK_HANDLER;
void tim1_trg_com_handler(void) WEAK_HANDLER;
void tim1_cc_handler(void) WEAK_HANDLER;
void tim2_handler(void) WEAK_HANDLER;
void tim3_handler(void) WEAK_HANDLER;
void tim4_handler(void) WEAK_HANDLER;
void i2c1_ev_handler(void) WEAK_HANDLER;
void i2c1_er_handler(void) WEAK_HANDLER;
void spi1_handler(void) WEAK_HANDLER;
void usart1_handler(void) WEAK_HANDLER;
void usart2_handler(void) WEAK_HANDLER;
void usart3_handler(void) WEAK_HANDLER;
void exti15_10_handler(void) WEAK_HANDLER;
void tim5_handler(void) WEAK_HANDLER;
void spi2_handler(void) WEAK_HANDLER;
void uart4_handler(void) WEAK_HANDLER;
void tim6_dac_handler(void) WEAK_HANDLER;
void tim7_handler(void) WEAK_HANDLER;
void dma2_stream0_handler(void) WEAK_HANDLER;
void i2c3_ev_handler(void) WEAK_HANDLER;
void i2c3_er_handler(void) WEAK_HANDLER;

__attribute__((section(".vectors"),
               used)) void (*const vector_table[])(void) = {
    (void (*)(void))&_estack,
    reset_handler,
    nmi_handler,
    hardfault_handler,
    memmanage_handler,
    busfault_handler,
    usagefault_handler,
    0,
    0,
    0,
    0,
    svc_handler,
    debugmon_handler,
    0,
    pendsv_handler,
    systick_handler,

    // IRQn 0..73 (offsets follow nvic.h)
    wwdg_handler,
    pvd_avd_handler,
    rtc_tamp_stamp_handler,
    rtc_wkup_handler,
    flash_handler,
    rcc_handler,
    exti0_handler,
    exti1_handler,
    exti2_handler,
    exti3_handler,
    exti4_handler,
    dma1_stream0_handler,
    dma1_stream1_handler,
    dma1_stream2_handler,
    dma1_stream3_handler,
    dma1_stream4_handler,
    dma1_stream5_handler,
    dma1_stream6_handler,
    adc_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    tim1_brk_handler,
    tim1_up_handler,
    tim1_trg_com_handler,
    tim1_cc_handler,
    default_handler,
    tim2_handler,
    tim3_handler,
    tim4_handler,
    i2c1_ev_handler,
    i2c1_er_handler,
    default_handler,
    default_handler,
    spi1_handler,
    default_handler,
    usart1_handler,
    usart2_handler,
    usart3_handler,
    exti15_10_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    tim5_handler,
    spi2_handler,
    uart4_handler,
    default_handler,
    tim6_dac_handler,
    tim7_handler,
    dma2_stream0_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    i2c3_ev_handler,
    i2c3_er_handler,
};
