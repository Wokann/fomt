#ifndef RESOURCE_SPRITE_RENDERER_HH
#define RESOURCE_SPRITE_RENDERER_HH

#include "prelude.h"

#include "resource_sprite_cache.hh"

// Owns the tile/palette cache shared by the farm and town map renderers.
// Its existing native constructor/destructor implement the actual C++ ABI.
#pragma interface "resource_sprite_renderer.hh"
struct ResourceSpriteRenderer
{
    ResourceSpriteRenderer();
    virtual ~ResourceSpriteRenderer();

    ResourceSpriteRendererStorage * storage;
};



EXTERN_C

void LoadResourceSprite(ResourceSpriteRenderer * renderer, IndexedResourceGroupResult const * group);
void DrawResourceSprite(ResourceSpriteRenderer * renderer, HardwareSpriteBufferState * buffer,
    IndexedResourceGroupResult const * group, i32 x, i32 y);
// A missing cached source returns -1; a found source is resolved through its
// allocation handle. These are complete native functions, not Load's tail.
i32 FindResourceSpriteTileIndex(ResourceSpriteRenderer const * renderer, IndexedResourceTileUnit const * source);
i32 FindResourceSpritePaletteBank(ResourceSpriteRenderer const * renderer, IndexedResourcePaletteBank const * source);

EXTERN_C_END

// Packed cell dimensions consumed by the native OAM renderer.
extern u8 const gResourceSpritePackedCellSizes[];

#endif // RESOURCE_SPRITE_RENDERER_HH
