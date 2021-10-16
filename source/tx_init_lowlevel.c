#include "fsl_common.h"

#include "tx_api.h"

// Defined in linker script.
extern void *__HeapLimit;
#define UNUSED_MEM_PTR  (&__HeapLimit)

// ThreadX global variables and functions.
extern VOID *_tx_initialize_unused_memory;
void _tx_timer_interrupt(void);

// Set stack end, configure SysTick interrupt, set NVIC levels
VOID _tx_initialize_low_level(VOID) {
    DisableGlobalIRQ();

    _tx_initialize_unused_memory = (VOID *)UNUSED_MEM_PTR;

    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    SysTick_Config(SystemCoreClock / TX_TIMER_TICKS_PER_SECOND);

    NVIC_SetPriority(MemoryManagement_IRQn, 0);
    NVIC_SetPriority(BusFault_IRQn,         0);
    NVIC_SetPriority(UsageFault_IRQn,       0);

    NVIC_SetPriority(SVCall_IRQn,         255);
    NVIC_SetPriority(DebugMonitor_IRQn,     0);
    NVIC_SetPriority(PendSV_IRQn,         255);
    NVIC_SetPriority(SysTick_IRQn,         64);

}

void SysTick_Handler(void) {
    _tx_timer_interrupt();
}