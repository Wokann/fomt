#ifndef RECORDS_SCREEN_DATA_HH
#define RECORDS_SCREEN_DATA_HH

#include "prelude.h"

struct RecordsScreenTaskResourcePair
{
    u8 const *unk_00;
    u8 const *unk_04;
};

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

extern RecordsScreenTaskResourcePair const gRecordsScreenMinigameTaskResources[];
extern char const gCppRuntimeBadAlloc_RecordsScreenResources[];
extern u8 const gCodeLinkoncePackedCellSizeLookup[];
extern char const gCppRuntimeBadAlloc_PackedCellSizeLookup[];
extern char const gCppRuntimeBadAlloc_UiDigitGlyphs[];
extern u16 const gUiPreloadedDigitGlyphCodes[];
extern char const gCppRuntimeBadAlloc_RecordsScreenTrailer[];

#endif // RECORDS_SCREEN_DATA_HH
