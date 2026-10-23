#include "intro_story_scene.hh"
#include "hardware_state_accessors.hh"
#include "hardware_input.hh"
#include "game_state.hh"

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
    func_080084DC(core, &input);
    core->vtable = reinterpret_cast<void **>(const_cast<IntroStorySceneCoreVTable *>(&gIntroStorySceneCoreVTable));
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
    core->unk_6420 = 0;
    core->unk_6422 = 0;
    core->unk_6426 = 2;
    core->unk_6424 = 0;
    core->variables.player_name = func_0800E4E0(core->saved->farmer);
    return core;
}

void DestroyIntroStorySceneCore(IntroStorySceneCore * core, u32 flags)
{
    // Destroy the concrete inline context before the UI can release its references.
    core->variables.IntroStoryTextVariables::~IntroStoryTextVariables();
    delete core->ui_state;
    func_080086BC(core, flags);
}

inline IntroStoryCoreOwner::IntroStoryCoreOwner(GameStateSaveImage * saved)
    : value(InitializeIntroStorySceneCore(static_cast<IntroStorySceneCore *>(
        ::operator new(sizeof(IntroStorySceneCore))), saved)) {}

inline IntroStoryCoreOwner::~IntroStoryCoreOwner()
{
    if (value != nullptr)
        reinterpret_cast<IntroStorySceneCoreVTable const *>(value->vtable)->destroy(value, 3);
}

IntroStoryScene::IntroStoryScene(SceneTransitionOwner & next, GameStateSaveImage * saved)
    : core(saved), continuation(next) {}

IntroStoryScene::~IntroStoryScene() {}

SceneTransitionOwner IntroStoryScene::Run()
{
    RunIntroStorySceneCore(core.value);
    return continuation;
}
