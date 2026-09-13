#ifndef ENTITY_UI_RESOURCE_SELECTOR_HH
#define ENTITY_UI_RESOURCE_SELECTOR_HH

#include "prelude.h"

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

extern "C" EntityUiResourceSelectorStorage const gUnk_080F33B8;
extern "C" EntityUiResourceSelectorExtendedStorage const gUnk_080F3408;
extern "C" EntityUiResourceSelectorLargeStorage const gUnk_080F35E4;
extern "C" EntityUiResourceSelectorFiveChoiceStorage const gUnk_080F3FD8;

#endif // ENTITY_UI_RESOURCE_SELECTOR_HH
