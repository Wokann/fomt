#include "field_render_farm_house_data.hh"
#include "static_resources.hh"

// These source payloads remain in the regional asset container.  The tables
// below keep real relocations to those raw resources rather than embedding ROM
// addresses in this C++ object.  Every symbol denotes the payload start in all
// regions; EU archive headers remain in the raw asset stream before labels.
extern u8 const gUnk_FarmHouseTilePatchResource_000[];
extern u8 const gUnk_FarmHouseTilePatchResource_001[];
extern u8 const gUnk_FarmHouseTilePatchResource_002[];
extern u8 const gUnk_FarmHouseTilePatchResource_003[];
extern u8 const gUnk_FarmHouseTilePatchResource_004[];
extern u8 const gUnk_FarmHouseTilePatchResource_005[];
extern u8 const gUnk_FarmHouseTilePatchResource_006[];
extern u8 const gUnk_FarmHouseTilePatchResource_007[];
extern u8 const gUnk_FarmHouseTilePatchResource_008[];
extern u8 const gUnk_FarmHouseTilePatchResource_009[];
extern u8 const gUnk_FarmHouseTilePatchResource_010[];
extern u8 const gUnk_FarmHouseTilePatchResource_011[];
extern u8 const gUnk_FarmHouseTilePatchResource_012[];
extern u8 const gUnk_FarmHouseTilePatchResource_013[];
extern u8 const gUnk_FarmHouseTilePatchResource_014[];
extern u8 const gUnk_FarmHouseTilePatchResource_015[];
extern u8 const gUnk_FarmHouseTilePatchResource_016[];
extern u8 const gUnk_FarmHouseTilePatchResource_017[];
extern u8 const gUnk_FarmHouseTilePatchResource_018[];
extern u8 const gUnk_FarmHouseTilePatchResource_019[];
extern u8 const gUnk_FarmHouseTilePatchResource_020[];
extern u8 const gUnk_FarmHouseTilePatchResource_021[];
extern u8 const gUnk_FarmHouseTilePatchResource_022[];
extern u8 const gUnk_FarmHouseTilePatchResource_023[];
extern u8 const gUnk_FarmHouseTilePatchResource_024[];
extern u8 const gUnk_FarmHouseTilePatchResource_025[];
extern u8 const gUnk_FarmHouseTilePatchResource_026[];
extern u8 const gUnk_FarmHouseTilePatchResource_027[];
extern u8 const gUnk_FarmHouseTilePatchAnimationResource_000[];
extern u8 const gUnk_FarmHouseTilePatchAnimationResource_001[];

extern u8 const gUnk_FarmHouseVisualResource_000[];
extern u8 const gUnk_FarmHouseVisualResource_001[];
extern u8 const gUnk_FarmHouseVisualResource_004[];
extern u8 const gUnk_FarmHouseVisualResource_005[];
extern u8 const gUnk_FarmHouseVisualResource_006[];
extern u8 const gUnk_FarmHouseVisualResource_007[];
extern u8 const gUnk_FarmHouseVisualResource_010[];
extern u8 const gUnk_FarmHouseVisualResource_011[];
extern u8 const gUnk_FarmHouseVisualResource_012[];
extern u8 const gUnk_FarmHouseVisualResource_013[];
extern u8 const gUnk_FarmHouseVisualResource_014[];
extern u8 const gUnk_FarmHouseVisualResource_015[];
extern u8 const gUnk_FarmHouseVisualResource_016[];
extern u8 const gUnk_FarmHouseVisualResource_017[];
extern u8 const gUnk_FarmHouseVisualResource_018[];
extern u8 const gUnk_FarmHouseVisualResource_019[];
extern u8 const gUnk_FarmHouseVisualResource_022[];
extern u8 const gUnk_FarmHouseVisualResource_023[];
extern u8 const gUnk_FarmHouseVisualResource_024[];
extern u8 const gUnk_FarmHouseVisualResource_025[];
extern u8 const gUnk_FarmHouseVisualResource_028[];
extern u8 const gUnk_FarmHouseVisualResource_029[];
extern u8 const gUnk_FarmHouseVisualResource_030[];
extern u8 const gUnk_FarmHouseVisualResource_031[];
extern u8 const gUnk_FarmHouseVisualResource_034[];
extern u8 const gUnk_FarmHouseVisualResource_035[];
extern u8 const gUnk_FarmHouseVisualResource_036[];
extern u8 const gUnk_FarmHouseVisualResource_037[];
extern u8 const gUnk_FarmHouseVisualResource_038[];
extern u8 const gUnk_FarmHouseVisualResource_041[];
extern u8 const gUnk_FarmHouseVisualResource_042[];

