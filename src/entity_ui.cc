#include "entity_ui.hh"

#define FOMT_ENTITY_UI_TEXT_NOT_AVAILABLE
#if defined(REGION_JP)
#include "data/text/jp/entity_ui.cc"
#else
#include "data/text/us/entity_ui.cc"
#endif
#undef FOMT_ENTITY_UI_TEXT_NOT_AVAILABLE

// This contiguous block immediately precedes the existing Entity-UI data.
// Native callers establish the widths and offsets below; unresolved fields keep
// their original gUnk names instead of receiving speculative game meanings.

extern "C" u32 const gUnk_080F0E88[] ALIGN(1) = {
    0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
    0x00000006, 0x00000007, 0x00000008, 0x00000009, 0x0000000A,
    0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F,
    0x00000010, 0x00000011, 0x00000012, 0x00000013, 0x00000014,
    0x00000015, 0x00000016, 0x00000017, 0x00000018, 0x00000019,
    0x0000001A, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001E,
    0x0000001F, 0x00000020, 0x00000021, 0x00000022, 0x00000023,
    0x0000002C, 0x00000036, 0x00000037, 0x00000038, 0x00000039,
    0x0000003A, 0x0000003B, 0x0000003C, 0x0000003D, 0x0000003E,
    0x0000003F, 0x00000040, 0x00000041, 0x00000042, 0x00000043,
    0x00000044, 0x00000045, 0x00000046, 0x00000047, 0x00000048,
    0x00000049, 0x0000004A, 0x00000058, 0x00000059, 0x0000005A,
};

extern "C" u32 const gUnk_080F0F78[] ALIGN(1) = {
    0x0000002C, 0x00000036, 0x00000037, 0x00000038, 0x00000039,
    0x0000003A, 0x0000003B, 0x0000003C, 0x0000003D, 0x0000003E,
    0x0000003F, 0x00000040, 0x00000041, 0x00000042, 0x00000043,
    0x00000044, 0x00000045, 0x0000004A, 0x00000058, 0x00000059,
    0x0000005A,
};

extern "C" u16 const gUnk_080F0FCC[6][7] ALIGN(1) = {
    { 0x0166, 0x016A, 0x016E, 0x0172, 0x0176, 0x017A, 0x017E },
    { 0x001A, 0x001E, 0x0022, 0x0026, 0x002A, 0x002E, 0x0032 },
    { 0x01CE, 0x01D2, 0x01D6, 0x01DA, 0x01DE, 0x01E2, 0x01E6 },
    { 0x00C2, 0x00C6, 0x00CA, 0x00CE, 0x00D2, 0x00D6, 0x00DA },
    { 0x009E, 0x00A2, 0x00A6, 0x00AA, 0x00AE, 0x00B2, 0x00B6 },
    { 0x0052, 0x0056, 0x005A, 0x005E, 0x0062, 0x0066, 0x006A },
};

