#include "fixed_labels.hh"

#if defined(FOMT_FIXED_LABELS_TEXT_RUNTIME)

char const gCppRuntimeBadAlloc_FixedLabels[] =
    "bad_alloc";

#else
#error "Include this file through src/fixed_labels.cc with a text partition."
#endif
