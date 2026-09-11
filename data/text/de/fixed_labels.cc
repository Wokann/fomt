#include "fixed_labels.hh"

#if defined(FOMT_FIXED_LABELS_TEXT_MONEYBAGS)

char const gText_Moneybags[] =
    "Moneybags ";

#elif defined(FOMT_FIXED_LABELS_TEXT_UNNAMED_SETTING)

char const gText_UnnamedSetting[] =
    "Unnamed setting";

#else
#error "Include this file through src/fixed_labels.cc with a text partition."
#endif
