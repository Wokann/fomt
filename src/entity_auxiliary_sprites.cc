#include "prelude.h"
#pragma implementation "entity_auxiliary_sprites.hh"
#include "game_world.hh"
#include "scene_sprite.hh"
#include "entity_auxiliary_sprites.hh"

EntityAuxiliarySprites::~EntityAuxiliarySprites()
{
    // Match native cleanup: release the first index, then destroy all three
    // retained tile entries in reverse member-array order.
    world->ClearSpritePaletteResourceFlag(indices[0]);
}

void EntityAuxiliarySprites::Draw(WorldSpriteDrawBuffer * buffer, i32 x, i32 y, u32 kind) const
{
    EntityAuxiliarySpriteEntry const & entry = entries[kind];
    u16 tile_offset = entry.tile_index;
    // Auxiliary groups retain a fixed depth key, independent of actor Y.
    u32 sort_key = 0x8000;
    GameObject * source = world;
    GameScenePaletteIndices const & palette_indices = indices;
    // All four source priorities map to hardware OBJ priority 2.
    SubmitWorldSpriteRecords(buffer, x, y, 0xAA, sort_key, entry.group.sprites,
        source, tile_offset, palette_indices);
}
