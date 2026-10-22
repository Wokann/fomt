#include "intro_story_scene.hh"

UiTextSubstitution IntroStoryTextVariables::Lookup(u32 code)
{
    if (code == 0xFF)
        return UiTextSubstitution(true, FixedStr<31>(player_name));
    return UiTextSubstitution(false, FixedStr<31>());
}
