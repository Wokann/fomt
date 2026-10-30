#include "game_scene.hh"
#pragma implementation "frisbee_scoreboard.hh"
#include "frisbee_scoreboard.hh"

void GameScene::ShowFrisbeeScoreboard()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FRISBEE_SCOREBOARD);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new FrisbeeScoreboardTransition(continuation, current->save);
    current->script_state = 0x18;
}

FrisbeeScoreboardCore::FrisbeeScoreboardCore(GameStateSaveImage * image)
    : HardwareBootstrap(HardwareInputRepeatParameters(30, 1)),
      save(image), music_player(2), unk_archive_010(gUnk_08527094),
      sprite_040(&unk_archive_010, 0), sprite_074(&unk_archive_010, 1),
      sprite_tiles(4), scroll_y(0)
{
}

FrisbeeScoreboardScene::FrisbeeScoreboardScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(new FrisbeeScoreboardCore(image)), continuation(next)
{
}

FrisbeeScoreboardScene::~FrisbeeScoreboardScene()
{
}

SceneTransitionOwner FrisbeeScoreboardScene::Run()
{
    core->Run();
    return continuation;
}

SceneOwner FrisbeeScoreboardTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__22FrisbeeScoreboardSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(FrisbeeScoreboardScene)), &next, save));
}

#include FOMT_TEXT_INCLUDE(frisbee_scoreboard.cc)
