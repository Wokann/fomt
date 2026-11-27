#ifndef FARMING_TUTORIAL_HH
#define FARMING_TUTORIAL_HH
#include "scene.hh"

#include "hardware_context.hh"
#include "script_engine.hh"
#include "game_scene.hh"
#include "game_scene_actions.hh"
#include "farming_tutorial_world.hh"
#include "farming_tutorial_script.hh"

#pragma interface "farming_tutorial.hh"

// The constructor installs this abstract scene table before either subsystem.
struct FarmingTutorialSceneBase : AScene {
};

struct FarmingTutorialScene : FarmingTutorialSceneBase, HardwareContext, AScriptEngine {
    FarmingTutorialScene(SceneTransitionOwner next, MaryFarmingTutorialKind value);
    virtual SceneTransitionOwner Run();
    // The member ABI receives the complete scene. Its native virtual entry
    // in farming_tutorial.cc includes the AScriptEngine subobject adjustment.
    // That file owns this scene's native callbacks, destructors and tables;
    // keep them imported here until their C++ emission unit is recovered.
    virtual int OnCall(int id);
    void Push(i32 value);

    SceneTransitionOwner continuation;
    // Run indexes gFarmingTutorialScriptIds before the Mary script table.
    MaryFarmingTutorialKind kind;
    // Run initializes this state before it is consumed.
    u32 script_state;
    FarmingTutorialWorldOwner game_object;
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

#endif
