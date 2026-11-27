#ifndef PLAYER_ACTOR_LIFETIMES_HH
#define PLAYER_ACTOR_LIFETIMES_HH

#include "entity_actor.hh"
#include "utility/vec2.hh"

struct PlayerActor;
struct GameStateSaveImage;
struct RucksackItem;
struct Food;
struct FishingCatchResult;

// Ordinary inline storage helpers do not own out-of-line definitions.

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
    void Push(PlayerSpriteSlot const & slot);
};

// Only complete lifetime interfaces belong to this implementation unit.
// The partial PlayerActor interface retains its existing native ABI table.
#pragma interface "player_actor_lifetimes.hh"
// The native ordinary-player base adds 29 pure virtual operations to AActorEntity.
// Its constructor restores the saved actor location. Unknown byte flags retain
// their slot names until their gameplay meaning is established.
struct PlayerActorBase : AActorEntity {
    PlayerActorBase(GameObject * world, GameStateSaveImage * save);

    /* vt+3C */ virtual u8 vfunc_3C() const = 0;
    /* vt+40 */ virtual bool IsRidingHorse() const = 0;
    /* vt+44 */ virtual bool IsHoldingTool() = 0;
    /* vt+48 */ virtual bool TryShipHeldItem() = 0;
    /* vt+4C */ virtual void ThrowHeldItem() = 0;
    /* vt+50 */ virtual void UseHeldItem() = 0;
    /* vt+54 */ virtual void ClearHeldItem() = 0;
    /* vt+58 */ virtual void EatFood(Food const & food) = 0;
    /* vt+5C */ virtual void SetHeldItem(RucksackItem const & item, bool wrapped) = 0;
    /* vt+60 */ virtual void GiveBasket() = 0;
    /* vt+64 */ virtual bool ChangeStaminaAndFatigue(MaryStaminaDelta stamina_delta,
        MaryFatigueDelta fatigue_delta) = 0;
    /* vt+68 */ virtual void BeginHoldingActorGraphic(u16 animation_id) = 0;
    // Paired player hooks prepare and restore direct script animation control.
    /* vt+6C */ virtual void PrepareForScriptedAnimation() = 0;
    /* vt+70 */ virtual void RestoreAfterScriptedAnimation() = 0;
    /* vt+74 */ virtual void ShowHoldingTool(MaryItemToolId tool_id) = 0;
    /* vt+78 */ virtual MaryAnimalSlotIndex GetInteractingAnimalIndex() = 0;
    /* vt+7C */ virtual void ObtainMysticBerry() = 0;
    /* vt+80 */ virtual void ObtainPowerBerry() = 0;
    /* vt+84 */ virtual MaryHeldItemKind GetPresentedItemKind() = 0;
    /* vt+88 */ virtual i32 GetPresentedItemId() = 0;
    /* vt+8C */ virtual bool IsPresentedItemGiftWrapped() = 0;
    /* vt+90 */ virtual FishingCatchResult const * GetCaughtFish() = 0;
    // Native byte getter at +0xC1; its gameplay role remains unknown.
    /* vt+94 */ virtual u8 vfunc_94() const = 0;
    // World clock guard, distinct from the player update-suspension byte.
    /* vt+98 */ virtual bool IsClockPausedByAction() = 0;
    /* vt+9C */ virtual void SetUpdateSuspended(u8 suspended) = 0;
    /* vt+A0 */ virtual u8 GetUpdateSuspended() const = 0;
    /* vt+A4 */ virtual void vfunc_A4() = 0;
    /* vt+A8 */ virtual void EnterHotSpringBathingState() = 0;
    /* vt+AC */ virtual void ExitHotSpringBathingState() = 0;
};


#pragma interface "player_actor_lifetimes.hh"

// The tutorial script VM addresses these five operations on entity 94.
// Its ordinary player counterpart has a different, larger virtual interface.
struct FarmingTutorialPlayerBase : AActorEntity {
    FarmingTutorialPlayerBase(GameObject * world);

    /* vt+3C */ virtual bool IsActionActive() const = 0;
    /* vt+40 */ virtual void ShowHoldingTool(MaryItemToolId tool_id) = 0;
    /* vt+44 */ virtual void BeginHoldingGraphic(u16 resource_index, bool alternate_archive) = 0;
    /* vt+48 */ virtual void ThrowHeldItem() = 0;
    /* vt+4C */ virtual void UseHeldItem() = 0;
};

#pragma interface "player_actor_lifetimes.hh"
struct PlayerSpriteController : EntitySpriteController {
    PlayerSpriteController(PlayerActor * player);

    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    GameSceneIndexedSprite held_actor_sprite;
    PlayerSpriteSlots slots;
    u8 next_slot;
    u8 unk_281;
};



typedef void (*PlayerActorVTableEntry)();
extern "C" PlayerActorVTableEntry const gPlayerActorVTable[];

#endif // PLAYER_ACTOR_LIFETIMES_HH
