#ifndef GAME_STATE_HH
#define GAME_STATE_HH

#include "prelude.h"

struct SramAccess;

// The save image stores these options at +0x2210. The menu keeps two
// four-byte copies at +0x198/+0x19C, one for each SRAM slot. Only the low
// four bits have verified meanings; initializing them preserves all others.
struct GameDisplayOptions {
    GameDisplayOptions();

    u32 control_scheme : 1; // 0: D-pad walks / R runs; 1: D-pad runs / R walks.
    u8 show_clock : 1;
    u8 show_portrait : 1;
    u8 show_nameplate : 1;
    u32 unk_4 : 28;
};

typedef char GameDisplayOptionsSizeCheck[sizeof(GameDisplayOptions) == 4 ? 1 : -1];

// Only the display options and total allocation size are recovered here.
// The remaining save-image fields retain explicit unknown storage.
struct GameStateSaveImage {
    u8 unk_0000[0x2210];
    GameDisplayOptions display_options;
    u8 unk_2214[0x12E0];
};

typedef char GameStateSaveImageSizeCheck[sizeof(GameStateSaveImage) == 0x34F4 ? 1 : -1];
typedef char GameStateSaveImageOptionsCheck[offsetof(GameStateSaveImage, display_options) == 0x2210 ? 1 : -1];

EXTERN_C

void InitializeGameDisplayOptions(struct GameDisplayOptions * options);

// Writes the original save image and its checksum at the selected SRAM
// offset. Zero denotes success; nonzero values carry the SRAM error flags.
u32 func_080115B0(void const * snapshot, struct SramAccess * access, u32 offset);

// Initializes and reads a save image into the supplied allocation. The
// status output is zero on success; the complete image layout is unresolved.
void * func_08011650(void * object, struct SramAccess * access, u32 offset,
    u32 * status);
// Copy-construction into existing storage and the original destructor ABI.
// Destructor flag bit zero requests deallocation after member cleanup.
void * func_080D4178(void * object, void const * source);
void func_080D4480(void * object, u32 flags);

EXTERN_C_END

inline GameDisplayOptions::GameDisplayOptions()
{
    InitializeGameDisplayOptions(this);
}

#if defined(REGION_JP)
extern char const gText_Calendar_SeasonNames[4][3];
extern char const gText_Calendar_WeekdayNames[7][3];
#else
extern char const gText_Calendar_SeasonNames[4][7];
extern char const gText_Calendar_WeekdayNames[7][5];
#endif

extern char const gText_Calendar_None[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer00[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer01[];
extern char const gCppRuntimeError_CalendarTrailer[];
extern char const gText_CalendarTrailerFallbackNone[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer02[];

// func_08010F54 scans the first 25 entries as packed season/day values.
extern u8 const gUnk_080F0566[];
extern char const gCppRuntimeBadAlloc_GameState[];

#endif // GAME_STATE_HH
