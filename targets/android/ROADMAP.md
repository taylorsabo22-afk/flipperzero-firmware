# Android Emulator Development Roadmap

This document outlines the next steps for completing the Flipper Zero Android emulator.

## Current Status

✅ **Completed:**
- HAL stub implementations for all components
- Android app skeleton with native bridge
- Build system (CMake, Gradle, NDK)
- Comprehensive documentation

⚠️ **Partial:**
- Basic display structure (no actual rendering)
- JNI bridge (lifecycle only)

❌ **Not Implemented:**
- Display framebuffer integration
- Input event handling
- Storage emulation
- Hardware peripheral emulation

## Priority Roadmap

### Phase 1: Display Integration (High Priority)

**Goal:** Render Flipper display on Android screen

#### Tasks:
1. **Connect u8g2 to Android Canvas**
   - Implement u8g2 display driver for Android
   - Create framebuffer in native code
   - Copy framebuffer to Java/Kotlin for rendering
   
2. **Implement Display HAL**
   ```c
   // In furi_hal/furi_hal_display.c
   void furi_hal_display_init(void);
   void furi_hal_display_update(const uint8_t* framebuffer);
   ```

3. **Add JNI methods**
   ```java
   private native byte[] nativeGetFramebuffer();
   ```

4. **Render in MainActivity**
   - Convert framebuffer to Bitmap
   - Scale to screen size
   - Draw on Canvas

**Files to modify:**
- `targets/android/furi_hal/furi_hal_display.c` (create)
- `targets/android/app/src/main/cpp/native-lib.cpp`
- `targets/android/app/src/main/java/.../MainActivity.java`

### Phase 2: Input Handling (High Priority)

**Goal:** Map Android inputs to Flipper buttons

#### Tasks:
1. **Define Input Events**
   - Map touch zones to buttons
   - Map Android keys to Flipper buttons
   
2. **Implement Input HAL**
   ```c
   // In furi_hal/furi_hal_input.c
   void furi_hal_input_init(void);
   bool furi_hal_input_get(InputKey key);
   ```

3. **Add Touch Handling**
   ```java
   @Override
   public boolean onTouchEvent(MotionEvent event) {
       // Convert touch to button press
       nativeHandleInput(button, pressed);
   }
   ```

**Files to create/modify:**
- `targets/android/furi_hal/furi_hal_input.c`
- `targets/android/app/src/main/java/.../MainActivity.java`

### Phase 3: Storage Emulation (Medium Priority)

**Goal:** Emulate SD card storage

#### Tasks:
1. **Implement Storage HAL**
   ```c
   // In furi_hal/furi_hal_sd.c
   bool furi_hal_sd_is_present(void);
   bool furi_hal_sd_read_blocks(uint8_t* buff, uint32_t sector, uint32_t count);
   bool furi_hal_sd_write_blocks(const uint8_t* buff, uint32_t sector, uint32_t count);
   ```

2. **Use Android Internal Storage**
   - Create virtual SD card file
   - Map FAT filesystem operations
   - Use Android app data directory

**Files to create/modify:**
- `targets/android/furi_hal/furi_hal_sd.c`
- Add storage permissions to AndroidManifest.xml

### Phase 4: FreeRTOS Integration (High Priority)

**Goal:** Run FreeRTOS on Android/Linux

#### Tasks:
1. **Port FreeRTOS**
   - Use Linux/POSIX port of FreeRTOS
   - Or use pthread-based implementation
   
2. **Integrate with Flipper**
   - Ensure all Furi primitives work
   - Test threading and synchronization

**Files to create/modify:**
- `lib/FreeRTOS-glue/` (Android-specific glue)
- `targets/android/furi_hal/furi_hal_os.c`

### Phase 5: Firmware Loading (Medium Priority)

**Goal:** Load and run Flipper firmware

#### Tasks:
1. **Initialize Furi**
   - Start FreeRTOS scheduler
   - Initialize Furi core
   
2. **Load Applications**
   - Bundle firmware apps
   - Load from assets or storage

**Files to modify:**
- `targets/android/app/src/main/cpp/native-lib.cpp`
- Add firmware initialization sequence

