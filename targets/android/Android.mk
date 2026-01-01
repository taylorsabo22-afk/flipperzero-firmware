LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := flipper_native

# Include paths
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/targets/android/furi_hal \
    $(LOCAL_PATH)/targets/android/inc \
    $(LOCAL_PATH)/targets/furi_hal_include \
    $(LOCAL_PATH)/furi \
    $(LOCAL_PATH)/lib/FreeRTOS-Kernel/include \
    $(LOCAL_PATH)/lib

# Source files - HAL layer
LOCAL_SRC_FILES := \
    targets/android/furi_hal/furi_hal.c \
    targets/android/furi_hal/furi_hal_bt.c \
    targets/android/furi_hal/furi_hal_bus.c \
    targets/android/furi_hal/furi_hal_clock.c \
    targets/android/furi_hal/furi_hal_cortex.c \
    targets/android/furi_hal/furi_hal_crypto.c \
    targets/android/furi_hal/furi_hal_dma.c \
    targets/android/furi_hal/furi_hal_flash.c \
    targets/android/furi_hal/furi_hal_i2c_config.c \
    targets/android/furi_hal/furi_hal_ibutton.c \
    targets/android/furi_hal/furi_hal_interrupt.c \
    targets/android/furi_hal/furi_hal_light.c \
    targets/android/furi_hal/furi_hal_memory.c \
    targets/android/furi_hal/furi_hal_os.c \
    targets/android/furi_hal/furi_hal_power.c \
    targets/android/furi_hal/furi_hal_random.c \
    targets/android/furi_hal/furi_hal_region.c \
    targets/android/furi_hal/furi_hal_resources.c \
    targets/android/furi_hal/furi_hal_rtc.c \
    targets/android/furi_hal/furi_hal_serial_control.c \
    targets/android/furi_hal/furi_hal_speaker.c \
    targets/android/furi_hal/furi_hal_spi_config.c \
    targets/android/furi_hal/furi_hal_version.c

# Libraries to link
LOCAL_LDLIBS := -llog -landroid

include $(BUILD_SHARED_LIBRARY)
