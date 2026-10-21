#include "heap.hh"

HeapBlock * gHeapFirstBlock;

void InitializeGameHeap(void * memory, u32 size)
{
    HeapBlock * block = static_cast<HeapBlock *>(memory);
    gHeapFirstBlock = block;
    block->size = size - sizeof(HeapBlock);
    block->allocated = 0;
    block->previous = 0;
    block->next = 0;
}

void * malloc(size_t requested)
{
    u32 size = (requested + 3) / 4 * 4;
    HeapBlock * block = gHeapFirstBlock;
    for (; block != 0; block = block->next) {
        if (block->allocated == 0 && block->size >= size) {
            // Keep the tail only when it can hold a header and sixteen bytes.
            if (block->size >= size + 2 * sizeof(HeapBlock)) {
                HeapBlock * remainder = reinterpret_cast<HeapBlock *>(
                    reinterpret_cast<char *>(block) + size + sizeof(HeapBlock));
                u32 available = block->size;
                available -= sizeof(HeapBlock);
                available -= size;
                remainder->size = available;
                remainder->allocated = 0;
                remainder->previous = block;
                remainder->next = block->next;
                if (block->next != 0)
                    block->next->previous = remainder;
                block->size = size;
                block->next = remainder;
            }
            block->allocated = 1;
            break;
        }
    }
    if (block != 0)
        return block + 1;
    else
        return 0;
}

void free(void * memory)
{
    if (memory != 0) {
        HeapBlock * block = static_cast<HeapBlock *>(memory) - 1;
        HeapBlock * previous = block->previous;
        if (previous != 0 && previous->allocated == 0) {
            previous->size += sizeof(HeapBlock) + block->size;
            previous->next = block->next;
            if (block->next != 0)
                block->next->previous = previous;
            block = previous;
        }
        {
            HeapBlock * next = block->next;
            if (next != 0 && next->allocated == 0) {
                block->size += sizeof(HeapBlock) + next->size;
                block->next = next->next;
                if (next->next != 0)
                    next->next->previous = block;
            }
        }
        block->allocated = 0;
    }
}

u32 GetHeapAllocationSize(void const * memory)
{
    return memory != 0 ? (static_cast<HeapBlock const *>(memory) - 1)->size : 0;
}
