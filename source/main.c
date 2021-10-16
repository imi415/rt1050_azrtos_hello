#include <stdint.h>

#include "fsl_gpio.h"

#include "board.h"
#include "pin_mux.h"
#include "peripherals.h"

#include "tx_api.h"

TX_THREAD hello_thread;

void hello_thread_entry(ULONG thread_input) {
    for(;;) {
        tx_thread_sleep(1000);
        GPIO_WritePinOutput(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_GPIO_PIN, 1U);
        tx_thread_sleep(1000);
        GPIO_WritePinOutput(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_GPIO_PIN, 0U);
    }
}

void tx_application_define(void *first_unused_memory) {
    tx_thread_create(&hello_thread, "Hello Thread", hello_thread_entry,
                     0x00, first_unused_memory, 1024, 3, 3,
                     TX_NO_TIME_SLICE, TX_AUTO_START);
    //
}

int main(void) {
    BOARD_BootClockRUN();
    BOARD_InitBootPins();
    BOARD_InitBootPeripherals();

    BOARD_ConfigMPU();

    tx_kernel_enter();

    for(;;)  {
        //
    }

    return 0;
}