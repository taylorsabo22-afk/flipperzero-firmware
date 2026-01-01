# Flipper Zero Android Emulator

This directory contains the Android emulator implementation for Flipper Zero firmware.

## Overview

The Android emulator allows you to run Flipper Zero firmware on Android devices. It provides:

- Hardware Abstraction Layer (HAL) for Android platform
- Android NDK build configuration
- Android app wrapper with display rendering
- JNI bridge between Java and native code

## Architecture

```
targets/android/
├── furi_hal/          # HAL implementation for Android
├── inc/               # Additional include files
├── app/               # Android application
│   └── src/main/
│       ├── java/      # Java/Kotlin code
│       ├── cpp/       # JNI bridge
│       └── res/       # Resources
├── CMakeLists.txt     # CMake build configuration
├── Android.mk         # NDK build configuration (legacy)
└── target.json        # Target configuration
```

## Requirements

- Android Studio Arctic Fox or newer
- Android NDK 23.0.0 or newer
- Android SDK API level 24 (Android 7.0) or higher
- CMake 3.10 or newer

## Building

### Using Android Studio

1. Open the `targets/android` directory in Android Studio
2. Sync project with Gradle files
3. Select your device or emulator
4. Click "Run" or press Shift+F10

### Using Command Line

```bash
cd targets/android
./gradlew assembleDebug
```

The APK will be generated at: `app/build/outputs/apk/debug/app-debug.apk`

### Installing

```bash
adb install app/build/outputs/apk/debug/app-debug.apk
```

## Current Status

**Note**: This is a minimal implementation providing:

✅ Basic HAL stub implementations  
✅ Android app skeleton with display  
✅ JNI bridge for native code  
✅ Build system configuration  

⚠️ **Not yet implemented**:
- Display rendering (u8g2 integration)
- Input handling (touch/buttons)
- Storage (SD card emulation)
- Hardware emulation (NFC, RFID, IR, etc.)
- Full FreeRTOS integration
- Firmware application loading

## HAL Implementation

The Android HAL provides stub implementations for:

- **furi_hal_cortex**: Basic timing and delays
- **furi_hal_power**: Battery stubs (always shows 100%)
- **furi_hal_rtc**: System time integration
- **furi_hal_light**: LED stubs (no hardware LEDs)
- **furi_hal_speaker**: Audio stubs (requires Android Audio API)
- **furi_hal_bt**: Bluetooth stubs (could use Android BT API)
- **furi_hal_version**: Device identification
- **Other peripherals**: GPIO, SPI, I2C, NFC, RFID (all stubs)

## Development

To extend the emulator:

1. **Display Integration**: Connect u8g2 framebuffer to Android Canvas
2. **Input Handling**: Map touch/button events to Flipper inputs
3. **Storage**: Implement SD card emulation using Android storage
4. **Hardware**: Add emulation for specific peripherals

## Limitations

- No real hardware access (NFC, RFID, IR, GPIO)
- Limited performance compared to real hardware
- Some features may not work without hardware emulation
- This is intended for UI testing and app development, not for production use

## License

Same as the main Flipper Zero firmware (see root LICENSE file)

## Contributing

When contributing to the Android emulator:

1. Follow the main firmware coding standards
2. Keep HAL implementations consistent with hardware targets
3. Add Android-specific documentation
4. Test on multiple Android versions and devices
