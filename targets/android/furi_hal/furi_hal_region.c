#include <furi_hal_region.h>

void furi_hal_region_init(void) {
    // Android platform - no region restrictions
}

void furi_hal_region_set(FuriHalRegion region) {
    (void)region;
}

FuriHalRegion furi_hal_region_get(void) {
    return FuriHalRegionWorldwide;
}

bool furi_hal_region_is_frequency_allowed(uint32_t frequency) {
    // All frequencies allowed in emulator
    (void)frequency;
    return true;
}

bool furi_hal_region_is_provisioned(void) {
    return true;
}

const char* furi_hal_region_get_name(void) {
    return "WW";
}
