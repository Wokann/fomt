#ifndef SCRIPT_SCENE_HH
#define SCRIPT_SCENE_HH
#include "scene.hh"

#include "hardware_bootstrap.hh"
#include "script_engine.hh"
#include "game_scene.hh"
#pragma interface "script_scene.hh"

// The continuation is transferred to the scene; the selector is kept
// unknown until its complete command/runtime use has been recovered.
struct ScriptSceneTransition : SceneTransition {
    ScriptSceneTransition(SceneTransitionOwner & next, u32 value);
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    u32 unk_08;
};

// The constructor installs this abstract scene table before either subsystem.
struct ScriptSceneBase : AScene {
};

struct ScriptScene : ScriptSceneBase, HardwareBootstrap, AScriptEngine {
    ScriptScene(SceneTransitionOwner next, u32 value)
        : continuation(next), unk_360(value), game_object(nullptr),
          talk_window(), screen_blend(nullptr), music_player_0(0),
          music_player_1(1), music_player_2(2), music_player_3(3), music_player_4(4),
          wait_frames(0), waiting_entity(nullptr), unk_3A0(1), unk_3A1(0) {}
    virtual SceneTransitionOwner Run();
    virtual int OnCall(int id);
    void Push(i32 value);

    SceneTransitionOwner continuation;
    // Run resolves this selector through a u16 table before the Mary index.
    u32 unk_360;
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
typedef char ScriptSceneStackOffsetCheck[
    sizeof(ScriptSceneBase) + sizeof(HardwareBootstrap) + offsetof(AScriptEngine, stack) == 0x30 ? 1 : -1];
typedef char ScriptSceneStackTopOffsetCheck[
    sizeof(ScriptSceneBase) + sizeof(HardwareBootstrap) + offsetof(AScriptEngine, stack) +
        offsetof(ScriptStack, top) == 0x1C0 ? 1 : -1];
typedef char ScriptSceneSizeCheck[sizeof(ScriptScene) == 0x3A4 ? 1 : -1];
typedef char ScriptSceneContinuationOffsetCheck[offsetof(ScriptScene, continuation) == 0x35C ? 1 : -1];
typedef char ScriptSceneObjectOffsetCheck[offsetof(ScriptScene, game_object) == 0x368 ? 1 : -1];
typedef char ScriptScenePlayerOffsetCheck[offsetof(ScriptScene, music_player_0) == 0x374 ? 1 : -1];
typedef char ScriptScenePoolOffsetCheck[offsetof(ScriptScene, song_players) == 0x388 ? 1 : -1];
typedef char ScriptSceneWaitOffsetCheck[offsetof(ScriptScene, wait_frames) == 0x398 ? 1 : -1];
typedef char ScriptSceneEntityOffsetCheck[offsetof(ScriptScene, waiting_entity) == 0x39C ? 1 : -1];
typedef char ScriptSceneFlagOffsetCheck[offsetof(ScriptScene, unk_3A1) == 0x3A1 ? 1 : -1];
#endif
