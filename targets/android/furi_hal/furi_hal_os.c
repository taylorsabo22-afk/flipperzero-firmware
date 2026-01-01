#include "furi_hal_os.h"
#include <FreeRTOS.h>
#include <task.h>

void furi_hal_os_init(void) {
    // FreeRTOS is already initialized, nothing to do
}

// FreeRTOS tick hook (called from tick interrupt)
void vApplicationTickHook(void) {
}

// FreeRTOS idle hook
void vApplicationIdleHook(void) {
}

// Stack overflow hook
void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName) {
    (void)xTask;
    (void)pcTaskName;
    // Handle stack overflow
    while(1);
}

// Malloc failed hook
void vApplicationMallocFailedHook(void) {
    // Handle malloc failure
    while(1);
}
