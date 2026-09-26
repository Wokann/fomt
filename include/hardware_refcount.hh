#ifndef HARDWARE_REFCOUNT_HH
#define HARDWARE_REFCOUNT_HH

#include "prelude.h"

EXTERN_C

extern u8 * gUnk_03000408;

// Retain the shared hardware state and return the supplied owner unchanged.
void * func_080079D0(void * owner);

EXTERN_C_END

#endif // HARDWARE_REFCOUNT_HH
