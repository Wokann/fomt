#ifndef COOKING_RECIPE_INVENTORY_HH
#define COOKING_RECIPE_INVENTORY_HH

#include "prelude.h"

EXTERN_C

struct CookingRecipeInventoryMaskEntry
{
    u16 required_mask;
    u16 selected_value;
};

// func_0809A58C walks these four-byte, zero-key-terminated records through
// the +0x0C and +0x10 pointers of a recipe definition.  The meanings of the
// signed adjustment bytes are not established yet.
struct ALIGN(4) CookingRecipeUnknownValueOffsetEntry
{
    u16 value;
    i8 unk_02;
    i8 unk_03;
};

// This table is terminated by a completely zero record.  The native recipe
// path reads the scalar fields and the three pointed lists directly; keep
// unproven field roles explicit rather than assigning speculative names.
struct CookingRecipeDefinition
{
    u16 recipe_id;
    u16 unk_02;
    i16 unk_04;
    u16 unk_06;
    u16 const * values_08;
    CookingRecipeUnknownValueOffsetEntry const * entries_0c;
    CookingRecipeUnknownValueOffsetEntry const * entries_10;
};

// This is the physically contiguous recipe-list payload immediately after
// gCookingRecipeDefinitions. Members are in ROM order. A name identifies
// the first definition field that reaches the list; later definitions may
// intentionally reuse that member.
struct ALIGN(4) CookingRecipeDefinitionPayload
{
    u16 recipe_000_values_08[3];
    u16 recipe_001_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_001_entries_0c[2];
    u16 recipe_002_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_002_entries_0c[3];
    u16 recipe_003_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_003_entries_0c[4];
    u16 recipe_004_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_004_entries_0c[5];
    u16 recipe_005_values_08[3];
    u16 recipe_006_values_08[6];
    CookingRecipeUnknownValueOffsetEntry recipe_005_entries_0c[6];
    u16 recipe_007_values_08[6];
    u16 recipe_008_values_08[6];
    u16 recipe_009_values_08[6];
    u16 recipe_010_values_08[4];
    u16 recipe_012_values_08[5];
    CookingRecipeUnknownValueOffsetEntry recipe_012_entries_0c[36];
    CookingRecipeUnknownValueOffsetEntry recipe_012_entries_10[4];
    u16 recipe_013_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_013_entries_0c[57];
    CookingRecipeUnknownValueOffsetEntry recipe_013_entries_10[6];
    u16 recipe_014_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_014_entries_0c[57];
    CookingRecipeUnknownValueOffsetEntry recipe_014_entries_10[5];
    u16 recipe_015_values_08[1];
    CookingRecipeUnknownValueOffsetEntry recipe_015_entries_0c[30];
    CookingRecipeUnknownValueOffsetEntry recipe_015_entries_10[6];
    u16 recipe_016_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_016_entries_0c[19];
    CookingRecipeUnknownValueOffsetEntry recipe_016_entries_10[4];
    u16 recipe_017_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_017_entries_0c[39];
    CookingRecipeUnknownValueOffsetEntry recipe_017_entries_10[5];
    u16 recipe_018_values_08[5];
    CookingRecipeUnknownValueOffsetEntry recipe_018_entries_0c[48];
    CookingRecipeUnknownValueOffsetEntry recipe_018_entries_10[3];
    u16 recipe_019_values_08[5];
    CookingRecipeUnknownValueOffsetEntry recipe_019_entries_0c[42];
    CookingRecipeUnknownValueOffsetEntry recipe_019_entries_10[3];
    u16 recipe_020_values_08[6];
    CookingRecipeUnknownValueOffsetEntry recipe_020_entries_0c[11];
    CookingRecipeUnknownValueOffsetEntry recipe_020_entries_10[5];
    u16 recipe_021_values_08[9];
    CookingRecipeUnknownValueOffsetEntry recipe_021_entries_0c[18];
    CookingRecipeUnknownValueOffsetEntry recipe_021_entries_10[5];
    u16 recipe_022_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_022_entries_0c[17];
    CookingRecipeUnknownValueOffsetEntry recipe_022_entries_10[5];
    u16 recipe_023_values_08[6];
    CookingRecipeUnknownValueOffsetEntry recipe_023_entries_0c[24];
    CookingRecipeUnknownValueOffsetEntry recipe_023_entries_10[5];
    u16 recipe_024_values_08[11];
    u16 recipe_025_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_024_entries_0c[28];
    CookingRecipeUnknownValueOffsetEntry recipe_024_entries_10[5];
    u16 recipe_026_values_08[12];
    u16 recipe_027_values_08[3];
    u16 recipe_028_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_026_entries_0c[36];
    CookingRecipeUnknownValueOffsetEntry recipe_026_entries_10[5];
    u16 recipe_029_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_029_entries_10[4];
    u16 recipe_030_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_030_entries_0c[2];
    CookingRecipeUnknownValueOffsetEntry recipe_030_entries_10[3];
    u16 recipe_011_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_011_entries_10[3];
    u16 recipe_031_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_031_entries_0c[3];
    CookingRecipeUnknownValueOffsetEntry recipe_031_entries_10[3];
    u16 recipe_032_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_032_entries_0c[8];
    CookingRecipeUnknownValueOffsetEntry recipe_032_entries_10[3];
    u16 recipe_033_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_033_entries_10[3];
    u16 recipe_034_values_08[3];
    u16 recipe_035_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_035_entries_0c[2];
    CookingRecipeUnknownValueOffsetEntry recipe_035_entries_10[3];
    u16 recipe_036_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_036_entries_0c[15];
    CookingRecipeUnknownValueOffsetEntry recipe_036_entries_10[2];
    u16 recipe_037_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_037_entries_0c[3];
    CookingRecipeUnknownValueOffsetEntry recipe_037_entries_10[4];
    u16 recipe_038_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_038_entries_0c[2];
    CookingRecipeUnknownValueOffsetEntry recipe_038_entries_10[5];
    u16 recipe_039_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_039_entries_0c[15];
    CookingRecipeUnknownValueOffsetEntry recipe_039_entries_10[2];
    u16 recipe_040_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_040_entries_0c[4];
    CookingRecipeUnknownValueOffsetEntry recipe_040_entries_10[4];
    u16 recipe_041_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_041_entries_10[2];
    u16 recipe_042_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_042_entries_0c[7];
    u16 recipe_043_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_043_entries_0c[3];
    CookingRecipeUnknownValueOffsetEntry recipe_043_entries_10[3];
    u16 recipe_044_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_044_entries_0c[2];
    CookingRecipeUnknownValueOffsetEntry recipe_044_entries_10[3];
    u16 recipe_045_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_045_entries_0c[14];
    CookingRecipeUnknownValueOffsetEntry recipe_045_entries_10[5];
    u16 recipe_046_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_046_entries_0c[42];
    CookingRecipeUnknownValueOffsetEntry recipe_046_entries_10[6];
    u16 recipe_047_values_08[5];
    CookingRecipeUnknownValueOffsetEntry recipe_047_entries_0c[42];
    CookingRecipeUnknownValueOffsetEntry recipe_047_entries_10[6];
    u16 recipe_048_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_048_entries_0c[13];
    CookingRecipeUnknownValueOffsetEntry recipe_048_entries_10[2];
    u16 recipe_049_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_049_entries_0c[28];
    CookingRecipeUnknownValueOffsetEntry recipe_049_entries_10[2];
    u16 recipe_050_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_050_entries_0c[7];
    CookingRecipeUnknownValueOffsetEntry recipe_050_entries_10[2];
    u16 recipe_051_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_051_entries_0c[7];
    CookingRecipeUnknownValueOffsetEntry recipe_051_entries_10[2];
    u16 recipe_052_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_052_entries_0c[25];
    CookingRecipeUnknownValueOffsetEntry recipe_052_entries_10[2];
    u16 recipe_053_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_053_entries_0c[20];
    CookingRecipeUnknownValueOffsetEntry recipe_053_entries_10[5];
    u16 recipe_054_values_08[8];
    CookingRecipeUnknownValueOffsetEntry recipe_054_entries_0c[15];
    u16 recipe_055_values_08[5];
    CookingRecipeUnknownValueOffsetEntry recipe_055_entries_0c[8];
    CookingRecipeUnknownValueOffsetEntry recipe_055_entries_10[3];
    u16 recipe_056_values_08[5];
    CookingRecipeUnknownValueOffsetEntry recipe_056_entries_0c[3];
    CookingRecipeUnknownValueOffsetEntry recipe_056_entries_10[3];
    u16 recipe_057_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_057_entries_10[5];
    u16 recipe_058_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_058_entries_0c[4];
    CookingRecipeUnknownValueOffsetEntry recipe_058_entries_10[2];
    u16 recipe_059_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_059_entries_0c[2];
    CookingRecipeUnknownValueOffsetEntry recipe_059_entries_10[5];
    u16 recipe_060_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_060_entries_10[5];
    u16 recipe_061_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_061_entries_10[5];
    u16 recipe_062_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_062_entries_0c[2];
    CookingRecipeUnknownValueOffsetEntry recipe_062_entries_10[2];
    u16 recipe_063_values_08[5];
    CookingRecipeUnknownValueOffsetEntry recipe_063_entries_0c[5];
    CookingRecipeUnknownValueOffsetEntry recipe_063_entries_10[3];
    u16 recipe_064_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_064_entries_0c[2];
    u16 recipe_065_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_065_entries_0c[3];
    u16 recipe_066_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_066_entries_0c[56];
    CookingRecipeUnknownValueOffsetEntry recipe_066_entries_10[6];
    u16 recipe_067_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_067_entries_0c[6];
    CookingRecipeUnknownValueOffsetEntry recipe_067_entries_10[3];
    u16 recipe_068_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_068_entries_0c[15];
    CookingRecipeUnknownValueOffsetEntry recipe_068_entries_10[3];
    u16 recipe_069_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_069_entries_0c[3];
    CookingRecipeUnknownValueOffsetEntry recipe_069_entries_10[2];
    u16 recipe_070_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_070_entries_0c[2];
    CookingRecipeUnknownValueOffsetEntry recipe_070_entries_10[3];
    u16 recipe_071_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_071_entries_0c[9];
    CookingRecipeUnknownValueOffsetEntry recipe_071_entries_10[2];
    u16 recipe_072_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_072_entries_0c[36];
    CookingRecipeUnknownValueOffsetEntry recipe_072_entries_10[4];
    u16 recipe_073_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_073_entries_0c[25];
    CookingRecipeUnknownValueOffsetEntry recipe_073_entries_10[6];
    u16 recipe_074_values_08[3];
    u16 recipe_075_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_074_entries_0c[25];
    CookingRecipeUnknownValueOffsetEntry recipe_074_entries_10[6];
    u16 recipe_076_values_08[3];
    u16 recipe_077_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_076_entries_0c[24];
    CookingRecipeUnknownValueOffsetEntry recipe_076_entries_10[6];
    u16 recipe_078_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_078_entries_0c[24];
    CookingRecipeUnknownValueOffsetEntry recipe_078_entries_10[6];
    u16 recipe_079_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_079_entries_0c[24];
    CookingRecipeUnknownValueOffsetEntry recipe_079_entries_10[6];
    u16 recipe_080_values_08[3];
    u16 recipe_081_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_080_entries_0c[24];
    CookingRecipeUnknownValueOffsetEntry recipe_080_entries_10[6];
    u16 recipe_082_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_082_entries_0c[24];
    CookingRecipeUnknownValueOffsetEntry recipe_082_entries_10[6];
    u16 recipe_083_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_083_entries_10[4];
    u16 recipe_084_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_084_entries_0c[31];
    CookingRecipeUnknownValueOffsetEntry recipe_084_entries_10[4];
    u16 recipe_085_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_085_entries_0c[9];
    u16 recipe_086_values_08[2];
    u16 recipe_087_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_087_entries_0c[3];
    CookingRecipeUnknownValueOffsetEntry recipe_087_entries_10[6];
    u16 recipe_088_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_088_entries_10[5];
    u16 recipe_089_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_089_entries_0c[10];
    u16 recipe_090_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_090_entries_10[4];
    u16 recipe_091_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_091_entries_10[4];
    u16 recipe_092_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_092_entries_10[3];
    u16 recipe_093_values_08[6];
    CookingRecipeUnknownValueOffsetEntry recipe_093_entries_10[2];
    u16 recipe_094_values_08[3];
    u16 recipe_095_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_095_entries_0c[8];
    u16 recipe_096_values_08[5];
    u16 recipe_097_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_096_entries_0c[8];
    CookingRecipeUnknownValueOffsetEntry recipe_096_entries_10[2];
    u16 recipe_098_values_08[3];
    CookingRecipeUnknownValueOffsetEntry recipe_098_entries_0c[24];
    CookingRecipeUnknownValueOffsetEntry recipe_098_entries_10[2];
    u16 recipe_099_values_08[4];
    CookingRecipeUnknownValueOffsetEntry recipe_099_entries_0c[20];
    CookingRecipeUnknownValueOffsetEntry recipe_099_entries_10[2];
    u16 recipe_100_values_08[5];
    CookingRecipeUnknownValueOffsetEntry recipe_100_entries_0c[20];
    CookingRecipeUnknownValueOffsetEntry recipe_100_entries_10[2];
    u16 recipe_101_values_08[7];
    CookingRecipeUnknownValueOffsetEntry recipe_101_entries_0c[6];
    CookingRecipeUnknownValueOffsetEntry recipe_101_entries_10[3];
    u16 recipe_102_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_102_entries_0c[25];
    CookingRecipeUnknownValueOffsetEntry recipe_102_entries_10[3];
    u16 recipe_103_values_08[4];
    u16 recipe_104_values_08[4];
    u16 recipe_105_values_08[4];
    u16 recipe_106_values_08[5];
    u16 recipe_107_values_08[3];
    u16 recipe_108_values_08[5];
    u16 recipe_109_values_08[3];
    u16 recipe_110_values_08[9];
    u16 recipe_111_values_08[9];
    u16 recipe_112_values_08[2];
    CookingRecipeUnknownValueOffsetEntry recipe_111_entries_0c[10];
    u16 recipe_113_values_08[6];
    u16 recipe_114_values_08[6];
    u16 recipe_115_values_08[7];
    u16 recipe_116_values_08[8];
};
enum
{
    COOKING_RECIPE_INVENTORY_UTENSIL_VALUE_COUNT = 8,
    COOKING_RECIPE_INVENTORY_MASK_ENTRY_COUNT = 9,
};

extern u16 const
    gCookingRecipeInventoryUtensilValues[COOKING_RECIPE_INVENTORY_UTENSIL_VALUE_COUNT];
extern CookingRecipeInventoryMaskEntry const
    gCookingRecipeInventoryMaskEntries[COOKING_RECIPE_INVENTORY_MASK_ENTRY_COUNT];
extern CookingRecipeDefinition const gCookingRecipeDefinitions[];
extern CookingRecipeDefinitionPayload const gCookingRecipeDefinitionPayload;

EXTERN_C_END

#endif // COOKING_RECIPE_INVENTORY_HH
