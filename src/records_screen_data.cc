#include "records_screen_data.hh"

#include FOMT_TEXT_INCLUDE(records_screen_data_1.cc)

// Records-screen callers select entries from this two-word resource table.
// The pointed-to payload format and the roles of its two fields are not yet
// decoded, so their member names intentionally remain address-based.
RecordsScreenTaskResourcePair const gRecordsScreenMinigameTaskResources[] = {
#if defined(REGION_JP)
    { gUnk_084D7EB8, gUnk_084D7F38 },
    { gUnk_084D7FF8, gUnk_084D8078 },
    { gUnk_084D8098, gUnk_084D8118 },
    { gUnk_084D8138, gUnk_084D81B8 },
    { gUnk_084D81D8, gUnk_084D8258 },
    { gUnk_084D8278, gUnk_084D82F8 },
    { gUnk_084D7F58, gUnk_084D7FD8 },
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

#include FOMT_TEXT_INCLUDE(records_screen_data_2.cc)

// func_080E2BB4 extracts packed two-bit cell dimensions from these bytes.
// Its owning high-level type is not decoded yet, so this name states only the
// verified call-site role rather than guessing a game subsystem.
u8 const gCodeLinkoncePackedCellSizeLookup[] = {
    0x50, 0xFA, 0x21, 0xB6, 0x84, 0xE9,
};

#include FOMT_TEXT_INCLUDE(records_screen_data_3.cc)

// func_08075E7C renders this regional glyph cache in numeric order.
u16 const gUiPreloadedDigitGlyphCodes[] =
#if defined(REGION_JP)
    FOMT_GLYPH_SEQUENCE("０１２３４５６７８９");
#elif defined(REGION_EU)
    FOMT_GLYPH_SEQUENCE("0123456789");
#elif defined(REGION_DE)
    FOMT_GLYPH_SEQUENCE("0123456789");
#else
    FOMT_GLYPH_SEQUENCE("0123456789");
#endif

#include FOMT_TEXT_INCLUDE(records_screen_data_4.cc)
