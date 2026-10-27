#ifndef SCENE_DIALOGUE_HH
#define SCENE_DIALOGUE_HH

#include "prelude.h"

// GameScene member commands and its shared state are declared in game_scene.hh.
struct GameSceneState;

EXTERN_C

void HideSceneDialogueHeartIndicator(GameSceneState * state);
void ClearSceneDialoguePortrait(GameSceneState * state);
void ClearSceneDialogueNameplate(GameSceneState * state);

EXTERN_C_END

#endif // SCENE_DIALOGUE_HH
