#include <furi_hal_version.h>
#include <furi.h>

void furi_hal_version_init(void) {
    // Nothing to initialize for Android emulator
}

bool furi_hal_version_do_i_belong_here(void) {
    return true;
}

const char* furi_hal_version_get_model_name(void) {
    return "Flipper Zero Android Emulator";
}

const char* furi_hal_version_get_model_code(void) {
    return "FZ-EMU-ANDROID";
}

const char* furi_hal_version_get_fcc_id(void) {
    return "N/A";
}

const char* furi_hal_version_get_ic_id(void) {
    return "N/A";
}

const FuriHalVersionOTP* furi_hal_version_get_otp(void) {
    static FuriHalVersionOTP otp = {0};
    return &otp;
}

const char* furi_hal_version_get_name_ptr(void) {
    return "Android Emulator";
}

const char* furi_hal_version_get_device_name_ptr(void) {
    return "Flipper Zero Emulator";
}

const char* furi_hal_version_get_ble_local_device_name_ptr(void) {
    return "Flipper Emu";
}

size_t furi_hal_version_get_hw_version(void) {
    return 0;
}

size_t furi_hal_version_get_hw_target(void) {
    return 99; // Custom target ID for Android
}

size_t furi_hal_version_get_hw_body(void) {
    return 0;
}

size_t furi_hal_version_get_hw_connect(void) {
    return 0;
}

size_t furi_hal_version_get_hw_display(void) {
    return 0;
}

uint32_t furi_hal_version_get_hw_timestamp(void) {
    return 0;
}

const char* furi_hal_version_get_hw_region_name(void) {
    return "WW";
}

FuriHalVersionRegion furi_hal_version_get_hw_region(void) {
    return FuriHalVersionRegionUnknown;
}

const char* furi_hal_version_get_hw_region_name_otp(void) {
    return "WW";
}

const uint8_t* furi_hal_version_uid(void) {
    static uint8_t uid[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
                               0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    return uid;
}

size_t furi_hal_version_uid_size(void) {
    return 16;
}
