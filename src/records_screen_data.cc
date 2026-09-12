#include "records_screen_data.hh"

#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(records.cc)
#else
#include FOMT_TEXT_INCLUDE(records.cc)
#endif

// Records-screen callers select entries from this two-word resource table.
// The pointed-to payload format and the roles of its two fields are not yet
// decoded, so their member names intentionally remain address-based.
RecordsScreenTaskResourcePair const gRecordsScreenMinigameTaskResources[] = {
#if defined(REGION_JP)
    { reinterpret_cast<u8 const *>(0x084D7EB8), reinterpret_cast<u8 const *>(0x084D7F38) },
    { reinterpret_cast<u8 const *>(0x084D7FF8), reinterpret_cast<u8 const *>(0x084D8078) },
    { reinterpret_cast<u8 const *>(0x084D8098), reinterpret_cast<u8 const *>(0x084D8118) },
    { reinterpret_cast<u8 const *>(0x084D8138), reinterpret_cast<u8 const *>(0x084D81B8) },
    { reinterpret_cast<u8 const *>(0x084D81D8), reinterpret_cast<u8 const *>(0x084D8258) },
    { reinterpret_cast<u8 const *>(0x084D8278), reinterpret_cast<u8 const *>(0x084D82F8) },
    { reinterpret_cast<u8 const *>(0x084D7F58), reinterpret_cast<u8 const *>(0x084D7FD8) },
#else
    { gUnk_08751F0C, gUnk_08751F8C },
    { gUnk_0875204C, gUnk_087520CC },
    { gUnk_087520EC, gUnk_0875216C },
    { gUnk_0875218C, gUnk_0875220C },
    { gUnk_0875222C, gUnk_087522AC },
    { gUnk_087522CC, gUnk_0875234C },
    { gUnk_08751FAC, gUnk_0875202C },
#endif
};

char const gCppRuntimeBadAlloc_RecordsScreenResources[] =
    "bad_alloc";

// func_080E2BB4 extracts packed two-bit cell dimensions from these bytes.
// Its owning high-level type is not decoded yet, so this name states only the
// verified call-site role rather than guessing a game subsystem.
u8 const gCodeLinkoncePackedCellSizeLookup[] = {
    0x50, 0xFA, 0x21, 0xB6, 0x84, 0xE9,
};

char const gCppRuntimeBadAlloc_PackedCellSizeLookup[] =
    "bad_alloc";

char const gCppRuntimeBadAlloc_UiDigitGlyphs[] =
    "bad_alloc";

// func_08075E7C renders these preloaded glyphs in numeric order.
u16 const gUiPreloadedDigitGlyphCodes[] = {
#if defined(REGION_JP)
    0x824F, 0x8250, 0x8251, 0x8252, 0x8253,
    0x8254, 0x8255, 0x8256, 0x8257, 0x8258,
#else
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034,
    0x0035, 0x0036, 0x0037, 0x0038, 0x0039,
#endif
};

char const gCppRuntimeBadAlloc_RecordsScreenTrailer[] =
    "bad_alloc";
