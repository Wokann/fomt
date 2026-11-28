#ifndef GAME_MENU_COMMAND_QUEUE_OPS_HH
#define GAME_MENU_COMMAND_QUEUE_OPS_HH

#include "game_menu_command_queue.hh"
#include "allocation_failure.hh"
#include <memory>

inline GameSceneMenuCommandIterator GameSceneMenuCommandQueue::Insert(GameSceneMenuCommandIterator position,
    HardwareLinkBase * const & command)
{
    GameSceneMenuCommandNode * node = static_cast<GameSceneMenuCommandNode *>(malloc(sizeof(GameSceneMenuCommandNode)));
    if (node == nullptr)
        node = static_cast<GameSceneMenuCommandNode *>(RetryMemoryAllocation(sizeof(GameSceneMenuCommandNode)));
    std::construct(&node->command, command);
    GameSceneMenuCommandNode * next = position.current;
    GameSceneMenuCommandNode * previous = next->previous;
    node->next = next;
    node->previous = previous;
    previous->next = node;
    next->previous = node;
    return GameSceneMenuCommandIterator(node);
}

#endif // GAME_MENU_COMMAND_QUEUE_OPS_HH
