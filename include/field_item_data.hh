#ifndef FIELD_ITEM_DATA_HH
#define FIELD_ITEM_DATA_HH

#include "field.hh"

enum FieldItemKind
{
    FIELD_ITEM_BAMBOO_SHOOT = 0x00,
    FIELD_ITEM_WILD_GRAPES = 0x01,
    FIELD_ITEM_MUSHROOM = 0x02,
    FIELD_ITEM_POISONOUS_MUSHROOM = 0x03,
    FIELD_ITEM_TRUFFLE = 0x04,
    FIELD_ITEM_BLUE_GRASS = 0x05,
    FIELD_ITEM_GREEN_GRASS = 0x06,
    FIELD_ITEM_RED_GRASS = 0x07,
    FIELD_ITEM_YELLOW_GRASS = 0x08,
    FIELD_ITEM_ORANGE_GRASS = 0x09,
    FIELD_ITEM_PURPLE_GRASS = 0x0A,
    FIELD_ITEM_INDIGO_GRASS = 0x0B,
    FIELD_ITEM_WHITE_GRASS = 0x0C,
    FIELD_ITEM_APPLE = 0x0D,
    FIELD_ITEM_MOON_DROP = 0x0E,
    FIELD_ITEM_PINK_CAT = 0x0F,
    FIELD_ITEM_MAGIC_BLUE = 0x10,
    FIELD_ITEM_TOY = 0x11,
    FIELD_ITEM_BRANCHES = 0x12,
    FIELD_ITEM_LARGE_STONE = 0x13,
    FIELD_ITEM_HUGE_STONE = 0x14,
    FIELD_ITEM_STUMP = 0x15,
};

enum FieldItemRecordIndex
{
    FIELD_ITEM_RECORD_SPRING_BEGIN = 0x00,
    FIELD_ITEM_RECORD_SUMMER_BEGIN = 0x1A,
    FIELD_ITEM_RECORD_FALL_BEGIN = 0x3A,
    FIELD_ITEM_RECORD_FALL_APPLES_BEGIN = 0x5B,
    FIELD_ITEM_RECORD_WINTER_BEGIN = 0x5E,
    FIELD_ITEM_RECORD_FALL_APPLES_END = FIELD_ITEM_RECORD_WINTER_BEGIN,
    FIELD_ITEM_RECORD_SHARED_BEGIN = 0x60,
    FIELD_ITEM_RECORD_SHARED_END = 0x74,
};

struct FieldItemRecord
{
    i32 kind;
    u32 map;
    i16 x;
    i16 y;
};

struct FieldItemInstance : FieldItemRecord
{
    u32 unk_0C;
};

// Packed whole-byte bitfields preserve the original read/modify/write behavior.
struct PACKED FieldItemAvailabilityByte
{
    u8 bits : 8;
};

// Save image +0x34C8: 56 availability bits, then fifteen packed 3-bit values.
// The last three bits and final alignment byte are not initialized by Reset.
// Hits with the appropriate tool reduce the resource values of stones and stumps.
// Their u32 base type also preserves the native cross-byte write operations.
struct PACKED ALIGN(2) FieldItemState
{
    FieldItemState(); // Intentionally does not initialize storage; Reset is separate.
    void Reset();
    RucksackItem PickUp(u32 map, Box const & area, int season);
    void ClearAvailability(u32 index, int season);
    FieldItemInstance GetRecord(u32 index) const;
    int Find(u32 map, Box const & area, int season) const;
    u32 GetAvailabilityIndex(u32 index, int season) const;
    bool IsAvailable(u32 index, int season) const;
    u32 GetResourceValue(u32 index) const;
    void DecreaseResourceValue(u32 index, i32 amount);

    FieldItemAvailabilityByte availability[7];
    u32 resource_60 : 3;
    u32 resource_61 : 3;
    u32 resource_62 : 3;
    u32 resource_63 : 3;
    u32 resource_64 : 3;
    u32 resource_65 : 3;
    u32 resource_66 : 3;
    u32 resource_67 : 3;
    u32 resource_68 : 3;
    u32 resource_69 : 3;
    u32 resource_6A : 3;
    u32 resource_6B : 3;
    u32 resource_6C : 3;
    u32 resource_6D : 3;
    u32 resource_6E : 3;
};

typedef char FieldItemStateSizeCheck[sizeof(FieldItemState) == 14 ? 1 : -1];
typedef char FieldItemRecordSizeCheck[sizeof(FieldItemRecord) == 12 ? 1 : -1];
typedef char FieldItemInstanceSizeCheck[sizeof(FieldItemInstance) == 16 ? 1 : -1];

typedef char FieldItemRecordMapCheck[offsetof(FieldItemRecord, map) == 4 ? 1 : -1];
typedef char FieldItemRecordPositionCheck[offsetof(FieldItemRecord, x) == 8 ? 1 : -1];
typedef char FieldItemInstanceExtraCheck[offsetof(FieldItemInstance, unk_0C) == 12 ? 1 : -1];

extern FieldItemRecord const gFieldItemRecords[];

#endif // FIELD_ITEM_DATA_HH
