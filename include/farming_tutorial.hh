#ifndef FARMING_TUTORIAL_HH
#define FARMING_TUTORIAL_HH
#include "scene.hh"

#include "hardware_bootstrap.hh"
#include "script_engine.hh"
#include "game_scene.hh"
#pragma interface "farming_tutorial.hh"

// Crops and animal-care tutorials run in this dedicated script host.
// Both entry paths transfer their continuation and one complete kind word.
struct FarmingTutorialTransition : SceneTransition {
    FarmingTutorialTransition(SceneTransitionOwner next, MaryFarmingTutorialKind value);
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    MaryFarmingTutorialKind kind;
};

// The constructor installs this abstract scene table before either subsystem.
struct FarmingTutorialSceneBase : AScene {
};

struct FarmingTutorialScene : FarmingTutorialSceneBase, HardwareBootstrap, AScriptEngine {
    FarmingTutorialScene(SceneTransitionOwner next, MaryFarmingTutorialKind value)
        : continuation(next), kind(value), game_object(nullptr),
          talk_window(), screen_blend(nullptr), music_player_0(0),
          music_player_1(1), music_player_2(2), music_player_3(3), music_player_4(4),
          wait_frames(0), waiting_entity(nullptr), unk_3A0(1), unk_3A1(0) {}
    virtual SceneTransitionOwner Run();
    virtual int OnCall(int id);
    void Push(i32 value);

    SceneTransitionOwner continuation;
    // Run indexes gFarmingTutorialScriptIds before the Mary script table.
    MaryFarmingTutorialKind kind;
    // Run initializes this state before it is consumed.
    u32 script_state;
    GameSceneWorldOwner game_object;
    GameSceneTalkWindowOwner talk_window;
    GameSceneBlendOwner screen_blend;
    HardwareMusicPlayerSlot music_player_0;
    HardwareMusicPlayerSlot music_player_1;
    HardwareMusicPlayerSlot music_player_2;
    HardwareMusicPlayerSlot music_player_3;
    HardwareMusicPlayerSlot music_player_4;
    GameSceneSongPlayerPool song_players;
    u16 wait_frames;
    AActorEntity * waiting_entity;
    u8 unk_3A0;
    u8 unk_3A1;
};
typedef char FarmingTutorialSceneStackOffsetCheck[
    sizeof(FarmingTutorialSceneBase) + sizeof(HardwareBootstrap) + offsetof(AScriptEngine, stack) == 0x30 ? 1 : -1];
typedef char FarmingTutorialSceneStackTopOffsetCheck[
    sizeof(FarmingTutorialSceneBase) + sizeof(HardwareBootstrap) + offsetof(AScriptEngine, stack) +
        offsetof(ScriptStack, top) == 0x1C0 ? 1 : -1];
typedef char FarmingTutorialSceneSizeCheck[sizeof(FarmingTutorialScene) == 0x3A4 ? 1 : -1];
typedef char FarmingTutorialSceneContinuationOffsetCheck[offsetof(FarmingTutorialScene, continuation) == 0x35C ? 1 : -1];
typedef char FarmingTutorialSceneObjectOffsetCheck[offsetof(FarmingTutorialScene, game_object) == 0x368 ? 1 : -1];
typedef char FarmingTutorialScenePlayerOffsetCheck[offsetof(FarmingTutorialScene, music_player_0) == 0x374 ? 1 : -1];
typedef char FarmingTutorialScenePoolOffsetCheck[offsetof(FarmingTutorialScene, song_players) == 0x388 ? 1 : -1];
typedef char FarmingTutorialSceneWaitOffsetCheck[offsetof(FarmingTutorialScene, wait_frames) == 0x398 ? 1 : -1];
typedef char FarmingTutorialSceneEntityOffsetCheck[offsetof(FarmingTutorialScene, waiting_entity) == 0x39C ? 1 : -1];
typedef char FarmingTutorialSceneFlagOffsetCheck[offsetof(FarmingTutorialScene, unk_3A1) == 0x3A1 ? 1 : -1];
#endif
