#include "hardware_display_output.hh"
#include "hardware_dma.hh"
#include "gbaio.h"
#include "gbasvc.h"

struct HardwareDisplayState * func_080096B0(struct HardwareDisplayState * object)
{
    volatile u16 zero = 0;
    CpuSet((void const *)&zero, object, 0x0100002B);
    object->control.word = 0x80;
    {
        u16 clear = 0;
        u16 identity = 0x100;
        object->matrix_a[0] = identity;
        object->matrix_a[1] = clear;
        object->matrix_a[2] = clear;
        object->matrix_a[3] = identity;
        object->matrix_b[0] = identity;
        object->matrix_b[1] = clear;
        object->matrix_b[2] = clear;
        object->matrix_b[3] = identity;
    }
    return object;
}

void WriteHardwareDisplayState(struct HardwareDisplayState * object)
{
    func_08008E64(object, (void *)&REG_DISPCNT,
        offsetof(struct HardwareDisplayState, blend_brightness));
    // The original routine writes BLDY as a halfword, not REG_BLDY's byte view.
    REG(u16, 0x04000054) = object->blend_brightness;
}

void func_08009710(struct HardwareDisplayState * object)
{
    CpuFastSet(object, (void *)0x04000000, 0x10);
    CpuSet((u8 *)object + 0x40, (void *)0x04000040, 0x04000005);
    // Keep this routine's distinct final BG1 write; it does not mirror BLDY.
    REG_BG1HOFS = object->background_scroll[1][0];
}

void * func_08009744(void * object, u8 byte1, u8 byte3)
{
    struct HardwareSpriteBufferState * buffer = (struct HardwareSpriteBufferState *)object;
    u8 * entry;
    u8 * end;

    buffer->reset_sprite_count = byte1 & 0x7F;
    buffer->sprite_count = byte1 & 0x7F;
    buffer->reset_matrix_count = byte3 & 0x1F;
    buffer->matrix_count = byte3 & 0x1F;
    entry = (u8 *)buffer->sprites;
    end = (u8 *)(buffer->sprites + ARRAY_COUNT(buffer->sprites));
    do {
        entry[1] = 2;
        entry += 8;
    } while (entry != end);
    return object;
}

void func_0800977C(void * object)
{
    func_08008E64((u8 *)object + 4, (void *)0x07000000, 0x400);
}

void func_08009790(void * object)
{
    CpuFastSet((u8 *)object + 4, (void *)0x07000000, 0x100);
}

void func_080097A4(u8 * buffer)
{
    u8 * parameter_cursor = buffer + 4;
    u8 * oam = (u8 *)0x07000000;
    u8 * end = buffer + 4 + ((struct HardwareSpriteBufferState *)buffer)->sprite_count *
        sizeof(struct HardwareSpriteOamRecord);
    u32 priority = 0;
    do {
        u8 * entry = buffer + 4;
        if (entry != end) {
            do {
                u16 attributes = *(u16 *)(entry + 4);
                if ((attributes & 0x0C00) == priority) {
                    *(u32 *)oam = *(u32 *)entry;
                    *(u16 *)(oam + 4) = attributes;
                    *(u16 *)(oam + 6) = *(u16 *)(parameter_cursor + 6);
                    parameter_cursor += 8;
                    oam += 8;
                }
                entry += 8;
            } while (entry != end);
        }
        priority += 0x400;
    } while (priority <= 0xFFF);

    if (oam != (u8 *)0x07000400) {
        u32 hidden = 0x200;
        u8 * last = (u8 *)0x07000400;
        do {
            *(u32 *)oam = hidden;
            *(u16 *)(oam + 6) = *(u16 *)(parameter_cursor + 6);
            parameter_cursor += 8;
            oam += 8;
        } while (oam != last);
    }
}