### Phase 6: Hardware Emulation (Low Priority)

**Goal:** Emulate specific hardware features

#### Optional Features:
1. **NFC (using Android NFC API)**
   - Read NFC tags
   - Emulate cards
   
2. **Bluetooth (using Android BT API)**
   - Scan and connect
   - Serial over BT

3. **Vibration**
   - Use Android Vibrator API

4. **Audio/Speaker**
   - Use Android AudioTrack API
   - Play tones and melodies

## Implementation Guide

### Getting Started

1. **Pick a Phase**
   - Start with Phase 1 (Display) for quick visual feedback
   - Or Phase 4 (FreeRTOS) for core functionality

2. **Set Up Development**
   ```bash
   cd targets/android
   # Open in Android Studio
   ```

3. **Create Feature Branch**
   ```bash
   git checkout -b feature/android-display
   ```

### Development Tips

1. **Test Incrementally**
   - Build and test after each small change
   - Use logcat for debugging: `adb logcat | grep FlipperNative`

2. **Reference Existing Targets**
   - Look at `targets/f7/` for hardware implementation
   - Adapt HAL calls to Android APIs

3. **Use Android Tools**
   - Android Profiler for performance
   - Layout Inspector for UI debugging
   - Native debugger (LLDB) for C/C++ code

### Code Structure

```
targets/android/
├── furi_hal/              # HAL implementations
│   ├── furi_hal_display.c    # → Add display driver
│   ├── furi_hal_input.c      # → Add input handling
│   └── furi_hal_sd.c         # → Add storage
├── app/src/main/
│   ├── cpp/               # Native code
│   │   └── native-lib.cpp    # → Extend JNI bridge
│   └── java/              # Android app code
│       └── MainActivity.java  # → Add UI features
```

## Testing Strategy

### Unit Tests
- Test HAL functions independently
- Mock Android APIs where needed

### Integration Tests
- Test display rendering
- Test input events
- Test storage operations

### Manual Testing
- Run on physical device
- Test on Android emulator
- Test different Android versions

## Performance Considerations

1. **Display Updates**
   - Limit to 60 FPS max
   - Use hardware acceleration
   - Consider VSync

2. **Threading**
   - Keep UI thread responsive
   - Run firmware in separate thread
   - Use proper synchronization

3. **Memory**
   - Monitor memory usage
   - Profile allocations
   - Avoid memory leaks

## Documentation

When implementing features:

1. **Update README.md**
   - Mark features as implemented
   - Update limitations section

2. **Add Code Comments**
   - Explain Android-specific code
   - Document API mappings

3. **Update BUILDING.md**
   - Add new build requirements
   - Update troubleshooting

## Contributing

### Before Submitting PR

1. ✅ Code builds without errors
2. ✅ Code follows Flipper coding style
3. ✅ Changes are tested on device
4. ✅ Documentation is updated
5. ✅ No new warnings introduced

### PR Template

```markdown
## Description
Brief description of changes

## Implementation
- What was implemented
- How it works
- Any Android-specific considerations

## Testing
- How was this tested
- Which devices/Android versions

## Screenshots
If UI changes, include screenshots
```

## Resources

### Android Development
- [Android NDK Guide](https://developer.android.com/ndk/guides)
- [JNI Tips](https://developer.android.com/training/articles/perf-jni)
- [Canvas Drawing](https://developer.android.com/guide/topics/graphics/2d-graphics)

### Flipper Development
- [Flipper HAL Documentation](https://developer.flipper.net/flipperzero/doxygen/furi_hal.html)
- [Application Development](https://developer.flipper.net/flipperzero/doxygen/apps.html)

### FreeRTOS
- [FreeRTOS Linux Port](https://www.freertos.org/FreeRTOS-simulator-for-Linux.html)
- [POSIX Port Guide](https://www.freertos.org/FreeRTOS-simulator-for-Linux.html)

## Questions?

- Open a GitHub Discussion
- Join Flipper Discord
- Comment on related issues

## License

All contributions must be compatible with the main Flipper Zero firmware license.
