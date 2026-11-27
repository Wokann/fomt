#ifndef RESOURCE_SPRITE_CACHE_HH
#define RESOURCE_SPRITE_CACHE_HH

#include "prelude.h"
#include "resource_archive.hh"
#include "red_black_tree.hh"
#include "obj_tile_pool.hh"
#include "obj_palette_pool.hh"

// The cache key is the source tile/palette address. The value is the pool
// allocation handle, not a ROM pointer or a hardware tile/palette index.
struct ResourceSpriteTileEntry {
    IndexedResourceTileUnit const * source;
    u32 handle;
};

struct ResourceSpritePaletteEntry {
    IndexedResourcePaletteBank const * source;
    u32 handle;
};

// Requests may change their key. A linked node keeps that key immutable.
struct ResourceSpriteTileStoredEntry {
    IndexedResourceTileUnit const * const source;
    u32 handle;
    ResourceSpriteTileStoredEntry(ResourceSpriteTileEntry const & value)
        : source(value.source), handle(value.handle) {}
};

struct ResourceSpritePaletteStoredEntry {
    IndexedResourcePaletteBank const * const source;
    u32 handle;
    ResourceSpritePaletteStoredEntry(ResourceSpritePaletteEntry const & value)
        : source(value.source), handle(value.handle) {}
};

struct ResourceSpriteTileNode : RedBlackTreeNode {
    ResourceSpriteTileStoredEntry entry;
};

struct ResourceSpritePaletteNode : RedBlackTreeNode {
    ResourceSpritePaletteStoredEntry entry;
};

// A separately allocated header node owns the root/first/last links. The
// two surrounding scalar fields remain unnamed; native setup initializes
// +0x0C but does not initialize +0x00.
struct ResourceSpriteTileCache {
    u32 unk_00;
    ResourceSpriteTileNode * header;
    u32 count;
    u32 unk_0C;
};

struct ResourceSpritePaletteCache {
    u32 unk_00;
    ResourceSpritePaletteNode * header;
    u32 count;
    u32 unk_0C;
};

struct ResourceSpriteTileIterator {
    ResourceSpriteTileIterator() {}
    explicit ResourceSpriteTileIterator(ResourceSpriteTileNode * value) : node(value) {}
    ResourceSpriteTileIterator(ResourceSpriteTileIterator const & other) : node(other.node) {}
    ResourceSpriteTileNode * node;
};
struct ResourceSpritePaletteIterator {
    ResourceSpritePaletteIterator() {}
    explicit ResourceSpritePaletteIterator(ResourceSpritePaletteNode * value) : node(value) {}
    ResourceSpritePaletteIterator(ResourceSpritePaletteIterator const & other) : node(other.node) {}
    ResourceSpritePaletteNode * node;
};
struct ResourceSpriteTileInsertResult {
    ResourceSpriteTileIterator iterator;
    bool inserted;
};
struct ResourceSpritePaletteInsertResult {
    ResourceSpritePaletteIterator iterator;
    bool inserted;
};

struct ResourceSpriteRendererStorage {
    ResourceSpriteRendererStorage() asm("ConstructResourceSpriteRendererStorage");
    ObjTilePoolOwner tiles;
    ResourceSpriteTileCache tile_cache;
    ObjPalettePoolOwner palettes;
    ResourceSpritePaletteCache palette_cache;
};


EXTERN_C

// These shared tree operations are emitted in the cache runtime's continuous
// native range. Other map containers use the same node prefix and entry points.
void RotateRedBlackTreeLeft(RedBlackTreeNode * node, RedBlackTreeNode *& root);
void RotateRedBlackTreeRight(RedBlackTreeNode * node, RedBlackTreeNode *& root);
void RebalanceRedBlackTreeAfterInsert(RedBlackTreeNode * node, RedBlackTreeNode *& root);
RedBlackTreeNode * PreviousRedBlackTreeNode(RedBlackTreeNode * node);
RedBlackTreeNode * NextRedBlackTreeNode(RedBlackTreeNode * node);
// Returns the detached node; callers release its allocation separately.
RedBlackTreeNode * EraseRedBlackTreeNode(RedBlackTreeNode * node, RedBlackTreeNode *& root,
    RedBlackTreeNode *& first, RedBlackTreeNode *& last);

// The real JP iterator copy constructor makes the compiler pass return
// storage in r0. Other native interfaces retain their explicit ABI views.
ResourceSpriteTileIterator InsertResourceSpriteTileNode(
    ResourceSpriteTileCache * cache,
    RedBlackTreeNode * position, RedBlackTreeNode * parent,
    ResourceSpriteTileEntry const & entry, RedBlackTreeNode * right_hint);
ResourceSpriteTileInsertResult InsertResourceSpriteTile(ResourceSpriteTileCache * cache,
    ResourceSpriteTileEntry const * entry);
ResourceSpriteTileIterator * InsertResourceSpriteTileWithHint(ResourceSpriteTileIterator * result,
    ResourceSpriteTileCache * cache,
    ResourceSpriteTileIterator const * hint, ResourceSpriteTileEntry const * entry);
ResourceSpritePaletteIterator InsertResourceSpritePaletteNode(
    ResourceSpritePaletteCache * cache,
    RedBlackTreeNode * position, RedBlackTreeNode * parent,
    ResourceSpritePaletteEntry const & entry, RedBlackTreeNode * right_hint);
ResourceSpritePaletteInsertResult InsertResourceSpritePalette(ResourceSpritePaletteCache * cache,
    ResourceSpritePaletteEntry const * entry);
ResourceSpritePaletteIterator * InsertResourceSpritePaletteWithHint(ResourceSpritePaletteIterator * result,
    ResourceSpritePaletteCache * cache,
    ResourceSpritePaletteIterator const * hint, ResourceSpritePaletteEntry const * entry);
void EraseResourceSpriteTileNodes(ResourceSpriteTileCache * cache, ResourceSpriteTileNode * node);
void EraseResourceSpritePaletteNodes(ResourceSpritePaletteCache * cache, ResourceSpritePaletteNode * node);
void DrawCachedResourceSprites(ResourceSpriteRendererStorage * storage, HardwareSpriteBufferState * buffer,
    IndexedResourceGroupResult const * group, i32 x, i32 y);
ResourceSpriteRendererStorage * ConstructResourceSpriteRendererStorage(ResourceSpriteRendererStorage * storage);

EXTERN_C_END

#endif // RESOURCE_SPRITE_CACHE_HH
