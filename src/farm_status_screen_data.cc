#include "farm_status_screen_data.hh"

// These regional text groups occupy the native Farm Status ROM run immediately
// before the screen's lookup and preview data.
#include FOMT_TEXT_INCLUDE(farm_status_screen_data_1.cc)
#include FOMT_TEXT_INCLUDE(farm_status_screen_data_2.cc)

// These packed labels are fields of the status-screen structures, not
// standalone string objects. Keeping their typed aggregates here preserves
// the original field layout while the text preprocessor encodes each literal.
AnimalStatusScreenPrefixText const gAnimalStatusScreenPrefixText = {
#if defined(REGION_JP)
    "なし",
    "O１２３４５６７８９\x82",
#else
    "N/A ",
    {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
    },
#endif
};

AnimalStatusScreenText const gAnimalStatusScreenText = {
#if defined(REGION_JP)
    "健康",
    "不機嫌",
    "病気",
    "春",
    "夏",
    "秋",
    "冬",
    "才",
    "日",
#elif defined(REGION_DE)
    "Gesund  ",
    "Traurig ",
    "Krank   ",
    "Frühl.",
    "Sommer",
    "Herbst",
    "Winter",
    "J ",
    "T ",
#else
    "Healthy ",
    "Unhappy ",
    "Sick    ",
    "Spring",
    "Summer",
    "Fall  ",
    "Winter",
    "Y ",
    "D ",
#endif
};

#include FOMT_TEXT_INCLUDE(farm_status_screen_data_3.cc)

// This runtime literal is physically between the two animal-contest text runs.
#include FOMT_TEXT_INCLUDE(farm_status_screen_data_4.cc)

// The final confirmation strings follow that runtime literal.
#include FOMT_TEXT_INCLUDE(farm_status_screen_data_5.cc)

// The renderer consumes this preloaded glyph-code array directly.  The
// selected regional text is encoded by the ordinary text channel.
u16 const gFarmStatusScreenPreloadedGlyphs[] = {
#include FOMT_TEXT_INCLUDE(farm_status_screen_data_6.cc)
};

// This runtime literal immediately follows the glyph array.
#include FOMT_TEXT_INCLUDE(farm_status_screen_data_7.cc)

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
    { gUnk_08529D74, gUnk_0852D020, 0x000D, 0x0001, 0x04, 0x06, 0x0000 },
    { gUnk_08529D14, gUnk_0852CFC0, 0x0009, 0x0001, 0x08, 0x06, 0x0000 },
    { gUnk_08529C6C, gUnk_0852CF18, 0x0005, 0x0001, 0x0C, 0x07, 0x0000 },
#elif defined(REGION_DE)
    { gUnk_082B0E10, gUnk_082B40BC, 0x000D, 0x0001, 0x04, 0x06, 0x0000 },
    { gUnk_082B0DB0, gUnk_082B405C, 0x0009, 0x0001, 0x08, 0x06, 0x0000 },
    { gUnk_082B0D08, gUnk_082B3FB4, 0x0005, 0x0001, 0x0C, 0x07, 0x0000 },
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
    { gUnk_08529B78, gUnk_0852CE24, 0x0007, 0x001A, 0x04, 0x06, 0x0000 },
    { gUnk_08529B18, gUnk_0852CDC4, 0x0007, 0x001A, 0x08, 0x06, 0x0000 },
#elif defined(REGION_DE)
    { gUnk_082B0C14, gUnk_082B3EC0, 0x0007, 0x001A, 0x04, 0x06, 0x0000 },
    { gUnk_082B0BB4, gUnk_082B3E60, 0x0007, 0x001A, 0x08, 0x06, 0x0000 },
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
    { gUnk_0852A684, gUnk_0852D930, 0x001D, 0x0001, 0x06, 0x07, 0x0000 },
    { gUnk_0852A5E8, gUnk_0852D894, 0x001D, 0x0001, 0x0B, 0x07, 0x0000 },
#elif defined(REGION_DE)
    { gUnk_082B1720, gUnk_082B49CC, 0x001D, 0x0001, 0x06, 0x07, 0x0000 },
    { gUnk_082B1684, gUnk_082B4930, 0x001D, 0x0001, 0x0B, 0x07, 0x0000 },
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

// This runtime literal is the final object in the native status-screen run.
#include FOMT_TEXT_INCLUDE(farm_status_screen_data_8.cc)
