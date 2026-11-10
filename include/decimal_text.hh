#ifndef DECIMAL_TEXT_HH
#define DECIMAL_TEXT_HH

#include "prelude.h"

EXTERN_C
// Writes two-byte full-width digits, spaces and hyphens followed by a NUL.
// Width zero uses the original ten-character limit; nonzero width pads or
// truncates to that many characters. Width must fit the original twelve-byte
// work buffers; output needs two bytes per resulting character plus the NUL.
void FormatFullWidthDecimal(i32 value, char * output, u32 width);

// Native signed ASCII formatter. A nonzero width pads or truncates the
// magnitude before prepending the sign; zero selects its actual digit count.
// The twelve-byte work buffer and the original extreme-input behavior remain.
void FormatSignedDecimal(i32 value, char * output, u32 width);

EXTERN_C_END

// These native objects physically precede the layout-position table.  The
// full-width decimal formatter FormatFullWidthDecimal reads two encoded bytes from
// each three-byte digit row, or from the space/hyphen strings.  Its checked
// ASCII index uses (DigitRows - '0' * 3) + character * 3; the terminator is
// not copied.  Existing names still describe the verified physical layout.
extern char const gUnk_PreUiTextLayoutDigitRows[10][3];
extern char const gUnk_PreUiTextLayoutFullWidthSpace[];
extern char const gUnk_PreUiTextLayoutFullWidthHyphen[];


#endif // DECIMAL_TEXT_HH
