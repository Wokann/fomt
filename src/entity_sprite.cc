#include "prelude.h"
#include "fomt_constants.hh"
#pragma implementation "entity_sprite.hh"
#include "entity_sprite.hh"
#include "entity_actor.hh"

EntitySpriteController::EntitySpriteController(AActorEntity * owner,
    u32 size_shift, u32 palette_kind, u32 profile, u32 unknown_8A2,
    u32 unknown_8B, bool sprite_unknown_3D)
    : EntityVisualController(owner),
      sprite(owner->game_object->vfunc_68(), owner->GetAnimationIndex(),
          owner->GetGameObject(), size_shift, palette_kind, sprite_unknown_3D),
      effect(owner->game_object->vfunc_6C(), 0, owner->GetGameObject(), 2, 14, false),
      aux_render_profile(profile), unk_89(0), effect_mode(0),
      unk_8A_2(unknown_8A2), unk_8B(unknown_8B)
{
}

EntitySpriteController::EntitySpriteController(AActorEntity * owner,
    u32 size_shift, i32 const * palette_kinds, u32 palette_count, u32 profile,
    u32 unknown_8A2, u32 unknown_8B, bool sprite_unknown_3D)
    : EntityVisualController(owner),
      sprite(owner->game_object->vfunc_68(), owner->GetAnimationIndex(),
          owner->GetGameObject(), size_shift, palette_kinds, palette_count, sprite_unknown_3D),
      effect(owner->game_object->vfunc_6C(), 0, owner->GetGameObject(), 2, 14, false),
      aux_render_profile(profile), unk_89(0), effect_mode(0),
      unk_8A_2(unknown_8A2), unk_8B(unknown_8B)
{
}

DefaultEntitySpriteController::DefaultEntitySpriteController(AActorEntity * entity)
    : EntitySpriteController(entity, 6, 0x20, ENTITY_AUX_RENDER_DEFAULT, 0, 0, false)
{
}
