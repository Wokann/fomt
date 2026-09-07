#include "entity_ui.hh"

#if defined(FOMT_ENTITY_UI_TEXT_NOT_AVAILABLE)

char const gText_NotAvailable[8] =
    "N/A ";

#else
#error "Include this file through src/entity_ui.cc with a text partition."
#endif