FarmHouseTilePatchData const gFarmHouseTilePatchData = {
    {
        { 0x0099, gUnk_FarmHouseTilePatchResource_000 },
        { 0x0099, gUnk_FarmHouseTilePatchResource_001 },
        { 0x009F, gUnk_FarmHouseTilePatchResource_002 },
        { 0x009F, gUnk_FarmHouseTilePatchResource_003 },
        { 0x00AB, gUnk_FarmHouseTilePatchResource_004 },
        { 0x00AB, gUnk_FarmHouseTilePatchResource_005 },
        { 0x0000, gUnk_FarmHouseTilePatchResource_006 },
    },
    {
        { 0x003D, gUnk_FarmHouseTilePatchResource_007, 0x0010 },
        { 0x003D, gUnk_FarmHouseTilePatchResource_008, 0x0010 },
        { 0x002F, gUnk_FarmHouseTilePatchResource_009, 0x0008 },
        { 0x002F, gUnk_FarmHouseTilePatchResource_010, 0x0008 },
    },
    {
        { 0x0090, gUnk_FarmHouseTilePatchResource_011 },
        { 0x0090, gUnk_FarmHouseTilePatchResource_012 },
        { 0x0000, gUnk_FarmHouseTilePatchResource_013 },
    },
    {
        { 0x0000, gUnk_FarmHouseTilePatchResource_014, 0x000A },
        { 0x0010, gUnk_FarmHouseTilePatchResource_015, 0x000A },
        { 0x0000, gUnk_FarmHouseTilePatchResource_016, 0x000A },
        { 0x0010, gUnk_FarmHouseTilePatchResource_017, 0x000A },
        { 0x0025, gUnk_FarmHouseTilePatchResource_018, 0x000A },
        { 0x0010, gUnk_FarmHouseTilePatchResource_019, 0x000A },
        { 0x0039, gUnk_FarmHouseTilePatchResource_020, 0x000A },
        { 0x0025, gUnk_FarmHouseTilePatchResource_021, 0x000A },
        { 0x0010, gUnk_FarmHouseTilePatchResource_022, 0x000A },
        { 0x0039, gUnk_FarmHouseTilePatchResource_023, 0x000A },
        { 0x0000, gUnk_FarmHouseTilePatchResource_024, 0x001E },
        { 0x001E, gUnk_FarmHouseTilePatchResource_025, 0x0007 },
        { 0x0000, gUnk_FarmHouseTilePatchResource_026, 0x001E },
        { 0x0000, gUnk_FarmHouseTilePatchResource_027, 0x000A },
    },
};

FarmHouseVisualDescriptor const gFarmHouseVisualDescriptors[7] = {
    {
        { 0x06, 0x04,
          { gUnk_FarmHouseVisualResource_000, gUnk_FarmHouseVisualResource_001, nullptr },
          gUnk_FarmHouseVisualResource_002, gUnk_FarmHouseVisualResource_003 },
        gUnk_FarmHouseVisualResource_004, 0x00000180,
        { gUnk_FarmHouseVisualResource_005, nullptr }, 0x0A, 0x01,
    },
    {
        { 0x15, 0x05,
          { gUnk_FarmHouseVisualResource_006, gUnk_FarmHouseVisualResource_007, nullptr },
          gUnk_FarmHouseVisualResource_008, gUnk_FarmHouseVisualResource_009 },
        gUnk_FarmHouseVisualResource_010, 0x000001C0,
        { gUnk_FarmHouseVisualResource_011, gUnk_FarmHouseVisualResource_012 }, 0x09, 0x03,
    },
    {
        { 0x15, 0x05,
          { gUnk_FarmHouseVisualResource_013, gUnk_FarmHouseVisualResource_014, nullptr },
          gUnk_FarmHouseVisualResource_008, gUnk_FarmHouseVisualResource_009 },
        gUnk_FarmHouseVisualResource_015, 0x000001C0,
        { gUnk_FarmHouseVisualResource_016, gUnk_FarmHouseVisualResource_017 }, 0x09, 0x03,
    },
    {
        { 0x0D, 0x0C,
          { gUnk_FarmHouseVisualResource_018, gUnk_FarmHouseVisualResource_019, nullptr },
          gUnk_FarmHouseVisualResource_020, gUnk_FarmHouseVisualResource_021 },
        gUnk_FarmHouseVisualResource_022, 0x00000200,
        { gUnk_FarmHouseVisualResource_023, nullptr }, 0x07, 0x01,
    },
    {
        { 0x18, 0x1B,
          { gUnk_FarmHouseVisualResource_024, gUnk_FarmHouseVisualResource_025, nullptr },
          gUnk_FarmHouseVisualResource_026, gUnk_FarmHouseVisualResource_027 },
        gUnk_FarmHouseVisualResource_028, 0x00000200,
        { gUnk_FarmHouseVisualResource_029, nullptr }, 0x07, 0x03,
    },
    {
        { 0x04, 0x05,
          { gUnk_FarmHouseVisualResource_030, gUnk_FarmHouseVisualResource_031, nullptr },
          gUnk_FarmHouseVisualResource_032, gUnk_FarmHouseVisualResource_033 },
        gUnk_FarmHouseVisualResource_034, 0x00000220,
        { gUnk_FarmHouseVisualResource_035, gUnk_FarmHouseVisualResource_036 }, 0x07, 0x01,
    },
    {
        { 0x0C, 0x0C,
          { gUnk_FarmHouseVisualResource_037, gUnk_FarmHouseVisualResource_038, nullptr },
          gUnk_FarmHouseVisualResource_039, gUnk_FarmHouseVisualResource_040 },
        gUnk_FarmHouseVisualResource_041, 0x00000200,
        { gUnk_FarmHouseVisualResource_042, nullptr }, 0x07, 0x04,
    },
};

FarmHouseTilePatchAnimationDescriptor const gFarmHouseTilePatchAnimations[2] = {
    { 0x0200, gUnk_FarmHouseTilePatchAnimationResource_000, 0x000C },
    { 0x0212, gUnk_FarmHouseTilePatchAnimationResource_001, 0x0008 },
};
