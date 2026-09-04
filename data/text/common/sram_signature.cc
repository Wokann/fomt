#include "sram_signature.hh"

// This is persisted to SRAM and compared as all 32 bytes, including its
// single terminator.  The same header is present in both regional ROMs.
char const gSramImageSignature[32] SECTION(".rodata.sram_signature") =
    "GBA牧場物語のSRAMイメージ 00000";
