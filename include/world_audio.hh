#ifndef WORLD_AUDIO_HH
#define WORLD_AUDIO_HH

#include "prelude.h"

struct GameSceneWorld;

EXTERN_C
u32 SelectWorldBackgroundAudio(GameSceneWorld & world);
void UpdateWorldBackgroundAudio(GameSceneWorld & world);
EXTERN_C_END

#endif // WORLD_AUDIO_HH
