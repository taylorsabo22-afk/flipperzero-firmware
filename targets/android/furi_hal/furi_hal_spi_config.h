#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void furi_hal_spi_config_init_early(void);
void furi_hal_spi_config_deinit_early(void);
void furi_hal_spi_config_init(void);
void furi_hal_spi_dma_init(void);

#ifdef __cplusplus
}
#endif
