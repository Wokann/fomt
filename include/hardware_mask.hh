#ifndef HARDWARE_MASK_HH
#define HARDWARE_MASK_HH

#include "prelude.h"

// The leaves of the OBJ tile tree each track 32 contiguous tiles.
typedef struct HardwareTileBitmap32 {
    u32 bits;
#ifdef __cplusplus
    HardwareTileBitmap32() : bits(0) {}
    bool IsFull() const { return bits + 1 == 0; }
    bool IsEmpty() const { return bits == 0; }
    // Allocate 2^size_shift tiles, or return 32 when no range is available.
    u32 Allocate(u32 size_shift);
    // The offset remains relative to the tree; only its low five bits matter.
    void Free(u32 offset, u32 size_shift);
#endif
} HardwareTileBitmap32;

typedef char HardwareTileBitmap32SizeCheck[sizeof(HardwareTileBitmap32) == 4 ? 1 : -1];

#endif // HARDWARE_MASK_HH
