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

struct EntityUiResourceSelectorStorage_080F42F0
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[4];
    EntityUiResourceSelectorTable table_storage[3];
    EntityUiResourceSelectorEntry entry_storage[10];
    EntityUiResourceSelectorPayload payload_storage[5];
    EntityUiResourceSelectorDetailEntry detail_storage[4];
};

struct EntityUiResourceSelectorStorage_080F43DC
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[19];
    EntityUiResourceSelectorTable table_storage[18];
    EntityUiResourceSelectorEntry entry_storage[83];
    EntityUiResourceSelectorPayload payload_storage[15];
    EntityUiResourceSelectorDetailEntry detail_storage[43];
};

struct EntityUiResourceSelectorStorage_080F4974
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[2];
    EntityUiResourceSelectorTable table_storage[1];
    EntityUiResourceSelectorEntry entry_storage[1];
    EntityUiResourceSelectorPayload payload_storage[1];
    EntityUiResourceSelectorDetailEntry detail_storage[2];
};

struct EntityUiResourceSelectorStorage_080F49C0
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[5];
    EntityUiResourceSelectorTable table_storage[4];
    EntityUiResourceSelectorEntry entry_storage[30];
    EntityUiResourceSelectorPayload payload_storage[10];
    EntityUiResourceSelectorDetailEntry detail_storage[64];
};

struct EntityUiResourceSelectorStorage_080F4D74
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[19];
    EntityUiResourceSelectorTable table_storage[18];
    EntityUiResourceSelectorEntry entry_storage[90];
    EntityUiResourceSelectorPayload payload_storage[26];
    EntityUiResourceSelectorDetailEntry detail_storage[90];
};

struct EntityUiResourceSelectorStorage_080F5540
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[6];
    EntityUiResourceSelectorTable table_storage[5];
    EntityUiResourceSelectorEntry entry_storage[32];
    EntityUiResourceSelectorPayload payload_storage[15];
    EntityUiResourceSelectorDetailEntry detail_storage[70];
};

struct EntityUiResourceSelectorStorage_080F597C
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[3];
    EntityUiResourceSelectorTable table_storage[2];
    EntityUiResourceSelectorEntry entry_storage[2];
    EntityUiResourceSelectorPayload payload_storage[1];
};

struct EntityUiResourceSelectorStorage_080F59CC
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[8];
    EntityUiResourceSelectorTable table_storage[7];
    EntityUiResourceSelectorEntry entry_storage[43];
    EntityUiResourceSelectorPayload payload_storage[18];
    EntityUiResourceSelectorDetailEntry detail_storage[37];
};

struct EntityUiResourceSelectorStorage_080F5D94
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[17];
    EntityUiResourceSelectorTable table_storage[16];
    EntityUiResourceSelectorEntry entry_storage[63];
    EntityUiResourceSelectorPayload payload_storage[15];
    EntityUiResourceSelectorDetailEntry detail_storage[28];
};

struct EntityUiResourceSelectorStorage_080F61FC
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[6];
    EntityUiResourceSelectorTable table_storage[5];
    EntityUiResourceSelectorEntry entry_storage[13];
    EntityUiResourceSelectorPayload payload_storage[7];
    EntityUiResourceSelectorDetailEntry detail_storage[12];
};

struct EntityUiResourceSelectorStorage_080F6370
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[6];
    EntityUiResourceSelectorTable table_storage[5];
    EntityUiResourceSelectorEntry entry_storage[41];
    EntityUiResourceSelectorPayload payload_storage[13];
    EntityUiResourceSelectorDetailEntry detail_storage[35];
};

struct EntityUiResourceSelectorStorage_080F66C4
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[6];
    EntityUiResourceSelectorTable table_storage[5];
    EntityUiResourceSelectorEntry entry_storage[39];
    EntityUiResourceSelectorPayload payload_storage[19];
    EntityUiResourceSelectorDetailEntry detail_storage[59];
};

struct EntityUiResourceSelectorStorage_080F6B10
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[2];
    EntityUiResourceSelectorTable table_storage[1];
    EntityUiResourceSelectorEntry entry_storage[1];
    EntityUiResourceSelectorPayload payload_storage[1];
};

struct EntityUiResourceSelectorStorage_080F6B4C
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[3];
    EntityUiResourceSelectorTable table_storage[2];
    EntityUiResourceSelectorEntry entry_storage[17];
    EntityUiResourceSelectorPayload payload_storage[14];
    EntityUiResourceSelectorDetailEntry detail_storage[39];
};

struct EntityUiResourceSelectorStorage_080F6DE8
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[10];
    EntityUiResourceSelectorTable table_storage[9];
    EntityUiResourceSelectorEntry entry_storage[23];
    EntityUiResourceSelectorPayload payload_storage[10];
    EntityUiResourceSelectorDetailEntry detail_storage[11];
};

