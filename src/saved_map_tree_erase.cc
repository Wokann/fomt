#include "saved_map_tree.hh"

void EraseSavedMapTreeNodes(SavedMapTreeState * state, SavedMapTreeNode * node)
{
    while (node != nullptr) {
        EraseSavedMapTreeNodes(state, node->right);
        SavedMapTreeNode * left = node->left;
        if (node != nullptr)
            free(node);
        node = left;
    }
}
