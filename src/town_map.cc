#include "prelude.h"
#include "gbaio.h"
#pragma implementation "town_map.hh"
#include "game_scene.hh"
#include "town_map.hh"

#include "town_map_area_data.hh"

extern "C" void CopyBgMap30x13(void const *, u32 map_block, u16 const * source)
{
    u32 next_row;

    for (u32 row = 0; row <= 12; row = next_row)
    {
        u32 column = 0;
        u32 row_offset = row << 6;

        next_row = row + 1;

        volatile u16 * destination = reinterpret_cast<volatile u16 *>(
            BG_SCREEN_ADDR(map_block) + row_offset);

        for (; column <= 29; column++)
            destination[column] = *source++;
    }
}

extern "C" void CopyBgMapRect(
    void const *,
    u32 map_block,
    u32 x,
    u32 y,
    u32 width,
    u32 height,
    u16 const * source)
{
    u32 max_x = x + width;
    u32 max_y = y + height;

    for (; y < max_y; y++)
    {
        for (u32 column = x; column < max_x; column++)
        {
            volatile u16 * destination = reinterpret_cast<volatile u16 *>(
                BG_SCREEN_ADDR(map_block) + (y << 6) + (column << 1));

            *destination = *source++;
        }
    }
}

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

// TownMapUiScene copies these four IDs then resolves each from the Town Map
// indexed resource archive before its UI is created.
u16 const gTownMapResourceIds[] = {
        0x0000,
        0x0001,
        0x0003,
        0x0002,
    };

// The selected regional labels and descriptions immediately precede the
// native Town Map tables in all four ROMs.
#include FOMT_TEXT_INCLUDE(town_map.cc)

