#include "time_of_day.hh"
#include "mine_floor.hh"
#include "mine_floor_items.h"
#include "mine_weight_rows.h"
#include "mine_item_codes.h"
#include "game_state.hh"
#include "random.hh"
#include "unknown_inlines.hh"

enum MineLayoutKind {
    MINE_LAYOUT_TOP_FLOOR = 0,
    MINE_LAYOUT_LARGE = 1,
    MINE_LAYOUT_MEDIUM = 2,
    MINE_LAYOUT_SMALL = 3,
    MINE_LAYOUT_LAKE_B9 = 4,
};

enum {
    MINE_DEFAULT_WIDTH = 13,
    MINE_DEFAULT_HEIGHT = 6,
    MINE_MEDIUM_HEIGHT = 14,
    MINE_LARGE_FLOOR_INTERVAL = 5,
    MINE_MEDIUM_FLOOR_INTERVAL = 3,
    MINE_TOP_FLOOR_ROCK_TARGET = 20,
    MINE_LARGE_FLOOR_ROCK_TARGET = 300,
    MINE_MEDIUM_FLOOR_ROCK_TARGET = 100,
    MINE_SMALL_FLOOR_ROCK_TARGET = 30,
    MINE_LAKE_B9_ROCK_TARGET = 40,
    MINE_ROCK_PLACEMENT_ATTEMPTS = 9,
};

enum {
    MINE_EXCLUDED_POSITION_COUNT = 12,
    MINE_FIRST_TILE_COLUMN = 2,
    MINE_FIRST_TILE_ROW = 7,
    MINE_TILES_PER_CELL_SHIFT = 1,
    MINE_INVALID_CELL_COORDINATE = 0xFF,
};

enum {
    MINE_SOIL_RANDOM_SHIFT = 4,
    MINE_ROCK_RANDOM_SHIFT = 8,
    MINE_POSITION_RANDOM_SHIFT = 8,
    MINE_WEIGHT_DRAW_MASK = 0xFF,
    MINE_NEIGHBOR_NEGATIVE = 1,
    MINE_NEIGHBOR_HORIZONTAL = 2,
    MINE_NEIGHBOR_DIRECTION_MASK = MINE_NEIGHBOR_NEGATIVE | MINE_NEIGHBOR_HORIZONTAL,
};

enum { TELEPORT_STONE_FIRST_YEAR = 3 };

// Initializing the 22 known flags preserves the two unknown upper bits at
// +0x626 and the padding at +0x627. Every cell's three fields are cleared.
MineFloorState::MineFloorState()
    : layout_kind(MINE_LAYOUT_TOP_FLOOR),
      found_lake_mine_power_berry(false), found_kappa_jewel_floor_0(false),
      found_kappa_jewel_b40(false), found_kappa_jewel_b60(false),
      found_kappa_jewel_b80(false), found_kappa_jewel_b120(false),
      found_kappa_jewel_b140(false), found_kappa_jewel_b160(false),
      found_kappa_jewel_b180(false), found_kappa_jewel_b255(false),
      found_spring_mine_power_berry(false), found_lithograph(false),
      found_teleport_stone(false), found_goddess_jewel_b60(false),
      found_goddess_jewel_b102(false), found_goddess_jewel_b123(false),
      found_goddess_jewel_b152(false), found_goddess_jewel_b155(false),
      found_goddess_jewel_b171(false), found_goddess_jewel_b190(false),
      found_goddess_jewel_b202(false), found_goddess_jewel_b222(false)
{
    for (u32 row = 0; row < ARRAY_COUNT(cells); ++row) {
        for (u32 column = 0; column < ARRAY_COUNT(cells[row]); ++column) {
            cells[row][column].type = MINE_CELL_SOIL;
            cells[row][column].rock_item = MINE_ITEM_NONE;
            cells[row][column].buried_item = MINE_ITEM_NONE;
        }
    }
}

