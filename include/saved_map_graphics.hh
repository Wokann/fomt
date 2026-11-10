#ifndef SAVED_MAP_GRAPHICS_HH
#define SAVED_MAP_GRAPHICS_HH

#include "prelude.h"
#include "fomt_constants.hh"

struct GameSceneSavedMap;
struct GameSceneWorldMap;

// agbcp pads an ordinary two-u8 aggregate. The ROM stores each range in two
// bytes, so keep the necessary layout constraint directly at the type.
struct __attribute__((packed)) FieldRenderSeasonalRecordRange
{
    u8 first_record_index;
    u8 past_last_record_index;
};

extern FieldRenderSeasonalRecordRange const gFieldRenderSeasonalRecordRanges[NUM_SEASONS];
extern u16 const gUnk_FieldRenderLookupValues[18][2];

EXTERN_C
u16 func_080AAF28(u32 record_index, u8 variant);
u32 SelectSavedWorldMapData(GameSceneSavedMap * map);
void func_080AAF9C(GameSceneWorldMap * map, u32 enabled);
u8 func_080AAFB8(GameSceneWorldMap * map);
EXTERN_C_END

#endif // SAVED_MAP_GRAPHICS_HH
