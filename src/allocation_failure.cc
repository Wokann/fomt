#include "allocation_failure.hh"

#include <new>
#include <stdlib.h>

void * RetryMemoryAllocation(size_t size)
{
    for (;;)
    {
        std::new_handler handler = gAllocationFailureHandler;
        if (handler == nullptr)
        {
            for (;;) {}
        }
        handler();
        void * result = malloc(size);
        if (result != nullptr)
            return result;
    }
}

// This independent runtime callback is part of the initialized IWRAM image.
extern "C" {
void (*gAllocationFailureHandler)() __attribute__((section(".data"))) = nullptr;
}