MineFloorPosition MineFloorState::GenerateLayout(MaryMineKind mine_kind,
    u32 floor, MineFloorPosition const * input, u32 count)
{
    MineFloorPosition result;
    MineFloorPosition excluded[MINE_EXCLUDED_POSITION_COUNT];
    for (u32 row = 0; row < ARRAY_COUNT(cells); ++row) {
        for (u32 column = 0; column < ARRAY_COUNT(cells[row]); ++column) {
            cells[row][column].type = MINE_CELL_SOIL;
            cells[row][column].rock_item = MINE_ITEM_NONE;
            cells[row][column].buried_item = MINE_ITEM_NONE;
        }
    }
    if (input != 0) {
        for (u32 index = 0; index < count; ++index)
            excluded[index] = input[index];
    }
    // The exclusions arrive in map tiles. Convert in-bounds coordinates into mine cells.
    for (i32 index = 0; index < MINE_EXCLUDED_POSITION_COUNT; ++index) {
        if (static_cast<u8>(excluded[index].column - MINE_FIRST_TILE_COLUMN)
            > (ARRAY_COUNT(cells[0]) << MINE_TILES_PER_CELL_SHIFT) - 1)
            excluded[index].column = MINE_INVALID_CELL_COORDINATE;
        else
            excluded[index].column = (excluded[index].column - MINE_FIRST_TILE_COLUMN) >> MINE_TILES_PER_CELL_SHIFT;
        if (static_cast<u8>(excluded[index].row - MINE_FIRST_TILE_ROW)
            > (ARRAY_COUNT(cells) << MINE_TILES_PER_CELL_SHIFT) - 1)
            excluded[index].row = MINE_INVALID_CELL_COORDINATE;
        else
            excluded[index].row = (excluded[index].row - MINE_FIRST_TILE_ROW) >> MINE_TILES_PER_CELL_SHIFT;
    }
    i32 rock_target;
    if (floor == 0) {
        layout_kind = MINE_LAYOUT_TOP_FLOOR;
        rock_target = MINE_TOP_FLOOR_ROCK_TARGET;
    } else if (floor == 9 && mine_kind == MINE_LAKE) {
        layout_kind = MINE_LAYOUT_LAKE_B9;
        rock_target = MINE_LAKE_B9_ROCK_TARGET;
    } else if (floor % MINE_LARGE_FLOOR_INTERVAL == 0) {
        layout_kind = MINE_LAYOUT_LARGE;
        rock_target = MINE_LARGE_FLOOR_ROCK_TARGET;
    } else if (floor % MINE_MEDIUM_FLOOR_INTERVAL == 0) {
        layout_kind = MINE_LAYOUT_MEDIUM;
        rock_target = MINE_MEDIUM_FLOOR_ROCK_TARGET;
    } else {
        layout_kind = MINE_LAYOUT_SMALL;
        rock_target = MINE_SMALL_FLOOR_ROCK_TARGET;
    }
    if (floor != 0) {
        // Place the up ladder inside the border, then pick a cardinal neighbor.
        i32 column = (rand() >> MINE_POSITION_RANDOM_SHIFT) % (GetWidth() - 2) + 1;
        i32 row = (rand() >> MINE_POSITION_RANDOM_SHIFT) % (GetHeight() - 2) + 1;
        cells[row][column].type = MINE_CELL_UP_LADDER;
        i32 const direction = (rand() >> MINE_POSITION_RANDOM_SHIFT) & MINE_NEIGHBOR_DIRECTION_MASK;
        if (direction & MINE_NEIGHBOR_HORIZONTAL) {
            if (direction & MINE_NEIGHBOR_NEGATIVE)
                --column;
            else
                ++column;
        } else {
            if (direction & MINE_NEIGHBOR_NEGATIVE)
                --row;
            else
                ++row;
        }
        result.column = column;
        result.row = row;
        // Temporarily leave this cell eligible for buried items and reserve it from rocks.
        cells[result.row][result.column].type = MINE_CELL_DUG_SOIL;
    }
    if (mine_kind == MINE_SPRING)
        PlaceSpringMineItems(floor, rock_target, excluded);
    else
        PlaceLakeMineItems(floor, rock_target, excluded);
    if (floor != 0)
        cells[result.row][result.column].type = MINE_CELL_SOIL;
    return result;
}

