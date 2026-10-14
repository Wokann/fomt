#include "iwram_sort.hh"

// Keep iterator differences signed: (hole - 1) / 2 truncates toward zero
// at the root, as in the native SGI-style max-heap implementation.
static inline void PushUnsignedWordHeap(u32 * first, ptrdiff_t hole, ptrdiff_t top, u32 value)
{
    ptrdiff_t parent = (hole - 1) / 2;
    while (hole > top && first[parent] < value)
    {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = value;
}

static inline void AdjustUnsignedWordHeap(u32 * first, ptrdiff_t hole, ptrdiff_t length, u32 value)
{
    ptrdiff_t top = hole;
    ptrdiff_t child = 2 * hole + 2;
    while (child < length)
    {
        if (first[child] < first[child - 1])
            --child;
        first[hole] = first[child];
        hole = child;
        child = 2 * (child + 1);
    }
    if (child == length)
    {
        first[hole] = first[child - 1];
        hole = child - 1;
    }
    PushUnsignedWordHeap(first, hole, top, value);
}

void MakeUnsignedWordHeap(u32 * first, u32 * last)
{
    if (last - first < 2)
        return;
    ptrdiff_t length = last - first;
    ptrdiff_t parent = (length - 2) / 2;
    for (;;)
    {
        AdjustUnsignedWordHeap(first, parent, length, first[parent]);
        if (parent == 0)
            return;
        --parent;
    }
}

static inline void PopUnsignedWordHeap(u32 * first, u32 * last, u32 * result, u32 value)
{
    *result = *first;
    AdjustUnsignedWordHeap(first, ptrdiff_t(0), last - first, value);
}

static inline void PopUnsignedWordHeap(u32 * first, u32 * last)
{
    PopUnsignedWordHeap(first, last - 1, last - 1, u32(*(last - 1)));
}

void SortUnsignedWordHeap(u32 * first, u32 * last)
{
    while (last - first > 1)
        PopUnsignedWordHeap(first, last--);
}

void SortUnsignedWords(u32 * first, u32 * last)
{
    MakeUnsignedWordHeap(first, last);
    SortUnsignedWordHeap(first, last);
}
