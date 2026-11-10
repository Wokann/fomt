#ifndef RANDOM_HH
#define RANDOM_HH

#include "libc_random.h"

EXTERN_C

// Scale the low 16 random bits with the original 32-bit product.
u32 RandomBelow(u32 limit);

EXTERN_C_END

#endif // RANDOM_HH
