#ifndef FIELD_RENDER_RESOURCE_DATA_HH
#define FIELD_RENDER_RESOURCE_DATA_HH

#include "field.hh"

struct FieldRenderParallelTables
{
    u32 values_00[3];
    u32 values_0C[3];
    u32 values_18[3];
    u32 values_24[3];
    u32 values_30[3];
};

struct FieldRenderPatchArgumentData
{
    u8 values_00[8];
    u8 values_08[4];
    u8 values_0C[16][2];
    u8 overlapping_values_2C[0x30];
    u8 values_5C[4];
};

// Native setup indexes these three-byte tables with the selected exterior
// style, then writes the result into a tile attribute's high nibble.  The
// table names retain physical offsets because the three concrete display
// groups are not fully named yet.
struct PACKED FarmHouseStyleNibbleLookupData
{
    u8 values_00[3];
    u8 values_03[3];
    u8 values_06[3];
};

extern u8 const gUnk_FieldRenderResource_158[];
extern u8 const gUnk_FieldRenderResource_159[];
extern u8 const gUnk_FieldRenderResource_177[];
extern u8 const gUnk_FieldRenderResource_178[];
extern char const gCppRuntimeBadAlloc_FieldRenderResource00[];
extern char const gCppRuntimeBadAlloc_FieldRenderResource01[];
extern FieldRenderParallelTables const gFieldRenderParallelTables;
extern FieldRenderPatchArgumentData const gFieldRenderPatchArgumentData;
extern char const gCppRuntimeBadAlloc_FieldRenderPatchArguments[];
extern FarmHouseStyleNibbleLookupData const gFarmHouseStyleNibbleLookupData;

#endif // FIELD_RENDER_RESOURCE_DATA_HH
