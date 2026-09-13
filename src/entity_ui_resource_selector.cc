#include "entity_ui_resource_selector.hh"

// This region-specific native callback chooses one of the descriptor's three
// table pointers.  Its input object type remains unmapped.
#if defined(REGION_JP)
extern "C" u32 func_0803DBC4(void const * state);
#else
extern "C" u32 func_0803DF50(void const * state);
#endif

// The physical order below is descriptor, table-choice array, two tables,
// two entries, the shared payload, and the C++ runtime string immediately
// following it.  Keeping it as one aggregate preserves the real internal
// relocations rather than embedding raw ROM addresses.
extern "C" EntityUiResourceSelectorStorage const gUnk_080F33B8 = {
        {
#if defined(REGION_JP)
            func_0803DBC4,
#else
            func_0803DF50,
#endif
            3,
            gUnk_080F33B8.table_choices,
        },
        {
            nullptr,
            &gUnk_080F33B8.table_storage[0],
            &gUnk_080F33B8.table_storage[1],
        },
        {
            { 1, 0, &gUnk_080F33B8.entry_storage[0] },
            { 1, 0, &gUnk_080F33B8.entry_storage[1] },
        },
        {
            { 0, &gUnk_080F33B8.payload },
            { 0, &gUnk_080F33B8.payload },
        },
        { nullptr, 0x0000, 0x0080, 0x0060, 0x000E },
    };

// "bad_alloc" has one automatic C terminator. The two subsequent zero bytes
// are linker alignment before the next raw object, not part of this string.
#include FOMT_TEXT_INCLUDE(entity_ui_resource_selector.cc)

#if defined(REGION_JP)
extern "C" u32 func_0803DC08(void const * state);
#else
extern "C" u32 func_0803DF94(void const * state);
#endif

// This is the immediately following, larger instance of the same selector
// family. The repeated entries intentionally retain their original pointers:
// native readers distinguish table placement even when a payload is shared.
extern "C" EntityUiResourceSelectorExtendedStorage const gUnk_080F3408 = {
        {
#if defined(REGION_JP)
            func_0803DC08,
#else
            func_0803DF94,
#endif
            5,
            gUnk_080F3408.table_choices,
        },
        {
            nullptr,
            &gUnk_080F3408.table_storage[0],
            &gUnk_080F3408.table_storage[1],
            &gUnk_080F3408.table_storage[2],
            &gUnk_080F3408.table_storage[3],
        },
        {
            { 3, 0, gUnk_080F3408.entry_storage_0 },
            { 7, 0, gUnk_080F3408.entry_storage_1 },
            { 5, 0, gUnk_080F3408.entry_storage_2 },
            { 1, 0, gUnk_080F3408.entry_storage_3 },
        },
        {
            { 0x0000, &gUnk_080F3408.payload_storage[0] },
            { 0x0078, &gUnk_080F3408.payload_storage[1] },
            { 0x02D0, &gUnk_080F3408.payload_storage[0] },
        },
        {
            { 0x0000, &gUnk_080F3408.payload_storage[0] },
            { 0x00F3, &gUnk_080F3408.payload_storage[2] },
            { 0x010E, &gUnk_080F3408.payload_storage[3] },
            { 0x01A7, &gUnk_080F3408.payload_storage[4] },
            { 0x01BB, &gUnk_080F3408.payload_storage[5] },
            { 0x0258, &gUnk_080F3408.payload_storage[6] },
            { 0x0263, &gUnk_080F3408.payload_storage[0] },
        },
        {
            { 0x0000, &gUnk_080F3408.payload_storage[0] },
            { 0x01A7, &gUnk_080F3408.payload_storage[7] },
            { 0x01C4, &gUnk_080F3408.payload_storage[8] },
            { 0x025B, &gUnk_080F3408.payload_storage[9] },
            { 0x0278, &gUnk_080F3408.payload_storage[0] },
        },
        {
            { 0x0000, &gUnk_080F3408.payload_storage[0] },
        },
        {
            { nullptr, 0x0000, 0x0028, 0x0058, 0x0410 },
            { nullptr, 0x0000, 0x00E3, 0x0073, 0x000F },
            { gUnk_080F3408.detail_storage_0, 0x0003, 0x02B0, 0x00A0, 0x0005 },
            { nullptr, 0x0000, 0x0108, 0x009B, 0x040C },
            { gUnk_080F3408.detail_storage_1, 0x0003, 0x04D0, 0x009C, 0x0005 },
            { nullptr, 0x0000, 0x0028, 0x00C0, 0x0C13 },
            { gUnk_080F3408.detail_storage_2, 0x0003, 0x0358, 0x00A4, 0x0005 },
            { gUnk_080F3408.detail_storage_3, 0x0005, 0x02B0, 0x00A0, 0x0005 },
            { nullptr, 0x0000, 0x00E0, 0x00EB, 0x0C15 },
            { gUnk_080F3408.detail_storage_4, 0x0005, 0x0278, 0x01E8, 0x0005 },
        },
        {
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0018, 0x04D0, 0x0000, 0x0000 },
            { 0x001B, 0x009C, 0x0001, 0x0000 },
        },
        {
            { 0x0003, 0x00D8, 0x0001, 0x0000 },
            { 0x0012, 0x0358, 0x0000, 0x0000 },
            { 0x0014, 0x00A4, 0x0001, 0x0000 },
        },
        {
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0009, 0x02B0, 0x0000, 0x0000 },
            { 0x000B, 0x00A0, 0x0001, 0x0000 },
        },
        {
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0007, 0x0328, 0x0000, 0x0000 },
            { 0x0014, 0x0218, 0x0001, 0x0000 },
            { 0x001B, 0x0278, 0x0000, 0x0000 },
            { 0x001D, 0x01E8, 0x0001, 0x0000 },
        },
        {
            { 0x0002, 0x0218, 0x0001, 0x0000 },
            { 0x0009, 0x0328, 0x0000, 0x0000 },
            { 0x0016, 0x00D8, 0x0001, 0x0000 },
            { 0x001B, 0x02B0, 0x0000, 0x0000 },
            { 0x001D, 0x00A0, 0x0001, 0x0000 },
        },
    };

