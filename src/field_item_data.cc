#include "field_item_data.hh"

FieldItemState::FieldItemState() {}

void FieldItemState::Reset()
{
    for (int i = 0; i <= 6; ++i)
        availability[i].bits = 0xFF;
    resource_60 = 6;
    resource_61 = 6;
    resource_62 = 6;
    resource_63 = 6;
    resource_64 = 6;
    resource_65 = 6;
    resource_66 = 6;
    resource_67 = 6;
    resource_68 = 6;
    resource_69 = 6;
    resource_6A = 6;
    resource_6B = 6;
    resource_6C = 6;
    resource_6D = 1;
    resource_6E = 1;
}

RucksackItem FieldItemState::PickUp(u32 map, Box const & area, int season)
{
    RucksackItem item;
    int index = Find(map, area, season);
    if (index < 0)
        return item;

    i32 kind = gFieldItemRecords[index].kind;
    if (kind > 0x12)
        return item;

    if (kind <= 0x0D)
    {
        u32 id = ITEM_FOOD_BAMBOO_SHOOT;
        switch (kind)
        {
        case 0: id = ITEM_FOOD_BAMBOO_SHOOT; break;
        case 1: id = ITEM_FOOD_WILD_GRAPES; break;
        case 2: id = ITEM_FOOD_MUSHROOM; break;
        case 3: id = ITEM_FOOD_POISONOUS_MUSHROOM; break;
        case 4: id = ITEM_FOOD_TRUFFLE; break;
        case 5: id = ITEM_FOOD_BLUE_GRASS; break;
        case 6: id = ITEM_FOOD_GREEN_GRASS; break;
        case 7: id = ITEM_FOOD_RED_GRASS; break;
        case 8: id = ITEM_FOOD_YELLOW_GRASS; break;
        case 9: id = ITEM_FOOD_ORANGE_GRASS; break;
        case 10: id = ITEM_FOOD_PURPLE_GRASS; break;
        case 11: id = ITEM_FOOD_INDIGO_GRASS; break;
        case 12: id = ITEM_FOOD_WHITE_GRASS; break;
        case 13: id = ITEM_FOOD_APPLE; break;
        }
        item = RucksackItem(Food(id));
    }
    else
    {
        u32 id = ITEM_ARTICLE_FLOWER_MOON_DROP;
        switch (kind)
        {
        case 0x0E: id = ITEM_ARTICLE_FLOWER_MOON_DROP; break;
        case 0x0F: id = ITEM_ARTICLE_FLOWER_PINK_CAT; break;
        case 0x10: id = ITEM_ARTICLE_FLOWER_MAGIC_BLUE; break;
        case 0x11: id = ITEM_ARTICLE_FLOWER_TOY; break;
        case 0x12: id = ITEM_ARTICLE_BRANCHES; break;
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
    case 0x13:
    case 0x15: result.unk_0C = 1; break;
    case 0x14: result.unk_0C = 2; break;
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
    int index = 0;
    int end = 0x1A;
    switch (season)
    {
    case SEASON_SPRING: break;
    case SEASON_SUMMER: index = 0x1A; end = 0x3A; break;
    case SEASON_FALL: index = 0x3A; end = 0x5E; break;
    case SEASON_WINTER: index = 0x5E; end = 0x60; break;
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
        index = 0x60;
        end = 0x74;
        for (; index < end; ++index)
        {
            if (gFieldItemRecords[index].map == map)
            {
                int width = 32;
                int height = 32;
                if (gFieldItemRecords[index].kind == 0x14) width = 48;
                if (gFieldItemRecords[index].kind == 0x12)
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
    if (index <= 0x5F)
    {
        switch (season)
        {
        case SEASON_SPRING: break;
        case SEASON_SUMMER: index -= 0x1A; break;
        case SEASON_FALL: index -= 0x3A; break;
        case SEASON_WINTER: index -= 0x5E; break;
        }
    }
    else index -= 0x3C;
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
    if (index > 0x5F)
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

// Records 0x00-0x5F follow the spring/summer/fall/winter ranges.
// Find also scans the shared trailing range 0x60-0x73.
FieldItemRecord const gFieldItemRecords[] = {
    /* 0x00 */ { 0x0E, 0x00,  232, 136 },
    /* 0x01 */ { 0x0E, 0x00,  248, 168 },
    /* 0x02 */ { 0x0E, 0x00,  248, 200 },
    /* 0x03 */ { 0x0E, 0x00,  264, 232 },
    /* 0x04 */ { 0x0E, 0x00,  280, 216 },
    /* 0x05 */ { 0x0E, 0x00,  736, 336 },
    /* 0x06 */ { 0x0E, 0x00,  720, 352 },
    /* 0x07 */ { 0x0E, 0x00,  736, 384 },
    /* 0x08 */ { 0x0E, 0x03,  464,  96 },
    /* 0x09 */ { 0x0E, 0x03,  384, 240 },
    /* 0x0A */ { 0x11, 0x00,  304, 232 },
    /* 0x0B */ { 0x11, 0x00,  336, 248 },
    /* 0x0C */ { 0x11, 0x00,  368, 232 },
    /* 0x0D */ { 0x11, 0x00,  728, 304 },
    /* 0x0E */ { 0x11, 0x00,  736, 408 },
    /* 0x0F */ { 0x11, 0x00,  704, 312 },
    /* 0x10 */ { 0x00, 0x00,  184, 536 },
    /* 0x11 */ { 0x00, 0x00,  224, 568 },
    /* 0x12 */ { 0x00, 0x00,  488, 616 },
    /* 0x13 */ { 0x08, 0x01,   48, 240 },
    /* 0x14 */ { 0x08, 0x01,  248, 184 },
    /* 0x15 */ { 0x09, 0x01,   48, 448 },
    /* 0x16 */ { 0x09, 0x01,  240, 344 },
    /* 0x17 */ { 0x05, 0x00, 1080, 528 },
    /* 0x18 */ { 0x05, 0x03,  304,  72 },
    /* 0x19 */ { 0x05, 0x03,  504,  96 },
    /* 0x1A */ { 0x01, 0x00,  192, 464 },
    /* 0x1B */ { 0x01, 0x03,  304,  32 },
    /* 0x1C */ { 0x05, 0x00, 1080, 528 },
    /* 0x1D */ { 0x05, 0x03,  304,  72 },
    /* 0x1E */ { 0x05, 0x03,  504,  96 },
    /* 0x1F */ { 0x06, 0x00,  152, 496 },
    /* 0x20 */ { 0x06, 0x00,  424, 608 },
    /* 0x21 */ { 0x06, 0x00, 1112, 416 },
    /* 0x22 */ { 0x07, 0x00,  632, 608 },
    /* 0x23 */ { 0x07, 0x00,  912, 360 },
    /* 0x24 */ { 0x07, 0x00, 1048, 424 },
    /* 0x25 */ { 0x07, 0x03,  704, 144 },
    /* 0x26 */ { 0x07, 0x05, 1064, 112 },
    /* 0x27 */ { 0x0F, 0x00,  232, 512 },
    /* 0x28 */ { 0x0F, 0x00,  248, 136 },
    /* 0x29 */ { 0x0F, 0x00,  248, 184 },
    /* 0x2A */ { 0x0F, 0x00,  264, 216 },
    /* 0x2B */ { 0x0F, 0x00,  280, 200 },
    /* 0x2C */ { 0x0F, 0x00,  312, 216 },
    /* 0x2D */ { 0x0F, 0x00,  312, 192 },
    /* 0x2E */ { 0x0F, 0x00,  336, 232 },
    /* 0x2F */ { 0x0F, 0x00,  352, 248 },
    /* 0x30 */ { 0x0F, 0x00,  696, 288 },
    /* 0x31 */ { 0x0F, 0x00,  728, 320 },
    /* 0x32 */ { 0x0F, 0x00,  736, 360 },
    /* 0x33 */ { 0x0F, 0x00,  736, 424 },
    /* 0x34 */ { 0x0F, 0x00, 1024, 568 },
    /* 0x35 */ { 0x0F, 0x00, 1064, 512 },
    /* 0x36 */ { 0x0A, 0x01,   48, 496 },
    /* 0x37 */ { 0x0A, 0x01,   88, 568 },
    /* 0x38 */ { 0x0A, 0x01,  168, 568 },
    /* 0x39 */ { 0x0A, 0x01,  184, 456 },
    /* 0x3A */ { 0x02, 0x00,  664,  48 },
    /* 0x3B */ { 0x02, 0x03,  424,  88 },
    /* 0x3C */ { 0x02, 0x04,   56, 288 },
    /* 0x3D */ { 0x04, 0x00,  256, 312 },
    /* 0x3E */ { 0x04, 0x04,  320, 160 },
    /* 0x3F */ { 0x04, 0x04,  136,  40 },
    /* 0x40 */ { 0x03, 0x03,  768, 160 },
    /* 0x41 */ { 0x03, 0x04,   32, 128 },
    /* 0x42 */ { 0x06, 0x00,  152, 496 },
    /* 0x43 */ { 0x06, 0x00,  424, 608 },
    /* 0x44 */ { 0x06, 0x00, 1112, 416 },
    /* 0x45 */ { 0x07, 0x00,  632, 608 },
    /* 0x46 */ { 0x07, 0x00,  912, 360 },
    /* 0x47 */ { 0x07, 0x00, 1048, 424 },
    /* 0x48 */ { 0x07, 0x03,  704, 144 },
    /* 0x49 */ { 0x07, 0x05, 1064, 112 },
    /* 0x4A */ { 0x10, 0x00,  256,  48 },
    /* 0x4B */ { 0x10, 0x00,  232, 112 },
    /* 0x4C */ { 0x10, 0x00,  208, 192 },
    /* 0x4D */ { 0x10, 0x00,  216, 216 },
    /* 0x4E */ { 0x10, 0x00,  320, 248 },
    /* 0x4F */ { 0x10, 0x00,  368, 208 },
    /* 0x50 */ { 0x10, 0x00,  384, 224 },
    /* 0x51 */ { 0x10, 0x00,  400, 192 },
    /* 0x52 */ { 0x10, 0x00,  424, 192 },
    /* 0x53 */ { 0x10, 0x00,  592,  48 },
    /* 0x54 */ { 0x10, 0x00,  624,  88 },
    /* 0x55 */ { 0x10, 0x00,  672, 152 },
    /* 0x56 */ { 0x10, 0x00,  624, 208 },
    /* 0x57 */ { 0x10, 0x03,  232, 240 },
    /* 0x58 */ { 0x10, 0x03,  264, 160 },
    /* 0x59 */ { 0x0B, 0x01,  232, 160 },
    /* 0x5A */ { 0x0B, 0x01,   48, 392 },
    /* 0x5B */ { 0x0D, 0x02,   96, 376 },
    /* 0x5C */ { 0x0D, 0x02,  126, 392 },
    /* 0x5D */ { 0x0D, 0x02,  156, 376 },
    /* 0x5E */ { 0x0C, 0x03,  720,  24 },
    /* 0x5F */ { 0x0C, 0x04,   72,  96 },
    /* 0x60 */ { 0x13, 0x00,  440, 176 },
    /* 0x61 */ { 0x13, 0x00,   64, 328 },
    /* 0x62 */ { 0x13, 0x00,    8, 488 },
    /* 0x63 */ { 0x13, 0x00,  376, 744 },
    /* 0x64 */ { 0x13, 0x00,  720, 440 },
    /* 0x65 */ { 0x15, 0x00, 1088, 488 },
    /* 0x66 */ { 0x15, 0x00, 1032, 528 },
    /* 0x67 */ { 0x15, 0x00,  392, 592 },
    /* 0x68 */ { 0x15, 0x03,  272, 216 },
    /* 0x69 */ { 0x15, 0x03,  288, 152 },
    /* 0x6A */ { 0x15, 0x03,  408, 120 },
    /* 0x6B */ { 0x15, 0x03,  488, 120 },
    /* 0x6C */ { 0x15, 0x03,  448, 192 },
    /* 0x6D */ { 0x14, 0x00,  264, 328 },
    /* 0x6E */ { 0x14, 0x00,  640, 664 },
    /* 0x6F */ { 0x12, 0x03,  360,  56 },
    /* 0x70 */ { 0x12, 0x03,  584,  72 },
    /* 0x71 */ { 0x12, 0x03,  736, 112 },
    /* 0x72 */ { 0x12, 0x00,  648,  64 },
    /* 0x73 */ { 0x12, 0x00,  576, 592 },
};

#include FOMT_TEXT_INCLUDE(field_item_data.cc)
