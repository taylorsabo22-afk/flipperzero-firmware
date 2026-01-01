#include <furi_hal_serial_control.h>

void furi_hal_serial_control_init(void) {
    // Android platform - no serial hardware to control
}

void furi_hal_serial_control_set_logging_config(FuriHalSerialId id, uint32_t baud_rate) {
    (void)id;
    (void)baud_rate;
}

void furi_hal_serial_control_suspend(void) {
    // Stub
}

void furi_hal_serial_control_resume(void) {
    // Stub
}

FuriHalSerialId furi_hal_serial_control_get_logging_serial_id(void) {
    return 0;
}

void furi_hal_serial_control_acquire_handler(void* context) {
    (void)context;
}

void furi_hal_serial_control_release_handler(void* context) {
    (void)context;
}
