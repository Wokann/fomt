#include "cooking_recipe_inventory.hh"

EXTERN_C

// The recipe screen walks the eight utensil flags in order and passes the
// corresponding value to its native display helper.
u16 const gCookingRecipeInventoryUtensilValues[]
    SECTION(".rodata.cooking_recipe_inventory_utensil_values") = {
        0x0109,
        0x00CC,
        0x015A,
        0x0040,
        0x01D8,
        0x0139,
        0x0147,
        0x0190,
    };

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
// func_0809A58C and func_0809A8AC both stop when recipe_id is zero.
extern u16 const gUnk_CookingRecipeDefinition_000_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_001_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_001_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_002_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_002_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_003_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_003_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_004_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_004_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_005_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_006_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_005_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_007_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_008_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_009_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_010_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_012_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_012_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_012_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_013_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_013_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_013_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_014_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_014_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_014_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_015_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_015_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_015_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_016_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_016_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_016_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_017_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_017_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_017_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_018_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_018_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_018_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_019_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_019_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_019_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_020_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_020_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_020_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_021_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_021_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_021_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_022_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_022_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_022_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_023_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_023_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_023_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_024_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_025_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_024_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_024_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_026_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_027_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_028_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_026_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_026_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_029_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_029_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_030_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_030_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_030_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_011_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_011_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_031_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_031_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_031_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_032_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_032_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_032_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_033_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_033_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_034_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_035_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_035_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_035_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_036_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_036_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_036_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_037_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_037_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_037_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_038_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_038_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_038_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_039_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_039_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_039_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_040_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_040_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_040_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_041_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_041_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_042_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_042_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_043_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_043_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_043_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_044_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_044_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_044_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_045_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_045_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_045_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_046_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_046_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_046_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_047_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_047_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_047_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_048_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_048_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_048_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_049_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_049_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_049_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_050_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_050_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_050_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_051_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_051_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_051_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_052_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_052_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_052_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_053_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_053_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_053_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_054_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_054_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_055_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_055_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_055_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_056_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_056_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_056_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_057_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_057_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_058_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_058_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_058_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_059_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_059_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_059_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_060_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_060_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_061_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_061_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_062_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_062_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_062_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_063_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_063_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_063_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_064_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_064_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_065_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_065_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_066_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_066_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_066_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_067_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_067_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_067_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_068_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_068_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_068_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_069_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_069_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_069_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_070_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_070_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_070_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_071_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_071_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_071_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_072_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_072_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_072_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_073_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_073_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_073_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_074_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_075_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_074_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_074_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_076_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_077_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_076_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_076_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_078_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_078_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_078_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_079_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_079_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_079_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_080_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_081_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_080_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_080_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_082_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_082_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_082_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_083_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_083_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_084_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_084_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_084_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_085_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_085_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_086_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_087_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_087_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_087_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_088_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_088_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_089_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_089_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_090_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_090_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_091_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_091_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_092_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_092_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_093_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_093_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_094_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_095_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_095_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_096_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_097_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_096_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_096_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_098_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_098_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_098_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_099_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_099_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_099_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_100_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_100_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_100_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_101_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_101_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_101_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_102_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_102_Entries0C[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_102_Entries10[];
extern u16 const gUnk_CookingRecipeDefinition_103_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_104_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_105_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_106_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_107_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_108_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_109_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_110_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_111_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_112_Values08[];
extern CookingRecipeUnknownValueOffsetEntry const gUnk_CookingRecipeDefinition_111_Entries0C[];
extern u16 const gUnk_CookingRecipeDefinition_113_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_114_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_115_Values08[];
extern u16 const gUnk_CookingRecipeDefinition_116_Values08[];

CookingRecipeDefinition const gCookingRecipeDefinitions[]
    SECTION(".rodata.cooking_recipe_definitions") = {
    /* 000 */ { 0x0017, 0x0001, -1, 0x0210, gUnk_CookingRecipeDefinition_000_Values08, nullptr, nullptr },
    /* 001 */ { 0x0018, 0x0002, -1, 0x0210, gUnk_CookingRecipeDefinition_001_Values08, gUnk_CookingRecipeDefinition_001_Entries0C, nullptr },
    /* 002 */ { 0x0019, 0x0003, -1, 0x0210, gUnk_CookingRecipeDefinition_002_Values08, gUnk_CookingRecipeDefinition_002_Entries0C, nullptr },
    /* 003 */ { 0x001A, 0x0004, -2, 0x0210, gUnk_CookingRecipeDefinition_003_Values08, gUnk_CookingRecipeDefinition_003_Entries0C, nullptr },
    /* 004 */ { 0x001B, 0x0005, -3, 0x0210, gUnk_CookingRecipeDefinition_004_Values08, gUnk_CookingRecipeDefinition_004_Entries0C, nullptr },
    /* 005 */ { 0x001C, 0x0006, -3, 0x0210, gUnk_CookingRecipeDefinition_005_Values08, gUnk_CookingRecipeDefinition_005_Entries0C, nullptr },
    /* 006 */ { 0x001C, 0x0006, -3, 0x0000, gUnk_CookingRecipeDefinition_006_Values08, gUnk_CookingRecipeDefinition_005_Entries0C, nullptr },
    /* 007 */ { 0x0015, 0x0006, -4, 0x0000, gUnk_CookingRecipeDefinition_007_Values08, nullptr, nullptr },
    /* 008 */ { 0x0022, 0x0007, -5, 0x0000, gUnk_CookingRecipeDefinition_008_Values08, nullptr, nullptr },
    /* 009 */ { 0x0028, 0x000A, -4, 0x0000, gUnk_CookingRecipeDefinition_009_Values08, nullptr, nullptr },
    /* 010 */ { 0x004C, 0x0001, -40, 0x0004, gUnk_CookingRecipeDefinition_010_Values08, nullptr, nullptr },
    /* 011 */ { 0x0060, 0x0014, -7, 0x0100, gUnk_CookingRecipeDefinition_011_Values08, nullptr, gUnk_CookingRecipeDefinition_011_Entries10 },
    /* 012 */ { 0x004D, 0x0014, -5, 0x0001, gUnk_CookingRecipeDefinition_012_Values08, gUnk_CookingRecipeDefinition_012_Entries0C, gUnk_CookingRecipeDefinition_012_Entries10 },
    /* 013 */ { 0x004E, 0x001E, -2, 0x0004, gUnk_CookingRecipeDefinition_013_Values08, gUnk_CookingRecipeDefinition_013_Entries0C, gUnk_CookingRecipeDefinition_013_Entries10 },
    /* 014 */ { 0x004F, 0x001E, -2, 0x0104, gUnk_CookingRecipeDefinition_014_Values08, gUnk_CookingRecipeDefinition_014_Entries0C, gUnk_CookingRecipeDefinition_014_Entries10 },
    /* 015 */ { 0x0050, 0x0005, -3, 0x0804, gUnk_CookingRecipeDefinition_015_Values08, gUnk_CookingRecipeDefinition_015_Entries0C, gUnk_CookingRecipeDefinition_015_Entries10 },
    /* 016 */ { 0x0051, 0x0028, -1, 0x0403, gUnk_CookingRecipeDefinition_016_Values08, gUnk_CookingRecipeDefinition_016_Entries0C, gUnk_CookingRecipeDefinition_016_Entries10 },
    /* 017 */ { 0x0052, 0x0028, -1, 0x0002, gUnk_CookingRecipeDefinition_017_Values08, gUnk_CookingRecipeDefinition_017_Entries0C, gUnk_CookingRecipeDefinition_017_Entries10 },
    /* 018 */ { 0x0053, 0x0032, -1, 0x0003, gUnk_CookingRecipeDefinition_018_Values08, gUnk_CookingRecipeDefinition_018_Entries0C, gUnk_CookingRecipeDefinition_018_Entries10 },
    /* 019 */ { 0x0054, 0x0028, -5, 0x0001, gUnk_CookingRecipeDefinition_019_Values08, gUnk_CookingRecipeDefinition_019_Entries0C, gUnk_CookingRecipeDefinition_019_Entries10 },
    /* 020 */ { 0x0055, 0x0014, -15, 0x0008, gUnk_CookingRecipeDefinition_020_Values08, gUnk_CookingRecipeDefinition_020_Entries0C, gUnk_CookingRecipeDefinition_020_Entries10 },
    /* 021 */ { 0x0058, 0x001E, -15, 0x0008, gUnk_CookingRecipeDefinition_021_Values08, gUnk_CookingRecipeDefinition_021_Entries0C, gUnk_CookingRecipeDefinition_021_Entries10 },
    /* 022 */ { 0x0056, 0x0014, -20, 0x0008, gUnk_CookingRecipeDefinition_022_Values08, gUnk_CookingRecipeDefinition_022_Entries0C, gUnk_CookingRecipeDefinition_022_Entries10 },
    /* 023 */ { 0x0059, 0x001E, -20, 0x0008, gUnk_CookingRecipeDefinition_023_Values08, gUnk_CookingRecipeDefinition_023_Entries0C, gUnk_CookingRecipeDefinition_023_Entries10 },
    /* 024 */ { 0x0057, 0x0032, -30, 0x0008, gUnk_CookingRecipeDefinition_024_Values08, gUnk_CookingRecipeDefinition_024_Entries0C, gUnk_CookingRecipeDefinition_024_Entries10 },
    /* 025 */ { 0x0057, 0x0032, -30, 0x0008, gUnk_CookingRecipeDefinition_025_Values08, gUnk_CookingRecipeDefinition_024_Entries0C, gUnk_CookingRecipeDefinition_024_Entries10 },
    /* 026 */ { 0x005A, 0x003C, -20, 0x0008, gUnk_CookingRecipeDefinition_026_Values08, gUnk_CookingRecipeDefinition_026_Entries0C, gUnk_CookingRecipeDefinition_026_Entries10 },
    /* 027 */ { 0x005A, 0x003C, -20, 0x0008, gUnk_CookingRecipeDefinition_027_Values08, gUnk_CookingRecipeDefinition_026_Entries0C, gUnk_CookingRecipeDefinition_026_Entries10 },
    /* 028 */ { 0x005A, 0x003C, -20, 0x0008, gUnk_CookingRecipeDefinition_028_Values08, gUnk_CookingRecipeDefinition_026_Entries0C, gUnk_CookingRecipeDefinition_026_Entries10 },
    /* 029 */ { 0x005E, 0x0014, -4, 0x0201, gUnk_CookingRecipeDefinition_029_Values08, nullptr, gUnk_CookingRecipeDefinition_029_Entries10 },
    /* 030 */ { 0x005F, 0x001E, -2, 0x0003, gUnk_CookingRecipeDefinition_030_Values08, gUnk_CookingRecipeDefinition_030_Entries0C, gUnk_CookingRecipeDefinition_030_Entries10 },
    /* 031 */ { 0x005C, 0x0005, -5, 0x0084, gUnk_CookingRecipeDefinition_031_Values08, gUnk_CookingRecipeDefinition_031_Entries0C, gUnk_CookingRecipeDefinition_031_Entries10 },
    /* 032 */ { 0x005B, 0x001E, -15, 0x0008, gUnk_CookingRecipeDefinition_032_Values08, gUnk_CookingRecipeDefinition_032_Entries0C, gUnk_CookingRecipeDefinition_032_Entries10 },
    /* 033 */ { 0x005D, 0x0014, -20, 0x0008, gUnk_CookingRecipeDefinition_033_Values08, nullptr, gUnk_CookingRecipeDefinition_033_Entries10 },
    /* 034 */ { 0x0061, 0x0001, 0x0000, 0x0388, gUnk_CookingRecipeDefinition_034_Values08, nullptr, nullptr },
    /* 035 */ { 0x0062, 0x001E, -1, 0x0002, gUnk_CookingRecipeDefinition_035_Values08, gUnk_CookingRecipeDefinition_035_Entries0C, gUnk_CookingRecipeDefinition_035_Entries10 },
    /* 036 */ { 0x0063, 0x000A, -2, 0x1020, gUnk_CookingRecipeDefinition_036_Values08, gUnk_CookingRecipeDefinition_036_Entries0C, gUnk_CookingRecipeDefinition_036_Entries10 },
    /* 037 */ { 0x0064, 0x0007, -1, 0x0040, gUnk_CookingRecipeDefinition_037_Values08, gUnk_CookingRecipeDefinition_037_Entries0C, gUnk_CookingRecipeDefinition_037_Entries10 },
    /* 038 */ { 0x0065, 0x0005, -15, 0x0008, gUnk_CookingRecipeDefinition_038_Values08, gUnk_CookingRecipeDefinition_038_Entries0C, gUnk_CookingRecipeDefinition_038_Entries10 },
    /* 039 */ { 0x0066, 0x0032, -10, 0x00C4, gUnk_CookingRecipeDefinition_039_Values08, gUnk_CookingRecipeDefinition_039_Entries0C, gUnk_CookingRecipeDefinition_039_Entries10 },
    /* 040 */ { 0x0067, 0x0008, -1, 0x0484, gUnk_CookingRecipeDefinition_040_Values08, gUnk_CookingRecipeDefinition_040_Entries0C, gUnk_CookingRecipeDefinition_040_Entries10 },
    /* 041 */ { 0x0068, 0x001E, -2, 0x0C82, gUnk_CookingRecipeDefinition_041_Values08, nullptr, gUnk_CookingRecipeDefinition_041_Entries10 },
    /* 042 */ { 0x0069, 0x0028, -5, 0x00C4, gUnk_CookingRecipeDefinition_042_Values08, gUnk_CookingRecipeDefinition_042_Entries0C, nullptr },
    /* 043 */ { 0x006A, 0x0028, -5, 0x0040, gUnk_CookingRecipeDefinition_043_Values08, gUnk_CookingRecipeDefinition_043_Entries0C, gUnk_CookingRecipeDefinition_043_Entries10 },
    /* 044 */ { 0x006B, 0x0014, -1, 0x0404, gUnk_CookingRecipeDefinition_044_Values08, gUnk_CookingRecipeDefinition_044_Entries0C, gUnk_CookingRecipeDefinition_044_Entries10 },
    /* 045 */ { 0x006C, 0x0028, -3, 0x0002, gUnk_CookingRecipeDefinition_045_Values08, gUnk_CookingRecipeDefinition_045_Entries0C, gUnk_CookingRecipeDefinition_045_Entries10 },
    /* 046 */ { 0x006D, 0x0032, -4, 0x0002, gUnk_CookingRecipeDefinition_046_Values08, gUnk_CookingRecipeDefinition_046_Entries0C, gUnk_CookingRecipeDefinition_046_Entries10 },
    /* 047 */ { 0x006E, 0x003C, -4, 0x0002, gUnk_CookingRecipeDefinition_047_Values08, gUnk_CookingRecipeDefinition_047_Entries0C, gUnk_CookingRecipeDefinition_047_Entries10 },
    /* 048 */ { 0x006F, 0x0014, -2, 0x0004, gUnk_CookingRecipeDefinition_048_Values08, gUnk_CookingRecipeDefinition_048_Entries0C, gUnk_CookingRecipeDefinition_048_Entries10 },
    /* 049 */ { 0x0095, 0x001E, -8, 0x00C4, gUnk_CookingRecipeDefinition_049_Values08, gUnk_CookingRecipeDefinition_049_Entries0C, gUnk_CookingRecipeDefinition_049_Entries10 },
    /* 050 */ { 0x0070, 0x0014, -10, 0x0004, gUnk_CookingRecipeDefinition_050_Values08, gUnk_CookingRecipeDefinition_050_Entries0C, gUnk_CookingRecipeDefinition_050_Entries10 },
    /* 051 */ { 0x0071, 0x0001, 0x0000, 0x0008, gUnk_CookingRecipeDefinition_051_Values08, gUnk_CookingRecipeDefinition_051_Entries0C, gUnk_CookingRecipeDefinition_051_Entries10 },
    /* 052 */ { 0x0072, 0x0032, -5, 0x00D4, gUnk_CookingRecipeDefinition_052_Values08, gUnk_CookingRecipeDefinition_052_Entries0C, gUnk_CookingRecipeDefinition_052_Entries10 },
    /* 053 */ { 0x0073, 0x0028, -3, 0x0004, gUnk_CookingRecipeDefinition_053_Values08, gUnk_CookingRecipeDefinition_053_Entries0C, gUnk_CookingRecipeDefinition_053_Entries10 },
    /* 054 */ { 0x0074, 0x0032, -8, 0x00E5, gUnk_CookingRecipeDefinition_054_Values08, gUnk_CookingRecipeDefinition_054_Entries0C, nullptr },
    /* 055 */ { 0x0075, 0x0005, -5, 0x0084, gUnk_CookingRecipeDefinition_055_Values08, gUnk_CookingRecipeDefinition_055_Entries0C, gUnk_CookingRecipeDefinition_055_Entries10 },
    /* 056 */ { 0x0076, 0x0008, -2, 0x0002, gUnk_CookingRecipeDefinition_056_Values08, gUnk_CookingRecipeDefinition_056_Entries0C, gUnk_CookingRecipeDefinition_056_Entries10 },
    /* 057 */ { 0x0078, 0x001E, -1, 0x0000, gUnk_CookingRecipeDefinition_057_Values08, nullptr, gUnk_CookingRecipeDefinition_057_Entries10 },
    /* 058 */ { 0x007E, 0x0005, -5, 0x0084, gUnk_CookingRecipeDefinition_058_Values08, gUnk_CookingRecipeDefinition_058_Entries0C, gUnk_CookingRecipeDefinition_058_Entries10 },
    /* 059 */ { 0x003F, 0x0005, -5, 0x0008, gUnk_CookingRecipeDefinition_059_Values08, gUnk_CookingRecipeDefinition_059_Entries0C, gUnk_CookingRecipeDefinition_059_Entries10 },
    /* 060 */ { 0x0077, 0x001E, -1, 0x0000, gUnk_CookingRecipeDefinition_060_Values08, nullptr, gUnk_CookingRecipeDefinition_060_Entries10 },
    /* 061 */ { 0x0079, 0x003C, -1, 0x0000, gUnk_CookingRecipeDefinition_061_Values08, nullptr, gUnk_CookingRecipeDefinition_061_Entries10 },
    /* 062 */ { 0x007A, 0x0028, -1, 0x0200, gUnk_CookingRecipeDefinition_062_Values08, gUnk_CookingRecipeDefinition_062_Entries0C, gUnk_CookingRecipeDefinition_062_Entries10 },
    /* 063 */ { 0x007B, 0x0028, -5, 0x0000, gUnk_CookingRecipeDefinition_063_Values08, gUnk_CookingRecipeDefinition_063_Entries0C, gUnk_CookingRecipeDefinition_063_Entries10 },
    /* 064 */ { 0x007C, 0x0028, -2, 0x0000, gUnk_CookingRecipeDefinition_064_Values08, gUnk_CookingRecipeDefinition_064_Entries0C, nullptr },
    /* 065 */ { 0x007D, 0x001E, -4, 0x0000, gUnk_CookingRecipeDefinition_065_Values08, gUnk_CookingRecipeDefinition_065_Entries0C, nullptr },
    /* 066 */ { 0x007F, 0x001E, -2, 0x0002, gUnk_CookingRecipeDefinition_066_Values08, gUnk_CookingRecipeDefinition_066_Entries0C, gUnk_CookingRecipeDefinition_066_Entries10 },
    /* 067 */ { 0x0093, 0x0007, -1, 0x0040, gUnk_CookingRecipeDefinition_067_Values08, gUnk_CookingRecipeDefinition_067_Entries0C, gUnk_CookingRecipeDefinition_067_Entries10 },
    /* 068 */ { 0x0094, 0x001E, -2, 0x0002, gUnk_CookingRecipeDefinition_068_Values08, gUnk_CookingRecipeDefinition_068_Entries0C, gUnk_CookingRecipeDefinition_068_Entries10 },
    /* 069 */ { 0x0080, 0x001E, -3, 0x0001, gUnk_CookingRecipeDefinition_069_Values08, gUnk_CookingRecipeDefinition_069_Entries0C, gUnk_CookingRecipeDefinition_069_Entries10 },
    /* 070 */ { 0x0081, 0x001E, -1, 0x0002, gUnk_CookingRecipeDefinition_070_Values08, gUnk_CookingRecipeDefinition_070_Entries0C, gUnk_CookingRecipeDefinition_070_Entries10 },
    /* 071 */ { 0x0082, 0x0032, -1, 0x0201, gUnk_CookingRecipeDefinition_071_Values08, gUnk_CookingRecipeDefinition_071_Entries0C, gUnk_CookingRecipeDefinition_071_Entries10 },
    /* 072 */ { 0x0083, 0x0028, -1, 0x0060, gUnk_CookingRecipeDefinition_072_Values08, gUnk_CookingRecipeDefinition_072_Entries0C, gUnk_CookingRecipeDefinition_072_Entries10 },
    /* 073 */ { 0x0084, 0x0028, -3, 0x0025, gUnk_CookingRecipeDefinition_073_Values08, gUnk_CookingRecipeDefinition_073_Entries0C, gUnk_CookingRecipeDefinition_073_Entries10 },
    /* 074 */ { 0x0085, 0x003C, -3, 0x0004, gUnk_CookingRecipeDefinition_074_Values08, gUnk_CookingRecipeDefinition_074_Entries0C, gUnk_CookingRecipeDefinition_074_Entries10 },
    /* 075 */ { 0x0085, 0x003C, -3, 0x0025, gUnk_CookingRecipeDefinition_075_Values08, gUnk_CookingRecipeDefinition_074_Entries0C, gUnk_CookingRecipeDefinition_074_Entries10 },
    /* 076 */ { 0x0086, 0x003C, -3, 0x0025, gUnk_CookingRecipeDefinition_076_Values08, gUnk_CookingRecipeDefinition_076_Entries0C, gUnk_CookingRecipeDefinition_076_Entries10 },
    /* 077 */ { 0x0086, 0x003C, -3, 0x0004, gUnk_CookingRecipeDefinition_077_Values08, gUnk_CookingRecipeDefinition_076_Entries0C, gUnk_CookingRecipeDefinition_076_Entries10 },
    /* 078 */ { 0x0087, 0x003C, -2, 0x0002, gUnk_CookingRecipeDefinition_078_Values08, gUnk_CookingRecipeDefinition_078_Entries0C, gUnk_CookingRecipeDefinition_078_Entries10 },
    /* 079 */ { 0x0088, 0x0028, -3, 0x0025, gUnk_CookingRecipeDefinition_079_Values08, gUnk_CookingRecipeDefinition_079_Entries0C, gUnk_CookingRecipeDefinition_079_Entries10 },
    /* 080 */ { 0x0089, 0x003C, -3, 0x0025, gUnk_CookingRecipeDefinition_080_Values08, gUnk_CookingRecipeDefinition_080_Entries0C, gUnk_CookingRecipeDefinition_080_Entries10 },
    /* 081 */ { 0x0089, 0x003C, -3, 0x0004, gUnk_CookingRecipeDefinition_081_Values08, gUnk_CookingRecipeDefinition_080_Entries0C, gUnk_CookingRecipeDefinition_080_Entries10 },
    /* 082 */ { 0x008A, 0x003C, -2, 0x0002, gUnk_CookingRecipeDefinition_082_Values08, gUnk_CookingRecipeDefinition_082_Entries0C, gUnk_CookingRecipeDefinition_082_Entries10 },
    /* 083 */ { 0x008B, 0x000F, -2, 0x0004, gUnk_CookingRecipeDefinition_083_Values08, nullptr, gUnk_CookingRecipeDefinition_083_Entries10 },
    /* 084 */ { 0x008E, 0x0014, -2, 0x0002, gUnk_CookingRecipeDefinition_084_Values08, gUnk_CookingRecipeDefinition_084_Entries0C, gUnk_CookingRecipeDefinition_084_Entries10 },
    /* 085 */ { 0x0096, 0x0028, -1, 0x0485, gUnk_CookingRecipeDefinition_085_Values08, gUnk_CookingRecipeDefinition_085_Entries0C, nullptr },
    /* 086 */ { 0x0097, 0x0028, -3, 0x0080, gUnk_CookingRecipeDefinition_086_Values08, nullptr, nullptr },
    /* 087 */ { 0x0099, 0x000A, -2, 0x1000, gUnk_CookingRecipeDefinition_087_Values08, gUnk_CookingRecipeDefinition_087_Entries0C, gUnk_CookingRecipeDefinition_087_Entries10 },
    /* 088 */ { 0x00A4, 0x0005, -1, 0x0040, gUnk_CookingRecipeDefinition_088_Values08, nullptr, gUnk_CookingRecipeDefinition_088_Entries10 },
    /* 089 */ { 0x00A7, 0x0005, -3, 0x0104, gUnk_CookingRecipeDefinition_089_Values08, gUnk_CookingRecipeDefinition_089_Entries0C, nullptr },
    /* 090 */ { 0x00A5, 0x001E, -2, 0x0000, gUnk_CookingRecipeDefinition_090_Values08, nullptr, gUnk_CookingRecipeDefinition_090_Entries10 },
    /* 091 */ { 0x00A6, 0x0014, -1, 0x0004, gUnk_CookingRecipeDefinition_091_Values08, nullptr, gUnk_CookingRecipeDefinition_091_Entries10 },
    /* 092 */ { 0x00AA, 0x0008, -1, 0x0004, gUnk_CookingRecipeDefinition_092_Values08, nullptr, gUnk_CookingRecipeDefinition_092_Entries10 },
    /* 093 */ { 0x00AB, 0x0014, -2, 0x0103, gUnk_CookingRecipeDefinition_093_Values08, nullptr, gUnk_CookingRecipeDefinition_093_Entries10 },
    /* 094 */ { 0x00A9, 0x0005, -1, 0x0108, gUnk_CookingRecipeDefinition_094_Values08, nullptr, nullptr },
    /* 095 */ { 0x008C, 0x000F, -5, 0x00E0, gUnk_CookingRecipeDefinition_095_Values08, gUnk_CookingRecipeDefinition_095_Entries0C, nullptr },
    /* 096 */ { 0x008D, 0x001E, -5, 0x00E0, gUnk_CookingRecipeDefinition_096_Values08, gUnk_CookingRecipeDefinition_096_Entries0C, gUnk_CookingRecipeDefinition_096_Entries10 },
    /* 097 */ { 0x008D, 0x001E, -5, 0x0000, gUnk_CookingRecipeDefinition_097_Values08, gUnk_CookingRecipeDefinition_096_Entries0C, gUnk_CookingRecipeDefinition_096_Entries10 },
    /* 098 */ { 0x008F, 0x001E, -20, 0x0094, gUnk_CookingRecipeDefinition_098_Values08, gUnk_CookingRecipeDefinition_098_Entries0C, gUnk_CookingRecipeDefinition_098_Entries10 },
    /* 099 */ { 0x0090, 0x0028, -8, 0x00D0, gUnk_CookingRecipeDefinition_099_Values08, gUnk_CookingRecipeDefinition_099_Entries0C, gUnk_CookingRecipeDefinition_099_Entries10 },
    /* 100 */ { 0x0091, 0x0046, -8, 0x00D0, gUnk_CookingRecipeDefinition_100_Values08, gUnk_CookingRecipeDefinition_100_Entries0C, gUnk_CookingRecipeDefinition_100_Entries10 },
    /* 101 */ { 0x00A8, 0x0014, -3, 0x0002, gUnk_CookingRecipeDefinition_101_Values08, gUnk_CookingRecipeDefinition_101_Entries0C, gUnk_CookingRecipeDefinition_101_Entries10 },
    /* 102 */ { 0x0092, 0x0032, -50, 0x0004, gUnk_CookingRecipeDefinition_102_Values08, gUnk_CookingRecipeDefinition_102_Entries0C, gUnk_CookingRecipeDefinition_102_Entries10 },
    /* 103 */ { 0x0048, 0x0002, -2, 0x0000, gUnk_CookingRecipeDefinition_103_Values08, nullptr, nullptr },
    /* 104 */ { 0x0049, 0x0002, -2, 0x0000, gUnk_CookingRecipeDefinition_104_Values08, nullptr, nullptr },
    /* 105 */ { 0x004A, 0x0002, -2, 0x0000, gUnk_CookingRecipeDefinition_105_Values08, nullptr, nullptr },
    /* 106 */ { 0x003A, 0x0032, -1, 0x0004, gUnk_CookingRecipeDefinition_106_Values08, nullptr, nullptr },
    /* 107 */ { 0x003B, 0x0064, -1, 0x0008, gUnk_CookingRecipeDefinition_107_Values08, nullptr, nullptr },
    /* 108 */ { 0x003C, 0x0000, -20, 0x0004, gUnk_CookingRecipeDefinition_108_Values08, nullptr, nullptr },
    /* 109 */ { 0x003D, 0x0000, -50, 0x0008, gUnk_CookingRecipeDefinition_109_Values08, nullptr, nullptr },
    /* 110 */ { 0x0047, 0x0002, -3, 0x0003, gUnk_CookingRecipeDefinition_110_Values08, nullptr, nullptr },
    /* 111 */ { 0x009A, 0x0064, -50, 0x0FC7, gUnk_CookingRecipeDefinition_111_Values08, gUnk_CookingRecipeDefinition_111_Entries0C, nullptr },
    /* 112 */ { 0x009A, 0x0064, -50, 0x0FC7, gUnk_CookingRecipeDefinition_112_Values08, gUnk_CookingRecipeDefinition_111_Entries0C, nullptr },
    /* 113 */ { 0x00D4, 0x0000, 0x0000, 0x0000, gUnk_CookingRecipeDefinition_113_Values08, nullptr, nullptr },
    /* 114 */ { 0x00D5, 0x0000, 0x0000, 0x0000, gUnk_CookingRecipeDefinition_114_Values08, nullptr, nullptr },
    /* 115 */ { 0x00D6, 0x0000, 0x0000, 0x0000, gUnk_CookingRecipeDefinition_115_Values08, nullptr, nullptr },
    /* 116 */ { 0x00D7, 0x0000, 0x0000, 0x0000, gUnk_CookingRecipeDefinition_116_Values08, nullptr, nullptr },
    {},
};

EXTERN_C_END
