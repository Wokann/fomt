#include "hardware_oam_state.hh"
#include "hardware_display_output.hh"
#include "gbasvc.h"

// A distinct initialized IWRAM data run, before the grouped sprite renderer.
// Its halfword lookup requires two-byte alignment, not per-record sections.
struct HardwareSpriteDimensions const gHardwareSpriteDimensions[3][4] ALIGN(2) = {
    { { 8, 8 }, { 16, 16 }, { 32, 32 }, { 64, 64 } },
    { { 16, 8 }, { 32, 8 }, { 32, 16 }, { 64, 32 } },
    { { 8, 16 }, { 8, 32 }, { 16, 32 }, { 32, 64 } },
};

void func_08009834(void * object)
{
    struct HardwareSpriteBufferState * buffer = (struct HardwareSpriteBufferState *)object;
    u8 old_count = buffer->sprite_count;
    u8 new_count = buffer->reset_sprite_count;
    if (old_count > new_count) {
        u8 * entry = (u8 *)(buffer->sprites + new_count);
        u8 * end = (u8 *)(buffer->sprites + old_count);
        do {
            entry[1] = 2;
            entry += 8;
        } while (entry != end);
    }
    buffer->sprite_count = new_count;
    buffer->matrix_count = buffer->reset_matrix_count;
}

void func_08009864(void * object)
{
    func_0800977C(object);
    func_08009834(object);
}

void func_08009878(void * object)
{
    CpuFastSet((u8 *)object + 4, (void *)0x07000000, 0x100);
    func_08009834(object);
}

void func_08009898(void * object)
{
    func_080097A4(object);
    func_08009834(object);
}
