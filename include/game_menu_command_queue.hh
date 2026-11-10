#ifndef GAME_MENU_COMMAND_QUEUE_HH
#define GAME_MENU_COMMAND_QUEUE_HH

#include "prelude.h"
#include <stdlib.h>

struct HardwareLinkBase;

struct GameSceneMenuCommandNode {
    GameSceneMenuCommandNode * next;
    GameSceneMenuCommandNode * previous;
    HardwareLinkBase * command;
};
struct GameSceneMenuCommandIterator {
    GameSceneMenuCommandNode * current;
    explicit GameSceneMenuCommandIterator(GameSceneMenuCommandNode * node) : current(node) {}
    GameSceneMenuCommandIterator(GameSceneMenuCommandIterator const & other) : current(other.current) {}
    bool operator!=(GameSceneMenuCommandIterator const & other) const
    {
        return current != other.current;
    }
    GameSceneMenuCommandIterator & operator++()
    {
        current = current->next;
        return *this;
    }
    HardwareLinkBase * operator*() const { return current->command; }
};
struct GameSceneMenuCommandQueue {
    u32 unk_00;
    GameSceneMenuCommandNode * sentinel;
    void ClearNodes();
    ~GameSceneMenuCommandQueue()
    {
        ClearNodes();
        if (sentinel != nullptr)
            free(sentinel);
    }
    GameSceneMenuCommandIterator Begin() const
    {
        return GameSceneMenuCommandIterator(sentinel->next);
    }
    GameSceneMenuCommandIterator End() const
    {
        return GameSceneMenuCommandIterator(sentinel);
    }
private:
    GameSceneMenuCommandQueue();
};

typedef char MenuCommandNodeSizeCheck[sizeof(GameSceneMenuCommandNode) == 12 ? 1 : -1];
typedef char MenuCommandNodeValueCheck[offsetof(GameSceneMenuCommandNode, command) == 8 ? 1 : -1];
typedef char MenuCommandIteratorSizeCheck[sizeof(GameSceneMenuCommandIterator) == 4 ? 1 : -1];
typedef char MenuCommandQueueSizeCheck[sizeof(GameSceneMenuCommandQueue) == 8 ? 1 : -1];
typedef char MenuCommandQueueHeadCheck[offsetof(GameSceneMenuCommandQueue, sentinel) == 4 ? 1 : -1];

#endif // GAME_MENU_COMMAND_QUEUE_HH
