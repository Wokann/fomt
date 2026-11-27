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

    void SetPosition(i32 x, i32 y, i32 z)
    {
        x_offset = x;
        y_offset = y;
        height = z;
    }

    void SetVelocity(i32 x, i32 y, i32 z)
    {
        x_velocity = x;
        y_velocity = y;
        vertical_velocity = z;
    }

    bool IsVisible() const
    {
        bool visible = false;
        if (this->visible == 1)
            visible = true;
        return visible;
    }

    u8 visible;
    u8 shadow_visible;
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
    void SetItemResourceAndIndex(u32 index);
    void SetActorResource(u32 index);
    void SetItemResource(u32 index);
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




#endif // FARMING_TUTORIAL_PLAYER_HH
