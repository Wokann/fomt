#include "field_data.hh"

// These labels name still-raw field render records.  Their payload format is not decoded yet.
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

FieldPlotWeatherRule const gFieldPlotOrdinaryWeatherRules[4][2] SECTION(".rodata.field_plot_weather_ordinary") ALIGN(4) = {
    { { { 0x02, 0x02, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00 } }, { { 0x0C, 0x02, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00 } } },
    { { { 0x02, 0x01, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00 } }, { { 0x10, 0x02, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00 } } },
    { { { 0x02, 0x02, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00 } }, { { 0x0C, 0x02, 0x02, 0x00, 0x05, 0x00, 0x00, 0x00 } } },
    { { { 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } }, { { 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } } },
};

FieldPlotWeatherRule const gFieldPlotSpecialWeatherRule3 SECTION(".rodata.field_plot_weather_special_3") ALIGN(4) = { { 0x19, 0x04, 0x03, 0x02, 0x0A, 0x03, 0x02, 0x0A } };
FieldPlotWeatherRule const gFieldPlotSpecialWeatherRule4 SECTION(".rodata.field_plot_weather_special_4") ALIGN(4) = { { 0x19, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x00 } };

u32 const gFieldPlotGrowthStageTransitions[21][21] SECTION(".rodata.field_plot_growth_transitions") ALIGN(4) = {
    { 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000004, 0x00000004, 0x00000005 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000002, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000002, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000001, 0x00000001, 0x00000001, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000004, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
};

// The record payloads remain raw.  Each pointer resolves to the selected
// region's matching raw render record through one shared label.
FieldPlotTypeDefinition const gFieldPlotTypeDefinitions[39] SECTION(".rodata.field_plot_definitions") ALIGN(4) = {
    { gUnk_FieldPlotRenderRecord_000, 0x00, 0xFF, 0xFF, 0x01, 0x02, 0x00, 0x0000 },
    { gUnk_FieldPlotRenderRecord_001, 0x00, 0xFF, 0xFF, 0x01, 0x02, 0x00, 0x0001 },
    { gUnk_FieldPlotRenderRecord_002, 0x00, 0x01, 0xFF, 0x02, 0x03, 0x00, 0x0002 },
    { gUnk_FieldPlotRenderRecord_003, 0x00, 0x01, 0xFF, 0x02, 0x03, 0x00, 0x0003 },
    { gUnk_FieldPlotRenderRecord_004, 0x00, 0x01, 0xFF, 0x02, 0x03, 0x00, 0x0004 },
    { gUnk_FieldPlotRenderRecord_005, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x0005 },
    { gUnk_FieldPlotRenderRecord_006, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x0006 },
    { gUnk_FieldPlotRenderRecord_007, 0x00, 0xFF, 0xFF, 0x01, 0x02, 0x00, 0x0007 },
    { gUnk_FieldPlotRenderRecord_008, 0x00, 0x01, 0xFF, 0x02, 0x03, 0x00, 0x0008 },
    { gUnk_FieldPlotRenderRecord_009, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x0009 },
    { gUnk_FieldPlotRenderRecord_010, 0x00, 0x01, 0xFF, 0x02, 0xFF, 0x00, 0x000A },
    { gUnk_FieldPlotRenderRecord_011, 0x00, 0xFF, 0xFF, 0x01, 0xFF, 0x00, 0x000B },
    { gUnk_FieldPlotRenderRecord_012, 0x00, 0xFF, 0xFF, 0x01, 0xFF, 0x00, 0x000C },
    { gUnk_FieldPlotRenderRecord_013, 0x00, 0xFF, 0xFF, 0x01, 0xFF, 0x00, 0x000D },
    { gUnk_FieldPlotRenderRecord_014, 0x00, 0x01, 0x02, 0x03, 0xFF, 0x00, 0x000E },
    { gUnk_FieldPlotRenderRecord_015, 0x00, 0x01, 0xFF, 0x02, 0x03, 0x00, 0x0000 },
    { gUnk_FieldPlotRenderRecord_016, 0x00, 0x01, 0xFF, 0x02, 0x03, 0x00, 0x0001 },
    { gUnk_FieldPlotRenderRecord_017, 0x00, 0x01, 0x02, 0x03, 0xFF, 0x00, 0x0002 },
    { gUnk_FieldPlotRenderRecord_018, 0x00, 0x01, 0x02, 0x03, 0xFF, 0x00, 0x0003 },
    { gUnk_FieldPlotRenderRecord_019, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x0004 },
    { gUnk_FieldPlotRenderRecord_020, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_021, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0030 },
    { gUnk_FieldPlotRenderRecord_022, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0031 },
    { gUnk_FieldPlotRenderRecord_023, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0032 },
    { gUnk_FieldPlotRenderRecord_024, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0059 },
    { gUnk_FieldPlotRenderRecord_025, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_026, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x005A },
    { gUnk_FieldPlotRenderRecord_027, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_028, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_029, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_030, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_031, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_032, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_033, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_034, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_035, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_036, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_037, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
    { gUnk_FieldPlotRenderRecord_038, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00FF },
};

// Rows use the region index from the native position lookup; columns use its
// native field-plot category.
u16 const gFieldPlotPositionValues[7][4] SECTION(".rodata.field_plot_position_values") = {
    { 0x0004, 0x0006, 0x0003, 0x0005 },
    { 0x0004, 0x0006, 0x0003, 0x0005 },
    { 0x0003, 0x0005, 0x0003, 0x0004 },
    { 0x0003, 0x0005, 0x0003, 0x0004 },
    { 0x0002, 0x0004, 0x0002, 0x0004 },
    { 0x0006, 0x0006, 0x0006, 0x0006 },
    { 0x000A, 0x000A, 0x000A, 0x000A },
};

FieldPlotPositionRule const gFieldPlotPositionRules[8] SECTION(".rodata.field_plot_position_rules") = {
    { 0x00000000, 0x00000021, 0x0000002A, 0x00000048, 0x00000044, 0x00000000 },
    { 0x00000000, 0x00000035, 0x00000020, 0x0000007D, 0x00000029, 0x00000001 },
    { 0x00000000, 0x00000075, 0x0000002A, 0x00000095, 0x00000033, 0x00000002 },
    { 0x00000002, 0x00000000, 0x0000002F, 0x0000007F, 0x00000057, 0x00000003 },
    { 0x00000001, 0x00000019, 0x00000000, 0x0000003F, 0x00000049, 0x00000004 },
    { 0x0000002B, 0x00000001, 0x00000000, 0x0000001C, 0x0000000A, 0x00000005 },
    { 0x00000000, 0x0000006E, 0x00000038, 0x00000075, 0x0000003D, 0x00000006 },
    { 0x00000007, 0x00000020, 0x0000003A, 0x000000AC, 0x0000003F, 0x00000003 },
};

char const gCppRuntimeBadAlloc_FieldPlotPositionRules[] =
    "bad_alloc";

// Field initialization and rendering paths consume these fixed-size records.
// Resource payload formats remain raw until their individual assets are decoded.
extern u8 const gUnk_FieldRenderResource_000[];
extern u8 const gUnk_FieldRenderResource_001[];
extern u8 const gUnk_FieldRenderResource_002[];
extern u8 const gUnk_FieldRenderResource_003[];
extern u8 const gUnk_FieldRenderResource_004[];
extern u8 const gUnk_FieldRenderResource_005[];
extern u8 const gUnk_FieldRenderResource_006[];
extern u8 const gUnk_FieldRenderResource_007[];
extern u8 const gUnk_FieldRenderResource_008[];
extern u8 const gUnk_FieldRenderResource_009[];
extern u8 const gUnk_FieldRenderResource_010[];
extern u8 const gUnk_FieldRenderResource_011[];
extern u8 const gUnk_FieldRenderResource_012[];
extern u8 const gUnk_FieldRenderResource_013[];
extern u8 const gUnk_FieldRenderResource_014[];
extern u8 const gUnk_FieldRenderResource_015[];
extern u8 const gUnk_FieldRenderResource_016[];
extern u8 const gUnk_FieldRenderResource_017[];
extern u8 const gUnk_FieldRenderResource_018[];
extern u8 const gUnk_FieldRenderResource_019[];
extern u8 const gUnk_FieldRenderResource_020[];
extern u8 const gUnk_FieldRenderResource_021[];
extern u8 const gUnk_FieldRenderResource_022[];
extern u8 const gUnk_FieldRenderResource_023[];
extern u8 const gUnk_FieldRenderResource_024[];
extern u8 const gUnk_FieldRenderResource_025[];
extern u8 const gUnk_FieldRenderResource_026[];
extern u8 const gUnk_FieldRenderResource_027[];
extern u8 const gUnk_FieldRenderResource_028[];
extern u8 const gUnk_FieldRenderResource_029[];
extern u8 const gUnk_FieldRenderResource_030[];
extern u8 const gUnk_FieldRenderResource_031[];
extern u8 const gUnk_FieldRenderResource_032[];
extern u8 const gUnk_FieldRenderResource_033[];
extern u8 const gUnk_FieldRenderResource_034[];
extern u8 const gUnk_FieldRenderResource_035[];
extern u8 const gUnk_FieldRenderResource_036[];
extern u8 const gUnk_FieldRenderResource_037[];
extern u8 const gUnk_FieldRenderResource_038[];
extern u8 const gUnk_FieldRenderResource_039[];
extern u8 const gUnk_FieldRenderResource_040[];
extern u8 const gUnk_FieldRenderResource_041[];
extern u8 const gUnk_FieldRenderResource_042[];
extern u8 const gUnk_FieldRenderResource_043[];
extern u8 const gUnk_FieldRenderResource_044[];
extern u8 const gUnk_FieldRenderResource_045[];
extern u8 const gUnk_FieldRenderResource_046[];
extern u8 const gUnk_FieldRenderResource_047[];
extern u8 const gUnk_FieldRenderResource_048[];
extern u8 const gUnk_FieldRenderResource_049[];
extern u8 const gUnk_FieldRenderResource_050[];
extern u8 const gUnk_FieldRenderResource_051[];
extern u8 const gUnk_FieldRenderResource_052[];
extern u8 const gUnk_FieldRenderResource_053[];
extern u8 const gUnk_FieldRenderResource_054[];
extern u8 const gUnk_FieldRenderResource_055[];
extern u8 const gUnk_FieldRenderResource_056[];
extern u8 const gUnk_FieldRenderResource_057[];
extern u8 const gUnk_FieldRenderResource_058[];
extern u8 const gUnk_FieldRenderResource_059[];
extern u8 const gUnk_FieldRenderResource_060[];
extern u8 const gUnk_FieldRenderResource_061[];
extern u8 const gUnk_FieldRenderResource_062[];
extern u8 const gUnk_FieldRenderResource_063[];
extern u8 const gUnk_FieldRenderResource_064[];
extern u8 const gUnk_FieldRenderResource_065[];
extern u8 const gUnk_FieldRenderResource_066[];
extern u8 const gUnk_FieldRenderResource_067[];
extern u8 const gUnk_FieldRenderResource_068[];
extern u8 const gUnk_FieldRenderResource_069[];
extern u8 const gUnk_FieldRenderResource_070[];
extern u8 const gUnk_FieldRenderResource_071[];
extern u8 const gUnk_FieldRenderResource_072[];
extern u8 const gUnk_FieldRenderResource_073[];
extern u8 const gUnk_FieldRenderResource_074[];
extern u8 const gUnk_FieldRenderResource_075[];
extern u8 const gUnk_FieldRenderResource_076[];
extern u8 const gUnk_FieldRenderResource_077[];
extern u8 const gUnk_FieldRenderResource_078[];
extern u8 const gUnk_FieldRenderResource_079[];
extern u8 const gUnk_FieldRenderResource_080[];
extern u8 const gUnk_FieldRenderResource_081[];
extern u8 const gUnk_FieldRenderResource_082[];
extern u8 const gUnk_FieldRenderResource_083[];
extern u8 const gUnk_FieldRenderResource_084[];
extern u8 const gUnk_FieldRenderResource_085[];
extern u8 const gUnk_FieldRenderResource_086[];
extern u8 const gUnk_FieldRenderResource_087[];
extern u8 const gUnk_FieldRenderResource_088[];
extern u8 const gUnk_FieldRenderResource_089[];
extern u8 const gUnk_FieldRenderResource_090[];
extern u8 const gUnk_FieldRenderResource_091[];
extern u8 const gUnk_FieldRenderResource_092[];
extern u8 const gUnk_FieldRenderResource_093[];
extern u8 const gUnk_FieldRenderResource_094[];
extern u8 const gUnk_FieldRenderResource_095[];
extern u8 const gUnk_FieldRenderResource_096[];
extern u8 const gUnk_FieldRenderResource_097[];
extern u8 const gUnk_FieldRenderResource_098[];
extern u8 const gUnk_FieldRenderResource_099[];
extern u8 const gUnk_FieldRenderResource_100[];
extern u8 const gUnk_FieldRenderResource_101[];
extern u8 const gUnk_FieldRenderResource_102[];
extern u8 const gUnk_FieldRenderResource_103[];
extern u8 const gUnk_FieldRenderResource_104[];
extern u8 const gUnk_FieldRenderResource_105[];
extern u8 const gUnk_FieldRenderResource_106[];
extern u8 const gUnk_FieldRenderResource_107[];
extern u8 const gUnk_FieldRenderResource_108[];
extern u8 const gUnk_FieldRenderResource_109[];
extern u8 const gUnk_FieldRenderResource_110[];
extern u8 const gUnk_FieldRenderResource_111[];
extern u8 const gUnk_FieldRenderResource_112[];
extern u8 const gUnk_FieldRenderResource_113[];
extern u8 const gUnk_FieldRenderResource_114[];
extern u8 const gUnk_FieldRenderResource_115[];
extern u8 const gUnk_FieldRenderResource_116[];
extern u8 const gUnk_FieldRenderResource_117[];
extern u8 const gUnk_FieldRenderResource_118[];
extern u8 const gUnk_FieldRenderResource_119[];
extern u8 const gUnk_FieldRenderResource_120[];
extern u8 const gUnk_FieldRenderResource_121[];
extern u8 const gUnk_FieldRenderResource_122[];
extern u8 const gUnk_FieldRenderResource_123[];
extern u8 const gUnk_FieldRenderResource_124[];
extern u8 const gUnk_FieldRenderResource_125[];
extern u8 const gUnk_FieldRenderResource_126[];
extern u8 const gUnk_FieldRenderResource_127[];
extern u8 const gUnk_FieldRenderResource_128[];
extern u8 const gUnk_FieldRenderResource_129[];
extern u8 const gUnk_FieldRenderResource_130[];
extern u8 const gUnk_FieldRenderResource_131[];
extern u8 const gUnk_FieldRenderResource_132[];
extern u8 const gUnk_FieldRenderResource_133[];
extern u8 const gUnk_FieldRenderResource_134[];
extern u8 const gUnk_FieldRenderResource_135[];
extern u8 const gUnk_FieldRenderResource_136[];
extern u8 const gUnk_FieldRenderResource_137[];
extern u8 const gUnk_FieldRenderResource_138[];
extern u8 const gUnk_FieldRenderResource_139[];
extern u8 const gUnk_FieldRenderResource_140[];
extern u8 const gUnk_FieldRenderResource_141[];
extern u8 const gUnk_FieldRenderResource_142[];
extern u8 const gUnk_FieldRenderResource_143[];
extern u8 const gUnk_FieldRenderResource_144[];
extern u8 const gUnk_FieldRenderResource_145[];
extern u8 const gUnk_FieldRenderResource_146[];
extern u8 const gUnk_FieldRenderResource_147[];
extern u8 const gUnk_FieldRenderResource_148[];
extern u8 const gUnk_FieldRenderResource_149[];
extern u8 const gUnk_FieldRenderResource_150[];
extern u8 const gUnk_FieldRenderResource_151[];
extern u8 const gUnk_FieldRenderResource_152[];
extern u8 const gUnk_FieldRenderResource_153[];
extern u8 const gUnk_FieldRenderResource_154[];
extern u8 const gUnk_FieldRenderResource_155[];
extern u8 const gUnk_FieldRenderResource_156[];
extern u8 const gUnk_FieldRenderResource_157[];
extern u8 const gUnk_FieldRenderResource_158[];
extern u8 const gUnk_FieldRenderResource_159[];
extern u8 const gUnk_FieldRenderResource_160[];
extern u8 const gUnk_FieldRenderResource_161[];
extern u8 const gUnk_FieldRenderResource_162[];
extern u8 const gUnk_FieldRenderResource_163[];
extern u8 const gUnk_FieldRenderResource_164[];
extern u8 const gUnk_FieldRenderResource_165[];
extern u8 const gUnk_FieldRenderResource_166[];
extern u8 const gUnk_FieldRenderResource_167[];
extern u8 const gUnk_FieldRenderResource_168[];
extern u8 const gUnk_FieldRenderResource_169[];
extern u8 const gUnk_FieldRenderResource_170[];
extern u8 const gUnk_FieldRenderResource_171[];
extern u8 const gUnk_FieldRenderResource_172[];
extern u8 const gUnk_FieldRenderResource_173[];
extern u8 const gUnk_FieldRenderResource_174[];
extern u8 const gUnk_FieldRenderResource_175[];
extern u8 const gUnk_FieldRenderResource_176[];
extern u8 const gUnk_FieldRenderResource_177[];
extern u8 const gUnk_FieldRenderResource_178[];
extern u8 const gUnk_FieldRenderResource_179[];
extern u8 const gUnk_FieldRenderResource_180[];
extern u8 const gUnk_FieldRenderResource_181[];
extern u8 const gUnk_FieldRenderResource_182[];
extern u8 const gUnk_FieldRenderResource_183[];
extern u8 const gUnk_FieldRenderResource_184[];
extern u8 const gUnk_FieldRenderResource_185[];
extern u8 const gUnk_FieldRenderResource_186[];
extern u8 const gUnk_FieldRenderResource_187[];
extern u8 const gUnk_FieldRenderResource_188[];
extern u8 const gUnk_FieldRenderResource_189[];
extern u8 const gUnk_FieldRenderResource_190[];
extern u8 const gUnk_FieldRenderResource_191[];
extern u8 const gUnk_FieldRenderResource_192[];
extern u8 const gUnk_FieldRenderResource_193[];
extern u8 const gUnk_FieldRenderResource_194[];
extern u8 const gUnk_FieldRenderResource_195[];
extern u8 const gUnk_FieldRenderResource_196[];
extern u8 const gUnk_FieldRenderResource_197[];
extern u8 const gUnk_FieldRenderResource_198[];
extern u8 const gUnk_FieldRenderResource_199[];
extern u8 const gUnk_FieldRenderResource_200[];
extern u8 const gUnk_FieldRenderResource_201[];
extern u8 const gUnk_FieldRenderResource_202[];
extern u8 const gUnk_FieldRenderResource_203[];
extern u8 const gUnk_FieldRenderResource_204[];
extern u8 const gUnk_FieldRenderResource_205[];
extern u8 const gUnk_FieldRenderResource_206[];
extern u8 const gUnk_FieldRenderResource_207[];
extern u8 const gUnk_FieldRenderResource_208[];
extern u8 const gUnk_FieldRenderResource_209[];
extern u8 const gUnk_FieldRenderResource_210[];
extern u8 const gUnk_FieldRenderResource_211[];
extern u8 const gUnk_FieldRenderResource_212[];
extern u8 const gUnk_FieldRenderResource_213[];
extern u8 const gUnk_FieldRenderResource_214[];
extern u8 const gUnk_FieldRenderResource_215[];
extern u8 const gUnk_FieldRenderResource_216[];
extern u8 const gUnk_FieldRenderResource_217[];
extern u8 const gUnk_FieldRenderResource_218[];
extern u8 const gUnk_FieldRenderResource_219[];
extern u8 const gUnk_FieldRenderResource_220[];
extern u8 const gUnk_FieldRenderResource_221[];
extern u8 const gUnk_FieldRenderResource_222[];
extern u8 const gUnk_FieldRenderResource_223[];
extern u8 const gUnk_FieldRenderResource_224[];
extern u8 const gUnk_FieldRenderResource_225[];
extern u8 const gUnk_FieldRenderResource_226[];
extern u8 const gUnk_FieldRenderResource_227[];

FieldRenderRectDescriptor const gFieldRenderRectDescriptors[FIELD_RENDER_RECT_DESCRIPTOR_COUNT] SECTION(".rodata.field_render_rect_descriptors") = {
    /* 0x00 */ {
        0x08, 0x0D,
        { gUnk_FieldRenderResource_000, gUnk_FieldRenderResource_001, nullptr },
        gUnk_FieldRenderResource_002,
        gUnk_FieldRenderResource_003,
    },
    /* 0x01 */ {
        0x08, 0x0C,
        { gUnk_FieldRenderResource_004, gUnk_FieldRenderResource_005, nullptr },
        gUnk_FieldRenderResource_002,
        gUnk_FieldRenderResource_003,
    },
    /* 0x02 */ {
        0x10, 0x0D,
        { gUnk_FieldRenderResource_006, gUnk_FieldRenderResource_007, nullptr },
        gUnk_FieldRenderResource_008,
        gUnk_FieldRenderResource_009,
    },
    /* 0x03 */ {
        0x10, 0x0C,
        { gUnk_FieldRenderResource_010, gUnk_FieldRenderResource_011, nullptr },
        gUnk_FieldRenderResource_008,
        gUnk_FieldRenderResource_009,
    },
    /* 0x04 */ {
        0x18, 0x0D,
        { gUnk_FieldRenderResource_012, gUnk_FieldRenderResource_013, nullptr },
        gUnk_FieldRenderResource_014,
        gUnk_FieldRenderResource_015,
    },
    /* 0x05 */ {
        0x18, 0x0D,
        { gUnk_FieldRenderResource_016, gUnk_FieldRenderResource_017, nullptr },
        gUnk_FieldRenderResource_014,
        gUnk_FieldRenderResource_015,
    },
    /* 0x06 */ {
        0x0C, 0x0E,
        { gUnk_FieldRenderResource_018, gUnk_FieldRenderResource_019, nullptr },
        gUnk_FieldRenderResource_020,
        gUnk_FieldRenderResource_021,
    },
    /* 0x07 */ {
        0x0C, 0x0D,
        { gUnk_FieldRenderResource_022, gUnk_FieldRenderResource_023, nullptr },
        gUnk_FieldRenderResource_020,
        gUnk_FieldRenderResource_021,
    },
    /* 0x08 */ {
        0x16, 0x0E,
        { gUnk_FieldRenderResource_024, gUnk_FieldRenderResource_025, nullptr },
        gUnk_FieldRenderResource_026,
        gUnk_FieldRenderResource_027,
    },
    /* 0x09 */ {
        0x16, 0x0D,
        { gUnk_FieldRenderResource_028, gUnk_FieldRenderResource_029, nullptr },
        gUnk_FieldRenderResource_026,
        gUnk_FieldRenderResource_027,
    },
    /* 0x0A */ {
        0x09, 0x0E,
        { gUnk_FieldRenderResource_030, gUnk_FieldRenderResource_031, gUnk_FieldRenderResource_032 },
        gUnk_FieldRenderResource_033,
        gUnk_FieldRenderResource_034,
    },
    /* 0x0B */ {
        0x09, 0x0D,
        { gUnk_FieldRenderResource_035, gUnk_FieldRenderResource_036, gUnk_FieldRenderResource_037 },
        gUnk_FieldRenderResource_033,
        gUnk_FieldRenderResource_034,
    },
    /* 0x0C */ {
        0x11, 0x0E,
        { gUnk_FieldRenderResource_038, gUnk_FieldRenderResource_039, gUnk_FieldRenderResource_040 },
        gUnk_FieldRenderResource_041,
        gUnk_FieldRenderResource_042,
    },
    /* 0x0D */ {
        0x11, 0x0D,
        { gUnk_FieldRenderResource_043, gUnk_FieldRenderResource_044, gUnk_FieldRenderResource_045 },
        gUnk_FieldRenderResource_041,
        gUnk_FieldRenderResource_042,
    },
    /* 0x0E */ {
        0x04, 0x06,
        { nullptr, gUnk_FieldRenderResource_046, gUnk_FieldRenderResource_047 },
        gUnk_FieldRenderResource_048,
        gUnk_FieldRenderResource_049,
    },
    /* 0x0F */ {
        0x04, 0x06,
        { nullptr, gUnk_FieldRenderResource_050, gUnk_FieldRenderResource_051 },
        gUnk_FieldRenderResource_052,
        gUnk_FieldRenderResource_053,
    },
    /* 0x10 */ {
        0x04, 0x06,
        { gUnk_FieldRenderResource_054, gUnk_FieldRenderResource_055, nullptr },
        gUnk_FieldRenderResource_056,
        gUnk_FieldRenderResource_057,
    },
    /* 0x11 */ {
        0x04, 0x06,
        { gUnk_FieldRenderResource_058, gUnk_FieldRenderResource_059, nullptr },
        gUnk_FieldRenderResource_060,
        gUnk_FieldRenderResource_061,
    },
    /* 0x12 */ {
        0x04, 0x07,
        { gUnk_FieldRenderResource_062, gUnk_FieldRenderResource_063, nullptr },
        gUnk_FieldRenderResource_064,
        gUnk_FieldRenderResource_065,
    },
    /* 0x13 */ {
        0x04, 0x07,
        { gUnk_FieldRenderResource_066, gUnk_FieldRenderResource_067, nullptr },
        gUnk_FieldRenderResource_068,
        gUnk_FieldRenderResource_069,
    },
    /* 0x14 */ {
        0x04, 0x03,
        { nullptr, gUnk_FieldRenderResource_070, gUnk_FieldRenderResource_071 },
        gUnk_FieldRenderResource_072,
        gUnk_FieldRenderResource_073,
    },
    /* 0x15 */ {
        0x04, 0x03,
        { nullptr, gUnk_FieldRenderResource_074, gUnk_FieldRenderResource_075 },
        gUnk_FieldRenderResource_076,
        gUnk_FieldRenderResource_077,
    },
    /* 0x16 */ {
        0x04, 0x03,
        { nullptr, gUnk_FieldRenderResource_078, gUnk_FieldRenderResource_079 },
        gUnk_FieldRenderResource_080,
        gUnk_FieldRenderResource_081,
    },
    /* 0x17 */ {
        0x0A, 0x0F,
        { gUnk_FieldRenderResource_082, gUnk_FieldRenderResource_083, nullptr },
        gUnk_FieldRenderResource_084,
        gUnk_FieldRenderResource_085,
    },
    /* 0x18 */ {
        0x06, 0x08,
        { nullptr, gUnk_FieldRenderResource_086, nullptr },
        gUnk_FieldRenderResource_087,
        gUnk_FieldRenderResource_088,
    },
    /* 0x19 */ {
        0x06, 0x08,
        { nullptr, gUnk_FieldRenderResource_089, nullptr },
        gUnk_FieldRenderResource_090,
        gUnk_FieldRenderResource_091,
    },
    /* 0x1A */ {
        0x0C, 0x0A,
        { gUnk_FieldRenderResource_092, nullptr, nullptr },
        nullptr,
        nullptr,
    },
    /* 0x1B */ {
        0x02, 0x03,
        { nullptr, gUnk_FieldRenderResource_093, nullptr },
        gUnk_FieldRenderResource_094,
        gUnk_FieldRenderResource_095,
    },
    /* 0x1C */ {
        0x03, 0x04,
        { gUnk_FieldRenderResource_096, nullptr, nullptr },
        gUnk_FieldRenderResource_097,
        gUnk_FieldRenderResource_098,
    },
    /* 0x1D */ {
        0x03, 0x06,
        { nullptr, gUnk_FieldRenderResource_099, nullptr },
        gUnk_FieldRenderResource_100,
        gUnk_FieldRenderResource_101,
    },
    /* 0x1E */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_102, nullptr },
        nullptr,
        nullptr,
    },
    /* 0x1F */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_103, nullptr },
        gUnk_FieldRenderResource_104,
        gUnk_FieldRenderResource_105,
    },
    /* 0x20 */ {
        0x03, 0x05,
        { gUnk_FieldRenderResource_106, gUnk_FieldRenderResource_107, nullptr },
        gUnk_FieldRenderResource_108,
        gUnk_FieldRenderResource_109,
    },
    /* 0x21 */ {
        0x03, 0x05,
        { gUnk_FieldRenderResource_110, gUnk_FieldRenderResource_111, nullptr },
        gUnk_FieldRenderResource_112,
        gUnk_FieldRenderResource_113,
    },
    /* 0x22 */ {
        0x03, 0x05,
        { gUnk_FieldRenderResource_114, gUnk_FieldRenderResource_115, nullptr },
        gUnk_FieldRenderResource_116,
        gUnk_FieldRenderResource_117,
    },
    /* 0x23 */ {
        0x02, 0x02,
        { nullptr, gUnk_FieldRenderResource_118, nullptr },
        nullptr,
        nullptr,
    },
    /* 0x24 */ {
        0x02, 0x02,
        { nullptr, gUnk_FieldRenderResource_119, nullptr },
        nullptr,
        nullptr,
    },
    /* 0x25 */ {
        0x2A, 0x28,
        { nullptr, nullptr, nullptr },
        gUnk_FieldRenderResource_120,
        gUnk_FieldRenderResource_121,
    },
    /* 0x26 */ {
        0x0E, 0x10,
        { gUnk_FieldRenderResource_122, gUnk_FieldRenderResource_123, nullptr },
        gUnk_FieldRenderResource_124,
        gUnk_FieldRenderResource_125,
    },
    /* 0x27 */ {
        0x0E, 0x10,
        { gUnk_FieldRenderResource_126, gUnk_FieldRenderResource_127, nullptr },
        gUnk_FieldRenderResource_124,
        gUnk_FieldRenderResource_125,
    },
    /* 0x28 */ {
        0x11, 0x14,
        { gUnk_FieldRenderResource_128, gUnk_FieldRenderResource_129, nullptr },
        gUnk_FieldRenderResource_130,
        gUnk_FieldRenderResource_131,
    },
    /* 0x29 */ {
        0x11, 0x14,
        { gUnk_FieldRenderResource_132, gUnk_FieldRenderResource_133, nullptr },
        gUnk_FieldRenderResource_130,
        gUnk_FieldRenderResource_131,
    },
    /* 0x2A */ {
        0x16, 0x24,
        { gUnk_FieldRenderResource_134, gUnk_FieldRenderResource_135, gUnk_FieldRenderResource_136 },
        gUnk_FieldRenderResource_137,
        gUnk_FieldRenderResource_138,
    },
    /* 0x2B */ {
        0x06, 0x04,
        { gUnk_FieldRenderResource_139, gUnk_FieldRenderResource_140, nullptr },
        gUnk_FieldRenderResource_141,
        gUnk_FieldRenderResource_142,
    },
    /* 0x2C */ {
        0x11, 0x0F,
        { gUnk_FieldRenderResource_143, gUnk_FieldRenderResource_144, gUnk_FieldRenderResource_145 },
        gUnk_FieldRenderResource_146,
        gUnk_FieldRenderResource_147,
    },
    /* 0x2D */ {
        0x11, 0x0F,
        { gUnk_FieldRenderResource_148, gUnk_FieldRenderResource_149, gUnk_FieldRenderResource_150 },
        gUnk_FieldRenderResource_146,
        gUnk_FieldRenderResource_147,
    },
    /* 0x2E */ {
        0x02, 0x03,
        { nullptr, gUnk_FieldRenderResource_151, nullptr },
        gUnk_FieldRenderResource_152,
        gUnk_FieldRenderResource_153,
    },
    /* 0x2F */ {
        0x02, 0x03,
        { nullptr, gUnk_FieldRenderResource_154, nullptr },
        gUnk_FieldRenderResource_155,
        gUnk_FieldRenderResource_156,
    },
    /* 0x30 */ {
        0x02, 0x03,
        { nullptr, gUnk_FieldRenderResource_157, nullptr },
        gUnk_FieldRenderResource_158,
        gUnk_FieldRenderResource_159,
    },
    /* 0x31 */ {
        0x09, 0x05,
        { nullptr, gUnk_FieldRenderResource_160, nullptr },
        gUnk_FieldRenderResource_161,
        gUnk_FieldRenderResource_162,
    },
    /* 0x32 */ {
        0x09, 0x05,
        { nullptr, gUnk_FieldRenderResource_163, nullptr },
        gUnk_FieldRenderResource_164,
        gUnk_FieldRenderResource_165,
    },
    /* 0x33 */ {
        0x09, 0x05,
        { nullptr, gUnk_FieldRenderResource_166, nullptr },
        gUnk_FieldRenderResource_167,
        gUnk_FieldRenderResource_168,
    },
    /* 0x34 */ {
        0x03, 0x04,
        { gUnk_FieldRenderResource_169, gUnk_FieldRenderResource_170, nullptr },
        gUnk_FieldRenderResource_171,
        gUnk_FieldRenderResource_172,
    },
    /* 0x35 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_173, nullptr },
        gUnk_FieldRenderResource_174,
        gUnk_FieldRenderResource_175,
    },
    /* 0x36 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_176, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x37 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_179, nullptr },
        gUnk_FieldRenderResource_180,
        gUnk_FieldRenderResource_181,
    },
    /* 0x38 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_182, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x39 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_183, nullptr },
        gUnk_FieldRenderResource_184,
        gUnk_FieldRenderResource_185,
    },
    /* 0x3A */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_186, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x3B */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_187, nullptr },
        gUnk_FieldRenderResource_188,
        gUnk_FieldRenderResource_189,
    },
    /* 0x3C */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_190, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x3D */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_191, nullptr },
        gUnk_FieldRenderResource_192,
        gUnk_FieldRenderResource_193,
    },
    /* 0x3E */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_194, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x3F */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_195, nullptr },
        gUnk_FieldRenderResource_196,
        gUnk_FieldRenderResource_197,
    },
    /* 0x40 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_198, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x41 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_199, nullptr },
        gUnk_FieldRenderResource_200,
        gUnk_FieldRenderResource_201,
    },
    /* 0x42 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_202, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x43 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_203, nullptr },
        gUnk_FieldRenderResource_204,
        gUnk_FieldRenderResource_205,
    },
    /* 0x44 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_206, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x45 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_207, nullptr },
        gUnk_FieldRenderResource_208,
        gUnk_FieldRenderResource_209,
    },
    /* 0x46 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_210, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x47 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_211, nullptr },
        gUnk_FieldRenderResource_212,
        gUnk_FieldRenderResource_213,
    },
    /* 0x48 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_214, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x49 */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_215, nullptr },
        gUnk_FieldRenderResource_216,
        gUnk_FieldRenderResource_217,
    },
    /* 0x4A */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_218, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x4B */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_219, nullptr },
        gUnk_FieldRenderResource_220,
        gUnk_FieldRenderResource_221,
    },
    /* 0x4C */ {
        0x03, 0x05,
        { nullptr, gUnk_FieldRenderResource_222, nullptr },
        gUnk_FieldRenderResource_177,
        gUnk_FieldRenderResource_178,
    },
    /* 0x4D */ {
        0x04, 0x04,
        { nullptr, gUnk_FieldRenderResource_223, nullptr },
        nullptr,
        nullptr,
    },
    /* 0x4E */ {
        0x04, 0x04,
        { nullptr, gUnk_FieldRenderResource_224, nullptr },
        nullptr,
        nullptr,
    },
    /* 0x4F */ {
        0x04, 0x04,
        { nullptr, gUnk_FieldRenderResource_225, nullptr },
        nullptr,
        nullptr,
    },
    /* 0x50 */ {
        0x04, 0x04,
        { nullptr, gUnk_FieldRenderResource_226, nullptr },
        nullptr,
        nullptr,
    },
    /* 0x51 */ {
        0x02, 0x02,
        { nullptr, gUnk_FieldRenderResource_227, nullptr },
        nullptr,
        nullptr,
    },
};
