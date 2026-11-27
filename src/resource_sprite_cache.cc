#include "resource_sprite_cache.hh"
#include "allocation_failure.hh"
#include <stdlib.h>
#include <new>

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".thumb\n"
);

void RotateRedBlackTreeLeft(RedBlackTreeNode * node, RedBlackTreeNode *& root)
{
    RedBlackTreeNode * right = node->right;
    node->right = right->left;
    if (right->left != 0)
        right->left->parent = node;
    right->parent = node->parent;
    if (node == root)
        root = right;
    else if (node == node->parent->left)
        node->parent->left = right;
    else
        node->parent->right = right;
    right->left = node;
    node->parent = right;
}

void RotateRedBlackTreeRight(RedBlackTreeNode * node, RedBlackTreeNode *& root)
{
    RedBlackTreeNode * left = node->left;
    node->left = left->right;
    if (left->right != 0)
        left->right->parent = node;
    left->parent = node->parent;
    if (node == root)
        root = left;
    else if (node == node->parent->right)
        node->parent->right = left;
    else
        node->parent->left = left;
    left->right = node;
    node->parent = left;
}

void RebalanceRedBlackTreeAfterInsert(RedBlackTreeNode * node, RedBlackTreeNode *& root)
{
    node->black = false;
    while (node != root && !node->parent->black) {
        if (node->parent == node->parent->parent->left) {
            RedBlackTreeNode * uncle = node->parent->parent->right;
            if (uncle != nullptr && !uncle->black) {
                node->parent->black = true;
                uncle->black = true;
                node->parent->parent->black = false;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    RotateRedBlackTreeLeft(node, root);
                }
                node->parent->black = true;
                node->parent->parent->black = false;
                RotateRedBlackTreeRight(node->parent->parent, root);
            }
        } else {
            RedBlackTreeNode * uncle = node->parent->parent->left;
            if (uncle != nullptr && !uncle->black) {
                node->parent->black = true;
                uncle->black = true;
                node->parent->parent->black = false;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    RotateRedBlackTreeRight(node, root);
                }
                node->parent->black = true;
                node->parent->parent->black = false;
                RotateRedBlackTreeLeft(node->parent->parent, root);
            }
        }
    }
    root->black = true;
}


// A typed tree exposes its base-node links as references to its node type.
template <typename Node>
static inline Node *& ResourceSpriteCacheLink(RedBlackTreeNode *& link)
{
    return reinterpret_cast<Node *&>(link);
}

template <typename Key>
static inline bool ResourceSpriteCacheKeyLess(Key const & first, Key const & second)
{
    return first < second;
}

template <typename Node, typename StoredEntry, typename Entry>
static inline Node * ConstructResourceSpriteCacheNode(Entry const & entry)
{
    Node * node = static_cast<Node *>(malloc(sizeof(Node)));
    if (node == nullptr)
        node = static_cast<Node *>(RetryMemoryAllocation(sizeof(Node)));
    new (&node->entry) StoredEntry(entry);
    return node;
}

extern "C" ResourceSpriteTileIterator InsertResourceSpriteTileNode(ResourceSpriteTileCache * cache,
    RedBlackTreeNode * position, RedBlackTreeNode * parent_base,
    ResourceSpriteTileEntry const & entry, RedBlackTreeNode * right_hint)
{
    ResourceSpriteTileNode * parent = static_cast<ResourceSpriteTileNode *>(parent_base);
    ResourceSpriteTileNode * node;
    if (parent == cache->header || (right_hint == nullptr
        && (position != nullptr || ResourceSpriteCacheKeyLess(entry.source, parent->entry.source)))) {
        node = ConstructResourceSpriteCacheNode<ResourceSpriteTileNode, ResourceSpriteTileStoredEntry>(entry);
        ResourceSpriteCacheLink<ResourceSpriteTileNode>(parent->left) = node;
        if (parent == cache->header) {
            ResourceSpriteCacheLink<ResourceSpriteTileNode>(parent->parent) = node;
            ResourceSpriteCacheLink<ResourceSpriteTileNode>(cache->header->right) = node;
        } else if (parent == ResourceSpriteCacheLink<ResourceSpriteTileNode>(cache->header->left)) {
            ResourceSpriteCacheLink<ResourceSpriteTileNode>(cache->header->left) = node;
        }
    } else {
        node = ConstructResourceSpriteCacheNode<ResourceSpriteTileNode, ResourceSpriteTileStoredEntry>(entry);
        ResourceSpriteCacheLink<ResourceSpriteTileNode>(parent->right) = node;
        if (parent == ResourceSpriteCacheLink<ResourceSpriteTileNode>(cache->header->right))
            ResourceSpriteCacheLink<ResourceSpriteTileNode>(cache->header->right) = node;
    }
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    RebalanceRedBlackTreeAfterInsert(node, cache->header->parent);
    ++cache->count;
    return ResourceSpriteTileIterator(node);
}

asm_unified(
    ".text\n"
);

RedBlackTreeNode * PreviousRedBlackTreeNode(RedBlackTreeNode * node)
{
    if (!node->black && node->parent->parent == node)
    {
        node = node->right;
    }
    else if (node->left != 0)
    {
        RedBlackTreeNode * child = node->left;
        while (child->right != 0)
            child = child->right;
        node = child;
    }
    else
    {
        RedBlackTreeNode * parent = node->parent;
        while (node == parent->left)
        {
            node = parent;
            parent = parent->parent;
        }
        node = parent;
    }
    return node;
}


extern "C" ResourceSpriteTileInsertResult InsertResourceSpriteTile(ResourceSpriteTileCache * cache,
    ResourceSpriteTileEntry const * entry)
{
    ResourceSpriteTileNode * parent = cache->header;
    ResourceSpriteTileNode * position = ResourceSpriteCacheLink<ResourceSpriteTileNode>(parent->parent);
    bool less = true;
    while (position != nullptr) {
        parent = position;
        less = ResourceSpriteCacheKeyLess(entry->source, position->entry.source);
        position = less ? ResourceSpriteCacheLink<ResourceSpriteTileNode>(position->left)
            : ResourceSpriteCacheLink<ResourceSpriteTileNode>(position->right);
    }
    ResourceSpriteTileIterator previous(parent);
    if (less) {
        ResourceSpriteTileIterator begin(ResourceSpriteCacheLink<ResourceSpriteTileNode>(cache->header->left));
        if (previous == begin)
            return ResourceSpriteTileInsertResult(InsertResourceSpriteTileNode(cache, position, parent, *entry, nullptr), true);
        previous.node = static_cast<ResourceSpriteTileNode *>(PreviousRedBlackTreeNode(previous.node));
    }
    if (ResourceSpriteCacheKeyLess(previous.node->entry.source, entry->source))
        return ResourceSpriteTileInsertResult(InsertResourceSpriteTileNode(cache, position, parent, *entry, nullptr), true);
    return ResourceSpriteTileInsertResult(previous, false);
}

