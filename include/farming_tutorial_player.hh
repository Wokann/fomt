#ifndef FARMING_TUTORIAL_PLAYER_HH
#define FARMING_TUTORIAL_PLAYER_HH

#include "player_actor.hh"

// Q16 position, velocity and height of the held or thrown graphic.
struct FarmingTutorialHeldGraphic {
    FarmingTutorialHeldGraphic()
        : visible(false), shadow_visible(false), x_offset(0), y_offset(0),
          x_velocity(0), y_velocity(0), height(0), vertical_velocity(0)
    {
    }

    bool visible;
    bool shadow_visible;
    i32 x_offset;
    i32 y_offset;
    i32 x_velocity;
    i32 y_velocity;
    i32 height;
    i32 vertical_velocity;
};

#pragma interface "farming_tutorial_player.hh"

// Player renderer used by the farming tutorial. The resource index is
// a separate archive selection; 0xFFFF suppresses the extra sprite.
struct FarmingTutorialPlayerSpriteController : EntitySpriteController {
    FarmingTutorialPlayerSpriteController(AActorEntity * entity);
    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    GameSceneIndexedSprite resource_sprite;
    u16 resource_index;
};

struct FarmingTutorialPlayer : FarmingTutorialPlayerBase {
    FarmingTutorialPlayer(GameObject * world);

    virtual void UpdateWhileSuspended(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();
    virtual bool IsActionActive() const;
    virtual void ShowHoldingTool(MaryItemToolId tool_id);
    virtual void BeginHoldingGraphic(u16 resource_index, bool alternate_archive);
    virtual void ThrowHeldItem();
    virtual void UseHeldItem();

    void UpdateAction();
    u32 GetActionAnimation() const;

    // The recovered constructor and action paths leave this word untouched.
    // Its purpose and original base/derived declaration ownership are unknown.
    u32 unk_30;
    u8 action;
    u8 show_tool_countdown;
    FarmingTutorialHeldGraphic graphic;
    bool action_active;
    u16 held_graphic_id;
    bool skip_action_update;
    bool holding_item;
};

EXTERN_C
FarmingTutorialPlayer * CreateFarmingTutorialPlayer(GameObject * world);
EXTERN_C_END

typedef char FarmingTutorialHeldGraphicSizeCheck[sizeof(FarmingTutorialHeldGraphic) == 0x1C ? 1 : -1];
typedef char FarmingTutorialPlayerSizeCheck[sizeof(FarmingTutorialPlayer) == 0x5C ? 1 : -1];
typedef char FarmingTutorialPlayerActionCheck[offsetof(FarmingTutorialPlayer, action) == 0x34 ? 1 : -1];
typedef char FarmingTutorialPlayerGraphicCheck[offsetof(FarmingTutorialPlayer, graphic) == 0x38 ? 1 : -1];
typedef char FarmingTutorialPlayerActiveCheck[offsetof(FarmingTutorialPlayer, action_active) == 0x54 ? 1 : -1];
typedef char FarmingTutorialPlayerHeldGraphicCheck[offsetof(FarmingTutorialPlayer, held_graphic_id) == 0x56 ? 1 : -1];
typedef char FarmingTutorialPlayerSkipUpdateCheck[offsetof(FarmingTutorialPlayer, skip_action_update) == 0x58 ? 1 : -1];
typedef char FarmingTutorialPlayerHoldingCheck[offsetof(FarmingTutorialPlayer, holding_item) == 0x59 ? 1 : -1];

typedef char FarmingTutorialPlayerSpriteSizeCheck[sizeof(FarmingTutorialPlayerSpriteController) == 0xD0 ? 1 : -1];
typedef char FarmingTutorialPlayerSpriteResourceCheck[offsetof(FarmingTutorialPlayerSpriteController, resource_sprite) == 0x8C ? 1 : -1];
typedef char FarmingTutorialPlayerSpriteIndexCheck[offsetof(FarmingTutorialPlayerSpriteController, resource_index) == 0xCC ? 1 : -1];


#endif // FARMING_TUTORIAL_PLAYER_HH
