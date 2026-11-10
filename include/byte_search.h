#ifndef BYTE_SEARCH_H
#define BYTE_SEARCH_H

#include "prelude.h"

EXTERN_C

// Return the first element >= *value in sorted [first, last), or last.
// Compare each unsigned byte against the full unsigned 32-bit key.
u8 const * FindLowerBoundUnsignedByte(u8 const * first, u8 const * last, u32 const * value);

EXTERN_C_END

#if defined(__cplusplus)
#include <algorithm>

struct UnsignedByteLess {
    bool operator()(u32 const & left, u32 const & right) const { return left < right; }
};

typedef char UnsignedByteLessAbiCheck[sizeof(UnsignedByteLess) == sizeof(u32) ? 1 : -1];

namespace std {
// The native implementation is the unsigned-byte/32-bit-key specialization.
// The stateless comparison and distance marker have no stored state.
template <>
u8 const * __lower_bound<u8 const *, u32, UnsignedByteLess, ptrdiff_t>(
    u8 const * first, u8 const * last, u32 const & value, UnsignedByteLess, ptrdiff_t *)
    asm("FindLowerBoundUnsignedByte");
}
#endif


#endif // BYTE_SEARCH_H
