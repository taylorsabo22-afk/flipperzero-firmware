#include <furi_hal_crypto.h>

void furi_hal_crypto_init(void) {
    // Android platform - can use standard crypto libs
}

bool furi_hal_crypto_verify_key(uint8_t key_slot) {
    (void)key_slot;
    return false;
}

bool furi_hal_crypto_store_keys(uint8_t* keys, uint8_t* signatures) {
    (void)keys;
    (void)signatures;
    return false;
}

void furi_hal_crypto_enclave_load_key(uint8_t key_slot) {
    (void)key_slot;
}

bool furi_hal_crypto_enclave_verify(
    uint8_t key_slot,
    uint8_t* hash,
    uint8_t* signature,
    size_t signature_length) {
    (void)key_slot;
    (void)hash;
    (void)signature;
    (void)signature_length;
    return false;
}

bool furi_hal_crypto_enclave_sign(
    uint8_t key_slot,
    uint8_t* hash,
    uint8_t* signature,
    FuriHalCryptoSignType sig_type) {
    (void)key_slot;
    (void)hash;
    (void)signature;
    (void)sig_type;
    return false;
}
