#include "prelude.h"
#pragma implementation "staff_credits.hh"
#include "staff_credits.hh"

// This is intentionally not ordinary C++: fomt-text lowers the selected
// regional credit rows into aligned text fields and their shared-pointer row
// table before agbcp compiles this owner.
FOMT_STAFF_CREDITS();

// This runtime string physically follows the native text fields and pointer
// table in every regional ROM.
#include FOMT_TEXT_INCLUDE(staff_credits_2.cc)


void GameScene::RunStaffCredits()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_STAFF_CREDITS);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new StaffCreditsTransition(next);
    current->script_state = 0x18;
}

StaffCreditsCore::StaffCreditsCore()
    : HardwareBootstrap(HardwareInputRepeatParameters(30, 1)),
      music_player_0(0), music_player_1(1)
{
    UnkUiSelectionDimensions size(28, 2);
    Clear2DGfxBuffer(reinterpret_cast<u32 const &>(size), text_tiles, 0);
#if defined(REGION_JP)
    unk_714 = -96;
#else
    unk_714 = 256;
#endif
    unk_716 = 0;
    unk_718 = 0;
    unk_71C = 0;
    unk_720 = 0;
    unk_724 = 0;
    unk_728 = true;
    unk_72A = 0;
    lines = gStaffCreditsLines;
}

StaffCreditsScene::StaffCreditsScene(SceneTransitionOwner next)
    : core(new StaffCreditsCore), continuation(next)
{
}

StaffCreditsScene::~StaffCreditsScene()
{
}

SceneTransitionOwner StaffCreditsScene::Run()
{
    core->Run();
    return continuation;
}

SceneOwner StaffCreditsTransition::CreateScene()
{
    return SceneOwner(new StaffCreditsScene(continuation));
}
