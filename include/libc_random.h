#ifndef LIBC_RANDOM_H
#define LIBC_RANDOM_H

#include "prelude.h"

EXTERN_C

extern u32 gRandomSeed;
void srand(unsigned int seed);
// Native LCG result: the updated seed with its high bit cleared.
int rand(void);

EXTERN_C_END

#endif // LIBC_RANDOM_H
