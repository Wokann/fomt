#pragma implementation "saved_map_tree.hh"
#include "saved_map_tree.hh"
#include "world_map.hh"
#include "resource_sprite_cache.hh"

static inline bool SavedMapTreeKeyLess(i32 const & first, i32 const & second)
{
    return first < second;
}


asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".thumb\n"
    ".align 2, 0\n"
    "\n"
    "\tthumb_func_start InsertSavedMapTreeNode\n"
    "InsertSavedMapTreeNode: @ 0x080E4244\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tadds r7, r0, #0\n"
    "\tadds r6, r1, #0\n"
    "\tldr r4, [sp, #0x14]\n"
    "\tadds r5, r3, #0\n"
    "\tldr r0, [r6, #4]\n"
    "\tcmp r5, r0\n"
    "\tbeq .L080E426E\n"
    "\tldr r0, [sp, #0x18]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E42AE\n"
    "\tcmp r2, #0\n"
    "\tbne .L080E426E\n"
    "\tmovs r2, #0\n"
    "\tldr r1, [r4]\n"
    "\tldr r0, [r5, #0x10]\n"
    "\tcmp r1, r0\n"
    "\tbge .L080E426A\n"
    "\tmovs r2, #1\n"
    ".L080E426A:\n"
    "\tcmp r2, #0\n"
    "\tbeq .L080E42AE\n"
    ".L080E426E:\n"
    "\tmovs r0, #0x18\n"
    "\tbl malloc\n"
    "\tadds r2, r0, #0\n"
    "\tcmp r2, #0\n"
    "\tbne .L080E4282\n"
    "\tmovs r0, #0x18\n"
    "\tbl RetryMemoryAllocation\n"
    "\tadds r2, r0, #0\n"
    ".L080E4282:\n"
    "\tadds r1, r2, #0\n"
    "\tadds r1, #0x10\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E4292\n"
    "\tldr r0, [r4]\n"
    "\tstr r0, [r2, #0x10]\n"
    "\tldr r0, [r4, #4]\n"
    "\tstr r0, [r1, #4]\n"
    ".L080E4292:\n"
    "\tadds r4, r2, #0\n"
    "\tstr r4, [r5, #8]\n"
    "\tldr r1, [r6, #4]\n"
    "\tcmp r5, r1\n"
    "\tbne .L080E42A4\n"
    "\tstr r4, [r5, #4]\n"
    "\tldr r0, [r6, #4]\n"
    "\tstr r4, [r0, #0xc]\n"
    "\tb .L080E42E0\n"
    ".L080E42A4:\n"
    "\tldr r0, [r1, #8]\n"
    "\tcmp r5, r0\n"
    "\tbne .L080E42E0\n"
    "\tstr r4, [r1, #8]\n"
    "\tb .L080E42E0\n"
    ".L080E42AE:\n"
    "\tmovs r0, #0x18\n"
    "\tbl malloc\n"
    "\tadds r2, r0, #0\n"
    "\tcmp r2, #0\n"
    "\tbne .L080E42C2\n"
    "\tmovs r0, #0x18\n"
    "\tbl RetryMemoryAllocation\n"
    "\tadds r2, r0, #0\n"
    ".L080E42C2:\n"
    "\tadds r1, r2, #0\n"
    "\tadds r1, #0x10\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E42D2\n"
    "\tldr r0, [r4]\n"
    "\tstr r0, [r2, #0x10]\n"
    "\tldr r0, [r4, #4]\n"
    "\tstr r0, [r1, #4]\n"
    ".L080E42D2:\n"
    "\tadds r4, r2, #0\n"
    "\tstr r4, [r5, #0xc]\n"
    "\tldr r1, [r6, #4]\n"
    "\tldr r0, [r1, #0xc]\n"
    "\tcmp r5, r0\n"
    "\tbne .L080E42E0\n"
    "\tstr r4, [r1, #0xc]\n"
    ".L080E42E0:\n"
    "\tstr r5, [r4, #4]\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [r4, #8]\n"
    "\tstr r0, [r4, #0xc]\n"
    "\tldr r1, [r6, #4]\n"
    "\tadds r1, #4\n"
    "\tadds r0, r4, #0\n"
    "\tbl RebalanceRedBlackTreeAfterInsert\n"
    "\tldr r0, [r6, #8]\n"
    "\tadds r0, #1\n"
    "\tstr r0, [r6, #8]\n"
    "\tstr r4, [r7]\n"
    "\tadds r0, r7, #0\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    "\n"

);

extern "C" SavedMapTreeInsertResult InsertSavedMapTreeEntry(SavedMapTreeState * state,
    SavedMapTreeEntry const * entry)
{
    SavedMapTreeNode * parent = state->header;
    SavedMapTreeNode * position = parent->parent;
    bool less = true;
    while (position != nullptr) {
        parent = position;
        less = SavedMapTreeKeyLess(entry->key, position->entry.key);
        position = less ? position->left : position->right;
    }
    SavedMapTreeIterator previous(parent);
    if (less) {
        SavedMapTreeIterator begin(state->header->left);
        if (previous == begin)
            return SavedMapTreeInsertResult(InsertSavedMapTreeNode(state, position, parent, entry, nullptr), true);
        previous.node = reinterpret_cast<SavedMapTreeNode *>(PreviousRedBlackTreeNode(
            reinterpret_cast<RedBlackTreeNode *>(previous.node)));
    }
    if (SavedMapTreeKeyLess(previous.node->entry.key, entry->key))
        return SavedMapTreeInsertResult(InsertSavedMapTreeNode(state, position, parent, entry, nullptr), true);
    return SavedMapTreeInsertResult(previous, false);
}


void DestroySavedWorldMap(GameSceneSavedMap * map, int flags)
{
    SavedMapTreeState * state = &map->saved_tree.state;
    if (state->node_count != 0) {
        EraseSavedMapTreeNodes(state, state->header->parent);
        state->header->left = state->header;
        state->header->parent = nullptr;
        state->header->right = state->header;
        state->node_count = 0;
    }
    if (state->header != nullptr)
        free(state->header);
    DestroyWorldMapBase(map, flags);
}

asm_unified(
    ".text\n"
    "thumb_func_start __12SavedMapTree\n"
    "__12SavedMapTree:\n"
    "    push {r4, r5, r6, lr}\n"
    "    sub sp, #8\n"
    "    adds r6, r0, #0\n"
    "    adds r4, r6, #0\n"
    "    adds r4, #8\n"
    "    movs r5, #0\n"
    "    str r5, [r4, #4]\n"
    "    movs r0, #24\n"
    "    bl malloc\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_2_0\n"
    "    movs r0, #24\n"
    "    bl RetryMemoryAllocation\n"
    ".Lscalar_2_0:\n"
    "    str r0, [r4, #4]\n"
    "    str r5, [r4, #8]\n"
    "    str r5, [r4, #12]\n"
    "    strb r5, [r0, #0]\n"
    "    str r5, [r0, #4]\n"
    "    ldr r0, [r4, #4]\n"
    "    str r0, [r0, #8]\n"
    "    ldr r0, [r4, #4]\n"
    "    str r0, [r0, #12]\n"
    "    adds r0, r6, #0\n"
    "    add sp, #8\n"
    "    pop {r4, r5, r6}\n"
    "    pop {r1}\n"
    "    bx r1\n"
    "    .align 2, 0\n"
);
