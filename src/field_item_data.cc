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
    int end = FIELD_ITEM_RECORD_SPRING_END;
    switch (season)
    {
    case SEASON_SPRING: break;
    case SEASON_SUMMER: index = FIELD_ITEM_RECORD_SUMMER_BEGIN; end = FIELD_ITEM_RECORD_SUMMER_END; break;
    case SEASON_FALL: index = FIELD_ITEM_RECORD_FALL_BEGIN; end = FIELD_ITEM_RECORD_FALL_END; break;
    case SEASON_WINTER: index = FIELD_ITEM_RECORD_WINTER_BEGIN; end = FIELD_ITEM_RECORD_WINTER_END; break;
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
        const u32 sharedBitBegin = FIELD_ITEM_RECORD_FALL_END - FIELD_ITEM_RECORD_FALL_BEGIN;
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