#include FOMT_TEXT_INCLUDE(entity_ui_resource_selector_1.cc)

#if defined(REGION_JP)
extern "C" u32 func_0803DC5C(void const * state);
#else
extern "C" u32 func_0803DFE8(void const * state);
#endif

// This 24-choice selector follows immediately in ROM. The aggregate keeps
// its table pointers, entries, payloads, and pointed detail records in their
// original physical order while giving every actual pointer a C++ relocation.
extern "C" EntityUiResourceSelectorLargeStorage const gUnk_080F35E4 = {
        {
#if defined(REGION_JP)
            func_0803DC5C,
#else
            func_0803DFE8,
#endif
            24,
            gUnk_080F35E4.table_choices,
        },
        {
            nullptr,
            &gUnk_080F35E4.table_storage[0],
            &gUnk_080F35E4.table_storage[1],
            &gUnk_080F35E4.table_storage[2],
            &gUnk_080F35E4.table_storage[3],
            &gUnk_080F35E4.table_storage[4],
            &gUnk_080F35E4.table_storage[5],
            &gUnk_080F35E4.table_storage[6],
            &gUnk_080F35E4.table_storage[7],
            &gUnk_080F35E4.table_storage[8],
            &gUnk_080F35E4.table_storage[9],
            &gUnk_080F35E4.table_storage[10],
            &gUnk_080F35E4.table_storage[11],
            &gUnk_080F35E4.table_storage[12],
            &gUnk_080F35E4.table_storage[13],
            &gUnk_080F35E4.table_storage[14],
            &gUnk_080F35E4.table_storage[15],
            &gUnk_080F35E4.table_storage[16],
            &gUnk_080F35E4.table_storage[17],
            &gUnk_080F35E4.table_storage[18],
            &gUnk_080F35E4.table_storage[19],
            &gUnk_080F35E4.table_storage[20],
            &gUnk_080F35E4.table_storage[21],
            &gUnk_080F35E4.table_storage[22],
        },
        {
            { 13, 0, &gUnk_080F35E4.entry_storage[0] },  // Choice 01.
            { 5, 0, &gUnk_080F35E4.entry_storage[13] },  // Choice 02.
            { 6, 0, &gUnk_080F35E4.entry_storage[18] },  // Choice 03.
            { 15, 0, &gUnk_080F35E4.entry_storage[24] }, // Choice 04.
            { 13, 0, &gUnk_080F35E4.entry_storage[39] }, // Choice 05.
            { 6, 0, &gUnk_080F35E4.entry_storage[52] },  // Choice 06.
            { 7, 0, &gUnk_080F35E4.entry_storage[58] },  // Choice 07.
            { 1, 0, &gUnk_080F35E4.entry_storage[65] },  // Choice 08.
            { 5, 0, &gUnk_080F35E4.entry_storage[66] },  // Choice 09.
            { 1, 0, &gUnk_080F35E4.entry_storage[71] },  // Choice 10.
            { 4, 0, &gUnk_080F35E4.entry_storage[72] },  // Choice 11.
            { 4, 0, &gUnk_080F35E4.entry_storage[76] },  // Choice 12.
            { 4, 0, &gUnk_080F35E4.entry_storage[80] },  // Choice 13.
            { 4, 0, &gUnk_080F35E4.entry_storage[84] },  // Choice 14.
            { 4, 0, &gUnk_080F35E4.entry_storage[88] },  // Choice 15.
            { 4, 0, &gUnk_080F35E4.entry_storage[92] },  // Choice 16.
            { 4, 0, &gUnk_080F35E4.entry_storage[96] },  // Choice 17.
            { 4, 0, &gUnk_080F35E4.entry_storage[100] }, // Choice 18.
            { 4, 0, &gUnk_080F35E4.entry_storage[104] }, // Choice 19.
            { 4, 0, &gUnk_080F35E4.entry_storage[108] }, // Choice 20.
            { 4, 0, &gUnk_080F35E4.entry_storage[112] }, // Choice 21.
            { 3, 0, &gUnk_080F35E4.entry_storage[116] }, // Choice 22.
            { 1, 0, &gUnk_080F35E4.entry_storage[119] }, // Choice 23.
        },
        {
            // Table 01.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[1] },
            { 0x007E, &gUnk_080F35E4.payload_storage[2] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[3] },
            { 0x00F6, &gUnk_080F35E4.payload_storage[0] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[4] },
            { 0x0258, &gUnk_080F35E4.payload_storage[0] },
            { 0x030C, &gUnk_080F35E4.payload_storage[5] },
            { 0x033A, &gUnk_080F35E4.payload_storage[6] },
            { 0x034B, &gUnk_080F35E4.payload_storage[7] },
            { 0x03C0, &gUnk_080F35E4.payload_storage[8] },
            { 0x03D2, &gUnk_080F35E4.payload_storage[9] },
            { 0x03FF, &gUnk_080F35E4.payload_storage[0] },
            // Table 02.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[4] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[0] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[4] },
            { 0x0258, &gUnk_080F35E4.payload_storage[0] },
            // Table 03.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[4] },
            { 0x030C, &gUnk_080F35E4.payload_storage[11] },
            { 0x0329, &gUnk_080F35E4.payload_storage[10] },
            { 0x03C9, &gUnk_080F35E4.payload_storage[12] },
            { 0x03E6, &gUnk_080F35E4.payload_storage[0] },
            // Table 04.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[1] },
            { 0x007E, &gUnk_080F35E4.payload_storage[2] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[3] },
            { 0x00F6, &gUnk_080F35E4.payload_storage[0] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[5] },
            { 0x01D2, &gUnk_080F35E4.payload_storage[13] },
            { 0x01E0, &gUnk_080F35E4.payload_storage[14] },
            { 0x0258, &gUnk_080F35E4.payload_storage[15] },
            { 0x0267, &gUnk_080F35E4.payload_storage[9] },
            { 0x0294, &gUnk_080F35E4.payload_storage[0] },
            { 0x030C, &gUnk_080F35E4.payload_storage[11] },
            { 0x0329, &gUnk_080F35E4.payload_storage[10] },
            { 0x03C9, &gUnk_080F35E4.payload_storage[12] },
            { 0x03E6, &gUnk_080F35E4.payload_storage[0] },
            // Table 05.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0078, &gUnk_080F35E4.payload_storage[4] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[0] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[5] },
            { 0x01D2, &gUnk_080F35E4.payload_storage[16] },
            { 0x01E9, &gUnk_080F35E4.payload_storage[17] },
            { 0x0258, &gUnk_080F35E4.payload_storage[18] },
            { 0x026F, &gUnk_080F35E4.payload_storage[9] },
            { 0x029C, &gUnk_080F35E4.payload_storage[0] },
            { 0x030C, &gUnk_080F35E4.payload_storage[11] },
            { 0x0329, &gUnk_080F35E4.payload_storage[10] },
            { 0x03C9, &gUnk_080F35E4.payload_storage[12] },
            { 0x03E6, &gUnk_080F35E4.payload_storage[0] },
            // Table 06.
            { 0x0000, &gUnk_080F35E4.payload_storage[20] },
            { 0x0078, &gUnk_080F35E4.payload_storage[21] },
            { 0x007D, &gUnk_080F35E4.payload_storage[22] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[23] },
            { 0x00F5, &gUnk_080F35E4.payload_storage[19] },
            { 0x030C, &gUnk_080F35E4.payload_storage[20] },
            // Table 07.
            { 0x0000, &gUnk_080F35E4.payload_storage[20] },
            { 0x0041, &gUnk_080F35E4.payload_storage[24] },
            { 0x005F, &gUnk_080F35E4.payload_storage[25] },
            { 0x008C, &gUnk_080F35E4.payload_storage[4] },
            { 0x030C, &gUnk_080F35E4.payload_storage[32] },
            { 0x033A, &gUnk_080F35E4.payload_storage[33] },
            { 0x0358, &gUnk_080F35E4.payload_storage[20] },
            // Table 08.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            // Table 09.
            { 0x0000, &gUnk_080F35E4.payload_storage[0] },
            { 0x0168, &gUnk_080F35E4.payload_storage[26] },
            { 0x0172, &gUnk_080F35E4.payload_storage[27] },
            { 0x01A4, &gUnk_080F35E4.payload_storage[31] },
            { 0x01AE, &gUnk_080F35E4.payload_storage[0] },
            // Table 10.
            { 0x0000, &gUnk_080F35E4.payload_storage[19] },
            // Table 11.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 12.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x00B4, &gUnk_080F35E4.payload_storage[4] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 13.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 14.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 15.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x00B4, &gUnk_080F35E4.payload_storage[4] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 16.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 17.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 18.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 19.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 20.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 21.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x00F0, &gUnk_080F35E4.payload_storage[34] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[30] },
            { 0x0348, &gUnk_080F35E4.payload_storage[29] },
            // Table 22.
            { 0x0000, &gUnk_080F35E4.payload_storage[30] },
            { 0x012C, &gUnk_080F35E4.payload_storage[28] },
            { 0x02D0, &gUnk_080F35E4.payload_storage[34] },
            // Table 23.
            { 0x0000, &gUnk_080F35E4.payload_storage[29] },
        },
        {
            { &gUnk_080F35E4.detail_storage[0], 0x0004, 0x0068, 0x0068, 0x1010 },
            { &gUnk_080F35E4.detail_storage[4], 0x0003, 0x02B0, 0x00A0, 0x0005 },
            { nullptr, 0x0000, 0x02F0, 0x00B8, 0x0005 },
            { &gUnk_080F35E4.detail_storage[7], 0x0003, 0x02F0, 0x00B8, 0x0005 },
            { &gUnk_080F35E4.detail_storage[10], 0x0002, 0x0080, 0x0050, 0x100F },
            { &gUnk_080F35E4.detail_storage[12], 0x0005, 0x02B0, 0x00A0, 0x0005 },
            { &gUnk_080F35E4.detail_storage[17], 0x0005, 0x0000, 0x0118, 0x0001 },
            { &gUnk_080F35E4.detail_storage[22], 0x0002, 0x0100, 0x0128, 0x1001 },
            { &gUnk_080F35E4.detail_storage[24], 0x0005, 0x0100, 0x0128, 0x0001 },
            { &gUnk_080F35E4.detail_storage[29], 0x0005, 0x04EC, 0x02C0, 0x0005 },
            { nullptr, 0x0000, 0x00D0, 0x0078, 0x0415 },
            { &gUnk_080F35E4.detail_storage[34], 0x0005, 0x02B0, 0x00A0, 0x0005 },
            { &gUnk_080F35E4.detail_storage[39], 0x0005, 0x0278, 0x01E8, 0x0005 },
            { &gUnk_080F35E4.detail_storage[44], 0x0008, 0x04B0, 0x0210, 0x0000 },
            { nullptr, 0x0000, 0x03F0, 0x01A8, 0x0400 },
            { &gUnk_080F35E4.detail_storage[52], 0x0008, 0x03F0, 0x01A8, 0x0000 },
            { &gUnk_080F35E4.detail_storage[60], 0x0003, 0x0340, 0x0000, 0x0003 },
            { &gUnk_080F35E4.detail_storage[63], 0x0002, 0x00A0, 0x00A0, 0x1028 },
            { &gUnk_080F35E4.detail_storage[65], 0x0003, 0x0264, 0x00F4, 0x0003 },
            { nullptr, 0x0000, 0x0058, 0x0068, 0x040A },
            { nullptr, 0x0000, 0x005A, 0x0050, 0x000B },
            { &gUnk_080F35E4.detail_storage[68], 0x0003, 0x023C, 0x00E3, 0x0007 },
            { &gUnk_080F35E4.detail_storage[71], 0x0002, 0x0220, 0x0138, 0x1007 },
            { &gUnk_080F35E4.detail_storage[73], 0x0003, 0x0220, 0x0138, 0x0007 },
            { &gUnk_080F35E4.detail_storage[76], 0x0005, 0x023C, 0x00E3, 0x0007 },
            { &gUnk_080F35E4.detail_storage[81], 0x0005, 0x0068, 0x02C0, 0x0005 },
            { &gUnk_080F35E4.detail_storage[86], 0x0002, 0x0154, 0x0000, 0x0002 },
            { nullptr, 0x0000, 0x00E4, 0x0091, 0x0402 },
            { &gUnk_080F35E4.detail_storage[88], 0x0004, 0x0070, 0x004C, 0x101D },
            { nullptr, 0x0000, 0x01B8, 0xFFD0, 0x001D },
            { &gUnk_080F35E4.detail_storage[92], 0x0004, 0x0100, 0x0098, 0x101D },
            { &gUnk_080F35E4.detail_storage[96], 0x0002, 0x00E4, 0x0091, 0x0002 },
            { &gUnk_080F35E4.detail_storage[98], 0x0005, 0x02B0, 0x00A0, 0x0005 },
            { &gUnk_080F35E4.detail_storage[103], 0x0005, 0x0068, 0x0000, 0x0007 },
            { nullptr, 0x0000, 0x0000, 0x0000, 0x0634 },
        },
        {
            { 0x0040, 0x0002, 0x0000, 0x0000 },
            { 0x00E0, 0x0002, 0x0078, 0x0004 },
            { 0x0068, 0x0002, 0x0000, 0x0004 },
            { 0x0068, 0x0002, 0x0078, 0x0003 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0005, 0x02F0, 0x0000, 0x0000 },
            { 0x0006, 0x00B8, 0x0001, 0x0000 },
            { 0x0001, 0x00D8, 0x0001, 0x0000 },
            { 0x0004, 0x02B0, 0x0000, 0x0000 },
            { 0x0006, 0x00A0, 0x0001, 0x0000 },
            { 0x0038, 0x0002, 0x0078, 0x0002 },
            { 0x0080, 0x0002, 0x0078, 0x0003 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0018, 0x04E0, 0x0000, 0x0000 },
            { 0x0019, 0x00F0, 0x0001, 0x0000 },
            { 0x001A, 0x04EC, 0x0000, 0x0000 },
            { 0x002E, 0x02E0, 0x0001, 0x0000 },
            { 0x0003, 0x0040, 0x0000, 0x0000 },
            { 0x0006, 0x0168, 0x0001, 0x0000 },
            { 0x0008, 0x0068, 0x0000, 0x0000 },
            { 0x000B, 0x0128, 0x0001, 0x0000 },
            { 0x0011, 0x0100, 0x0000, 0x0000 },
            { 0x0150, 0x0002, 0x0078, 0x0007 },
            { 0x0128, 0x0002, 0x0078, 0x0007 },
            { 0x0006, 0x0068, 0x0000, 0x0000 },
            { 0x0009, 0x0168, 0x0001, 0x0000 },
            { 0x000B, 0x0040, 0x0000, 0x0000 },
            { 0x000E, 0x0118, 0x0001, 0x0000 },
            { 0x0012, 0xFFF0, 0x0000, 0x0000 },
            { 0x0013, 0x00F0, 0x0001, 0x0000 },
            { 0x0014, 0x04E0, 0x0000, 0x0000 },
            { 0x0015, 0x00D8, 0x0001, 0x0000 },
            { 0x002B, 0x02B0, 0x0000, 0x0000 },
            { 0x002D, 0x00A0, 0x0001, 0x0000 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0007, 0x0328, 0x0000, 0x0000 },
            { 0x0014, 0x0218, 0x0001, 0x0000 },
            { 0x001B, 0x0278, 0x0000, 0x0000 },
            { 0x001D, 0x01E8, 0x0001, 0x0000 },
            { 0x0002, 0x0218, 0x0001, 0x0000 },
            { 0x0009, 0x0328, 0x0000, 0x0000 },
            { 0x0016, 0x00D8, 0x0001, 0x0000 },
            { 0x001B, 0x02B0, 0x0000, 0x0000 },
            { 0x001D, 0x00A0, 0x0001, 0x0000 },
            { 0x0001, 0x0498, 0x0000, 0x0000 },
            { 0x0002, 0x0200, 0x0001, 0x0000 },
            { 0x0003, 0x0488, 0x0000, 0x0000 },
            { 0x0004, 0x01F0, 0x0001, 0x0000 },
            { 0x0005, 0x0478, 0x0000, 0x0000 },
            { 0x0006, 0x01E0, 0x0001, 0x0000 },
            { 0x000B, 0x03F0, 0x0000, 0x0000 },
            { 0x000E, 0x01A8, 0x0001, 0x0000 },
            { 0x0003, 0x01E0, 0x0001, 0x0000 },
            { 0x0008, 0x0478, 0x0000, 0x0000 },
            { 0x0009, 0x01F0, 0x0001, 0x0000 },
            { 0x000A, 0x0488, 0x0000, 0x0000 },
            { 0x000B, 0x0200, 0x0001, 0x0000 },
            { 0x000C, 0x0498, 0x0000, 0x0000 },
            { 0x000D, 0x0210, 0x0001, 0x0000 },
            { 0x000F, 0x04C0, 0x0000, 0x0000 },
            { 0x000C, 0x0128, 0x0001, 0x0000 },
            { 0x0015, 0x0266, 0x0000, 0x0000 },
            { 0x0017, 0x00F4, 0x0001, 0x0000 },
            { 0x00D8, 0x0002, 0x0078, 0x0003 },
            { 0x00A0, 0x0002, 0x0078, 0x0002 },
            { 0x0002, 0x0128, 0x0001, 0x0000 },
            { 0x000B, 0x0340, 0x0000, 0x0000 },
            { 0x0017, 0x0000, 0x0001, 0x0000 },
            { 0x0001, 0x00F8, 0x0001, 0x0000 },
            { 0x0002, 0x0220, 0x0000, 0x0000 },
            { 0x0005, 0x0138, 0x0001, 0x0000 },
            { 0x0258, 0x0002, 0x0078, 0x0003 },
            { 0x0220, 0x0002, 0x0078, 0x0002 },
            { 0x0003, 0x00F8, 0x0001, 0x0000 },
            { 0x0004, 0x023C, 0x0000, 0x0000 },
            { 0x0005, 0x00E3, 0x0001, 0x0000 },
            { 0x0001, 0x00F8, 0x0001, 0x0000 },
            { 0x0005, 0x01D8, 0x0000, 0x0000 },
            { 0x0009, 0x0098, 0x0001, 0x0000 },
            { 0x0018, 0x0068, 0x0000, 0x0000 },
            { 0x001E, 0x0000, 0x0001, 0x0000 },
            { 0x0013, 0x00F0, 0x0001, 0x0000 },
            { 0x0014, 0x0090, 0x0000, 0x0000 },
            { 0x0015, 0x00D8, 0x0001, 0x0000 },
            { 0x002B, 0x02B0, 0x0000, 0x0000 },
            { 0x002D, 0x00A0, 0x0001, 0x0000 },
            { 0x0006, 0x0091, 0x0001, 0x0000 },
            { 0x000A, 0x00E4, 0x0000, 0x0000 },
            { 0x006C, 0x0002, 0x0078, 0x0006 },
            { 0x0080, 0x0002, 0x0078, 0x0003 },
            { 0x004C, 0x0002, 0x0078, 0x0007 },
            { 0x0070, 0x0002, 0x0078, 0x0002 },
            { 0x0060, 0x0002, 0x0000, 0x0004 },
            { 0x0148, 0x0002, 0x0078, 0x0003 },
            { 0x0100, 0x0002, 0x0000, 0x0000 },
            { 0x0098, 0x0002, 0x0078, 0x0004 },
            { 0x0004, 0x0154, 0x0000, 0x0000 },
            { 0x000A, 0x0000, 0x0001, 0x0000 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0018, 0x0090, 0x0000, 0x0000 },
            { 0x0019, 0x00F0, 0x0001, 0x0000 },
            { 0x001A, 0x0068, 0x0000, 0x0000 },
            { 0x002E, 0x02E0, 0x0001, 0x0000 },
            { 0x0006, 0x0098, 0x0001, 0x0000 },
            { 0x0015, 0x01D8, 0x0000, 0x0000 },
            { 0x0019, 0x00F8, 0x0001, 0x0000 },
            { 0x001D, 0x023C, 0x0000, 0x0000 },
            { 0x001E, 0x00E3, 0x0001, 0x0000 },
        },
    };

