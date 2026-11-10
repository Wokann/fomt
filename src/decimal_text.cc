#include "decimal_text.hh"
#include "decimal_format.h"

#include FOMT_TEXT_INCLUDE(decimal_text.cc)

// Fixed-width formatting retains the original truncation and padding rules.
// Width zero emits at most ten ASCII characters before expanding each glyph.
void FormatFullWidthDecimal(i32 value, char * output, u32 width)
{
    char ascii[12];
    char reversed[12];
    if (width != 0) {
        bool negative = false;
        if (value < 0) {
            value = -value;
            negative = true;
        }
        i32 count = 0;
        for (; count < width; count++) {
            reversed[count] = value % 10 + '0';
            value /= 10;
            if (value == 0) {
                count++;
                for (; count < width; count++)
                    reversed[count] = ' ';
                break;
            }
        }
        if (negative)
            reversed[count] = '-';
        for (u32 index = 0; index < width; index++)
            ascii[width - index - 1] = reversed[index];
        ascii[width] = '\0';
    } else {
        i32 remaining = value;
        char * end = ascii;
        if (remaining < 0) {
            *end++ = '-';
            remaining = -remaining;
        }
        FormatUnsignedDecimal(remaining, end);
        ascii[10] = '\0';
    }
    u8 const * cursor = reinterpret_cast<u8 const *>(ascii);
    u8 character;
    while ((character = *cursor) != '\0') {
        char const * glyph;
        if ((u8)(character - '0') <= 9)
            glyph = gUnk_PreUiTextLayoutDigitRows[character - '0'];
        else if (character == ' ')
            glyph = gUnk_PreUiTextLayoutFullWidthSpace;
        else if (character == '-')
            glyph = gUnk_PreUiTextLayoutFullWidthHyphen;
        else
            break;
        output[0] = glyph[0];
        output[1] = glyph[1];
        output += 2;
        cursor++;
    }
    *output = '\0';
}

void FormatSignedDecimal(i32 value, char * output, u32 width)
{
    char reversed[12];
    bool negative = value < 0;
    u32 count = 0;
    i32 remaining = value;
    if (remaining < 0)
        remaining = -remaining;

    do {
        reversed[count++] = remaining % 10 + '0';
        remaining /= 10;
    } while (remaining > 0 && count + 1 <= 10);

    if (width != 0) {
        if (width < count)
            count = width;
        else {
            for (; width > count; count++)
                reversed[count] = ' ';
        }
    }
    if (negative)
        reversed[count++] = '-';
    for (count--; count != 0xFFFFFFFF; count--)
        *output++ = reversed[count];
    *output = '\0';
}
