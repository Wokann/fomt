#ifndef PLAYER_ACTOR_HH
#define PLAYER_ACTOR_HH

#include "entity_actor.hh"

#pragma interface "player_actor.hh"

// Verified player actor interface and payload through the update-state byte.
// The rest of the native player, construction and action bodies remain unrecovered.
// This partial type is never allocated or used to infer the native object size.
// The player owns this native catch record; this interface only borrows it.
struct GameSceneCaughtFish;
struct RucksackItem;
struct Article;
struct Food;
struct GameStateSaveImage;
struct Farmer;
struct PlayerActor : AActorEntity {
    /* vt+3C */ virtual void vfunc_3C();
    /* vt+40 */ virtual bool IsRidingHorse();
    /* vt+44 */ virtual bool IsHoldingTool();
    /* vt+48 */ virtual bool TryShipHeldItem();
    /* vt+4C */ virtual void ThrowHeldItem();
    /* vt+50 */ virtual void UseHeldItem();
    /* vt+54 */ virtual void ClearHeldItem();
    /* vt+58 */ virtual void EatFood(Food const & food);
    /* vt+5C */ virtual void SetHeldItem(RucksackItem const & item, bool wrapped);
    /* vt+60 */ virtual void GiveBasket();
    /* vt+64 */ virtual void ChangeStaminaAndFatigue(MaryStaminaDelta stamina_delta,
        MaryFatigueDelta fatigue_delta);
    /* vt+68 */ virtual void BeginHoldingActorGraphic(u16 animation_id);
    // Paired player hooks prepare and restore direct script animation control.
    /* vt+6C */ virtual void PrepareForScriptedAnimation();
    /* vt+70 */ virtual void RestoreAfterScriptedAnimation();
    /* vt+74 */ virtual void ShowHoldingTool(MaryItemToolId tool_id);
    /* vt+78 */ virtual MaryAnimalSlotIndex GetInteractingAnimalIndex();
    /* vt+7C */ virtual void ObtainMysticBerry();
    /* vt+80 */ virtual void ObtainPowerBerry();
    /* vt+84 */ virtual MaryHeldItemKind GetPresentedItemKind();
    /* vt+88 */ virtual i32 GetPresentedItemId();
    /* vt+8C */ virtual bool IsPresentedItemGiftWrapped();
    /* vt+90 */ virtual GameSceneCaughtFish const * GetCaughtFish();
    // Unrecovered intervening slots are not called by this partial interface.
    /* vt+94 */ virtual void vfunc_94();
    /* vt+98 */ virtual void vfunc_98();
    /* vt+9C */ virtual void SetUpdateSuspended(u8 suspended);
    /* vt+A0 */ virtual u8 GetUpdateSuspended() const;
    /* vt+A4 */ virtual void vfunc_A4();
    /* vt+A8 */ virtual void EnterHotSpringBathingState();
    /* vt+AC */ virtual void ExitHotSpringBathingState();
    u32 GetMaxWateringCanCapacity() const;

    u8 unk_30[4];
    GameStateSaveImage * save_image;
    Farmer * farmer;
    u8 unk_3C[0x86];
    u8 update_suspended;

private:
    PlayerActor();
};
typedef char PlayerActorSaveImageOffsetCheck[offsetof(PlayerActor, save_image) == 0x34 ? 1 : -1];
typedef char PlayerActorFarmerOffsetCheck[offsetof(PlayerActor, farmer) == 0x38 ? 1 : -1];
typedef char PlayerActorBaseSizeCheck[sizeof(AActorEntity) == 0x30 ? 1 : -1];
typedef char PlayerActorUpdateStateOffsetCheck[offsetof(PlayerActor, update_suspended) == 0xC2 ? 1 : -1];

EXTERN_C
// The actual native implementation still serves the player virtual slot.
void PlayerShowHoldingTool(PlayerActor & player, MaryItemToolId tool_id);
EXTERN_C_END

#endif // PLAYER_ACTOR_HH
