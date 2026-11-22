#ifndef FIELD_ITEM_DATA_HH
#define FIELD_ITEM_DATA_HH

#include "field.hh"
#include "field_item_records.h"

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
typedef char FieldItemInstanceSizeCheck[sizeof(FieldItemInstance) == 16 ? 1 : -1];

typedef char FieldItemInstanceExtraCheck[offsetof(FieldItemInstance, unk_0C) == 12 ? 1 : -1];

#endif // FIELD_ITEM_DATA_HH
