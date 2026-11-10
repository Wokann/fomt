#include "cooking_recipe.hh"
#include "fomt_constants.hh"

extern "C" {

// func_080977A0 compares a recipe inventory bitfield to required_mask and
// writes selected_value for the first matching row.
CookingRecipeInventoryMaskEntry const gCookingRecipeInventoryMaskEntries[] = {
    { 0x0008, 0x009C },
    { 0x0020, 0x00A0 },
    { 0x0040, 0x009E },
    { 0x0004, 0x009D },
    { 0x0002, 0x009F },
    { 0x0001, 0x009B },
    { 0x0010, 0x009E },
    { 0x0F80, 0x009B },
    { 0x0000, 0x009B },
};

// The list contains 117 native definitions followed by this all-zero sentinel.
// EvaluateCookingRecipe and CookingRecipeInventory both stop when recipe_id is zero.
CookingRecipeDefinition const gCookingRecipeDefinitions[] = {
    /* 000 */ { 0x0017, 0x0001, -1, 0x0210, gCookingRecipeDefinitionPayload.recipe_000_values_08, nullptr, nullptr },
    /* 001 */ { 0x0018, 0x0002, -1, 0x0210, gCookingRecipeDefinitionPayload.recipe_001_values_08, gCookingRecipeDefinitionPayload.recipe_001_entries_0c, nullptr },
    /* 002 */ { 0x0019, 0x0003, -1, 0x0210, gCookingRecipeDefinitionPayload.recipe_002_values_08, gCookingRecipeDefinitionPayload.recipe_002_entries_0c, nullptr },
    /* 003 */ { 0x001A, 0x0004, -2, 0x0210, gCookingRecipeDefinitionPayload.recipe_003_values_08, gCookingRecipeDefinitionPayload.recipe_003_entries_0c, nullptr },
    /* 004 */ { 0x001B, 0x0005, -3, 0x0210, gCookingRecipeDefinitionPayload.recipe_004_values_08, gCookingRecipeDefinitionPayload.recipe_004_entries_0c, nullptr },
    /* 005 */ { 0x001C, 0x0006, -3, 0x0210, gCookingRecipeDefinitionPayload.recipe_005_values_08, gCookingRecipeDefinitionPayload.recipe_005_entries_0c, nullptr },
    /* 006 */ { 0x001C, 0x0006, -3, 0x0000, gCookingRecipeDefinitionPayload.recipe_006_values_08, gCookingRecipeDefinitionPayload.recipe_005_entries_0c, nullptr },
    /* 007 */ { 0x0015, 0x0006, -4, 0x0000, gCookingRecipeDefinitionPayload.recipe_007_values_08, nullptr, nullptr },
    /* 008 */ { 0x0022, 0x0007, -5, 0x0000, gCookingRecipeDefinitionPayload.recipe_008_values_08, nullptr, nullptr },
    /* 009 */ { 0x0028, 0x000A, -4, 0x0000, gCookingRecipeDefinitionPayload.recipe_009_values_08, nullptr, nullptr },
    /* 010 */ { 0x004C, 0x0001, -40, 0x0004, gCookingRecipeDefinitionPayload.recipe_010_values_08, nullptr, nullptr },
    /* 011 */ { 0x0060, 0x0014, -7, 0x0100, gCookingRecipeDefinitionPayload.recipe_011_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_011_entries_10 },
    /* 012 */ { 0x004D, 0x0014, -5, 0x0001, gCookingRecipeDefinitionPayload.recipe_012_values_08, gCookingRecipeDefinitionPayload.recipe_012_entries_0c, gCookingRecipeDefinitionPayload.recipe_012_entries_10 },
    /* 013 */ { 0x004E, 0x001E, -2, 0x0004, gCookingRecipeDefinitionPayload.recipe_013_values_08, gCookingRecipeDefinitionPayload.recipe_013_entries_0c, gCookingRecipeDefinitionPayload.recipe_013_entries_10 },
    /* 014 */ { 0x004F, 0x001E, -2, 0x0104, gCookingRecipeDefinitionPayload.recipe_014_values_08, gCookingRecipeDefinitionPayload.recipe_014_entries_0c, gCookingRecipeDefinitionPayload.recipe_014_entries_10 },
    /* 015 */ { 0x0050, 0x0005, -3, 0x0804, gCookingRecipeDefinitionPayload.recipe_015_values_08, gCookingRecipeDefinitionPayload.recipe_015_entries_0c, gCookingRecipeDefinitionPayload.recipe_015_entries_10 },
    /* 016 */ { 0x0051, 0x0028, -1, 0x0403, gCookingRecipeDefinitionPayload.recipe_016_values_08, gCookingRecipeDefinitionPayload.recipe_016_entries_0c, gCookingRecipeDefinitionPayload.recipe_016_entries_10 },
    /* 017 */ { 0x0052, 0x0028, -1, 0x0002, gCookingRecipeDefinitionPayload.recipe_017_values_08, gCookingRecipeDefinitionPayload.recipe_017_entries_0c, gCookingRecipeDefinitionPayload.recipe_017_entries_10 },
    /* 018 */ { 0x0053, 0x0032, -1, 0x0003, gCookingRecipeDefinitionPayload.recipe_018_values_08, gCookingRecipeDefinitionPayload.recipe_018_entries_0c, gCookingRecipeDefinitionPayload.recipe_018_entries_10 },
    /* 019 */ { 0x0054, 0x0028, -5, 0x0001, gCookingRecipeDefinitionPayload.recipe_019_values_08, gCookingRecipeDefinitionPayload.recipe_019_entries_0c, gCookingRecipeDefinitionPayload.recipe_019_entries_10 },
    /* 020 */ { 0x0055, 0x0014, -15, 0x0008, gCookingRecipeDefinitionPayload.recipe_020_values_08, gCookingRecipeDefinitionPayload.recipe_020_entries_0c, gCookingRecipeDefinitionPayload.recipe_020_entries_10 },
    /* 021 */ { 0x0058, 0x001E, -15, 0x0008, gCookingRecipeDefinitionPayload.recipe_021_values_08, gCookingRecipeDefinitionPayload.recipe_021_entries_0c, gCookingRecipeDefinitionPayload.recipe_021_entries_10 },
    /* 022 */ { 0x0056, 0x0014, -20, 0x0008, gCookingRecipeDefinitionPayload.recipe_022_values_08, gCookingRecipeDefinitionPayload.recipe_022_entries_0c, gCookingRecipeDefinitionPayload.recipe_022_entries_10 },
    /* 023 */ { 0x0059, 0x001E, -20, 0x0008, gCookingRecipeDefinitionPayload.recipe_023_values_08, gCookingRecipeDefinitionPayload.recipe_023_entries_0c, gCookingRecipeDefinitionPayload.recipe_023_entries_10 },
    /* 024 */ { 0x0057, 0x0032, -30, 0x0008, gCookingRecipeDefinitionPayload.recipe_024_values_08, gCookingRecipeDefinitionPayload.recipe_024_entries_0c, gCookingRecipeDefinitionPayload.recipe_024_entries_10 },
    /* 025 */ { 0x0057, 0x0032, -30, 0x0008, gCookingRecipeDefinitionPayload.recipe_025_values_08, gCookingRecipeDefinitionPayload.recipe_024_entries_0c, gCookingRecipeDefinitionPayload.recipe_024_entries_10 },
    /* 026 */ { 0x005A, 0x003C, -20, 0x0008, gCookingRecipeDefinitionPayload.recipe_026_values_08, gCookingRecipeDefinitionPayload.recipe_026_entries_0c, gCookingRecipeDefinitionPayload.recipe_026_entries_10 },
    /* 027 */ { 0x005A, 0x003C, -20, 0x0008, gCookingRecipeDefinitionPayload.recipe_027_values_08, gCookingRecipeDefinitionPayload.recipe_026_entries_0c, gCookingRecipeDefinitionPayload.recipe_026_entries_10 },
    /* 028 */ { 0x005A, 0x003C, -20, 0x0008, gCookingRecipeDefinitionPayload.recipe_028_values_08, gCookingRecipeDefinitionPayload.recipe_026_entries_0c, gCookingRecipeDefinitionPayload.recipe_026_entries_10 },
    /* 029 */ { 0x005E, 0x0014, -4, 0x0201, gCookingRecipeDefinitionPayload.recipe_029_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_029_entries_10 },
    /* 030 */ { 0x005F, 0x001E, -2, 0x0003, gCookingRecipeDefinitionPayload.recipe_030_values_08, gCookingRecipeDefinitionPayload.recipe_030_entries_0c, gCookingRecipeDefinitionPayload.recipe_030_entries_10 },
    /* 031 */ { 0x005C, 0x0005, -5, 0x0084, gCookingRecipeDefinitionPayload.recipe_031_values_08, gCookingRecipeDefinitionPayload.recipe_031_entries_0c, gCookingRecipeDefinitionPayload.recipe_031_entries_10 },
    /* 032 */ { 0x005B, 0x001E, -15, 0x0008, gCookingRecipeDefinitionPayload.recipe_032_values_08, gCookingRecipeDefinitionPayload.recipe_032_entries_0c, gCookingRecipeDefinitionPayload.recipe_032_entries_10 },
    /* 033 */ { 0x005D, 0x0014, -20, 0x0008, gCookingRecipeDefinitionPayload.recipe_033_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_033_entries_10 },
    /* 034 */ { 0x0061, 0x0001, 0x0000, 0x0388, gCookingRecipeDefinitionPayload.recipe_034_values_08, nullptr, nullptr },
    /* 035 */ { 0x0062, 0x001E, -1, 0x0002, gCookingRecipeDefinitionPayload.recipe_035_values_08, gCookingRecipeDefinitionPayload.recipe_035_entries_0c, gCookingRecipeDefinitionPayload.recipe_035_entries_10 },
    /* 036 */ { 0x0063, 0x000A, -2, 0x1020, gCookingRecipeDefinitionPayload.recipe_036_values_08, gCookingRecipeDefinitionPayload.recipe_036_entries_0c, gCookingRecipeDefinitionPayload.recipe_036_entries_10 },
    /* 037 */ { 0x0064, 0x0007, -1, 0x0040, gCookingRecipeDefinitionPayload.recipe_037_values_08, gCookingRecipeDefinitionPayload.recipe_037_entries_0c, gCookingRecipeDefinitionPayload.recipe_037_entries_10 },
    /* 038 */ { 0x0065, 0x0005, -15, 0x0008, gCookingRecipeDefinitionPayload.recipe_038_values_08, gCookingRecipeDefinitionPayload.recipe_038_entries_0c, gCookingRecipeDefinitionPayload.recipe_038_entries_10 },
    /* 039 */ { 0x0066, 0x0032, -10, 0x00C4, gCookingRecipeDefinitionPayload.recipe_039_values_08, gCookingRecipeDefinitionPayload.recipe_039_entries_0c, gCookingRecipeDefinitionPayload.recipe_039_entries_10 },
    /* 040 */ { 0x0067, 0x0008, -1, 0x0484, gCookingRecipeDefinitionPayload.recipe_040_values_08, gCookingRecipeDefinitionPayload.recipe_040_entries_0c, gCookingRecipeDefinitionPayload.recipe_040_entries_10 },
    /* 041 */ { 0x0068, 0x001E, -2, 0x0C82, gCookingRecipeDefinitionPayload.recipe_041_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_041_entries_10 },
    /* 042 */ { 0x0069, 0x0028, -5, 0x00C4, gCookingRecipeDefinitionPayload.recipe_042_values_08, gCookingRecipeDefinitionPayload.recipe_042_entries_0c, nullptr },
    /* 043 */ { 0x006A, 0x0028, -5, 0x0040, gCookingRecipeDefinitionPayload.recipe_043_values_08, gCookingRecipeDefinitionPayload.recipe_043_entries_0c, gCookingRecipeDefinitionPayload.recipe_043_entries_10 },
    /* 044 */ { 0x006B, 0x0014, -1, 0x0404, gCookingRecipeDefinitionPayload.recipe_044_values_08, gCookingRecipeDefinitionPayload.recipe_044_entries_0c, gCookingRecipeDefinitionPayload.recipe_044_entries_10 },
    /* 045 */ { 0x006C, 0x0028, -3, 0x0002, gCookingRecipeDefinitionPayload.recipe_045_values_08, gCookingRecipeDefinitionPayload.recipe_045_entries_0c, gCookingRecipeDefinitionPayload.recipe_045_entries_10 },
    /* 046 */ { 0x006D, 0x0032, -4, 0x0002, gCookingRecipeDefinitionPayload.recipe_046_values_08, gCookingRecipeDefinitionPayload.recipe_046_entries_0c, gCookingRecipeDefinitionPayload.recipe_046_entries_10 },
    /* 047 */ { 0x006E, 0x003C, -4, 0x0002, gCookingRecipeDefinitionPayload.recipe_047_values_08, gCookingRecipeDefinitionPayload.recipe_047_entries_0c, gCookingRecipeDefinitionPayload.recipe_047_entries_10 },
    /* 048 */ { 0x006F, 0x0014, -2, 0x0004, gCookingRecipeDefinitionPayload.recipe_048_values_08, gCookingRecipeDefinitionPayload.recipe_048_entries_0c, gCookingRecipeDefinitionPayload.recipe_048_entries_10 },
    /* 049 */ { 0x0095, 0x001E, -8, 0x00C4, gCookingRecipeDefinitionPayload.recipe_049_values_08, gCookingRecipeDefinitionPayload.recipe_049_entries_0c, gCookingRecipeDefinitionPayload.recipe_049_entries_10 },
    /* 050 */ { 0x0070, 0x0014, -10, 0x0004, gCookingRecipeDefinitionPayload.recipe_050_values_08, gCookingRecipeDefinitionPayload.recipe_050_entries_0c, gCookingRecipeDefinitionPayload.recipe_050_entries_10 },
    /* 051 */ { 0x0071, 0x0001, 0x0000, 0x0008, gCookingRecipeDefinitionPayload.recipe_051_values_08, gCookingRecipeDefinitionPayload.recipe_051_entries_0c, gCookingRecipeDefinitionPayload.recipe_051_entries_10 },
    /* 052 */ { 0x0072, 0x0032, -5, 0x00D4, gCookingRecipeDefinitionPayload.recipe_052_values_08, gCookingRecipeDefinitionPayload.recipe_052_entries_0c, gCookingRecipeDefinitionPayload.recipe_052_entries_10 },
    /* 053 */ { 0x0073, 0x0028, -3, 0x0004, gCookingRecipeDefinitionPayload.recipe_053_values_08, gCookingRecipeDefinitionPayload.recipe_053_entries_0c, gCookingRecipeDefinitionPayload.recipe_053_entries_10 },
    /* 054 */ { 0x0074, 0x0032, -8, 0x00E5, gCookingRecipeDefinitionPayload.recipe_054_values_08, gCookingRecipeDefinitionPayload.recipe_054_entries_0c, nullptr },
    /* 055 */ { 0x0075, 0x0005, -5, 0x0084, gCookingRecipeDefinitionPayload.recipe_055_values_08, gCookingRecipeDefinitionPayload.recipe_055_entries_0c, gCookingRecipeDefinitionPayload.recipe_055_entries_10 },
    /* 056 */ { 0x0076, 0x0008, -2, 0x0002, gCookingRecipeDefinitionPayload.recipe_056_values_08, gCookingRecipeDefinitionPayload.recipe_056_entries_0c, gCookingRecipeDefinitionPayload.recipe_056_entries_10 },
    /* 057 */ { 0x0078, 0x001E, -1, 0x0000, gCookingRecipeDefinitionPayload.recipe_057_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_057_entries_10 },
    /* 058 */ { 0x007E, 0x0005, -5, 0x0084, gCookingRecipeDefinitionPayload.recipe_058_values_08, gCookingRecipeDefinitionPayload.recipe_058_entries_0c, gCookingRecipeDefinitionPayload.recipe_058_entries_10 },
    /* 059 */ { 0x003F, 0x0005, -5, 0x0008, gCookingRecipeDefinitionPayload.recipe_059_values_08, gCookingRecipeDefinitionPayload.recipe_059_entries_0c, gCookingRecipeDefinitionPayload.recipe_059_entries_10 },
    /* 060 */ { 0x0077, 0x001E, -1, 0x0000, gCookingRecipeDefinitionPayload.recipe_060_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_060_entries_10 },
    /* 061 */ { 0x0079, 0x003C, -1, 0x0000, gCookingRecipeDefinitionPayload.recipe_061_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_061_entries_10 },
    /* 062 */ { 0x007A, 0x0028, -1, 0x0200, gCookingRecipeDefinitionPayload.recipe_062_values_08, gCookingRecipeDefinitionPayload.recipe_062_entries_0c, gCookingRecipeDefinitionPayload.recipe_062_entries_10 },
    /* 063 */ { 0x007B, 0x0028, -5, 0x0000, gCookingRecipeDefinitionPayload.recipe_063_values_08, gCookingRecipeDefinitionPayload.recipe_063_entries_0c, gCookingRecipeDefinitionPayload.recipe_063_entries_10 },
    /* 064 */ { 0x007C, 0x0028, -2, 0x0000, gCookingRecipeDefinitionPayload.recipe_064_values_08, gCookingRecipeDefinitionPayload.recipe_064_entries_0c, nullptr },
    /* 065 */ { 0x007D, 0x001E, -4, 0x0000, gCookingRecipeDefinitionPayload.recipe_065_values_08, gCookingRecipeDefinitionPayload.recipe_065_entries_0c, nullptr },
    /* 066 */ { 0x007F, 0x001E, -2, 0x0002, gCookingRecipeDefinitionPayload.recipe_066_values_08, gCookingRecipeDefinitionPayload.recipe_066_entries_0c, gCookingRecipeDefinitionPayload.recipe_066_entries_10 },
    /* 067 */ { 0x0093, 0x0007, -1, 0x0040, gCookingRecipeDefinitionPayload.recipe_067_values_08, gCookingRecipeDefinitionPayload.recipe_067_entries_0c, gCookingRecipeDefinitionPayload.recipe_067_entries_10 },
    /* 068 */ { 0x0094, 0x001E, -2, 0x0002, gCookingRecipeDefinitionPayload.recipe_068_values_08, gCookingRecipeDefinitionPayload.recipe_068_entries_0c, gCookingRecipeDefinitionPayload.recipe_068_entries_10 },
    /* 069 */ { 0x0080, 0x001E, -3, 0x0001, gCookingRecipeDefinitionPayload.recipe_069_values_08, gCookingRecipeDefinitionPayload.recipe_069_entries_0c, gCookingRecipeDefinitionPayload.recipe_069_entries_10 },
    /* 070 */ { 0x0081, 0x001E, -1, 0x0002, gCookingRecipeDefinitionPayload.recipe_070_values_08, gCookingRecipeDefinitionPayload.recipe_070_entries_0c, gCookingRecipeDefinitionPayload.recipe_070_entries_10 },
    /* 071 */ { 0x0082, 0x0032, -1, 0x0201, gCookingRecipeDefinitionPayload.recipe_071_values_08, gCookingRecipeDefinitionPayload.recipe_071_entries_0c, gCookingRecipeDefinitionPayload.recipe_071_entries_10 },
    /* 072 */ { 0x0083, 0x0028, -1, 0x0060, gCookingRecipeDefinitionPayload.recipe_072_values_08, gCookingRecipeDefinitionPayload.recipe_072_entries_0c, gCookingRecipeDefinitionPayload.recipe_072_entries_10 },
    /* 073 */ { 0x0084, 0x0028, -3, 0x0025, gCookingRecipeDefinitionPayload.recipe_073_values_08, gCookingRecipeDefinitionPayload.recipe_073_entries_0c, gCookingRecipeDefinitionPayload.recipe_073_entries_10 },
    /* 074 */ { 0x0085, 0x003C, -3, 0x0004, gCookingRecipeDefinitionPayload.recipe_074_values_08, gCookingRecipeDefinitionPayload.recipe_074_entries_0c, gCookingRecipeDefinitionPayload.recipe_074_entries_10 },
    /* 075 */ { 0x0085, 0x003C, -3, 0x0025, gCookingRecipeDefinitionPayload.recipe_075_values_08, gCookingRecipeDefinitionPayload.recipe_074_entries_0c, gCookingRecipeDefinitionPayload.recipe_074_entries_10 },
    /* 076 */ { 0x0086, 0x003C, -3, 0x0025, gCookingRecipeDefinitionPayload.recipe_076_values_08, gCookingRecipeDefinitionPayload.recipe_076_entries_0c, gCookingRecipeDefinitionPayload.recipe_076_entries_10 },
    /* 077 */ { 0x0086, 0x003C, -3, 0x0004, gCookingRecipeDefinitionPayload.recipe_077_values_08, gCookingRecipeDefinitionPayload.recipe_076_entries_0c, gCookingRecipeDefinitionPayload.recipe_076_entries_10 },
    /* 078 */ { 0x0087, 0x003C, -2, 0x0002, gCookingRecipeDefinitionPayload.recipe_078_values_08, gCookingRecipeDefinitionPayload.recipe_078_entries_0c, gCookingRecipeDefinitionPayload.recipe_078_entries_10 },
    /* 079 */ { 0x0088, 0x0028, -3, 0x0025, gCookingRecipeDefinitionPayload.recipe_079_values_08, gCookingRecipeDefinitionPayload.recipe_079_entries_0c, gCookingRecipeDefinitionPayload.recipe_079_entries_10 },
    /* 080 */ { 0x0089, 0x003C, -3, 0x0025, gCookingRecipeDefinitionPayload.recipe_080_values_08, gCookingRecipeDefinitionPayload.recipe_080_entries_0c, gCookingRecipeDefinitionPayload.recipe_080_entries_10 },
    /* 081 */ { 0x0089, 0x003C, -3, 0x0004, gCookingRecipeDefinitionPayload.recipe_081_values_08, gCookingRecipeDefinitionPayload.recipe_080_entries_0c, gCookingRecipeDefinitionPayload.recipe_080_entries_10 },
    /* 082 */ { 0x008A, 0x003C, -2, 0x0002, gCookingRecipeDefinitionPayload.recipe_082_values_08, gCookingRecipeDefinitionPayload.recipe_082_entries_0c, gCookingRecipeDefinitionPayload.recipe_082_entries_10 },
    /* 083 */ { 0x008B, 0x000F, -2, 0x0004, gCookingRecipeDefinitionPayload.recipe_083_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_083_entries_10 },
    /* 084 */ { 0x008E, 0x0014, -2, 0x0002, gCookingRecipeDefinitionPayload.recipe_084_values_08, gCookingRecipeDefinitionPayload.recipe_084_entries_0c, gCookingRecipeDefinitionPayload.recipe_084_entries_10 },
    /* 085 */ { 0x0096, 0x0028, -1, 0x0485, gCookingRecipeDefinitionPayload.recipe_085_values_08, gCookingRecipeDefinitionPayload.recipe_085_entries_0c, nullptr },
    /* 086 */ { 0x0097, 0x0028, -3, 0x0080, gCookingRecipeDefinitionPayload.recipe_086_values_08, nullptr, nullptr },
    /* 087 */ { 0x0099, 0x000A, -2, 0x1000, gCookingRecipeDefinitionPayload.recipe_087_values_08, gCookingRecipeDefinitionPayload.recipe_087_entries_0c, gCookingRecipeDefinitionPayload.recipe_087_entries_10 },
    /* 088 */ { 0x00A4, 0x0005, -1, 0x0040, gCookingRecipeDefinitionPayload.recipe_088_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_088_entries_10 },
    /* 089 */ { 0x00A7, 0x0005, -3, 0x0104, gCookingRecipeDefinitionPayload.recipe_089_values_08, gCookingRecipeDefinitionPayload.recipe_089_entries_0c, nullptr },
    /* 090 */ { 0x00A5, 0x001E, -2, 0x0000, gCookingRecipeDefinitionPayload.recipe_090_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_090_entries_10 },
    /* 091 */ { 0x00A6, 0x0014, -1, 0x0004, gCookingRecipeDefinitionPayload.recipe_091_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_091_entries_10 },
    /* 092 */ { 0x00AA, 0x0008, -1, 0x0004, gCookingRecipeDefinitionPayload.recipe_092_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_092_entries_10 },
    /* 093 */ { 0x00AB, 0x0014, -2, 0x0103, gCookingRecipeDefinitionPayload.recipe_093_values_08, nullptr, gCookingRecipeDefinitionPayload.recipe_093_entries_10 },
    /* 094 */ { 0x00A9, 0x0005, -1, 0x0108, gCookingRecipeDefinitionPayload.recipe_094_values_08, nullptr, nullptr },
    /* 095 */ { 0x008C, 0x000F, -5, 0x00E0, gCookingRecipeDefinitionPayload.recipe_095_values_08, gCookingRecipeDefinitionPayload.recipe_095_entries_0c, nullptr },
    /* 096 */ { 0x008D, 0x001E, -5, 0x00E0, gCookingRecipeDefinitionPayload.recipe_096_values_08, gCookingRecipeDefinitionPayload.recipe_096_entries_0c, gCookingRecipeDefinitionPayload.recipe_096_entries_10 },
    /* 097 */ { 0x008D, 0x001E, -5, 0x0000, gCookingRecipeDefinitionPayload.recipe_097_values_08, gCookingRecipeDefinitionPayload.recipe_096_entries_0c, gCookingRecipeDefinitionPayload.recipe_096_entries_10 },
    /* 098 */ { 0x008F, 0x001E, -20, 0x0094, gCookingRecipeDefinitionPayload.recipe_098_values_08, gCookingRecipeDefinitionPayload.recipe_098_entries_0c, gCookingRecipeDefinitionPayload.recipe_098_entries_10 },
    /* 099 */ { 0x0090, 0x0028, -8, 0x00D0, gCookingRecipeDefinitionPayload.recipe_099_values_08, gCookingRecipeDefinitionPayload.recipe_099_entries_0c, gCookingRecipeDefinitionPayload.recipe_099_entries_10 },
    /* 100 */ { 0x0091, 0x0046, -8, 0x00D0, gCookingRecipeDefinitionPayload.recipe_100_values_08, gCookingRecipeDefinitionPayload.recipe_100_entries_0c, gCookingRecipeDefinitionPayload.recipe_100_entries_10 },
    /* 101 */ { 0x00A8, 0x0014, -3, 0x0002, gCookingRecipeDefinitionPayload.recipe_101_values_08, gCookingRecipeDefinitionPayload.recipe_101_entries_0c, gCookingRecipeDefinitionPayload.recipe_101_entries_10 },
    /* 102 */ { 0x0092, 0x0032, -50, 0x0004, gCookingRecipeDefinitionPayload.recipe_102_values_08, gCookingRecipeDefinitionPayload.recipe_102_entries_0c, gCookingRecipeDefinitionPayload.recipe_102_entries_10 },
    /* 103 */ { 0x0048, 0x0002, -2, 0x0000, gCookingRecipeDefinitionPayload.recipe_103_values_08, nullptr, nullptr },
    /* 104 */ { 0x0049, 0x0002, -2, 0x0000, gCookingRecipeDefinitionPayload.recipe_104_values_08, nullptr, nullptr },
    /* 105 */ { 0x004A, 0x0002, -2, 0x0000, gCookingRecipeDefinitionPayload.recipe_105_values_08, nullptr, nullptr },
    /* 106 */ { 0x003A, 0x0032, -1, 0x0004, gCookingRecipeDefinitionPayload.recipe_106_values_08, nullptr, nullptr },
    /* 107 */ { 0x003B, 0x0064, -1, 0x0008, gCookingRecipeDefinitionPayload.recipe_107_values_08, nullptr, nullptr },
    /* 108 */ { 0x003C, 0x0000, -20, 0x0004, gCookingRecipeDefinitionPayload.recipe_108_values_08, nullptr, nullptr },
    /* 109 */ { 0x003D, 0x0000, -50, 0x0008, gCookingRecipeDefinitionPayload.recipe_109_values_08, nullptr, nullptr },
    /* 110 */ { 0x0047, 0x0002, -3, 0x0003, gCookingRecipeDefinitionPayload.recipe_110_values_08, nullptr, nullptr },
    /* 111 */ { 0x009A, 0x0064, -50, 0x0FC7, gCookingRecipeDefinitionPayload.recipe_111_values_08, gCookingRecipeDefinitionPayload.recipe_111_entries_0c, nullptr },
    /* 112 */ { 0x009A, 0x0064, -50, 0x0FC7, gCookingRecipeDefinitionPayload.recipe_112_values_08, gCookingRecipeDefinitionPayload.recipe_111_entries_0c, nullptr },
    /* 113 */ { 0x00D4, 0x0000, 0x0000, 0x0000, gCookingRecipeDefinitionPayload.recipe_113_values_08, nullptr, nullptr },
    /* 114 */ { 0x00D5, 0x0000, 0x0000, 0x0000, gCookingRecipeDefinitionPayload.recipe_114_values_08, nullptr, nullptr },
    /* 115 */ { 0x00D6, 0x0000, 0x0000, 0x0000, gCookingRecipeDefinitionPayload.recipe_115_values_08, nullptr, nullptr },
    /* 116 */ { 0x00D7, 0x0000, 0x0000, 0x0000, gCookingRecipeDefinitionPayload.recipe_116_values_08, nullptr, nullptr },
    {},
};

// The definition table precedes this aggregate in ROM. Its aggregate
// layout supplies only the verified two-/four-byte alignment gaps between
// lists; no zero-filled gap is represented as an invented data object.
CookingRecipeDefinitionPayload const gCookingRecipeDefinitionPayload = {
    {
        0x0010, 0x0042, 0x0000,
    },
    {
        0x0011, 0x0042, 0x0000,
    },
    {
        { 0x0010, 0, 0 },
        {},
    },
    {
        0x0012, 0x0042, 0x0000,
    },
    {
        { 0x0010, 0, 0 },
        { 0x0011, 0, 0 },
        {},
    },
    {
        0x0013, 0x0042, 0x0000,
    },
    {
        { 0x0010, 0, 0 },
        { 0x0011, 0, 0 },
        { 0x0012, 0, 0 },
        {},
    },
    {
        0x0014, 0x0042, 0x0000,
    },
    {
        { 0x0010, 0, 0 },
        { 0x0011, 0, 0 },
        { 0x0012, 0, 0 },
        { 0x0013, 0, 0 },
        {},
    },
    {
        0x0015, 0x0042, 0x0000,
    },
    {
        0x0017, 0x0018, 0x0019, 0x001A, 0x001B, 0x0000,
    },
    {
        { 0x0010, 0, 0 },
        { 0x0011, 0, 0 },
        { 0x0012, 0, 0 },
        { 0x0013, 0, 0 },
        { 0x0014, 0, 0 },
        {},
    },
    {
        0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0000,
    },
    {
        0x001D, 0x001E, 0x001F, 0x0020, 0x0021, 0x0000,
    },
    {
        0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0000,
    },
    {
        0x002C, 0x003E, 0x0035, 0x0000,
    },
    {
        0x8003, 0x8006, 0x800C, 0x0005, 0x0000,
    },
    {
        { 0x0003, 7, -3 },
        { 0x0006, 6, -5 },
        { 0x000C, 5, 0 },
        { 0x0005, 3, -2 },
        { 0x0008, 5, -3 },
        { 0x000E, 3, -3 },
        { 0x000F, 2, 0 },
        { 0x0002, 7, 0 },
        { 0x0007, 7, -2 },
        { 0x0001, 2, -1 },
        { 0x0023, 1, -1 },
        { 0x0024, 2, -1 },
        { 0x0025, 3, -1 },
        { 0x0026, 4, -1 },
        { 0x0027, 4, -1 },
        { 0x0028, 4, -2 },
        { 0x0004, 2, -5 },
        { 0x000A, 4, -4 },
        { 0x0029, 5, -5 },
        { 0x002D, 2, 1 },
        { 0x002E, -60, 20 },
        { 0x002F, 1, -3 },
        { 0x006F, 7, -1 },
        { 0x0048, 5, -5 },
        { 0x0049, 5, -5 },
        { 0x004A, 5, -5 },
        { 0x0042, 5, -3 },
        { 0x0017, 5, -1 },
        { 0x0018, 5, -1 },
        { 0x0019, 5, -1 },
        { 0x001A, 5, -2 },
        { 0x001B, 5, -2 },
        { 0x001C, 6, -3 },
        { 0x0064, 1, 0 },
        { 0x0076, 1, 0 },
        {},
    },
    {
        { 0x0100, 5, 0 },
        { 0x0200, 5, 0 },
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x0044, 0x0040, 0x0000,
    },
    {
        { 0x0001, 2, 0 },
        { 0x0002, 7, 0 },
        { 0x0006, 5, -2 },
        { 0x0007, 7, 0 },
        { 0x0008, 6, 0 },
        { 0x0009, 4, 0 },
        { 0x000A, 7, -3 },
        { 0x000B, 6, 0 },
        { 0x000C, 7, 0 },
        { 0x000D, 5, 0 },
        { 0x000E, 2, 0 },
        { 0x000F, 3, 0 },
        { 0x0010, 3, 0 },
        { 0x0011, 3, 0 },
        { 0x0012, 3, 0 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -2 },
        { 0x0015, 6, -2 },
        { 0x006F, 4, 0 },
        { 0x0016, 5, 0 },
        { 0x001D, 3, 0 },
        { 0x001E, 3, 0 },
        { 0x001F, 3, 0 },
        { 0x0020, 4, -1 },
        { 0x0021, 5, -2 },
        { 0x0022, 5, -2 },
        { 0x0023, 4, 0 },
        { 0x0024, 4, 0 },
        { 0x0025, 4, 0 },
        { 0x0026, 5, -1 },
        { 0x0027, 6, -2 },
        { 0x0028, 6, -2 },
        { 0x0029, 7, -3 },
        { 0x0048, 7, -3 },
        { 0x0049, 7, -3 },
        { 0x004A, 7, -3 },
        { 0x002A, 7, -2 },
        { 0x002B, 5, 0 },
        { 0x002C, 3, -2 },
        { 0x002D, 5, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 4, 0 },
        { 0x00A1, 5, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 6, 0 },
        { 0x003E, 2, -1 },
        { 0x003F, 2, -1 },
        { 0x0046, 2, -1 },
        { 0x0042, 0, 0 },
        { 0x0056, 2, 0 },
        { 0x0064, 1, 0 },
        { 0x0076, 1, 0 },
        { 0x0098, 1, 0 },
        { 0x0099, 1, 0 },
        { 0x00AB, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 3, 0 },
        { 0x0001, 8, 0 },
        {},
    },
    {
        0x0043, 0x0201, 0x0000,
    },
    {
        { 0x0001, 5, 0 },
        { 0x0002, 7, 0 },
        { 0x0006, 5, -2 },
        { 0x0007, 7, 0 },
        { 0x0008, 6, 0 },
        { 0x0009, 4, 0 },
        { 0x000A, 2, -3 },
        { 0x000B, 6, 0 },
        { 0x000C, 7, 0 },
        { 0x000D, 5, 0 },
        { 0x000E, 2, 0 },
        { 0x000F, 3, 0 },
        { 0x0010, 3, 0 },
        { 0x0011, 3, 0 },
        { 0x0012, 3, 0 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -2 },
        { 0x0015, 6, -2 },
        { 0x006F, 4, 0 },
        { 0x0016, 5, 0 },
        { 0x001D, 2, 0 },
        { 0x001E, 2, 0 },
        { 0x001F, 2, 0 },
        { 0x0020, 3, -1 },
        { 0x0021, 4, -2 },
        { 0x0022, 5, -2 },
        { 0x0023, 4, 0 },
        { 0x0024, 4, 0 },
        { 0x0025, 4, 0 },
        { 0x0026, 5, -1 },
        { 0x0027, 6, -2 },
        { 0x0028, 6, -2 },
        { 0x0029, 5, -3 },
        { 0x0048, 5, -3 },
        { 0x0049, 5, -3 },
        { 0x004A, 5, -3 },
        { 0x002A, 3, -2 },
        { 0x002B, 5, 0 },
        { 0x002C, 3, -2 },
        { 0x002D, 5, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 5, 0 },
        { 0x00A1, 5, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 6, 0 },
        { 0x003E, 2, -1 },
        { 0x003F, 2, -1 },
        { 0x0046, 2, -1 },
        { 0x0042, 0, 0 },
        { 0x0056, 2, 0 },
        { 0x0064, 1, 0 },
        { 0x0076, 1, 0 },
        { 0x0098, 1, 0 },
        { 0x0099, 1, 0 },
        { 0x00AB, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0001, 8, 0 },
        { 0x0080, -5, 0 },
        { 0x0200, 0, 3 },
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x0000,
    },
    {
        { 0x0001, 5, -1 },
        { 0x0002, 3, 0 },
        { 0x0005, 3, -1 },
        { 0x0006, -1, 0 },
        { 0x0007, 4, 0 },
        { 0x0008, 5, -1 },
        { 0x0009, 4, 0 },
        { 0x000B, 4, -1 },
        { 0x000C, 4, -1 },
        { 0x000D, 3, 0 },
        { 0x000E, 3, 0 },
        { 0x000F, -1, 0 },
        { 0x0010, 1, -1 },
        { 0x0011, 1, -1 },
        { 0x0012, 1, -1 },
        { 0x0013, 2, -1 },
        { 0x0014, 3, -1 },
        { 0x0015, 4, -2 },
        { 0x0016, 4, -1 },
        { 0x002B, 5, -1 },
        { 0x002D, 5, -1 },
        { 0x002E, -60, 20 },
        { 0x002F, 8, -2 },
        { 0x00A1, 5, -1 },
        { 0x008E, 3, -1 },
        { 0x0064, 1, 0 },
        { 0x0098, 1, -1 },
        { 0x0099, 1, -1 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0001, 8, 0 },
        { 0x0080, -3, 1 },
        { 0x0100, 7, 0 },
        { 0x0200, -3, 1 },
        { 0x0400, 5, 0 },
        {},
    },
    {
        0x0042, 0x0005, 0x0000,
    },
    {
        { 0x0001, 3, 0 },
        { 0x0002, 1, 0 },
        { 0x0003, 2, -1 },
        { 0x0006, 1, -1 },
        { 0x0007, 5, -1 },
        { 0x0008, 7, -2 },
        { 0x0009, 2, 0 },
        { 0x000B, 6, -1 },
        { 0x000C, 7, -1 },
        { 0x000D, 2, 0 },
        { 0x000E, 3, -1 },
        { 0x000F, 7, -2 },
        { 0x002B, 5, -1 },
        { 0x002D, 5, -1 },
        { 0x002E, -60, 20 },
        { 0x002F, 9, -1 },
        { 0x00A1, 1, -1 },
        { 0x0064, 1, 0 },
        {},
    },
    {
        { 0x0100, 7, 0 },
        { 0x0200, 1, 0 },
        { 0x0800, 3, 0 },
        {},
    },
    {
        0x0040, 0x0042, 0x0200, 0x0000,
    },
    {
        { 0x0003, 1, -1 },
        { 0x0005, 5, -2 },
        { 0x0007, 5, -2 },
        { 0x0008, 3, -2 },
        { 0x000B, -1, -1 },
        { 0x000C, 5, -2 },
        { 0x000E, 1, -1 },
        { 0x000F, 3, -2 },
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x0016, 3, -1 },
        { 0x0023, -1, 0 },
        { 0x0024, -1, 0 },
        { 0x0025, -1, 0 },
        { 0x0026, -1, 0 },
        { 0x0027, -1, 0 },
        { 0x0028, -1, 0 },
        { 0x002B, 1, -1 },
        { 0x002D, 1, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 5, 0 },
        { 0x003E, 1, -1 },
        { 0x00A3, 3, 0 },
        { 0x00A2, 3, 0 },
        { 0x00A1, 3, 0 },
        { 0x0052, -5, 1 },
        { 0x0051, 1, 0 },
        { 0x006C, 1, -1 },
        { 0x006F, 1, -1 },
        { 0x0080, 3, 0 },
        { 0x0081, 2, 0 },
        { 0x00A4, 2, 0 },
        { 0x00AB, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0001, 3, 0 },
        { 0x0080, -1, 0 },
        { 0x0100, 5, 0 },
        { 0x0400, 5, 0 },
        {},
    },
    {
        0x0043, 0x0005, 0x0042, 0x0200, 0x0000,
    },
    {
        { 0x0001, 2, 0 },
        { 0x0002, 1, 0 },
        { 0x0003, 1, 0 },
        { 0x0007, 4, -1 },
        { 0x0008, 5, 0 },
        { 0x0009, 2, 0 },
        { 0x000B, 3, 0 },
        { 0x000C, 4, 0 },
        { 0x000E, 3, 0 },
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x0017, 5, 0 },
        { 0x0018, 6, 0 },
        { 0x0019, 7, 0 },
        { 0x001A, 8, 0 },
        { 0x001B, 9, 0 },
        { 0x001C, 10, 0 },
        { 0x001D, 1, -1 },
        { 0x001E, 1, -1 },
        { 0x001F, 1, -1 },
        { 0x0020, 2, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0023, 3, 0 },
        { 0x0024, 3, 0 },
        { 0x0025, 3, 0 },
        { 0x0026, 4, 0 },
        { 0x0027, 5, 0 },
        { 0x0028, 6, 0 },
        { 0x002B, 5, 0 },
        { 0x002D, 5, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 7, 0 },
        { 0x00A1, 7, 0 },
        { 0x00A2, 7, 0 },
        { 0x00A3, 7, 0 },
        { 0x0098, 1, 0 },
        { 0x0099, 1, 0 },
        { 0x0064, 1, 0 },
        { 0x008A, 20, -2 },
        { 0x0087, 5, 0 },
        { 0x00AB, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0100, 3, 0 },
        { 0x0400, 5, 0 },
        {},
    },
    {
        0x0041, 0x8003, 0x8006, 0x006F, 0x0000,
    },
    {
        { 0x0071, 7, 0 },
        { 0x0002, 7, 0 },
        { 0x0004, 5, -3 },
        { 0x0005, 3, -2 },
        { 0x0007, 5, -2 },
        { 0x0008, 4, -2 },
        { 0x000A, 5, -3 },
        { 0x000C, 4, -2 },
        { 0x000D, 4, 0 },
        { 0x0017, 4, -1 },
        { 0x0018, 4, -1 },
        { 0x0019, 4, -1 },
        { 0x001A, 5, -1 },
        { 0x001B, 5, -1 },
        { 0x001C, 6, -2 },
        { 0x0023, 3, -1 },
        { 0x0024, 3, -1 },
        { 0x0025, 3, -1 },
        { 0x0026, 4, -1 },
        { 0x0027, 4, -1 },
        { 0x0028, 5, -2 },
        { 0x0029, 4, -3 },
        { 0x0048, 4, -3 },
        { 0x0049, 4, -3 },
        { 0x004A, 4, -3 },
        { 0x002C, 4, -3 },
        { 0x002D, 4, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 2, 0 },
        { 0x00A1, 3, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        { 0x002A, 3, -3 },
        { 0x003E, 3, -2 },
        { 0x0003, 5, -2 },
        { 0x0006, 6, -2 },
        { 0x006F, 7, -1 },
        { 0x0064, 1, 0 },
        { 0x0076, 1, 0 },
        { 0x008A, 8, 0 },
        { 0x00AB, 5, 0 },
        {},
    },
    {
        { 0x0080, 5, 0 },
        { 0x0100, 5, 0 },
        {},
    },
    {
        0x8004, 0x8029, 0x8048, 0x8049, 0x004A, 0x0000,
    },
    {
        { 0x0048, 3, -3 },
        { 0x0049, 3, -3 },
        { 0x004A, 3, -3 },
        { 0x003F, 3, -1 },
        { 0x002A, 1, -2 },
        { 0x0029, 3, -3 },
        { 0x002C, 3, -3 },
        { 0x000A, 3, -3 },
        { 0x0004, 3, -3 },
        { 0x0055, 1, -1 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0080, 2, 0 },
        { 0x0100, 1, 0 },
        { 0x0200, -1, 1 },
        {},
    },
    {
        0x0201, 0x800A, 0x8029, 0x802C, 0x8048, 0x8049, 0x804A, 0x0055,
        0x0000,
    },
    {
        { 0x0048, 3, -3 },
        { 0x0049, 3, -3 },
        { 0x004A, 3, -3 },
        { 0x003F, 3, -1 },
        { 0x002A, 1, -2 },
        { 0x0029, 3, -3 },
        { 0x002C, 3, -3 },
        { 0x000A, 3, -3 },
        { 0x0004, 3, -3 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0055, 1, -1 },
        { 0x0058, 1, -1 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0080, 2, 0 },
        { 0x0100, 0, 0 },
        { 0x0200, -1, 1 },
        {},
    },
    {
        0x8003, 0x8005, 0x000C, 0x0000,
    },
    {
        { 0x002B, 3, -1 },
        { 0x002D, 3, -1 },
        { 0x002E, -60, 20 },
        { 0x002F, 1, -1 },
        { 0x0001, 3, -2 },
        { 0x0007, 2, -2 },
        { 0x0008, 4, -3 },
        { 0x000B, 3, -3 },
        { 0x000E, 7, -3 },
        { 0x000F, 5, -3 },
        { 0x0006, 5, -4 },
        { 0x0003, 5, -4 },
        { 0x0005, 4, -4 },
        { 0x000C, 4, -4 },
        { 0x0009, 1, -3 },
        { 0x0056, 1, -1 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0080, 1, 0 },
        { 0x0100, 2, 0 },
        { 0x0200, -1, 1 },
        {},
    },
    {
        0x0201, 0x8003, 0x8005, 0x800C, 0x0056, 0x0000,
    },
    {
        { 0x002B, 3, -1 },
        { 0x002D, 3, -1 },
        { 0x002E, -60, 20 },
        { 0x002F, 1, -1 },
        { 0x0001, 3, -2 },
        { 0x0007, 2, -2 },
        { 0x0008, 4, -3 },
        { 0x000B, 3, -3 },
        { 0x000E, 7, -3 },
        { 0x000F, 5, -3 },
        { 0x0006, 5, -4 },
        { 0x0003, 5, -4 },
        { 0x0005, 4, -4 },
        { 0x000C, 4, -4 },
        { 0x0009, 1, -3 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0056, 1, -1 },
        { 0x0059, 1, -1 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0080, 2, 0 },
        { 0x0100, 2, 0 },
        { 0x0200, -1, 1 },
        {},
    },
    {
        0x8004, 0x800A, 0x8029, 0x8048, 0x8049, 0x804A, 0x002C, 0x8003,
        0x8005, 0x000C, 0x0000,
    },
    {
        0x0055, 0x0056, 0x0000,
    },
    {
        { 0x0048, 3, -3 },
        { 0x0049, 3, -3 },
        { 0x004A, 3, -3 },
        { 0x003F, 3, -1 },
        { 0x002A, 1, -2 },
        { 0x002B, 3, -1 },
        { 0x002D, 3, -1 },
        { 0x002E, -60, 20 },
        { 0x002F, 1, -1 },
        { 0x0001, 3, -2 },
        { 0x0007, 2, -2 },
        { 0x0008, 4, -3 },
        { 0x000B, 3, -3 },
        { 0x000E, 7, -3 },
        { 0x000F, 5, -3 },
        { 0x0006, 5, -4 },
        { 0x0003, 5, -4 },
        { 0x0005, 4, -4 },
        { 0x000C, 4, -4 },
        { 0x0009, 1, -3 },
        { 0x0029, 3, -3 },
        { 0x002C, 3, -3 },
        { 0x000A, 3, -3 },
        { 0x0004, 3, -3 },
        { 0x0055, 1, -1 },
        { 0x0056, 1, -1 },
        { 0x0057, 1, -1 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0080, 2, 0 },
        { 0x0100, 2, 0 },
        { 0x0200, -1, 1 },
        {},
    },
    {
        0x0201, 0x8004, 0x800A, 0x8029, 0x8048, 0x8049, 0x804A, 0x002C,
        0x8003, 0x8005, 0x000C, 0x0000,
    },
    {
        0x0201, 0x0057, 0x0000,
    },
    {
        0x0201, 0x0055, 0x0056, 0x0000,
    },
    {
        { 0x0048, 3, -3 },
        { 0x0049, 3, -3 },
        { 0x004A, 3, -3 },
        { 0x003F, 3, -1 },
        { 0x002A, 1, -2 },
        { 0x002B, 3, -1 },
        { 0x002D, 3, -1 },
        { 0x002E, -60, 20 },
        { 0x002F, 1, -1 },
        { 0x0001, 3, -2 },
        { 0x0007, 2, -2 },
        { 0x0008, 4, -3 },
        { 0x000B, 3, -3 },
        { 0x000E, 7, -3 },
        { 0x000F, 2, -3 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0055, 1, -1 },
        { 0x0056, 1, -1 },
        { 0x0058, 1, -1 },
        { 0x0059, 1, -1 },
        { 0x005A, 1, -1 },
        { 0x0006, 5, -4 },
        { 0x0003, 5, -4 },
        { 0x0005, 4, -4 },
        { 0x000C, 4, -4 },
        { 0x0009, 1, -3 },
        { 0x0029, 3, -3 },
        { 0x002C, 3, -3 },
        { 0x000A, 3, -3 },
        { 0x0004, 3, -3 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0080, 2, 0 },
        { 0x0100, 2, 0 },
        { 0x0200, -1, 1 },
        {},
    },
    {
        0x0001, 0x0000,
    },
    {
        { 0x0080, 2, 0 },
        { 0x0100, 2, 0 },
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x0002, 0x0042, 0x0000,
    },
    {
        { 0x0061, 5, 0 },
        {},
    },
    {
        { 0x0080, 1, 0 },
        { 0x0100, 5, 0 },
        {},
    },
    {
        0x0003, 0x0000,
    },
    {
        { 0x0001, 3, 0 },
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x0004, 0x0000,
    },
    {
        { 0x002A, 3, 0 },
        { 0x003E, 1, 0 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0100, -1, 1 },
        {},
    },
    {
        0x0004, 0x0201, 0x0000,
    },
    {
        { 0x002A, 3, -2 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        {},
    },
    {
        { 0x0080, 3, -1 },
        { 0x0100, 0, 0 },
        {},
    },
    {
        0x0006, 0x0000,
    },
    {
        { 0x0001, 0, 0 },
        { 0x0100, 5, -1 },
        {},
    },
    {
        0x0006, 0x0008, 0x0000,
    },
    {
        0x0007, 0x0000,
    },
    {
        { 0x0071, 5, 0 },
        {},
    },
    {
        { 0x0080, 1, 0 },
        { 0x0100, 5, 0 },
        {},
    },
    {
        0x0007, 0x0000,
    },
    {
        { 0x001D, 5, -1 },
        { 0x001E, 5, -1 },
        { 0x001F, 5, -1 },
        { 0x0020, 6, -1 },
        { 0x0021, 6, -1 },
        { 0x0022, 7, -2 },
        { 0x0004, 3, -3 },
        { 0x0029, 3, -3 },
        { 0x0048, 3, -3 },
        { 0x0049, 3, -3 },
        { 0x004A, 3, -3 },
        { 0x000A, 3, -3 },
        { 0x002C, 3, -3 },
        { 0x0046, 5, -1 },
        {},
    },
    {
        { 0x0001, 3, 0 },
        {},
    },
    {
        0x0007, 0x0000,
    },
    {
        { 0x0071, 5, 0 },
        { 0x0042, 2, 0 },
        {},
    },
    {
        { 0x0080, 2, 0 },
        { 0x0100, 2, 0 },
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x000A, 0x0000,
    },
    {
        { 0x002A, 1, -2 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0080, 2, 0 },
        { 0x0100, 1, 0 },
        { 0x0200, -1, 1 },
        {},
    },
    {
        0x0200, 0x0201, 0x0009, 0x0000,
    },
    {
        { 0x002A, 1, -2 },
        { 0x003E, 1, -3 },
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x001D, 2, -2 },
        { 0x001E, 2, -2 },
        { 0x001F, 2, -2 },
        { 0x0020, 3, -2 },
        { 0x0021, 3, -2 },
        { 0x0022, 3, -3 },
        {},
    },
    {
        { 0x0001, 2, 0 },
        {},
    },
    {
        0x0009, 0x0000,
    },
    {
        { 0x002A, 1, -1 },
        { 0x003F, 1, -1 },
        { 0x003E, 1, -1 },
        {},
    },
    {
        { 0x0001, 2, 0 },
        { 0x0100, 1, 0 },
        { 0x0200, 1, 0 },
        {},
    },
    {
        0x000B, 0x0000,
    },
    {
        { 0x0001, 2, 0 },
        {},
    },
    {
        0x0200, 0x000D, 0x0071, 0x0000,
    },
    {
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        {},
    },
    {
        0x000D, 0x0000,
    },
    {
        { 0x00DD, 1, 0 },
        { 0x0071, 2, -1 },
        {},
    },
    {
        { 0x0080, 1, 0 },
        { 0x0100, 1, 0 },
        {},
    },
    {
        0x000E, 0x0000,
    },
    {
        { 0x002A, 1, 0 },
        {},
    },
    {
        { 0x0001, 2, 0 },
        { 0x0080, 1, 0 },
        {},
    },
    {
        0x0200, 0x0042, 0x0000,
    },
    {
        { 0x0071, 3, 0 },
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x0017, 3, -1 },
        { 0x0018, 3, -1 },
        { 0x0019, 3, -1 },
        { 0x001A, 4, -1 },
        { 0x001B, 4, -1 },
        { 0x001C, 4, -2 },
        {},
    },
    {
        { 0x0010, 3, 0 },
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x0200, 0x0201, 0x0042, 0x0000,
    },
    {
        { 0x0002, 7, -1 },
        { 0x0005, 3, -1 },
        { 0x0007, 7, -1 },
        { 0x0008, 6, -1 },
        { 0x0009, 3, -1 },
        { 0x000B, 3, -1 },
        { 0x000C, 4, -1 },
        { 0x000D, 4, -1 },
        { 0x000E, 5, -1 },
        { 0x000F, 4, -1 },
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x0017, 3, -1 },
        { 0x0018, 3, -1 },
        { 0x0019, 3, -1 },
        { 0x001A, 4, -1 },
        { 0x001B, 4, -1 },
        { 0x001C, 4, -2 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0023, 2, -1 },
        { 0x0024, 2, -1 },
        { 0x0025, 2, -1 },
        { 0x0026, 3, -1 },
        { 0x0027, 3, -1 },
        { 0x0028, 3, -2 },
        { 0x002B, 3, -1 },
        { 0x002D, 4, -1 },
        { 0x002F, 2, -1 },
        { 0x00A1, 5, -1 },
        { 0x00A2, 7, -1 },
        { 0x00A3, 5, -1 },
        { 0x0061, 5, 0 },
        {},
    },
    {
        { 0x0001, 2, 0 },
        { 0x0010, 3, 0 },
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x0200, 0x0201, 0x0040, 0x0042, 0x0000,
    },
    {
        { 0x0002, 7, -1 },
        { 0x0005, 3, -1 },
        { 0x0007, 7, -1 },
        { 0x0008, 6, -1 },
        { 0x0009, 3, -1 },
        { 0x000B, 3, -1 },
        { 0x000C, 4, -1 },
        { 0x000D, 4, -1 },
        { 0x000E, 5, -1 },
        { 0x000F, 4, -1 },
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x0017, 3, -1 },
        { 0x0018, 3, -1 },
        { 0x0019, 3, -1 },
        { 0x001A, 4, -1 },
        { 0x001B, 4, -1 },
        { 0x001C, 4, -2 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0023, 2, -1 },
        { 0x0024, 2, -1 },
        { 0x0025, 2, -1 },
        { 0x0026, 3, -1 },
        { 0x0027, 3, -1 },
        { 0x0028, 3, -2 },
        { 0x002B, 3, -1 },
        { 0x002D, 4, -1 },
        { 0x002F, 2, -1 },
        { 0x00A1, 5, -1 },
        { 0x00A2, 7, -1 },
        { 0x00A3, 5, -1 },
        { 0x0061, 5, 0 },
        {},
    },
    {
        { 0x0001, 2, 0 },
        { 0x0010, 3, 0 },
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x0200, 0x0000,
    },
    {
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x0017, 1, 0 },
        { 0x0018, 1, 0 },
        { 0x0019, 1, 0 },
        { 0x001A, 2, 0 },
        { 0x001B, 2, 0 },
        { 0x001C, 2, 0 },
        {},
    },
    {
        { 0x0100, 3, 0 },
        {},
    },
    {
        0x0200, 0x0201, 0x0000,
    },
    {
        { 0x002A, 1, -2 },
        { 0x003E, 1, -2 },
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0004, 3, -3 },
        { 0x0029, 3, -3 },
        { 0x0048, 3, -3 },
        { 0x0049, 3, -3 },
        { 0x004A, 3, -3 },
        { 0x000A, 3, -3 },
        { 0x002C, 3, -4 },
        { 0x008F, 7, -10 },
        { 0x0046, 3, -2 },
        { 0x0063, 3, -1 },
        { 0x005C, 3, -3 },
        { 0x0075, 3, -3 },
        { 0x007E, 3, -3 },
        {},
    },
    {
        { 0x0001, 2, 0 },
        {},
    },
    {
        0x0201, 0x0000,
    },
    {
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        {},
    },
    {
        { 0x0080, 4, -1 },
        {},
    },
    {
        0x0201, 0x0000,
    },
    {
        { 0x001D, 2, 0 },
        { 0x001E, 2, 0 },
        { 0x001F, 2, 0 },
        { 0x0020, 3, 0 },
        { 0x0021, 3, 0 },
        { 0x0022, 3, 0 },
        {},
    },
    {
        { 0x0100, 1, 0 },
        {},
    },
    {
        0x0202, 0x0200, 0x0201, 0x0000,
    },
    {
        { 0x003E, 5, -2 },
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0023, 2, -1 },
        { 0x0024, 2, -1 },
        { 0x0025, 2, -1 },
        { 0x0026, 3, -1 },
        { 0x0027, 3, -1 },
        { 0x0028, 3, -2 },
        { 0x002A, 2, -1 },
        { 0x0071, 2, 0 },
        { 0x005C, 5, -3 },
        { 0x0075, 5, -3 },
        { 0x007E, 5, -3 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        {},
    },
    {
        0x0202, 0x0041, 0x0000,
    },
    {
        { 0x003E, 5, -2 },
        { 0x0023, 2, 0 },
        { 0x0024, 2, 0 },
        { 0x0025, 2, 0 },
        { 0x0026, 3, 0 },
        { 0x0027, 3, 0 },
        { 0x0028, 3, 0 },
        { 0x0002, 5, 0 },
        { 0x0008, 5, 0 },
        { 0x0009, 5, 0 },
        { 0x000B, 5, 0 },
        { 0x000C, 5, 0 },
        { 0x000F, 5, 0 },
        { 0x002B, 6, 0 },
        { 0x002D, 5, 0 },
        { 0x002F, 8, 0 },
        { 0x00A3, 4, 0 },
        { 0x00A2, 3, 0 },
        { 0x00A1, 2, 0 },
        {},
    },
    {
        { 0x0001, 3, 0 },
        { 0x0010, 5, 0 },
        { 0x0080, -5, 0 },
        { 0x0100, 5, 0 },
        {},
    },
    {
        0x8029, 0x8048, 0x8049, 0x004A, 0x0200, 0x0071, 0x0043, 0x0000,
    },
    {
        { 0x0010, 3, -1 },
        { 0x0011, 3, -1 },
        { 0x0012, 3, -1 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -1 },
        { 0x0015, 6, -2 },
        { 0x002A, 3, -2 },
        { 0x003E, 1, -2 },
        { 0x0029, 3, -2 },
        { 0x0048, 3, -2 },
        { 0x0049, 3, -2 },
        { 0x004A, 3, -2 },
        { 0x0075, 5, -2 },
        { 0x0076, 1, 0 },
        {},
    },
    {
        0x8029, 0x8048, 0x8049, 0x004A, 0x0000,
    },
    {
        { 0x002A, 3, 0 },
        { 0x003E, 1, 0 },
        { 0x0029, 3, 0 },
        { 0x0048, 3, 0 },
        { 0x0049, 3, 0 },
        { 0x004A, 3, 0 },
        { 0x0076, 1, 0 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0100, -1, 0 },
        {},
    },
    {
        0x8029, 0x8048, 0x8049, 0x004A, 0x0000,
    },
    {
        { 0x0042, 1, 0 },
        { 0x0071, 1, 0 },
        {},
    },
    {
        { 0x0080, 1, -1 },
        { 0x0100, 1, 0 },
        {},
    },
    {
        0x002B, 0x0040, 0x0000,
    },
    {
        { 0x0001, 3, 0 },
        { 0x0004, 3, 0 },
        { 0x0100, 1, 0 },
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x002C, 0x0000,
    },
    {
        { 0x002A, 3, -2 },
        { 0x003E, 1, -1 },
        { 0x003F, 1, -1 },
        {},
    },
    {
        { 0x0100, -1, 0 },
        {},
    },
    {
        0x002C, 0x0000,
    },
    {
        { 0x002A, 1, -2 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        { 0x0080, 2, 0 },
        { 0x0100, 1, 0 },
        { 0x0200, 0, 0 },
        {},
    },
    {
        0x002D, 0x0040, 0x0000,
    },
    {
        { 0x0001, 3, 0 },
        { 0x0004, 3, 0 },
        { 0x0100, 1, 0 },
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x002F, 0x0040, 0x0000,
    },
    {
        { 0x0001, 3, 0 },
        { 0x0004, 3, 0 },
        { 0x0100, 1, 0 },
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x0040, 0x0080, 0x0000,
    },
    {
        { 0x006C, 5, -1 },
        {},
    },
    {
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x0041, 0x8075, 0x807E, 0x005C, 0x0000,
    },
    {
        { 0x002A, 2, -1 },
        { 0x0075, 5, -2 },
        { 0x007E, 5, -2 },
        { 0x005C, 5, -2 },
        {},
    },
    {
        { 0x0080, 1, 0 },
        { 0x0100, 1, 0 },
        {},
    },
    {
        0x0041, 0x0071, 0x0000,
    },
    {
        { 0x002A, 2, -1 },
        {},
    },
    {
        0x0041, 0x002C, 0x0000,
    },
    {
        { 0x002A, 2, -1 },
        { 0x003F, 1, -1 },
        {},
    },
    {
        0x0041, 0x0044, 0x0042, 0x0000,
    },
    {
        { 0x0001, 2, 0 },
        { 0x0002, 7, 0 },
        { 0x0006, 5, -2 },
        { 0x0007, 7, 0 },
        { 0x0008, 6, 0 },
        { 0x0009, 4, 0 },
        { 0x000A, 7, -3 },
        { 0x000B, 6, 0 },
        { 0x000C, 7, 0 },
        { 0x000D, 5, 0 },
        { 0x000E, 2, 0 },
        { 0x000F, 3, 0 },
        { 0x0010, 3, 0 },
        { 0x0011, 3, 0 },
        { 0x0012, 3, 0 },
        { 0x0013, 4, -1 },
        { 0x0014, 5, -2 },
        { 0x0015, 6, -2 },
        { 0x006F, 4, 0 },
        { 0x0016, 5, 0 },
        { 0x001D, 3, 0 },
        { 0x001E, 3, 0 },
        { 0x001F, 3, 0 },
        { 0x0020, 4, -1 },
        { 0x0021, 5, -2 },
        { 0x0022, 5, -2 },
        { 0x0023, 4, 0 },
        { 0x0024, 4, 0 },
        { 0x0025, 4, 0 },
        { 0x0026, 5, -1 },
        { 0x0027, 6, -2 },
        { 0x0028, 6, -2 },
        { 0x0029, 7, -3 },
        { 0x0048, 7, -3 },
        { 0x0049, 7, -3 },
        { 0x004A, 7, -3 },
        { 0x002A, 7, -2 },
        { 0x002B, 5, 0 },
        { 0x002C, 3, -2 },
        { 0x002D, 5, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 4, 0 },
        { 0x00A1, 5, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 6, 0 },
        { 0x003E, 2, -1 },
        { 0x003F, 2, -1 },
        { 0x0046, 2, -1 },
        { 0x0056, 2, 0 },
        { 0x0064, 1, 0 },
        { 0x0076, 1, 0 },
        { 0x0098, 1, 0 },
        { 0x0099, 1, 0 },
        { 0x00AB, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0001, 8, 0 },
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x0041, 0x0000,
    },
    {
        { 0x0071, 1, 0 },
        { 0x002A, 1, -2 },
        { 0x0075, 5, -2 },
        { 0x007E, 5, -2 },
        { 0x005C, 5, -2 },
        {},
    },
    {
        { 0x0080, 1, 0 },
        { 0x0100, 1, 0 },
        {},
    },
    {
        0x0200, 0x0041, 0x0042, 0x0000,
    },
    {
        { 0x0010, 4, -1 },
        { 0x0011, 4, -1 },
        { 0x0012, 4, -1 },
        { 0x0013, 5, -1 },
        { 0x0014, 6, -1 },
        { 0x0015, 7, -2 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0071, 1, 0 },
        { 0x0061, 1, 0 },
        {},
    },
    {
        { 0x0010, 1, -1 },
        { 0x0080, 1, 0 },
        {},
    },
    {
        0x80A2, 0x00A3, 0x0000,
    },
    {
        { 0x00A2, 5, 0 },
        { 0x00A3, 5, 0 },
        {},
    },
    {
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x00A2, 0x0000,
    },
    {
        { 0x0042, 3, 0 },
        {},
    },
    {
        { 0x0100, 3, 0 },
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x0040, 0x006C, 0x0080, 0x0000,
    },
    {
        { 0x0003, 2, -1 },
        { 0x000C, 3, -1 },
        { 0x002D, 3, 0 },
        { 0x002E, -60, 20 },
        { 0x002B, 5, 0 },
        { 0x002F, 8, 0 },
        { 0x008A, 8, 0 },
        { 0x00A9, 2, 0 },
        {},
    },
    {
        { 0x0400, 3, 0 },
        {},
    },
    {
        0x0202, 0x0043, 0x0061, 0x0000,
    },
    {
        { 0x0002, 7, 0 },
        { 0x0006, 8, -1 },
        { 0x0007, 7, -1 },
        { 0x0008, 6, -1 },
        { 0x0009, 2, 0 },
        { 0x000A, 3, -1 },
        { 0x000B, 3, 0 },
        { 0x000C, 3, 0 },
        { 0x000D, 2, 0 },
        { 0x000F, 6, -1 },
        { 0x0010, 4, 0 },
        { 0x0011, 4, 0 },
        { 0x0012, 4, 0 },
        { 0x0013, 5, 0 },
        { 0x0014, 6, 0 },
        { 0x0015, 7, 0 },
        { 0x0017, 3, 0 },
        { 0x0018, 3, 0 },
        { 0x0019, 3, 0 },
        { 0x001A, 4, 0 },
        { 0x001B, 4, 0 },
        { 0x001C, 4, 0 },
        { 0x0023, 2, -1 },
        { 0x0024, 2, -1 },
        { 0x0025, 2, -1 },
        { 0x0026, 3, -1 },
        { 0x0027, 3, -1 },
        { 0x0028, 3, -2 },
        { 0x002B, 2, 0 },
        { 0x002D, 5, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 3, 0 },
        { 0x00A1, 4, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        {},
    },
    {
        { 0x0001, 7, 0 },
        { 0x0080, 1, 0 },
        { 0x0100, 3, 0 },
        {},
    },
    {
        0x0043, 0x0000,
    },
    {
        { 0x0001, 1, 0 },
        { 0x0005, 1, -1 },
        { 0x0008, 3, -1 },
        { 0x000B, 3, 0 },
        { 0x000C, 3, -1 },
        { 0x000D, 2, -1 },
        { 0x000F, 3, 0 },
        { 0x0010, 7, -1 },
        { 0x0011, 7, -1 },
        { 0x0012, 7, -1 },
        { 0x0013, 8, -1 },
        { 0x0014, 8, -1 },
        { 0x0015, 9, -2 },
        { 0x002B, 3, 0 },
        { 0x002D, 3, 0 },
        { 0x002F, 3, 0 },
        { 0x002E, -60, 20 },
        { 0x00A1, 6, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        { 0x0098, 5, 0 },
        { 0x0099, 5, 0 },
        { 0x008A, 8, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 7, 0 },
        { 0x0800, 5, 0 },
        {},
    },
    {
        0x0084, 0x0044, 0x0000,
    },
    {
        0x0043, 0x0044, 0x0000,
    },
    {
        { 0x0001, 1, 0 },
        { 0x0005, 1, -1 },
        { 0x0008, 3, -1 },
        { 0x000B, 3, 0 },
        { 0x000C, 3, -1 },
        { 0x000D, 2, -1 },
        { 0x000F, 3, 0 },
        { 0x0010, 2, -1 },
        { 0x0011, 2, -1 },
        { 0x0012, 2, -1 },
        { 0x0013, 3, -1 },
        { 0x0014, 3, -1 },
        { 0x0015, 4, -2 },
        { 0x002B, 3, 0 },
        { 0x002D, 3, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 3, 0 },
        { 0x00A1, 6, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        { 0x0098, 5, 0 },
        { 0x0099, 5, 0 },
        { 0x00AB, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0080, 1, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 3, 0 },
        { 0x0800, 2, 0 },
        {},
    },
    {
        0x0043, 0x008E, 0x0000,
    },
    {
        0x0084, 0x008E, 0x0000,
    },
    {
        { 0x0001, 1, 0 },
        { 0x0005, 1, -1 },
        { 0x0008, 3, -1 },
        { 0x000B, 3, 0 },
        { 0x000C, 3, -1 },
        { 0x000D, 2, -1 },
        { 0x000F, 3, 0 },
        { 0x0010, 2, -1 },
        { 0x0011, 2, -1 },
        { 0x0012, 2, -1 },
        { 0x0013, 3, -1 },
        { 0x0014, 3, -1 },
        { 0x0015, 4, -2 },
        { 0x002B, 3, 0 },
        { 0x002D, 3, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 3, -5 },
        { 0x00A1, 6, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        { 0x0098, 5, 0 },
        { 0x0099, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 7, 0 },
        { 0x0800, 5, 0 },
        {},
    },
    {
        0x0084, 0x0042, 0x0000,
    },
    {
        { 0x0001, -2, 0 },
        { 0x0005, 1, -1 },
        { 0x0008, 3, -1 },
        { 0x000B, 1, 0 },
        { 0x000C, 3, -1 },
        { 0x000D, 2, -1 },
        { 0x000F, 3, 0 },
        { 0x0010, 7, -1 },
        { 0x0011, 7, -1 },
        { 0x0012, 7, -1 },
        { 0x0013, 8, -1 },
        { 0x0014, 8, -1 },
        { 0x0015, 9, -2 },
        { 0x002B, 3, 0 },
        { 0x002D, 3, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 3, 0 },
        { 0x00A1, 6, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        { 0x0098, 5, 0 },
        { 0x0099, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0080, 1, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 7, 0 },
        { 0x0800, 5, 0 },
        {},
    },
    {
        0x004B, 0x0000,
    },
    {
        { 0x0001, 1, 0 },
        { 0x0005, 1, -1 },
        { 0x0008, 3, -1 },
        { 0x000B, 3, 0 },
        { 0x000C, 3, -1 },
        { 0x000D, 2, -1 },
        { 0x000F, 3, 0 },
        { 0x0010, 7, -1 },
        { 0x0011, 7, -1 },
        { 0x0012, 7, -1 },
        { 0x0013, 8, -1 },
        { 0x0014, 8, -1 },
        { 0x0015, 9, -2 },
        { 0x002B, 3, 0 },
        { 0x002D, 3, 0 },
        { 0x002F, 3, 0 },
        { 0x002E, -60, 20 },
        { 0x00A1, 6, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        { 0x0098, 5, 0 },
        { 0x0099, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 7, 0 },
        { 0x0800, 5, 0 },
        {},
    },
    {
        0x004B, 0x008E, 0x0000,
    },
    {
        0x0088, 0x008E, 0x0000,
    },
    {
        { 0x0001, 1, 0 },
        { 0x0005, 1, -1 },
        { 0x0008, 3, -1 },
        { 0x000B, 3, 0 },
        { 0x000C, 3, -1 },
        { 0x000D, 2, -1 },
        { 0x000F, 3, 0 },
        { 0x0010, 2, -1 },
        { 0x0011, 2, -1 },
        { 0x0012, 2, -1 },
        { 0x0013, 3, -1 },
        { 0x0014, 3, -1 },
        { 0x0015, 4, -2 },
        { 0x002B, 3, 0 },
        { 0x002D, 3, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 3, -5 },
        { 0x00A1, 6, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        { 0x0098, 5, 0 },
        { 0x0099, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0080, 3, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 7, 0 },
        { 0x0800, 5, 0 },
        {},
    },
    {
        0x0088, 0x0042, 0x0000,
    },
    {
        { 0x0001, -2, 0 },
        { 0x0005, 1, -1 },
        { 0x0008, 3, -1 },
        { 0x000B, 1, 0 },
        { 0x000C, 3, -1 },
        { 0x000D, 2, -1 },
        { 0x000F, 3, 0 },
        { 0x0010, 7, -1 },
        { 0x0011, 7, -1 },
        { 0x0012, 7, -1 },
        { 0x0013, 8, -1 },
        { 0x0014, 8, -1 },
        { 0x0015, 9, -2 },
        { 0x002B, 3, 0 },
        { 0x002D, 3, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 3, -1 },
        { 0x00A1, 6, 0 },
        { 0x00A2, 5, 0 },
        { 0x00A3, 4, 0 },
        { 0x0098, 5, 0 },
        { 0x0099, 5, 0 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0080, 1, 0 },
        { 0x0100, 3, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 7, 0 },
        { 0x0800, 5, 0 },
        {},
    },
    {
        0x004B, 0x0000,
    },
    {
        { 0x0010, 1, 0 },
        { 0x0020, 1, 0 },
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x0200, 0x0043, 0x0042, 0x0000,
    },
    {
        { 0x0001, 3, -1 },
        { 0x0002, 6, -1 },
        { 0x0003, 3, -1 },
        { 0x0005, 4, -1 },
        { 0x0007, 5, -1 },
        { 0x0008, 6, -1 },
        { 0x0009, 5, -1 },
        { 0x000A, 5, 0 },
        { 0x000B, 7, -1 },
        { 0x000C, 5, -1 },
        { 0x000D, 6, -1 },
        { 0x000E, 5, 0 },
        { 0x000F, 6, -1 },
        { 0x0010, 4, 0 },
        { 0x0011, 4, 0 },
        { 0x0012, 4, 0 },
        { 0x0013, 5, 0 },
        { 0x0014, 5, 0 },
        { 0x0015, 5, 0 },
        { 0x0016, 4, 0 },
        { 0x006F, 5, 0 },
        { 0x002D, 6, 0 },
        { 0x002E, -60, 20 },
        { 0x002F, 2, 0 },
        { 0x00A1, 5, -1 },
        { 0x00A2, 7, -1 },
        { 0x00A3, 6, -1 },
        { 0x0046, -2, 1 },
        { 0x008F, -1, 1 },
        { 0x00A9, 3, 0 },
        {},
    },
    {
        { 0x0010, 1, 0 },
        { 0x0100, 1, 0 },
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x000C, 0x002B, 0x002D, 0x0000,
    },
    {
        { 0x002A, 3, -1 },
        { 0x00A3, 3, 0 },
        { 0x00A2, 2, 0 },
        { 0x00A1, 1, 0 },
        { 0x002F, 8, 0 },
        { 0x002E, -60, 20 },
        { 0x0002, 5, 0 },
        { 0x0042, 2, 0 },
        {},
    },
    {
        0x0045, 0x0000,
    },
    {
        0x0098, 0x0000,
    },
    {
        { 0x0071, 1, 0 },
        { 0x0042, 1, 0 },
        {},
    },
    {
        { 0x0080, 1, -1 },
        { 0x0100, 1, 0 },
        { 0x0200, 1, 0 },
        { 0x0400, 1, 0 },
        { 0x0800, 1, 0 },
        {},
    },
    {
        0x0040, 0x0000,
    },
    {
        { 0x0080, -2, 0 },
        { 0x0100, 2, 0 },
        { 0x0400, 3, 0 },
        { 0x0800, 4, 0 },
        {},
    },
    {
        0x0040, 0x0000,
    },
    {
        { 0x0030, 2, 0 },
        { 0x0031, 0, -1 },
        { 0x0032, -2, 1 },
        { 0x0033, -1, -1 },
        { 0x0034, 0, 0 },
        { 0x0035, 1, -1 },
        { 0x0036, 4, 0 },
        { 0x0037, 1, -1 },
        { 0x0038, 2, -2 },
        {},
    },
    {
        0x0040, 0x008E, 0x0000,
    },
    {
        { 0x0080, 2, -1 },
        { 0x0100, 2, 0 },
        { 0x0400, 2, 0 },
        {},
    },
    {
        0x0200, 0x0040, 0x0000,
    },
    {
        { 0x0080, 2, 0 },
        { 0x0100, 2, 0 },
        { 0x0400, 2, 0 },
        {},
    },
    {
        0x000D, 0x002A, 0x0000,
    },
    {
        { 0x0080, 2, 0 },
        { 0x0100, 1, 0 },
        {},
    },
    {
        0x0002, 0x0008, 0x0042, 0x0043, 0x0200, 0x0000,
    },
    {
        { 0x0400, 1, 0 },
        {},
    },
    {
        0x80A2, 0x00A3, 0x0000,
    },
    {
        0x0200, 0x0043, 0x0071, 0x0000,
    },
    {
        { 0x0010, 1, -1 },
        { 0x0011, 1, -1 },
        { 0x0012, 1, -1 },
        { 0x0013, 2, -1 },
        { 0x0014, 2, -1 },
        { 0x0015, 2, -2 },
        { 0x002A, 2, -1 },
        {},
    },
    {
        0x0200, 0x0043, 0x0071, 0x0046, 0x0000,
    },
    {
        0x0046, 0x008C, 0x0000,
    },
    {
        { 0x0010, 1, -1 },
        { 0x0011, 1, -1 },
        { 0x0012, 1, -1 },
        { 0x0013, 2, -1 },
        { 0x0014, 2, -1 },
        { 0x0015, 2, -2 },
        { 0x002A, 2, -1 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        {},
    },
    {
        0x0200, 0x0201, 0x0000,
    },
    {
        { 0x0010, 2, -1 },
        { 0x0011, 2, -1 },
        { 0x0012, 2, -1 },
        { 0x0013, 3, -1 },
        { 0x0014, 3, -1 },
        { 0x0015, 3, -2 },
        { 0x001D, 2, -1 },
        { 0x001E, 2, -1 },
        { 0x001F, 2, -1 },
        { 0x0020, 3, -1 },
        { 0x0021, 3, -1 },
        { 0x0022, 3, -2 },
        { 0x0004, 5, -3 },
        { 0x000A, 5, -3 },
        { 0x0029, 5, -3 },
        { 0x0048, 5, -3 },
        { 0x0049, 5, -3 },
        { 0x004A, 5, -3 },
        { 0x002A, 2, -2 },
        { 0x002C, 5, -3 },
        { 0x005C, 5, -5 },
        { 0x0075, 5, -5 },
        { 0x007E, 5, -5 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        {},
    },
    {
        0x0200, 0x0043, 0x0071, 0x0000,
    },
    {
        { 0x003E, 5, -2 },
        { 0x0010, 2, -1 },
        { 0x0011, 2, -1 },
        { 0x0012, 2, -1 },
        { 0x0013, 3, -1 },
        { 0x0014, 3, -1 },
        { 0x0015, 3, -2 },
        { 0x0004, 5, -3 },
        { 0x000A, 5, -3 },
        { 0x0029, 5, -3 },
        { 0x0048, 5, -3 },
        { 0x0049, 5, -3 },
        { 0x004A, 5, -3 },
        { 0x002A, 2, -1 },
        { 0x002C, 5, -2 },
        { 0x008F, 7, -7 },
        { 0x005C, 5, -4 },
        { 0x0075, 5, -4 },
        { 0x007E, 5, -4 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        {},
    },
    {
        0x0200, 0x0043, 0x0071, 0x0046, 0x0000,
    },
    {
        { 0x003E, 5, -2 },
        { 0x0010, 2, -1 },
        { 0x0011, 2, -1 },
        { 0x0012, 2, -1 },
        { 0x0013, 3, -1 },
        { 0x0014, 3, -1 },
        { 0x0015, 3, -2 },
        { 0x0004, 5, -3 },
        { 0x000A, 5, -3 },
        { 0x0029, 5, -3 },
        { 0x0048, 5, -3 },
        { 0x0049, 5, -3 },
        { 0x004A, 5, -3 },
        { 0x002A, 2, -1 },
        { 0x002C, 5, -2 },
        { 0x008F, 7, -7 },
        { 0x005C, 5, -4 },
        { 0x0075, 5, -4 },
        { 0x007E, 5, -4 },
        {},
    },
    {
        { 0x0001, 1, 0 },
        {},
    },
    {
        0x0043, 0x0042, 0x0200, 0x0201, 0x8071, 0x002A, 0x0000,
    },
    {
        { 0x005C, 5, -1 },
        { 0x0075, 5, -1 },
        { 0x007E, 5, -1 },
        { 0x0071, 4, -1 },
        { 0x002A, 3, -1 },
        {},
    },
    {
        { 0x0010, 3, 0 },
        { 0x0080, 2, -1 },
        {},
    },
    {
        0x0047, 0x0000,
    },
    {
        { 0x000A, 3, -5 },
        { 0x0004, 3, -5 },
        { 0x002C, 3, -4 },
        { 0x0029, 3, -6 },
        { 0x0048, 3, -6 },
        { 0x0049, 3, -6 },
        { 0x004A, 3, -6 },
        { 0x002A, 2, -3 },
        { 0x003E, 5, -4 },
        { 0x001D, 5, -3 },
        { 0x001E, 5, -3 },
        { 0x001F, 5, -3 },
        { 0x0020, 6, -4 },
        { 0x0021, 6, -5 },
        { 0x0022, 7, -6 },
        { 0x0030, 10, -3 },
        { 0x0031, 2, -10 },
        { 0x0032, -10, -10 },
        { 0x0033, 5, -2 },
        { 0x0034, 2, -3 },
        { 0x0035, 7, -2 },
        { 0x0036, 5, 0 },
        { 0x0037, 3, 0 },
        { 0x0038, 1, -10 },
        {},
    },
    {
        { 0x0001, 3, 0 },
        { 0x0080, 3, 0 },
        {},
    },
    {
        0x0029, 0x0049, 0x004A, 0x0000,
    },
    {
        0x0029, 0x0048, 0x004A, 0x0000,
    },
    {
        0x0029, 0x0048, 0x0049, 0x0000,
    },
    {
        0x002A, 0x0034, 0x0037, 0x00AF, 0x0000,
    },
    {
        0x003A, 0x0030, 0x0000,
    },
    {
        0x002A, 0x0034, 0x0038, 0x00AF, 0x0000,
    },
    {
        0x003C, 0x0031, 0x0000,
    },
    {
        0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x00DC,
        0x0000,
    },
    {
        0x009B, 0x009C, 0x009D, 0x009E, 0x009F, 0x00A0, 0x003B, 0x003D,
        0x0000,
    },
    {
        0x009A, 0x0000,
    },
    {
        { 0x0030, 20, 0 },
        { 0x0031, 0, -1 },
        { 0x0032, 0, -10 },
        { 0x0033, 10, -5 },
        { 0x0034, 5, -6 },
        { 0x0035, 15, -4 },
        { 0x0036, 10, 0 },
        { 0x0037, 30, 0 },
        { 0x0038, 10, -25 },
        {},
    },
    {
        0x00AC, 0x00AD, 0x00AE, 0x00AF, 0x00B0, 0x0000,
    },
    {
        0x00A1, 0x00A2, 0x00A3, 0x00E2, 0x00E3, 0x0000,
    },
    {
        0x0015, 0x001C, 0x0022, 0x0028, 0x00B6, 0x00BC, 0x0000,
    },
    {
        0x00C4, 0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x0000,
    },
};


}

// The evaluator reads the saved record layout directly. Its complete type
// and constructor implementation dependencies follow the earlier ROM tables.
#include "cooking_recipe_inventory.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".ifdef REGION_JP\n"
    "    .align 2, 0\n"
    "\n"
    "    .global EvaluateCookingRecipe\n"
    "    .thumb_func\n"
    "EvaluateCookingRecipe:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, sb\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    sub sp, #0x30\n"
    "    str r0, [sp, #0x24]\n"
    "    str r1, [sp, #0x28]\n"
    "    ldr r0, .Ljp_0809A050 @ =gCookingRecipeDefinitions\n"
    "    mov r8, r0\n"
    "    add r1, sp, #0x10\n"
    "    movs r0, #0\n"
    "    strh r0, [r1]\n"
    "    ldr r2, [sp, #0x28]\n"
    "    ldrh r0, [r2, #0x12]\n"
    "    lsls r0, r0, #0x14\n"
    "    lsrs r0, r0, #0x14\n"
    "    strh r0, [r1, #6]\n"
    "    mov r3, r8\n"
    "    ldrh r0, [r3]\n"
    "    mov sl, r1\n"
    "    cmp r0, #0\n"
    "    bne .Ljp_08099FF4\n"
    "    b .Ljp_0809A2C4\n"
    ".Ljp_08099FF4:\n"
    "    adds r2, #2\n"
    "    str r2, [sp, #0x2c]\n"
    ".Ljp_08099FF8:\n"
    "    movs r0, #0\n"
    "    mov r4, sl\n"
    "    strh r0, [r4, #2]\n"
    "    strh r0, [r4, #4]\n"
    "    ldr r1, [sp, #0x28]\n"
    "    ldrh r0, [r1, #0x12]\n"
    "    lsls r0, r0, #0x14\n"
    "    lsrs r4, r0, #0x14\n"
    "    ldr r2, [sp, #0x2c]\n"
    "    mov r1, sp\n"
    "    movs r3, #7\n"
    ".Ljp_0809A00E:\n"
    "    ldrh r0, [r2]\n"
    "    strh r0, [r1]\n"
    "    adds r2, #2\n"
    "    adds r1, #2\n"
    "    subs r3, #1\n"
    "    cmp r3, #0\n"
    "    bge .Ljp_0809A00E\n"
    "    movs r2, #0\n"
    "    mov ip, r2\n"
    "    mov r3, r8\n"
    "    ldrh r1, [r3, #6]\n"
    "    movs r0, #0x80\n"
    "    lsls r0, r0, #5\n"
    "    ands r0, r1\n"
    "    adds r5, r1, #0\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A048\n"
    "    movs r2, #0x42\n"
    "    ands r2, r4\n"
    "    cmp r2, #2\n"
    "    beq .Ljp_0809A044\n"
    "    movs r1, #0x40\n"
    "    eors r1, r2\n"
    "    rsbs r0, r1, #0\n"
    "    orrs r0, r1\n"
    "    lsrs r0, r0, #0x1f\n"
    "    mov ip, r0\n"
    ".Ljp_0809A044:\n"
    "    ldr r0, .Ljp_0809A054 @ =0x0000FFBD\n"
    "    ands r4, r0\n"
    ".Ljp_0809A048:\n"
    "    movs r3, #0\n"
    "    movs r6, #1\n"
    "    adds r1, r5, #0\n"
    "    b .Ljp_0809A05A\n"
    "    .align 2, 0\n"
    ".Ljp_0809A050: .word gCookingRecipeDefinitions\n"
    ".Ljp_0809A054: .word 0x0000FFBD\n"
    ".Ljp_0809A058:\n"
    "    adds r3, #1\n"
    ".Ljp_0809A05A:\n"
    "    cmp r3, #0xb\n"
    "    bgt .Ljp_0809A078\n"
    "    adds r2, r6, #0\n"
    "    lsls r2, r3\n"
    "    ands r2, r1\n"
    "    cmp r2, #0\n"
    "    beq .Ljp_0809A058\n"
    "    adds r0, r4, #0\n"
    "    ands r0, r2\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A074\n"
    "    eors r4, r2\n"
    "    b .Ljp_0809A058\n"
    ".Ljp_0809A074:\n"
    "    movs r0, #1\n"
    "    mov ip, r0\n"
    ".Ljp_0809A078:\n"
    "    cmp r4, #0\n"
    "    beq .Ljp_0809A0BC\n"
    "    mov r1, r8\n"
    "    ldr r0, [r1, #0x10]\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A0B4\n"
    "    adds r2, r0, #0\n"
    "    ldrh r1, [r2]\n"
    "    cmp r1, #0\n"
    "    beq .Ljp_0809A0B4\n"
    "    mov r3, sl\n"
    ".Ljp_0809A08E:\n"
    "    adds r0, r4, #0\n"
    "    ands r0, r1\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A0AC\n"
    "    eors r4, r1\n"
    "    movs r0, #2\n"
    "    ldrsb r0, [r2, r0]\n"
    "    ldrh r1, [r3, #2]\n"
    "    adds r1, r1, r0\n"
    "    strh r1, [r3, #2]\n"
    "    movs r0, #3\n"
    "    ldrsb r0, [r2, r0]\n"
    "    ldrh r1, [r3, #4]\n"
    "    adds r0, r0, r1\n"
    "    strh r0, [r3, #4]\n"
    ".Ljp_0809A0AC:\n"
    "    adds r2, #4\n"
    "    ldrh r1, [r2]\n"
    "    cmp r1, #0\n"
    "    bne .Ljp_0809A08E\n"
    ".Ljp_0809A0B4:\n"
    "    cmp r4, #0\n"
    "    beq .Ljp_0809A0BC\n"
    "    movs r2, #1\n"
    "    mov ip, r2\n"
    ".Ljp_0809A0BC:\n"
    "    mov r3, r8\n"
    "    ldr r4, [r3, #8]\n"
    "    ldrh r0, [r4]\n"
    "    cmp r0, #0\n"
    "    bne .Ljp_0809A0C8\n"
    "    b .Ljp_0809A214\n"
    ".Ljp_0809A0C8:\n"
    "    mov r7, sp\n"
    "    movs r0, #0x80\n"
    "    lsls r0, r0, #8\n"
    "    mov sb, r0\n"
    ".Ljp_0809A0D0:\n"
    "    ldr r6, .Ljp_0809A0E8 @ =0x0000FFFF\n"
    "    ldrh r1, [r4]\n"
    "    ldr r0, .Ljp_0809A0EC @ =0x00000201\n"
    "    cmp r1, r0\n"
    "    beq .Ljp_0809A12A\n"
    "    cmp r1, r0\n"
    "    bgt .Ljp_0809A0F0\n"
    "    subs r0, #1\n"
    "    cmp r1, r0\n"
    "    beq .Ljp_0809A104\n"
    "    b .Ljp_0809A1A4\n"
    "    .align 2, 0\n"
    ".Ljp_0809A0E8: .word 0x0000FFFF\n"
    ".Ljp_0809A0EC: .word 0x00000201\n"
    ".Ljp_0809A0F0:\n"
    "    ldr r0, .Ljp_0809A100 @ =0x00000202\n"
    "    cmp r1, r0\n"
    "    beq .Ljp_0809A150\n"
    "    adds r0, #1\n"
    "    cmp r1, r0\n"
    "    beq .Ljp_0809A176\n"
    "    b .Ljp_0809A1A4\n"
    "    .align 2, 0\n"
    ".Ljp_0809A100: .word 0x00000202\n"
    ".Ljp_0809A104:\n"
    "    movs r1, #0\n"
    "    ldrh r0, [r7]\n"
    "    subs r0, #0x10\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r0, r0, #0x10\n"
    "    cmp r0, #5\n"
    "    bls .Ljp_0809A184\n"
    ".Ljp_0809A112:\n"
    "    adds r1, #1\n"
    "    cmp r1, #7\n"
    "    bgt .Ljp_0809A1E4\n"
    "    lsls r0, r1, #1\n"
    "    add r0, sp\n"
    "    ldrh r0, [r0]\n"
    "    subs r0, #0x10\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r0, r0, #0x10\n"
    "    cmp r0, #5\n"
    "    bhi .Ljp_0809A112\n"
    "    b .Ljp_0809A19E\n"
    ".Ljp_0809A12A:\n"
    "    movs r1, #0\n"
    "    ldrh r0, [r7]\n"
    "    subs r0, #0x1d\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r0, r0, #0x10\n"
    "    cmp r0, #5\n"
    "    bls .Ljp_0809A184\n"
    ".Ljp_0809A138:\n"
    "    adds r1, #1\n"
    "    cmp r1, #7\n"
    "    bgt .Ljp_0809A1E4\n"
    "    lsls r0, r1, #1\n"
    "    add r0, sp\n"
    "    ldrh r0, [r0]\n"
    "    subs r0, #0x1d\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r0, r0, #0x10\n"
    "    cmp r0, #5\n"
    "    bhi .Ljp_0809A138\n"
    "    b .Ljp_0809A19E\n"
    ".Ljp_0809A150:\n"
    "    movs r1, #0\n"
    "    ldrh r0, [r7]\n"
    "    subs r0, #0x23\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r0, r0, #0x10\n"
    "    cmp r0, #5\n"
    "    bls .Ljp_0809A184\n"
    ".Ljp_0809A15E:\n"
    "    adds r1, #1\n"
    "    cmp r1, #7\n"
    "    bgt .Ljp_0809A1E4\n"
    "    lsls r0, r1, #1\n"
    "    add r0, sp\n"
    "    ldrh r0, [r0]\n"
    "    subs r0, #0x23\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r0, r0, #0x10\n"
    "    cmp r0, #5\n"
    "    bhi .Ljp_0809A15E\n"
    "    b .Ljp_0809A19E\n"
    ".Ljp_0809A176:\n"
    "    movs r1, #0\n"
    "    ldrh r0, [r7]\n"
    "    subs r0, #0x17\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r0, r0, #0x10\n"
    "    cmp r0, #5\n"
    "    bhi .Ljp_0809A188\n"
    ".Ljp_0809A184:\n"
    "    movs r6, #0\n"
    "    b .Ljp_0809A1E4\n"
    ".Ljp_0809A188:\n"
    "    adds r1, #1\n"
    "    cmp r1, #7\n"
    "    bgt .Ljp_0809A1E4\n"
    "    lsls r0, r1, #1\n"
    "    add r0, sp\n"
    "    ldrh r0, [r0]\n"
    "    subs r0, #0x17\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r0, r0, #0x10\n"
    "    cmp r0, #5\n"
    "    bhi .Ljp_0809A188\n"
    ".Ljp_0809A19E:\n"
    "    lsls r0, r1, #0x10\n"
    "    lsrs r6, r0, #0x10\n"
    "    b .Ljp_0809A1E4\n"
    ".Ljp_0809A1A4:\n"
    "    movs r2, #0\n"
    "    ldrh r1, [r4]\n"
    "    ldr r3, .Ljp_0809A1D8 @ =0x00000FFF\n"
    "    ands r3, r1\n"
    "    mov r0, sb\n"
    "    ands r0, r1\n"
    "    lsls r0, r0, #0x10\n"
    "    lsrs r5, r0, #0x10\n"
    "    mov r1, sp\n"
    ".Ljp_0809A1B6:\n"
    "    ldrh r0, [r1]\n"
    "    cmp r0, r3\n"
    "    bne .Ljp_0809A1DC\n"
    "    lsls r0, r2, #0x10\n"
    "    lsrs r6, r0, #0x10\n"
    "    cmp r5, #0\n"
    "    beq .Ljp_0809A1E4\n"
    "    movs r2, #0x80\n"
    "    lsls r2, r2, #8\n"
    ".Ljp_0809A1C8:\n"
    "    adds r4, #2\n"
    "    ldrh r1, [r4]\n"
    "    adds r0, r2, #0\n"
    "    ands r0, r1\n"
    "    cmp r0, #0\n"
    "    bne .Ljp_0809A1C8\n"
    "    b .Ljp_0809A1E4\n"
    "    .align 2, 0\n"
    ".Ljp_0809A1D8: .word 0x00000FFF\n"
    ".Ljp_0809A1DC:\n"
    "    adds r1, #2\n"
    "    adds r2, #1\n"
    "    cmp r2, #7\n"
    "    ble .Ljp_0809A1B6\n"
    ".Ljp_0809A1E4:\n"
    "    lsls r0, r6, #0x10\n"
    "    asrs r0, r0, #0x10\n"
    "    movs r1, #1\n"
    "    rsbs r1, r1, #0\n"
    "    cmp r0, r1\n"
    "    bne .Ljp_0809A200\n"
    "    ldrh r1, [r4]\n"
    "    mov r0, sb\n"
    "    ands r0, r1\n"
    "    cmp r0, #0\n"
    "    bne .Ljp_0809A20A\n"
    "    movs r2, #1\n"
    "    mov ip, r2\n"
    "    b .Ljp_0809A214\n"
    ".Ljp_0809A200:\n"
    "    lsls r0, r0, #1\n"
    "    mov r3, sp\n"
    "    adds r1, r3, r0\n"
    "    movs r0, #0\n"
    "    strh r0, [r1]\n"
    ".Ljp_0809A20A:\n"
    "    adds r4, #2\n"
    "    ldrh r0, [r4]\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A214\n"
    "    b .Ljp_0809A0D0\n"
    ".Ljp_0809A214:\n"
    "    movs r2, #0\n"
    "    mov r1, sp\n"
    "    movs r3, #7\n"
    ".Ljp_0809A21A:\n"
    "    ldrh r0, [r1]\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A22A\n"
    "    lsls r0, r2, #0x10\n"
    "    movs r4, #0x80\n"
    "    lsls r4, r4, #9\n"
    "    adds r0, r0, r4\n"
    "    lsrs r2, r0, #0x10\n"
    ".Ljp_0809A22A:\n"
    "    adds r1, #2\n"
    "    subs r3, #1\n"
    "    cmp r3, #0\n"
    "    bge .Ljp_0809A21A\n"
    "    cmp r2, #0\n"
    "    beq .Ljp_0809A280\n"
    "    mov r1, r8\n"
    "    ldr r0, [r1, #0xc]\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A280\n"
    "    adds r2, r0, #0\n"
    "    ldrh r0, [r2]\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A280\n"
    "    mov r3, sl\n"
    "    movs r7, #0\n"
    ".Ljp_0809A24A:\n"
    "    movs r4, #0\n"
    "    adds r6, r2, #4\n"
    "    ldrh r5, [r2]\n"
    "    mov r1, sp\n"
    ".Ljp_0809A252:\n"
    "    ldrh r0, [r1]\n"
    "    cmp r0, r5\n"
    "    bne .Ljp_0809A270\n"
    "    strh r7, [r1]\n"
    "    movs r0, #2\n"
    "    ldrsb r0, [r2, r0]\n"
    "    ldrh r1, [r3, #2]\n"
    "    adds r1, r1, r0\n"
    "    strh r1, [r3, #2]\n"
    "    movs r0, #3\n"
    "    ldrsb r0, [r2, r0]\n"
    "    ldrh r2, [r3, #4]\n"
    "    adds r0, r0, r2\n"
    "    strh r0, [r3, #4]\n"
    "    b .Ljp_0809A278\n"
    ".Ljp_0809A270:\n"
    "    adds r1, #2\n"
    "    adds r4, #1\n"
    "    cmp r4, #7\n"
    "    ble .Ljp_0809A252\n"
    ".Ljp_0809A278:\n"
    "    adds r2, r6, #0\n"
    "    ldrh r0, [r2]\n"
    "    cmp r0, #0\n"
    "    bne .Ljp_0809A24A\n"
    ".Ljp_0809A280:\n"
    "    movs r2, #0\n"
    "    mov r1, sp\n"
    "    movs r3, #7\n"
    ".Ljp_0809A286:\n"
    "    ldrh r0, [r1]\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A296\n"
    "    lsls r0, r2, #0x10\n"
    "    movs r4, #0x80\n"
    "    lsls r4, r4, #9\n"
    "    adds r0, r0, r4\n"
    "    lsrs r2, r0, #0x10\n"
    ".Ljp_0809A296:\n"
    "    adds r1, #2\n"
    "    subs r3, #1\n"
    "    cmp r3, #0\n"
    "    bge .Ljp_0809A286\n"
    "    cmp r2, #0\n"
    "    beq .Ljp_0809A2A6\n"
    "    movs r0, #1\n"
    "    mov ip, r0\n"
    ".Ljp_0809A2A6:\n"
    "    mov r1, ip\n"
    "    cmp r1, #0\n"
    "    bne .Ljp_0809A2B6\n"
    "    mov r2, r8\n"
    "    ldrh r0, [r2]\n"
    "    mov r3, sl\n"
    "    strh r0, [r3]\n"
    "    b .Ljp_0809A2C4\n"
    ".Ljp_0809A2B6:\n"
    "    movs r4, #0x14\n"
    "    add r8, r4\n"
    "    mov r1, r8\n"
    "    ldrh r0, [r1]\n"
    "    cmp r0, #0\n"
    "    beq .Ljp_0809A2C4\n"
    "    b .Ljp_08099FF8\n"
    ".Ljp_0809A2C4:\n"
    "    ldr r1, [sp, #0x24]\n"
    "    mov r0, sl\n"
    "    ldm r0!, {r2, r3, r4}\n"
    "    stm r1!, {r2, r3, r4}\n"
    "    ldm r0!, {r2, r3}\n"
    "    stm r1!, {r2, r3}\n"
    "    ldr r0, [sp, #0x24]\n"
    "    add sp, #0x30\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov sb, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r1}\n"
    "    bx r1\n"
    "    .align 2, 0\n"
    "\n"
    "    .else\n"
    "    .align 2, 0\n"
    "\n"
    "\tthumb_func_start EvaluateCookingRecipe\n"
    "EvaluateCookingRecipe: @ 0x0809A58C\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #0x30\n"
    "\tstr r0, [sp, #0x24]\n"
    "\tstr r1, [sp, #0x28]\n"
    "\tldr r0, .L0809A618 @ =gCookingRecipeDefinitions\n"
    "\tmov r8, r0\n"
    "\tadd r1, sp, #0x10\n"
    "\tmovs r0, #0\n"
    "\tstrh r0, [r1]\n"
    "\tldr r2, [sp, #0x28]\n"
    "\tldrh r0, [r2, #0x12]\n"
    "\tlsls r0, r0, #0x14\n"
    "\tlsrs r0, r0, #0x14\n"
    "\tstrh r0, [r1, #6]\n"
    "\tmov r3, r8\n"
    "\tldrh r0, [r3]\n"
    "\tmov sl, r1\n"
    "\tcmp r0, #0\n"
    "\tbne .L0809A5BC\n"
    "\tb .L0809A88C\n"
    ".L0809A5BC:\n"
    "\tadds r2, #2\n"
    "\tstr r2, [sp, #0x2c]\n"
    ".L0809A5C0:\n"
    "\tmovs r0, #0\n"
    "\tmov r4, sl\n"
    "\tstrh r0, [r4, #2]\n"
    "\tstrh r0, [r4, #4]\n"
    "\tldr r1, [sp, #0x28]\n"
    "\tldrh r0, [r1, #0x12]\n"
    "\tlsls r0, r0, #0x14\n"
    "\tlsrs r4, r0, #0x14\n"
    "\tldr r2, [sp, #0x2c]\n"
    "\tmov r1, sp\n"
    "\tmovs r3, #7\n"
    ".L0809A5D6:\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r1]\n"
    "\tadds r2, #2\n"
    "\tadds r1, #2\n"
    "\tsubs r3, #1\n"
    "\tcmp r3, #0\n"
    "\tbge .L0809A5D6\n"
    "\tmovs r2, #0\n"
    "\tmov ip, r2\n"
    "\tmov r3, r8\n"
    "\tldrh r1, [r3, #6]\n"
    "\tmovs r0, #0x80\n"
    "\tlsls r0, r0, #5\n"
    "\tands r0, r1\n"
    "\tadds r5, r1, #0\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A610\n"
    "\tmovs r2, #0x42\n"
    "\tands r2, r4\n"
    "\tcmp r2, #2\n"
    "\tbeq .L0809A60C\n"
    "\tmovs r1, #0x40\n"
    "\teors r1, r2\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tlsrs r0, r0, #0x1f\n"
    "\tmov ip, r0\n"
    ".L0809A60C:\n"
    "\tldr r0, .L0809A61C @ =0x0000FFBD\n"
    "\tands r4, r0\n"
    ".L0809A610:\n"
    "\tmovs r3, #0\n"
    "\tmovs r6, #1\n"
    "\tadds r1, r5, #0\n"
    "\tb .L0809A622\n"
    "\t.align 2, 0\n"
    ".L0809A618: .word gCookingRecipeDefinitions\n"
    ".L0809A61C: .word 0x0000FFBD\n"
    ".L0809A620:\n"
    "\tadds r3, #1\n"
    ".L0809A622:\n"
    "\tcmp r3, #0xb\n"
    "\tbgt .L0809A640\n"
    "\tadds r2, r6, #0\n"
    "\tlsls r2, r3\n"
    "\tands r2, r1\n"
    "\tcmp r2, #0\n"
    "\tbeq .L0809A620\n"
    "\tadds r0, r4, #0\n"
    "\tands r0, r2\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A63C\n"
    "\teors r4, r2\n"
    "\tb .L0809A620\n"
    ".L0809A63C:\n"
    "\tmovs r0, #1\n"
    "\tmov ip, r0\n"
    ".L0809A640:\n"
    "\tcmp r4, #0\n"
    "\tbeq .L0809A684\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1, #0x10]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A67C\n"
    "\tadds r2, r0, #0\n"
    "\tldrh r1, [r2]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0809A67C\n"
    "\tmov r3, sl\n"
    ".L0809A656:\n"
    "\tadds r0, r4, #0\n"
    "\tands r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A674\n"
    "\teors r4, r1\n"
    "\tmovs r0, #2\n"
    "\tldrsb r0, [r2, r0]\n"
    "\tldrh r1, [r3, #2]\n"
    "\tadds r1, r1, r0\n"
    "\tstrh r1, [r3, #2]\n"
    "\tmovs r0, #3\n"
    "\tldrsb r0, [r2, r0]\n"
    "\tldrh r1, [r3, #4]\n"
    "\tadds r0, r0, r1\n"
    "\tstrh r0, [r3, #4]\n"
    ".L0809A674:\n"
    "\tadds r2, #4\n"
    "\tldrh r1, [r2]\n"
    "\tcmp r1, #0\n"
    "\tbne .L0809A656\n"
    ".L0809A67C:\n"
    "\tcmp r4, #0\n"
    "\tbeq .L0809A684\n"
    "\tmovs r2, #1\n"
    "\tmov ip, r2\n"
    ".L0809A684:\n"
    "\tmov r3, r8\n"
    "\tldr r4, [r3, #8]\n"
    "\tldrh r0, [r4]\n"
    "\tcmp r0, #0\n"
    "\tbne .L0809A690\n"
    "\tb .L0809A7DC\n"
    ".L0809A690:\n"
    "\tmov r7, sp\n"
    "\tmovs r0, #0x80\n"
    "\tlsls r0, r0, #8\n"
    "\tmov sb, r0\n"
    ".L0809A698:\n"
    "\tldr r6, .L0809A6B0 @ =0x0000FFFF\n"
    "\tldrh r1, [r4]\n"
    "\tldr r0, .L0809A6B4 @ =0x00000201\n"
    "\tcmp r1, r0\n"
    "\tbeq .L0809A6F2\n"
    "\tcmp r1, r0\n"
    "\tbgt .L0809A6B8\n"
    "\tsubs r0, #1\n"
    "\tcmp r1, r0\n"
    "\tbeq .L0809A6CC\n"
    "\tb .L0809A76C\n"
    "\t.align 2, 0\n"
    ".L0809A6B0: .word 0x0000FFFF\n"
    ".L0809A6B4: .word 0x00000201\n"
    ".L0809A6B8:\n"
    "\tldr r0, .L0809A6C8 @ =0x00000202\n"
    "\tcmp r1, r0\n"
    "\tbeq .L0809A718\n"
    "\tadds r0, #1\n"
    "\tcmp r1, r0\n"
    "\tbeq .L0809A73E\n"
    "\tb .L0809A76C\n"
    "\t.align 2, 0\n"
    ".L0809A6C8: .word 0x00000202\n"
    ".L0809A6CC:\n"
    "\tmovs r1, #0\n"
    "\tldrh r0, [r7]\n"
    "\tsubs r0, #0x10\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #5\n"
    "\tbls .L0809A74C\n"
    ".L0809A6DA:\n"
    "\tadds r1, #1\n"
    "\tcmp r1, #7\n"
    "\tbgt .L0809A7AC\n"
    "\tlsls r0, r1, #1\n"
    "\tadd r0, sp\n"
    "\tldrh r0, [r0]\n"
    "\tsubs r0, #0x10\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #5\n"
    "\tbhi .L0809A6DA\n"
    "\tb .L0809A766\n"
    ".L0809A6F2:\n"
    "\tmovs r1, #0\n"
    "\tldrh r0, [r7]\n"
    "\tsubs r0, #0x1d\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #5\n"
    "\tbls .L0809A74C\n"
    ".L0809A700:\n"
    "\tadds r1, #1\n"
    "\tcmp r1, #7\n"
    "\tbgt .L0809A7AC\n"
    "\tlsls r0, r1, #1\n"
    "\tadd r0, sp\n"
    "\tldrh r0, [r0]\n"
    "\tsubs r0, #0x1d\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #5\n"
    "\tbhi .L0809A700\n"
    "\tb .L0809A766\n"
    ".L0809A718:\n"
    "\tmovs r1, #0\n"
    "\tldrh r0, [r7]\n"
    "\tsubs r0, #0x23\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #5\n"
    "\tbls .L0809A74C\n"
    ".L0809A726:\n"
    "\tadds r1, #1\n"
    "\tcmp r1, #7\n"
    "\tbgt .L0809A7AC\n"
    "\tlsls r0, r1, #1\n"
    "\tadd r0, sp\n"
    "\tldrh r0, [r0]\n"
    "\tsubs r0, #0x23\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #5\n"
    "\tbhi .L0809A726\n"
    "\tb .L0809A766\n"
    ".L0809A73E:\n"
    "\tmovs r1, #0\n"
    "\tldrh r0, [r7]\n"
    "\tsubs r0, #0x17\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #5\n"
    "\tbhi .L0809A750\n"
    ".L0809A74C:\n"
    "\tmovs r6, #0\n"
    "\tb .L0809A7AC\n"
    ".L0809A750:\n"
    "\tadds r1, #1\n"
    "\tcmp r1, #7\n"
    "\tbgt .L0809A7AC\n"
    "\tlsls r0, r1, #1\n"
    "\tadd r0, sp\n"
    "\tldrh r0, [r0]\n"
    "\tsubs r0, #0x17\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #5\n"
    "\tbhi .L0809A750\n"
    ".L0809A766:\n"
    "\tlsls r0, r1, #0x10\n"
    "\tlsrs r6, r0, #0x10\n"
    "\tb .L0809A7AC\n"
    ".L0809A76C:\n"
    "\tmovs r2, #0\n"
    "\tldrh r1, [r4]\n"
    "\tldr r3, .L0809A7A0 @ =0x00000FFF\n"
    "\tands r3, r1\n"
    "\tmov r0, sb\n"
    "\tands r0, r1\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r5, r0, #0x10\n"
    "\tmov r1, sp\n"
    ".L0809A77E:\n"
    "\tldrh r0, [r1]\n"
    "\tcmp r0, r3\n"
    "\tbne .L0809A7A4\n"
    "\tlsls r0, r2, #0x10\n"
    "\tlsrs r6, r0, #0x10\n"
    "\tcmp r5, #0\n"
    "\tbeq .L0809A7AC\n"
    "\tmovs r2, #0x80\n"
    "\tlsls r2, r2, #8\n"
    ".L0809A790:\n"
    "\tadds r4, #2\n"
    "\tldrh r1, [r4]\n"
    "\tadds r0, r2, #0\n"
    "\tands r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbne .L0809A790\n"
    "\tb .L0809A7AC\n"
    "\t.align 2, 0\n"
    ".L0809A7A0: .word 0x00000FFF\n"
    ".L0809A7A4:\n"
    "\tadds r1, #2\n"
    "\tadds r2, #1\n"
    "\tcmp r2, #7\n"
    "\tble .L0809A77E\n"
    ".L0809A7AC:\n"
    "\tlsls r0, r6, #0x10\n"
    "\tasrs r0, r0, #0x10\n"
    "\tmovs r1, #1\n"
    "\trsbs r1, r1, #0\n"
    "\tcmp r0, r1\n"
    "\tbne .L0809A7C8\n"
    "\tldrh r1, [r4]\n"
    "\tmov r0, sb\n"
    "\tands r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbne .L0809A7D2\n"
    "\tmovs r2, #1\n"
    "\tmov ip, r2\n"
    "\tb .L0809A7DC\n"
    ".L0809A7C8:\n"
    "\tlsls r0, r0, #1\n"
    "\tmov r3, sp\n"
    "\tadds r1, r3, r0\n"
    "\tmovs r0, #0\n"
    "\tstrh r0, [r1]\n"
    ".L0809A7D2:\n"
    "\tadds r4, #2\n"
    "\tldrh r0, [r4]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A7DC\n"
    "\tb .L0809A698\n"
    ".L0809A7DC:\n"
    "\tmovs r2, #0\n"
    "\tmov r1, sp\n"
    "\tmovs r3, #7\n"
    ".L0809A7E2:\n"
    "\tldrh r0, [r1]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A7F2\n"
    "\tlsls r0, r2, #0x10\n"
    "\tmovs r4, #0x80\n"
    "\tlsls r4, r4, #9\n"
    "\tadds r0, r0, r4\n"
    "\tlsrs r2, r0, #0x10\n"
    ".L0809A7F2:\n"
    "\tadds r1, #2\n"
    "\tsubs r3, #1\n"
    "\tcmp r3, #0\n"
    "\tbge .L0809A7E2\n"
    "\tcmp r2, #0\n"
    "\tbeq .L0809A848\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A848\n"
    "\tadds r2, r0, #0\n"
    "\tldrh r0, [r2]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A848\n"
    "\tmov r3, sl\n"
    "\tmovs r7, #0\n"
    ".L0809A812:\n"
    "\tmovs r4, #0\n"
    "\tadds r6, r2, #4\n"
    "\tldrh r5, [r2]\n"
    "\tmov r1, sp\n"
    ".L0809A81A:\n"
    "\tldrh r0, [r1]\n"
    "\tcmp r0, r5\n"
    "\tbne .L0809A838\n"
    "\tstrh r7, [r1]\n"
    "\tmovs r0, #2\n"
    "\tldrsb r0, [r2, r0]\n"
    "\tldrh r1, [r3, #2]\n"
    "\tadds r1, r1, r0\n"
    "\tstrh r1, [r3, #2]\n"
    "\tmovs r0, #3\n"
    "\tldrsb r0, [r2, r0]\n"
    "\tldrh r2, [r3, #4]\n"
    "\tadds r0, r0, r2\n"
    "\tstrh r0, [r3, #4]\n"
    "\tb .L0809A840\n"
    ".L0809A838:\n"
    "\tadds r1, #2\n"
    "\tadds r4, #1\n"
    "\tcmp r4, #7\n"
    "\tble .L0809A81A\n"
    ".L0809A840:\n"
    "\tadds r2, r6, #0\n"
    "\tldrh r0, [r2]\n"
    "\tcmp r0, #0\n"
    "\tbne .L0809A812\n"
    ".L0809A848:\n"
    "\tmovs r2, #0\n"
    "\tmov r1, sp\n"
    "\tmovs r3, #7\n"
    ".L0809A84E:\n"
    "\tldrh r0, [r1]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A85E\n"
    "\tlsls r0, r2, #0x10\n"
    "\tmovs r4, #0x80\n"
    "\tlsls r4, r4, #9\n"
    "\tadds r0, r0, r4\n"
    "\tlsrs r2, r0, #0x10\n"
    ".L0809A85E:\n"
    "\tadds r1, #2\n"
    "\tsubs r3, #1\n"
    "\tcmp r3, #0\n"
    "\tbge .L0809A84E\n"
    "\tcmp r2, #0\n"
    "\tbeq .L0809A86E\n"
    "\tmovs r0, #1\n"
    "\tmov ip, r0\n"
    ".L0809A86E:\n"
    "\tmov r1, ip\n"
    "\tcmp r1, #0\n"
    "\tbne .L0809A87E\n"
    "\tmov r2, r8\n"
    "\tldrh r0, [r2]\n"
    "\tmov r3, sl\n"
    "\tstrh r0, [r3]\n"
    "\tb .L0809A88C\n"
    ".L0809A87E:\n"
    "\tmovs r4, #0x14\n"
    "\tadd r8, r4\n"
    "\tmov r1, r8\n"
    "\tldrh r0, [r1]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0809A88C\n"
    "\tb .L0809A5C0\n"
    ".L0809A88C:\n"
    "\tldr r1, [sp, #0x24]\n"
    "\tmov r0, sl\n"
    "\tldm r0!, {r2, r3, r4}\n"
    "\tstm r1!, {r2, r3, r4}\n"
    "\tldm r0!, {r2, r3}\n"
    "\tstm r1!, {r2, r3}\n"
    "\tldr r0, [sp, #0x24]\n"
    "\tadd sp, #0x30\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    "\n"
    "    .endif\n"
);
