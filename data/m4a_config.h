#include "prelude.h"
#include "m4a.h"

// defined in lds
extern char _M4aMaxLines[];

#define MAX_LINES ((u32) _M4aMaxLines)

#define SOUND_MODE \
    (10 << SOUND_MODE_MAXCHN_SHIFT) | \
    (11 << SOUND_MODE_MASVOL_SHIFT) | \
    SOUND_MODE_FREQ_13379 | SOUND_MODE_DA_BIT_8
