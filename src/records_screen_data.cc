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
    { 0x084D7EB8, 0x084D7F38 },
    { 0x084D7FF8, 0x084D8078 },
    { 0x084D8098, 0x084D8118 },
    { 0x084D8138, 0x084D81B8 },
    { 0x084D81D8, 0x084D8258 },
    { 0x084D8278, 0x084D82F8 },
    { 0x084D7F58, 0x084D7FD8 },
#else
    { 0x08751F0C, 0x08751F8C },
    { 0x0875204C, 0x087520CC },
    { 0x087520EC, 0x0875216C },
    { 0x0875218C, 0x0875220C },
    { 0x0875222C, 0x087522AC },
    { 0x087522CC, 0x0875234C },
    { 0x08751FAC, 0x0875202C },
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
