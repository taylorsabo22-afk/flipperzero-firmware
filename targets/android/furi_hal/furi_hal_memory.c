#include <furi_hal_memory.h>

void furi_hal_memory_init(void) {
    // Android platform - standard memory management
}

size_t furi_hal_memory_get_free(void) {
    // Return a large value for Android
    return 1024 * 1024 * 100; // 100MB
}

size_t furi_hal_memory_max_pool_block(void) {
    return 1024 * 1024; // 1MB
}

void* furi_hal_memory_alloc(size_t size) {
    return malloc(size);
}

void furi_hal_memory_free(void* ptr) {
    free(ptr);
}
