#ifndef FIELD_RENDER_FARM_HOUSE_DATA_HH
#define FIELD_RENDER_FARM_HOUSE_DATA_HH

#include "field_render_rect_descriptors.hh"

// QueueMapTilePatch reads the destination tile and source pointer from these
// records.  The two bytes after destination_tile are compiler alignment for
// the pointer, not an independently meaningful ROM field.
struct FarmHouseTilePatchDescriptor
{
    u16 destination_tile;
    u8 const * frame_data;
};

// The native frame stream begins with two halfwords; tile bytes follow.
struct MapTilePatchFrameHeader {
    u16 tiles_per_frame;
    u16 frame_count;
};

typedef char MapTilePatchFrameHeaderSizeCheck[sizeof(MapTilePatchFrameHeader) == 4 ? 1 : -1];
typedef char MapTilePatchFrameCountCheck[offsetof(MapTilePatchFrameHeader, frame_count) == 2 ? 1 : -1];

// Native timers compare elapsed updates against frame_duration at +0x08.
// The animation frame count is read from frame_data, not from this field.
// Pointer alignment and tail alignment are natural structure padding.
struct FarmHouseTilePatchAnimationDescriptor
{
    FarmHouseTilePatchDescriptor patch;
    u16 frame_duration;
};

typedef char MapTilePatchAnimationPrefixCheck[offsetof(FarmHouseTilePatchAnimationDescriptor, patch) == 0 ? 1 : -1];
typedef char MapTilePatchAnimationDescriptorSizeCheck[sizeof(FarmHouseTilePatchAnimationDescriptor) == 12 ? 1 : -1];
typedef char MapTilePatchAnimationDurationCheck[offsetof(FarmHouseTilePatchAnimationDescriptor, frame_duration) == 8 ? 1 : -1];

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

// These contiguous records follow gFarmHouseVisualDescriptors in ROM.
// Native drawing and timer updates address them independently, not through
// an indexed table. Keep neutral names until their visual roles are known.
extern FarmHouseTilePatchAnimationDescriptor const gMapTilePatchAnimation0;
extern FarmHouseTilePatchAnimationDescriptor const gMapTilePatchAnimation1;

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
