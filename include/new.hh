#ifndef NEW_HH
#define NEW_HH

#include "prelude.h"

// Standard new operators use this independent runtime callback.
extern void (*__new_handler)();

EXTERN_C

// Native adapters to the ordinary C++ allocation/deallocation entries.
void * AllocateCppObjectMemory(u32 size);
void DeallocateCppObjectMemory(void * pointer);

EXTERN_C_END

#endif // NEW_HH
