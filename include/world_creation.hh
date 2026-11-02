#ifndef WORLD_CREATION_HH
#define WORLD_CREATION_HH

#include "prelude.h"
#include "game_world.hh"
#pragma interface "world_creation.hh"

struct GameScene;
struct GameStateSaveImage;

// Transfer from the factory's concrete world slot to the base-world owner.
struct GameSceneWorldOwnerTransfer {
    GameSceneWorld * & source;
    GameObject * value;
    GameSceneWorldOwnerTransfer(GameSceneWorld * & input, GameObject * world)
        : source(input), value(world)
    {
        // Cache the base pointer before releasing the concrete source slot.
        input = nullptr;
    }
    GameObject * release() const
    {
        return value;
    }
};

// Own the complete native world. Return adoption clears the source slot
// through its eight-byte transfer record; assignment to the base owner uses
// the separate transfer contract above.
struct GameSceneWorldInstanceTransfer {
    GameSceneWorld * & source;
    GameSceneWorld * value;
    GameSceneWorldInstanceTransfer(GameSceneWorld * & input, GameSceneWorld * world)
        : source(input), value(world) {}
    GameSceneWorld * release() const
    {
        GameSceneWorld * world = value;
        source = nullptr;
        return world;
    }
};

struct GameSceneWorldInstanceOwner {
    GameSceneWorld * value;
    GameSceneWorld * release()
    {
        GameSceneWorld * world = value;
        value = nullptr;
        return world;
    }
    explicit GameSceneWorldInstanceOwner(GameSceneWorld * input = nullptr) : value(input) {}
    GameSceneWorldInstanceOwner(GameSceneWorldInstanceOwner & other) : value(other.release()) {}
    GameSceneWorldInstanceOwner(GameSceneWorldInstanceTransfer input) : value(input.release()) {}
    operator GameSceneWorldInstanceTransfer()
    {
        return GameSceneWorldInstanceTransfer(value, value);
    }
    ~GameSceneWorldInstanceOwner() { delete value; }
    operator GameSceneWorldOwnerTransfer()
    {
        return GameSceneWorldOwnerTransfer(value, value);
    }
};

typedef char GameSceneWorldInstanceTransferSizeCheck[sizeof(GameSceneWorldInstanceTransfer) == 8 ? 1 : -1];
typedef char GameSceneWorldInstanceTransferValueCheck[offsetof(GameSceneWorldInstanceTransfer, value) == 4 ? 1 : -1];

typedef char GameSceneWorldInstanceOwnerSizeCheck[sizeof(GameSceneWorldInstanceOwner) == 4 ? 1 : -1];
typedef char GameSceneWorldOwnerTransferSizeCheck[sizeof(GameSceneWorldOwnerTransfer) == 8 ? 1 : -1];
typedef char GameSceneWorldOwnerTransferValueCheck[offsetof(GameSceneWorldOwnerTransfer, value) == 4 ? 1 : -1];

EXTERN_C
// The native factory allocates the concrete world and its associated object.
// The final argument's role is unknown; native callers pass only false/true.
GameSceneWorldInstanceOwner CreateGameWorld(GameStateSaveImage * save, GameScene * scene, bool unk);
EXTERN_C_END

#endif // WORLD_CREATION_HH
