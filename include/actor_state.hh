#ifndef ACTOR_STATE_HH
#define ACTOR_STATE_HH

#include "prelude.h"

// Three parallel six-entry state arrays used by the actor-state helpers.
struct ActorStateSlots
{
    u8 unk_00[6];
    u8 unk_06[6];
    u8 unk_0C[6];
};

extern u8 const gActorStateMaxValues[];
extern "C" u32 func_0809C3E0(ActorStateSlots & self, u32 index);
extern char const gCppRuntimeBadAlloc_ActorDataSelectionPrefix[];

// func_0809C510 selects one of the two unknown data pointers in each row and
// copies unk_08 and unk_09 into its three-word output.  The pointed-to data
// has not been identified yet.
struct ActorDataSelectionEntry
{
    u8 const * unk_00;
    u8 const * unk_04;
    u8 unk_08;
    u8 unk_09;
    u16 unk_0A;
};

extern ActorDataSelectionEntry const gActorDataSelectionEntries[];
extern char const gCppRuntimeBadAlloc_ActorDataSelectionTrailer[];

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
