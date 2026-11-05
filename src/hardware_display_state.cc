#include "hardware_display_state.hh"

#include "hardware_dma.hh"
#include "gbaio.h"
#include "gbasvc.h"

HardwareDisplayState::HardwareDisplayState()
{
    volatile u16 zero = 0;
    CpuSet((void const *)&zero, this, CPUSET_SRC_FIXED | CPUSET_16BIT
        | (offsetof(HardwareDisplayState, unk_56) / sizeof(u16)));
    this->control.word = DISPCNT_FORCED_BLANK;
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
    REG_BLDY = object->blend_brightness;
}

void WriteHardwareDisplayStateWithBios(struct HardwareDisplayState * object)
{
    CpuFastSet(object, (void *)&REG_DISPCNT,
        (REG_OFFSET_WIN0H - REG_OFFSET_DISPCNT) / sizeof(u32));
    CpuSet((u8 *)object + REG_OFFSET_WIN0H, (void *)&REG_WIN0H,
        CPUSET_32BIT | ((REG_OFFSET_BLDY - REG_OFFSET_WIN0H) / sizeof(u32)));
    // Keep this routine's distinct final BG1 write; it does not mirror BLDY.
    REG_BG1HOFS = object->background_scroll[1][0];
}
