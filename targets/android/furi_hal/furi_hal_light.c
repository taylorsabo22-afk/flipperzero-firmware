#include <furi_hal_light.h>

void furi_hal_light_init(void) {
    // Android platform - no hardware light to initialize
}

void furi_hal_light_set(Light light, uint8_t value) {
    // Stub: No hardware LED support on Android emulator
    (void)light;
    (void)value;
}

void furi_hal_light_blink_start(Light light, uint8_t brightness, uint16_t on_time, uint16_t period) {
    // Stub: No hardware LED support on Android emulator
    (void)light;
    (void)brightness;
    (void)on_time;
    (void)period;
}

void furi_hal_light_blink_stop(void) {
    // Stub: No hardware LED support on Android emulator
}

void furi_hal_light_blink_set_color(Light light) {
    // Stub: No hardware LED support on Android emulator
    (void)light;
}

void furi_hal_light_sequence(const char* sequence) {
    // Stub: No hardware LED support on Android emulator
    (void)sequence;
}
