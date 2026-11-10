#ifndef DECIMAL_FORMAT_H
#define DECIMAL_FORMAT_H

#include "prelude.h"

EXTERN_C

// Writes an unsigned 32-bit value as ASCII decimal followed by a terminator.
// The caller provides space for up to ten digits and the terminator.
void FormatUnsignedDecimal(u32 value, char * output);

EXTERN_C_END

#endif // DECIMAL_FORMAT_H
