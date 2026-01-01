#include <furi_hal_flash.h>

void furi_hal_flash_init(void) {
    // Android platform - uses standard file system
}

size_t furi_hal_flash_get_base(void) {
    return 0;
}

size_t furi_hal_flash_get_read_block_size(void) {
    return 1;
}

size_t furi_hal_flash_get_write_block_size(void) {
    return 1;
}

size_t furi_hal_flash_get_page_size(void) {
    return 4096;
}

size_t furi_hal_flash_get_cycles_count(void) {
    return 0;
}

const void* furi_hal_flash_get_free_start_address(void) {
    return NULL;
}

const void* furi_hal_flash_get_free_end_address(void) {
    return NULL;
}

size_t furi_hal_flash_get_free_page_start_address(void) {
    return 0;
}

size_t furi_hal_flash_get_free_page_count(void) {
    return 0;
}

bool furi_hal_flash_erase(uint8_t page) {
    (void)page;
    return false;
}

bool furi_hal_flash_write_dword(size_t address, uint64_t data) {
    (void)address;
    (void)data;
    return false;
}

bool furi_hal_flash_write_dword_from(size_t address, size_t source_address) {
    (void)address;
    (void)source_address;
    return false;
}

void furi_hal_flash_write_ob_dword(size_t address, uint64_t data) {
    (void)address;
    (void)data;
}
