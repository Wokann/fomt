#include "game_scene.hh"
#include "entity_actor.hh"

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
