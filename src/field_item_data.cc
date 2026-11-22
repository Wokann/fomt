#include "field_item_data.hh"
#include "fomt_constants.hh"

FieldItemState::FieldItemState() {}

void FieldItemState::Reset()
{
    for (int i = 0; i <= 6; ++i)
        availability[i].bits = 0xFF;

    const u32 largeStoneOrStumpResource = 6;
    const u32 hugeStoneResource = 1;
    resource_60 = largeStoneOrStumpResource;
    resource_61 = largeStoneOrStumpResource;
    resource_62 = largeStoneOrStumpResource;
    resource_63 = largeStoneOrStumpResource;
    resource_64 = largeStoneOrStumpResource;
    resource_65 = largeStoneOrStumpResource;
    resource_66 = largeStoneOrStumpResource;
    resource_67 = largeStoneOrStumpResource;
    resource_68 = largeStoneOrStumpResource;
    resource_69 = largeStoneOrStumpResource;
    resource_6A = largeStoneOrStumpResource;
    resource_6B = largeStoneOrStumpResource;
    resource_6C = largeStoneOrStumpResource;
    resource_6D = hugeStoneResource;
    resource_6E = hugeStoneResource;
}

RucksackItem FieldItemState::PickUp(u32 map, Box const & area, int season)
{
    RucksackItem item;
    int index = Find(map, area, season);
    if (index < 0)
        return item;

    i32 kind = gFieldItemRecords[index].kind;
    if (kind > FIELD_ITEM_BRANCHES)
        return item;

    if (kind <= FIELD_ITEM_APPLE)
    {
        u32 id = ITEM_FOOD_BAMBOO_SHOOT;
        switch (kind)
        {
        case FIELD_ITEM_BAMBOO_SHOOT: id = ITEM_FOOD_BAMBOO_SHOOT; break;
        case FIELD_ITEM_WILD_GRAPES: id = ITEM_FOOD_WILD_GRAPES; break;
        case FIELD_ITEM_MUSHROOM: id = ITEM_FOOD_MUSHROOM; break;
        case FIELD_ITEM_POISONOUS_MUSHROOM: id = ITEM_FOOD_POISONOUS_MUSHROOM; break;
        case FIELD_ITEM_TRUFFLE: id = ITEM_FOOD_TRUFFLE; break;
        case FIELD_ITEM_BLUE_GRASS: id = ITEM_FOOD_BLUE_GRASS; break;
        case FIELD_ITEM_GREEN_GRASS: id = ITEM_FOOD_GREEN_GRASS; break;
        case FIELD_ITEM_RED_GRASS: id = ITEM_FOOD_RED_GRASS; break;
        case FIELD_ITEM_YELLOW_GRASS: id = ITEM_FOOD_YELLOW_GRASS; break;
        case FIELD_ITEM_ORANGE_GRASS: id = ITEM_FOOD_ORANGE_GRASS; break;
        case FIELD_ITEM_PURPLE_GRASS: id = ITEM_FOOD_PURPLE_GRASS; break;
        case FIELD_ITEM_INDIGO_GRASS: id = ITEM_FOOD_INDIGO_GRASS; break;
        case FIELD_ITEM_WHITE_GRASS: id = ITEM_FOOD_WHITE_GRASS; break;
        case FIELD_ITEM_APPLE: id = ITEM_FOOD_APPLE; break;
        }
        item = RucksackItem(Food(id));
    }
    else
    {
        u32 id = ITEM_ARTICLE_FLOWER_MOON_DROP;
        switch (kind)
        {
        case FIELD_ITEM_MOON_DROP: id = ITEM_ARTICLE_FLOWER_MOON_DROP; break;
        case FIELD_ITEM_PINK_CAT: id = ITEM_ARTICLE_FLOWER_PINK_CAT; break;
        case FIELD_ITEM_MAGIC_BLUE: id = ITEM_ARTICLE_FLOWER_MAGIC_BLUE; break;
        case FIELD_ITEM_TOY: id = ITEM_ARTICLE_FLOWER_TOY; break;
        case FIELD_ITEM_BRANCHES: id = ITEM_ARTICLE_BRANCHES; break;
        }
        item = RucksackItem(Article(id));
    }
    ClearAvailability(index, season);
    return item;
}

