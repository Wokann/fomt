#ifndef RANDOM_HH
#define RANDOM_HH

#include "prelude.h"

EXTERN_C

extern u32 gRandomSeed;
void srand(unsigned int seed);
// Native LCG result: the updated seed with its high bit cleared.
int rand(void);

// Scale the low 16 random bits with the original 32-bit product.
u32 RandomBelow(u32 limit);

EXTERN_C_END

#endif // RANDOM_HH