asm_unified(
    ".text\n"
    "    .align 2, 0\n"
    "\tthumb_func_start InsertResourceSpriteTileWithHint\n"
    "InsertResourceSpriteTileWithHint: \n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sb\n"
    "\tmov r6, r8\n"
    "\tpush {r6, r7}\n"
    "\tsub sp, #0x18\n"
    "\tadds r7, r0, #0\n"
    "\tadds r6, r1, #0\n"
    "\tmov r8, r2\n"
    "\tadds r4, r3, #0\n"
    "\tldr r1, [r6, #4]\n"
    "\tldr r2, [r2]\n"
    "\tldr r0, [r1, #8]\n"
    "\tcmp r2, r0\n"
    "\tbne .L080E24D4\n"
    "\tldr r0, [r6, #8]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2474\n"
    "\tadd r0, sp, #8\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r4, #0\n"
    "\tbl InsertResourceSpriteTile\n"
    "\tldr r0, [sp, #8]\n"
    "\tb .L080E25E8\n"
    ".L080E2474:\n"
    "\tmovs r0, #0\n"
    "\tldr r1, [r2, #0x10]\n"
    "\tadds r3, r2, #0\n"
    "\tldr r2, [r4]\n"
    "\tcmp r2, r1\n"
    "\tbhs .L080E2482\n"
    "\tmovs r0, #1\n"
    ".L080E2482:\n"
    "\tmov sb, r0\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2548\n"
    "\tmovs r0, #0\n"
    "\tcmp r1, r2\n"
    "\tbhs .L080E2490\n"
    "\tmovs r0, #1\n"
    ".L080E2490:\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2498\n"
    "\tstr r3, [r7]\n"
    "\tb .L080E25EA\n"
    ".L080E2498:\n"
    "\tstr r3, [sp, #8]\n"
    "\tadds r0, r3, #0\n"
    "\tbl NextRedBlackTreeNode\n"
    "\tadds r2, r0, #0\n"
    "\tstr r2, [sp, #8]\n"
    "\tldr r0, [r6, #4]\n"
    "\tcmp r2, r0\n"
    "\tbne .L080E24B0\n"
    "\tmov r0, r8\n"
    "\tldr r3, [r0]\n"
    "\tb .L080E25AE\n"
    ".L080E24B0:\n"
    "\tmovs r3, #0\n"
    "\tldr r1, [r4]\n"
    "\tldr r0, [r2, #0x10]\n"
    "\tadds r5, r2, #0\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E24BE\n"
    "\tmovs r3, #1\n"
    ".L080E24BE:\n"
    "\tcmp r3, #0\n"
    "\tbne .L080E24C4\n"
    "\tb .L080E25DC\n"
    ".L080E24C4:\n"
    "\tmov r1, r8\n"
    "\tldr r3, [r1]\n"
    "\tldr r0, [r3, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E25AE\n"
    "\tstr r4, [sp]\n"
    "\tmov r0, sb\n"
    "\tb .L080E25C2\n"
    ".L080E24D4:\n"
    "\tcmp r2, r1\n"
    "\tbne .L080E24FE\n"
    "\tldr r3, [r2, #0xc]\n"
    "\tmovs r5, #0\n"
    "\tldr r1, [r3, #0x10]\n"
    "\tldr r0, [r4]\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E24E6\n"
    "\tmovs r5, #1\n"
    ".L080E24E6:\n"
    "\tcmp r5, #0\n"
    "\tbeq .L080E24F0\n"
    "\tstr r4, [sp]\n"
    "\tstr r2, [sp, #4]\n"
    "\tb .L080E25B2\n"
    ".L080E24F0:\n"
    "\tadd r0, sp, #8\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r4, #0\n"
    "\tbl InsertResourceSpriteTile\n"
    "\tldr r0, [sp, #8]\n"
    "\tb .L080E25E8\n"
    ".L080E24FE:\n"
    "\tstr r2, [sp, #8]\n"
    "\tadds r0, r2, #0\n"
    "\tbl PreviousRedBlackTreeNode\n"
    "\tadds r2, r0, #0\n"
    "\tstr r2, [sp, #8]\n"
    "\tmov r1, r8\n"
    "\tldr r3, [r1]\n"
    "\tmovs r5, #0\n"
    "\tldr r1, [r4]\n"
    "\tldr r0, [r3, #0x10]\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E251A\n"
    "\tmovs r5, #1\n"
    ".L080E251A:\n"
    "\tmov sb, r5\n"
    "\tcmp r5, #0\n"
    "\tbeq .L080E255A\n"
    "\tmovs r0, #0\n"
    "\tmov ip, r0\n"
    "\tldr r0, [r2, #0x10]\n"
    "\tadds r5, r2, #0\n"
    "\tcmp r0, r1\n"
    "\tbhs .L080E2530\n"
    "\tmovs r1, #1\n"
    "\tmov ip, r1\n"
    ".L080E2530:\n"
    "\tmov r0, ip\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E255A\n"
    "\tldr r0, [r5, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2548\n"
    "\tstr r4, [sp]\n"
    "\tstr r5, [sp, #4]\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tmovs r2, #0\n"
    "\tb .L080E25CA\n"
    ".L080E2548:\n"
    "\tstr r4, [sp]\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [sp, #4]\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r3, #0\n"
    "\tbl InsertResourceSpriteTileNode\n"
    "\tb .L080E25EA\n"
    ".L080E255A:\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tstr r0, [sp, #0xc]\n"
    "\tbl NextRedBlackTreeNode\n"
    "\tmov ip, r0\n"
    "\tstr r0, [sp, #0xc]\n"
    "\tmovs r0, #1\n"
    "\tmov r1, sb\n"
    "\teors r1, r0\n"
    "\tmov r0, sb\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E25D2\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tmovs r5, #0\n"
    "\tldr r1, [r0, #0x10]\n"
    "\tadds r3, r0, #0\n"
    "\tldr r2, [r4]\n"
    "\tcmp r1, r2\n"
    "\tbhs .L080E2586\n"
    "\tmovs r5, #1\n"
    ".L080E2586:\n"
    "\tadds r1, r5, #0\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E25D2\n"
    "\tldr r0, [r6, #4]\n"
    "\tmov r5, ip\n"
    "\tcmp r5, r0\n"
    "\tbeq .L080E25A8\n"
    "\tmovs r0, #0\n"
    "\tmov ip, r0\n"
    "\tldr r0, [r5, #0x10]\n"
    "\tcmp r2, r0\n"
    "\tbhs .L080E25A2\n"
    "\tmovs r0, #1\n"
    "\tmov ip, r0\n"
    ".L080E25A2:\n"
    "\tmov r0, ip\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E25D2\n"
    ".L080E25A8:\n"
    "\tldr r0, [r3, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E25BE\n"
    ".L080E25AE:\n"
    "\tstr r4, [sp]\n"
    "\tstr r3, [sp, #4]\n"
    ".L080E25B2:\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tmovs r2, #0\n"
    "\tbl InsertResourceSpriteTileNode\n"
    "\tb .L080E25EA\n"
    ".L080E25BE:\n"
    "\tstr r4, [sp]\n"
    "\tmovs r0, #0\n"
    ".L080E25C2:\n"
    "\tstr r0, [sp, #4]\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r5, #0\n"
    ".L080E25CA:\n"
    "\tadds r3, r5, #0\n"
    "\tbl InsertResourceSpriteTileNode\n"
    "\tb .L080E25EA\n"
    ".L080E25D2:\n"
    "\tcmp sb, r1\n"
    "\tbne .L080E25DC\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tb .L080E25E8\n"
    ".L080E25DC:\n"
    "\tadd r0, sp, #0x10\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r4, #0\n"
    "\tbl InsertResourceSpriteTile\n"
    "\tldr r0, [sp, #0x10]\n"
    ".L080E25E8:\n"
    "\tstr r0, [r7]\n"
    ".L080E25EA:\n"
    "\tadds r0, r7, #0\n"
    "\tadd sp, #0x18\n"
    "\tpop {r3, r4}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    "\n"
    "\tthumb_func_start EraseRedBlackTreeNode\n"
    "EraseRedBlackTreeNode: \n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, r8\n"
    "\tpush {r7}\n"
    "\tadds r5, r0, #0\n"
    "\tmov r8, r1\n"
    "\tadds r7, r5, #0\n"
    "\tldr r1, [r7, #8]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E2624\n"
    "\tldr r0, [r7, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2618\n"
    "\tadds r6, r1, #0\n"
    "\tb .L080E2626\n"
    ".L080E2618:\n"
    "\tadds r7, r0, #0\n"
    "\tb .L080E261E\n"
    ".L080E261C:\n"
    "\tldr r7, [r7, #8]\n"
    ".L080E261E:\n"
    "\tldr r0, [r7, #8]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E261C\n"
    ".L080E2624:\n"
    "\tldr r6, [r7, #0xc]\n"
    ".L080E2626:\n"
    "\tcmp r7, r5\n"
    "\tbeq .L080E267A\n"
    "\tldr r0, [r5, #8]\n"
    "\tstr r7, [r0, #4]\n"
    "\tldr r0, [r5, #8]\n"
    "\tstr r0, [r7, #8]\n"
    "\tldr r0, [r5, #0xc]\n"
    "\tcmp r7, r0\n"
    "\tbeq .L080E264E\n"
    "\tldr r4, [r7, #4]\n"
    "\tcmp r6, #0\n"
    "\tbeq .L080E2640\n"
    "\tstr r4, [r6, #4]\n"
    ".L080E2640:\n"
    "\tldr r0, [r7, #4]\n"
    "\tstr r6, [r0, #8]\n"
    "\tldr r0, [r5, #0xc]\n"
    "\tstr r0, [r7, #0xc]\n"
    "\tldr r0, [r5, #0xc]\n"
    "\tstr r7, [r0, #4]\n"
    "\tb .L080E2650\n"
    ".L080E264E:\n"
    "\tadds r4, r7, #0\n"
    ".L080E2650:\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tcmp r0, r5\n"
    "\tbne .L080E265C\n"
    "\tstr r7, [r1]\n"
    "\tb .L080E266A\n"
    ".L080E265C:\n"
    "\tldr r1, [r5, #4]\n"
    "\tldr r0, [r1, #8]\n"
    "\tcmp r0, r5\n"
    "\tbne .L080E2668\n"
    "\tstr r7, [r1, #8]\n"
    "\tb .L080E266A\n"
    ".L080E2668:\n"
    "\tstr r7, [r1, #0xc]\n"
    ".L080E266A:\n"
    "\tldr r0, [r5, #4]\n"
    "\tstr r0, [r7, #4]\n"
    "\tldrb r1, [r7]\n"
    "\tldrb r0, [r5]\n"
    "\tstrb r0, [r7]\n"
    "\tstrb r1, [r5]\n"
    "\tadds r7, r5, #0\n"
    "\tb .L080E26E4\n"
    ".L080E267A:\n"
    "\tldr r4, [r7, #4]\n"
    "\tcmp r6, #0\n"
    "\tbeq .L080E2682\n"
    "\tstr r4, [r6, #4]\n"
    ".L080E2682:\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tcmp r0, r7\n"
    "\tbne .L080E268E\n"
    "\tstr r6, [r1]\n"
    "\tb .L080E269C\n"
    ".L080E268E:\n"
    "\tldr r1, [r7, #4]\n"
    "\tldr r0, [r1, #8]\n"
    "\tcmp r0, r7\n"
    "\tbne .L080E269A\n"
    "\tstr r6, [r1, #8]\n"
    "\tb .L080E269C\n"
    ".L080E269A:\n"
    "\tstr r6, [r1, #0xc]\n"
    ".L080E269C:\n"
    "\tldr r0, [r2]\n"
    "\tcmp r0, r5\n"
    "\tbne .L080E26C0\n"
    "\tldr r0, [r5, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E26AE\n"
    "\tldr r0, [r5, #4]\n"
    "\tstr r0, [r2]\n"
    "\tb .L080E26C0\n"
    ".L080E26AE:\n"
    "\tadds r1, r6, #0\n"
    "\tldr r0, [r6, #8]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E26BE\n"
    ".L080E26B6:\n"
    "\tldr r1, [r1, #8]\n"
    "\tldr r0, [r1, #8]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E26B6\n"
    ".L080E26BE:\n"
    "\tstr r1, [r2]\n"
    ".L080E26C0:\n"
    "\tldr r0, [r3]\n"
    "\tcmp r0, r5\n"
    "\tbne .L080E26E4\n"
    "\tldr r0, [r5, #8]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E26D2\n"
    "\tldr r0, [r5, #4]\n"
    "\tstr r0, [r3]\n"
    "\tb .L080E26E4\n"
    ".L080E26D2:\n"
    "\tadds r1, r6, #0\n"
    "\tldr r0, [r6, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E26E2\n"
    ".L080E26DA:\n"
    "\tldr r1, [r1, #0xc]\n"
    "\tldr r0, [r1, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E26DA\n"
    ".L080E26E2:\n"
    "\tstr r1, [r3]\n"
    ".L080E26E4:\n"
    "\tldrb r0, [r7]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E26EC\n"
    "\tb .L080E27F0\n"
    ".L080E26EC:\n"
    "\tb .L080E27D6\n"
    ".L080E26EE:\n"
    "\tldr r0, [r4, #8]\n"
    "\tcmp r6, r0\n"
    "\tbne .L080E2760\n"
    "\tldr r2, [r4, #0xc]\n"
    "\tldrb r1, [r2]\n"
    "\tcmp r1, #0\n"
    "\tbne .L080E270C\n"
    "\tmovs r0, #1\n"
    "\tstrb r0, [r2]\n"
    "\tstrb r1, [r4]\n"
    "\tadds r0, r4, #0\n"
    "\tmov r1, r8\n"
    "\tbl RotateRedBlackTreeLeft\n"
    "\tldr r2, [r4, #0xc]\n"
    ".L080E270C:\n"
    "\tldr r3, [r2, #8]\n"
    "\tcmp r3, #0\n"
    "\tbeq .L080E271A\n"
    "\tldrb r0, [r3]\n"
    "\tldr r1, [r2, #0xc]\n"
    "\tcmp r0, #1\n"
    "\tbne .L080E2726\n"
    ".L080E271A:\n"
    "\tldr r1, [r2, #0xc]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E2792\n"
    "\tldrb r0, [r1]\n"
    "\tcmp r0, #1\n"
    "\tbeq .L080E2792\n"
    ".L080E2726:\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E2730\n"
    "\tldrb r0, [r1]\n"
    "\tcmp r0, #1\n"
    "\tbne .L080E2746\n"
    ".L080E2730:\n"
    "\tcmp r3, #0\n"
    "\tbeq .L080E2738\n"
    "\tmovs r0, #1\n"
    "\tstrb r0, [r3]\n"
    ".L080E2738:\n"
    "\tmovs r0, #0\n"
    "\tstrb r0, [r2]\n"
    "\tadds r0, r2, #0\n"
    "\tmov r1, r8\n"
    "\tbl RotateRedBlackTreeRight\n"
    "\tldr r2, [r4, #0xc]\n"
    ".L080E2746:\n"
    "\tldrb r0, [r4]\n"
    "\tstrb r0, [r2]\n"
    "\tmovs r1, #1\n"
    "\tstrb r1, [r4]\n"
    "\tldr r0, [r2, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E2756\n"
    "\tstrb r1, [r0]\n"
    ".L080E2756:\n"
    "\tadds r0, r4, #0\n"
    "\tmov r1, r8\n"
    "\tbl RotateRedBlackTreeLeft\n"
    "\tb .L080E27E8\n"
    ".L080E2760:\n"
    "\tadds r2, r0, #0\n"
    "\tldrb r1, [r2]\n"
    "\tcmp r1, #0\n"
    "\tbne .L080E2778\n"
    "\tmovs r0, #1\n"
    "\tstrb r0, [r2]\n"
    "\tstrb r1, [r4]\n"
    "\tadds r0, r4, #0\n"
    "\tmov r1, r8\n"
    "\tbl RotateRedBlackTreeRight\n"
    "\tldr r2, [r4, #8]\n"
    ".L080E2778:\n"
    "\tldr r3, [r2, #0xc]\n"
    "\tcmp r3, #0\n"
    "\tbeq .L080E2786\n"
    "\tldrb r0, [r3]\n"
    "\tldr r1, [r2, #8]\n"
    "\tcmp r0, #1\n"
    "\tbne .L080E279C\n"
    ".L080E2786:\n"
    "\tldr r1, [r2, #8]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E2792\n"
    "\tldrb r0, [r1]\n"
    "\tcmp r0, #1\n"
    "\tbne .L080E279C\n"
    ".L080E2792:\n"
    "\tmovs r0, #0\n"
    "\tstrb r0, [r2]\n"
    "\tadds r6, r4, #0\n"
    "\tldr r4, [r6, #4]\n"
    "\tb .L080E27D6\n"
    ".L080E279C:\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E27A6\n"
    "\tldrb r0, [r1]\n"
    "\tcmp r0, #1\n"
    "\tbne .L080E27BC\n"
    ".L080E27A6:\n"
    "\tcmp r3, #0\n"
    "\tbeq .L080E27AE\n"
    "\tmovs r0, #1\n"
    "\tstrb r0, [r3]\n"
    ".L080E27AE:\n"
    "\tmovs r0, #0\n"
    "\tstrb r0, [r2]\n"
    "\tadds r0, r2, #0\n"
    "\tmov r1, r8\n"
    "\tbl RotateRedBlackTreeLeft\n"
    "\tldr r2, [r4, #8]\n"
    ".L080E27BC:\n"
    "\tldrb r0, [r4]\n"
    "\tstrb r0, [r2]\n"
    "\tmovs r1, #1\n"
    "\tstrb r1, [r4]\n"
    "\tldr r0, [r2, #8]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E27CC\n"
    "\tstrb r1, [r0]\n"
    ".L080E27CC:\n"
    "\tadds r0, r4, #0\n"
    "\tmov r1, r8\n"
    "\tbl RotateRedBlackTreeRight\n"
    "\tb .L080E27E8\n"
    ".L080E27D6:\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tcmp r6, r0\n"
    "\tbeq .L080E27E8\n"
    "\tcmp r6, #0\n"
    "\tbeq .L080E26EE\n"
    "\tldrb r0, [r6]\n"
    "\tcmp r0, #1\n"
    "\tbeq .L080E26EE\n"
    ".L080E27E8:\n"
    "\tcmp r6, #0\n"
    "\tbeq .L080E27F0\n"
    "\tmovs r0, #1\n"
    "\tstrb r0, [r6]\n"
    ".L080E27F0:\n"
    "\tadds r0, r7, #0\n"
    "\tpop {r3}\n"
    "\tmov r8, r3\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\n"
);

