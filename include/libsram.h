#ifndef LIBSRAM_H
#define LIBSRAM_H

#include "prelude.h"

EXTERN_C

// Read and verify copy their core routines to RAM before accessing SRAM.
void ReadSramFast_Core(u8 const *source, u8 *destination, u32 size);
void ReadSramFast(u8 const *source, u8 *destination, u32 size);
void WriteSramFast(u8 const *source, u8 *destination, u32 size);

// Return the first mismatching destination address, or zero on success.
u32 VerifySramFast_Core(u8 const *source, u8 const *destination, u32 size);
u32 VerifySramFast(u8 const *source, u8 const *destination, u32 size);
// Try writing and verifying at most three times; return the last result.
u32 WriteSramFastAndVerify(u8 const *source, u8 *destination, u32 size);

EXTERN_C_END

#endif // LIBSRAM_H
