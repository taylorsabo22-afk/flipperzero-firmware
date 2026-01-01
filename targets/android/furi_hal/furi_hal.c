#include <furi_hal.h>
#include <furi_hal_memory.h>

#define TAG "FuriHalAndroid"

void furi_hal_init_early(void) {
    // Android platform initialization
    furi_hal_cortex_init_early();
    furi_hal_os_init();
    furi_hal_light_init();
    furi_hal_rtc_init_early();
    furi_hal_version_init();
}

void furi_hal_deinit_early(void) {
    // Android platform de-initialization
    furi_hal_rtc_deinit_early();
}

void furi_hal_init(void) {
    // Full Android HAL initialization
    furi_hal_random_init();
    furi_hal_rtc_init();
    furi_hal_interrupt_init();
    furi_hal_region_init();
    furi_hal_speaker_init();
    furi_hal_crypto_init();
    furi_hal_power_init();
    furi_hal_light_init();
    furi_hal_memory_init();
}

void furi_hal_switch(void* address) {
    // Not supported on Android
    (void)address;
}
