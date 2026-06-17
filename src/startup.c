#include <stdint.h>

extern uint32_t _estack; // end of stack -> initial SP
extern void reset_handler(void);

__attribute__((section(".vectors"),
               used)) void (*const vector_table[])(void) = {
    (void (*)(void))&_estack,
    reset_handler,
};
