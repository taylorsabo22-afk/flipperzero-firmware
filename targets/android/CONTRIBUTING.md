# Contributing to Android Emulator

Thank you for your interest in contributing to the Flipper Zero Android emulator!

## Quick Links

- [Development Roadmap](ROADMAP.md) - See what needs to be done
- [Building Guide](BUILDING.md) - How to build the project
- [Main Contribution Guide](../../CONTRIBUTING.md) - General contribution guidelines

## How to Contribute

### 1. Find Something to Work On

Check the [ROADMAP.md](ROADMAP.md) for:
- Priority tasks
- Feature ideas
- Known limitations

Or create your own improvement!

### 2. Discuss First (Optional but Recommended)

For large changes:
- Open a GitHub issue
- Describe what you want to implement
- Get feedback before coding

### 3. Set Up Development Environment

See [BUILDING.md](BUILDING.md) for setup instructions.

### 4. Make Your Changes

Follow these guidelines:

#### Code Style

Follow the main [Flipper coding style](../../CODING_STYLE.md):
- Use snake_case for functions and variables
- Use descriptive names
- Add comments for complex logic
- Keep functions focused and small

#### Android-Specific Guidelines

**Java/Kotlin Code:**
```java
// Use meaningful variable names
private SurfaceView displayView;

// Follow Android conventions
@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    // ...
}
```

**Native Code (C/C++):**
```c
// Follow Flipper style
void furi_hal_display_update(const uint8_t* framebuffer) {
    furi_check(framebuffer);
    // Implementation
}
```

**JNI Bridge:**
```c
// Clear naming for JNI functions
JNIEXPORT void JNICALL
Java_com_flipperdevices_emulator_MainActivity_nativeUpdateDisplay(
    JNIEnv* env, 
    jobject thiz,
    jbyteArray framebuffer) {
    // Implementation
}
```

#### HAL Implementation Guidelines

1. **Match Hardware Interface**
   - Implement the same function signatures as hardware targets
   - Return appropriate values even if feature isn't supported

2. **Use Stubs Appropriately**
   - For unimplemented features, return safe defaults
   - Log when stub functions are called (for debugging)

3. **Document Limitations**
   - Add comments explaining what works and what doesn't
   - Update README.md limitations section

**Example:**
```c
void furi_hal_nfc_init(void) {
    // Android platform - NFC requires Android NFC API integration
    // TODO: Implement using Android NFC API
    FURI_LOG_W(TAG, "NFC initialization skipped (not implemented)");
}
```

### 5. Test Your Changes

#### Build and Run
```bash
./gradlew assembleDebug
adb install app/build/outputs/apk/debug/app-debug.apk
```

#### Test On:
- Physical Android device (preferred)
- Android emulator
- Multiple Android versions if possible

#### Check Logs
```bash
adb logcat | grep -E "FlipperNative|AndroidRuntime"
```

### 6. Submit Pull Request

#### Before Submitting

- [ ] Code builds without errors or warnings
- [ ] Tested on at least one Android device
- [ ] Updated documentation if needed
- [ ] Followed coding style
- [ ] Added appropriate comments

#### PR Description Template

```markdown
## Summary
Brief description of what this PR does.

## Changes
- List of specific changes
- What files were modified
- What features were added/fixed

## Implementation Details
Explain how you implemented the feature:
- Which Android APIs used
- How it integrates with Flipper HAL
- Any limitations or known issues

## Testing
How was this tested:
- Device/emulator used
- Android version(s)
- What was tested
- Any issues encountered

## Screenshots/Videos
If UI changes, include screenshots or screen recordings.

## Checklist
- [ ] Code builds successfully
- [ ] Tested on device
- [ ] Documentation updated
- [ ] Follows coding style
- [ ] No new warnings
```

## Types of Contributions

### 🎨 Display and UI
- Implement display rendering
- Improve UI layout
- Add controls and buttons

### ⌨️ Input Handling
- Map touch events to buttons
- Add keyboard support
- Implement gesture controls

### 💾 Storage
- Implement SD card emulation
- Add file management
- Optimize I/O performance

### 🔧 HAL Implementation
- Implement missing HAL functions
- Integrate Android APIs
- Add hardware emulation

### 📱 Android Integration
- Use Android features (NFC, BT, sensors)
- Improve app lifecycle
- Add Android-specific features

### 📚 Documentation
- Improve guides
- Add tutorials
- Fix typos and errors

### 🐛 Bug Fixes
- Fix crashes
- Fix memory leaks
- Improve stability

## Development Workflow

### Branch Naming

- `feature/android-display` - New features
- `fix/android-crash` - Bug fixes
- `docs/android-readme` - Documentation
- `refactor/android-hal` - Code improvements

### Commit Messages

Follow [Conventional Commits](https://www.conventionalcommits.org/):

```
feat(android): add display rendering support
fix(android): fix memory leak in JNI bridge
docs(android): update build instructions
refactor(android): simplify HAL initialization
```

### Code Review

Expect feedback on:
- Code quality and style
- Android best practices
- Integration with Flipper HAL
- Performance implications
- Documentation completeness

## Getting Help

### Where to Ask

- **GitHub Discussions** - General questions
- **Discord** - Real-time chat
- **GitHub Issues** - Bug reports and feature requests

### Before Asking

1. Check existing documentation
2. Search closed issues
3. Try debugging yourself
4. Provide details when asking:
   - What you're trying to do
   - What you've tried
   - Error messages/logs
   - Android version
   - Device model

## Recognition

Contributors will be:
- Listed in commit messages (Co-authored-by)
- Mentioned in release notes
- Part of the Flipper community!

## License

By contributing, you agree that your contributions will be licensed under the same license as the Flipper Zero firmware.

## Code of Conduct

Follow the [Flipper Code of Conduct](../../CODE_OF_CONDUCT.md):
- Be respectful and inclusive
- Provide constructive feedback
- Focus on what's best for the community

## Questions?

- Open a GitHub Discussion
- Ask in Discord #development channel
- Comment on related issues

Thank you for contributing! 🚀
