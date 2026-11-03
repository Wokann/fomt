#include "world_sprite_effects.hh"

WorldSpriteEffects::~WorldSpriteEffects()
{
    delete state;
}

WorldSpriteEffectFrames & WorldSpriteEffectFrames::operator=(WorldSpriteEffectFrames const & other)
{
    unk_00 = other.unk_00;
    unk_01 = other.unk_01;
    {
        IndexedResourceGroupResult * target = groups;
        u32 count = ARRAY_COUNT(groups) - 1;
        IndexedResourceGroupResult const * source = other.groups;
        do {
            *target = *source;
            ++target;
            ++source;
        } while (count-- != 0);
    }
    {
        HardwareStateEntry * target = tiles;
        u32 count = ARRAY_COUNT(tiles) - 1;
        HardwareStateEntry const * source = other.tiles;
        do {
            *target = *source;
            ++target;
            ++source;
        } while (count-- != 0);
    }
    return *this;
}
