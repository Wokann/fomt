#include "decimal_format.h"

void FormatUnsignedDecimal(u32 value, char * output)
{
    char * end = output + 1;
    u32 maximum_power = 0xFFFFFFFFu / 10;
    u32 power = 10;
    while (value >= power) {
        ++end;
        if (power > maximum_power)
            break;
        power *= 10;
    }
    *end = '\0';
    do {
        u32 quotient;
        --end;
        quotient = value / 10;
        *end = value - quotient * 10 + '0';
        value = quotient;
    } while (value != 0);
}
