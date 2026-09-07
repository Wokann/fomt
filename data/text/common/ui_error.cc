#include "ui_error.hh"

#if defined(FOMT_UI_ERROR_TEXT_FALLBACK_ERROR)

char const gText_Fallback_Error[] =
    "Error";

#elif defined(FOMT_UI_ERROR_TEXT_RUNTIME)

char const gCppRuntimeBadAlloc_UiErrorFirst[] =
    "bad_alloc";
char const gCppRuntimeBadAlloc_UiErrorSecond[] =
    "bad_alloc";

#else
#error "Include this file through src/ui_error.cc with a text partition."
#endif
