#ifndef NPC_SCHEDULE_DATA_HH
#define NPC_SCHEDULE_DATA_HH

#include "data_schedules.hh"

// This is one physical ROM object: descriptor, table pointers, two tables,
// two entries, and their shared payload. Its first member is the label used
// by the native NPC schedule code.
struct NpcScheduleStorage
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entry_storage[2];
    PathInfo payload;
};

struct NpcScheduleDetailEntry
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
};

// The next physical selector has the same leading layout, followed by four
// indexed tables, ten payload records, and five pointed detail arrays.
struct NpcScheduleExtendedStorage
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage_0[3];
    ScheduleEntry entry_storage_1[7];
    ScheduleEntry entry_storage_2[5];
    ScheduleEntry entry_storage_3[1];
    PathInfo payload_storage[10];
    NpcScheduleDetailEntry detail_storage_0[3];
    NpcScheduleDetailEntry detail_storage_1[3];
    NpcScheduleDetailEntry detail_storage_2[3];
    NpcScheduleDetailEntry detail_storage_3[5];
    NpcScheduleDetailEntry detail_storage_4[5];
};

// The following selector is a larger contiguous instance of the same format.
// Its individual table sizes vary, so the physical table, entry, payload, and
// detail regions are each represented by one ordered storage array.
struct NpcScheduleLargeStorage
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[24];
    Schedule table_storage[23];
    ScheduleEntry entry_storage[120];
    PathInfo payload_storage[35];
    NpcScheduleDetailEntry detail_storage[108];
};

// This physical selector has one null choice and four real tables. Its backing
// records are contiguous in ROM, so one aggregate preserves their order.
struct NpcScheduleFiveChoiceStorage
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage[22];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[45];
};

struct NpcScheduleStorage_080F42F0
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[4];
    Schedule table_storage[3];
    ScheduleEntry entry_storage[10];
    PathInfo payload_storage[5];
    NpcScheduleDetailEntry detail_storage[4];
};

struct NpcScheduleStorage_080F43DC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[19];
    Schedule table_storage[18];
    ScheduleEntry entry_storage[83];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[43];
};

struct NpcScheduleStorage_080F4974
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[2];
    Schedule table_storage[1];
    ScheduleEntry entry_storage[1];
    PathInfo payload_storage[1];
    NpcScheduleDetailEntry detail_storage[2];
};

struct NpcScheduleStorage_080F49C0
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage[30];
    PathInfo payload_storage[10];
    NpcScheduleDetailEntry detail_storage[64];
};

struct NpcScheduleStorage_080F4D74
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[19];
    Schedule table_storage[18];
    ScheduleEntry entry_storage[90];
    PathInfo payload_storage[26];
    NpcScheduleDetailEntry detail_storage[90];
};

struct NpcScheduleStorage_080F5540
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[32];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[70];
};

struct NpcScheduleStorage_080F597C
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entry_storage[2];
    PathInfo payload_storage[1];
};

struct NpcScheduleStorage_080F59CC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[8];
    Schedule table_storage[7];
    ScheduleEntry entry_storage[43];
    PathInfo payload_storage[18];
    NpcScheduleDetailEntry detail_storage[37];
};

struct NpcScheduleStorage_080F5D94
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[17];
    Schedule table_storage[16];
    ScheduleEntry entry_storage[63];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[28];
};

struct NpcScheduleStorage_080F61FC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[13];
    PathInfo payload_storage[7];
    NpcScheduleDetailEntry detail_storage[12];
};

struct NpcScheduleStorage_080F6370
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[41];
    PathInfo payload_storage[13];
    NpcScheduleDetailEntry detail_storage[35];
};

struct NpcScheduleStorage_080F66C4
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[39];
    PathInfo payload_storage[19];
    NpcScheduleDetailEntry detail_storage[59];
};

struct NpcScheduleStorage_080F6B10
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[2];
    Schedule table_storage[1];
    ScheduleEntry entry_storage[1];
    PathInfo payload_storage[1];
};

