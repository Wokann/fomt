#ifndef INTRO_SCENE_STARTUP_HH
#define INTRO_SCENE_STARTUP_HH

#include "prelude.h"

EXTERN_C

extern u8 const gIntroSceneStartupBg0Tilemap[];
extern u8 const gIntroSceneStartupBg1Tilemap[];
extern u8 const gIntroSceneStartupBg2Tilemap[];
extern u8 const gIntroSceneStartupBg3Tilemap[];
extern u8 const gIntroSceneStartupTiles[];
extern u8 const gIntroSceneStartupPaletteBanks[];

extern u8 const * const gIntroSceneStartupBgTilemaps[4];
extern char const gCppRuntimeBadAlloc_IntroSceneStartup[];
extern char const gCppRuntimeError_IntroSceneStartup[];

EXTERN_C_END

#endif // INTRO_SCENE_STARTUP_HH
