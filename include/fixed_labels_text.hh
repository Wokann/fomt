#ifndef FIXED_LABELS_TEXT_HH
#define FIXED_LABELS_TEXT_HH

#include "prelude.h"

// These two directly addressed, non-script text fields have different fixed
// capacities in the US and JP ROM layouts.  Keep the declarations unsized so
// their common semantic names do not hide those regional layout differences.
extern char const gText_Moneybags[];
extern char const gText_UnnamedSetting[];

#endif // FIXED_LABELS_TEXT_HH
