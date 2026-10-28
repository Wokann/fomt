#include "intro_scene_startup.hh"

EXTERN_C

// BG0 through BG3 each use one 64-by-32 tilemap, stored as 64 entries
// per row. The native loader sends each row's left/right halves to
// the paired 32-by-32 screen blocks; table order is BG register order.
u8 const * const gIntroSceneStartupBgTilemaps[4] = {
    gIntroSceneStartupBg0Tilemap,
    gIntroSceneStartupBg1Tilemap,
    gIntroSceneStartupBg2Tilemap,
    gIntroSceneStartupBg3Tilemap,
};

EXTERN_C_END

// These runtime strings immediately follow the startup resource table in the
// original ROM and are selected from the regional text source at this exact
// physical point.
#include FOMT_TEXT_INCLUDE(intro_scene_startup.cc)
