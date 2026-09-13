#ifndef RECORDS_SCREEN_DATA_HH
#define RECORDS_SCREEN_DATA_HH

#include "prelude.h"

struct RecordsScreenTaskResourcePair
{
    u8 const *unk_00;
    u8 const *unk_04;
};

#if defined(REGION_JP)
extern u8 const gUnk_084D7EB8[];
extern u8 const gUnk_084D7F38[];
extern u8 const gUnk_084D7F58[];
extern u8 const gUnk_084D7FD8[];
extern u8 const gUnk_084D7FF8[];
extern u8 const gUnk_084D8078[];
extern u8 const gUnk_084D8098[];
extern u8 const gUnk_084D8118[];
extern u8 const gUnk_084D8138[];
extern u8 const gUnk_084D81B8[];
extern u8 const gUnk_084D81D8[];
extern u8 const gUnk_084D8258[];
extern u8 const gUnk_084D8278[];
extern u8 const gUnk_084D82F8[];
#else
extern u8 const gUnk_08751F0C[];
extern u8 const gUnk_08751F8C[];
extern u8 const gUnk_08751FAC[];
extern u8 const gUnk_0875202C[];
extern u8 const gUnk_0875204C[];
extern u8 const gUnk_087520CC[];
extern u8 const gUnk_087520EC[];
extern u8 const gUnk_0875216C[];
extern u8 const gUnk_0875218C[];
extern u8 const gUnk_0875220C[];
extern u8 const gUnk_0875222C[];
extern u8 const gUnk_087522AC[];
extern u8 const gUnk_087522CC[];
extern u8 const gUnk_0875234C[];
#endif

extern RecordsScreenTaskResourcePair const gRecordsScreenMinigameTaskResources[];
extern char const gCppRuntimeBadAlloc_RecordsScreenResources[];
extern u8 const gCodeLinkoncePackedCellSizeLookup[];
extern char const gCppRuntimeBadAlloc_PackedCellSizeLookup[];
extern char const gCppRuntimeBadAlloc_UiDigitGlyphs[];
extern u16 const gUiPreloadedDigitGlyphCodes[];
extern char const gCppRuntimeBadAlloc_RecordsScreenTrailer[];

extern char const gText_Records_NumberShipped[];
extern char const gText_Records_ShippedCountSuffix[];
extern char const gText_Records_Fishing[];
extern char const gText_Records_Name[];
extern char const gText_Records_MaximumSize[];
extern char const gText_Records_Results[];
extern char const gText_Records_FishUnit[];
extern char const gText_Records_MeterUnit[];
extern char const gText_Records_CentimeterUnit[];
extern char const gText_Records_Separator[];
extern char const gText_Records_Other[];
extern char const gText_Records_MiniGameRecords[];
extern char const gText_Records_Harvest[];
extern char const gText_Records_AnimalHusbandry[];
extern char const gText_Records_Watering[];
extern char const gText_Records_Frisbee[];
extern char const gText_Records_SecondsUnit[];
extern char const gText_Records_IncomeExpenses[];
extern char const gText_Records_HighestAmount[];
extern char const gText_Records_Earned[];
extern char const gText_Records_Used[];
extern char const gText_Records_GoldUnit[];
extern char const gText_Records_LongestLivingAnimal[];
extern char const gText_Records_Chicken[];
extern char const gText_Records_Cow[];
extern char const gText_Records_Sheep[];
extern char const gText_Records_YearsUnit[];
extern char const gText_Records_MonthsUnit[];
extern char const gText_Records_DaysUnit[];
extern char const gText_Records_MineDepth[];
extern char const gText_Records_BelowGround[];
extern char const gText_Records_MolesWhacked[];

#if defined(REGION_JP)
extern char const gText_Records_FloorUnit[];
#else
extern char const gText_Records_MineDepthPadding[];
#endif

#endif // RECORDS_SCREEN_DATA_HH
