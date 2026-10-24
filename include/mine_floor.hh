#ifndef MINE_FLOOR_HH
#define MINE_FLOOR_HH

#include "prelude.h"

struct GameStateSaveImage;

// The initializer visits the complete 28x28 backing grid. Active width
// and height depend on layout_kind. The two six-bit fields are native mine
// item codes consumed by the dig/rock paths, not global ITEM_* identifiers.
struct PACKED ALIGN(2) MineFloorCell
{
    u32 type : 4;
    u32 rock_item : 6;
    u32 buried_item : 6;
};

// The generator supplies twelve four-byte exclusion records. Only column
// and row are consumed here; the remaining bytes are not identified.
struct MineFloorExcludedCell {
    u8 column;
    u8 row;
    u16 unk_02;
};

typedef char MineFloorExcludedCellSizeCheck[sizeof(MineFloorExcludedCell) == 4 ? 1 : -1];
typedef char MineFloorExcludedCellRowCheck[offsetof(MineFloorExcludedCell, row) == 1 ? 1 : -1];

struct MineFloorState
{
    MineFloorState();
    u32 GetSpringBuriedItemTableIndex(u32 floor) const;
    u32 GetSpringRockTableIndex(u32 floor) const;
    void PlaceLakeMineItems(u32 floor, i32 rock_count,
        MineFloorExcludedCell const * excluded);
    // Still a native Thumb body; no source-level table approximation.
    u32 GetLakeBuriedItemTableIndex(u32 floor) const;
    u32 GetLakeRockTableIndex(u32 floor) const;
    u32 GetLayoutKind() const;
    u32 GetWidth() const;
    u32 GetHeight() const;
    u32 GetCellType(u32 column, u32 row) const;
    // These return mine-local result codes, not global ITEM_* IDs. A revealed
    // down ladder is consumed by DigSoil and reported as zero to its caller.
    u32 DigSoil(u32 column, u32 row, GameStateSaveImage & game);
    u32 BreakRock(u32 column, u32 row, GameStateSaveImage & game);
    // Apply eligibility checks and their saved-state side effects.
    u32 ProcessItemCode(u32 code, GameStateSaveImage & game);
    bool HasCursedTool(u32 group, GameStateSaveImage const & game) const;
    // These count exactly the indicated saved bits; their item identities
    // are not yet established here and are deliberately not guessed.
    u8 CountFlags13To21() const;
    u8 CountFlags1To9() const;
    u16 const * GetCellTilemap(u32 column, u32 row) const;
    void CountCellValues(u8 * counts) const;
    // Native unchecked counts: lake buried/rock 5/10, spring 10/14, even
    // when these exceed a named table's length. No clearing, destination-ID
    // bounds check or mine-map validation is added to this original behavior.
    void CopyCurrentItemWeights(u8 * weights, GameStateSaveImage const & game) const;
    bool GetFlag0() const;
    bool GetFlag10() const;
    bool GetFlag11() const;
    bool GetFlag12() const;

    u32 layout_kind;
    MineFloorCell cells[28][28];
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

typedef char MineFloorCellSizeCheck[sizeof(MineFloorCell) == 2 ? 1 : -1];
typedef char MineFloorStateSizeCheck[sizeof(MineFloorState) == 0x628 ? 1 : -1];
typedef char MineFloorCellsCheck[offsetof(MineFloorState, cells) == 4 ? 1 : -1];
typedef char MineFloorCellEndCheck[offsetof(MineFloorState, cells) + sizeof(MineFloorCell) * 28 * 28 == 0x624 ? 1 : -1];

extern u16 const gMineFloorCellType0Tilemap[6];
extern u16 const gMineFloorCellType1Tilemap[6];
extern u16 const gMineFloorCellType2Tilemap[6];
extern u16 const gMineFloorCellType3Tilemap[6];
extern u16 const gMineFloorCellType4Tilemap[6];


extern "C" u32 const gLakeMineBuriedItemCodes[];
extern "C" u8 const gLakeMineBuriedItemWeights[][10];
extern "C" u32 const gLakeMineRockItemCodes[];
extern "C" u8 const gLakeMineRockItemWeights[][14];
extern "C" u32 const gSpringMineBuriedItemCodes[];
extern "C" u8 const gSpringMineBuriedItemWeights[][5];
extern "C" u32 const gSpringMineRockItemCodes[];
extern "C" u8 const gSpringMineRockItemWeights[][10];
extern char const gCppRuntimeBadAlloc_MineFloorTables[];

#endif // MINE_FLOOR_HH
