#ifndef TOWN_MAP_HH
#define TOWN_MAP_HH

#include "prelude.h"

EXTERN_C

struct TownMapHotspot
{
    char const * primary_text;
    char const * alternate_text;
    u32 map_id;
    u16 map_x;
    u16 map_y;
    u8 min_cursor_x;
    u8 min_cursor_y;
    u8 max_cursor_x;
    u8 max_cursor_y;
};

struct TownMapAreaBounds;

enum
{
    TOWN_MAP_HOTSPOT_COUNT = 40,
    TOWN_MAP_AREA_LOOKUP_COUNT = 0x34,
};

struct TownMapAreaLookup
{
    u32 lookup_key;
    TownMapAreaBounds const * bounds;
};

extern TownMapHotspot const gTownMapHotspots[TOWN_MAP_HOTSPOT_COUNT];
extern u16 const gTownMapResourceIds[];
extern TownMapAreaLookup const gTownMapAreaLookup[TOWN_MAP_AREA_LOOKUP_COUNT];
extern TownMapAreaLookup const gTownMapAreaLookupFallback_034To133;
extern TownMapAreaLookup const gTownMapAreaLookupFallback_134To233;

void CopyBgMap30x13(void const *, u32 map_block, u16 const * source);

void CopyBgMapRect(
    void const *,
    u32 map_block,
    u32 x,
    u32 y,
    u32 width,
    u32 height,
    u16 const * source);

bool TownMapHotspotContains(
    void const *, u32 cursor_x, u32 cursor_y, TownMapHotspot const * hotspot);

EXTERN_C_END

extern char const gText_TownMap_PlayerFarmNameSuffix[];
extern char const gText_TownMap_PlayerFarmDescription[];
extern char const gText_TownMap_PlayerFarmLabel[];
extern char const gText_TownMap_MountainCottageLabel[];
extern char const gText_TownMap_SeasideCottageLabel[];
extern char const gText_TownMap_TownCottageLabel[];
extern char const gText_TownMap_TimeWindowSeasonDescription[];
extern char const gText_TownMap_TimeWindowDateDescription[];
extern char const gText_TownMap_TimeWindowDayDescription[];
extern char const gText_TownMap_TimeWindowTimeDescription[];
extern char const gText_TownMap_TimeWindowWeatherDescription[];
extern char const gText_TownMap_TimeWindowLabel[];
extern char const gText_TownMap_BasilHouseLabel[];
extern char const gText_TownMap_MaryLibraryDescription[];
extern char const gText_TownMap_MaryLibraryHours[];
extern char const gText_TownMap_EllenHouseLabel[];
extern char const gText_TownMap_MayorHouseLabel[];
extern char const gText_TownMap_SupermarketDescription[];
extern char const gText_TownMap_SupermarketHours[];
extern char const gText_TownMap_MineralClinicDescription[];
extern char const gText_TownMap_MineralClinicHours[];
extern char const gText_TownMap_ChurchDescription[];
extern char const gText_TownMap_ChurchHours[];
extern char const gText_TownMap_AjaWineryDescription[];
extern char const gText_TownMap_AjaWineryHours[];
extern char const gText_TownMap_DukeCellarLabel[];
extern char const gText_TownMap_DougsInnDescription[];
extern char const gText_TownMap_DougsInnHours[];
extern char const gText_TownMap_HarvestSpritesHomeDescription[];
extern char const gText_TownMap_HarvestSpritesHomeHours[];
extern char const gText_TownMap_ZackHouseDescription[];
extern char const gText_TownMap_ZackHouseLabel[];
extern char const gText_TownMap_KaiSeasideLodgeDescription[];
extern char const gText_TownMap_KaiSeasideLodgeHours[];
extern char const gText_TownMap_SaibaraBlacksmithDescription[];
extern char const gText_TownMap_SaibaraBlacksmithHours[];
extern char const gText_TownMap_YodelFarmDescription[];
extern char const gText_TownMap_YodelFarmHours[];
extern char const gText_TownMap_PoultryFarmDescription[];
extern char const gText_TownMap_PoultryFarmHours[];
extern char const gText_TownMap_WoodcutterHouseDescription[];
extern char const gText_TownMap_WoodcutterHouseHours[];
extern char const gText_TownMap_LakeMineDescription[];
extern char const gText_TownMap_LakeMineLabel[];
extern char const gText_TownMap_SpringMineDescription[];
extern char const gText_TownMap_SpringMineLabel[];
extern char const gText_TownMap_HotSpringDescription[];
extern char const gText_TownMap_HotSpringLabel[];
extern char const gText_TownMap_Empty[];
extern char const gText_TownMap_NorthMineralTownDescription[];
extern char const gText_TownMap_NorthMineralTownLabel[];
extern char const gText_TownMap_RearChurchDescription[];
extern char const gText_TownMap_RearChurchLabel[];
extern char const gText_TownMap_RoseSquareDescription[];
extern char const gText_TownMap_RoseSquareLabel[];
extern char const gText_TownMap_MineralBeachDescription[];
extern char const gText_TownMap_MineralBeachLabel[];
extern char const gText_TownMap_SouthMineralTownDescription[];
extern char const gText_TownMap_SouthMineralTownLabel[];
extern char const gText_TownMap_ForestDescription[];
extern char const gText_TownMap_ForestLabel[];
extern char const gText_TownMap_MothersHillPeakDescription[];
extern char const gText_TownMap_MothersHillPeakLabel[];
extern char const gText_TownMap_MothersHillDescription[];
extern char const gText_TownMap_MothersHillLabel[];

#endif // TOWN_MAP_HH