#include FOMT_TEXT_INCLUDE(entity_ui_resource_selector_2.cc)

#if defined(REGION_JP)
extern "C" u32 func_0803DE18(void const * state);
#else
extern "C" u32 func_0803E1A4(void const * state);
#endif

// The next ROM object has five choices, of which the first is null. Keep its
// tables, entry records, payloads, and detail records contiguous and ordered.
extern "C" EntityUiResourceSelectorFiveChoiceStorage const gUnk_080F3FD8 = {
        {
#if defined(REGION_JP)
            func_0803DE18,
#else
            func_0803E1A4,
#endif
            5,
            gUnk_080F3FD8.table_choices,
        },
        {
            nullptr,
            &gUnk_080F3FD8.table_storage[0],
            &gUnk_080F3FD8.table_storage[1],
            &gUnk_080F3FD8.table_storage[2],
            &gUnk_080F3FD8.table_storage[3],
        },
        {
            { 7, 0, &gUnk_080F3FD8.entry_storage[0] },  // Choice 01.
            { 3, 0, &gUnk_080F3FD8.entry_storage[7] },  // Choice 02.
            { 11, 0, &gUnk_080F3FD8.entry_storage[10] }, // Choice 03.
            { 1, 0, &gUnk_080F3FD8.entry_storage[21] }, // Choice 04.
        },
        {
            // Table 01.
            { 0x0000, &gUnk_080F3FD8.payload_storage[0] },
            { 0x01A4, &gUnk_080F3FD8.payload_storage[1] },
            { 0x01D2, &gUnk_080F3FD8.payload_storage[2] },
            { 0x01D9, &gUnk_080F3FD8.payload_storage[3] },
            { 0x0258, &gUnk_080F3FD8.payload_storage[4] },
            { 0x025F, &gUnk_080F3FD8.payload_storage[5] },
            { 0x028C, &gUnk_080F3FD8.payload_storage[0] },
            // Table 02.
            { 0x0000, &gUnk_080F3FD8.payload_storage[0] },
            { 0x01A4, &gUnk_080F3FD8.payload_storage[12] },
            { 0x0258, &gUnk_080F3FD8.payload_storage[0] },
            // Table 03.
            { 0x0000, &gUnk_080F3FD8.payload_storage[0] },
            { 0x003C, &gUnk_080F3FD8.payload_storage[1] },
            { 0x006A, &gUnk_080F3FD8.payload_storage[6] },
            { 0x0083, &gUnk_080F3FD8.payload_storage[7] },
            { 0x00F3, &gUnk_080F3FD8.payload_storage[8] },
            { 0x011E, &gUnk_080F3FD8.payload_storage[9] },
            { 0x01A7, &gUnk_080F3FD8.payload_storage[10] },
            { 0x01C5, &gUnk_080F3FD8.payload_storage[11] },
            { 0x01E7, &gUnk_080F3FD8.payload_storage[13] },
            { 0x0258, &gUnk_080F3FD8.payload_storage[14] },
            { 0x0268, &gUnk_080F3FD8.payload_storage[0] },
            // Table 04.
            { 0x0000, &gUnk_080F3FD8.payload_storage[0] },
        },
        {
            { &gUnk_080F3FD8.detail_storage[0], 0x0002, 0x0088, 0x0050, 0x1010 },
            { &gUnk_080F3FD8.detail_storage[2], 0x0005, 0x02B0, 0x00A0, 0x0005 },
            { &gUnk_080F3FD8.detail_storage[7], 0x0002, 0x00DC, 0x0000, 0x0006 },
            { nullptr, 0x0000, 0x0148, 0x0050, 0x0006 },
            { &gUnk_080F3FD8.detail_storage[9], 0x0002, 0x0148, 0x0050, 0x0006 },
            { &gUnk_080F3FD8.detail_storage[11], 0x0005, 0x04EC, 0x02C0, 0x0005 },
            { &gUnk_080F3FD8.detail_storage[16], 0x0007, 0x04F8, 0x0000, 0x0007 },
            { nullptr, 0x0000, 0x0078, 0x0078, 0x0029 },
            { &gUnk_080F3FD8.detail_storage[23], 0x0007, 0x03E0, 0x00EA, 0x0007 },
            { nullptr, 0x0000, 0x00C0, 0x008A, 0x000A },
            { &gUnk_080F3FD8.detail_storage[30], 0x0005, 0x023C, 0x00E3, 0x0007 },
            { &gUnk_080F3FD8.detail_storage[35], 0x0005, 0x0068, 0x02C0, 0x0005 },
            { &gUnk_080F3FD8.detail_storage[40], 0x0002, 0x0100, 0x0050, 0x100F },
            { nullptr, 0x0000, 0x0070, 0x0088, 0x040E },
            { &gUnk_080F3FD8.detail_storage[42], 0x0003, 0x0190, 0x00A0, 0x0005 },
        },
        {
            { 0x0110, 0x0002, 0x0078, 0x0003 },
            { 0x0088, 0x0002, 0x0078, 0x0002 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x0018, 0x04E0, 0x0000, 0x0000 },
            { 0x0019, 0x00F0, 0x0001, 0x0000 },
            { 0x001A, 0x04EC, 0x0000, 0x0000 },
            { 0x002E, 0x02E0, 0x0001, 0x0000 },
            { 0x0003, 0x0050, 0x0001, 0x0000 },
            { 0x0007, 0x0148, 0x0000, 0x0000 },
            { 0x0004, 0x00DC, 0x0000, 0x0000 },
            { 0x0007, 0x0000, 0x0001, 0x0000 },
            { 0x0013, 0x00F0, 0x0001, 0x0000 },
            { 0x0014, 0x04E0, 0x0000, 0x0000 },
            { 0x0015, 0x00D8, 0x0001, 0x0000 },
            { 0x002B, 0x02B0, 0x0000, 0x0000 },
            { 0x002D, 0x00A0, 0x0001, 0x0000 },
            { 0x0005, 0x0080, 0x0001, 0x0000 },
            { 0x0006, 0x04E0, 0x0000, 0x0000 },
            { 0x0007, 0x0098, 0x0001, 0x0000 },
            { 0x000F, 0x0424, 0x0000, 0x0000 },
            { 0x0014, 0x0118, 0x0001, 0x0000 },
            { 0x0017, 0x03E0, 0x0000, 0x0000 },
            { 0x0019, 0x00E8, 0x0001, 0x0000 },
            { 0x0002, 0x0118, 0x0001, 0x0000 },
            { 0x0005, 0x0424, 0x0000, 0x0000 },
            { 0x000A, 0x0098, 0x0001, 0x0000 },
            { 0x0022, 0x01D8, 0x0000, 0x0000 },
            { 0x0026, 0x00F8, 0x0001, 0x0000 },
            { 0x002A, 0x023C, 0x0000, 0x0000 },
            { 0x002B, 0x00E3, 0x0001, 0x0000 },
            { 0x0001, 0x00F8, 0x0001, 0x0000 },
            { 0x0005, 0x01D8, 0x0000, 0x0000 },
            { 0x0009, 0x0098, 0x0001, 0x0000 },
            { 0x0018, 0x0068, 0x0000, 0x0000 },
            { 0x001E, 0x0000, 0x0001, 0x0000 },
            { 0x0013, 0x00F0, 0x0001, 0x0000 },
            { 0x0015, 0x0090, 0x0000, 0x0000 },
            { 0x0016, 0x00D8, 0x0001, 0x0000 },
            { 0x0020, 0x0190, 0x0000, 0x0000 },
            { 0x0022, 0x00A0, 0x0001, 0x0000 },
            { 0x00C8, 0x0002, 0x0078, 0x0002 },
            { 0x0100, 0x0002, 0x0078, 0x0003 },
            { 0x0002, 0x00D8, 0x0001, 0x0000 },
            { 0x000E, 0x02B0, 0x0000, 0x0000 },
            { 0x0010, 0x00A0, 0x0001, 0x0000 },
        },
    };

#include FOMT_TEXT_INCLUDE(entity_ui_resource_selector_3.cc)
