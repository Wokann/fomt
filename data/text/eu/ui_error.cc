#include "ui_error.hh"

#if defined(FOMT_UI_ERROR_TEXT_FALLBACK_NONE)

char const gText_Fallback_None[] =
    "N/A ";

#else
#error "Include this file through src/ui_error.cc with a text partition."
#endif
