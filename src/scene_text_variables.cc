#include "prelude.h"
#pragma implementation "scene_text_variables.hh"
#include "scene_text_variables.hh"

GameSceneTextVariables::GameSceneTextVariables(GameStateSaveImage * image)
    : save(image) {}

void GameSceneTextVariables::Set(u32 slot, char const * text)
{
    FixedStr<MAX_VALUE_BYTES> value(text);
    values[slot] = value;
}

GameSceneTextVariables::~GameSceneTextVariables() {}
