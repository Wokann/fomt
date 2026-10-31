#ifndef WORLD_REBUILD_HH
#define WORLD_REBUILD_HH

#include "prelude.h"
#include "game_world.hh"
#pragma interface "world_rebuild.hh"

struct GameScene;
struct GameStateSaveImage;

// Transfer from the factory's concrete world slot to the base-world owner.
struct GameSceneWorldOwnerTransfer {
    GameSceneWorldPrefix * & source;
    GameObject * value;
    GameSceneWorldOwnerTransfer(GameSceneWorldPrefix * & input, GameObject * world)
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

// This owner uses only the verified virtual prefix; it never allocates the
// partial class or infers its native size. The native factory does allocation.
struct GameSceneWorldInstanceOwner {
    GameSceneWorldPrefix * value;
    GameSceneWorldPrefix * release()
    {
        GameSceneWorldPrefix * world = value;
        value = nullptr;
        return world;
    }
    explicit GameSceneWorldInstanceOwner(GameSceneWorldPrefix * input = nullptr) : value(input) {}
    GameSceneWorldInstanceOwner(GameSceneWorldInstanceOwner & other) : value(other.release()) {}
    ~GameSceneWorldInstanceOwner() { delete value; }
    operator GameSceneWorldOwnerTransfer()
    {
        return GameSceneWorldOwnerTransfer(value, value);
    }
};

typedef char GameSceneWorldInstanceOwnerSizeCheck[sizeof(GameSceneWorldInstanceOwner) == 4 ? 1 : -1];
typedef char GameSceneWorldOwnerTransferSizeCheck[sizeof(GameSceneWorldOwnerTransfer) == 8 ? 1 : -1];
typedef char GameSceneWorldOwnerTransferValueCheck[offsetof(GameSceneWorldOwnerTransfer, value) == 4 ? 1 : -1];

EXTERN_C
// The native factory allocates the concrete world and its associated object.
// Its final byte's complete role is still unconfirmed.
GameSceneWorldInstanceOwner CreateGameWorld(GameStateSaveImage * save, GameScene * scene, u8 unk);
EXTERN_C_END

#endif // WORLD_REBUILD_HH
