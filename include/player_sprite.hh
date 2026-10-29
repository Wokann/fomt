#ifndef PLAYER_SPRITE_HH
#define PLAYER_SPRITE_HH

#include "entity_sprite.hh"
#include "utility/vec2.hh"
#include <new>

#pragma interface "player_sprite.hh"

struct PlayerActor;

struct PlayerSpriteSlot {
    PlayerSpriteSlot(IndexedResourceProvider * resource, GameObject * world)
        : active(false), sprite(resource, 0, world, 0, 18, false), position(0, 0)
    {
    }

    bool active;
    GameSceneIndexedSprite sprite;
    // Native insertion captures the player's signed Q16 integer coordinates.
    Vec2 position;

    void Update()
    {
        if (active) {
            IndexedResourceUpdateResult const & result = sprite.UpdateAnimation();
            if (result.flags.wrapped)
                active = false;
        }
    }
};

// Only the first count records are live. Insertion constructs one record;
// unused capacity never constructs or destroys a graphics resource.
struct PlayerSpriteSlots {
    PlayerSpriteSlots() : count(0) {}

    enum { CAPACITY = 6 };
    u32 count;
    u32 storage[CAPACITY * sizeof(PlayerSpriteSlot) / sizeof(u32)];

    PlayerSpriteSlot * Data()
    {
        return reinterpret_cast<PlayerSpriteSlot *>(storage);
    }
    PlayerSpriteSlot * End()
    {
        return &reinterpret_cast<PlayerSpriteSlot *>(storage)[count];
    }
    PlayerSpriteSlot & operator[](u32 index)
    {
        return Data()[index];
    }
    ~PlayerSpriteSlots()
    {
        PlayerSpriteSlot * last = End();
        PlayerSpriteSlot * first = Data();
        while (first != last) {
            first->~PlayerSpriteSlot();
            ++first;
        }
    }
    void Push(PlayerSpriteSlot const & slot)
    {
        if (count < CAPACITY) {
            new (End()) PlayerSpriteSlot(slot);
            ++count;
        }
    }
};

struct PlayerSpriteController : EntitySpriteController {
    PlayerSpriteController(PlayerActor * player);

    virtual void Update();
    virtual void Draw(void * draw_context);

    GameSceneIndexedSprite held_actor_sprite;
    PlayerSpriteSlots slots;
    u8 next_slot;
    u8 unk_281;
};

typedef char PlayerSpriteSlotSizeCheck[sizeof(PlayerSpriteSlot) == 0x48 ? 1 : -1];
typedef char PlayerSpriteSlotSpriteCheck[offsetof(PlayerSpriteSlot, sprite) == 4 ? 1 : -1];
typedef char PlayerSpriteSlotPositionCheck[offsetof(PlayerSpriteSlot, position) == 0x44 ? 1 : -1];
typedef char PlayerSpriteSlotsSizeCheck[sizeof(PlayerSpriteSlots) == 0x1B4 ? 1 : -1];
typedef char PlayerSpriteControllerSizeCheck[sizeof(PlayerSpriteController) == 0x284 ? 1 : -1];
typedef char PlayerSpriteControllerSpriteCheck[offsetof(PlayerSpriteController, held_actor_sprite) == 0x8C ? 1 : -1];
typedef char PlayerSpriteControllerSlotsCheck[offsetof(PlayerSpriteController, slots) == 0xCC ? 1 : -1];
typedef char PlayerSpriteControllerSlotIndexCheck[offsetof(PlayerSpriteController, next_slot) == 0x280 ? 1 : -1];
typedef char PlayerSpriteControllerFlagCheck[offsetof(PlayerSpriteController, unk_281) == 0x281 ? 1 : -1];

#endif // PLAYER_SPRITE_HH
