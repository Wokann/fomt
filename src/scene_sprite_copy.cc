#include "scene_sprite.hh"

GameSceneSpriteBase::GameSceneSpriteBase(GameSceneSpriteBase const & other)
    : world(other.world), tiles(other.tiles), tile_index(other.tile_index),
      palettes(other.palettes)
{
}
