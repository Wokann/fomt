#include "prelude.h"
#pragma implementation "script_scene.hh"
#include "script_scene.hh"

ScriptSceneTransition::ScriptSceneTransition(SceneTransitionOwner & next, u32 value)
    : continuation(next), unk_08(value) {}
