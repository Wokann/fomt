#ifndef LIBRARY_TEXT_HH
#define LIBRARY_TEXT_HH

#include "prelude.h"

#define LIBRARY_INFO_TEXT SECTION(".rodata.library_info")
#define LIBRARY_MENU_TEXT SECTION(".rodata.library_menu")

extern char const gText_Library_OpeningHours[];
extern char const gText_Library_Menu[];
extern char const gCppRuntimeBadAlloc_LibraryMenu[];

#endif // LIBRARY_TEXT_HH
