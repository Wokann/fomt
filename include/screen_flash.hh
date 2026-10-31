#ifndef SCREEN_FLASH_HH
#define SCREEN_FLASH_HH

#include "prelude.h"

// One entry per update; the fixed native effect has 120 updates.
// These are blend strengths, including the eight final zero-strength frames.
extern u8 const gScreenFlashBlendStrengths[120];

#endif // SCREEN_FLASH_HH
