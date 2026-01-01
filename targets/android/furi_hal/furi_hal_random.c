#include <furi_hal_random.h>
#include <stdlib.h>
#include <time.h>

void furi_hal_random_init(void) {
    // Seed random number generator
    srand(time(NULL));
}

uint32_t furi_hal_random_get(void) {
    return (uint32_t)rand();
}

void furi_hal_random_fill_buf(uint8_t* buf, uint32_t len) {
    for(uint32_t i = 0; i < len; i++) {
        buf[i] = (uint8_t)(rand() & 0xFF);
    }
}
