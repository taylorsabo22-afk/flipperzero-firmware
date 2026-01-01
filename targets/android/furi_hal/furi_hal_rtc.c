#include <furi_hal_rtc.h>
#include <furi.h>
#include <time.h>

void furi_hal_rtc_init_early(void) {
    // Android platform - system time is available
}

void furi_hal_rtc_deinit_early(void) {
    // Nothing to deinit
}

void furi_hal_rtc_init(void) {
    // Android platform - system time is available
}

void furi_hal_rtc_reset(void) {
    // Cannot reset system time
}

void furi_hal_rtc_get_datetime(DateTime* datetime) {
    furi_check(datetime);
    
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    
    datetime->year = tm_info->tm_year + 1900;
    datetime->month = tm_info->tm_mon + 1;
    datetime->day = tm_info->tm_mday;
    datetime->hour = tm_info->tm_hour;
    datetime->minute = tm_info->tm_min;
    datetime->second = tm_info->tm_sec;
    datetime->weekday = tm_info->tm_wday;
}

void furi_hal_rtc_set_datetime(DateTime* datetime) {
    // Cannot set system time from app
    (void)datetime;
}

bool furi_hal_rtc_is_flag_set(FuriHalRtcFlag flag) {
    // No persistent flags on Android emulator
    (void)flag;
    return false;
}

void furi_hal_rtc_set_flag(FuriHalRtcFlag flag) {
    // No persistent flags on Android emulator
    (void)flag;
}

void furi_hal_rtc_clear_flag(FuriHalRtcFlag flag) {
    // No persistent flags on Android emulator
    (void)flag;
}

void furi_hal_rtc_set_boot_mode(FuriHalRtcBootMode mode) {
    // No boot modes on Android emulator
    (void)mode;
}

FuriHalRtcBootMode furi_hal_rtc_get_boot_mode(void) {
    // Always normal boot
    return FuriHalRtcBootModeNormal;
}

void furi_hal_rtc_set_heap_track_mode(FuriHalRtcHeapTrackMode mode) {
    (void)mode;
}

FuriHalRtcHeapTrackMode furi_hal_rtc_get_heap_track_mode(void) {
    return FuriHalRtcHeapTrackModeNone;
}

void furi_hal_rtc_set_locale_units(FuriHalRtcLocaleUnits value) {
    (void)value;
}

FuriHalRtcLocaleUnits furi_hal_rtc_get_locale_units(void) {
    return FuriHalRtcLocaleUnitsMetric;
}

void furi_hal_rtc_set_locale_timeformat(FuriHalRtcLocaleTimeFormat value) {
    (void)value;
}

FuriHalRtcLocaleTimeFormat furi_hal_rtc_get_locale_timeformat(void) {
    return FuriHalRtcLocaleTimeFormat24h;
}

void furi_hal_rtc_set_locale_dateformat(FuriHalRtcLocaleDateFormat value) {
    (void)value;
}

FuriHalRtcLocaleDateFormat furi_hal_rtc_get_locale_dateformat(void) {
    return FuriHalRtcLocaleDateFormatDMY;
}

void furi_hal_rtc_set_log_level(uint8_t level) {
    (void)level;
}

uint8_t furi_hal_rtc_get_log_level(void) {
    return 0;
}

void furi_hal_rtc_set_fault_data(uint32_t value) {
    (void)value;
}

uint32_t furi_hal_rtc_get_fault_data(void) {
    return 0;
}

void furi_hal_rtc_set_pin_fails(uint32_t value) {
    (void)value;
}

uint32_t furi_hal_rtc_get_pin_fails(void) {
    return 0;
}

uint32_t furi_hal_rtc_get_timestamp(void) {
    return (uint32_t)time(NULL);
}
