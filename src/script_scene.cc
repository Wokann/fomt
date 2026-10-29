#include "prelude.h"
#pragma implementation "script_scene.hh"
#include "script_scene.hh"
void * operator new(unsigned long);

ScriptSceneTransition::ScriptSceneTransition(SceneTransitionOwner & next, u32 value)
    : continuation(next), unk_08(value) {}

SceneOwner ScriptSceneTransition::CreateScene()
{
    return SceneOwner(new ScriptScene(continuation, unk_08));
}
