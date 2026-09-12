#include "farm_status_screen_data.hh"

// These regional text groups occupy the native Farm Status ROM run immediately
// before the screen's lookup and preview data.
#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(farm_status.cc)
#include FOMT_TEXT_INCLUDE(animal_contest.cc)
#else
#include FOMT_TEXT_INCLUDE(farm_status.cc)
#include FOMT_TEXT_INCLUDE(animal_contest.cc)
#endif

#if defined(REGION_JP)
u16 const gFarmStatusScreenPreloadedGlyphs[] =
    FOMT_GLYPH_SEQUENCE("０１２３４５６７８９春夏秋冬誕生日の月＿　");
#elif defined(REGION_DE)
u16 const gFarmStatusScreenPreloadedGlyphs[] =
    FOMT_GLYPH_SEQUENCE("0123456789Frühl.SommerHerbstWinter_Geburtstag ");
#else
u16 const gFarmStatusScreenPreloadedGlyphs[] =
    FOMT_GLYPH_SEQUENCE("0123456789SpringSummerFall  Winter_Birthday");
#endif

char const gCppRuntimeBadAlloc_FarmStatusScreenGlyphs[] =
    "bad_alloc";

FarmStatusScreenResourceDescriptor const gFarmStatusScreenResourceDescriptors[] = {
    { 0x0078, 0x0010 },
    { 0x0048, 0x00D8 },
    { 0x00F8, 0x0010 },
    { 0x0178, 0x0010 },
};

u16 const gFarmStatusScreenTileLookup[] = {
    0xF1E0, 0xF1E1, 0xE1E2, 0xC1E3, 0xE1E4, 0xC200, 0xF201,
    0xD204, 0xC202, 0xF203, 0xE220, 0xD223, 0xD221, 0xE224,
    0xE222, 0xF1E5, 0xE205, 0xC225, 0xC226, 0xF1E6, 0xB188,
    0xB185, 0xA180, 0xA184, 0xA181, 0xA182, 0xA183, 0xA1A4,
    0xA1A5, 0xA1C4, 0xA1C5, 0xA1A0, 0xA1A1, 0xA1C0, 0xA1C1,
    0xA1A2, 0xA1A3, 0xA1C2, 0xA1C3, 0x0000,
};

FarmStatusScreenBuildingPreview const gFarmStatusScreenFarmHousePreviews[] = {
#if defined(REGION_JP)
    { gUnk_082AFED0, gUnk_082B317C, 0x000D, 0x0001, 0x04, 0x06, 0x0000 },
    { gUnk_082AFE70, gUnk_082B311C, 0x0009, 0x0001, 0x08, 0x06, 0x0000 },
    { gUnk_082AFDC8, gUnk_082B3074, 0x0005, 0x0001, 0x0C, 0x07, 0x0000 },
#elif defined(REGION_EU)
    { gUnk_08529D74 - 8, gUnk_0852D020 - 8, 0x000D, 0x0001, 0x04, 0x06, 0x0000 },
    { gUnk_08529D14 - 8, gUnk_0852CFC0 - 8, 0x0009, 0x0001, 0x08, 0x06, 0x0000 },
    { gUnk_08529C6C - 8, gUnk_0852CF18 - 8, 0x0005, 0x0001, 0x0C, 0x07, 0x0000 },
#else
    { gUnk_08529D74, gUnk_0852D020, 0x000D, 0x0001, 0x04, 0x06, 0x0000 },
    { gUnk_08529D14, gUnk_0852CFC0, 0x0009, 0x0001, 0x08, 0x06, 0x0000 },
    { gUnk_08529C6C, gUnk_0852CF18, 0x0005, 0x0001, 0x0C, 0x07, 0x0000 },
#endif
};

FarmStatusScreenBuildingPreview const gFarmStatusScreenCoopPreviews[] = {
#if defined(REGION_JP)
    { gUnk_082AFCD4, gUnk_082B2F80, 0x0007, 0x001A, 0x04, 0x06, 0x0000 },
    { gUnk_082AFC74, gUnk_082B2F20, 0x0007, 0x001A, 0x08, 0x06, 0x0000 },
#elif defined(REGION_EU)
    { gUnk_08529B78 - 8, gUnk_0852CE24 - 8, 0x0007, 0x001A, 0x04, 0x06, 0x0000 },
    { gUnk_08529B18 - 8, gUnk_0852CDC4 - 8, 0x0007, 0x001A, 0x08, 0x06, 0x0000 },
#else
    { gUnk_08529B78, gUnk_0852CE24, 0x0007, 0x001A, 0x04, 0x06, 0x0000 },
    { gUnk_08529B18, gUnk_0852CDC4, 0x0007, 0x001A, 0x08, 0x06, 0x0000 },
#endif
};

FarmStatusScreenBuildingPreview const gFarmStatusScreenBarnPreviews[] = {
#if defined(REGION_JP)
    { gUnk_082B07E0, gUnk_082B3A8C, 0x001D, 0x0001, 0x06, 0x07, 0x0000 },
    { gUnk_082B0744, gUnk_082B39F0, 0x001D, 0x0001, 0x0B, 0x07, 0x0000 },
#elif defined(REGION_EU)
    { gUnk_0852A684 - 8, gUnk_0852D930 - 8, 0x001D, 0x0001, 0x06, 0x07, 0x0000 },
    { gUnk_0852A5E8 - 8, gUnk_0852D894 - 8, 0x001D, 0x0001, 0x0B, 0x07, 0x0000 },
#else
    { gUnk_0852A684, gUnk_0852D930, 0x001D, 0x0001, 0x06, 0x07, 0x0000 },
    { gUnk_0852A5E8, gUnk_0852D894, 0x001D, 0x0001, 0x0B, 0x07, 0x0000 },
#endif
};

FarmStatusScreenExteriorStyleData const gFarmStatusScreenExteriorStyleData = {
    { 0x05, 0x06, 0x05 },
    {
        { 0x05, 0x06, 0x08 },
        { 0x05, 0x01, 0x01 },
        { 0x00, 0x00, 0x00 },
    },
};

char const gCppRuntimeBadAlloc_FarmStatusScreenTrailer[] =
    "bad_alloc";
