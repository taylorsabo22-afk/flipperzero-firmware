#include <furi_hal_bt.h>

void furi_hal_bt_init(void) {
    // Android platform - could use Android Bluetooth API via JNI
}

void furi_hal_bt_lock_core2(void) {
    // Stub
}

void furi_hal_bt_unlock_core2(void) {
    // Stub
}

bool furi_hal_bt_start_radio_stack(void) {
    return false;
}

FuriHalBtStack furi_hal_bt_get_radio_stack(void) {
    return FuriHalBtStackUnknown;
}

bool furi_hal_bt_is_alive(void) {
    return false;
}

bool furi_hal_bt_is_ble_gatt_gap_supported(void) {
    return false;
}

bool furi_hal_bt_is_testing_supported(void) {
    return false;
}

void furi_hal_bt_start_advertising(void) {
    // Stub
}

void furi_hal_bt_stop_advertising(void) {
    // Stub
}

bool furi_hal_bt_is_connected(void) {
    return false;
}

void furi_hal_bt_set_key_storage_change_callback(
    FuriHalBtKeyStorageChangedCallback callback,
    void* context) {
    (void)callback;
    (void)context;
}

void furi_hal_bt_nvm_sram_sem_acquire(void) {
    // Stub
}

void furi_hal_bt_nvm_sram_sem_release(void) {
    // Stub
}

bool furi_hal_bt_clear_white_list(void) {
    return false;
}

void furi_hal_bt_dump_state(FuriString* buffer) {
    (void)buffer;
}

void furi_hal_bt_change_log_level(FuriLogLevel level) {
    (void)level;
}

bool furi_hal_bt_reinit(void) {
    return false;
}

void furi_hal_bt_get_key_storage_buff(uint8_t** key_buff_addr, uint16_t* key_buff_size) {
    (void)key_buff_addr;
    (void)key_buff_size;
}

void furi_hal_bt_set_profile_adv_name(const char* name, uint8_t len) {
    (void)name;
    (void)len;
}

const uint8_t* furi_hal_bt_get_ble_mac(void) {
    static uint8_t mac[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
    return mac;
}

void furi_hal_bt_start_tone_tx(uint8_t channel, uint8_t power) {
    (void)channel;
    (void)power;
}

void furi_hal_bt_stop_tone_tx(void) {
    // Stub
}

void furi_hal_bt_start_packet_tx(uint8_t channel, uint8_t pattern, uint8_t datarate) {
    (void)channel;
    (void)pattern;
    (void)datarate;
}

void furi_hal_bt_stop_packet_test(void) {
    // Stub
}

void furi_hal_bt_start_packet_rx(uint8_t channel, uint8_t datarate) {
    (void)channel;
    (void)datarate;
}

uint16_t furi_hal_bt_get_rssi(void) {
    return 0;
}

uint32_t furi_hal_bt_get_transmitted_packets(void) {
    return 0;
}

void furi_hal_bt_reverse_mac_addr(uint8_t mac_addr[GAP_MAC_ADDR_SIZE]) {
    (void)mac_addr;
}