TownMapHotspot const gTownMapHotspots[TOWN_MAP_HOTSPOT_COUNT] = {
    { gText_TownMap_MountainCottageLabel, gText_TownMap_MountainCottageLabel, MAP_MOTHERS_HILL_MIDDLE, 0x0168, 0x0090, 0x02, 0x29, 0x14, 0x37 },
    { gText_TownMap_SeasideCottageLabel, gText_TownMap_SeasideCottageLabel, MAP_MINERAL_BEACH, 0x0104, 0x01F8, 0xDB, 0x31, 0xEC, 0x42 },
    { gText_TownMap_TownCottageLabel, gText_TownMap_TownCottageLabel, MAP_SOUTH_SIDE_TOWN, 0x0224, 0x006A, 0x70, 0x30, 0x7E, 0x3A },
    { gText_TownMap_TimeWindowSeasonDescription, gText_TownMap_TimeWindowSeasonDescription, MAP_NONE, 0x0000, 0x0000, 0x9C, 0x54, 0xAB, 0x5B },
    { gText_TownMap_TimeWindowDateDescription, gText_TownMap_TimeWindowDateDescription, MAP_NONE, 0x0000, 0x0000, 0xAC, 0x54, 0xC3, 0x5B },
    { gText_TownMap_TimeWindowDayDescription, gText_TownMap_TimeWindowDayDescription, MAP_NONE, 0x0000, 0x0000, 0xC4, 0x54, 0xDB, 0x5B },
    { gText_TownMap_TimeWindowTimeDescription, gText_TownMap_TimeWindowTimeDescription, MAP_NONE, 0x0000, 0x0000, 0x9C, 0x5C, 0xDB, 0x68 },
    { gText_TownMap_TimeWindowWeatherDescription, gText_TownMap_TimeWindowWeatherDescription, MAP_NONE, 0x0000, 0x0000, 0xDC, 0x54, 0xEC, 0x68 },
    { gText_TownMap_TimeWindowLabel, gText_TownMap_TimeWindowLabel, MAP_NONE, 0x0000, 0x0000, 0x98, 0x50, 0xF0, 0x68 },
    { gText_TownMap_BasilHouseLabel, gText_TownMap_BasilHouseLabel, MAP_NORTH_SIDE_TOWN, 0x00C8, 0x00A8, 0x50, 0x02, 0x58, 0x0F },
    { gText_TownMap_MaryLibraryDescription, gText_TownMap_MaryLibraryHours, MAP_NORTH_SIDE_TOWN, 0x0114, 0x00B0, 0x59, 0x02, 0x5E, 0x0F },
    { gText_TownMap_EllenHouseLabel, gText_TownMap_EllenHouseLabel, MAP_NORTH_SIDE_TOWN, 0x0190, 0x00A8, 0x61, 0x02, 0x6B, 0x0F },
    { gText_TownMap_MayorHouseLabel, gText_TownMap_MayorHouseLabel, MAP_NORTH_SIDE_TOWN, 0x01E0, 0x00A8, 0x6D, 0x02, 0x77, 0x0F },
    { gText_TownMap_SupermarketDescription, gText_TownMap_SupermarketHours, MAP_NORTH_SIDE_TOWN, 0x02B0, 0x00A8, 0x7C, 0x02, 0x8F, 0x0F },
    { gText_TownMap_MineralClinicDescription, gText_TownMap_MineralClinicHours, MAP_NORTH_SIDE_TOWN, 0x0358, 0x00A8, 0x98, 0x02, 0xA8, 0x0F },
    { gText_TownMap_ChurchDescription, gText_TownMap_ChurchHours, MAP_NORTH_SIDE_TOWN, 0x04D0, 0x00A8, 0xB1, 0x02, 0xC7, 0x0F },
    { gText_TownMap_AjaWineryDescription, gText_TownMap_AjaWineryHours, MAP_NORTH_SIDE_TOWN, 0x00E8, 0x01E8, 0x52, 0x16, 0x71, 0x22 },
    { gText_TownMap_DukeCellarLabel, gText_TownMap_DukeCellarLabel, MAP_NORTH_SIDE_TOWN, 0x013C, 0x01D0, 0x61, 0x16, 0x68, 0x1E },
    { gText_TownMap_DougsInnDescription, gText_TownMap_DougsInnHours, MAP_NORTH_SIDE_TOWN, 0x0278, 0x01F0, 0x78, 0x17, 0x8A, 0x22 },
    { gText_TownMap_HarvestSpritesHomeDescription, gText_TownMap_HarvestSpritesHomeHours, MAP_BEHIND_CHURCH, 0x0174, 0x0138, 0xD8, 0x00, 0xDF, 0x08 },
    { gText_TownMap_ZackHouseDescription, gText_TownMap_ZackHouseLabel, MAP_MINERAL_BEACH, 0x00D4, 0x0078, 0xD2, 0x22, 0xDE, 0x2B },
    { gText_TownMap_KaiSeasideLodgeDescription, gText_TownMap_KaiSeasideLodgeHours, MAP_MINERAL_BEACH, 0x0054, 0x0078, 0xC8, 0x22, 0xCF, 0x2B },
    { gText_TownMap_SaibaraBlacksmithDescription, gText_TownMap_SaibaraBlacksmithHours, MAP_SOUTH_SIDE_TOWN, 0x0128, 0x0078, 0x56, 0x2B, 0x68, 0x3A },
    { gText_TownMap_YodelFarmDescription, gText_TownMap_YodelFarmHours, MAP_SOUTH_SIDE_TOWN, 0x03E0, 0x00F0, 0x94, 0x3C, 0xBF, 0x4E },
    { gText_TownMap_PoultryFarmDescription, gText_TownMap_PoultryFarmHours, MAP_SOUTH_SIDE_TOWN, 0x023C, 0x00E8, 0x6C, 0x3C, 0x80, 0x4E },
    { gText_TownMap_WoodcutterHouseDescription, gText_TownMap_WoodcutterHouseHours, MAP_FOREST, 0x0264, 0x00F8, 0x74, 0x51, 0x7B, 0x5D },
    { gText_TownMap_LakeMineDescription, gText_TownMap_LakeMineLabel, MAP_MOTHERS_HILL_MIDDLE, 0x01A8, 0x01C0, 0x04, 0x4A, 0x11, 0x55 },
    { gText_TownMap_SpringMineDescription, gText_TownMap_SpringMineLabel, MAP_MOTHERS_HILL_MIDDLE, 0x0384, 0x015E, 0x22, 0x3A, 0x2F, 0x45 },
    { gText_TownMap_HotSpringDescription, gText_TownMap_HotSpringLabel, MAP_MOTHERS_HILL_MIDDLE, 0x0358, 0x0218, 0x28, 0x4A, 0x37, 0x58 },
    { gText_TownMap_Empty, gText_TownMap_Empty, MAP_FARM, 0x00E4, 0x0078, 0x41, 0x3D, 0x66, 0x59 },
    { gText_TownMap_NorthMineralTownDescription, gText_TownMap_NorthMineralTownLabel, MAP_NORTH_SIDE_TOWN, 0x0068, 0x02A8, 0x41, 0x00, 0xC6, 0x27 },
    { gText_TownMap_RearChurchDescription, gText_TownMap_RearChurchLabel, MAP_BEHIND_CHURCH, 0x014C, 0x0170, 0xC7, 0x00, 0xE4, 0x20 },
    { gText_TownMap_RoseSquareDescription, gText_TownMap_RoseSquareLabel, MAP_ROSE_SQUARE, 0x00DC, 0x01B0, 0xAB, 0x28, 0xC7, 0x36 },
    { gText_TownMap_MineralBeachDescription, gText_TownMap_MineralBeachLabel, MAP_MINERAL_BEACH, 0x0018, 0x0118, 0xC8, 0x21, 0xEA, 0x48 },
    { gText_TownMap_SouthMineralTownDescription, gText_TownMap_SouthMineralTownLabel, MAP_SOUTH_SIDE_TOWN, 0x0068, 0x01F0, 0x41, 0x28, 0xAA, 0x3C },
    { gText_TownMap_SouthMineralTownDescription, gText_TownMap_SouthMineralTownLabel, MAP_SOUTH_SIDE_TOWN, 0x0068, 0x01F0, 0x67, 0x37, 0xC7, 0x50 },
    { gText_TownMap_ForestDescription, gText_TownMap_ForestLabel, MAP_FOREST, 0x00A8, 0x0018, 0x67, 0x51, 0xC7, 0x5A },
    { gText_TownMap_ForestDescription, gText_TownMap_ForestLabel, MAP_FOREST, 0x00A8, 0x0018, 0x41, 0x5A, 0xB9, 0x67 },
    { gText_TownMap_MothersHillPeakDescription, gText_TownMap_MothersHillPeakLabel, MAP_MOTHERS_HILL_SUMMIT, 0x00EC, 0x01D0, 0x10, 0x00, 0x28, 0x14 },
    { gText_TownMap_MothersHillDescription, gText_TownMap_MothersHillLabel, MAP_MOTHERS_HILL_MIDDLE, 0x0497, 0x02F0, 0x00, 0x20, 0x40, 0x67 },
};

