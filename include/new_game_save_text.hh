#ifndef NEW_GAME_SAVE_TEXT_HH
#define NEW_GAME_SAVE_TEXT_HH

#include "prelude.h"

// Save/load result messages and confirmation fields used by the new-game flow.
extern char const gText_NewGameSave_SaveFailed[];
extern char const gText_NewGameSave_LoadFailed[];
extern char const gText_NewGameSave_LoadPrompt[];

#if defined(REGION_JP)
extern char const gText_NewGameSave_Affirmative[];
#else
extern char const gText_NewGameSave_OverwritePrompt[];
#endif

#endif // NEW_GAME_SAVE_TEXT_HH
