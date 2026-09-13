#include "sram_proxy_1.hh"

// Persisted SRAM image signature; its explicit bound is part of the format.
char const gSramImageSignature[32] =
    "GBA牧場物語のSRAMイメージ 00000";

char const gUnk_SramSignatureTrailerBadAllocFirst[] ALIGN(4) =
    "bad_alloc";

char const gUnk_SramSignatureTrailerEmptyText[] ALIGN(4) =
    "";

char const gUnk_SramSignatureTrailerBadAllocSecond[] ALIGN(4) =
    "bad_alloc";

char const gUnk_SramSignatureTrailerBadAllocThird[] ALIGN(4) =
    "bad_alloc";