extern "C" EntityUiUnknownTableEntry const gUnk_080F1020[6][7] ALIGN(1) = {
    {
        { 0x018A, 0x006F, -2, -10, 0x00, 0x00 },
        { 0x018A, 0x0070, -3, -15, 0x00, 0x00 },
        { 0x018A, 0x0071, -5, -25, 0x00, 0x00 },
        { 0x0186, 0x0072, -7, -35, 0x00, 0x00 },
        { 0x0182, 0x0073, -10, -50, 0x00, 0x00 },
        { 0x0182, 0x0074, -20, -100, 0x00, 0x00 },
        { 0x0182, 0x0075, -35, 0, 0x00, 0x00 },
    },
    {
        { 0x0036, 0x0084, -2, -10, 0x00, 0x00 },
        { 0x0036, 0x0085, -4, -20, 0x00, 0x00 },
        { 0x0036, 0x0086, -5, -25, 0x00, 0x00 },
        { 0x003A, 0x0087, -8, -40, 0x00, 0x00 },
        { 0x003A, 0x0088, -10, -50, 0x00, 0x00 },
        { 0x003A, 0x0089, -20, -100, 0x00, 0x00 },
        { 0x003A, 0x008A, -10, 0, 0x00, 0x00 },
    },
    {
        { 0x01EE, 0x008B, -2, -10, 0x00, 0x00 },
        { 0x01F6, 0x008C, -4, -20, 0x00, 0x00 },
        { 0x01F6, 0x008D, -6, -30, 0x00, 0x00 },
        { 0x01F6, 0x008E, -8, -40, 0x00, 0x00 },
        { 0x01F6, 0x008F, -10, -50, 0x00, 0x00 },
        { 0x01F2, 0x0090, -20, -100, 0x00, 0x00 },
        { 0x01F2, 0x0091, -30, 0, 0x00, 0x00 },
    },
    {
        { 0x00DE, 0x0076, -2, -10, 0x00, 0x00 },
        { 0x00DE, 0x0077, -3, -15, 0x00, 0x00 },
        { 0x00DE, 0x0078, -4, -20, 0x00, 0x00 },
        { 0x00DE, 0x0079, -5, -25, 0x00, 0x00 },
        { 0x00DE, 0x007A, -7, -35, 0x00, 0x00 },
        { 0x00DE, 0x007B, -10, -100, 0x00, 0x00 },
        { 0x00DE, 0x007C, -40, 0, 0x00, 0x00 },
    },
    {
        { 0x00BA, 0x007D, -2, -10, 0x00, 0x00 },
        { 0x00BA, 0x007E, -4, -20, 0x00, 0x00 },
        { 0x00BA, 0x007F, -5, -25, 0x00, 0x00 },
        { 0x00BE, 0x0080, -8, -40, 0x00, 0x00 },
        { 0x00BE, 0x0081, -10, -50, 0x00, 0x00 },
        { 0x00BE, 0x0082, -15, -100, 0x00, 0x00 },
        { 0x00BE, 0x0083, -20, 0, 0x00, 0x00 },
    },
    {
        { 0x007A, 0x0095, -2, -2, 0x00, 0x00 },
        { 0x007A, 0x0096, -2, -2, 0x00, 0x00 },
        { 0x007A, 0x0097, -2, -2, 0x00, 0x00 },
        { 0x007A, 0x0098, -2, -2, 0x00, 0x00 },
        { 0x007A, 0x0099, -2, -2, 0x00, 0x00 },
        { 0x007A, 0x009A, -2, -2, 0x00, 0x00 },
        { 0x007A, 0x009B, -2, -2, 0x00, 0x00 },
    },
};

extern "C" u32 const gUnk_080F1170[] ALIGN(1) = {
    0x00120000, 0x00000014,
};

extern "C" u8 const gUnk_080F1178[] ALIGN(1) = {
    0x01, 0x02, 0x03, 0x04, 0x06, 0x0C, 0x12,
};

extern "C" u8 const gUnk_080F117F[] ALIGN(1) = {
    0x00, 0x18, 0x12, 0x00, 0x00,
};

extern "C" u8 const gUnk_080F1184[] ALIGN(1) = {
    0x00, 0x00, 0x13, 0x00, 0x14, 0x00, 0x00, 0x00,
};

extern "C" u8 const gUnk_080F118C[] ALIGN(1) = {
    0x00, 0x00, 0x14, 0x00, 0x14, 0x00, 0x00, 0x00,
};

extern "C" u8 const gUnk_080F1194[] ALIGN(1) = {
    0x00, 0x00, 0x15, 0x00, 0x14, 0x00, 0x00, 0x00,
};

extern "C" u8 const gUnk_080F119C[] ALIGN(1) = {
    0x00, 0x00, 0x16, 0x00, 0x14, 0x00, 0x00, 0x00,
};

extern "C" u8 const gUnk_080F11A4[] ALIGN(1) = {
    0x00, 0x00, 0x17, 0x00, 0x14, 0x00, 0x00, 0x00,
};

extern "C" u8 const gUnk_080F11AC[] ALIGN(1) = {
    0x00, 0x00, 0x18, 0x00, 0x14, 0x00, 0x00, 0x00,
};

