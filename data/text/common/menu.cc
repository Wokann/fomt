#include "menu_data.hh"

#if defined(FOMT_MENU_TEXT_RUNTIME_FIRST)

char const gCppRuntimeBadAlloc_MenuFirst[] =
    "bad_alloc";
char const gCppRuntimeBadAlloc_MenuSecond[] =
    "bad_alloc";

#elif defined(FOMT_MENU_TEXT_RUNTIME_THIRD)

char const gCppRuntimeBadAlloc_MenuThird[] =
    "bad_alloc";

#else
#error "Include this file through src/menu_data.cc with a text partition."
#endif
