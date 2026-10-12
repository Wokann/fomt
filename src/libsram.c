#include "libsram.h"

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
