#ifndef COMPRESSION_HH
#define COMPRESSION_HH

#include "prelude.h"

EXTERN_C

// FoMT's native Huffman/LZ/delta stream, not the GBA BIOS LZ format.
// The header/source is word-aligned and output uses halfword stores.
// Returns the header's unpacked byte count. No input validation is added.
u32 Unpack(u8 const * source, void * destination);

EXTERN_C_END

#endif // COMPRESSION_HH
