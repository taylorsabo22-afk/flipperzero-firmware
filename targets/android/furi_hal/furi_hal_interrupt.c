#include <furi_hal_interrupt.h>

void furi_hal_interrupt_init(void) {
    // Android platform - interrupts not applicable
}

void furi_hal_interrupt_set_isr(FuriHalInterruptId index, FuriHalInterruptISR isr, void* context) {
    // Stub
    (void)index;
    (void)isr;
    (void)context;
}

void furi_hal_interrupt_set_isr_ex(
    FuriHalInterruptId index,
    FuriHalInterruptPriority priority,
    FuriHalInterruptISR isr,
    void* context) {
    // Stub
    (void)index;
    (void)priority;
    (void)isr;
    (void)context;
}
