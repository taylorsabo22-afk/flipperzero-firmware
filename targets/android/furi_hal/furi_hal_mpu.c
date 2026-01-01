#include <furi_hal_mpu.h>

void furi_hal_mpu_init(void) {
    // Android platform - no MPU configuration needed
}

void furi_hal_mpu_enable(void) {
    // Stub
}

void furi_hal_mpu_disable(void) {
    // Stub
}

void furi_hal_mpu_set_region_ro_nocache(void* start, size_t size) {
    (void)start;
    (void)size;
}

void furi_hal_mpu_set_region_ro_cache(void* start, size_t size) {
    (void)start;
    (void)size;
}

void furi_hal_mpu_set_region_rw_nocache(void* start, size_t size) {
    (void)start;
    (void)size;
}

void furi_hal_mpu_set_region_rw_cache(void* start, size_t size) {
    (void)start;
    (void)size;
}
