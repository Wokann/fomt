#ifndef WORLD_FURNITURE_HH
#define WORLD_FURNITURE_HH

#include "game_world.hh"

EXTERN_C

// Still native: update/create the vase sprite in the farmhouse, or release it
// outside that map. ITEM_ARTICLE_NONE leaves an existing vase sprite alone.
void RefreshWorldVase(GameSceneWorldPrefix & world);

EXTERN_C_END

#endif // WORLD_FURNITURE_HH
