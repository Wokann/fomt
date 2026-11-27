#include "saved_map_graphics.hh"
#include "field_item_data.hh"

FieldRenderSeasonalRecordRange const gFieldRenderSeasonalRecordRanges[NUM_SEASONS] = {
        { FIELD_ITEM_RECORD_SPRING_BEGIN, FIELD_ITEM_RECORD_SPRING_END },
        { FIELD_ITEM_RECORD_SUMMER_BEGIN, FIELD_ITEM_RECORD_SUMMER_END },
        { FIELD_ITEM_RECORD_FALL_BEGIN, FIELD_ITEM_RECORD_FALL_END },
        { FIELD_ITEM_RECORD_WINTER_BEGIN, FIELD_ITEM_RECORD_WINTER_END },
    };


// func_080AAF28 indexes this as [native_record_index][variant].  The two
// columns are both consumed by the native field-render path, but their
// gameplay roles remain undecoded.
u16 const gUnk_FieldRenderLookupValues[18][2] = {
        { 0x0032, 0x0033 },
        { 0x0135, 0x0136 },
        { 0x0132, 0x0133 },
        { 0x00F5, 0x00F6 },
        { 0x0119, 0x011A },
        { 0x0041, 0x0042 },
        { 0x00D8, 0x00D9 },
        { 0x0178, 0x0179 },
        { 0x01EA, 0x01EB },
        { 0x0142, 0x0143 },
        { 0x0165, 0x0166 },
        { 0x0100, 0x0101 },
        { 0x01D9, 0x01DA },
        { 0x0008, 0x0009 },
        { 0x012F, 0x0130 },
        { 0x0151, 0x0152 },
        { 0x0110, 0x0111 },
        { 0x01C4, 0x01C5 },
    };

// These native readers use the real saved-image and map-selection APIs.
// Keep their implementation dependencies after the physically earlier tables.
#include "calendar.hh"
#include "world_saved_map.hh"
#include "game_state.hh"
#include "map_data.hh"
#include "map_selection.h"
#include "hardware_dma.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".include \"asm/gba.inc\"\n"
    ".align 2, 0\n"
);

u16 func_080AAF28(u32 record_index, u8 variant)
{
    return gUnk_FieldRenderLookupValues[record_index][variant];
}

asm_unified(
    "    .align 2, 0\n"
);

EC u32 SelectSavedWorldMapData(GameSceneSavedMap * map)
{
    u32 season = GetCalendarEffectiveSeason(map->save->clock.calendar);
    u32 house = map->save->farm.farm_house.GetUpgradeLevel();
    u32 coop = map->save->farm.coop.GetUpgradeLevel();
    u32 barn = map->save->farm.barn.GetUpgradeLevel();
    return SelectMapDataId(map->map, season, house, coop, barn);
}


asm_unified(
    ".text\n"
    ".align 2, 0\n"
);

#include "hardware_dma.hh"
void func_080AAF9C(GameSceneWorldMap * map, u32 enabled)
{
    if (enabled == 0)
        return;
    if (map->map != 2)
        return;
    CopyHardwareDma3(map->tile_attributes, (void *)enabled, 0xB000);
}

asm_unified(
    "    .align 2, 0\n"
);

#include "world_map.hh"
#include "map_data.hh"
u8 func_080AAFB8(GameSceneWorldMap * map)
{
    return GetMapData(map->map_data_id)->flags;
}

asm_unified(
    "    .align 2, 0\n"
);
