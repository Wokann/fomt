#include "prelude.h"
#pragma implementation "player_sprite.hh"
#include "player_actor.hh"
#include "entity_ui.hh"
#include <new>
#include "player_sprite.hh"

PlayerSpriteController::PlayerSpriteController(PlayerActor * player)
    : EntitySpriteController(player, 6, gPlayerSpritePaletteKinds, 3,
          ENTITY_AUX_RENDER_DEFAULT, 0, 1, true),
      unk_8C(player->game_object->vfunc_64(), 0, player->GetGameObject(), 2, 1, false),
      slots(), unk_281(0)
{
    for (u32 i = 0; i < PlayerSpriteSlots::CAPACITY; ++i)
        slots.Push(PlayerSpriteSlot(player->game_object->vfunc_68(), player->GetGameObject()));
    next_slot = 0;
}