void FieldItemState::ClearAvailability(u32 index, int season)
{
    u32 bit = GetAvailabilityIndex(index, season);
    u32 byte = bit >> 3;
    if (byte <= 6)
        availability[byte].bits &= ~(1 << (bit & 7));
}

FieldItemInstance FieldItemState::GetRecord(u32 index) const
{
    FieldItemInstance result;
    result.kind = gFieldItemRecords[index].kind;
    result.map = gFieldItemRecords[index].map;
    result.x = gFieldItemRecords[index].x;
    result.y = gFieldItemRecords[index].y;
    switch (result.kind)
    {
    case FIELD_ITEM_LARGE_STONE:
    case FIELD_ITEM_STUMP: result.unk_0C = 1; break;
    case FIELD_ITEM_HUGE_STONE: result.unk_0C = 2; break;
    default: result.unk_0C = 0; break;
    }
    return result;
}

static inline bool BoxesOverlap(Box const & a, Box const & b)
{
    return ((a.x1 - b.x2) & (b.x1 - a.x2) & (a.y1 - b.y2) & (b.y1 - a.y2)) < 0;
}

int FieldItemState::Find(u32 map, Box const & area, int season) const
{
    int index = FIELD_ITEM_RECORD_SPRING_BEGIN;
    int end = FIELD_ITEM_RECORD_SUMMER_BEGIN;
    switch (season)
    {
    case SEASON_SPRING: break;
    case SEASON_SUMMER: index = FIELD_ITEM_RECORD_SUMMER_BEGIN; end = FIELD_ITEM_RECORD_FALL_BEGIN; break;
    case SEASON_FALL: index = FIELD_ITEM_RECORD_FALL_BEGIN; end = FIELD_ITEM_RECORD_WINTER_BEGIN; break;
    case SEASON_WINTER: index = FIELD_ITEM_RECORD_WINTER_BEGIN; end = FIELD_ITEM_RECORD_SHARED_BEGIN; break;
    }
    for (; index < end; ++index)
    {
        if (gFieldItemRecords[index].map == map)
        {
            Box box(gFieldItemRecords[index].x, gFieldItemRecords[index].y);
            box.x2 += 16;
            box.y2 += 16;
            if (BoxesOverlap(box, area))
                break;
        }
    }
    if (index == end)
    {
        index = FIELD_ITEM_RECORD_SHARED_BEGIN;
        end = FIELD_ITEM_RECORD_SHARED_END;
        for (; index < end; ++index)
        {
            if (gFieldItemRecords[index].map == map)
            {
                int width = 32;
                int height = 32;
                if (gFieldItemRecords[index].kind == FIELD_ITEM_HUGE_STONE) width = 48;
                if (gFieldItemRecords[index].kind == FIELD_ITEM_BRANCHES)
                {
                    height = 16;
                    width = 16;
                }
                Box box(gFieldItemRecords[index].x, gFieldItemRecords[index].y);
                box.x2 += width;
                box.y2 += height;
                if (BoxesOverlap(box, area))
                    break;
            }
        }
        if (index == end) index = -1;
    }
    // Preserve the first geometric match; an unavailable match is not skipped.
    if (index >= 0 && !IsAvailable(index, season))
        index = -1;
    return index;
}

