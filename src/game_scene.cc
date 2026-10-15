#include "game_scene.hh"
#include "entity_actor.hh"
#include "entity_ui.hh"

u8 * func_080100F0(void)
{
    return gUnk_0300040C + 0x524;
}

u8 * func_08010104(void)
{
    return gUnk_0300040C + 0x4DC;
}

u8 * func_08010118(void)
{
    return gUnk_0300040C + 0x378;
}

u8 * func_08010128(void)
{
    return gUnk_0300040C + 0x36C;
}

u8 * func_08010138(void)
{
    return gUnk_0300040C + 0x368;
}

u32 func_08010148(void)
{
    return 25;
}

u8 * func_0801014C(void)
{
    return gUnk_0300040C + 8;
}

SceneTransitionOwner GameScene::Run()
{
    return sub_080D8178(state);
}

void GameScene::SetEntityPosition(u32 id, i32 x, i32 y, u32 facing)
{
    GameSceneState * current = state;
    u32 map = current->game_object->vfunc_14();
    func_080D7F9C(current, id, map, x, y, facing);
}

i32 GameScene::GetEntityX(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16X();
    return value >> 16;
}

i32 GameScene::GetEntityY(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    i32 value = 0;
    if (entity != nullptr)
        value = entity->GetQ16Y();
    return value >> 16;
}

void GameScene::SetEntityFacing(u32 id, u32 facing)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr && entity->facing != facing)
        entity->SetAnimFacing(facing);
}

u32 GameScene::GetEntityFacing(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    return entity != nullptr ? entity->facing : 0;
}

u32 GameScene::GetEntityMap(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    u32 map = MAP_NONE;
    if (entity != nullptr)
        map = entity->GetMap();
    return map;
}

void GameScene::SetEntitySpritePriority(u32 id, u32 priority)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        entity->unk_21 = priority;
}

void GameScene::MoveEntityXTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_08032308(*entity, target, speed_q16);
}

void GameScene::MoveEntityYTo(u32 id, u32 target, i32 speed_q16)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_0803233C(*entity, target, speed_q16);
}

void GameScene::WaitForEntityMovement(u32 id)
{
    GameSceneState * current = state;
    AActorEntity * entity = current->game_object->GetActorEntity(id);
    current->waiting_entity = entity;
    if (entity != nullptr)
        current->script_state = 0x16;
}

void GameScene::SetEntityAnim(u32 id, u32 animation)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr && entity->anim_id != animation)
        entity->SetAnim(animation);
}

void GameScene::NoOp014(i32)
{
}

void GameScene::HideEntity(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        entity->PutOutOfTown();
}

void GameScene::OffsetEntityPosition(u32 id, i32 delta_x, i32 delta_y)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr) {
        // This native callback uses the extended +0x30 selector, not the
        // actor's +0x20 facing. It does not write the actor's coordinates.
        EntityUiCallbackState * callback = reinterpret_cast<EntityUiCallbackState *>(entity);
        i32 x = entity->GetQ16X() >> 16;
        i32 y = entity->GetQ16Y() >> 16;
        x += delta_x;
        y += delta_y;
        func_08033B84(callback, callback->value_30, x, y);
    }
}

void GameScene::StartEntityEffect(u32 id, u32 effect, u32 persistent)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_08032384(*entity, effect, persistent != 0);
}

void GameScene::StopEntityEffect(u32 id)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_080323C8(*entity);
}

void GameScene::SetEntityAuxRenderProfile(u32 id, u32 profile)
{
    AActorEntity * entity = state->game_object->GetActorEntity(id);
    if (entity != nullptr)
        func_080323E0(*entity, profile);
}

void GameScene::ChangeMap(u32 map, i32 x, i32 y)
{
    GameSceneState * current = state;
    current->game_object->ChangeMap(Location(map, x, y), true);
    func_080D7F08(current);
}

void GameScene::PanCameraTo(i32 x, i32 y, u32 speed)
{
    state->game_object->PanCameraTo(x, y, speed);
}

void GameScene::WaitForCameraMovement()
{
    GameSceneState * current = state;
    if (!current->game_object->IsCameraMovementComplete())
        current->script_state = 0x17;
}
