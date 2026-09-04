#ifndef SRAM_SIGNATURE_HH
#define SRAM_SIGNATURE_HH

#include "prelude.h"

// Fixed 32-byte header used to identify a valid FOMT SRAM image.
extern char const gSramImageSignature[32];

#endif // SRAM_SIGNATURE_HH
