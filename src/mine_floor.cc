#include "mine_floor.hh"
#include "game_state.hh"
#include "random.hh"
#include "unknown_inlines.hh"

// Lake-mine buried-item codes and the matching per-floor weight rows.
extern "C" u32 const gLakeMineBuriedItemCodes[] = {
    1, 2, 4, 5, 6, 7, 8, 9, 11, 3,
};

// Each weight column corresponds to gLakeMineBuriedItemCodes. The
// floor-group selector distinguishes the cursed-tool floors explicitly.
extern "C" u8 const gLakeMineBuriedItemWeights[][10] = {
    { 0x19, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00 },
    { 0x14, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00 },
    { 0x14, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x00 },
    { 0x14, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x00 },
    { 0x14, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00 },
    { 0x14, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00 },
    { 0x14, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00 },
    { 0x14, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00 },
    { 0x14, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00 },
    { 0x0A, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00 },
    { 0x14, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00 },
    { 0x1E, 0x4B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x32 },
    { 0x14, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00 },
    { 0x1E, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0A, 0x00 },
    { 0x14, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00 },
    { 0x1E, 0x37, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00 },
    { 0x14, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00 },
    { 0x1E, 0x3C, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00 },
    { 0x14, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00 },
    { 0x1E, 0x41, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x06, 0x00 },
    { 0x14, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00 },
    { 0x1E, 0x46, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x06, 0x00 },
    { 0x14, 0x4B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00 },
    { 0x1E, 0x2D, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00 },
    { 0x0F, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00 },
    { 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00 },
};

// Lake-mine rock item codes; each following weight row has one column
// per code. Codes remain native mine-domain values, not global item IDs.
extern "C" u32 const gLakeMineRockItemCodes[] = {
    0x21, 0x0C, 0x15, 0x16, 0x13, 0x14, 0x18,
    0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
};