extern "C" u8 const gUnk_080F11B4[] ALIGN(1) = {
    0x1E, 0x2D, 0x3C, 0x5A, 0x96, 0xFF, 0xFF, 0x00,
};

extern "C" u32 const gUnk_080F11BC[] ALIGN(1) = {
    0x00000039, 0x00000053, 0x00000054, 0x00000055, 0x00000056,
    0x00000057, 0x00000058, 0x00000059, 0x0000005A,
};

extern "C" u32 const gUnk_080F11E0[] ALIGN(1) = {
    0x00000039, 0x00000053, 0x0000005B, 0x0000005C, 0x0000005D,
    0x0000005E, 0x0000005F, 0x00000060, 0x00000061, 0x00000062,
    0x00000063, 0x00000064, 0x00000065, 0x00000066,
};

extern "C" u32 const gUnk_080F1218[] ALIGN(1) = {
    0x00000000, 0x00000002, 0x00000005,
};

extern "C" u32 const gUnk_080F1224[] ALIGN(1) = {
    0x00000000, 0x00000002, 0x00000005,
};

extern "C" u8 const gUnk_080F1230[] ALIGN(1) = {
    0xE0, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3,
    0xB4, 0xB5, 0xB6, 0xDF, 0xA8, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
    0x80, 0x81, 0x82, 0x83, 0x84, 0xB7, 0xDE, 0xA7, 0x78, 0x51, 0x52, 0x53,
    0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x85, 0xB8, 0xDD, 0xA6, 0x77,
    0x50, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x5B, 0x86, 0xB9,
    0xDC, 0xA5, 0x76, 0x4F, 0x30, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x39,
    0x5C, 0x87, 0xBA, 0xDB, 0xA4, 0x75, 0x4E, 0x2F, 0x18, 0x09, 0x0A, 0x0B,
    0x0C, 0x1F, 0x3A, 0x5D, 0x88, 0xBB, 0xDA, 0xA3, 0x74, 0x4D, 0x2E, 0x17,
    0x08, 0x01, 0x02, 0x0D, 0x20, 0x3B, 0x5E, 0x89, 0xBC, 0xD9, 0xA2, 0x73,
    0x4C, 0x2D, 0x16, 0x07, 0x00, 0x03, 0x0E, 0x21, 0x3C, 0x5F, 0x8A, 0xBD,
    0xD8, 0xA1, 0x72, 0x4B, 0x2C, 0x15, 0x06, 0x05, 0x04, 0x0F, 0x22, 0x3D,
    0x60, 0x8B, 0xBE, 0xD7, 0xA0, 0x71, 0x4A, 0x2B, 0x14, 0x13, 0x12, 0x11,
    0x10, 0x23, 0x3E, 0x61, 0x8C, 0xBF, 0xD6, 0x9F, 0x70, 0x49, 0x2A, 0x29,
    0x28, 0x27, 0x26, 0x25, 0x24, 0x3F, 0x62, 0x8D, 0xC0, 0xD5, 0x9E, 0x6F,
    0x48, 0x47, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41, 0x40, 0x63, 0x8E, 0xC1,
    0xD4, 0x9D, 0x6E, 0x6D, 0x6C, 0x6B, 0x6A, 0x69, 0x68, 0x67, 0x66, 0x65,
    0x64, 0x8F, 0xC2, 0xD3, 0x9C, 0x9B, 0x9A, 0x99, 0x98, 0x97, 0x96, 0x95,
    0x94, 0x93, 0x92, 0x91, 0x90, 0xC3, 0xD2, 0xD1, 0xD0, 0xCF, 0xCE, 0xCD,
    0xCC, 0xCB, 0xCA, 0xC9, 0xC8, 0xC7, 0xC6, 0xC5, 0xC4, 0x00, 0x00, 0x00,
};

#define FOMT_ENTITY_UI_TEXT_BEFORE_OFFSETS
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_BEFORE_OFFSETS

