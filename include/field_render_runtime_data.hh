#ifndef FIELD_RENDER_RUNTIME_DATA_HH
#define FIELD_RENDER_RUNTIME_DATA_HH

#include "field.hh"

struct PACKED FieldRenderSeasonalRecordRange
{
    u8 first_record_index;
    u8 past_last_record_index;
};

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
extern u32 const gUnk_080AE894InitialValues[5];
extern u32 const gUnk_080AE894LayoutValues[10];
extern char const gText_080B0708DefaultGlyph[];
extern u32 const gUnk_080B09B0IndexValues[7];
extern u32 const gUnk_080B0BB8FirstValues[5];
extern u32 const gUnk_080B0BB8SecondValues[5];

#endif // FIELD_RENDER_RUNTIME_DATA_HH
