#include <jni.h>
#include <android/log.h>
#include <furi_hal.h>

#define TAG "FlipperNative"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

extern "C" {

JNIEXPORT void JNICALL
Java_com_flipperdevices_emulator_MainActivity_nativeInit(JNIEnv* env, jobject thiz) {
    LOGI("Initializing Flipper firmware...");
    
    // Initialize HAL early
    furi_hal_init_early();
    
    // Initialize full HAL
    furi_hal_init();
    
    LOGI("Flipper firmware initialized");
}

JNIEXPORT void JNICALL
Java_com_flipperdevices_emulator_MainActivity_nativeUpdate(JNIEnv* env, jobject thiz) {
    // Update emulator state - called every frame
    // This would run the main firmware loop
}

JNIEXPORT void JNICALL
Java_com_flipperdevices_emulator_MainActivity_nativeCleanup(JNIEnv* env, jobject thiz) {
    LOGI("Cleaning up Flipper firmware...");
    
    // Deinitialize HAL
    furi_hal_deinit_early();
    
    LOGI("Flipper firmware cleaned up");
}

} // extern "C"
