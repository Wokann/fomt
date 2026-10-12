#include "libsram.h"
#include "gbaio.h"

// SDK identification, not localized game text. The following four function
// address constants are emitted naturally by the RAM-copy implementations.
char const gSramLibraryVersion[] = "SRAM_V113";

void ReadSramFast_Core(u8 const *source, u8 *destination, u32 size)
{
    u32 remaining = size - 1;

    if (size != 0)
    {
        do
        {
            *destination++ = *source++;
        } while (remaining--);
    }
}

void ReadSramFast(u8 const *source, u8 *destination, u32 size)
{
    u16 code[64];
    u16 const *input;
    u16 *output;
    u16 count;

    REG_WAITCNT = (REG_WAITCNT & 0xFFFC) | 3;

    // Read the core's instructions, not its Thumb-tagged entry pointer.
    input = (u16 const *)ReadSramFast_Core;
    input = (u16 const *)((u32)input & ~1);
    output = code;
    count = ((u32)ReadSramFast - (u32)ReadSramFast_Core) / 2;
    while (count != 0)
    {
        *output++ = *input++;
        --count;
    }

    // Execute the copied code in RAM; bit zero selects Thumb state.
    ((void (*)(u8 const *, u8 *, u32))((u32)code + 1))(source, destination, size);
}

void WriteSramFast(u8 const *source, u8 *destination, u32 size)
{
    REG_WAITCNT = (REG_WAITCNT & 0xFFFC) | 3;
    while (size--)
        *destination++ = *source++;
}

u32 VerifySramFast_Core(u8 const *source, u8 const *destination, u32 size)
{
    u32 remaining = size - 1;

    if (size != 0)
    {
        do
        {
            if (*destination++ != *source++)
                return (u32)(destination - 1);
        } while (remaining--);
    }
    return 0;
}

u32 VerifySramFast(u8 const *source, u8 const *destination, u32 size)
{
    u16 code[96];
    u16 const *input;
    u16 *output;
    u16 count;

    REG_WAITCNT = (REG_WAITCNT & 0xFFFC) | 3;

    input = (u16 const *)VerifySramFast_Core;
    input = (u16 const *)((u32)input & ~1);
    output = code;
    count = ((u32)VerifySramFast - (u32)VerifySramFast_Core) / 2;
    while (count != 0)
    {
        *output++ = *input++;
        --count;
    }

    return ((u32 (*)(u8 const *, u8 const *, u32))((u32)code + 1))(source, destination, size);
}

u32 WriteSramFastAndVerify(u8 const *source, u8 *destination, u32 size)
{
    u8 retry;
    u32 result;

    for (retry = 0; retry < 3; retry++)
    {
        WriteSramFast(source, destination, size);
        result = VerifySramFast(source, destination, size);
        if (result == 0)
            break;
    }
    return result;
}