extern "C" EntityUiScreenOffset const gUnk_080F1328[] ALIGN(1) = {
    { -3, -43 },
    { -3, -43 },
    { -3, -43 },
    { -3, -43 },
    { -3, -37 },
    { -3, -37 },
    { -3, -37 },
    { -3, -37 },
    { -3, -45 },
    { -3, -45 },
    { -3, -45 },
    { -3, -45 },
    { -3, -39 },
    { -3, -39 },
    { -8, -39 },
    { 4, -39 },
    { -3, -34 },
    { -3, -34 },
    { -3, -34 },
    { -3, -34 },
    { 12, -13 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { -6, -26 },
    { -6, -26 },
    { -6, -26 },
    { -6, -26 },
    { -5, -32 },
    { -5, -32 },
    { -5, -32 },
    { -5, -32 },
    { -6, -28 },
    { -6, -28 },
    { -6, -28 },
    { -6, -28 },
    { -5, -29 },
    { -5, -32 },
    { -13, -30 },
    { 1, -30 },
    { -5, -29 },
    { -5, -32 },
    { -11, -32 },
    { -4, -32 },
    { -5, -32 },
    { -5, -36 },
    { -14, -36 },
    { 2, -36 },
    { -4, -33 },
    { -4, -38 },
    { -14, -36 },
    { 5, -36 },
    { -4, -33 },
    { -4, -38 },
    { -10, -35 },
    { -1, -35 },
    { -4, -33 },
    { -4, -40 },
    { -15, -36 },
    { 6, -36 },
    { -4, -35 },
    { -4, -43 },
    { -16, -41 },
    { 7, -41 },
};

#define FOMT_ENTITY_UI_TEXT_AFTER_OFFSETS
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_AFTER_OFFSETS

extern "C" u32 const gUnk_080F143C[] ALIGN(1) = {
    0x00030114, 0x00030132, 0x00030314, 0x0003030A, 0x00000000,
};

// This contiguous ROM block is kept in physical order.  The entries whose
// game-level meaning is not established by a native reader retain gUnk names.
extern "C" u16 const gEntityUiAnimationLookupTable[] = {
    0x03E0, 0x03E4, 0x03E8, 0x03EC, 0x03F0,
    0x0488, 0x048C, 0x0490, 0x0494, 0x0498,
    0x04DC, 0x04E0, 0x04E4, 0x04E8, 0x04EC,
    0x0530, 0x0534, 0x0538, 0x053C, 0x0540,
    0x0584, 0x0588, 0x058C, 0x0590, 0x0594,
    0x05D8, 0x05DC, 0x05E0, 0x05E4, 0x05E8,
    0x0434, 0x0438, 0x043C, 0x0440, 0x0444,
};

extern "C" u8 const gUnk_080F1496[] = {
    0x0A, 0x05, 0x14, 0x00, 0x00, 0x00,
};

extern "C" u32 const gUnk_080F149C[] = {
    0x00000024, 0x00000025, 0x00000026, 0x00000027,
    0x00000028, 0x00000029, 0x0000002A,
};

extern "C" u32 const gUnk_080F14B8[] = {
    0x00000013, 0x00000014, 0x00000015, 0x00000016,
    0x00000017, 0x00000018, 0x00000019,
};

extern "C" u16 const gUnk_080F14D4[] = {
    0x03E7, 0x03E9, 0x03EA, 0x03EB, 0x03EC, 0x03ED, 0x03E8,
};

extern "C" u16 const gUnk_080F14E2[] = {
    0x03E4, 0x048C, 0x04E0, 0x0534, 0x0588, 0x05DC, 0x0438,
};

extern "C" u16 const gUnk_080F14F0[] = {
    0x042C, 0x04D4, 0x0528, 0x057C,
    0x05D0, 0x0624, 0x0480, 0x0000,
};

#define FOMT_ENTITY_UI_TEXT_FIRST
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_FIRST

extern "C" u16 const gUnk_080F1514[] ALIGN(4) = {
    0x0032, 0x000C, 0x0014, 0x0008,
    0x0014, 0x0004, 0x000A, 0x0000,
};

#define FOMT_ENTITY_UI_TEXT_SECOND
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_SECOND

// Native callers read the first byte of each entry; the table's game-level
// field meanings remain unresolved.
extern "C" EntityUiUnknownEntry const gUnk_080F1538[] ALIGN(4) = {
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x32, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x64, 0x09, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
};

// The following physical ROM range is byte-identical in both revisions.
// Keep address-derived names until a native caller establishes a semantic one.
extern "C" u16 const gUnk_080F1560[] = {
    0x071C, 0x0720, 0x0724, 0x072C, 0x0728, 0x0000,
};

extern "C" EntityUiUnknownEntry const gUnk_080F156C[] = {
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x2D, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x64, 0x09, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
};

extern "C" u16 const gUnk_080F15A4[] = {
    0x02AC, 0x02B0, 0x02B4, 0x02B8,
    0x02BC, 0x02C0, 0x02C4, 0x0000,
};

extern "C" EntityUiUnknownEntry const gUnk_080F15B4[] = {
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x05, 0x01, 0x04, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x05, 0x01, 0x02, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x05, 0x01, 0x02, 0x00 },
    { 0x19, 0x01, 0x02, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x0A, 0x05, 0x03, 0x00 },
    { 0x3C, 0x08, 0x04, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
};

extern "C" u16 const gUnk_080F161C[] = {
    0x0379, 0x037D, 0x0381, 0x0385, 0x0389, 0x038D, 0x0391,
    0x0395, 0x0399, 0x039D, 0x03A1, 0x03A5, 0x03AA, 0x0000,
};

extern "C" EntityUiUnknownEntry const gUnk_080F1638[] = {
    { 0x28, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
};

extern "C" u16 const gUnk_080F1644[] = {
    0x0207, 0x020B, 0x020F, 0x0000,
};

#define FOMT_ENTITY_UI_TEXT_THIRD
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_THIRD

extern "C" u16 const gUnk_080F165E[] = {
    0x00E8, 0x0068, 0x00A8, 0x00A8, 0x0120,
    0x0080, 0x0130, 0x00A0, 0x0098, 0x0060,
};

extern "C" u16 const gUnk_080F1672[] = {
    0xB4A0, 0x00C8, 0x0000,
};

extern "C" u32 const gUnk_080F1678[] = {
    0x00001999, 0x00003333, 0x00004CCC,
};

extern "C" u16 const gUnk_080F1684[][4] = {
    { 0x0000, 0x0003, 0x00A8, 0x0000 },
    { 0x0001, 0x0004, 0x00C8, 0x0000 },
    { 0x0002, 0x0005, 0x00F0, 0x0000 },
};

#define FOMT_ENTITY_UI_TEXT_FOURTH
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_FOURTH

extern "C" u16 const gUnk_080F16AE[] = {
    0x09BF, 0x09C3, 0x09C7, 0x09CB, 0x09CF,
};

#define FOMT_ENTITY_UI_TEXT_FIFTH
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_FIFTH

extern "C" u16 const gUnk_080F16C2[] = {
    0x00B4, 0x01AC, 0x00A4, 0x028C,
    0x01A4, 0x029C, 0x00FC, 0x0274,
};

// A 256-entry signed lookup table; native callers read signed halfwords.
extern "C" i16 const gUnk_080F16D2[] = {
    0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92,
    97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176,
    181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234,
    236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255,
    256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238,
    236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185,
    181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103,
    97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6,
    0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92,
    -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176,
    -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234,
    -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255,
    -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238,
    -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185,
    -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103,
    -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6,
};

extern "C" u8 const gUnk_080F18D2[] = {
    0x28, 0x14, 0x1E, 0x3C, 0x00, 0x0A, 0x0A, 0x14,
    0x00, 0x01, 0x00, 0x05, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x1E, 0x00, 0x03, 0x05, 0x05, 0x00, 0x00,
    0x03, 0x1E, 0x0A, 0x00, 0x00, 0x03, 0x00, 0x1E,
    0x00, 0x00, 0x03, 0x05, 0x0A, 0x05, 0x00, 0x01,
    0x00, 0x00, 0x0A, 0x14, 0x01, 0x0A, 0x0A, 0x05,
    0x14, 0x01,
};

extern "C" u8 const gUnk_080F1904[] = {
    0x5A, 0x3C, 0x1E, 0x64, 0x00, 0x0A, 0x0F, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x46, 0x00, 0x03, 0x00,
    0x19, 0x00, 0x00, 0x03,
};

#define FOMT_ENTITY_UI_TEXT_SIXTH_TO_NINTH
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_SIXTH_TO_NINTH

extern "C" u32 const gUnk_080F1948[] = {
    0xFFFFCCCD, 0x00010000, 0x00003333, 0x00010000,
    0xFFFFCCCD, 0x00040000, 0x0000CCCC, 0x00040000,
};

#define FOMT_ENTITY_UI_TEXT_TENTH
#include "data/text/common/entity_ui.cc"
#undef FOMT_ENTITY_UI_TEXT_TENTH

extern "C" void func_080330F4(EntityUiHarvestSpriteResult * result,
                               void * unknown_3C, GameObject * game_object,
                               Location const * location,
                               HarvestSprite::Task task,
                               EntityUiHarvestSpriteEntry const * entries);

extern "C" void ResolveIndexedResourceHandle(void * handle, u32 index);
extern "C" void func_08033B84(EntityUiCallbackState * state, u32 value,
                               u32 arg_1, u32 arg_2);
extern "C" void func_080324BC(EntityUiConstructorState * state, void * arg_1,
                               u32 arg_2, u32 arg_3, u32 arg_4, u32 arg_5,
                               u32 arg_6, bool arg_7);
extern "C" u8 const vtable_unk_080E6864[];

// The ROM leaf unconditionally returns false.  Its caller-facing purpose is
// not mapped yet.
extern "C" bool func_080324B8()
    SECTION(".text.entity_ui_default_no_action");

// Initializes an unmapped entity-UI object, then assigns its verified vtable.
extern "C" EntityUiConstructorState * func_08032A00(
    EntityUiConstructorState * state, void * arg_1)
    SECTION(".text.entity_ui_constructor");

// The semantic name of byte 0x41 is still unknown; preserve the exact leaf
// write while its callers and owning entity layout are recovered.
extern "C" void func_08033B7C(void * entity)
    SECTION(".text.entity_ui_unknown_flag");

// For kind 2, x=0x110..0x3BF and y=0xB0..0x24F return 1; other coordinates
// return 2.  Every other kind returns 0.  The caller's domain remains unmapped.
extern "C" u32 func_08032900(u32 kind, u32 x, i32 y)
    SECTION(".text.entity_ui_region_classification");

// Converts Harvest Sprite task experience into the fixed-point value consumed
// by the following entity-UI path.  The game-level meaning remains unmapped.
extern "C" u32 func_08033914(u32 task_experience)
    SECTION(".text.entity_ui_harvest_sprite_task_experience");

// Tests the selected Harvest Sprite UI entry before and after its shared
// result-record calculation.  The names of the byte flags remain unmapped.
extern "C" bool func_08033B24(EntityUiHarvestSpriteState * state)
    SECTION(".text.entity_ui_harvest_sprite_selection");

// The caller uses this lookup result as an AActorEntityUi animation ID.  Its
// state-byte categories have not been named yet.
extern "C" u32 func_08034248(EntityUiAnimationState const * state, u32 value)
    SECTION(".text.entity_ui_animation_lookup");

// Initializes the resource handle at +0xB4 and its following UI fields.  The
// three control-byte meanings are not mapped yet.
extern "C" void func_08034BFC(EntityUiResourceSetupState * state,
                               u32 table_index, u32 first_value,
                               u32 second_value)
    SECTION(".text.entity_ui_resource_setup");

extern "C" u32 func_08034C40(EntityUiCallbackState const * state)
    SECTION(".text.entity_ui_get_value_30");
extern "C" void * func_08034C48(EntityUiCallbackState const * state)
    SECTION(".text.entity_ui_get_pointer_10");
extern "C" void func_08034C4C(EntityUiCallbackState * state, u32 arg_1,
                               u32 arg_2)
    SECTION(".text.entity_ui_dispatch_value_30");

extern "C" bool func_080324B8()
{
    return false;
}

extern "C" EntityUiConstructorState * func_08032A00(
    EntityUiConstructorState * state, void * arg_1)
{
    func_080324BC(state, arg_1, 6, 0x20, 1, 0, 0, false);
    state->vtable = vtable_unk_080E6864;
    return state;
}

extern "C" void func_08033B7C(void * entity)
{
    EntityUiUnknownState * state = (EntityUiUnknownState *)entity;

    state->unknown_41 = 0;
}

extern "C" u32 func_08032900(u32 kind, u32 x, i32 y)
{
    if (kind == 2)
    {
        x += (u32)-0x110;
        i32 limit = 0x2AF;

        if (x <= (u32)limit)
        {
            if (y > 0xAF)
            {
                limit -= 0x60;
                if (y <= limit)
                {
                    return 1;
                }
            }
        }

        return 2;
    }

    return 0;
}

extern "C" u32 func_08033914(u32 task_experience)
{
    u32 scale = 0xC0;
    scale <<= 9;

    task_experience++;
    task_experience *= scale;
    task_experience >>= 8;

    u32 base = 0x80;
    base <<= 8;
    return task_experience + base;
}

extern "C" bool func_08033B24(EntityUiHarvestSpriteState * state)
{
    u32 entry_offset = state->entry_index;
    EntityUiHarvestSpriteEntry const * entry = state->entries;
    entry_offset <<= 3;
    entry = (EntityUiHarvestSpriteEntry const *)((u8 const *)entry + entry_offset);
    if ((entry->flags << 28) != 0)
    {
        return false;
    }

    GameObject * game_object = state->game_object;
    EntityUiHarvestSpriteResult result;
    Location location = state->GetLocation();
    HarvestSprite::Task task = state->harvest_sprite->GetCurrentTask();
    func_080330F4(&result, state->unknown_3C, game_object, &location, task,
                  state->entries);

    EntityUiHarvestSpriteResult * result_pointer = &result;
    u32 value = 0;
    if ((result_pointer->flags << 28) == 0)
    {
        value = 1;
    }
    return value;
}

extern "C" u32 func_08034248(EntityUiAnimationState const * state, u32 value)
{
    u16 const * table = gEntityUiAnimationLookupTable;
    u8 entry_index = state->entry_index;
    u32 table_offset = entry_index;
    table_offset <<= 2;
    table_offset += entry_index;
    table_offset += value;
    table_offset <<= 1;

    return *(u16 const *)((u8 const *)table + table_offset);
}

extern "C" void func_08034BFC(EntityUiResourceSetupState * state,
                               u32 table_index, u32 first_value,
                               u32 second_value)
{
    u16 const * table = gUnk_080F14F0;
    u16 resource_id = table[table_index];
    ResolveIndexedResourceHandle(state->resource_handle, resource_id);

    state->enabled = 1;
    state->active = 0;
    state->visible = 1;
    state->first_value = first_value;
    state->second_value = second_value;
    state->duration = 0x3C;
}

extern "C" u32 func_08034C40(EntityUiCallbackState const * state)
{
    return state->value_30;
}

extern "C" void * func_08034C48(EntityUiCallbackState const * state)
{
    return state->unknown_10;
}

extern "C" void func_08034C4C(EntityUiCallbackState * state, u32 arg_1,
                               u32 arg_2)
{
    func_08033B84(state, state->value_30, arg_1, arg_2);
}

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
extern "C" EntityUiResourceSelectorStorage const gUnk_080F33B8
    SECTION(".rodata.entity_ui_resource_selector") = {
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
        { 0, 0x00800000, 0x000E0060 },
    };

// "bad_alloc" has one automatic C terminator. The two subsequent zero bytes
// are linker alignment before the next raw object, not part of this string.
extern "C" char const gCppRuntimeBadAlloc_EntityUiResourceSelector[]
    SECTION(".rodata.entity_ui_resource_selector") =
        "bad_alloc";
