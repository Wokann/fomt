#include "map_selection.h"
#include "fomt_constants.hh"

u32 SelectMapDataId(i32 map, u32 season, u32 house, u32 coop, u32 barn)
{
    if (((u32)map - MAP_SPRING_MINE_FLOOR_0) <=
        MAP_LAKE_MINE_FLOOR_255 - MAP_SPRING_MINE_FLOOR_0) {
        u32 floor;
        u32 mine_type; // 0: Spring Mine, 1: Lake Mine.
        if (map > MAP_SPRING_MINE_FLOOR_255) {
            floor = map - MAP_LAKE_MINE_FLOOR_0;
            mine_type = 1;
        } else {
            floor = map - MAP_SPRING_MINE_FLOOR_0;
            mine_type = 0;
        }
        if (floor == 0)
            return 56;
        if (floor == 9 && mine_type == 1)
            return 61;
        if (floor % 5 == 0)
            return 57;
        if (floor % 3 == 0)
            return 58;
        return 59;
    }

    switch (map) {
    case MAP_FARM:
        return season != SEASON_WINTER ? 0 : 1;
    case MAP_ROSE_SQUARE:
        return season != SEASON_WINTER ? 2 : 3;
    case MAP_NORTH_SIDE_TOWN:
        return season != SEASON_WINTER ? 4 : 5;
    case MAP_SOUTH_SIDE_TOWN:
        return season != SEASON_WINTER ? 6 : 7;
    case MAP_MINERAL_BEACH:
        return season != SEASON_WINTER ? 8 : 9;
    case MAP_FOREST:
        return season != SEASON_WINTER ? 12 : 13;
    case MAP_BEHIND_CHURCH:
        return season != SEASON_WINTER ? 10 : 11;
    case MAP_MOTHERS_HILL_MIDDLE:
        return season != SEASON_WINTER ? 14 : 15;
    case MAP_MOTHERS_HILL_SUMMIT:
        return season != SEASON_WINTER ? 16 : 17;
    case MAP_CHICKEN_COOP:
        switch (coop) {
        case 0: return 36;
        case 1: return 37;
        }
        break;
    case MAP_BARN:
        switch (barn) {
        case 0: return 38;
        case 1: return 39;
        }
        break;
    case MAP_FARMHOUSE:
        switch (house) {
        case 0: return 41;
        case 1: return 42;
        case 2: return 43;
        }
        break;
    case MAP_AJA_WINERY_1F: return 18;
    case MAP_AJA_WINERY_2F: return 19;
    case MAP_AJA_WINERY_STORAGE_1F: return 20;
    case MAP_AJA_WINERY_STORAGE_B1F: return 21;
    case MAP_INN_1F: return 22;
    case MAP_INN_BACK_ROOM: return 23;
    case MAP_INN_2F: return 24;
    case MAP_SUPERMARKET: return 25;
    case MAP_SUPERMARKET_BACK_ROOM: return 26;
    case MAP_KAI_RESTAURANT: return 27;
    case MAP_ZACK_HOUSE: return 28;
    case MAP_MINERAL_CLINIC_1F: return 29;
    case MAP_MINERAL_CLINIC_2F: return 30;
    case MAP_CHURCH: return 31;
    case MAP_LIBRARY_1F: return 32;
    case MAP_LIBRARY_2F: return 33;
    case MAP_BASIL_HOUSE_1F: return 34;
    case MAP_BASIL_HOUSE_2F: return 35;
    case MAP_HORSE_STABLE: return 40;
    case MAP_POULTRY_FARM_HOUSE_1F: return 44;
    case MAP_POULTRY_FARM_HOUSE_2F: return 45;
    case MAP_YODEL_RANCH_HOUSE_1F: return 46;
    case MAP_YODEL_RANCH_HOUSE_2F: return 47;
    case MAP_BLACKSMITH: return 48;
    case MAP_GOTZ_HOUSE: return 49;
    case MAP_MAYOR_HOUSE: return 50;
    case MAP_ELLEN_HOUSE: return 51;
    case MAP_HARVEST_SPRITES_HUT: return 52;
    case MAP_MOUNTAIN_COTTAGE: return 53;
    case MAP_BEACH_HOUSE: return 54;
    case MAP_TOWN_COTTAGE: return 55;
    case MAP_LAKE_MINE_ENTRANCE: return 60;
    case MAP_TUTORIAL_ANIMAL_FIELD: return MAP_DATA_TUTORIAL_ANIMAL_FIELD;
    case MAP_TUTORIAL_CHICKEN_COOP: return 63;
    case MAP_TUTORIAL_BARN: return 64;
    case MAP_SPRING_MINE_ENTRANCE: return 65;
    case MAP_MOTHERS_HILL_SUMMIT_CLEAR:
    case MAP_MOTHERS_HILL_SUMMIT_RAIN:
    case MAP_MOTHERS_HILL_SUMMIT_SNOW:
        return 16;
    case MAP_TUTORIAL_FIELD:
        return 17;
    }
    return 0;
}