TownMapAreaLookup const gTownMapAreaLookup[TOWN_MAP_AREA_LOOKUP_COUNT] = {
        /* 0x00 */ { 0x00005C21, gTownMapAreaBounds.map_000 },
        /* 0x01 */ { 0x000034D3, gTownMapAreaBounds.map_001 },
        /* 0x02 */ { 0x00005054, nullptr },
        /* 0x03 */ { 0x00005E8C, gTownMapAreaBounds.map_003 },
        /* 0x04 */ { 0x00000CD0, nullptr },
        /* 0x05 */ { 0x00001C8E, gTownMapAreaBounds.map_005 },
        /* 0x06 */ { 0x000030B8, nullptr },
        /* 0x07 */ { 0x00003C8F, gTownMapAreaBounds.map_007 },
        /* 0x08 */ { 0x0000081B, nullptr },
        /* 0x09 */ { 0x00004462, nullptr },
        /* 0x0A */ { 0x0000417A, nullptr },
        /* 0x0B */ { 0x0000417A, nullptr },
        /* 0x0C */ { 0x00000BBF, nullptr },
        /* 0x0D */ { 0x000027D8, nullptr },
        /* 0x0E */ { 0x00000B66, nullptr },
        /* 0x0F */ { 0x00000B85, nullptr },
        /* 0x10 */ { 0x00000B85, nullptr },
        /* 0x11 */ { 0x00005344, nullptr },
        /* 0x12 */ { 0x0000310A, nullptr },
        /* 0x13 */ { 0x00000B9E, nullptr },
        /* 0x14 */ { 0x00000B9E, nullptr },
        /* 0x15 */ { 0x00001E82, nullptr },
        /* 0x16 */ { 0x00001E82, nullptr },
        /* 0x17 */ { 0x00001E82, nullptr },
        /* 0x18 */ { 0x00000B5B, nullptr },
        /* 0x19 */ { 0x00000B5B, nullptr },
        /* 0x1A */ { 0x00000B54, nullptr },
        /* 0x1B */ { 0x00000B54, nullptr },
        /* 0x1C */ { 0x000006DB, nullptr },
        /* 0x1D */ { 0x00004748, nullptr },
        /* 0x1E */ { 0x00000B72, nullptr },
        /* 0x1F */ { 0x00001E58, nullptr },
        /* 0x20 */ { 0x00001E58, nullptr },
        /* 0x21 */ { 0x00001A64, nullptr },
        /* 0x22 */ { 0x00001A64, nullptr },
        /* 0x23 */ { 0x000035E4, nullptr },
        /* 0x24 */ { 0x000027CB, nullptr },
        /* 0x25 */ { 0x0000445A, nullptr },
        /* 0x26 */ { 0x00003160, nullptr },
        /* 0x27 */ { 0x00003475, nullptr },
        /* 0x28 */ { 0x00005877, nullptr },
        /* 0x29 */ { 0x0000419D, nullptr },
        /* 0x2A */ { 0x0000419D, nullptr },
        /* 0x2B */ { 0x00004F0A, nullptr },
        /* 0x2C */ { 0x00000000, nullptr },
        /* 0x2D */ { 0x00000000, nullptr },
        /* 0x2E */ { 0x00000000, nullptr },
        /* 0x2F */ { 0x00000000, nullptr },
        /* 0x30 */ { 0x00000000, nullptr },
        /* 0x31 */ { 0x00000000, nullptr },
        /* 0x32 */ { 0x00000000, nullptr },
        /* 0x33 */ { 0x00000000, nullptr },
    };

