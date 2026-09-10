#ifndef HELP_MENU_HH
#define HELP_MENU_HH

#include "prelude.h"

extern char const gText_LoadError[];
extern char const gCppRuntimeBadAlloc_LoadError[];
extern char const gText_LoadErrorFallbackNone[];
extern char const gCppRuntimeError_LoadError[];

// These are passed as four direct pointers to the help-menu constructor.
extern char const gText_HelpMenu_Crops[];
extern char const gText_HelpMenu_Animals[];
extern char const gText_HelpMenu_UsefulTips[];
extern char const gText_HelpMenu_Exit[];

extern u8 const gUnk_HelpMenuByteTable[];

#endif // HELP_MENU_HH