struct EntityUiResourceSelectorStorage_080F6FF8
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[5];
    EntityUiResourceSelectorTable table_storage[4];
    EntityUiResourceSelectorEntry entry_storage[22];
    EntityUiResourceSelectorPayload payload_storage[12];
    EntityUiResourceSelectorDetailEntry detail_storage[34];
};

struct EntityUiResourceSelectorStorage_080F7294
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[10];
    EntityUiResourceSelectorTable table_storage[9];
    EntityUiResourceSelectorEntry entry_storage[68];
    EntityUiResourceSelectorPayload payload_storage[22];
    EntityUiResourceSelectorDetailEntry detail_storage[55];
};

struct EntityUiResourceSelectorStorage_080F77FC
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[6];
    EntityUiResourceSelectorTable table_storage[5];
    EntityUiResourceSelectorEntry entry_storage[37];
    EntityUiResourceSelectorPayload payload_storage[15];
    EntityUiResourceSelectorDetailEntry detail_storage[34];
};

struct EntityUiResourceSelectorStorage_080F7B40
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[15];
    EntityUiResourceSelectorTable table_storage[14];
    EntityUiResourceSelectorEntry entry_storage[47];
    EntityUiResourceSelectorPayload payload_storage[24];
    EntityUiResourceSelectorDetailEntry detail_storage[100];
};

struct EntityUiResourceSelectorStorage_080F81BC
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[7];
    EntityUiResourceSelectorTable table_storage[6];
    EntityUiResourceSelectorEntry entry_storage[40];
    EntityUiResourceSelectorPayload payload_storage[18];
    EntityUiResourceSelectorDetailEntry detail_storage[72];
};

struct EntityUiResourceSelectorStorage_080F8678
{
    EntityUiResourceSelectorDescriptor descriptor;
    EntityUiResourceSelectorTable const * const table_choices[5];
    EntityUiResourceSelectorTable table_storage[4];
    EntityUiResourceSelectorEntry entry_storage[24];
    EntityUiResourceSelectorPayload payload_storage[13];
    EntityUiResourceSelectorDetailEntry detail_storage[56];
};

extern "C" EntityUiResourceSelectorStorage const gUnk_080F33B8;
extern "C" EntityUiResourceSelectorExtendedStorage const gUnk_080F3408;
extern "C" EntityUiResourceSelectorLargeStorage const gUnk_080F35E4;
extern "C" EntityUiResourceSelectorFiveChoiceStorage const gUnk_080F3FD8;

extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelectorExtended[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelectorLarge[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelectorFiveChoice[];

extern "C" EntityUiResourceSelectorStorage_080F42F0 const gUnk_080F42F0;
extern "C" EntityUiResourceSelectorStorage_080F43DC const gUnk_080F43DC;
extern "C" EntityUiResourceSelectorStorage_080F4974 const gUnk_080F4974;
extern "C" EntityUiResourceSelectorStorage_080F49C0 const gUnk_080F49C0;
extern "C" EntityUiResourceSelectorStorage_080F4D74 const gUnk_080F4D74;
extern "C" EntityUiResourceSelectorStorage_080F5540 const gUnk_080F5540;
extern "C" EntityUiResourceSelectorStorage_080F597C const gUnk_080F597C;
extern "C" EntityUiResourceSelectorStorage_080F59CC const gUnk_080F59CC;
extern "C" EntityUiResourceSelectorStorage_080F5D94 const gUnk_080F5D94;
extern "C" EntityUiResourceSelectorStorage_080F61FC const gUnk_080F61FC;
extern "C" EntityUiResourceSelectorStorage_080F6370 const gUnk_080F6370;
extern "C" EntityUiResourceSelectorStorage_080F66C4 const gUnk_080F66C4;
extern "C" EntityUiResourceSelectorStorage_080F6B10 const gUnk_080F6B10;
extern "C" EntityUiResourceSelectorStorage_080F6B4C const gUnk_080F6B4C;
extern "C" EntityUiResourceSelectorStorage_080F6DE8 const gUnk_080F6DE8;
extern "C" EntityUiResourceSelectorStorage_080F6FF8 const gUnk_080F6FF8;
extern "C" EntityUiResourceSelectorStorage_080F7294 const gUnk_080F7294;
extern "C" EntityUiResourceSelectorStorage_080F77FC const gUnk_080F77FC;
extern "C" EntityUiResourceSelectorStorage_080F7B40 const gUnk_080F7B40;
extern "C" EntityUiResourceSelectorStorage_080F81BC const gUnk_080F81BC;
extern "C" EntityUiResourceSelectorStorage_080F8678 const gUnk_080F8678;

extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F42F0[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F43DC[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F4974[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F49C0[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F4D74[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F5540[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F597C[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F59CC[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F5D94[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F61FC[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F6370[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F66C4[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F6B10[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F6B4C[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F6DE8[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F6FF8[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F7294[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F77FC[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F7B40[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector_080F81BC[];

#endif // ENTITY_UI_RESOURCE_SELECTOR_HH
