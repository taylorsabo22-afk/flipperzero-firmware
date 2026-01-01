#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void furi_hal_i2c_init_early(void);
void furi_hal_i2c_deinit_early(void);
void furi_hal_i2c_init(void);

#ifdef __cplusplus
}
#endif
