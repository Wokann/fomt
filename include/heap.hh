#ifndef HEAP_HH
#define HEAP_HH

#include "prelude.h"
#include <stddef.h>
#include <stdlib.h>

// Every block has a sixteen-byte header followed by its payload. The linked
// list contains both allocated and free blocks in physical address order.
struct HeapBlock {
    u32 size;
    u32 allocated;
    HeapBlock * previous;
    HeapBlock * next;
};

typedef char HeapBlockSizeCheck[sizeof(HeapBlock) == 16 ? 1 : -1];
typedef char HeapBlockAllocatedCheck[offsetof(HeapBlock, allocated) == 4 ? 1 : -1];
typedef char HeapBlockPreviousCheck[offsetof(HeapBlock, previous) == 8 ? 1 : -1];
typedef char HeapBlockNextCheck[offsetof(HeapBlock, next) == 12 ? 1 : -1];

extern HeapBlock * gHeapFirstBlock;

EXTERN_C

// Called by crt0 before the C++ runtime starts allocating objects.
void InitializeGameHeap(void * memory, u32 size);

// malloc/free use the standard declarations from stdlib.h above. This query
// returns stored payload capacity, including any unsplit spare bytes, or zero
// for a null pointer; it is not necessarily the originally requested size.
u32 GetHeapAllocationSize(void const * memory);

EXTERN_C_END

#endif // HEAP_HH
