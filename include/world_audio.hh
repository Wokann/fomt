#ifndef WORLD_AUDIO_HH
#define WORLD_AUDIO_HH

#include "prelude.h"

struct GameSceneWorldPrefix;

EXTERN_C
u32 SelectWorldBackgroundAudio(GameSceneWorldPrefix & world);
void UpdateWorldBackgroundAudio(GameSceneWorldPrefix & world);
EXTERN_C_END

#endif // WORLD_AUDIO_HH
