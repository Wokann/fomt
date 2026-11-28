#ifndef PLAYER_ACTOR_HH
#define PLAYER_ACTOR_HH

#include "player_actor_lifetimes.hh"
#include "fishing.hh"

// Verified player actor interface and payload through the update-state byte.
// Native construction and action bodies are retained as assembly in player_actor.cc.
// The concrete payload below remains partial: never allocate it or infer
// its native size. The untouched +0x30 word has unknown declaration ownership.
// The player owns this native catch record; this interface only borrows it.
struct RucksackItem;
struct Article;
struct Food;
struct GameStateSaveImage;
struct Farmer;
// Q16 offsets, planar velocity and vertical motion of the held graphic.
// The native renderer accepts state 1; retain the full stored state byte.
struct PlayerHeldGraphic
{
    u8 state;
    u8 shadow_visible;
    i32 x_offset;
    i32 y_offset;
    i32 x_velocity;
    i32 y_velocity;
    i32 height;
    i32 vertical_velocity;

    void SetPosition(i32 x, i32 y, i32 z)
    {
        x_offset = x;
        y_offset = y;
        height = z;
    }
};

#pragma interface "player_actor.hh"
// Address-only declaration of the native ABI table; calls use PlayerActorBase.

struct PlayerActor : PlayerActorBase {
    virtual Box GetBox() const;
    virtual void vfunc_10();
    virtual void SuspendNormalUpdates();
    virtual void ResumeNormalUpdates();
    // Shadow values other than 0 and 1 leave the existing flag unchanged.
    void SetHeldGraphic(u32 resource_index, i32 shadow);
    void ShowSelectedToolGraphic();
    void RefreshHeldItemGraphic();
    void HideHeldGraphic();
    PlayerHeldGraphic * GetHeldGraphic();
    u32 IsActionTargetEntityId(u32 entity_id) const;
    bool IsOnOverworld() const;
    /* vt+3C */ virtual u8 vfunc_3C() const;
    /* vt+40 */ virtual bool IsRidingHorse() const;
    /* vt+44 */ virtual bool IsHoldingTool();
    /* vt+48 */ virtual bool TryShipHeldItem();
    /* vt+4C */ virtual void ThrowHeldItem();
    /* vt+50 */ virtual void UseHeldItem();
    /* vt+54 */ virtual void ClearHeldItem();
    /* vt+58 */ virtual void EatFood(Food const & food);
    /* vt+5C */ virtual void SetHeldItem(RucksackItem const & item, bool wrapped);
    /* vt+60 */ virtual void GiveBasket();
    /* vt+64 */ virtual bool ChangeStaminaAndFatigue(MaryStaminaDelta stamina_delta,
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
    /* vt+90 */ virtual FishingCatchResult const * GetCaughtFish();
    // Native byte getter at +0xC1; its gameplay role remains unknown.
    /* vt+94 */ virtual u8 vfunc_94() const;
    // World clock guard, distinct from the player update-suspension byte.
    /* vt+98 */ virtual bool IsClockPausedByAction();
    /* vt+9C */ virtual void SetUpdateSuspended(u8 suspended);
    /* vt+A0 */ virtual u8 GetUpdateSuspended() const;
    /* vt+A4 */ virtual void vfunc_A4();
    /* vt+A8 */ virtual void EnterHotSpringBathingState();
    /* vt+AC */ virtual void ExitHotSpringBathingState();
    u32 GetMaxWateringCanCapacity() const;

    u8 unk_30[4];
    GameStateSaveImage * save_image;
    Farmer * farmer;
    bool IsHoldingActorGraphic() const
    {
        u8 const & state = held_graphic.state;
        bool holding = false;
        if (state == 1)
            holding = true;
        return holding;
    }

    u8 action_state;
    u8 unk_3D;
    u8 unk_3E;
    u8 unk_3F[0x60 - 0x3F];
    FishingCatchResult caught_fish;
    u8 unk_78;
    u8 unk_79;
    bool holding_tool;
    u16 unk_7C;
    u8 unk_7E[0x0A];
    PlayerHeldGraphic held_graphic;
    u8 unk_A4;
    u8 unk_A5;
    u16 unk_A6;
    MaryHeldItemKind presented_item_kind;
    i32 presented_item_id;
    bool presented_item_wrapped;
    u8 interacting_animal_index;
    u8 unk_B2[0xC0 - 0xB2];
    u8 unk_C0;
    u8 unk_C1;
    u8 update_suspended;

private:
    PlayerActor();
};

EXTERN_C
// The actual native implementation still serves the player virtual slot.
void PlayerShowHoldingTool(PlayerActor & player, MaryItemToolId tool_id);
EXTERN_C_END

Box GetMountedPlayerBounds(i32 x, i32 y);

struct Tool;

// Crop ids produced by the sowing routine. The original fallback is weeds.
enum SeedCropId {
    SEED_CROP_TURNIP = 0,
    SEED_CROP_POTATO = 1,
    SEED_CROP_CUCUMBER = 2,
    SEED_CROP_STRAWBERRY = 3,
    SEED_CROP_CABBAGE = 4,
    SEED_CROP_TOMATO = 5,
    SEED_CROP_CORN = 6,
    SEED_CROP_ONION = 7,
    SEED_CROP_PUMPKIN = 8,
    SEED_CROP_PINEAPPLE = 9,
    SEED_CROP_EGGPLANT = 10,
    SEED_CROP_CARROT = 11,
    SEED_CROP_SWEET_POTATO = 12,
    SEED_CROP_SPINACH = 13,
    SEED_CROP_GREEN_PEPPER = 14,
    SEED_CROP_MOON_DROP = 15,
    SEED_CROP_PINK_CAT = 16,
    SEED_CROP_MAGIC_BLUE = 17,
    SEED_CROP_MAGIC_RED = 18,
    SEED_CROP_TOY_FLOWER = 19,
    SEED_CROP_GRASS = 20,
    SEED_CROP_WEEDS = 21,
};

EXTERN_C
SeedCropId GetCropForSeed(int tool_id);
u32 AccumulateMaxWateringCanTier(u32 max_tier, Tool const & tool);
EXTERN_C_END

EXTERN_C
void UpdatePlayerPedometer(PlayerActor const & player);
bool IsActorTerrainBlocked(AActorEntity const & actor);
void CheckPlayerCollectionEvents(PlayerActor const & player);
// Front-facing rectangle used by actor interaction and range selection.
// Invalid directions produce the original zero rectangle.
Box GetActorInteractionBounds(AActorEntity const & actor, i32 facing);
EXTERN_C_END

struct EntityUiUnknownTableEntry
{
    u16 unk_00;
    u16 unk_02;
    i8 unk_04;
    i8 unk_05;
    u8 unk_06;
    u8 unk_07;
};

extern "C" char const gText_NotAvailable[];
extern "C" u32 const gUnk_080F0E88[];
extern "C" u32 const gUnk_080F0F78[];
extern "C" u16 const gUnk_080F0FCC[6][7];
extern "C" EntityUiUnknownTableEntry const gUnk_080F1020[6][7];
extern "C" u32 const gUnk_080F1170[];
extern "C" u8 const gUnk_080F1178[];
extern "C" u8 const gUnk_080F117F[];
extern "C" u8 const gUnk_080F1184[];
extern "C" u8 const gUnk_080F118C[];
extern "C" u8 const gUnk_080F1194[];
extern "C" u8 const gUnk_080F119C[];
extern "C" u8 const gUnk_080F11A4[];
extern "C" u8 const gUnk_080F11AC[];
extern "C" u8 const gWateringCanCapacityByTier[];
extern "C" u32 const gSpringMineCollectionProducts[9];
extern "C" u32 const gLakeMineCollectionProducts[14];
extern "C" i32 const gPlayerSpritePaletteKinds[3];
extern "C" i32 const gFarmingTutorialPlayerSpritePaletteKinds[];
extern "C" u8 const gPlayerToolSpiralRanks[][15];

extern char const gCppRuntimeError_AnimalDataSecond[];

#endif // PLAYER_ACTOR_HH
