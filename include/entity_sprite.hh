#ifndef ENTITY_SPRITE_HH
#define ENTITY_SPRITE_HH

#include "scene_sprite.hh"

struct AEntity;
struct AActorEntity;

// Mode 1 clears at a wrap; mode 2 survives that automatic clear.
enum EntitySpriteEffectMode {
    ENTITY_SPRITE_EFFECT_NONE = 0,
    ENTITY_SPRITE_EFFECT_UNTIL_WRAP = 1,
    ENTITY_SPRITE_EFFECT_PERSISTENT = 2,
};

#pragma interface "entity_sprite.hh"
// The common actor-owned interface. Other entity controllers need not
// contain sprite members. Draw receives the native renderer context;
// its complete type is not recovered yet.
struct EntityVisualController {
    EntityVisualController(AEntity * owner) SECTION(".text.entity_visual_controller_constructor");
    virtual ~EntityVisualController() SECTION(".text.entity_visual_controller_cleanup");
    virtual void Update() = 0;
    virtual void Draw(void * draw_context) = 0;
    AEntity * entity;
};

inline EntityVisualController::EntityVisualController(AEntity * owner) : entity(owner) {}

inline EntityVisualController::~EntityVisualController() {}

// Two independently allocated OBJ resources: the actor animation and
// its attached effect. Virtual Update/Draw bodies remain assembly;
// construction, controls and cleanup use the observed member lifetimes.
struct EntitySpriteController : EntityVisualController {
    EntitySpriteController(AActorEntity * entity, u32 size_shift, u32 palette_kind,
        u32 aux_render_profile, u32 unknown_8A2, u32 unknown_8B, bool sprite_unknown_3D) SECTION(".text.entity_sprite_constructors");
    EntitySpriteController(AActorEntity * entity, u32 size_shift, i32 const * palette_kinds,
        u32 palette_count, u32 aux_render_profile, u32 unknown_8A2, u32 unknown_8B,
        bool sprite_unknown_3D) SECTION(".text.entity_sprite_constructors");

    virtual void Update();
    virtual void Draw(void * draw_context);

    GameSceneIndexedSprite sprite;
    GameSceneIndexedSprite effect;
    u8 aux_render_profile;
    u8 unk_89;
    u8 effect_mode : 2;
    u8 unk_8A_2 : 6;
    u8 unk_8B;

    // The old compiler emits out-of-line inline copies in reverse
    // definition order. Keep these definitions in native ROM order
    // after that compiler traversal, without per-method sections.
    void SetAnimation(u32 index)
    {
        ResolveIndexedResourceHandle(&this->sprite.handle, index);
        this->sprite.unk_3C = 1;
        this->sprite.unk_3E = 0;
        this->sprite.unk_3F = 1;
    }
    void SetUnknown8A2(u32 value)
    {
        this->unk_8A_2 = value;
    }
    void StartEffect(u32 index, bool persistent)
    {
        ResolveIndexedResourceHandle(&this->effect.handle, index);
        this->effect.unk_3C = 1;
        this->effect.unk_3E = 0;
        this->effect.unk_3F = 1;
        this->effect_mode = persistent ? ENTITY_SPRITE_EFFECT_PERSISTENT : ENTITY_SPRITE_EFFECT_UNTIL_WRAP;
    }
    void StopEffect()
    {
        this->effect_mode = ENTITY_SPRITE_EFFECT_NONE;
    }
    // Canonical values are MaryEntityAuxRenderProfile. Native callers
    // store the low byte without validation.
    void SetAuxRenderProfile(u32 profile)
    {
        this->aux_render_profile = profile;
    }
    void SetUnknown89(u32 value)
    {
        this->unk_89 = value;
    }
    void SetUnknown8B(u32 value)
    {
        this->unk_8B = value;
    }
    // Update sets this byte when the primary resource group changes.
    u8 GetFrameChangeFlag() const
    {
        return this->sprite.unk_3C;
    }
    bool IsAnimationPlaying() const
    {
        IndexedResourceHandle const & animation = this->sprite.handle;
        bool playing = false;
        if (animation.metric_scaled != 0)
            playing = animation.scroll_delta != 0;
        return playing;
    }
    // Requires the same valid resolved range as the handle predictor.
    bool WouldAnimationWrap() const
    {
        return WouldIndexedResourceHandleWrap(&this->sprite.handle);
    }
};

// Fixed native preset: size shift 6, palette kind 0x20, default auxiliary
// rendering. No new members or alternate virtual operations.
struct DefaultEntitySpriteController : EntitySpriteController {
    DefaultEntitySpriteController(AActorEntity * entity)
        SECTION(".text.entity_sprite_default_constructor");
};

#pragma implementation

typedef char EntityVisualControllerSizeCheck[sizeof(EntityVisualController) == 8 ? 1 : -1];
typedef char EntitySpriteControllerSizeCheck[sizeof(EntitySpriteController) == 0x8C ? 1 : -1];
typedef char DefaultEntitySpriteControllerSizeCheck[sizeof(DefaultEntitySpriteController) == 0x8C ? 1 : -1];
typedef char EntityVisualControllerOwnerOffset[offsetof(EntityVisualController, entity) == 0 ? 1 : -1];
typedef char EntitySpriteControllerSpriteOffset[offsetof(EntitySpriteController, sprite) == 8 ? 1 : -1];
typedef char EntitySpriteControllerEffectOffset[offsetof(EntitySpriteController, effect) == 0x48 ? 1 : -1];
typedef char EntitySpriteControllerProfileOffset[offsetof(EntitySpriteController, aux_render_profile) == 0x88 ? 1 : -1];
typedef char EntitySpriteControllerUnknown89Offset[offsetof(EntitySpriteController, unk_89) == 0x89 ? 1 : -1];
typedef char EntitySpriteControllerUnknown8BOffset[offsetof(EntitySpriteController, unk_8B) == 0x8B ? 1 : -1];

#endif // ENTITY_SPRITE_HH
