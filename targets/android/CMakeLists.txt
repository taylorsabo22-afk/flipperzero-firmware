cmake_minimum_required(VERSION 3.10)

project(FlipperZeroAndroid)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/targets/android/furi_hal
    ${CMAKE_SOURCE_DIR}/targets/android/inc
    ${CMAKE_SOURCE_DIR}/targets/furi_hal_include
    ${CMAKE_SOURCE_DIR}/furi/core
    ${CMAKE_SOURCE_DIR}/lib/FreeRTOS-Kernel/include
    ${CMAKE_SOURCE_DIR}/lib
)

# HAL source files
set(HAL_SOURCES
    targets/android/furi_hal/furi_hal.c
    targets/android/furi_hal/furi_hal_bt.c
    targets/android/furi_hal/furi_hal_bus.c
    targets/android/furi_hal/furi_hal_clock.c
    targets/android/furi_hal/furi_hal_cortex.c
    targets/android/furi_hal/furi_hal_crypto.c
    targets/android/furi_hal/furi_hal_dma.c
    targets/android/furi_hal/furi_hal_flash.c
    targets/android/furi_hal/furi_hal_i2c_config.c
    targets/android/furi_hal/furi_hal_ibutton.c
    targets/android/furi_hal/furi_hal_interrupt.c
    targets/android/furi_hal/furi_hal_light.c
    targets/android/furi_hal/furi_hal_memory.c
    targets/android/furi_hal/furi_hal_os.c
    targets/android/furi_hal/furi_hal_power.c
    targets/android/furi_hal/furi_hal_random.c
    targets/android/furi_hal/furi_hal_region.c
    targets/android/furi_hal/furi_hal_resources.c
    targets/android/furi_hal/furi_hal_rtc.c
    targets/android/furi_hal/furi_hal_serial_control.c
    targets/android/furi_hal/furi_hal_speaker.c
    targets/android/furi_hal/furi_hal_spi_config.c
    targets/android/furi_hal/furi_hal_version.c
)

# Create the native library
add_library(flipper_native SHARED ${HAL_SOURCES})

# Link libraries
target_link_libraries(flipper_native
    log
    android
)
