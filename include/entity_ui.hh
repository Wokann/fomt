#ifndef ENTITY_UI_HH
#define ENTITY_UI_HH

#include "entity.hh"
#include "harvest_sprite.hh"

struct EntityUiUnknownState
{
    u8 unknown_00[0x41];
    u8 unknown_41;
};

struct EntityUiConstructorState
{
    void * unknown_00;
    void const * vtable;
};

struct EntityUiHarvestSpriteEntry
{
    u8 flags;
    u8 unknown_01[7];
};

struct EntityUiHarvestSpriteResult
{
    u8 flags;
    u8 unknown_01[7];
};

struct EntityUiUnknownEntry
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
};

// The callers establish the physical 8-byte layout, but not the game-level
// meaning of these fields yet.
struct EntityUiUnknownTableEntry
{
    u16 unk_00;
    u16 unk_02;
    i8 unk_04;
    i8 unk_05;
    u8 unk_06;
    u8 unk_07;
};

struct EntityUiScreenOffset
{
    i16 x;
    i16 y;
};

struct EntityUiAnimationState
{
    u8 unknown_00[0x30];
    u8 entry_index;
};

struct EntityUiResourceSetupState
{
    u8 unknown_00[0xB4];
    u8 resource_handle[0x14];
    u8 enabled;
    u8 unknown_C9;
    u8 active;
    u8 visible;
    u16 first_value;
    u16 second_value;
    u16 duration;
};

// func_08034C64 calls selector, then selects one of the three table pointers.
// The later entry and payload fields are read by native Entity-UI code, but
// their game-level meanings are not established yet.
typedef u32 (*EntityUiResourceSelectorCallback)(void const * state);

struct EntityUiResourceSelectorPayload
{
    void const * unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
};

struct EntityUiResourceSelectorEntry
{
    u32 unk_00;
    EntityUiResourceSelectorPayload const * payload;
};

struct EntityUiResourceSelectorTable
{
    u16 entry_count;
    u16 unk_02;
    EntityUiResourceSelectorEntry const * entries;
};

struct EntityUiResourceSelectorDescriptor
{
    EntityUiResourceSelectorCallback selector;
    u32 table_count;
    EntityUiResourceSelectorTable const * const * tables;
};

// This is one physical ROM object: descriptor, table pointers, two tables,
// two entries, and their shared payload. Its first member is the label used
// by the remaining native Entity-UI code.
struct EntityUiResourceSelectorStorage
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[3];
    EntityUiResourceSelectorTable table_storage[2];
    EntityUiResourceSelectorEntry entry_storage[2];
    EntityUiResourceSelectorPayload payload;
};

struct EntityUiResourceSelectorDetailEntry
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
};

// The next physical selector has the same leading layout, followed by four
// indexed tables, ten payload records, and five pointed detail arrays.
struct EntityUiResourceSelectorExtendedStorage
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[5];
    EntityUiResourceSelectorTable table_storage[4];
    EntityUiResourceSelectorEntry entry_storage_0[3];
    EntityUiResourceSelectorEntry entry_storage_1[7];
    EntityUiResourceSelectorEntry entry_storage_2[5];
    EntityUiResourceSelectorEntry entry_storage_3[1];
    EntityUiResourceSelectorPayload payload_storage[10];
    EntityUiResourceSelectorDetailEntry detail_storage_0[3];
    EntityUiResourceSelectorDetailEntry detail_storage_1[3];
    EntityUiResourceSelectorDetailEntry detail_storage_2[3];
    EntityUiResourceSelectorDetailEntry detail_storage_3[5];
    EntityUiResourceSelectorDetailEntry detail_storage_4[5];
};

// The following selector is a larger contiguous instance of the same format.
// Its individual table sizes vary, so the physical table, entry, payload, and
// detail regions are each represented by one ordered storage array.
struct EntityUiResourceSelectorLargeStorage
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[24];
    EntityUiResourceSelectorTable table_storage[23];
    EntityUiResourceSelectorEntry entry_storage[120];
    EntityUiResourceSelectorPayload payload_storage[35];
    EntityUiResourceSelectorDetailEntry detail_storage[108];
};

// This physical selector has one null choice and four real tables. Its backing
// records are contiguous in ROM, so one aggregate preserves their order.
struct EntityUiResourceSelectorFiveChoiceStorage
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[5];
    EntityUiResourceSelectorTable table_storage[4];
    EntityUiResourceSelectorEntry entry_storage[22];
    EntityUiResourceSelectorPayload payload_storage[15];
    EntityUiResourceSelectorDetailEntry detail_storage[45];
};

struct EntityUiCallbackState
{
    u8 unknown_00[0x10];
    void * unknown_10;
    u8 unknown_14[0x1C];
    u8 value_30;
};

struct EntityUiHarvestSpriteState : public AEntity
{
    EntityUiHarvestSpriteState(GameObject * game_object, Location const & location)
        : AEntity(game_object, location)
    {
    }

    u8 unknown_18[0x18];
    u8 entry_index;
    u8 unknown_31[3];
    HarvestSprite * harvest_sprite;
    EntityUiHarvestSpriteEntry const * entries;
    void * unknown_3C;
};

extern "C" char const gText_NotAvailable[];

extern "C" EntityUiResourceSelectorStorage const gUnk_080F33B8;
extern "C" EntityUiResourceSelectorExtendedStorage const gUnk_080F3408;
extern "C" EntityUiResourceSelectorLargeStorage const gUnk_080F35E4;
extern "C" EntityUiResourceSelectorFiveChoiceStorage const gUnk_080F3FD8;

extern "C" char const gCppRuntimeBadAlloc_EntityUiBeforeOffsets[];
extern "C" char const gCppRuntimeError_EntityUiBeforeOffsets[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiAfterOffsets[];
extern "C" char const gCppRuntimeError_EntityUiAfterOffsets[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiFirst[];
extern "C" char const gCppRuntimeError_EntityUiFirst[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiSecond[];
extern "C" char const gCppRuntimeError_EntityUiSecond[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiThird[];
extern "C" char const gCppRuntimeError_EntityUiThird[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiFourth[];
extern "C" char const gCppRuntimeError_EntityUiFourth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiFifth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiSixth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiSeventh[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiEighth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiNinth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiTenth[];

#endif
