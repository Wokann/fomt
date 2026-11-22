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
    "thumb_func_start func_080AAF28\n"
    "func_080AAF28:\n"
    "lsls r1, r1, #0x18\n"
    "ldr r2, .Lsaved_map_tree_reset_after_00f4\n"
    "lsrs r1, r1, #0x17\n"
    "lsls r0, r0, #2\n"
    "adds r1, r1, r0\n"
    "adds r1, r1, r2\n"
    "ldrh r0, [r1]\n"
    "bx lr\n"
    ".align 2, 0\n"
    ".Lsaved_map_tree_reset_after_00f4: .word gUnk_FieldRenderLookupValues\n"
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
    "thumb_func_start func_080AAF9C\n"
    "func_080AAF9C:\n"
    "push {lr}\n"
    "adds r2, r0, #0\n"
    "cmp r1, #0\n"
    "beq .Lworld_map_tail_0018\n"
    "ldr r0, [r2]\n"
    "cmp r0, #2\n"
    "bne .Lworld_map_tail_0018\n"
    "ldr r0, [r2, #0x2c]\n"
    "movs r2, #0xb0\n"
    "lsls r2, r2, #8\n"
    "bl CopyHardwareDma3\n"
    ".Lworld_map_tail_0018:\n"
    "pop {r0}\n"
    "bx r0\n"
    "thumb_func_start func_080AAFB8\n"
    "func_080AAFB8:\n"
    "push {lr}\n"
    "ldr r0, [r0, #4]\n"
    "bl GetMapData\n"
    "adds r0, #0x24\n"
    "ldrb r0, [r0]\n"
    "pop {r1}\n"
    "bx r1\n"
);
