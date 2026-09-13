#ifndef COMMON_UI_HH
#define COMMON_UI_HH

#include "prelude.h"

// Fixed labels at the start of the contiguous Common UI ROM block.
extern char const gText_Moneybags[];
extern u8 const gFixedLabelsPaddingBeforeUnnamedSetting[];
extern char const gText_UnnamedSetting[];
extern char const gCppRuntimeBadAlloc_FixedLabels[];

// Error fallback labels and the small native halfword table following them.
extern char const gText_Fallback_Error[];
extern char const gText_Fallback_None[];
extern u16 const gUnk_080F19AE[];
extern char const gCppRuntimeBadAlloc_UiErrorFirst[];
extern char const gCppRuntimeBadAlloc_UiErrorSecond[];

// The seven-entry menu table and its adjacent labels.
extern u32 const gMenuEntryIds[7];
extern char const gText_Menu_Diary[];
extern char const gText_Menu_Rucksack[];
extern char const gText_Menu_WorldMap[];
extern char const gText_Menu_FarmMap[];
extern char const gText_Menu_Earnings[];
extern char const gText_Menu_Memo[];
extern char const gText_Menu_Tutorial[];
extern char const * const gMenuEntryLabels[7];
extern char const gCppRuntimeBadAlloc_MenuFirst[];
extern char const gCppRuntimeBadAlloc_MenuSecond[];
extern u8 const gUnk_080F1A66[];
extern char const gCppRuntimeBadAlloc_MenuThird[];

#endif // COMMON_UI_HH
