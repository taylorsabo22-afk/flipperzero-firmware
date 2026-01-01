#include <furi_hal_adc.h>

void furi_hal_adc_init(void) {
    // Android platform - no ADC hardware
}

void furi_hal_adc_configure(void) {
    // Stub
}

float furi_hal_adc_read(FuriHalAdcChannel channel, uint32_t samples) {
    (void)channel;
    (void)samples;
    return 0.0f;
}

uint16_t furi_hal_adc_read_raw(FuriHalAdcChannel channel, uint32_t samples) {
    (void)channel;
    (void)samples;
    return 0;
}

float furi_hal_adc_convert_to_voltage(uint16_t value) {
    (void)value;
    return 0.0f;
}
