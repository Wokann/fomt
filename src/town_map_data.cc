#include "town_map.hh"

#include "town_map_text.hh"

extern "C" bool TownMapHotspotContains(
    void const *, u32 cursor_x, u32 cursor_y, TownMapHotspot const * hotspot)
    SECTION(".text.town_map_hotspot_contains");

extern "C" bool TownMapHotspotContains(
    void const *, u32 cursor_x, u32 cursor_y, TownMapHotspot const * hotspot)
{
    bool result = false;

    if (hotspot->min_cursor_x <= cursor_x &&
        cursor_x <= hotspot->max_cursor_x &&
        hotspot->min_cursor_y <= cursor_y &&
        cursor_y <= hotspot->max_cursor_y)
        result = true;

    return result;
}

TownMapHotspot const gTownMapHotspots[TOWN_MAP_HOTSPOT_COUNT] SECTION(".rodata.town_map_hotspots") = {
    { gText_TownMap_MountainCottageLabel, gText_TownMap_MountainCottageLabel, 0x00000000, 0x0168, 0x0090, 0x02, 0x29, 0x14, 0x37 },
    { gText_TownMap_SeasideCottageLabel, gText_TownMap_SeasideCottageLabel, 0x00000001, 0x0104, 0x01F8, 0xDB, 0x31, 0xEC, 0x42 },
    { gText_TownMap_TownCottageLabel, gText_TownMap_TownCottageLabel, 0x00000007, 0x0224, 0x006A, 0x70, 0x30, 0x7E, 0x3A },
    { gText_TownMap_TimeWindowSeasonDescription, gText_TownMap_TimeWindowSeasonDescription, 0x00000234, 0x0000, 0x0000, 0x9C, 0x54, 0xAB, 0x5B },
    { gText_TownMap_TimeWindowDateDescription, gText_TownMap_TimeWindowDateDescription, 0x00000234, 0x0000, 0x0000, 0xAC, 0x54, 0xC3, 0x5B },
    { gText_TownMap_TimeWindowDayDescription, gText_TownMap_TimeWindowDayDescription, 0x00000234, 0x0000, 0x0000, 0xC4, 0x54, 0xDB, 0x5B },
    { gText_TownMap_TimeWindowTimeDescription, gText_TownMap_TimeWindowTimeDescription, 0x00000234, 0x0000, 0x0000, 0x9C, 0x5C, 0xDB, 0x68 },
    { gText_TownMap_TimeWindowWeatherDescription, gText_TownMap_TimeWindowWeatherDescription, 0x00000234, 0x0000, 0x0000, 0xDC, 0x54, 0xEC, 0x68 },
    { gText_TownMap_TimeWindowLabel, gText_TownMap_TimeWindowLabel, 0x00000234, 0x0000, 0x0000, 0x98, 0x50, 0xF0, 0x68 },
    { gText_TownMap_BasilHouseLabel, gText_TownMap_BasilHouseLabel, 0x00000005, 0x00C8, 0x00A8, 0x50, 0x02, 0x58, 0x0F },
    { gText_TownMap_MaryLibraryDescription, gText_TownMap_MaryLibraryHours, 0x00000005, 0x0114, 0x00B0, 0x59, 0x02, 0x5E, 0x0F },
    { gText_TownMap_EllenHouseLabel, gText_TownMap_EllenHouseLabel, 0x00000005, 0x0190, 0x00A8, 0x61, 0x02, 0x6B, 0x0F },
    { gText_TownMap_MayorHouseLabel, gText_TownMap_MayorHouseLabel, 0x00000005, 0x01E0, 0x00A8, 0x6D, 0x02, 0x77, 0x0F },
    { gText_TownMap_SupermarketDescription, gText_TownMap_SupermarketHours, 0x00000005, 0x02B0, 0x00A8, 0x7C, 0x02, 0x8F, 0x0F },
    { gText_TownMap_MineralClinicDescription, gText_TownMap_MineralClinicHours, 0x00000005, 0x0358, 0x00A8, 0x98, 0x02, 0xA8, 0x0F },
    { gText_TownMap_ChurchDescription, gText_TownMap_ChurchHours, 0x00000005, 0x04D0, 0x00A8, 0xB1, 0x02, 0xC7, 0x0F },
    { gText_TownMap_AjaWineryDescription, gText_TownMap_AjaWineryHours, 0x00000005, 0x00E8, 0x01E8, 0x52, 0x16, 0x71, 0x22 },
    { gText_TownMap_DukeCellarLabel, gText_TownMap_DukeCellarLabel, 0x00000005, 0x013C, 0x01D0, 0x61, 0x16, 0x68, 0x1E },
    { gText_TownMap_DougsInnDescription, gText_TownMap_DougsInnHours, 0x00000005, 0x0278, 0x01F0, 0x78, 0x17, 0x8A, 0x22 },
    { gText_TownMap_HarvestSpritesHomeDescription, gText_TownMap_HarvestSpritesHomeHours, 0x00000004, 0x0174, 0x0138, 0xD8, 0x00, 0xDF, 0x08 },
    { gText_TownMap_ZackHouseDescription, gText_TownMap_ZackHouseLabel, 0x00000001, 0x00D4, 0x0078, 0xD2, 0x22, 0xDE, 0x2B },
    { gText_TownMap_KaiSeasideLodgeDescription, gText_TownMap_KaiSeasideLodgeHours, 0x00000001, 0x0054, 0x0078, 0xC8, 0x22, 0xCF, 0x2B },
    { gText_TownMap_SaibaraBlacksmithDescription, gText_TownMap_SaibaraBlacksmithHours, 0x00000007, 0x0128, 0x0078, 0x56, 0x2B, 0x68, 0x3A },
    { gText_TownMap_YodelFarmDescription, gText_TownMap_YodelFarmHours, 0x00000007, 0x03E0, 0x00F0, 0x94, 0x3C, 0xBF, 0x4E },
    { gText_TownMap_PoultryFarmDescription, gText_TownMap_PoultryFarmHours, 0x00000007, 0x023C, 0x00E8, 0x6C, 0x3C, 0x80, 0x4E },
    { gText_TownMap_WoodcutterHouseDescription, gText_TownMap_WoodcutterHouseHours, 0x00000003, 0x0264, 0x00F8, 0x74, 0x51, 0x7B, 0x5D },
    { gText_TownMap_LakeMineDescription, gText_TownMap_LakeMineLabel, 0x00000000, 0x01A8, 0x01C0, 0x04, 0x4A, 0x11, 0x55 },
    { gText_TownMap_SpringMineDescription, gText_TownMap_SpringMineLabel, 0x00000000, 0x0384, 0x015E, 0x22, 0x3A, 0x2F, 0x45 },
    { gText_TownMap_HotSpringDescription, gText_TownMap_HotSpringLabel, 0x00000000, 0x0358, 0x0218, 0x28, 0x4A, 0x37, 0x58 },
    { gText_TownMap_Empty, gText_TownMap_Empty, 0x00000002, 0x00E4, 0x0078, 0x41, 0x3D, 0x66, 0x59 },
    { gText_TownMap_NorthMineralTownDescription, gText_TownMap_NorthMineralTownLabel, 0x00000005, 0x0068, 0x02A8, 0x41, 0x00, 0xC6, 0x27 },
    { gText_TownMap_RearChurchDescription, gText_TownMap_RearChurchLabel, 0x00000004, 0x014C, 0x0170, 0xC7, 0x00, 0xE4, 0x20 },
    { gText_TownMap_RoseSquareDescription, gText_TownMap_RoseSquareLabel, 0x00000006, 0x00DC, 0x01B0, 0xAB, 0x28, 0xC7, 0x36 },
    { gText_TownMap_MineralBeachDescription, gText_TownMap_MineralBeachLabel, 0x00000001, 0x0018, 0x0118, 0xC8, 0x21, 0xEA, 0x48 },
    { gText_TownMap_SouthMineralTownDescription, gText_TownMap_SouthMineralTownLabel, 0x00000007, 0x0068, 0x01F0, 0x41, 0x28, 0xAA, 0x3C },
    { gText_TownMap_SouthMineralTownDescription, gText_TownMap_SouthMineralTownLabel, 0x00000007, 0x0068, 0x01F0, 0x67, 0x37, 0xC7, 0x50 },
    { gText_TownMap_ForestDescription, gText_TownMap_ForestLabel, 0x00000003, 0x00A8, 0x0018, 0x67, 0x51, 0xC7, 0x5A },
    { gText_TownMap_ForestDescription, gText_TownMap_ForestLabel, 0x00000003, 0x00A8, 0x0018, 0x41, 0x5A, 0xB9, 0x67 },
    { gText_TownMap_MothersHillPeakDescription, gText_TownMap_MothersHillPeakLabel, 0x00000008, 0x00EC, 0x01D0, 0x10, 0x00, 0x28, 0x14 },
    { gText_TownMap_MothersHillDescription, gText_TownMap_MothersHillLabel, 0x00000000, 0x0497, 0x02F0, 0x00, 0x20, 0x40, 0x67 },
};
