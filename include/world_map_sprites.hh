#ifndef WORLD_MAP_SPRITES_HH
#define WORLD_MAP_SPRITES_HH

#include "game_world.hh"

EXTERN_C

// Release the old two owners first, then create the map/season variants.
void RefreshWorldHillSeasonalSprites(GameSceneWorldPrefix & world);
// The supported maps combine winter state and the three actual fireplace bits.
void RefreshWorldWinterAndFireplaceSprites(GameSceneWorldPrefix & world);

EXTERN_C_END

#endif // WORLD_MAP_SPRITES_HH
