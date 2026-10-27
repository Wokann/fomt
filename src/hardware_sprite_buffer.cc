#include "hardware_sprite_buffer.hh"

#include "hardware_dma.hh"
#include "gbaio.h"
#include "gbasvc.h"

// A distinct initialized IWRAM data run, before the grouped sprite renderer.
// Its halfword lookup requires two-byte alignment, not per-record sections.
struct HardwareSpriteDimensions const gHardwareSpriteDimensions[3][4] ALIGN(2) = {
    { { 8, 8 }, { 16, 16 }, { 32, 32 }, { 64, 64 } },
    { { 16, 8 }, { 32, 8 }, { 32, 16 }, { 64, 32 } },
    { { 8, 16 }, { 8, 32 }, { 16, 32 }, { 32, 64 } },
};

HardwareSpriteBufferState::HardwareSpriteBufferState(u8 byte1, u8 byte3)
{
    u8 * entry;
    u8 * end;

    this->reset_sprite_count = byte1 & 0x7F;
    this->sprite_count = byte1 & 0x7F;
    this->reset_matrix_count = byte3 & 0x1F;
    this->matrix_count = byte3 & 0x1F;
    entry = (u8 *)this->sprites;
    end = (u8 *)(this->sprites + ARRAY_COUNT(this->sprites));
    do {
        entry[1] = 2;
        entry += 8;
    } while (entry != end);
}

void WriteHardwareSpriteBuffer(HardwareSpriteBufferState * object)
{
    CopyHardwareDma3((u8 *)object + 4, (void *)0x07000000, 0x400);
}

void WriteHardwareSpriteBufferWithBios(HardwareSpriteBufferState * object)
{
    CpuFastSet((u8 *)object + 4, (void *)0x07000000, 0x100);
}

void WritePrioritizedHardwareSpriteBuffer(HardwareSpriteBufferState * state)
{
    u8 * buffer = reinterpret_cast<u8 *>(state);
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

void ResetHardwareSpriteBuffer(HardwareSpriteBufferState * object)
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

void WriteAndResetHardwareSpriteBuffer(HardwareSpriteBufferState * object)
{
    WriteHardwareSpriteBuffer(object);
    ResetHardwareSpriteBuffer(object);
}

void WriteAndResetHardwareSpriteBufferWithBios(HardwareSpriteBufferState * object)
{
    CpuFastSet((u8 *)object + 4, (void *)0x07000000, 0x100);
    ResetHardwareSpriteBuffer(object);
}

void WriteAndResetPrioritizedHardwareSpriteBuffer(HardwareSpriteBufferState * object)
{
    WritePrioritizedHardwareSpriteBuffer(object);
    ResetHardwareSpriteBuffer(object);
}
