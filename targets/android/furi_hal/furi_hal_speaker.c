#include <furi_hal_speaker.h>

void furi_hal_speaker_init(void) {
    // Android platform - audio would need JNI bridge
}

void furi_hal_speaker_start(float frequency, float volume) {
    // Stub: Would need Android Audio API integration
    (void)frequency;
    (void)volume;
}

void furi_hal_speaker_stop(void) {
    // Stub
}

void furi_hal_speaker_set_volume(float volume) {
    (void)volume;
}

void furi_hal_speaker_acquire(uint32_t timeout) {
    (void)timeout;
}

void furi_hal_speaker_release(void) {
    // Stub
}

bool furi_hal_speaker_is_mine(void) {
    return true;
}

bool furi_hal_speaker_acquire_semaphore(void) {
    return true;
}

void furi_hal_speaker_release_semaphore(void) {
    // Stub
}
