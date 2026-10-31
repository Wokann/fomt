#include "prelude.h"
#include "game_scene.hh"
#include "world_rebuild.hh"

void GameScene::RebuildMapEntitiesForNewDay()
{
    GameSceneState * current = state;
    current->game_object = nullptr;
    current->save->DayUpdate();
    current->game_object = CreateGameWorld(current->save, current->scene, false);
    current->game_object.value->vfunc_138();
    PlayerActor * player = static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER));
    GameScenePreservedPlayerLocation & preserved =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C)->preserved_player_location;
    if (preserved.active != 0) {
        u32 hour = preserved.time.GetHour();
        i32 elapsed = (hour <= 5 ? 6 : 30) - hour;
        player->ChangeStaminaAndFatigue(7 * elapsed, -2 * elapsed);
    }
}
