#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void furi_hal_resources_init_early(void);
void furi_hal_resources_deinit_early(void);
void furi_hal_resources_init(void);

#ifdef __cplusplus
}
#endif