void MineFloorState::PlaceSpringMineItems(u32 floor, i32 rock_count,
    MineFloorPosition const * excluded)
{
    u32 const width = GetWidth();
    u32 const height = GetHeight();
    u32 weight_row = GetSpringBuriedItemTableIndex(floor);
    i32 const random_start = rand() >> MINE_SOIL_RANDOM_SHIFT;
    u32 const first = random_start % (height * width);
    for (u32 visit = 0; visit < (height * width); ++visit) {
        u32 index = first + visit;
        if (index >= (height * width))
            index -= (height * width);
        i32 const column = index % width;
        i32 const row = index / width;
        i32 const type = cells[row][column].type;
        if (type <= MINE_CELL_DUG_SOIL) {
            i32 roll = (rand() >> MINE_SOIL_RANDOM_SHIFT) & MINE_WEIGHT_DRAW_MASK;
            for (i32 item_index = 0; item_index < static_cast<i32>(sizeof(SpringMineBuriedWeightRow)); ++item_index) {
                if (gSpringMineBuriedItemWeights.bytes[weight_row][item_index] != 0) {
                    if (roll < gSpringMineBuriedItemWeights.bytes[weight_row][item_index]) {
                        u32 item = gSpringMineBuriedItemCodes[item_index];
                        if (item == MINE_ITEM_DOWN_LADDER) {
                            if (row != 0 && row < height - 1
                                && column != 0 && column < width - 1) {
                                for (i32 near_row = row - 1; near_row < row + 2; ++near_row) {
                                    if (near_row < 0 || near_row >= static_cast<i32>(height))
                                        continue;
                                    for (i32 near_column = column - 1; near_column < column + 2; ++near_column) {
                                        // Preserve the native conjunction, not an intended bounds fix.
                                        if (near_column < 0 && near_column >= static_cast<i32>(width))
                                            continue;
                                        if (cells[near_row][near_column].type == MINE_CELL_UP_LADDER) {
                                            item = MINE_ITEM_NONE;
                                            break;
                                        }
                                    }
                                    if (item == MINE_ITEM_NONE)
                                        break;
                                }
                            } else {
                                item = MINE_ITEM_NONE;
                            }
                        }
                        cells[row][column].buried_item = item;
                        break;
                    }
                    roll -= gSpringMineBuriedItemWeights.bytes[weight_row][item_index];
                    if (roll < 0)
                        break;
                }
            }
        }
    }

    weight_row = GetSpringRockTableIndex(floor);
    for (; rock_count > 0; --rock_count) {
        bool placed = false;
        for (i32 attempts = 1; attempts <= MINE_ROCK_PLACEMENT_ATTEMPTS; ++attempts) {
            i32 const column = (rand() >> MINE_POSITION_RANDOM_SHIFT) % width;
            i32 const row = (rand() >> MINE_POSITION_RANDOM_SHIFT) % height;
            if (cells[row][column].type == MINE_CELL_SOIL) {
                placed = true;
                for (i32 index = 0; index < MINE_EXCLUDED_POSITION_COUNT; ++index) {
                    if (excluded[index].column == column && excluded[index].row == row) {
                        placed = false;
                        break;
                    }
                }
                if (placed == true) {
                    cells[row][column].type = MINE_CELL_ROCK;
                    i32 roll = (rand() >> MINE_ROCK_RANDOM_SHIFT) & MINE_WEIGHT_DRAW_MASK;
                    for (i32 item_index = 0; item_index < static_cast<i32>(sizeof(SpringMineRockWeightRow)); ++item_index) {
                        if (gSpringMineRockItemWeights.bytes[weight_row][item_index] != 0) {
                            if (roll < gSpringMineRockItemWeights.bytes[weight_row][item_index]) {
                                cells[row][column].rock_item = gSpringMineRockItemCodes[item_index];
                                break;
                            }
                            roll -= gSpringMineRockItemWeights.bytes[weight_row][item_index];
                            if (roll < 0)
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

u32 MineFloorState::GetSpringBuriedItemTableIndex(u32 floor) const
{
    u32 result = SPRING_BURIED_ROW_ENTRY;

    if (floor != 0)
    {
        if (floor <= 9)
        {
            result = SPRING_BURIED_ROW_B1_B9;
        }
        else if (floor <= 99)
        {
            result = SPRING_BURIED_ROW_B10_B19;
            u32 next = 20;
            if (floor >= next)
            {
                do
                {
                    ++result;
                    next += 20;
                } while (next <= 99 && floor >= next);
            }
        }
        else if (floor == 100)
        {
            result = SPRING_BURIED_ROW_B100;
        }
        else if (floor <= 249)
        {
            result = SPRING_BURIED_ROW_B101_B129;
            u32 next = 130;
            if (floor >= next)
            {
                do
                {
                    ++result;
                    next += 30;
                } while (next <= 249 && floor >= next);
            }
        }
        else
        {
            result = SPRING_BURIED_ROW_B255;
            if (floor <= 254)
                result = SPRING_BURIED_ROW_B250_B254;
        }
    }

    return result;
}

// Selects one of the 21 spring-mine rock-weight rows.
u32 MineFloorState::GetSpringRockTableIndex(u32 floor) const
{
    u32 result;
    switch (floor) {
    case 20: result = SPRING_ROCK_ROW_B20; break;
    case 30: result = SPRING_ROCK_ROW_B30; break;
    case 40: result = SPRING_ROCK_ROW_B40; break;
    case 60:
    case 102:
    case 123:
    case 152:
    case 155:
    case 171:
    case 190:
    case 202:
    case 222:
        result = SPRING_ROCK_ROW_GODDESS_JEWEL_FLOORS; break;
    case 255: result = SPRING_ROCK_ROW_B255; break;
    default:
        result = floor;
        if (floor > 10) {
            result = SPRING_ROCK_ROW_B11_B19;
            if (floor > 19) {
                result = SPRING_ROCK_ROW_B21_B29;
                if (floor > 29) {
                    result = SPRING_ROCK_ROW_B31_B39;
                    if (floor > 39) {
                        result = SPRING_ROCK_ROW_B231_B254;
                        if (floor <= 230)
                            result = SPRING_ROCK_ROW_B41_B230;
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
    u32 weight_row = GetLakeBuriedItemTableIndex(floor);
    i32 const random_start = rand() >> MINE_SOIL_RANDOM_SHIFT;
    u32 const first = random_start % (height * width);
    for (u32 visit = 0; visit < (height * width); ++visit) {
        u32 index = first + visit;
        if (index >= (height * width))
            index -= (height * width);
        i32 const column = index % width;
        i32 const row = index / width;
        i32 const type = cells[row][column].type;
        if (type <= MINE_CELL_DUG_SOIL) {
            i32 roll = (rand() >> MINE_SOIL_RANDOM_SHIFT) & MINE_WEIGHT_DRAW_MASK;
            for (i32 item_index = 0; item_index < static_cast<i32>(sizeof(LakeMineBuriedWeightRow)); ++item_index) {
                if (gLakeMineBuriedItemWeights.bytes[weight_row][item_index] != 0) {
                    if (roll < gLakeMineBuriedItemWeights.bytes[weight_row][item_index]) {
                        u32 item = gLakeMineBuriedItemCodes[item_index];
                        if (item == MINE_ITEM_DOWN_LADDER) {
                            if (row != 0 && row < height - 1
                                && column != 0 && column < width - 1) {
                                for (i32 near_row = row - 1; near_row < row + 2; ++near_row) {
                                    if (near_row < 0 || near_row >= static_cast<i32>(height))
                                        continue;
                                    for (i32 near_column = column - 1; near_column < column + 2; ++near_column) {
                                        // Preserve the native conjunction, not an intended bounds fix.
                                        if (near_column < 0 && near_column >= static_cast<i32>(width))
                                            continue;
                                        if (cells[near_row][near_column].type == MINE_CELL_UP_LADDER) {
                                            item = MINE_ITEM_NONE;
                                            break;
                                        }
                                    }
                                    if (item == MINE_ITEM_NONE)
                                        break;
                                }
                            } else {
                                item = MINE_ITEM_NONE;
                            }
                        }
                        cells[row][column].buried_item = item;
                        break;
                    }
                    roll -= gLakeMineBuriedItemWeights.bytes[weight_row][item_index];
                    if (roll < 0)
                        break;
                }
            }
        }
    }

    weight_row = GetLakeRockTableIndex(floor);
    for (; rock_count > 0; --rock_count) {
        bool placed = false;
        for (i32 attempts = 1; attempts <= MINE_ROCK_PLACEMENT_ATTEMPTS; ++attempts) {
            i32 const column = (rand() >> MINE_POSITION_RANDOM_SHIFT) % width;
            i32 const row = (rand() >> MINE_POSITION_RANDOM_SHIFT) % height;
            if (cells[row][column].type == MINE_CELL_SOIL) {
                placed = true;
                for (i32 index = 0; index < MINE_EXCLUDED_POSITION_COUNT; ++index) {
                    if (excluded[index].column == column && excluded[index].row == row) {
                        placed = false;
                        break;
                    }
                }
                if (placed == true) {
                    cells[row][column].type = MINE_CELL_ROCK;
                    i32 roll = (rand() >> MINE_ROCK_RANDOM_SHIFT) & MINE_WEIGHT_DRAW_MASK;
                    for (i32 item_index = 0; item_index < static_cast<i32>(sizeof(LakeMineRockWeightRow)); ++item_index) {
                        if (gLakeMineRockItemWeights.bytes[weight_row][item_index] != 0) {
                            if (roll < gLakeMineRockItemWeights.bytes[weight_row][item_index]) {
                                cells[row][column].rock_item = gLakeMineRockItemCodes[item_index];
                                break;
                            }
                            roll -= gLakeMineRockItemWeights.bytes[weight_row][item_index];
                            if (roll < 0)
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

u32 MineFloorState::GetLakeBuriedItemTableIndex(u32 floor) const
{
    u32 row;
    do {
        row = floor;
        if (floor <= 9)
            break;

        row = LAKE_BURIED_ROW_B255;
        if (floor == 255)
            break;

        row = LAKE_BURIED_ROW_B80_B254;
        if (floor > 79)
            break;

        row = LAKE_BURIED_ROW_B10_B18;
        for (u32 bound = 19; bound <= 79 && floor >= bound; bound += 10) {
            if (floor == bound) {
                ++row;
                break;
            }
            row += 2;
        }
    } while (false);

    return row;
}

u32 MineFloorState::GetLakeRockTableIndex(u32 floor) const
{
    switch (floor)
    {
    case 255:
        return LAKE_ROCK_ROW_B255;
    case 30:
    case 70:
    case 90:
        return LAKE_ROCK_ROW_B30_B70_B90;
    case 40:
    case 60:
    case 80:
        return LAKE_ROCK_ROW_B40_B60_B80;
    case 50:
    case 100:
    case 150:
    case 200:
        return LAKE_ROCK_ROW_B50_B100_B150_B200;
    case 110:
    case 130:
    case 170:
    case 190:
        return LAKE_ROCK_ROW_B110_B130_B170_B190;
    case 120:
    case 140:
    case 160:
    case 180:
        return LAKE_ROCK_ROW_SHARED_TENS_AFTER_B100;
    }

    if (floor <= 20)
        return floor;
    if (floor > 250)
        return LAKE_ROCK_ROW_B251_B254;
    if (floor <= 99)
        return floor % 10 + LAKE_ROCK_ROW_B20;
    if (floor > 199)
        return floor % 10 + LAKE_ROCK_ROW_SHARED_TENS_AFTER_B100;
    return floor % 10 + LAKE_ROCK_ROW_B50_B100_B150_B200;
}

u32 MineFloorState::GetLayoutKind() const
{
    return layout_kind;
}

u32 MineFloorState::GetWidth() const
{
    u32 result = MINE_DEFAULT_WIDTH;

    if (layout_kind == MINE_LAYOUT_LARGE)
        result = ARRAY_COUNT(cells[0]);

    return result;
}

u32 MineFloorState::GetHeight() const
{
    u32 result = MINE_DEFAULT_HEIGHT;

    if (layout_kind == MINE_LAYOUT_LARGE)
        result = ARRAY_COUNT(cells);
    else if (layout_kind == MINE_LAYOUT_MEDIUM)
        result = MINE_MEDIUM_HEIGHT;

    return result;
}

u32 MineFloorState::GetCellType(u32 column, u32 row) const
{
    return cells[row][column].type;
}

u32 MineFloorState::DigSoil(u32 column, u32 row, GameStateSaveImage & game)
{
    u32 result = MINE_ITEM_NONE;
    if (cells[row][column].type == MINE_CELL_SOIL) {
        result = ProcessItemCode(cells[row][column].buried_item, game);
        if (result == MINE_ITEM_DOWN_LADDER) {
            cells[row][column].type = MINE_CELL_DOWN_LADDER;
            result = MINE_ITEM_NONE;
            for (i32 clear_row = 0; clear_row < static_cast<i32>(GetHeight()); ++clear_row) {
                for (i32 clear_column = 0; clear_column < static_cast<i32>(GetWidth()); ++clear_column) {
                    if (cells[clear_row][clear_column].buried_item == MINE_ITEM_DOWN_LADDER)
                        cells[clear_row][clear_column].buried_item = MINE_ITEM_NONE;
                }
            }
        } else {
            cells[row][column].type = MINE_CELL_DUG_SOIL;
        }
        cells[row][column].buried_item = MINE_ITEM_NONE;
    }
    return result;
}

u32 MineFloorState::BreakRock(u32 column, u32 row, GameStateSaveImage & game)
{
    u32 result = MINE_ITEM_NONE;
    if (cells[row][column].type == MINE_CELL_ROCK) {
        result = ProcessItemCode(cells[row][column].rock_item, game);
        cells[row][column].type = MINE_CELL_SOIL;
        cells[row][column].rock_item = MINE_ITEM_NONE;
    }
    return result;
}

u32 MineFloorState::ProcessItemCode(u32 code, GameStateSaveImage & game)
{
    // Both nine-piece collections share this availability/floor workspace.
    bool collection_blocked;
    i32 floor;
    switch (code) {
    case MINE_ITEM_POWER_BERRY:
        if (game.farmer.GetLocation().map <= static_cast<i32>(MAP_SPRING_MINE_FLOOR_255)) {
            if (found_spring_mine_power_berry == false) {
                found_spring_mine_power_berry = true;
            } else {
                code = MINE_ITEM_NONE;
            }
        } else {
            if (found_lake_mine_power_berry == false) {
                found_lake_mine_power_berry = true;
            } else {
                code = MINE_ITEM_NONE;
            }
        }
        break;
    case MINE_ITEM_SICKLE_CURSED:
    case MINE_ITEM_HOE_CURSED:
    case MINE_ITEM_AXE_CURSED:
    case MINE_ITEM_HAMMER_CURSED:
    case MINE_ITEM_WATERING_CAN_CURSED:
    case MINE_ITEM_FISHING_ROD_CURSED: {
        bool blocked = false;
        if (game.farmer.rucksack.GetFirstFreeToolSlot() == static_cast<u32>(-1))
            blocked = true;
        if (!game.npcs.saibara.HasCollectedAllMystrileTools())
            blocked = true;
        if (HasCursedTool(code, game))
            blocked = true;
        if (blocked == true) {
            code = MINE_ITEM_NONE;
        } else {
            u32 tool = ITEM_TOOL_NONE;
            switch (code) {
            case MINE_ITEM_SICKLE_CURSED:
                tool = ITEM_TOOL_SICKLE_CURSED;
                break;
            case MINE_ITEM_HOE_CURSED:
                tool = ITEM_TOOL_HOE_CURSED;
                break;
            case MINE_ITEM_AXE_CURSED:
                tool = ITEM_TOOL_AXE_CURSED;
                break;
            case MINE_ITEM_HAMMER_CURSED:
                tool = ITEM_TOOL_HAMMER_CURSED;
                break;
            case MINE_ITEM_WATERING_CAN_CURSED:
                tool = ITEM_TOOL_WATERING_CAN_CURSED;
                break;
            case MINE_ITEM_FISHING_ROD_CURSED:
                tool = ITEM_TOOL_FISHING_ROD_CURSED;
                break;
            }
            if (tool != ITEM_TOOL_NONE)
                game.cursed_tools.StartCurse(tool);
        }
        break;
    }
    case MINE_ITEM_TELEPORT_STONE: {
        bool blocked = false;
        if (game.clock.calendar.GetYear(200) < TELEPORT_STONE_FIRST_YEAR)
            blocked = true;
        if (found_teleport_stone == true)
            blocked = true;
        if (game.farmer.rucksack.GetFirstFreeToolSlot() == static_cast<u32>(-1))
            blocked = true;
        if (blocked)
            code = MINE_ITEM_NONE;
        else
            found_teleport_stone = true;
        break;
    }
    case MINE_ITEM_MYTHIC_STONE: {
        bool blocked = false;
        if (!game.cursed_tools.HaveBlessedAllTools())
            blocked = true;
        for (i32 group = MINE_ITEM_SICKLE_CURSED;
             group <= MINE_ITEM_FISHING_ROD_CURSED; ++group) {
            if (HasCursedTool(group, game))
                blocked = true;
        }
        if (blocked == true)
            code = MINE_ITEM_NONE;
        break;
    }
    case MINE_ITEM_HARVEST_GODDESS_JEWEL: {
        collection_blocked = false;
        if (game.farm.farm_house.GetShelf() == 0)
            collection_blocked = true;
        if (CountHarvestGoddessJewels() == 8
            && game.farmer.rucksack.GetFirstFreeToolSlot() == static_cast<u32>(-1))
            collection_blocked = true;
        if (!collection_blocked) {
            floor = game.farmer.GetLocation().map - static_cast<i32>(MAP_SPRING_MINE_FLOOR_0);
            switch (floor) {
            case 60:
                if (found_goddess_jewel_b60 == false) {
                    found_goddess_jewel_b60 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 102:
                if (found_goddess_jewel_b102 == false) {
                    found_goddess_jewel_b102 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 123:
                if (found_goddess_jewel_b123 == false) {
                    found_goddess_jewel_b123 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 152:
                if (found_goddess_jewel_b152 == false) {
                    found_goddess_jewel_b152 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 155:
                if (found_goddess_jewel_b155 == false) {
                    found_goddess_jewel_b155 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 171:
                if (found_goddess_jewel_b171 == false) {
                    found_goddess_jewel_b171 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 190:
                if (found_goddess_jewel_b190 == false) {
                    found_goddess_jewel_b190 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 202:
                if (found_goddess_jewel_b202 == false) {
                    found_goddess_jewel_b202 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 222:
                if (found_goddess_jewel_b222 == false) {
                    found_goddess_jewel_b222 = true;
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
            code = MINE_ITEM_NONE;
        break;
    }
    case MINE_ITEM_KAPPA_JEWEL: {
        collection_blocked = false;
        if (game.farm.farm_house.GetShelf() == 0)
            collection_blocked = true;
        if (CountKappaJewels() == 8
            && game.farmer.rucksack.GetFirstFreeToolSlot() == static_cast<u32>(-1))
            collection_blocked = true;
        if (!collection_blocked) {
            floor = game.farmer.GetLocation().map - static_cast<i32>(MAP_LAKE_MINE_FLOOR_0);
            switch (floor) {
            case 0:
                if (found_kappa_jewel_floor_0 == false) {
                    found_kappa_jewel_floor_0 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 40:
                if (found_kappa_jewel_b40 == false) {
                    found_kappa_jewel_b40 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 60:
                if (found_kappa_jewel_b60 == false) {
                    found_kappa_jewel_b60 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 80:
                if (found_kappa_jewel_b80 == false) {
                    found_kappa_jewel_b80 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 120:
                if (found_kappa_jewel_b120 == false) {
                    found_kappa_jewel_b120 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 140:
                if (found_kappa_jewel_b140 == false) {
                    found_kappa_jewel_b140 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 160:
                if (found_kappa_jewel_b160 == false) {
                    found_kappa_jewel_b160 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 180:
                if (found_kappa_jewel_b180 == false) {
                    found_kappa_jewel_b180 = true;
                } else {
                    collection_blocked = true;
                }
                break;
            case 255:
                if (found_kappa_jewel_b255 == false) {
                    found_kappa_jewel_b255 = true;
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
            code = MINE_ITEM_NONE;
        break;
    }
    case MINE_ITEM_LITHOGRAPH:
        if (found_lithograph == false) {
            found_lithograph = true;
        } else {
            code = MINE_ITEM_NONE;
        }
        break;
    }
    return code;
}

bool MineFloorState::HasCursedTool(u32 mine_item_code, GameStateSaveImage const & game) const
{
    bool found = false;
    i32 tool_id = ITEM_TOOL_NONE;
    switch (mine_item_code) {
    case MINE_ITEM_SICKLE_CURSED: tool_id = ITEM_TOOL_SICKLE_CURSED; break;
    case MINE_ITEM_HOE_CURSED: tool_id = ITEM_TOOL_HOE_CURSED; break;
    case MINE_ITEM_AXE_CURSED: tool_id = ITEM_TOOL_AXE_CURSED; break;
    case MINE_ITEM_HAMMER_CURSED: tool_id = ITEM_TOOL_HAMMER_CURSED; break;
    case MINE_ITEM_WATERING_CAN_CURSED: tool_id = ITEM_TOOL_WATERING_CAN_CURSED; break;
    case MINE_ITEM_FISHING_ROD_CURSED: tool_id = ITEM_TOOL_FISHING_ROD_CURSED; break;
    }
    if (tool_id < ITEM_TOOL_NONE) {
        if (game.farmer.rucksack.GetFirstSlotWithTool(tool_id) != static_cast<u32>(-1))
            found = true;
        if (game.farm.farm_house.tool_chest.GetFirstSlotWith(tool_id) != static_cast<u32>(-1))
            found = true;
    }
    return found;
}

u8 MineFloorState::CountHarvestGoddessJewels() const
{
    u8 result = found_goddess_jewel_b60;
    if (found_goddess_jewel_b102)
        ++result;
    if (found_goddess_jewel_b123)
        ++result;
    if (found_goddess_jewel_b152)
        ++result;
    if (found_goddess_jewel_b155)
        ++result;
    if (found_goddess_jewel_b171)
        ++result;
    if (found_goddess_jewel_b190)
        ++result;
    if (found_goddess_jewel_b202)
        ++result;
    if (found_goddess_jewel_b222)
        ++result;
    return result;
}

u8 MineFloorState::CountKappaJewels() const
{
    u8 result = found_kappa_jewel_floor_0;
    if (found_kappa_jewel_b40)
        ++result;
    if (found_kappa_jewel_b60)
        ++result;
    if (found_kappa_jewel_b80)
        ++result;
    if (found_kappa_jewel_b120)
        ++result;
    if (found_kappa_jewel_b140)
        ++result;
    if (found_kappa_jewel_b160)
        ++result;
    if (found_kappa_jewel_b180)
        ++result;
    if (found_kappa_jewel_b255)
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
    case MINE_CELL_SOIL:
        return gMineFloorSoilTilemap;
    case MINE_CELL_DUG_SOIL:
        return gMineFloorDugSoilTilemap;
    case MINE_CELL_DOWN_LADDER:
        return gMineFloorDownLadderTilemap;
    case MINE_CELL_UP_LADDER:
        return gMineFloorUpLadderTilemap;
    case MINE_CELL_ROCK:
        return gMineFloorRockTilemap;
    default:
        return 0;
    }
}

// Accumulate rock and buried item codes, including MINE_ITEM_NONE. The
// original updates the supplied byte counters without clearing them.
void MineFloorState::AccumulateCellItemCounts(u8 * counts) const
{
    for (u32 row = 0; row < GetHeight(); ++row) {
        for (u32 column = 0; column < GetWidth(); ++column) {
            ++counts[cells[row][column].rock_item];
            ++counts[cells[row][column].buried_item];
        }
    }
}

bool MineFloorState::HasFoundLakeMinePowerBerry() const
{
    return found_lake_mine_power_berry;
}

bool MineFloorState::HasFoundSpringMinePowerBerry() const
{
    return found_spring_mine_power_berry;
}

bool MineFloorState::HasFoundLithograph() const
{
    return found_lithograph;
}

bool MineFloorState::HasFoundTeleportStone() const
{
    return found_teleport_stone;
}

// Preserve the native copy counts, including the unvalidated spring-table
// overruns. This method neither clears weights nor validates destination IDs.
void MineFloorState::CopyCurrentItemWeights(u8 * weights, GameStateSaveImage const & game) const
{
    if (game.farmer.GetLocation().map > static_cast<i32>(MAP_SPRING_MINE_FLOOR_255)) {
        u32 floor = game.farmer.GetLocation().map - static_cast<i32>(MAP_LAKE_MINE_FLOOR_0);
        u32 index = GetLakeBuriedItemTableIndex(floor);
        for (i32 i = 0; i < 5; ++i)
            weights[gLakeMineBuriedItemCodes[i]] = gLakeMineBuriedItemWeights.bytes[index][i];

        index = GetLakeRockTableIndex(floor);
        for (i32 i = 0; i < 10; ++i)
            weights[gLakeMineRockItemCodes[i]] = gLakeMineRockItemWeights.bytes[index][i];
    } else {
        u32 floor = game.farmer.GetLocation().map - static_cast<i32>(MAP_SPRING_MINE_FLOOR_0);
        u32 index = GetSpringBuriedItemTableIndex(floor);
        for (i32 i = 0; i < 10; ++i)
            weights[gSpringMineBuriedItemCodes[i]] = gSpringMineBuriedItemWeights.bytes[index][i];

        index = GetSpringRockTableIndex(floor);
        for (i32 i = 0; i < 14; ++i)
            weights[gSpringMineRockItemCodes[i]] = gSpringMineRockItemWeights.bytes[index][i];
    }
}
