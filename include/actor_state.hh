#ifndef ACTOR_STATE_HH
#define ACTOR_STATE_HH

#include "prelude.h"

extern char const gCppRuntimeBadAlloc_ActorDataSelectionPrefix[];

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
extern char const gCppRuntimeBadAlloc_ActorDataSelectionTrailer[];
extern "C" FieldRenderPatchPlacement SelectMapFlagPatch(u32 const & flags, u32 index, bool winter);

#endif // ACTOR_STATE_HH
