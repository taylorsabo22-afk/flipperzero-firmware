# Building Flipper Zero Android Emulator

This guide explains how to build the Flipper Zero Android emulator from source.

## Prerequisites

### Required Software

1. **Android Studio** (Arctic Fox 2020.3.1 or newer)
   - Download from: https://developer.android.com/studio

2. **Android NDK** (r23 or newer)
   - Install via Android Studio SDK Manager
   - Or download from: https://developer.android.com/ndk/downloads

3. **CMake** (3.10 or newer)
   - Install via Android Studio SDK Manager

4. **Java Development Kit (JDK)** 8 or newer
   - OpenJDK or Oracle JDK

### Recommended

- **Android device** or **Emulator** running Android 7.0 (API 24) or higher
- **ADB (Android Debug Bridge)** for installing and debugging

## Setup

### 1. Clone the Repository

```bash
git clone --recursive https://github.com/flipperdevices/flipperzero-firmware.git
cd flipperzero-firmware
```

### 2. Configure Android SDK Path

Navigate to the Android target directory:

```bash
cd targets/android
```

Copy the template file:

```bash
cp local.properties.template local.properties
```

Edit `local.properties` and set your Android SDK path:

```properties
# Example for macOS
sdk.dir=/Users/YOUR_USERNAME/Library/Android/sdk

# Example for Windows
sdk.dir=C\:\\Users\\YOUR_USERNAME\\AppData\\Local\\Android\\Sdk

# Example for Linux
sdk.dir=/home/YOUR_USERNAME/Android/Sdk
```

## Building

### Option 1: Using Android Studio (Recommended)

1. **Open the Project**
   - Launch Android Studio
   - Select "Open an Existing Project"
   - Navigate to `flipperzero-firmware/targets/android`
   - Click "OK"

2. **Sync Project**
   - Android Studio will automatically sync Gradle
   - Wait for the sync to complete
   - If prompted, install any missing SDK components

3. **Build the Project**
   - Click "Build" → "Make Project" (or press Ctrl+F9 / Cmd+F9)
   - Wait for the build to complete

4. **Run on Device/Emulator**
   - Connect your Android device via USB (or start an emulator)
   - Click "Run" → "Run 'app'" (or press Shift+F10)
   - Select your target device
   - The app will install and launch automatically

### Option 2: Using Command Line

#### Build Debug APK

```bash
cd targets/android
./gradlew assembleDebug
```

The APK will be created at:
```
app/build/outputs/apk/debug/app-debug.apk
```

#### Build Release APK

```bash
./gradlew assembleRelease
```

The APK will be created at:
```
app/build/outputs/apk/release/app-release-unsigned.apk
```

**Note:** Release APKs need to be signed before installation.

#### Install APK to Device

```bash
adb install app/build/outputs/apk/debug/app-debug.apk
```

## Build Variants

The project supports multiple build variants:

- **debug**: Debug build with logging and debugging symbols
- **release**: Optimized release build

## Troubleshooting

### Common Issues

#### 1. Gradle Sync Failed

**Problem:** Gradle sync fails with SDK not found error

**Solution:**
- Ensure `local.properties` has the correct SDK path
- Open Android Studio SDK Manager and install missing components

#### 2. CMake Not Found

**Problem:** Build fails with "CMake not found" error

**Solution:**
- Open Android Studio
- Go to SDK Manager → SDK Tools
- Check "CMake" and "NDK"
- Click "Apply" to install

#### 3. NDK Version Mismatch

**Problem:** Build fails due to NDK version issues

**Solution:**
- Update `app/build.gradle` to specify your NDK version
- Or install the required NDK version via SDK Manager

#### 4. Out of Memory During Build

**Problem:** Gradle runs out of memory during build

**Solution:**
Create/edit `gradle.properties`:
```properties
org.gradle.jvmargs=-Xmx4096m -XX:MaxPermSize=512m
```

### Build Configuration

#### Changing Minimum SDK Version

Edit `app/build.gradle`:
```gradle
defaultConfig {
    minSdk 24  // Change this value
    ...
}
```

#### Changing Target ABIs

Edit `app/build.gradle`:
```gradle
ndk {
    abiFilters 'armeabi-v7a', 'arm64-v8a'  // Add/remove ABIs
}
```

Common ABIs:
- `armeabi-v7a`: 32-bit ARM (older devices)
- `arm64-v8a`: 64-bit ARM (modern devices)
- `x86`: 32-bit x86 (emulators)
- `x86_64`: 64-bit x86 (emulators)

## Development Workflow

### Making Changes

1. Make changes to Java code in `app/src/main/java/`
2. Make changes to native code in `targets/android/furi_hal/`
3. Build and run to test changes

### Debugging

#### Java/Kotlin Code
- Use Android Studio debugger
- Set breakpoints in Java files
- Run in Debug mode (Shift+F9)

#### Native Code (C/C++)
- Use Android Studio LLDB debugger
- Set breakpoints in C/C++ files
- Attach debugger to running app

### Viewing Logs

```bash
# View all logs
adb logcat

# Filter Flipper logs
adb logcat | grep FlipperNative

# Clear logs
adb logcat -c
```

## Clean Build

If you encounter build issues, try cleaning:

```bash
# Using Gradle
./gradlew clean

# Full clean (removes all build artifacts)
rm -rf .gradle build app/build
```

## Next Steps

After building successfully:
- Read [README.md](README.md) for architecture overview
- Check [Development Roadmap](#) for planned features
- Contribute improvements!

## Support

For build issues:
1. Check this guide's troubleshooting section
2. Search existing GitHub issues
3. Open a new issue with build logs
