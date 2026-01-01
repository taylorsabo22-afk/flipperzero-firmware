#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void furi_hal_clock_init_early(void);
void furi_hal_clock_deinit_early(void);
void furi_hal_clock_init(void);

#ifdef __cplusplus
}
#endif
