#ifndef IWRAM_SORT_HH
#define IWRAM_SORT_HH

#include "prelude.h"

EXTERN_C

// ARM entries in IWRAM. The existing ROM caller uses an interworking
// function pointer, rather than a Thumb BL to this different memory region.
// All ranges are half-open [first, last); comparisons are unsigned.
void MakeUnsignedWordHeap(u32 * first, u32 * last);
// The input range must already be a max-heap.
void SortUnsignedWordHeap(u32 * first, u32 * last);
void SortUnsignedWords(u32 * first, u32 * last);

EXTERN_C_END

#endif // IWRAM_SORT_HH
