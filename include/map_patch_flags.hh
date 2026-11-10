#ifndef MAP_PATCH_FLAGS_HH
#define MAP_PATCH_FLAGS_HH

#include "prelude.h"
#include <stl_bitset.h>

// Saved at +0x34D8. Indices 0 through 13 select the absent/present
// map patches below. Setting and clearing a flag preserve all other bits.
struct MapPatchFlags
{
    MapPatchFlags();
    bool IsClear(u32 index) const;
    void Set(u32 index);
    void Clear(u32 index);
    void ClearAll();

    std::bitset<14> value;
};

typedef char MapPatchFlagsSizeCheck[sizeof(MapPatchFlags) == 4 ? 1 : -1];


// Each flag selects an absent/present map rectangle at the stored tile position.
// The final two bytes of a row are natural four-byte alignment padding.
struct FieldRenderRectDescriptor;
struct FieldRenderPatchPlacement;
struct ActorDataSelectionEntry
{
    FieldRenderRectDescriptor const * absent_patch;
    FieldRenderRectDescriptor const * present_patch;
    u8 tile_x;
    u8 tile_y;
};

typedef char ActorDataSelectionEntrySizeCheck[sizeof(ActorDataSelectionEntry) == 12 ? 1 : -1];
typedef char ActorDataSelectionEntryXCheck[offsetof(ActorDataSelectionEntry, tile_x) == 8 ? 1 : -1];
typedef char ActorDataSelectionEntryYCheck[offsetof(ActorDataSelectionEntry, tile_y) == 9 ? 1 : -1];

extern ActorDataSelectionEntry const gActorDataSelectionEntries[];
extern "C" FieldRenderPatchPlacement SelectMapFlagPatch(MapPatchFlags const & flags, u32 index, bool winter);

#endif // MAP_PATCH_FLAGS_HH
