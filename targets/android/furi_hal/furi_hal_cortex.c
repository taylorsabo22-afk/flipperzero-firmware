#include <furi_hal_cortex.h>
#include <furi.h>

void furi_hal_cortex_init_early(void) {
    // Android platform - no cortex specific initialization needed
}

void furi_hal_cortex_delay_us(uint32_t microseconds) {
    // Simple delay using system calls
    struct timespec ts;
    ts.tv_sec = microseconds / 1000000;
    ts.tv_nsec = (microseconds % 1000000) * 1000;
    nanosleep(&ts, NULL);
}

FuriHalCortexTimer furi_hal_cortex_timer_get(uint32_t timeout_us) {
    FuriHalCortexTimer timer = {0};
    timer.start = furi_get_tick();
    timer.value = timeout_us;
    return timer;
}

bool furi_hal_cortex_timer_is_expired(FuriHalCortexTimer timer) {
    uint32_t elapsed = furi_get_tick() - timer.start;
    return (elapsed * 1000) >= timer.value;
}

void furi_hal_cortex_timer_wait(FuriHalCortexTimer timer) {
    while(!furi_hal_cortex_timer_is_expired(timer)) {
        furi_delay_tick(1);
    }
}