extern "C" ResourceSpritePaletteIterator InsertResourceSpritePaletteNode(ResourceSpritePaletteCache * cache,
    RedBlackTreeNode * position, RedBlackTreeNode * parent_base,
    ResourceSpritePaletteEntry const & entry, RedBlackTreeNode * right_hint)
{
    ResourceSpritePaletteNode * parent = static_cast<ResourceSpritePaletteNode *>(parent_base);
    ResourceSpritePaletteNode * node;
    if (parent == cache->header || (right_hint == nullptr
        && (position != nullptr || ResourceSpriteCacheKeyLess(entry.source, parent->entry.source)))) {
        node = ConstructResourceSpriteCacheNode<ResourceSpritePaletteNode, ResourceSpritePaletteStoredEntry>(entry);
        ResourceSpriteCacheLink<ResourceSpritePaletteNode>(parent->left) = node;
        if (parent == cache->header) {
            ResourceSpriteCacheLink<ResourceSpritePaletteNode>(parent->parent) = node;
            ResourceSpriteCacheLink<ResourceSpritePaletteNode>(cache->header->right) = node;
        } else if (parent == ResourceSpriteCacheLink<ResourceSpritePaletteNode>(cache->header->left)) {
            ResourceSpriteCacheLink<ResourceSpritePaletteNode>(cache->header->left) = node;
        }
    } else {
        node = ConstructResourceSpriteCacheNode<ResourceSpritePaletteNode, ResourceSpritePaletteStoredEntry>(entry);
        ResourceSpriteCacheLink<ResourceSpritePaletteNode>(parent->right) = node;
        if (parent == ResourceSpriteCacheLink<ResourceSpritePaletteNode>(cache->header->right))
            ResourceSpriteCacheLink<ResourceSpritePaletteNode>(cache->header->right) = node;
    }
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    RebalanceRedBlackTreeAfterInsert(node, cache->header->parent);
    ++cache->count;
    return ResourceSpritePaletteIterator(node);
}


