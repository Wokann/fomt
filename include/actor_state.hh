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

// The initializer visits 28 rows of 28 two-byte cells. The low four bits
// select the cell's data; the meanings of the remaining fields are unknown.
struct PACKED ALIGN(2) ActorStateGridCell
{
    u32 unk_00 : 4;
    u32 unk_04 : 6;
    u32 unk_0A : 6;
};

struct ActorStateGrid
{
    ActorStateGrid();

    u32 unk_00;
    ActorStateGridCell cells[28][28];
    bool flag_624_0 : 1;
    bool flag_624_1 : 1;
    bool flag_624_2 : 1;
    bool flag_624_3 : 1;
    bool flag_624_4 : 1;
    bool flag_624_5 : 1;
    bool flag_624_6 : 1;
    bool flag_624_7 : 1;
    bool flag_625_0 : 1;
    bool flag_625_1 : 1;
    bool flag_625_2 : 1;
    bool flag_625_3 : 1;
    bool flag_625_4 : 1;
    bool flag_625_5 : 1;
    bool flag_625_6 : 1;
    bool flag_625_7 : 1;
    bool flag_626_0 : 1;
    bool flag_626_1 : 1;
    bool flag_626_2 : 1;
    bool flag_626_3 : 1;
    bool flag_626_4 : 1;
    bool flag_626_5 : 1;
    bool unk_626_6 : 1;
    bool unk_626_7 : 1;
};

typedef char ActorStateGridCellSizeCheck[sizeof(ActorStateGridCell) == 2 ? 1 : -1];
typedef char ActorStateGridSizeCheck[sizeof(ActorStateGrid) == 0x628 ? 1 : -1];
typedef char ActorStateGridCellsCheck[offsetof(ActorStateGrid, cells) == 4 ? 1 : -1];
typedef char ActorStateGridCellEndCheck[offsetof(ActorStateGrid, cells) + sizeof(ActorStateGridCell) * 28 * 28 == 0x624 ? 1 : -1];

extern u8 const gActorStateGridCellType0Data[];
extern u8 const gActorStateGridCellType1Data[];
extern u8 const gActorStateGridCellType2Data[];
extern u8 const gActorStateGridCellType3Data[];
extern u8 const gActorStateGridCellType4Data[];

extern "C" u32 func_0809D8D4(ActorStateGrid const * grid, u32 column, u32 row);
extern "C" u8 func_0809DFAC(ActorStateGrid const & state);
extern "C" u8 func_0809E02C(ActorStateGrid const & state);
extern "C" u8 const * func_0809E0AC(ActorStateGrid const * grid, u32 column, u32 row);
extern "C" bool func_0809E174(ActorStateGrid const & state);
extern "C" bool func_0809E184(ActorStateGrid const & state);
extern "C" bool func_0809E194(ActorStateGrid const & state);
extern "C" bool func_0809E1A4(ActorStateGrid const & state);

#endif // ACTOR_STATE_HH
