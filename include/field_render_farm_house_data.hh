#ifndef FIELD_RENDER_FARM_HOUSE_DATA_HH
#define FIELD_RENDER_FARM_HOUSE_DATA_HH

#include "field_render_rect_descriptors.hh"

// func_080A5AB0 reads the destination tile and source pointer from these
// records.  The two bytes after destination_tile are compiler alignment for
// the pointer, not an independently meaningful ROM field.
struct FarmHouseTilePatchDescriptor
{
    u16 destination_tile;
    u8 const * frame_data;
};

// Callers additionally read frame_count at +0x08.  As above, both the
// pointer alignment and tail alignment are natural structure padding.
struct FarmHouseTilePatchAnimationDescriptor
{
    u16 destination_tile;
    u8 const * frame_data;
    u16 frame_count;
};

// The numeric group names deliberately describe only the four physically
// contiguous ROM groups.  The still-native callers do not prove a stronger
// gameplay-specific subdivision yet.
struct FarmHouseTilePatchData
{
    FarmHouseTilePatchDescriptor group0[7];
    FarmHouseTilePatchAnimationDescriptor animation_group0[4];
    FarmHouseTilePatchDescriptor group1[3];
    FarmHouseTilePatchAnimationDescriptor animation_group1[14];
};

extern FarmHouseTilePatchData const gFarmHouseTilePatchData;

// These are the two contiguous animation descriptors following
// gFarmHouseVisualDescriptors in ROM.  Their neutral table name deliberately
// avoids assigning a stronger gameplay role before the neighboring raw data
// has been recovered.
extern FarmHouseTilePatchAnimationDescriptor const gFarmHouseTilePatchAnimations[2];

// These records start with the exact 0x18-byte tile-patch layout consumed by
// func_080A5BD8.  Native setup also passes unk_18 to Unpack and derives a VRAM
// destination from unk_1C.  The remaining resource fields are preserved with
// deliberately neutral names until their higher-level roles are recovered.
struct FarmHouseVisualDescriptor
{
    FieldRenderRectDescriptor tile_patch;
    u8 const * unk_18;
    u32 unk_1C;
    u8 const * unk_20[2];
    u8 unk_28;
    u8 unk_29;
};

extern FarmHouseVisualDescriptor const gFarmHouseVisualDescriptors[7];

#endif // FIELD_RENDER_FARM_HOUSE_DATA_HH
