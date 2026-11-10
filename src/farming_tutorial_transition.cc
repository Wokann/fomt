#include "farming_tutorial_transition.hh"
#include "farming_tutorial.hh"

void * operator new(unsigned long);

inline FarmingTutorialScene::FarmingTutorialScene(SceneTransitionOwner next, MaryFarmingTutorialKind value)
    : continuation(next), kind(value), game_object(nullptr),
      talk_window(), screen_blend(nullptr), music_player_0(0),
      music_player_1(1), music_player_2(2), music_player_3(3), music_player_4(4),
      wait_frames(0), waiting_entity(nullptr), unk_3A0(1), unk_3A1(0) {}

FarmingTutorialTransition::FarmingTutorialTransition(SceneTransitionOwner next, MaryFarmingTutorialKind value)
    : continuation(next), kind(value) {}

SceneOwner FarmingTutorialTransition::CreateScene()
{
    return SceneOwner(new FarmingTutorialScene(continuation, kind));
}
