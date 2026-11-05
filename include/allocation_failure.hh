#ifndef ALLOCATION_FAILURE_HH
#define ALLOCATION_FAILURE_HH

#include "prelude.h"

EXTERN_C

// This handler belongs to the original runtime's allocation-failure path,
// independently of the __new_handler used by the early new operators.
// This native callback has no dependency on the standard new header.
extern void (*gAllocationFailureHandler)();
void * RetryMemoryAllocation(size_t size);

EXTERN_C_END

#endif // ALLOCATION_FAILURE_HH
