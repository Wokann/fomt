#ifndef WORLD_AUDIO_HH
#define WORLD_AUDIO_HH

#include "prelude.h"

struct GameSceneWorldPrefix;
struct GameSceneSongPlayerPool;

EXTERN_C
u32 SelectWorldBackgroundAudio(GameSceneWorldPrefix & world);
GameSceneSongPlayerPool & GetWorldSongPlayerPool(GameSceneWorldPrefix & world);
void UpdateWorldBackgroundAudio(GameSceneWorldPrefix & world);
EXTERN_C_END

#endif // WORLD_AUDIO_HH
