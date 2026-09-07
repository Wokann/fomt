#ifndef POSSESSIVE_LABELS_TEXT_HH
#define POSSESSIVE_LABELS_TEXT_HH

#include "prelude.h"

#define POSSESSIVE_LABEL_TEXT SECTION(".rodata.possessive_labels")

// Directly selected possessive labels for farm entities.  Each literal owns
// its normal C terminator; object spacing is linker padding rather than text.
extern char const gText_Possessive_Horse[];
extern char const gText_Possessive_Cow[];
extern char const gText_Possessive_Sheep[];
extern char const gText_Possessive_Chicken[];
extern char const gText_Possessive_Child[];
extern char const gText_Possessive_Player[];
extern char const gCppRuntimeBadAlloc_PossessiveLabelsTrailer[];

#endif // POSSESSIVE_LABELS_TEXT_HH
