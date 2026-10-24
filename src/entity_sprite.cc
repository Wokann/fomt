#include "prelude.h"
#include "fomt_constants.hh"
#pragma implementation "entity_sprite.hh"
#include "entity_sprite.hh"

DefaultEntitySpriteController::DefaultEntitySpriteController(AActorEntity * entity)
    : EntitySpriteController(entity, 6, 0x20, ENTITY_AUX_RENDER_DEFAULT, 0, 0, false)
{
}
