#include "game_menu_command_queue.hh"

void GameSceneMenuCommandQueue::ClearNodes()
{
    GameSceneMenuCommandNode * node = sentinel->next;
    while (node != sentinel) {
        GameSceneMenuCommandNode * old = node;
        node = node->next;
        if (old != nullptr)
            free(old);
    }
    GameSceneMenuCommandNode * head = sentinel;
    head->next = head;
    head->previous = head;
}
