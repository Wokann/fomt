#include "sram_image.hh"
#include "sram_access.hh"
#include "types.h"

#include <string.h>

u8 IsValidSramImage(SramAccess *source)
{
    u8 header[0x20];
    u32 flags;
    u32 state;
    u8 result;

    source->Read(header, 0, sizeof(header));
    if (gSramAccessStatus != 0)
        return 0;

    flags = 0;
    source->Read(&flags, 0x20, sizeof(flags));
    if (gSramAccessStatus != 0)
        return 0;

    state = 0;
    source->Read(&state, 0x24, sizeof(state));
    if (gSramAccessStatus != 0)
        return 0;

    result = 0;
    if (memcmp(header, gSramImageSignature, sizeof(header)) == 0)
    {
        if ((flags & 3) == flags)
        {
            if (state <= 1)
                result = 1;
        }
    }

    return result;
}

void InitializeSramImageHeader(SramAccess *destination)
{
    u32 zero;

    destination->Write(0, gSramImageSignature, 0x20);
    if (gSramAccessStatus != 0)
        return;

    zero = 0;
    destination->Write(0x20, &zero, sizeof(zero));
    if (gSramAccessStatus != 0)
        return;

    destination->Write(0x24, &zero, sizeof(zero));
}

u32 GetSramSaveSlotMask(SramAccess *source)
{
    u32 value;

    if (!IsValidSramImage(source))
        return 0;

    value = 0;
    source->Read(&value, 0x20, sizeof(value));
    if (gSramAccessStatus != 0)
        return 0;

    return value;
}

u32 GetSramSaveSlotOffset(SramAccess const *unused, u32 index)
{
    u32 multiplier = 0x3FEC;
    return index * multiplier + 0x28;
}

void MarkSramSaveSlotPresent(SramAccess *source, u32 index)
{
    u32 value = 0;

    source->Read(&value, 0x20, sizeof(value));
    if (gSramAccessStatus == 0)
    {
        value |= 1 << index;
        source->Write(0x20, &value, sizeof(value));
    }
}

void ClearSramSaveSlotPresent(SramAccess *source, u32 index)
{
    u32 value = 0;

    source->Read(&value, 0x20, sizeof(value));
    if (gSramAccessStatus == 0)
    {
        value &= ~(1 << index);
        source->Write(0x20, &value, sizeof(value));
    }
}

void SetLastUsedSramSaveSlot(SramAccess *destination, u32 value)
{
    destination->Write(0x24, &value, sizeof(value));
}

u32 GetLastUsedSramSaveSlot(SramAccess *source)
{
    u32 value;

    if (!IsValidSramImage(source))
        return 0;

    value = 0;
    source->Read(&value, 0x24, sizeof(value));
    if (gSramAccessStatus != 0)
        return 0;

    return value;
}

// The persisted signature and its physically adjacent runtime strings are
// region-owned text.  Keeping the include here preserves their exact ROM
// order after the SRAM routines above.
#include FOMT_TEXT_INCLUDE(sram_image.cc)