extern "C" ResourceSpritePaletteInsertResult InsertResourceSpritePalette(ResourceSpritePaletteCache * cache,
    ResourceSpritePaletteEntry const * entry)
{
    ResourceSpritePaletteNode * parent = cache->header;
    ResourceSpritePaletteNode * position = ResourceSpriteCacheLink<ResourceSpritePaletteNode>(parent->parent);
    bool less = true;
    while (position != nullptr) {
        parent = position;
        less = ResourceSpriteCacheKeyLess(entry->source, position->entry.source);
        position = less ? ResourceSpriteCacheLink<ResourceSpritePaletteNode>(position->left)
            : ResourceSpriteCacheLink<ResourceSpritePaletteNode>(position->right);
    }
    ResourceSpritePaletteIterator previous(parent);
    if (less) {
        ResourceSpritePaletteIterator begin(ResourceSpriteCacheLink<ResourceSpritePaletteNode>(cache->header->left));
        if (previous == begin)
            return ResourceSpritePaletteInsertResult(InsertResourceSpritePaletteNode(cache, position, parent, *entry, nullptr), true);
        previous.node = static_cast<ResourceSpritePaletteNode *>(PreviousRedBlackTreeNode(previous.node));
    }
    if (ResourceSpriteCacheKeyLess(previous.node->entry.source, entry->source))
        return ResourceSpritePaletteInsertResult(InsertResourceSpritePaletteNode(cache, position, parent, *entry, nullptr), true);
    return ResourceSpritePaletteInsertResult(previous, false);
}

