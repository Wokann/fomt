#ifndef RANDOM_HH
#define RANDOM_HH

#include "prelude.h"

EXTERN_C

extern u32 gRandomSeed;
void srand(unsigned int seed);
// Native LCG result: the updated seed with its high bit cleared.
int rand(void);

EXTERN_C_END

#endif // RANDOM_HH
