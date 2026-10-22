#ifndef INTRO_STORY_SCENE_HH
#define INTRO_STORY_SCENE_HH

#include "ui_state.hh"

// Variable context embedded in the childhood story. Its local selector is
// 0xFF; do not confuse this with a complete encoded control sequence.
struct IntroStoryTextVariables : ScriptTextVariableStore
{
    char const * player_name;
    IntroStoryTextVariables() : player_name(nullptr) {}
    virtual ~IntroStoryTextVariables() {}
    virtual UiTextSubstitution Lookup(u32 code);
};

typedef char IntroStoryTextVariablesSizeCheck[sizeof(IntroStoryTextVariables) == 8 ? 1 : -1];
typedef char IntroStoryPlayerNameOffsetCheck[offsetof(IntroStoryTextVariables, player_name) == 4 ? 1 : -1];

#endif // INTRO_STORY_SCENE_HH
