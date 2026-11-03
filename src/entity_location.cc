#include "entity_location.hh"
#include "game_scene.hh"

void GameScene::SetEntityPosition(u32 id, i32 x, i32 y, u32 facing)
{
    GameSceneState * current = state;
    u32 map = current->game_object.value->vfunc_14();
    ::RelocateEntityToMap(current, id, map, x, y, facing);
}

i32 GameScene::GetEntityX(u32 id)
{
    AEntity * entity = state->game_object.value->GetEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16X();
    return value >> 16;
}

i32 GameScene::GetEntityY(u32 id)
{
    AEntity * entity = state->game_object.value->GetEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16Y();
    return value >> 16;
}

void GameScene::SetEntityFacing(u32 id, u32 facing)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr && entity->facing != facing)
        entity->SetAnimFacing(facing);
}

u32 GameScene::GetEntityFacing(u32 id)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    return entity != nullptr ? entity->facing : 0;
}

u32 GameScene::GetEntityMap(u32 id)
{
    AEntity * entity = state->game_object.value->GetEntity(id);
    u32 map = MAP_NONE;
    if (entity != nullptr)
        map = entity->GetMap();
    return map;
}

void GameScene::MoveEntityXTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        StartActorXMotion(*entity, target, speed_q16);
}

void GameScene::MoveEntityYTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = static_cast<AActorEntity *>(state->game_object.value->GetEntity(id));
    if (entity != nullptr)
        StartActorYMotion(*entity, target, speed_q16);
}

void GameScene::WaitForEntityMovement(u32 id)
{
    GameSceneState * current = state;
    AActorEntity * entity = static_cast<AActorEntity *>(current->game_object.value->GetEntity(id));
    current->waiting_entity = entity;
    if (entity != nullptr)
        current->script_state = 0x16;
}

// Both native entry points share these location and player-map effects.
// The signed entity selector and full-width map checks are intentional.
static inline void ApplyEntityLocation(GameSceneState * current, i32 entity_id,
    u32 map, i32 x, i32 y, u32 facing)
{
    if (entity_id <= ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3) {
        AActorEntity * entity = static_cast<AActorEntity *>(
            current->game_object.value->GetEntity(entity_id));
        if (entity != nullptr) {
            entity->SetLocation(ActorLocation(Location(map, x, y), facing));
            entity->SuspendNormalUpdates();
        }
    } else {
        AEntity * entity = current->game_object.value->GetEntity(entity_id);
        if (entity != nullptr) {
            entity->SetLocation(Location(map, x, y));
            entity->SuspendNormalUpdates();
        }
    }

    // Missing actors do not suppress the original player-map side effects.
    if (entity_id == ENTITY_PLAYER) {
        if (map == MAP_LIBRARY_2F)
            current->save->npcs.RecordLibrarySecondFloorVisit();

        i32 floor = 0;
        if (map >= MAP_SPRING_MINE_FLOOR_1 && map <= MAP_SPRING_MINE_FLOOR_255)
            floor = map - MAP_SPRING_MINE_FLOOR_0;
        else if (map >= MAP_LAKE_MINE_FLOOR_1 && map <= MAP_LAKE_MINE_FLOOR_255)
            floor = map - MAP_LAKE_MINE_FLOOR_0;

        if (floor > 0)
            UpdateDeepestMineFloor(current->save->farmer, floor);
    }
}

void GameScene::RelocateEntityToMap(i32 entity_id, u32 map,
    i32 x, i32 y, u32 facing)
{
    i32 target_x = x;
    GameSceneState * current = state;
    u32 target_map = map;
    ApplyEntityLocation(current, entity_id, target_map, target_x, y, facing);
}

void RelocateEntityToMap(GameSceneState * current, i32 entity_id, u32 map,
    i32 x, i32 y, u32 facing)
{
    i32 target_x = x;
    u32 target_map = map;
    ApplyEntityLocation(current, entity_id, target_map, target_x, y, facing);
}
