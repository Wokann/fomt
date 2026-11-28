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
    GameSceneMenuCommandIterator Erase(GameSceneMenuCommandIterator position)
    {
        GameSceneMenuCommandNode * node = position.current;
        GameSceneMenuCommandNode * next = node->next;
        GameSceneMenuCommandNode * previous = node->previous;
        previous->next = next;
        next->previous = previous;
        free(node);
        return GameSceneMenuCommandIterator(next);
    }
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

#endif // GAME_MENU_COMMAND_QUEUE_HH
