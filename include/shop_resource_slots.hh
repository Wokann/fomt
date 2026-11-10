#ifndef SHOP_RESOURCE_SLOTS_HH
#define SHOP_RESOURCE_SLOTS_HH

#include "red_black_tree.hh"

#if !defined(REGION_JP)
// UpdateShopScreenDisplay builds two temporary maps, keyed by a visible row's
// tile or palette source pointer. The value selects one of its nine OBJ slots.
// JP draws the corresponding rows directly and does not create these maps.
struct ShopResourceSlotEntry {
    void const * source;
    u32 slot;
};

struct ShopResourceSlotNode : RedBlackTreeNode {
    ShopResourceSlotEntry entry;
};

// The separately allocated header owns root/first/last links. Only +0x0C is
// initialized among these two otherwise unidentified words.
struct ShopResourceSlotMap {
    u32 unk_00;
    ShopResourceSlotNode * header;
    u32 count;
    u32 unk_0C;
};

struct ShopResourceSlotIterator { ShopResourceSlotNode * node; };
struct ShopResourceSlotInsertResult {
    ShopResourceSlotIterator iterator;
    bool inserted;
};

typedef char ShopResourceSlotEntrySizeCheck[sizeof(ShopResourceSlotEntry) == 8 ? 1 : -1];
typedef char ShopResourceSlotNodeSizeCheck[sizeof(ShopResourceSlotNode) == 24 ? 1 : -1];
typedef char ShopResourceSlotNodeEntryCheck[offsetof(ShopResourceSlotNode, entry) == 16 ? 1 : -1];
typedef char ShopResourceSlotMapSizeCheck[sizeof(ShopResourceSlotMap) == 16 ? 1 : -1];
typedef char ShopResourceSlotIteratorSizeCheck[sizeof(ShopResourceSlotIterator) == 4 ? 1 : -1];
typedef char ShopResourceSlotResultSizeCheck[sizeof(ShopResourceSlotInsertResult) == 8 ? 1 : -1];

EXTERN_C
// Release the subtree's nodes; the caller separately frees its header.
void EraseShopResourceSlotNodes(ShopResourceSlotMap * map, ShopResourceSlotNode * node);
ShopResourceSlotIterator InsertShopResourceSlotNode(ShopResourceSlotMap * map,
    ShopResourceSlotNode * position, ShopResourceSlotNode * parent,
    ShopResourceSlotEntry const * entry, ShopResourceSlotNode * right_hint);
// Existing source pointers keep their previous slot and return inserted=false.
ShopResourceSlotInsertResult InsertShopResourceSlot(ShopResourceSlotMap * map,
    ShopResourceSlotEntry const * entry);
ShopResourceSlotIterator InsertShopResourceSlotWithHint(ShopResourceSlotMap * map,
    ShopResourceSlotIterator const * hint, ShopResourceSlotEntry const * entry);
EXTERN_C_END
#endif

#endif // SHOP_RESOURCE_SLOTS_HH
