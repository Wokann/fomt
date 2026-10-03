#ifndef NEW_HH
#define NEW_HH

#include "prelude.h"
#include <new>

EXTERN_C

// This handler belongs to the original runtime's allocation-failure path,
// independently of the __new_handler used by the early new operators.
extern std::new_handler gUnk_03000CD4;
void * RetryMemoryAllocation(size_t size) SECTION(".text.new_retry");

EXTERN_C_END

#endif // NEW_HH