struct NpcScheduleStorage_080F6B4C
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[3];
    Schedule table_storage[2];
    ScheduleEntry entry_storage[17];
    PathInfo payload_storage[14];
    NpcScheduleDetailEntry detail_storage[39];
};

struct NpcScheduleStorage_080F6DE8
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[10];
    Schedule table_storage[9];
    ScheduleEntry entry_storage[23];
    PathInfo payload_storage[10];
    NpcScheduleDetailEntry detail_storage[11];
};

struct NpcScheduleStorage_080F6FF8
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage[22];
    PathInfo payload_storage[12];
    NpcScheduleDetailEntry detail_storage[34];
};

struct NpcScheduleStorage_080F7294
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[10];
    Schedule table_storage[9];
    ScheduleEntry entry_storage[68];
    PathInfo payload_storage[22];
    NpcScheduleDetailEntry detail_storage[55];
};

struct NpcScheduleStorage_080F77FC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[6];
    Schedule table_storage[5];
    ScheduleEntry entry_storage[37];
    PathInfo payload_storage[15];
    NpcScheduleDetailEntry detail_storage[34];
};

struct NpcScheduleStorage_080F7B40
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[15];
    Schedule table_storage[14];
    ScheduleEntry entry_storage[47];
    PathInfo payload_storage[24];
    NpcScheduleDetailEntry detail_storage[100];
};

struct NpcScheduleStorage_080F81BC
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[7];
    Schedule table_storage[6];
    ScheduleEntry entry_storage[40];
    PathInfo payload_storage[18];
    NpcScheduleDetailEntry detail_storage[72];
};

struct NpcScheduleStorage_080F8678
{
    ScheduleInfo descriptor;
    Schedule const * const table_choices[5];
    Schedule table_storage[4];
    ScheduleEntry entry_storage[24];
    PathInfo payload_storage[13];
    NpcScheduleDetailEntry detail_storage[56];
};

extern "C" NpcScheduleStorage const gUnk_080F33B8;
extern "C" NpcScheduleExtendedStorage const gUnk_080F3408;
extern "C" NpcScheduleLargeStorage const gUnk_080F35E4;
extern "C" NpcScheduleFiveChoiceStorage const gUnk_080F3FD8;

extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelectorExtended[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelectorLarge[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelectorFiveChoice[];

extern "C" NpcScheduleStorage_080F42F0 const gUnk_080F42F0;
extern "C" NpcScheduleStorage_080F43DC const gUnk_080F43DC;
extern "C" NpcScheduleStorage_080F4974 const gUnk_080F4974;
extern "C" NpcScheduleStorage_080F49C0 const gUnk_080F49C0;
extern "C" NpcScheduleStorage_080F4D74 const gUnk_080F4D74;
extern "C" NpcScheduleStorage_080F5540 const gUnk_080F5540;
extern "C" NpcScheduleStorage_080F597C const gUnk_080F597C;
extern "C" NpcScheduleStorage_080F59CC const gUnk_080F59CC;
extern "C" NpcScheduleStorage_080F5D94 const gUnk_080F5D94;
extern "C" NpcScheduleStorage_080F61FC const gUnk_080F61FC;
extern "C" NpcScheduleStorage_080F6370 const gUnk_080F6370;
extern "C" NpcScheduleStorage_080F66C4 const gUnk_080F66C4;
extern "C" NpcScheduleStorage_080F6B10 const gUnk_080F6B10;
extern "C" NpcScheduleStorage_080F6B4C const gUnk_080F6B4C;
extern "C" NpcScheduleStorage_080F6DE8 const gUnk_080F6DE8;
extern "C" NpcScheduleStorage_080F6FF8 const gUnk_080F6FF8;
extern "C" NpcScheduleStorage_080F7294 const gUnk_080F7294;
extern "C" NpcScheduleStorage_080F77FC const gUnk_080F77FC;
extern "C" NpcScheduleStorage_080F7B40 const gUnk_080F7B40;
extern "C" NpcScheduleStorage_080F81BC const gUnk_080F81BC;
extern "C" NpcScheduleStorage_080F8678 const gUnk_080F8678;

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

#endif // NPC_SCHEDULE_DATA_HH