TownMapAreaLookup const gTownMapAreaLookupFallback_034To133 = {
        0x00003F28,
        nullptr,
    };

TownMapAreaLookup const gTownMapAreaLookupFallback_134To233 = {
        0x00004F0A,
        nullptr,
    };


void GameScene::OpenTownMap(u8 allow_teleport)
{
    GameSceneState * current = state;
    current->pending_transition = new TownMapTransition(allow_teleport ? 2 : 0, current->GetSave());
    current->script_state = 0x18;
}

SceneOwner TownMapTransition::CreateScene()
{
    bool allow_teleport = false;
    if (mode == 2)
        allow_teleport = true;
    SceneTransition * next = result.release();
    return SceneOwner(new TownMapUiScene(save, SceneTransitionOwner(next), allow_teleport));
}

SceneOwner TownMapReturnTransition::CreateScene()
{
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_TOWN_MAP);
    switch (mode) {
    case 0:
        request = GameSceneResumeRequest(1);
        break;
    case 1:
        // This other native mode has its own regional resume kind.
#if defined(REGION_JP)
        request = GameSceneResumeRequest(4);
#else
        request = GameSceneResumeRequest(5);
#endif
        break;
    case 2:
        request.town_map_selection.has_selection = has_selection;
        if (has_selection) {
            request.town_map_selection.map = location.map;
            request.town_map_selection.x = location.x;
            request.town_map_selection.y = location.y;
        }
        break;
    }
    return SceneOwner(new GameScene(save, request));
}