// GetLakeRockTableIndex selects one fourteen-column row. Columns follow
// gLakeMineRockItemCodes; these are weights in the native item domain.
extern "C" u8 const gLakeMineRockItemWeights[][14] = {
    { 0x01, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x05, 0x0A, 0x14, 0x1E },
    { 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0A, 0x14, 0x1E, 0x32 },
    { 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 0x14, 0x1E, 0x32, 0x1E },
    { 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x0A, 0x1E, 0x32, 0x1E, 0x14 },
    { 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x14, 0x32, 0x1E, 0x14, 0x0A },
    { 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
    { 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x32, 0x14, 0x0A, 0x05, 0x01 },
    { 0x00, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x1E, 0x0A, 0x05, 0x01, 0x01 },
    { 0x00, 0x46, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
    { 0x00, 0x46, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x05, 0x14, 0x1E, 0x32, 0x46 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x0A, 0x1E, 0x32, 0x46, 0x32 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x14, 0x32, 0x46, 0x32, 0x1E },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x1E, 0x46, 0x32, 0x1E, 0x14 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x46, 0x1E, 0x14, 0x0A, 0x05 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x32, 0x14, 0x0A, 0x05, 0x03 },
    { 0x00, 0x32, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 },
    { 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 },
    { 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0A, 0x0A, 0x14, 0x1E, 0x5A },
    { 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0A, 0x14, 0x1E, 0x5A, 0x1E },
    { 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0A, 0x1E, 0x5A, 0x1E, 0x14 },
    { 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x14, 0x5A, 0x1E, 0x14, 0x0A },
    { 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x5A, 0x14, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5A, 0x1E, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x14, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x14, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x14, 0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x01, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0A, 0x14, 0x1E, 0x32, 0x5A },
    { 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0A, 0x1E, 0x32, 0x5A, 0x32 },
    { 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x14, 0x32, 0x5A, 0x32, 0x1E },
    { 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x1E, 0x5A, 0x32, 0x1E, 0x14 },
    { 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x5A, 0x1E, 0x14, 0x0A, 0x0A },
    { 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5A, 0x32, 0x14, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x0A, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x0A, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x0A, 0x01, 0x00, 0x00, 0x00, 0x32, 0x00, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x02, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x0A, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x1E, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x32, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x46, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x32, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x1E, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x1E, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x32, 0x0A, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x46, 0x0A, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 },
    { 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E },
    { 0x32, 0x00, 0x01, 0x01, 0x0A, 0x0A, 0x32, 0x32, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A },
};

// Spring-mine buried-item codes, followed by their per-floor-group weights.
extern "C" u32 const gSpringMineBuriedItemCodes[] = {
    1, 2, 11, 3, 34,
};

// GetSpringBuriedItemTableIndex selects a row with one column per code.
extern "C" u8 const gSpringMineBuriedItemWeights[][5] = {
    { 0x32, 0x28, 0x05, 0x00, 0x00 },
    { 0x32, 0x28, 0x0A, 0x00, 0x00 },
    { 0x19, 0x32, 0x0A, 0x00, 0x00 },
    { 0x19, 0x32, 0x0F, 0x00, 0x00 },
    { 0x19, 0x3C, 0x0F, 0x00, 0x00 },
    { 0x19, 0x3C, 0x14, 0x00, 0x00 },
    { 0x19, 0x46, 0x14, 0x00, 0x00 },
    { 0x19, 0x46, 0x19, 0x32, 0x00 },
    { 0x19, 0x50, 0x00, 0x00, 0x00 },
    { 0x19, 0x50, 0x00, 0x00, 0x00 },
    { 0x19, 0x5A, 0x00, 0x00, 0x00 },
    { 0x19, 0x5A, 0x00, 0x00, 0x00 },
    { 0x19, 0x63, 0x00, 0x00, 0x00 },
    { 0x19, 0x63, 0x0A, 0x00, 0x00 },
    { 0x00, 0x63, 0x63, 0x00, 0x32 },
};

// Spring-mine rock item codes, in the column order of the following rows.
extern "C" u32 const gSpringMineRockItemCodes[] = {
    0x0A, 0x20, 0x0C, 0x0D, 0x0E,
    0x0F, 0x10, 0x11, 0x12, 0x17,
};

// The native spring-mine rock selector yields the row index (0..20).
extern "C" u8 const gSpringMineRockItemWeights[][10] = {
    { 0x00, 0x00, 0x32, 0x32, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x32, 0x32, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x32, 0x32, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x28, 0x32, 0x19, 0x19, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x28, 0x32, 0x19, 0x19, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x1E, 0x32, 0x32, 0x19, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x1E, 0x32, 0x32, 0x19, 0x19, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x14, 0x32, 0x32, 0x19, 0x19, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x14, 0x32, 0x32, 0x32, 0x19, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x0A, 0x32, 0x32, 0x32, 0x19, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x0A, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x00 },
    { 0x00, 0x00, 0x05, 0x32, 0x32, 0x32, 0x32, 0x19, 0x19, 0x00 },
    { 0x00, 0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x32, 0x32, 0x00 },
    { 0x00, 0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x00 },
    { 0x00, 0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x32, 0x32, 0x00 },
    { 0x00, 0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x00 },
    { 0x00, 0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x32, 0x32, 0x00 },
    { 0x00, 0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x00 },
    { 0x00, 0x0A, 0x05, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x01 },
    { 0x00, 0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x01 },
    { 0x32, 0x00, 0x05, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x01 },
};

#include FOMT_TEXT_INCLUDE(mine_floor.cc)


// Initializing the 22 known flags preserves the two unknown upper bits at
// +0x626 and the padding at +0x627. Every cell's three fields are cleared.
MineFloorState::MineFloorState()
    : layout_kind(0),
      flag_624_0(false), flag_624_1(false), flag_624_2(false), flag_624_3(false),
      flag_624_4(false), flag_624_5(false), flag_624_6(false), flag_624_7(false),
      flag_625_0(false), flag_625_1(false), flag_625_2(false), flag_625_3(false),
      flag_625_4(false), flag_625_5(false), flag_625_6(false), flag_625_7(false),
      flag_626_0(false), flag_626_1(false), flag_626_2(false),
      flag_626_3(false), flag_626_4(false), flag_626_5(false)
{
    for (u32 row = 0; row < 28; ++row) {
        for (u32 column = 0; column < 28; ++column) {
            cells[row][column].type = 0;
            cells[row][column].rock_item = 0;
            cells[row][column].buried_item = 0;
        }
    }
}

MineFloorPosition MineFloorState::GenerateLayout(MaryMineKind mine_kind,
    u32 floor, MineFloorPosition const * input, u32 count)
{
    MineFloorPosition result;
    MineFloorPosition excluded[12];
    for (u32 row = 0; row < 28; ++row) {
        for (u32 column = 0; column < 28; ++column) {
            cells[row][column].type = 0;
            cells[row][column].rock_item = 0;
            cells[row][column].buried_item = 0;
        }
    }
    if (input != 0) {
        for (u32 index = 0; index < count; ++index)
            excluded[index] = input[index];
    }
    for (i32 index = 0; index < 12; ++index) {
        if (static_cast<u8>(excluded[index].column - 2) > 55)
            excluded[index].column = 0xFF;
        else
            excluded[index].column = (excluded[index].column - 2) >> 1;
        if (static_cast<u8>(excluded[index].row - 7) > 55)
            excluded[index].row = 0xFF;
        else
            excluded[index].row = (excluded[index].row - 7) >> 1;
    }
    i32 rocks;
    if (floor == 0) {
        layout_kind = 0;
        rocks = 20;
    } else if (floor == 9 && mine_kind == MINE_LAKE) {
        layout_kind = 4;
        rocks = 40;
    } else if (floor % 5 == 0) {
        layout_kind = 1;
        rocks = 300;
    } else if (floor % 3 == 0) {
        layout_kind = 2;
        rocks = 100;
    } else {
        layout_kind = 3;
        rocks = 30;
    }
    if (floor != 0) {
        i32 column = (rand() >> 8) % (GetWidth() - 2) + 1;
        i32 row = (rand() >> 8) % (GetHeight() - 2) + 1;
        cells[row][column].type = 3;
        i32 const direction = (rand() >> 8) & 3;
        if (direction & 2) {
            if (direction & 1)
                --column;
            else
                ++column;
        } else {
            if (direction & 1)
                --row;
            else
                ++row;
        }
        result.column = column;
        result.row = row;
        cells[result.row][result.column].type = 1;
    }
    if (mine_kind == MINE_SPRING)
        PlaceSpringMineItems(floor, rocks, excluded);
    else
        PlaceLakeMineItems(floor, rocks, excluded);
    if (floor != 0)
        cells[result.row][result.column].type = 0;
    return result;
}

void MineFloorState::PlaceSpringMineItems(u32 floor, i32 rock_count,
    MineFloorPosition const * excluded)
{
    u32 const width = GetWidth();
    u32 const height = GetHeight();
    u32 table = GetSpringBuriedItemTableIndex(floor);
    i32 const random_start = rand() >> 4;
    u32 const first = random_start % (height * width);
    for (u32 visit = 0; visit < (height * width); ++visit) {
        u32 index = first + visit;
        if (index >= (height * width))
            index -= (height * width);
        i32 const column = index % width;
        i32 const row = index / width;
        i32 const type = cells[row][column].type;
        if (type <= 1) {
            i32 random = (rand() >> 4) & 0xFF;
            for (i32 item_index = 0; item_index < 5; ++item_index) {
                if (gSpringMineBuriedItemWeights[table][item_index] != 0) {
                    if (random < gSpringMineBuriedItemWeights[table][item_index]) {
                        u32 item = gSpringMineBuriedItemCodes[item_index];
                        if (item == 1) {
                            if (row != 0 && row < height - 1
                                && column != 0 && column < width - 1) {
                                for (i32 near_row = row - 1; near_row < row + 2; ++near_row) {
                                    if (near_row < 0 || near_row >= static_cast<i32>(height))
                                        continue;
                                    for (i32 near_column = column - 1; near_column < column + 2; ++near_column) {
                                        // Preserve the native conjunction, not an intended bounds fix.
                                        if (near_column < 0 && near_column >= static_cast<i32>(width))
                                            continue;
                                        if (cells[near_row][near_column].type == 3) {
                                            item = 0;
                                            break;
                                        }
                                    }
                                    if (item == 0)
                                        break;
                                }
                            } else {
                                item = 0;
                            }
                        }
                        cells[row][column].buried_item = item;
                        break;
                    }
                    random -= gSpringMineBuriedItemWeights[table][item_index];
                    if (random < 0)
                        break;
                }
            }
        }
    }

    table = GetSpringRockTableIndex(floor);
    for (; rock_count > 0; --rock_count) {
        bool placed = false;
        for (i32 attempts = 1; attempts <= 9; ++attempts) {
            i32 const column = (rand() >> 8) % width;
            i32 const row = (rand() >> 8) % height;
            if (cells[row][column].type == 0) {
                placed = true;
                for (i32 index = 0; index < 12; ++index) {
                    if (excluded[index].column == column && excluded[index].row == row) {
                        placed = false;
                        break;
                    }
                }
                if (placed == true) {
                    cells[row][column].type = 4;
                    i32 random = (rand() >> 8) & 0xFF;
                    for (i32 item_index = 0; item_index < 10; ++item_index) {
                        if (gSpringMineRockItemWeights[table][item_index] != 0) {
                            if (random < gSpringMineRockItemWeights[table][item_index]) {
                                cells[row][column].rock_item = gSpringMineRockItemCodes[item_index];
                                break;
                            }
                            random -= gSpringMineRockItemWeights[table][item_index];
                            if (random < 0)
                                break;
                        }
                    }
                }
            }
            if (placed)
                break;
        }
    }
}

u32 MineFloorState::GetSpringBuriedItemTableIndex(u32 value) const
{
    u32 result = 0;

    if (value != 0)
    {
        if (value <= 9)
        {
            result = 1;
        }
        else if (value <= 0x63)
        {
            result = 2;
            u32 next = 0x14;
            if (value >= next)
            {
                do
                {
                    ++result;
                    next += 0x14;
                } while (next <= 0x63 && value >= next);
            }
        }
        else if (value == 0x64)
        {
            result = 7;
        }
        else if (value <= 0xF9)
        {
            result = 8;
            u32 next = 0x82;
            if (value >= next)
            {
                do
                {
                    ++result;
                    next += 0x1E;
                } while (next <= 0xF9 && value >= next);
            }
        }
        else
        {
            result = 0xE;
            if (value <= 0xFE)
                result = 0xD;
        }
    }

    return result;
}

// Selects one of the 21 spring-mine rock-weight rows.
u32 MineFloorState::GetSpringRockTableIndex(u32 floor) const
{
    u32 result;
    switch (floor) {
    case 20: result = 12; break;
    case 30: result = 14; break;
    case 40: result = 16; break;
    case 60:
    case 102:
    case 123:
    case 152:
    case 155:
    case 171:
    case 190:
    case 202:
    case 222:
        result = 18; break;
    case 255: result = 20; break;
    default:
        result = floor;
        if (floor > 10) {
            result = 11;
            if (floor > 19) {
                result = 13;
                if (floor > 29) {
                    result = 15;
                    if (floor > 39) {
                        result = 19;
                        if (floor <= 230)
                            result = 17;
                    }
                }
            }
        }
        break;
    }
    return result;
}

void MineFloorState::PlaceLakeMineItems(u32 floor, i32 rock_count,
    MineFloorPosition const * excluded)
{
    u32 const width = GetWidth();
    u32 const height = GetHeight();
    u32 table = GetLakeBuriedItemTableIndex(floor);
    i32 const random_start = rand() >> 4;
    u32 const first = random_start % (height * width);
    for (u32 visit = 0; visit < (height * width); ++visit) {
        u32 index = first + visit;
        if (index >= (height * width))
            index -= (height * width);
        i32 const column = index % width;
        i32 const row = index / width;
        i32 const type = cells[row][column].type;
        if (type <= 1) {
            i32 random = (rand() >> 4) & 0xFF;
            for (i32 item_index = 0; item_index < 10; ++item_index) {
                if (gLakeMineBuriedItemWeights[table][item_index] != 0) {
                    if (random < gLakeMineBuriedItemWeights[table][item_index]) {
                        u32 item = gLakeMineBuriedItemCodes[item_index];
                        if (item == 1) {
                            if (row != 0 && row < height - 1
                                && column != 0 && column < width - 1) {
                                for (i32 near_row = row - 1; near_row < row + 2; ++near_row) {
                                    if (near_row < 0 || near_row >= static_cast<i32>(height))
                                        continue;
                                    for (i32 near_column = column - 1; near_column < column + 2; ++near_column) {
                                        // Preserve the native conjunction, not an intended bounds fix.
                                        if (near_column < 0 && near_column >= static_cast<i32>(width))
                                            continue;
                                        if (cells[near_row][near_column].type == 3) {
                                            item = 0;
                                            break;
                                        }
                                    }
                                    if (item == 0)
                                        break;
                                }
                            } else {
                                item = 0;
                            }
                        }
                        cells[row][column].buried_item = item;
                        break;
                    }
                    random -= gLakeMineBuriedItemWeights[table][item_index];
                    if (random < 0)
                        break;
                }
            }
        }
    }

    table = GetLakeRockTableIndex(floor);
    for (; rock_count > 0; --rock_count) {
        bool placed = false;
        for (i32 attempts = 1; attempts <= 9; ++attempts) {
            i32 const column = (rand() >> 8) % width;
            i32 const row = (rand() >> 8) % height;
            if (cells[row][column].type == 0) {
                placed = true;
                for (i32 index = 0; index < 12; ++index) {
                    if (excluded[index].column == column && excluded[index].row == row) {
                        placed = false;
                        break;
                    }
                }
                if (placed == true) {
                    cells[row][column].type = 4;
                    i32 random = (rand() >> 8) & 0xFF;
                    for (i32 item_index = 0; item_index < 14; ++item_index) {
                        if (gLakeMineRockItemWeights[table][item_index] != 0) {
                            if (random < gLakeMineRockItemWeights[table][item_index]) {
                                cells[row][column].rock_item = gLakeMineRockItemCodes[item_index];
                                break;
                            }
                            random -= gLakeMineRockItemWeights[table][item_index];
                            if (random < 0)
                                break;
                        }
                    }
                }
            }
            if (placed)
                break;
        }
    }
}

u32 MineFloorState::GetLakeRockTableIndex(u32 value) const
{
    switch (value)
    {
    case 0xFF:
        return 0x37;
    case 0x1E:
    case 0x46:
    case 0x5A:
        return 0x1E;
    case 0x28:
    case 0x3C:
    case 0x50:
        return 0x1F;
    case 0x32:
    case 0x64:
    case 0x96:
    case 0xC8:
        return 0x20;
    case 0x6E:
    case 0x82:
    case 0xAA:
    case 0xBE:
        return 0x2A;
    case 0x78:
    case 0x8C:
    case 0xA0:
    case 0xB4:
        return 0x2B;
    }

    if (value <= 0x14)
        return value;
    if (value > 0xFA)
        return 0x36;
    if (value <= 0x63)
        return value % 10 + 0x14;
    if (value > 0xC7)
        return value % 10 + 0x2B;
    return value % 10 + 0x20;
}

u32 MineFloorState::GetLayoutKind() const
{
    return layout_kind;
}

u32 MineFloorState::GetWidth() const
{
    u32 result = 13;

    if (layout_kind == 1)
        result = 28;

    return result;
}

u32 MineFloorState::GetHeight() const
{
    u32 result = 6;

    if (layout_kind == 1)
        result = 28;
    else if (layout_kind == 2)
        result = 14;

    return result;
}

u32 MineFloorState::GetCellType(u32 column, u32 row) const
{
    return cells[row][column].type;
}

u32 MineFloorState::DigSoil(u32 column, u32 row, GameStateSaveImage & game)
{
    u32 result = 0;
    if (cells[row][column].type == 0) {
        result = ProcessItemCode(cells[row][column].buried_item, game);
        if (result == 1) {
            cells[row][column].type = 2;
            result = 0;
            for (i32 clear_row = 0; clear_row < static_cast<i32>(GetHeight()); ++clear_row) {
                for (i32 clear_column = 0; clear_column < static_cast<i32>(GetWidth()); ++clear_column) {
                    if (cells[clear_row][clear_column].buried_item == 1)
                        cells[clear_row][clear_column].buried_item = 0;
                }
            }
        } else {
            cells[row][column].type = 1;
        }
        cells[row][column].buried_item = 0;
    }
    return result;
}

u32 MineFloorState::BreakRock(u32 column, u32 row, GameStateSaveImage & game)
{
    u32 result = 0;
    if (cells[row][column].type == 4) {
        result = ProcessItemCode(cells[row][column].rock_item, game);
        cells[row][column].type = 0;
        cells[row][column].rock_item = 0;
    }
    return result;
}

u32 MineFloorState::ProcessItemCode(u32 code, GameStateSaveImage & game)
{
    // Both nine-piece collections share this availability/floor workspace.
    bool collection_blocked;
    i32 floor;
    switch (code) {
    case 3:
        if (game.farmer.GetLocation().map <= static_cast<i32>(MAP_SPRING_MINE_FLOOR_255)) {
            if (flag_625_2 == false) {
                flag_625_2 = true;
            } else {
                code = 0;
            }
        } else {
            if (flag_624_0 == false) {
                flag_624_0 = true;
            } else {
                code = 0;
            }
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9: {
        bool blocked = false;
        if (game.farmer.rucksack.GetFirstFreeToolSlot() == static_cast<u32>(-1))
            blocked = true;
        if (!game.npcs.saibara.HasCollectedAllMystrileTools())
            blocked = true;
        if (HasCursedTool(code, game))
            blocked = true;
        if (blocked == true) {
            code = 0;
        } else {
            u32 tool = ITEM_TOOL_NONE;
            switch (code) {
            case 4:
                tool = ITEM_TOOL_SICKLE_CURSED;
                break;
            case 5:
                tool = ITEM_TOOL_HOE_CURSED;
                break;
            case 6:
                tool = ITEM_TOOL_AXE_CURSED;
                break;
            case 7:
                tool = ITEM_TOOL_HAMMER_CURSED;
                break;
            case 8:
                tool = ITEM_TOOL_WATERING_CAN_CURSED;
                break;
            case 9:
                tool = ITEM_TOOL_FISHING_ROD_CURSED;
                break;
            }
            if (tool != ITEM_TOOL_NONE)
                game.cursed_tools.StartCurse(tool);
        }
        break;
    }
    case 10: {
        bool blocked = false;
        if (min_inl<u32 const &>(200, game.clock.calendar.GetYear()) <= 2)
            blocked = true;
        if (flag_625_4 == true)
            blocked = true;
        if (game.farmer.rucksack.GetFirstFreeToolSlot() == static_cast<u32>(-1))
            blocked = true;
        if (blocked)
            code = 0;
        else
            flag_625_4 = true;
        break;
    }
    case 23: {
        bool blocked = false;
        if (!game.cursed_tools.HaveBlessedAllTools())
            blocked = true;
        for (i32 group = 4; group <= 9; ++group) {
            if (HasCursedTool(group, game))
                blocked = true;
        }
        if (blocked == true)
            code = 0;
        break;
    }
    case 32: {
        collection_blocked = false;
        if (game.farm.farm_house.GetShelf() == 0)
            collection_blocked = true;
        if (CountFlags13To21() == 8
            && game.farmer.rucksack.GetFirstFreeToolSlot() == static_cast<u32>(-1))
            collection_blocked = true;
        if (!collection_blocked) {
            floor = game.farmer.GetLocation().map - static_cast<i32>(MAP_SPRING_MINE_FLOOR_0);
            switch (floor) {
            case 60:
                if (flag_625_5 == false) {
                    flag_625_5 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 102:
                if (flag_625_6 == false) {
                    flag_625_6 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 123:
                if (flag_625_7 == false) {
                    flag_625_7 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 152:
                if (flag_626_0 == false) {
                    flag_626_0 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 155:
                if (flag_626_1 == false) {
                    flag_626_1 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 171:
                if (flag_626_2 == false) {
                    flag_626_2 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 190:
                if (flag_626_3 == false) {
                    flag_626_3 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 202:
                if (flag_626_4 == false) {
                    flag_626_4 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 222:
                if (flag_626_5 == false) {
                    flag_626_5 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            default:
                collection_blocked = true;
                break;
            }
        }
        if (collection_blocked == true)
            code = 0;
        break;
    }
    case 33: {
        collection_blocked = false;
        if (game.farm.farm_house.GetShelf() == 0)
            collection_blocked = true;
        if (CountFlags1To9() == 8
            && game.farmer.rucksack.GetFirstFreeToolSlot() == static_cast<u32>(-1))
            collection_blocked = true;
        if (!collection_blocked) {
            floor = game.farmer.GetLocation().map - static_cast<i32>(MAP_LAKE_MINE_FLOOR_0);
            switch (floor) {
            case 0:
                if (flag_624_1 == false) {
                    flag_624_1 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 40:
                if (flag_624_2 == false) {
                    flag_624_2 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 60:
                if (flag_624_3 == false) {
                    flag_624_3 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 80:
                if (flag_624_4 == false) {
                    flag_624_4 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 120:
                if (flag_624_5 == false) {
                    flag_624_5 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 140:
                if (flag_624_6 == false) {
                    flag_624_6 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 160:
                if (flag_624_7 == false) {
                    flag_624_7 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 180:
                if (flag_625_0 == false) {
                    flag_625_0 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 255:
                if (flag_625_1 == false) {
                    flag_625_1 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            default:
                collection_blocked = true;
                break;
            }
        }
        if (collection_blocked == true)
            code = 0;
        break;
    }
    case 34:
        if (flag_625_3 == false) {
            flag_625_3 = true;
        } else {
            code = 0;
        }
        break;
    }
    return code;
}

bool MineFloorState::HasCursedTool(u32 group, GameStateSaveImage const & game) const
{
    bool available = false;
    i32 type = ITEM_TOOL_NONE;
    switch (group) {
    case 4: type = ITEM_TOOL_SICKLE_CURSED; break;
    case 5: type = ITEM_TOOL_HOE_CURSED; break;
    case 6: type = ITEM_TOOL_AXE_CURSED; break;
    case 7: type = ITEM_TOOL_HAMMER_CURSED; break;
    case 8: type = ITEM_TOOL_WATERING_CAN_CURSED; break;
    case 9: type = ITEM_TOOL_FISHING_ROD_CURSED; break;
    }
    if (type <= ITEM_TOOL_GEM_TRUTH) {
        if (game.farmer.rucksack.GetFirstSlotWithTool(type) != static_cast<u32>(-1))
            available = true;
        if (game.farm.farm_house.tool_chest.GetFirstSlotWith(type) != static_cast<u32>(-1))
            available = true;
    }
    return available;
}

u8 MineFloorState::CountFlags13To21() const
{
    u8 result = flag_625_5;
    if (flag_625_6)
        ++result;
    if (flag_625_7)
        ++result;
    if (flag_626_0)
        ++result;
    if (flag_626_1)
        ++result;
    if (flag_626_2)
        ++result;
    if (flag_626_3)
        ++result;
    if (flag_626_4)
        ++result;
    if (flag_626_5)
        ++result;
    return result;
}

u8 MineFloorState::CountFlags1To9() const
{
    u8 result = flag_624_1;
    if (flag_624_2)
        ++result;
    if (flag_624_3)
        ++result;
    if (flag_624_4)
        ++result;
    if (flag_624_5)
        ++result;
    if (flag_624_6)
        ++result;
    if (flag_624_7)
        ++result;
    if (flag_625_0)
        ++result;
    if (flag_625_1)
        ++result;
    return result;
}

u16 const * MineFloorState::GetCellTilemap(u32 column, u32 row) const
{
    u32 offset = row * sizeof(cells[0]) + offsetof(MineFloorState, cells);
    u8 const * bytes = reinterpret_cast<u8 const *>(this);
    bytes += offset;
    bytes += column * 2;
    u16 const value = *reinterpret_cast<u16 const *>(bytes);

    switch ((static_cast<u32>(value) << 28) >> 28)
    {
    case 0:
        return gMineFloorCellType0Tilemap;
    case 1:
        return gMineFloorCellType1Tilemap;
    case 2:
        return gMineFloorCellType2Tilemap;
    case 3:
        return gMineFloorCellType3Tilemap;
    case 4:
        return gMineFloorCellType4Tilemap;
    default:
        return 0;
    }
}

// Accumulate both six-bit cell values into the supplied counters. The
// original neither clears the counters nor checks byte overflow.
void MineFloorState::CountCellValues(u8 * counts) const
{
    for (u32 row = 0; row < GetHeight(); ++row) {
        for (u32 column = 0; column < GetWidth(); ++column) {
            ++counts[cells[row][column].rock_item];
            ++counts[cells[row][column].buried_item];
        }
    }
}

bool MineFloorState::GetFlag0() const
{
    return flag_624_0;
}

bool MineFloorState::GetFlag10() const
{
    return flag_625_2;
}

bool MineFloorState::GetFlag11() const
{
    return flag_625_3;
}

bool MineFloorState::GetFlag12() const
{
    return flag_625_4;
}

// Preserve the native copy counts, including the unvalidated spring-table
// overruns. This method neither clears weights nor validates destination IDs.
void MineFloorState::CopyCurrentItemWeights(u8 * weights, GameStateSaveImage const & game) const
{
    if (game.farmer.GetLocation().map > static_cast<i32>(MAP_SPRING_MINE_FLOOR_255)) {
        u32 floor = game.farmer.GetLocation().map - static_cast<i32>(MAP_LAKE_MINE_FLOOR_0);
        u32 index = GetLakeBuriedItemTableIndex(floor);
        for (i32 i = 0; i < 5; ++i)
            weights[gLakeMineBuriedItemCodes[i]] = gLakeMineBuriedItemWeights[index][i];

        index = GetLakeRockTableIndex(floor);
        for (i32 i = 0; i < 10; ++i)
            weights[gLakeMineRockItemCodes[i]] = gLakeMineRockItemWeights[index][i];
    } else {
        u32 floor = game.farmer.GetLocation().map - static_cast<i32>(MAP_SPRING_MINE_FLOOR_0);
        u32 index = GetSpringBuriedItemTableIndex(floor);
        for (i32 i = 0; i < 10; ++i)
            weights[gSpringMineBuriedItemCodes[i]] = gSpringMineBuriedItemWeights[index][i];

        index = GetSpringRockTableIndex(floor);
        for (i32 i = 0; i < 14; ++i)
            weights[gSpringMineRockItemCodes[i]] = gSpringMineRockItemWeights[index][i];
    }
}
