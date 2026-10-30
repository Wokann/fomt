#include "game_scene.hh"
#include "hardware_state_accessors.hh"
#include "hardware_display_state.hh"
#include "hardware_display_commands.hh"
#pragma implementation "scene_chicken_festival.hh"
#include "scene_chicken_festival.hh"
#include "harvest_sprite.hh"

void GameScene::RunChickenFestivalContest()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CHICKEN_FESTIVAL_CONTEST);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ChickenFestivalContestTransition(continuation, current->save);
    current->script_state = 0x18;
}

ChickenFestivalEntrant::ChickenFestivalEntrant()
    : name(gText_HarvestSpriteMiniGameAnimalHusbandryEmpty), year(0), affection(0)
{
}

bool ChickenFestivalMinigameCore::HasWon() const
{
    return won;
}

SceneTransitionOwner ChickenFestivalMinigameCore::Run()
{
    PrepareDisplay();
    HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(this));
    HardwareDisplayRegisterValue control(0x3F);
    display->SetBlendControl(control);
    ResetRun();
    music_players[0].Start(0x21);
    while (!finished) {
        UpdateHardwareFrame(this);
        switch (phase) {
        case 1: UpdateUnkPhase1(); break;
        case 2: UpdateUnkPhase2(); break;
        case 0: UpdateUnkPhase0(); break;
        case 3: UpdateUnkPhase3(); break;
        }
    }
    while (blend.IsQueued())
        UpdateHardwareFrame(this);
    return SceneTransitionOwner();
}

void ChickenFestivalMinigameCore::PrepareDisplay()
{
    EnableHardwareForcedBlank(this);
}

ChickenFestivalMinigameScene::ChickenFestivalMinigameScene(ChickenFestivalEntrant const & entrant)
    : core(new ChickenFestivalMinigameCore(entrant))
{
}

ChickenFestivalMinigameScene::~ChickenFestivalMinigameScene()
{
    delete core;
}

bool ChickenFestivalMinigameScene::HasWon() const
{
    return core->HasWon();
}

SceneTransitionOwner ChickenFestivalMinigameScene::Run()
{
    return core->Run();
}

SceneOwner ChickenFestivalContestTransition::CreateScene()
{
    return SceneOwner(new ChickenFestivalContestScene(continuation, save));
}
