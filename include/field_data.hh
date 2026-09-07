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

extern FieldPlotWeatherRule const gFieldPlotOrdinaryWeatherRules[4][2];
extern FieldPlotWeatherRule const gFieldPlotSpecialWeatherRule3;
extern FieldPlotWeatherRule const gFieldPlotSpecialWeatherRule4;
extern u32 const gFieldPlotGrowthStageTransitions[21][21];
extern FieldPlotTypeDefinition const gFieldPlotTypeDefinitions[39];
extern FieldPlotPositionRule const gFieldPlotPositionRules[8];
extern char const gCppRuntimeBadAlloc_FieldPlotPositionRules[];

#endif // FIELD_DATA_HH
