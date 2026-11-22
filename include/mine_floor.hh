#ifndef MINE_FLOOR_HH
#define MINE_FLOOR_HH

#include "prelude.h"
#include "fomt_constants.hh"

struct GameStateSaveImage;

enum MineFloorCellType {
    MINE_CELL_SOIL = 0,
    MINE_CELL_DUG_SOIL = 1,
    MINE_CELL_DOWN_LADDER = 2,
    MINE_CELL_UP_LADDER = 3,
    MINE_CELL_ROCK = 4,
};

// The initializer visits the complete 28x28 backing grid. Active width
// and height depend on layout_kind. The two six-bit fields are native mine
// item codes consumed by the dig/rock paths, not global ITEM_* identifiers.
struct PACKED ALIGN(2) MineFloorCell
{
    u32 type : 4;
    u32 rock_item : 6;
    u32 buried_item : 6;
};

// GenerateLayout converts occupied map-tile coordinates to mine-cell
// coordinates and returns its reserved neighboring cell. Only these two
// bytes are known fields; the old C++ ABI supplies the remaining padding.
struct MineFloorPosition {
    MineFloorPosition() : column(0), row(0) {}
    u8 column;
    u8 row;
};

struct MineFloorState
{
    MineFloorState();
    MineFloorPosition GenerateLayout(MaryMineKind mine_kind, u32 floor,
        MineFloorPosition const * input, u32 count);
    void PlaceSpringMineItems(u32 floor, i32 rock_count, MineFloorPosition const * excluded);
    u32 GetSpringBuriedItemTableIndex(u32 floor) const;
    u32 GetSpringRockTableIndex(u32 floor) const;
    void PlaceLakeMineItems(u32 floor, i32 rock_count,
        MineFloorPosition const * excluded);
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
    bool HasCursedTool(u32 mine_item_code, GameStateSaveImage const & game) const;
    // Count persisted jewel discovery bits, not current inventory objects.
    u8 CountHarvestGoddessJewels() const;
    u8 CountKappaJewels() const;
    u16 const * GetCellTilemap(u32 column, u32 row) const;
    void AccumulateCellItemCounts(u8 * counts) const;
    // BUGFIX corrects the mine selection and fixed copy counts.
    // The caller supplies a mine location and a buffer indexed by mine-local item code.
    void CopyCurrentItemWeights(u8 * weights, GameStateSaveImage const & game) const;
    bool HasFoundLakeMinePowerBerry() const;
    bool HasFoundSpringMinePowerBerry() const;
    bool HasFoundLithograph() const;
    bool HasFoundTeleportStone() const;

    u32 layout_kind;
    MineFloorCell cells[28][28];
    // Persisted discovery flags start at 0x624 in the original save layout.
    bool found_lake_mine_power_berry : 1;
    bool found_kappa_jewel_floor_0 : 1;
    bool found_kappa_jewel_b40 : 1;
    bool found_kappa_jewel_b60 : 1;
    bool found_kappa_jewel_b80 : 1;
    bool found_kappa_jewel_b120 : 1;
    bool found_kappa_jewel_b140 : 1;
    bool found_kappa_jewel_b160 : 1;
    bool found_kappa_jewel_b180 : 1;
    bool found_kappa_jewel_b255 : 1;
    bool found_spring_mine_power_berry : 1;
    bool found_lithograph : 1;
    bool found_teleport_stone : 1;
    bool found_goddess_jewel_b60 : 1;
    bool found_goddess_jewel_b102 : 1;
    bool found_goddess_jewel_b123 : 1;
    bool found_goddess_jewel_b152 : 1;
    bool found_goddess_jewel_b155 : 1;
    bool found_goddess_jewel_b171 : 1;
    bool found_goddess_jewel_b190 : 1;
    bool found_goddess_jewel_b202 : 1;
    bool found_goddess_jewel_b222 : 1;
    bool unk_626_6 : 1;
    bool unk_626_7 : 1;
};

// Two columns across three rows; the first row is written to a separate layer.
extern u16 const gMineFloorSoilTilemap[6];
extern u16 const gMineFloorDugSoilTilemap[6];
extern u16 const gMineFloorDownLadderTilemap[6];
extern u16 const gMineFloorUpLadderTilemap[6];
extern u16 const gMineFloorRockTilemap[6];

#endif // MINE_FLOOR_HH
