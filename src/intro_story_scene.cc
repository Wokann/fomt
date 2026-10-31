#include "intro_story_scene.hh"
#include "game_scene.hh"

#include "hardware_state_accessors.hh"
#include "hardware_input.hh"
#include "game_state.hh"
#include "intro_scene_data.hh"

void GameScene::StartFarmInheritanceFlashback()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FARM_INHERITANCE_FLASHBACK);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new IntroStoryTransition(next, current->save);
    current->script_state = 0x18;
}

void * operator new(unsigned long);
inline void * operator new(unsigned long, void * destination) { return destination; }

IntroStorySceneCoreVTable const gIntroStorySceneCoreVTable = {
    { nullptr, nullptr }, DestroyIntroStorySceneCore,
};

UiTextSubstitution IntroStoryTextVariables::Lookup(u32 code)
{
    if (code == 0xFF)
        return UiTextSubstitution(true, FixedStr<31>(player_name));
    return UiTextSubstitution(false, FixedStr<31>());
}

IntroStorySceneCore * InitializeIntroStorySceneCore(IntroStorySceneCore * core,
    GameStateSaveImage * saved)
{
    HardwareInputRepeatParameters input(30, 1);
    ConstructHardwareBootstrapWithInput(core, &input);
    InstallHardwareBootstrapNativeVTable(core, &gIntroStorySceneCoreVTable);
    core->saved = saved;
    core->unk_0C = 0;
    void * storage = operator new(sizeof(UiStateOwner));
    {
        HardwareStateOwner shared;
        HardwareResource resources;
        core->ui_state = new (storage) UiStateOwner(0, 31, 15, core->unk_0C, shared, resources);
    }
    new (&core->music_players[0]) HardwareMusicPlayerSlot(1);
    new (&core->music_players[1]) HardwareMusicPlayerSlot(0);
    new (&core->music_players[2]) HardwareMusicPlayerSlot(2);
    new (&core->variables) IntroStoryTextVariables;
    func_08050E98(*reinterpret_cast<FirstFieldUiOwner *>(core->ui_state), 0x0B);
    core->scene_step = 0;
    core->transition_phase = 0;
    core->dialogue_state = 2;
    core->story_step = 0;
    core->variables.player_name = core->saved->farmer.GetName();
    return core;
}

void DestroyIntroStorySceneCore(IntroStorySceneCore * core, u32 flags)
{
    // Destroy the concrete inline context before the UI can release its references.
    core->variables.IntroStoryTextVariables::~IntroStoryTextVariables();
    delete core->ui_state;
    DestroyHardwareBootstrap(core, flags);
}

inline IntroStoryCoreOwner::IntroStoryCoreOwner(GameStateSaveImage * saved)
    : value(InitializeIntroStorySceneCore(static_cast<IntroStorySceneCore *>(
        ::operator new(sizeof(IntroStorySceneCore))), saved)) {}

inline IntroStoryCoreOwner::~IntroStoryCoreOwner()
{
    delete value;
}

static inline SceneTransition * TakeIntroStoryContinuation(SceneTransition *& next)
{
    SceneTransition * result = next;
    next = nullptr;
    return result;
}

IntroStoryScene::IntroStoryScene(SceneTransition *& next, GameStateSaveImage * saved)
    : core(saved), continuation(TakeIntroStoryContinuation(next)) {}

IntroStoryScene::~IntroStoryScene() {}

SceneTransitionOwner IntroStoryScene::Run()
{
    RunIntroStorySceneCore(core.value);
    return continuation;
}

SceneOwner IntroStoryTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(new IntroStoryScene(next, saved));
}


void UpdateIntroStoryUi(IntroStorySceneCore * core)
{
    UiStateOwner * ui = core->ui_state;
    HardwareCoreState * state = static_cast<HardwareCoreState *>(GetHardwareCoreState(reinterpret_cast<void * const *>(core)));
    HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    HardwareInterruptList * manager = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    HardwareMusicPlayerSlot * music = core->music_players;
    switch (ui->Update(state, sprites, display, links, manager, music))
    {
    case 0:
        if (core->dialogue_state == 0)
        {
            func_08050E74(reinterpret_cast<void * const *>(core->ui_state));
            func_08050D5C(core->ui_state);
            core->dialogue_state = 3;
        }
        else if (core->dialogue_state == 6)
            core->dialogue_state = 0;
        else
            core->dialogue_state = 2;
        break;
    case 1:
    case 2:
        break;
    case 3:
        if (core->dialogue_state == 5)
        {
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state));
            core->dialogue_state = 1;
        }
        else if (core->dialogue_state == 6)
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state));
        else if (core->dialogue_state == 3)
        {
            core->dialogue_state = 5;
            switch (core->story_step)
            {
            case 0:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_MotherName);
                func_08050DA0(core->ui_state, gText_IntroScene_MotherTravelGreeting, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 1;
                break;
            case 1:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_FatherName);
                func_08050DA0(core->ui_state, gText_IntroScene_FatherFishingInvitation, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 2;
                break;
            case 2:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_MotherName);
                func_08050DA0(core->ui_state, gText_IntroScene_MotherCannotFindPlayer, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 3;
                break;
            case 3:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_FatherName);
                func_08050DA0(core->ui_state, gText_IntroScene_PlayerResponseWhat, &core->variables);
                break;
            case 4:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state, gText_IntroScene_OldManFindsPlayer, &core->variables);
                break;
            case 5:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_MotherName);
                func_08050DA0(core->ui_state, gText_IntroScene_MotherThanksOldMan, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 6;
                break;
            case 6:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_FatherName);
                func_08050DA0(core->ui_state, gText_IntroScene_FatherExplainsVacation, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 7;
                break;
            case 7:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state, gText_IntroScene_OldManOffersStay, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 9;
                break;
            case 8:
                break;
            case 9:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_FatherName);
                func_08050DA0(core->ui_state, gText_IntroScene_FatherAsksAboutStay, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 10;
                break;
            case 10:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state, gText_IntroScene_OldManWelcomesFamily, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 11;
                break;
            case 11:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_MotherName);
                func_08050DA0(core->ui_state, gText_IntroScene_MotherTellsPlayerToPlay, &core->variables);
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_UnknownName);
                func_08050DA0(core->ui_state, gText_IntroScene_UnknownCallsPlayer, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 15;
                break;
            case 15:
                func_08050DA0(core->ui_state, gText_IntroScene_UnknownFindsPlayer, &core->variables);
                break;
            case 16:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state, gText_IntroScene_GirlThinksPlayerDead, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 17;
                break;
            case 17:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state, gText_IntroScene_GirlInvitesPlayerToPlay, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 18;
                break;
            case 18:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state, gText_IntroScene_GirlAsksPlayerStory, &core->variables);
                break;
            case 19:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state, gText_IntroScene_OldManFarewell, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 20;
                break;
            case 20:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state, gText_IntroScene_OldManRequestsLetter, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 21;
                break;
            case 21:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state, gText_IntroScene_OldManGivesAddress, &core->variables);
                break;
            case 22:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state, gText_IntroScene_GirlSaysGoodbye, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 23;
                break;
            case 23:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state, gText_IntroScene_GirlAsksPlayerToReturn, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 24;
                break;
            case 24:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state, gText_IntroScene_OldManNotesFriend, &core->variables);
                break;
            case 25:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state, gText_IntroScene_OldManWaitsForLetter, &core->variables);
                break;
            }
        }
        break;
    case 4:
    case 5:
    case 6:
        break;
    }
}
