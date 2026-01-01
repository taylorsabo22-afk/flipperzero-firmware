#include <furi_hal_power.h>
#include <furi.h>

void furi_hal_power_init(void) {
    // Android platform - stub initialization
}

void furi_hal_power_reset(void) {
    // Exit the application
    exit(0);
}

void furi_hal_power_off(void) {
    // Exit the application
    exit(0);
}

void furi_hal_power_insomnia_enter(void) {
    // Prevent sleep - not applicable on Android emulator
}

void furi_hal_power_insomnia_exit(void) {
    // Allow sleep - not applicable on Android emulator
}

bool furi_hal_power_is_charging(void) {
    // Always return false on Android emulator
    return false;
}

uint8_t furi_hal_power_get_pct(void) {
    // Return 100% battery on Android emulator
    return 100;
}

bool furi_hal_power_is_battery_low(void) {
    // Never low on Android emulator
    return false;
}

uint16_t furi_hal_power_get_battery_voltage(FuriHalPowerIC ic) {
    // Return nominal voltage
    (void)ic;
    return 3300; // 3.3V
}

float furi_hal_power_get_battery_current(FuriHalPowerIC ic) {
    // Return zero current
    (void)ic;
    return 0.0f;
}

float furi_hal_power_get_battery_temperature(FuriHalPowerIC ic) {
    // Return room temperature
    (void)ic;
    return 25.0f;
}

void furi_hal_power_enable_otg(void) {
    // Stub: No OTG support
}

void furi_hal_power_disable_otg(void) {
    // Stub: No OTG support
}

bool furi_hal_power_is_otg_enabled(void) {
    // Stub: No OTG support
    return false;
}

void furi_hal_power_suppress_charge_enter(void) {
    // Stub
}

void furi_hal_power_suppress_charge_exit(void) {
    // Stub
}
