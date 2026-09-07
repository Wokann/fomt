#ifndef FIELD_DATA_HH
#define FIELD_DATA_HH

#include "field.hh"

// One entry for each FieldPlot type.  The first pointer selects a contiguous
// group of render records; the next five bytes select a record for states 2-6.
struct FieldPlotTypeDefinition
{
    /* +00 */ Unk_Something const * render_variants;
    /* +04 */ u8 state_2_variant_index;
    /* +05 */ u8 state_3_variant_index;
    /* +06 */ u8 state_4_variant_index;
    /* +07 */ u8 state_5_variant_index;
    /* +08 */ u8 state_6_variant_index;
    /* +09 */ u8 reserved_variant_index;
    /* +0A */ u16 result_item_id;
};

struct FieldPlotWeatherRule
{
    u8 bytes[8];
};

// Native code first matches match_value, then tests the inclusive x/y bounds
// before returning result.
struct FieldPlotPositionRule
{
    u32 match_value;
    i32 minimum_x;
    i32 minimum_y;
    i32 maximum_x;
    i32 maximum_y;
    u32 result;
};

// The two bytes after height in the ROM layout are natural alignment before
// the pointer fields; they are not a separate data member.
struct FieldRenderRectDescriptor
{
    u8 width;
    u8 height;
    void const * source_buffers[3];
    void const * lookup_values;
    void const * lookup_indices;
};

// func_080A4F50 indexes every three-word span with the same slot.  The
// physical-offset names are intentional: the role of each span beyond that
// native behavior has not been recovered yet.
struct FieldRenderParallelTables
{
    u32 values_00[3];
    u32 values_0C[3];
    u32 values_18[3];
    u32 values_24[3];
    u32 values_30[3];
};

// func_080A6024 and func_080A607C read these bytes as arguments for
// func_080A5BD8.  The two native bases at +0x2C and +0x3C overlap, so their
// shared 0x30-byte physical region is deliberately represented only once.
struct FieldRenderPatchArgumentData
{
    u8 values_00[8];
    u8 values_08[4];
    u8 values_0C[16][2];
    u8 overlapping_values_2C[0x30];
    u8 values_5C[4];
};

// func_080AACB8 selects one half-open record-index span with the current
// season before it scans the shared trailing range.  The record payloads
// themselves are still retained in the native gUnk_081043BC block.
struct PACKED FieldRenderSeasonalRecordRange
{
    u8 first_record_index;
    u8 past_last_record_index;
};

#define FIELD_RENDER_RECT_DESCRIPTOR_COUNT 82

extern FieldPlotWeatherRule const gFieldPlotOrdinaryWeatherRules[4][2];
extern FieldPlotWeatherRule const gFieldPlotSpecialWeatherRule3;
extern FieldPlotWeatherRule const gFieldPlotSpecialWeatherRule4;
extern u32 const gFieldPlotGrowthStageTransitions[21][21];
extern FieldPlotTypeDefinition const gFieldPlotTypeDefinitions[39];
extern FieldRenderRectDescriptor const gFieldRenderRectDescriptors[FIELD_RENDER_RECT_DESCRIPTOR_COUNT];
extern FieldRenderParallelTables const gFieldRenderParallelTables;
extern FieldRenderPatchArgumentData const gFieldRenderPatchArgumentData;
extern FieldRenderSeasonalRecordRange const gFieldRenderSeasonalRecordRanges[NUM_SEASONS];
extern u16 const gUnk_FieldRenderLookupValues[18][2];
extern char const gCppRuntimeBadAlloc_FieldRenderRuntime00[];
extern char const gCppRuntimeBadAlloc_FieldRenderRuntime01[];
extern char const gCppRuntimeBadAlloc_FieldRenderRuntime02[];
extern char const gCppRuntimeBadAlloc_FieldRenderRuntime03[];
extern char const gCppRuntimeBadAlloc_FieldRenderRuntime04[];
extern char const gCppRuntimeError_FieldRenderRuntime[];
extern char const gText_FieldRenderFallbackNone[];
extern char const gCppRuntimeBadAlloc_FieldRenderRuntime05[];
extern u8 const gUnk_FieldRenderSortedValues[];
extern char const gCppRuntimeBadAlloc_FieldRenderSortedValuesFirst[];
extern char const gCppRuntimeBadAlloc_FieldRenderSortedValuesSecond[];
extern char const gCppRuntimeBadAlloc_FieldRenderResource00[];
extern char const gCppRuntimeBadAlloc_FieldRenderResource01[];
extern u32 const gUnk_080AE894InitialValues[5];
extern u32 const gUnk_080AE894LayoutValues[10];
extern char const gText_080B0708DefaultGlyph[];
extern u32 const gUnk_080B09B0IndexValues[7];
extern u32 const gUnk_080B0BB8FirstValues[5];
extern u32 const gUnk_080B0BB8SecondValues[5];
extern u16 const gFieldPlotPositionValues[7][4];
extern FieldPlotPositionRule const gFieldPlotPositionRules[8];
extern char const gCppRuntimeBadAlloc_FieldPlotPositionRules[];

#endif // FIELD_DATA_HH
