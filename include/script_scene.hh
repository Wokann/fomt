#ifndef SCRIPT_SCENE_HH
#define SCRIPT_SCENE_HH

#include "scene.hh"

#pragma interface "script_scene.hh"

// This transition transfers the continuation to a scene with its own native
// script interpreter. Its remaining parameter has not been given a meaning.
struct ScriptSceneTransition : SceneTransition {
    ScriptSceneTransition(SceneTransitionOwner & next, u32 value);
    virtual SceneOwner CreateScene();

    // The implicit destructor releases this owner and forwards native base flags.
    SceneTransitionOwner continuation;
    u32 unk_08;
};

typedef char ScriptSceneTransitionSizeCheck[sizeof(ScriptSceneTransition) == 12 ? 1 : -1];
typedef char ScriptSceneTransitionContinuationCheck[offsetof(ScriptSceneTransition, continuation) == 4 ? 1 : -1];
typedef char ScriptSceneTransitionUnknownCheck[offsetof(ScriptSceneTransition, unk_08) == 8 ? 1 : -1];

#endif // SCRIPT_SCENE_HH