u32 FieldItemState::GetAvailabilityIndex(u32 index, int season) const
{
    if (index < FIELD_ITEM_RECORD_SHARED_BEGIN)
    {
        switch (season)
        {
        case SEASON_SPRING: break;
        case SEASON_SUMMER: index -= FIELD_ITEM_RECORD_SUMMER_BEGIN; break;
        case SEASON_FALL: index -= FIELD_ITEM_RECORD_FALL_BEGIN; break;
        case SEASON_WINTER: index -= FIELD_ITEM_RECORD_WINTER_BEGIN; break;
        }
    }
    else
    {
        // The shared bits start after the largest seasonal range (fall).
        const u32 sharedBitBegin = FIELD_ITEM_RECORD_WINTER_BEGIN - FIELD_ITEM_RECORD_FALL_BEGIN;
        index -= FIELD_ITEM_RECORD_SHARED_BEGIN - sharedBitBegin;
    }
    return index;
}

bool FieldItemState::IsAvailable(u32 index, int season) const
{
    u32 bit = GetAvailabilityIndex(index, season);
    return (availability[bit >> 3].bits >> (bit & 7)) & 1;
}

u32 FieldItemState::GetResourceValue(u32 index) const
{
    u32 value = 0;
    if (index >= FIELD_ITEM_RECORD_SHARED_BEGIN)
    {
        switch (index)
        {
        case 0x60: value = resource_60; break;
        case 0x61: value = resource_61; break;
        case 0x62: value = resource_62; break;
        case 0x63: value = resource_63; break;
        case 0x64: value = resource_64; break;
        case 0x65: value = resource_65; break;
        case 0x66: value = resource_66; break;
        case 0x67: value = resource_67; break;
        case 0x68: value = resource_68; break;
        case 0x69: value = resource_69; break;
        case 0x6A: value = resource_6A; break;
        case 0x6B: value = resource_6B; break;
        case 0x6C: value = resource_6C; break;
        case 0x6D: value = resource_6D; break;
        case 0x6E: value = resource_6E; break;
        }
    }
    return value;
}

void FieldItemState::DecreaseResourceValue(u32 index, i32 amount)
{
    if (index >= FIELD_ITEM_RECORD_SHARED_BEGIN)
    {
        switch (index)
        {
        case 0x60: {
            i32 value = resource_60 - amount;
            if (value < 0)
                value = 0;
            resource_60 = value;
            break;
        }
        case 0x61: {
            i32 value = resource_61 - amount;
            if (value < 0)
                value = 0;
            resource_61 = value;
            break;
        }
        case 0x62: {
            i32 value = resource_62 - amount;
            if (value < 0)
                value = 0;
            resource_62 = value;
            break;
        }
        case 0x63: {
            i32 value = resource_63 - amount;
            if (value < 0)
                value = 0;
            resource_63 = value;
            break;
        }
        case 0x64: {
            i32 value = resource_64 - amount;
            if (value < 0)
                value = 0;
            resource_64 = value;
            break;
        }
        case 0x65: {
            i32 value = resource_65 - amount;
            if (value < 0)
                value = 0;
            resource_65 = value;
            break;
        }
        case 0x66: {
            i32 value = resource_66 - amount;
            if (value < 0)
                value = 0;
            resource_66 = value;
            break;
        }
        case 0x67: {
            i32 value = resource_67 - amount;
            if (value < 0)
                value = 0;
            resource_67 = value;
            break;
        }
        case 0x68: {
            i32 value = resource_68 - amount;
            if (value < 0)
                value = 0;
            resource_68 = value;
            break;
        }
        case 0x69: {
            i32 value = resource_69 - amount;
            if (value < 0)
                value = 0;
            resource_69 = value;
            break;
        }
        case 0x6A: {
            i32 value = resource_6A - amount;
            if (value < 0)
                value = 0;
            resource_6A = value;
            break;
        }
        case 0x6B: {
            i32 value = resource_6B - amount;
            if (value < 0)
                value = 0;
            resource_6B = value;
            break;
        }
        case 0x6C: {
            i32 value = resource_6C - amount;
            if (value < 0)
                value = 0;
            resource_6C = value;
            break;
        }
        case 0x6D: {
            i32 value = resource_6D - amount;
            if (value < 0)
                value = 0;
            resource_6D = value;
            break;
        }
        case 0x6E: {
            i32 value = resource_6E - amount;
            if (value < 0)
                value = 0;
            resource_6E = value;
            break;
        }
        }
    }
}

