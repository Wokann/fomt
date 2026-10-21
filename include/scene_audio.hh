#ifndef SCENE_AUDIO_HH
#define SCENE_AUDIO_HH

#include "prelude.h"

struct GameScene;
struct GameSceneSongPlayerPool;

// The scene's audio members and pool layout remain declared in game_scene.hh.
// World audio uses this C-linkage accessor to the scene's shared player pool.
EXTERN_C

GameSceneSongPlayerPool & GetSceneSongPlayerPool(GameScene & scene);

EXTERN_C_END

#endif // SCENE_AUDIO_HH
