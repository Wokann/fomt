#include "hardware_display_state.hh"

#include "hardware_dma.hh"
#include "gbaio.h"
#include "gbasvc.h"

HardwareDisplayState::HardwareDisplayState()
{
    volatile u16 zero = 0;
    CpuSet((void const *)&zero, this, 0x0100002B);
    this->control.word = 0x80;
    {
        u16 clear = 0;
        u16 identity = 0x100;
        this->matrix_a[0] = identity;
        this->matrix_a[1] = clear;
        this->matrix_a[2] = clear;
        this->matrix_a[3] = identity;
        this->matrix_b[0] = identity;
        this->matrix_b[1] = clear;
        this->matrix_b[2] = clear;
        this->matrix_b[3] = identity;
    }
}

void WriteHardwareDisplayState(struct HardwareDisplayState * object)
{
    CopyHardwareDma3(object, (void *)&REG_DISPCNT,
        offsetof(struct HardwareDisplayState, blend_brightness));
    // The original routine writes BLDY as a halfword, not REG_BLDY's byte view.
    REG(u16, 0x04000054) = object->blend_brightness;
}

void WriteHardwareDisplayStateWithBios(struct HardwareDisplayState * object)
{
    CpuFastSet(object, (void *)0x04000000, 0x10);
    CpuSet((u8 *)object + 0x40, (void *)0x04000040, 0x04000005);
    // Keep this routine's distinct final BG1 write; it does not mirror BLDY.
    REG_BG1HOFS = object->background_scroll[1][0];
}
