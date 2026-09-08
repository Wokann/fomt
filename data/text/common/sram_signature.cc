#include "sram_signature.hh"

// This is persisted to SRAM and compared as all 32 bytes, including its
// single terminator.  The same header is present in both regional ROMs.
char const gSramImageSignature[32] SECTION(".rodata.sram_signature") =
    "GBA牧場物語のSRAMイメージ 00000";

// These objects occupy the contiguous tail after the persisted signature.
// Their byte layouts are known, but no code reference establishes a higher-
// level role for them, so their names intentionally remain gUnk.
extern char const gUnk_SramSignatureTrailerBadAllocFirst[]
    SECTION(".rodata.sram_signature") ALIGN(4) =
        "bad_alloc";

extern char const gUnk_SramSignatureTrailerEmptyText[]
    SECTION(".rodata.sram_signature") ALIGN(4) =
        "";

extern char const gUnk_SramSignatureTrailerBadAllocSecond[]
    SECTION(".rodata.sram_signature") ALIGN(4) =
        "bad_alloc";

extern char const gUnk_SramSignatureTrailerBadAllocThird[]
    SECTION(".rodata.sram_signature") ALIGN(4) =
        "bad_alloc";

#if defined(REGION_US)
extern char const gUnk_SramSignatureTrailerError[]
    SECTION(".rodata.sram_signature") ALIGN(4) =
        "Error";

extern char const gUnk_SramSignatureTrailerNotAvailable[]
    SECTION(".rodata.sram_signature") ALIGN(4) =
        "N/A ";
#endif
