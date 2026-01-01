# Quick Start Guide - Flipper Zero Android Emulator

This is a quick guide to get the Android emulator running in 5 minutes.

## Prerequisites

- Android Studio installed
- Android device or emulator

## Steps

### 1. Clone Repository

```bash
git clone --recursive https://github.com/flipperdevices/flipperzero-firmware.git
cd flipperzero-firmware/targets/android
```

### 2. Configure SDK

Copy and edit the SDK configuration:
```bash
cp local.properties.template local.properties
# Edit local.properties and set your Android SDK path
```

### 3. Open in Android Studio

1. Launch Android Studio
2. Select "Open an Existing Project"
3. Navigate to `flipperzero-firmware/targets/android`
4. Click "OK"
5. Wait for Gradle sync to complete

### 4. Run

1. Connect your Android device via USB (or start an emulator)
2. Click the green "Run" button (▶️) or press `Shift+F10`
3. Select your device
4. Wait for installation and launch

## What You'll See

- A black screen with "Flipper Zero Emulator" text
- This is the basic skeleton - the display integration is not yet complete

## Next Steps

See [BUILDING.md](BUILDING.md) for:
- Detailed build instructions
- Troubleshooting
- Development workflow

See [README.md](README.md) for:
- Architecture overview
- Current limitations
- How to contribute

## Troubleshooting

**Build fails?**
- Check that `local.properties` has the correct SDK path
- Install NDK and CMake via SDK Manager

**Can't find device?**
- Enable USB debugging on your Android device
- Check `adb devices` to verify connection

**App crashes on launch?**
- Check logcat: `adb logcat | grep FlipperNative`
- Report the issue with logs

## Support

For help:
- Read [BUILDING.md](BUILDING.md) troubleshooting section
- Check GitHub issues
- Open a new issue with details
