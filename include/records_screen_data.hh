#ifndef RECORDS_SCREEN_DATA_HH
#define RECORDS_SCREEN_DATA_HH

#include "prelude.h"

struct RecordsScreenTaskResourcePair
{
    u32 unk_00;
    u32 unk_04;
};

extern RecordsScreenTaskResourcePair const gRecordsScreenMinigameTaskResources[];
extern char const gCppRuntimeBadAlloc_RecordsScreenResources[];
extern u8 const gCodeLinkoncePackedCellSizeLookup[];
extern char const gCppRuntimeBadAlloc_PackedCellSizeLookup[];
extern char const gCppRuntimeBadAlloc_UiDigitGlyphs[];
extern u16 const gUiPreloadedDigitGlyphCodes[];
extern char const gCppRuntimeBadAlloc_RecordsScreenTrailer[];

#endif // RECORDS_SCREEN_DATA_HH
