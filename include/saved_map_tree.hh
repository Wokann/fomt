#ifndef SAVED_MAP_TREE_HH
#define SAVED_MAP_TREE_HH

#include "prelude.h"
#include <stdlib.h>
#include "allocation_failure.hh"

// Tiles are copied to VRAM at tile_index * 32; palettes are copied to the
// selected map palette buffer at palette_index * 32. The fourth byte is
// ordinary structure padding, copied with the value by the native helpers.
struct SavedMapGraphicsSlot {
    u16 tile_index;
    u8 palette_index;
};

struct SavedMapTreeEntry {
    i32 key;
    SavedMapGraphicsSlot slot;
};

// This is the same 16-byte link prefix used by the shared red-black-tree
// rotations. The sentinel allocation also reserves space for an entry.
struct SavedMapTreeNode {
    bool black;
    SavedMapTreeNode * parent;
    SavedMapTreeNode * left;
    SavedMapTreeNode * right;
    SavedMapTreeEntry entry;
};

struct SavedMapTreeState {
    u8 unk_00[4];
    SavedMapTreeNode * header;
    u32 node_count;
    u32 unk_0C;
};

struct SavedMapTree {
    SavedMapTree();
    u32 next_tile_index;
    u32 next_palette_index;
    SavedMapTreeState state;
};

struct SavedMapTreeIterator { SavedMapTreeNode * node; };
struct SavedMapTreeInsertResult {
    SavedMapTreeIterator iterator;
    bool inserted;
};


struct GameSceneSavedMap;

EXTERN_C
// Release the saved-map tree before forwarding the original destructor flags.
void DestroySavedWorldMap(GameSceneSavedMap * map, int flags);
SavedMapTreeIterator InsertSavedMapTreeNode(SavedMapTreeState * state,
    SavedMapTreeNode * position, SavedMapTreeNode * parent,
    SavedMapTreeEntry const * entry, SavedMapTreeNode * right_hint);
// Signed keys are unique; an existing key returns its original node.
SavedMapTreeInsertResult InsertSavedMapTreeEntry(SavedMapTreeState * state,
    SavedMapTreeEntry const * entry);

void EraseSavedMapTreeNodes(SavedMapTreeState * state, SavedMapTreeNode * node);
EXTERN_C_END

#endif // SAVED_MAP_TREE_HH
