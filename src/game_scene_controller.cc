#include "prelude.h"
#include "game_scene_controller.hh"
#pragma implementation "game_scene_controller_lifetimes.hh"
#include "game_scene_controller_lifetimes.hh"
#include "game_scene.hh"
#include "game_scene_return.hh"
#include "hardware_manager.hh"

GameSceneScriptController * gCurrentGameSceneScriptController;

SceneTransitionOwner GameSceneScriptController::Run()
{
    HardwareManagerOwner hardware;
    SceneOwner scene;
    if (unk_364 != 0)
    {
        GameSceneResumeRequest request(0);
        scene = new GameScene(save.get(), request);
    }
    else
    {
        GameSceneResumeRequest request(1);
        scene = new GameScene(save.get(), request);
    }
    SceneMain(scene);
    return SceneTransitionOwner();
}

GameSceneControllerActorRecord * GetSceneActorRecords(void)
{
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    return controller->actor_records;
}

GameSceneEventIconRecord * GetSceneEventIconRecords(void)
{
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    return controller->event_icon_records;
}

GameSceneScriptQueue<2> * GetSceneScriptQueue0(void)
{
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    return &controller->queues.queue_0;
}

GameScenePreservedPlayerLocation * GetScenePreservedPlayerLocation(void)
{
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    return &controller->preserved_player_location;
}

u8 * func_08010138(void)
{
    return reinterpret_cast<u8 *>(&gCurrentGameSceneScriptController->unk_368);
}

u32 func_08010148(void)
{
    return 25;
}

ScriptEngine * GetSceneScriptEngine(void)
{
    GameSceneScriptController * controller =
        gCurrentGameSceneScriptController;
    return &controller->script_engine;
}

GameSceneScriptController::~GameSceneScriptController()
{
    gCurrentGameSceneScriptController = nullptr;
}