// Use the same pixel-axis notation as Mary scripts in this table.
#define X(value) (value)
#define Y(value) (value)

FieldItemRecord const gFieldItemRecords[] = {
    // Spring
    /* 0x00 */ { FIELD_ITEM_MOON_DROP,          MAP_MOTHERS_HILL_MIDDLE, X( 232), Y(136) },
    /* 0x01 */ { FIELD_ITEM_MOON_DROP,          MAP_MOTHERS_HILL_MIDDLE, X( 248), Y(168) },
    /* 0x02 */ { FIELD_ITEM_MOON_DROP,          MAP_MOTHERS_HILL_MIDDLE, X( 248), Y(200) },
    /* 0x03 */ { FIELD_ITEM_MOON_DROP,          MAP_MOTHERS_HILL_MIDDLE, X( 264), Y(232) },
    /* 0x04 */ { FIELD_ITEM_MOON_DROP,          MAP_MOTHERS_HILL_MIDDLE, X( 280), Y(216) },
    /* 0x05 */ { FIELD_ITEM_MOON_DROP,          MAP_MOTHERS_HILL_MIDDLE, X( 736), Y(336) },
    /* 0x06 */ { FIELD_ITEM_MOON_DROP,          MAP_MOTHERS_HILL_MIDDLE, X( 720), Y(352) },
    /* 0x07 */ { FIELD_ITEM_MOON_DROP,          MAP_MOTHERS_HILL_MIDDLE, X( 736), Y(384) },
    /* 0x08 */ { FIELD_ITEM_MOON_DROP,          MAP_FOREST,              X( 464), Y( 96) },
    /* 0x09 */ { FIELD_ITEM_MOON_DROP,          MAP_FOREST,              X( 384), Y(240) },
    /* 0x0A */ { FIELD_ITEM_TOY,                MAP_MOTHERS_HILL_MIDDLE, X( 304), Y(232) },
    /* 0x0B */ { FIELD_ITEM_TOY,                MAP_MOTHERS_HILL_MIDDLE, X( 336), Y(248) },
    /* 0x0C */ { FIELD_ITEM_TOY,                MAP_MOTHERS_HILL_MIDDLE, X( 368), Y(232) },
    /* 0x0D */ { FIELD_ITEM_TOY,                MAP_MOTHERS_HILL_MIDDLE, X( 728), Y(304) },
    /* 0x0E */ { FIELD_ITEM_TOY,                MAP_MOTHERS_HILL_MIDDLE, X( 736), Y(408) },
    /* 0x0F */ { FIELD_ITEM_TOY,                MAP_MOTHERS_HILL_MIDDLE, X( 704), Y(312) },
    /* 0x10 */ { FIELD_ITEM_BAMBOO_SHOOT,       MAP_MOTHERS_HILL_MIDDLE, X( 184), Y(536) },
    /* 0x11 */ { FIELD_ITEM_BAMBOO_SHOOT,       MAP_MOTHERS_HILL_MIDDLE, X( 224), Y(568) },
    /* 0x12 */ { FIELD_ITEM_BAMBOO_SHOOT,       MAP_MOTHERS_HILL_MIDDLE, X( 488), Y(616) },
    /* 0x13 */ { FIELD_ITEM_YELLOW_GRASS,       MAP_MINERAL_BEACH,       X(  48), Y(240) },
    /* 0x14 */ { FIELD_ITEM_YELLOW_GRASS,       MAP_MINERAL_BEACH,       X( 248), Y(184) },
    /* 0x15 */ { FIELD_ITEM_ORANGE_GRASS,       MAP_MINERAL_BEACH,       X(  48), Y(448) },
    /* 0x16 */ { FIELD_ITEM_ORANGE_GRASS,       MAP_MINERAL_BEACH,       X( 240), Y(344) },
    /* 0x17 */ { FIELD_ITEM_BLUE_GRASS,         MAP_MOTHERS_HILL_MIDDLE, X(1080), Y(528) },
    /* 0x18 */ { FIELD_ITEM_BLUE_GRASS,         MAP_FOREST,              X( 304), Y( 72) },
    /* 0x19 */ { FIELD_ITEM_BLUE_GRASS,         MAP_FOREST,              X( 504), Y( 96) },

    // Summer
    /* 0x1A */ { FIELD_ITEM_WILD_GRAPES,        MAP_MOTHERS_HILL_MIDDLE, X( 192), Y(464) },
    /* 0x1B */ { FIELD_ITEM_WILD_GRAPES,        MAP_FOREST,              X( 304), Y( 32) },
    /* 0x1C */ { FIELD_ITEM_BLUE_GRASS,         MAP_MOTHERS_HILL_MIDDLE, X(1080), Y(528) },
    /* 0x1D */ { FIELD_ITEM_BLUE_GRASS,         MAP_FOREST,              X( 304), Y( 72) },
    /* 0x1E */ { FIELD_ITEM_BLUE_GRASS,         MAP_FOREST,              X( 504), Y( 96) },
    /* 0x1F */ { FIELD_ITEM_GREEN_GRASS,        MAP_MOTHERS_HILL_MIDDLE, X( 152), Y(496) },
    /* 0x20 */ { FIELD_ITEM_GREEN_GRASS,        MAP_MOTHERS_HILL_MIDDLE, X( 424), Y(608) },
    /* 0x21 */ { FIELD_ITEM_GREEN_GRASS,        MAP_MOTHERS_HILL_MIDDLE, X(1112), Y(416) },
    /* 0x22 */ { FIELD_ITEM_RED_GRASS,          MAP_MOTHERS_HILL_MIDDLE, X( 632), Y(608) },
    /* 0x23 */ { FIELD_ITEM_RED_GRASS,          MAP_MOTHERS_HILL_MIDDLE, X( 912), Y(360) },
    /* 0x24 */ { FIELD_ITEM_RED_GRASS,          MAP_MOTHERS_HILL_MIDDLE, X(1048), Y(424) },
    /* 0x25 */ { FIELD_ITEM_RED_GRASS,          MAP_FOREST,              X( 704), Y(144) },
    /* 0x26 */ { FIELD_ITEM_RED_GRASS,          MAP_NORTH_SIDE_TOWN,     X(1064), Y(112) },
    /* 0x27 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 232), Y(512) },
    /* 0x28 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 248), Y(136) },
    /* 0x29 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 248), Y(184) },
    /* 0x2A */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 264), Y(216) },
    /* 0x2B */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 280), Y(200) },
    /* 0x2C */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 312), Y(216) },
    /* 0x2D */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 312), Y(192) },
    /* 0x2E */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 336), Y(232) },
    /* 0x2F */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 352), Y(248) },
    /* 0x30 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 696), Y(288) },
    /* 0x31 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 728), Y(320) },
    /* 0x32 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 736), Y(360) },
    /* 0x33 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X( 736), Y(424) },
    /* 0x34 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X(1024), Y(568) },
    /* 0x35 */ { FIELD_ITEM_PINK_CAT,           MAP_MOTHERS_HILL_MIDDLE, X(1064), Y(512) },
    /* 0x36 */ { FIELD_ITEM_PURPLE_GRASS,       MAP_MINERAL_BEACH,       X(  48), Y(496) },
    /* 0x37 */ { FIELD_ITEM_PURPLE_GRASS,       MAP_MINERAL_BEACH,       X(  88), Y(568) },
    /* 0x38 */ { FIELD_ITEM_PURPLE_GRASS,       MAP_MINERAL_BEACH,       X( 168), Y(568) },
    /* 0x39 */ { FIELD_ITEM_PURPLE_GRASS,       MAP_MINERAL_BEACH,       X( 184), Y(456) },

    // Fall
    /* 0x3A */ { FIELD_ITEM_MUSHROOM,           MAP_MOTHERS_HILL_MIDDLE, X( 664), Y( 48) },
    /* 0x3B */ { FIELD_ITEM_MUSHROOM,           MAP_FOREST,              X( 424), Y( 88) },
    /* 0x3C */ { FIELD_ITEM_MUSHROOM,           MAP_BEHIND_CHURCH,       X(  56), Y(288) },
    /* 0x3D */ { FIELD_ITEM_TRUFFLE,            MAP_MOTHERS_HILL_MIDDLE, X( 256), Y(312) },
    /* 0x3E */ { FIELD_ITEM_TRUFFLE,            MAP_BEHIND_CHURCH,       X( 320), Y(160) },
    /* 0x3F */ { FIELD_ITEM_TRUFFLE,            MAP_BEHIND_CHURCH,       X( 136), Y( 40) },
    /* 0x40 */ { FIELD_ITEM_POISONOUS_MUSHROOM, MAP_FOREST,              X( 768), Y(160) },
    /* 0x41 */ { FIELD_ITEM_POISONOUS_MUSHROOM, MAP_BEHIND_CHURCH,       X(  32), Y(128) },
    /* 0x42 */ { FIELD_ITEM_GREEN_GRASS,        MAP_MOTHERS_HILL_MIDDLE, X( 152), Y(496) },
    /* 0x43 */ { FIELD_ITEM_GREEN_GRASS,        MAP_MOTHERS_HILL_MIDDLE, X( 424), Y(608) },
    /* 0x44 */ { FIELD_ITEM_GREEN_GRASS,        MAP_MOTHERS_HILL_MIDDLE, X(1112), Y(416) },
    /* 0x45 */ { FIELD_ITEM_RED_GRASS,          MAP_MOTHERS_HILL_MIDDLE, X( 632), Y(608) },
    /* 0x46 */ { FIELD_ITEM_RED_GRASS,          MAP_MOTHERS_HILL_MIDDLE, X( 912), Y(360) },
    /* 0x47 */ { FIELD_ITEM_RED_GRASS,          MAP_MOTHERS_HILL_MIDDLE, X(1048), Y(424) },
    /* 0x48 */ { FIELD_ITEM_RED_GRASS,          MAP_FOREST,              X( 704), Y(144) },
    /* 0x49 */ { FIELD_ITEM_RED_GRASS,          MAP_NORTH_SIDE_TOWN,     X(1064), Y(112) },
    /* 0x4A */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 256), Y( 48) },
    /* 0x4B */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 232), Y(112) },
    /* 0x4C */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 208), Y(192) },
    /* 0x4D */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 216), Y(216) },
    /* 0x4E */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 320), Y(248) },
    /* 0x4F */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 368), Y(208) },
    /* 0x50 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 384), Y(224) },
    /* 0x51 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 400), Y(192) },
    /* 0x52 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 424), Y(192) },
    /* 0x53 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 592), Y( 48) },
    /* 0x54 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 624), Y( 88) },
    /* 0x55 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 672), Y(152) },
    /* 0x56 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_MOTHERS_HILL_MIDDLE, X( 624), Y(208) },
    /* 0x57 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_FOREST,              X( 232), Y(240) },
    /* 0x58 */ { FIELD_ITEM_MAGIC_BLUE,         MAP_FOREST,              X( 264), Y(160) },
    /* 0x59 */ { FIELD_ITEM_INDIGO_GRASS,       MAP_MINERAL_BEACH,       X( 232), Y(160) },
    /* 0x5A */ { FIELD_ITEM_INDIGO_GRASS,       MAP_MINERAL_BEACH,       X(  48), Y(392) },
    /* 0x5B */ { FIELD_ITEM_APPLE,              MAP_FARM,                X(  96), Y(376) },
    /* 0x5C */ { FIELD_ITEM_APPLE,              MAP_FARM,                X( 126), Y(392) },
    /* 0x5D */ { FIELD_ITEM_APPLE,              MAP_FARM,                X( 156), Y(376) },

    // Winter
    /* 0x5E */ { FIELD_ITEM_WHITE_GRASS,        MAP_FOREST,              X( 720), Y( 24) },
    /* 0x5F */ { FIELD_ITEM_WHITE_GRASS,        MAP_BEHIND_CHURCH,       X(  72), Y( 96) },

    // Shared across seasons
    /* 0x60 */ { FIELD_ITEM_LARGE_STONE,        MAP_MOTHERS_HILL_MIDDLE, X( 440), Y(176) },
    /* 0x61 */ { FIELD_ITEM_LARGE_STONE,        MAP_MOTHERS_HILL_MIDDLE, X(  64), Y(328) },
    /* 0x62 */ { FIELD_ITEM_LARGE_STONE,        MAP_MOTHERS_HILL_MIDDLE, X(   8), Y(488) },
    /* 0x63 */ { FIELD_ITEM_LARGE_STONE,        MAP_MOTHERS_HILL_MIDDLE, X( 376), Y(744) },
    /* 0x64 */ { FIELD_ITEM_LARGE_STONE,        MAP_MOTHERS_HILL_MIDDLE, X( 720), Y(440) },
    /* 0x65 */ { FIELD_ITEM_STUMP,              MAP_MOTHERS_HILL_MIDDLE, X(1088), Y(488) },
    /* 0x66 */ { FIELD_ITEM_STUMP,              MAP_MOTHERS_HILL_MIDDLE, X(1032), Y(528) },
    /* 0x67 */ { FIELD_ITEM_STUMP,              MAP_MOTHERS_HILL_MIDDLE, X( 392), Y(592) },
    /* 0x68 */ { FIELD_ITEM_STUMP,              MAP_FOREST,              X( 272), Y(216) },
    /* 0x69 */ { FIELD_ITEM_STUMP,              MAP_FOREST,              X( 288), Y(152) },
    /* 0x6A */ { FIELD_ITEM_STUMP,              MAP_FOREST,              X( 408), Y(120) },
    /* 0x6B */ { FIELD_ITEM_STUMP,              MAP_FOREST,              X( 488), Y(120) },
    /* 0x6C */ { FIELD_ITEM_STUMP,              MAP_FOREST,              X( 448), Y(192) },
    /* 0x6D */ { FIELD_ITEM_HUGE_STONE,         MAP_MOTHERS_HILL_MIDDLE, X( 264), Y(328) },
    /* 0x6E */ { FIELD_ITEM_HUGE_STONE,         MAP_MOTHERS_HILL_MIDDLE, X( 640), Y(664) },
    /* 0x6F */ { FIELD_ITEM_BRANCHES,           MAP_FOREST,              X( 360), Y( 56) },
    /* 0x70 */ { FIELD_ITEM_BRANCHES,           MAP_FOREST,              X( 584), Y( 72) },
    /* 0x71 */ { FIELD_ITEM_BRANCHES,           MAP_FOREST,              X( 736), Y(112) },
    /* 0x72 */ { FIELD_ITEM_BRANCHES,           MAP_MOTHERS_HILL_MIDDLE, X( 648), Y( 64) },
    /* 0x73 */ { FIELD_ITEM_BRANCHES,           MAP_MOTHERS_HILL_MIDDLE, X( 576), Y(592) },
};

#undef Y
#undef X
