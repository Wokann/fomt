#ifndef FIELD_DATA_HH
#define FIELD_DATA_HH

#include "field.hh"

// These labels name still-raw field render records. Their payload format is
// not decoded yet, but all consumers use relocatable symbols.
extern Unk_Something const gUnk_FieldPlotRenderRecord_000[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_001[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_002[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_003[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_004[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_005[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_006[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_007[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_008[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_009[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_010[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_011[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_012[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_013[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_014[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_015[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_016[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_017[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_018[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_019[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_020[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_021[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_022[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_023[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_024[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_025[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_026[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_027[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_028[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_029[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_030[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_031[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_032[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_033[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_034[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_035[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_036[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_037[];
extern Unk_Something const gUnk_FieldPlotRenderRecord_038[];

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

extern FieldPlotWeatherRule const gFieldPlotOrdinaryWeatherRules[4][2];
extern FieldPlotWeatherRule const gFieldPlotSpecialWeatherRule3;
extern FieldPlotWeatherRule const gFieldPlotSpecialWeatherRule4;
extern u32 const gFieldPlotGrowthStageTransitions[21][21];
extern FieldPlotTypeDefinition const gFieldPlotTypeDefinitions[39];

#endif // FIELD_DATA_HH