asm_unified(
    ".text\n"
    "    .align 2, 0\n"
    "\tthumb_func_start InsertResourceSpritePaletteWithHint\n"
    "InsertResourceSpritePaletteWithHint: \n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sb\n"
    "\tmov r6, r8\n"
    "\tpush {r6, r7}\n"
    "\tsub sp, #0x18\n"
    "\tadds r7, r0, #0\n"
    "\tadds r6, r1, #0\n"
    "\tmov r8, r2\n"
    "\tadds r4, r3, #0\n"
    "\tldr r1, [r6, #4]\n"
    "\tldr r2, [r2]\n"
    "\tldr r0, [r1, #8]\n"
    "\tcmp r2, r0\n"
    "\tbne .L080E2A00\n"
    "\tldr r0, [r6, #8]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E29A0\n"
    "\tadd r0, sp, #8\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r4, #0\n"
    "\tbl InsertResourceSpritePalette\n"
    "\tldr r0, [sp, #8]\n"
    "\tb .L080E2B14\n"
    ".L080E29A0:\n"
    "\tmovs r0, #0\n"
    "\tldr r1, [r2, #0x10]\n"
    "\tadds r3, r2, #0\n"
    "\tldr r2, [r4]\n"
    "\tcmp r2, r1\n"
    "\tbhs .L080E29AE\n"
    "\tmovs r0, #1\n"
    ".L080E29AE:\n"
    "\tmov sb, r0\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2A74\n"
    "\tmovs r0, #0\n"
    "\tcmp r1, r2\n"
    "\tbhs .L080E29BC\n"
    "\tmovs r0, #1\n"
    ".L080E29BC:\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E29C4\n"
    "\tstr r3, [r7]\n"
    "\tb .L080E2B16\n"
    ".L080E29C4:\n"
    "\tstr r3, [sp, #8]\n"
    "\tadds r0, r3, #0\n"
    "\tbl NextRedBlackTreeNode\n"
    "\tadds r2, r0, #0\n"
    "\tstr r2, [sp, #8]\n"
    "\tldr r0, [r6, #4]\n"
    "\tcmp r2, r0\n"
    "\tbne .L080E29DC\n"
    "\tmov r0, r8\n"
    "\tldr r3, [r0]\n"
    "\tb .L080E2ADA\n"
    ".L080E29DC:\n"
    "\tmovs r3, #0\n"
    "\tldr r1, [r4]\n"
    "\tldr r0, [r2, #0x10]\n"
    "\tadds r5, r2, #0\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E29EA\n"
    "\tmovs r3, #1\n"
    ".L080E29EA:\n"
    "\tcmp r3, #0\n"
    "\tbne .L080E29F0\n"
    "\tb .L080E2B08\n"
    ".L080E29F0:\n"
    "\tmov r1, r8\n"
    "\tldr r3, [r1]\n"
    "\tldr r0, [r3, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E2ADA\n"
    "\tstr r4, [sp]\n"
    "\tmov r0, sb\n"
    "\tb .L080E2AEE\n"
    ".L080E2A00:\n"
    "\tcmp r2, r1\n"
    "\tbne .L080E2A2A\n"
    "\tldr r3, [r2, #0xc]\n"
    "\tmovs r5, #0\n"
    "\tldr r1, [r3, #0x10]\n"
    "\tldr r0, [r4]\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E2A12\n"
    "\tmovs r5, #1\n"
    ".L080E2A12:\n"
    "\tcmp r5, #0\n"
    "\tbeq .L080E2A1C\n"
    "\tstr r4, [sp]\n"
    "\tstr r2, [sp, #4]\n"
    "\tb .L080E2ADE\n"
    ".L080E2A1C:\n"
    "\tadd r0, sp, #8\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r4, #0\n"
    "\tbl InsertResourceSpritePalette\n"
    "\tldr r0, [sp, #8]\n"
    "\tb .L080E2B14\n"
    ".L080E2A2A:\n"
    "\tstr r2, [sp, #8]\n"
    "\tadds r0, r2, #0\n"
    "\tbl PreviousRedBlackTreeNode\n"
    "\tadds r2, r0, #0\n"
    "\tstr r2, [sp, #8]\n"
    "\tmov r1, r8\n"
    "\tldr r3, [r1]\n"
    "\tmovs r5, #0\n"
    "\tldr r1, [r4]\n"
    "\tldr r0, [r3, #0x10]\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E2A46\n"
    "\tmovs r5, #1\n"
    ".L080E2A46:\n"
    "\tmov sb, r5\n"
    "\tcmp r5, #0\n"
    "\tbeq .L080E2A86\n"
    "\tmovs r0, #0\n"
    "\tmov ip, r0\n"
    "\tldr r0, [r2, #0x10]\n"
    "\tadds r5, r2, #0\n"
    "\tcmp r0, r1\n"
    "\tbhs .L080E2A5C\n"
    "\tmovs r1, #1\n"
    "\tmov ip, r1\n"
    ".L080E2A5C:\n"
    "\tmov r0, ip\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E2A86\n"
    "\tldr r0, [r5, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2A74\n"
    "\tstr r4, [sp]\n"
    "\tstr r5, [sp, #4]\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tmovs r2, #0\n"
    "\tb .L080E2AF6\n"
    ".L080E2A74:\n"
    "\tstr r4, [sp]\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [sp, #4]\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r3, #0\n"
    "\tbl InsertResourceSpritePaletteNode\n"
    "\tb .L080E2B16\n"
    ".L080E2A86:\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tstr r0, [sp, #0xc]\n"
    "\tbl NextRedBlackTreeNode\n"
    "\tmov ip, r0\n"
    "\tstr r0, [sp, #0xc]\n"
    "\tmovs r0, #1\n"
    "\tmov r1, sb\n"
    "\teors r1, r0\n"
    "\tmov r0, sb\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2AFE\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tmovs r5, #0\n"
    "\tldr r1, [r0, #0x10]\n"
    "\tadds r3, r0, #0\n"
    "\tldr r2, [r4]\n"
    "\tcmp r1, r2\n"
    "\tbhs .L080E2AB2\n"
    "\tmovs r5, #1\n"
    ".L080E2AB2:\n"
    "\tadds r1, r5, #0\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080E2AFE\n"
    "\tldr r0, [r6, #4]\n"
    "\tmov r5, ip\n"
    "\tcmp r5, r0\n"
    "\tbeq .L080E2AD4\n"
    "\tmovs r0, #0\n"
    "\tmov ip, r0\n"
    "\tldr r0, [r5, #0x10]\n"
    "\tcmp r2, r0\n"
    "\tbhs .L080E2ACE\n"
    "\tmovs r0, #1\n"
    "\tmov ip, r0\n"
    ".L080E2ACE:\n"
    "\tmov r0, ip\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080E2AFE\n"
    ".L080E2AD4:\n"
    "\tldr r0, [r3, #0xc]\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2AEA\n"
    ".L080E2ADA:\n"
    "\tstr r4, [sp]\n"
    "\tstr r3, [sp, #4]\n"
    ".L080E2ADE:\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tmovs r2, #0\n"
    "\tbl InsertResourceSpritePaletteNode\n"
    "\tb .L080E2B16\n"
    ".L080E2AEA:\n"
    "\tstr r4, [sp]\n"
    "\tmovs r0, #0\n"
    ".L080E2AEE:\n"
    "\tstr r0, [sp, #4]\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r5, #0\n"
    ".L080E2AF6:\n"
    "\tadds r3, r5, #0\n"
    "\tbl InsertResourceSpritePaletteNode\n"
    "\tb .L080E2B16\n"
    ".L080E2AFE:\n"
    "\tcmp sb, r1\n"
    "\tbne .L080E2B08\n"
    "\tmov r1, r8\n"
    "\tldr r0, [r1]\n"
    "\tb .L080E2B14\n"
    ".L080E2B08:\n"
    "\tadd r0, sp, #0x10\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r4, #0\n"
    "\tbl InsertResourceSpritePalette\n"
    "\tldr r0, [sp, #0x10]\n"
    ".L080E2B14:\n"
    "\tstr r0, [r7]\n"
    ".L080E2B16:\n"
    "\tadds r0, r7, #0\n"
    "\tadd sp, #0x18\n"
    "\tpop {r3, r4}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    "\n"
);

