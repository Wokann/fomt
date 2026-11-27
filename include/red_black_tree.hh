#ifndef RED_BLACK_TREE_HH
#define RED_BLACK_TREE_HH

#include "prelude.h"

// Shared prefix used by the renderer caches, town-map counts and saved maps.
// Native rotations and iteration read only this prefix, never the node value.
struct RedBlackTreeNode {
    bool black;
    RedBlackTreeNode * parent;
    RedBlackTreeNode * left;
    RedBlackTreeNode * right;
};


#endif // RED_BLACK_TREE_HH
