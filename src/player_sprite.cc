#include "prelude.h"
#pragma implementation "player_sprite.hh"
#include "player_actor.hh"
#include "entity_ui.hh"
#include <new>
#include "player_sprite.hh"

PlayerSpriteController::PlayerSpriteController(PlayerActor * player)
    : EntitySpriteController(player, 6, gPlayerSpritePaletteKinds, 3,
          ENTITY_AUX_RENDER_DEFAULT, 0, 1, true),
      held_actor_sprite(player->game_object->vfunc_64(), 0, player->GetGameObject(), 2, 1, false),
      slots(), unk_281(0)
{
    for (u32 i = 0; i < PlayerSpriteSlots::CAPACITY; ++i)
        slots.Push(PlayerSpriteSlot(player->game_object->vfunc_68(), player->GetGameObject()));
    next_slot = 0;
}

void PlayerSpriteController::Update()
{
    EntitySpriteController::Update();
    PlayerActor * player = static_cast<PlayerActor *>(entity);
    u8 frame_changed = GetFrameChangeFlag();
    if (player->unk_7C != 0xFFFF && frame_changed == 0)
        player->unk_7C = 0xFFFF;
    if (player->IsHoldingActorGraphic())
        held_actor_sprite.UpdateAnimation();
    for (u32 i = 0; i < PlayerSpriteSlots::CAPACITY; ++i)
        slots[i].Update();
}