RedBlackTreeNode * NextRedBlackTreeNode(RedBlackTreeNode * node)
{
    if (node->right != 0)
    {
        node = node->right;
        while (node->left != 0)
            node = node->left;
    }
    else
    {
        RedBlackTreeNode * parent = node->parent;
        while (node == parent->right)
        {
            node = parent;
            parent = parent->parent;
        }
        if (node->right != parent)
            node = parent;
    }
    return node;
}

void EraseResourceSpriteTileNodes(ResourceSpriteTileCache * cache, ResourceSpriteTileNode * node)
{
    while (node)
    {
        EraseResourceSpriteTileNodes(cache, (ResourceSpriteTileNode *)node->right);
        ResourceSpriteTileNode * left = (ResourceSpriteTileNode *)node->left;
        if (node) free(node);
        node = left;
    }
}

void EraseResourceSpritePaletteNodes(ResourceSpritePaletteCache * cache, ResourceSpritePaletteNode * node)
{
    while (node)
    {
        EraseResourceSpritePaletteNodes(cache, (ResourceSpritePaletteNode *)node->right);
        ResourceSpritePaletteNode * left = (ResourceSpritePaletteNode *)node->left;
        if (node) free(node);
        node = left;
    }
}

asm_unified(
    "    .align 2, 0\n"
    "\tthumb_func_start DrawCachedResourceSprites\n"
    "DrawCachedResourceSprites: \n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #0x28\n"
    "\tmov sl, r0\n"
    "\tstr r1, [sp, #0x10]\n"
    "\tstr r3, [sp, #0x14]\n"
    "\tldr r0, [r2, #8]\n"
    "\tstr r0, [sp, #0x18]\n"
    "\tldr r1, [r2, #0x10]\n"
    "\tstr r1, [sp, #0x1c]\n"
    "\tldr r3, [r2]\n"
    "\tmovs r0, #0\n"
    "\tcmp r3, #0\n"
    "\tbeq .L080E2BD8\n"
    "\tldrh r0, [r2, #4]\n"
    ".L080E2BD8:\n"
    "\tlsls r0, r0, #3\n"
    "\tadds r0, r3, r0\n"
    "\tstr r0, [sp, #0x20]\n"
    "\tcmp r3, r0\n"
    "\tbne .L080E2BE4\n"
    "\tb .L080E2DA2\n"
    ".L080E2BE4:\n"
    "\tldm r3!, {r0, r1}\n"
    "\tstr r0, [sp]\n"
    "\tstr r1, [sp, #4]\n"
    "\tldr r2, [sp]\n"
    "\tlsls r0, r2, #7\n"
    "\tasrs r6, r0, #0x17\n"
    "\tldr r0, [sp, #0x14]\n"
    "\tadds r6, r6, r0\n"
    "\tstr r3, [sp, #0x24]\n"
    "\tcmp r6, #0xef\n"
    "\tble .L080E2BFC\n"
    "\tb .L080E2D98\n"
    ".L080E2BFC:\n"
    "\tmov r0, sp\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tmov r8, r0\n"
    "\tldr r1, [sp, #0x48]\n"
    "\tadd r8, r1\n"
    "\tmov r0, r8\n"
    "\tcmp r0, #0x9f\n"
    "\tble .L080E2C12\n"
    "\tb .L080E2D98\n"
    ".L080E2C12:\n"
    "\tlsls r1, r2, #0x10\n"
    "\tlsrs r1, r1, #0x1e\n"
    "\tlsls r1, r1, #2\n"
    "\tlsrs r0, r2, #0x1e\n"
    "\tadds r1, r1, r0\n"
    "\tldr r2, .L080E2C84 @ =gResourceSpritePackedCellSizes\n"
    "\tlsrs r0, r1, #1\n"
    "\tadds r0, r0, r2\n"
    "\tldrb r2, [r0]\n"
    "\tmovs r0, #1\n"
    "\tands r1, r0\n"
    "\tlsls r1, r1, #2\n"
    "\tasrs r2, r1\n"
    "\tmovs r3, #3\n"
    "\tadds r1, r2, #0\n"
    "\tands r1, r3\n"
    "\tmovs r4, #8\n"
    "\tadds r0, r4, #0\n"
    "\tlsls r0, r1\n"
    "\tadds r0, r6, r0\n"
    "\tcmp r0, #0\n"
    "\tbgt .L080E2C40\n"
    "\tb .L080E2D98\n"
    ".L080E2C40:\n"
    "\tlsrs r1, r2, #2\n"
    "\tands r1, r3\n"
    "\tadds r0, r4, #0\n"
    "\tlsls r0, r1\n"
    "\tadd r0, r8\n"
    "\tcmp r0, #0\n"
    "\tbgt .L080E2C50\n"
    "\tb .L080E2D98\n"
    ".L080E2C50:\n"
    "\tldr r0, [sp, #4]\n"
    "\tlsls r0, r0, #0x16\n"
    "\tlsrs r0, r0, #0x11\n"
    "\tldr r1, [sp, #0x18]\n"
    "\tadds r0, r1, r0\n"
    "\tstr r0, [sp, #8]\n"
    "\tmov r1, sl\n"
    "\tadds r1, #4\n"
    "\tadd r7, sp, #8\n"
    "\tldr r4, [r1, #4]\n"
    "\tldr r2, [r4, #4]\n"
    "\tmov ip, r1\n"
    "\tcmp r2, #0\n"
    "\tbeq .L080E2C8E\n"
    "\tadds r5, r0, #0\n"
    ".L080E2C6E:\n"
    "\tmovs r3, #0\n"
    "\tldr r0, [r2, #0x10]\n"
    "\tcmp r0, r5\n"
    "\tbhs .L080E2C78\n"
    "\tmovs r3, #1\n"
    ".L080E2C78:\n"
    "\tcmp r3, #0\n"
    "\tbne .L080E2C88\n"
    "\tadds r4, r2, #0\n"
    "\tldr r2, [r4, #8]\n"
    "\tb .L080E2C8A\n"
    "\t.align 2, 0\n"
    ".L080E2C84: .word gResourceSpritePackedCellSizes\n"
    ".L080E2C88:\n"
    "\tldr r2, [r2, #0xc]\n"
    ".L080E2C8A:\n"
    "\tcmp r2, #0\n"
    "\tbne .L080E2C6E\n"
    ".L080E2C8E:\n"
    "\tldr r3, [r1, #4]\n"
    "\tcmp r4, r3\n"
    "\tbeq .L080E2CA4\n"
    "\tmovs r2, #0\n"
    "\tldr r1, [r7]\n"
    "\tldr r0, [r4, #0x10]\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E2CA0\n"
    "\tmovs r2, #1\n"
    ".L080E2CA0:\n"
    "\tcmp r2, #0\n"
    "\tbeq .L080E2CA6\n"
    ".L080E2CA4:\n"
    "\tadds r4, r3, #0\n"
    ".L080E2CA6:\n"
    "\tmov r0, ip\n"
    "\tldr r1, [r0, #4]\n"
    "\teors r1, r4\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbge .L080E2CBE\n"
    "\tldr r1, [r4, #0x14]\n"
    "\tmov r0, sl\n"
    "\tbl GetObjTileIndex\n"
    "\tb .L080E2CC2\n"
    ".L080E2CBE:\n"
    "\tmovs r0, #1\n"
    "\trsbs r0, r0, #0\n"
    ".L080E2CC2:\n"
    "\tmov sb, r0\n"
    "\tcmp r0, #0\n"
    "\tblt .L080E2D98\n"
    "\tldr r0, [sp, #4]\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x1c\n"
    "\tlsls r0, r0, #5\n"
    "\tldr r1, [sp, #0x1c]\n"
    "\tadds r0, r1, r0\n"
    "\tstr r0, [sp, #0xc]\n"
    "\tmov r1, sl\n"
    "\tadds r1, #0x18\n"
    "\tadd r7, sp, #0xc\n"
    "\tldr r4, [r1, #4]\n"
    "\tldr r2, [r4, #4]\n"
    "\tmov ip, r1\n"
    "\tcmp r2, #0\n"
    "\tbeq .L080E2D02\n"
    "\tadds r5, r0, #0\n"
    ".L080E2CE8:\n"
    "\tmovs r3, #0\n"
    "\tldr r0, [r2, #0x10]\n"
    "\tcmp r0, r5\n"
    "\tbhs .L080E2CF2\n"
    "\tmovs r3, #1\n"
    ".L080E2CF2:\n"
    "\tcmp r3, #0\n"
    "\tbne .L080E2CFC\n"
    "\tadds r4, r2, #0\n"
    "\tldr r2, [r4, #8]\n"
    "\tb .L080E2CFE\n"
    ".L080E2CFC:\n"
    "\tldr r2, [r2, #0xc]\n"
    ".L080E2CFE:\n"
    "\tcmp r2, #0\n"
    "\tbne .L080E2CE8\n"
    ".L080E2D02:\n"
    "\tldr r3, [r1, #4]\n"
    "\tcmp r4, r3\n"
    "\tbeq .L080E2D18\n"
    "\tmovs r2, #0\n"
    "\tldr r1, [r7]\n"
    "\tldr r0, [r4, #0x10]\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E2D14\n"
    "\tmovs r2, #1\n"
    ".L080E2D14:\n"
    "\tcmp r2, #0\n"
    "\tbeq .L080E2D1A\n"
    ".L080E2D18:\n"
    "\tadds r4, r3, #0\n"
    ".L080E2D1A:\n"
    "\tmov r0, ip\n"
    "\tldr r1, [r0, #4]\n"
    "\teors r1, r4\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbge .L080E2D36\n"
    "\tldr r1, [r4, #0x14]\n"
    "\tmov r0, sl\n"
    "\tadds r0, #0x14\n"
    "\tbl GetObjPaletteBank\n"
    "\tadds r4, r0, #0\n"
    "\tb .L080E2D3A\n"
    ".L080E2D36:\n"
    "\tmovs r4, #1\n"
    "\trsbs r4, r4, #0\n"
    ".L080E2D3A:\n"
    "\tcmp r4, #0\n"
    "\tblt .L080E2D98\n"
    "\tmov r1, r8\n"
    "\tlsls r0, r1, #0x18\n"
    "\tlsrs r0, r0, #0x18\n"
    "\tldr r1, .L080E2DB4 @ =0xFFFFFF00\n"
    "\tldr r3, [sp]\n"
    "\tands r3, r1\n"
    "\torrs r3, r0\n"
    "\tldr r0, .L080E2DB8 @ =0x000001FF\n"
    "\tands r6, r0\n"
    "\tlsls r1, r6, #0x10\n"
    "\tldr r0, .L080E2DBC @ =0xFE00FFFF\n"
    "\tands r3, r0\n"
    "\torrs r3, r1\n"
    "\tstr r3, [sp]\n"
    "\tmov r1, sb\n"
    "\tlsls r0, r1, #0x16\n"
    "\tlsrs r0, r0, #0x16\n"
    "\tldr r1, .L080E2DC0 @ =0xFFFFFC00\n"
    "\tmov r5, sp\n"
    "\tldr r2, [sp, #4]\n"
    "\tands r2, r1\n"
    "\torrs r2, r0\n"
    "\tlsls r0, r4, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tmovs r1, #0xf\n"
    "\tands r0, r1\n"
    "\tlsls r0, r0, #0xc\n"
    "\tldr r1, .L080E2DC4 @ =0xFFFF0FFF\n"
    "\tands r2, r1\n"
    "\torrs r2, r0\n"
    "\tstr r2, [sp, #4]\n"
    "\tldr r0, [sp, #0x10]\n"
    "\tldrb r2, [r0]\n"
    "\tcmp r2, #0x7f\n"
    "\tbhi .L080E2D98\n"
    "\tlsls r0, r2, #3\n"
    "\tadds r0, #4\n"
    "\tldr r1, [sp, #0x10]\n"
    "\tadds r0, r1, r0\n"
    "\tstr r3, [r0]\n"
    "\tldrh r1, [r5, #4]\n"
    "\tstrh r1, [r0, #4]\n"
    "\tadds r0, r2, #1\n"
    "\tldr r1, [sp, #0x10]\n"
    "\tstrb r0, [r1]\n"
    ".L080E2D98:\n"
    "\tldr r3, [sp, #0x24]\n"
    "\tldr r0, [sp, #0x20]\n"
    "\tcmp r3, r0\n"
    "\tbeq .L080E2DA2\n"
    "\tb .L080E2BE4\n"
    ".L080E2DA2:\n"
    "\tadd sp, #0x28\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
    ".L080E2DB4: .word 0xFFFFFF00\n"
    ".L080E2DB8: .word 0x000001FF\n"
    ".L080E2DBC: .word 0xFE00FFFF\n"
    ".L080E2DC0: .word 0xFFFFFC00\n"
    ".L080E2DC4: .word 0xFFFF0FFF\n"
    "\n"
    "\tthumb_func_start ConstructResourceSpriteRendererStorage\n"
    "ConstructResourceSpriteRendererStorage: \n"
    "\tpush {r4, r5, r6, lr}\n"
    "\tsub sp, #0x10\n"
    "\tadds r6, r0, #0\n"
    "\tbl InitializeObjTilePoolOwner\n"
    "\tadds r4, r6, #4\n"
    "\tmovs r5, #0\n"
    "\tstr r5, [r4, #4]\n"
    "\tmovs r0, #0x18\n"
    "\tbl malloc\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2DE8\n"
    "\tmovs r0, #0x18\n"
    "\tbl RetryMemoryAllocation\n"
    ".L080E2DE8:\n"
    "\tstr r0, [r4, #4]\n"
    "\tstr r5, [r4, #8]\n"
    "\tstr r5, [r4, #0xc]\n"
    "\tstrb r5, [r0]\n"
    "\tstr r5, [r0, #4]\n"
    "\tldr r0, [r4, #4]\n"
    "\tstr r0, [r0, #8]\n"
    "\tldr r0, [r4, #4]\n"
    "\tstr r0, [r0, #0xc]\n"
    "\tadds r0, r6, #0\n"
    "\tadds r0, #0x14\n"
    "\tbl ConstructObjPalettePoolOwner\n"
    "\tadds r4, r6, #0\n"
    "\tadds r4, #0x18\n"
    "\tstr r5, [r4, #4]\n"
    "\tmovs r0, #0x18\n"
    "\tbl malloc\n"
    "\tcmp r0, #0\n"
    "\tbne .L080E2E18\n"
    "\tmovs r0, #0x18\n"
    "\tbl RetryMemoryAllocation\n"
    ".L080E2E18:\n"
    "\tstr r0, [r4, #4]\n"
    "\tstr r5, [r4, #8]\n"
    "\tstr r5, [r4, #0xc]\n"
    "\tstrb r5, [r0]\n"
    "\tstr r5, [r0, #4]\n"
    "\tldr r0, [r4, #4]\n"
    "\tstr r0, [r0, #8]\n"
    "\tldr r0, [r4, #4]\n"
    "\tstr r0, [r0, #0xc]\n"
    "\tadds r0, r6, #0\n"
    "\tadd sp, #0x10\n"
    "\tpop {r4, r5, r6}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
);
