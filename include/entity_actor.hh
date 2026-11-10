#ifndef ENTITY_ACTOR_HH
#define ENTITY_ACTOR_HH

#include "prelude.h"

#include "entity.hh"
#include "scene_sprite_indexed.hh"
#include "actor_movement.hh"

// One axis command at a time. Only speed is initialized by the native constructor.
struct ActorAxisMotion
{
    ActorAxisMotion();

    u32 speed_q16;
    i16 target_pixel;
    u8 axis; // Zero selects X; every nonzero value selects Y.
};

typedef char ActorAxisMotionSizeCheck[sizeof(ActorAxisMotion) == 8 ? 1 : -1];
typedef char ActorAxisMotionTargetCheck[offsetof(ActorAxisMotion, target_pixel) == 4 ? 1 : -1];
typedef char ActorAxisMotionAxisCheck[offsetof(ActorAxisMotion, axis) == 6 ? 1 : -1];

// Mode 1 clears at a wrap; mode 2 survives that automatic clear.
enum EntitySpriteEffectMode {
    ENTITY_SPRITE_EFFECT_NONE = 0,
    ENTITY_SPRITE_EFFECT_UNTIL_WRAP = 1,
    ENTITY_SPRITE_EFFECT_PERSISTENT = 2,
};

struct AActorEntity;

// Two independently allocated OBJ resources: the actor animation and
// its attached effect. Virtual Update/Draw bodies remain assembly;
// construction, controls and cleanup use the observed member lifetimes.
#pragma interface "entity_actor_lifetimes.hh"
struct EntitySpriteController : EntityVisualController {
    EntitySpriteController(AActorEntity * entity, u32 size_shift, u32 palette_kind,
        u32 aux_render_profile, u32 unknown_8A2, u32 unknown_8B, bool sprite_unknown_3D);
    EntitySpriteController(AActorEntity * entity, u32 size_shift, i32 const * palette_kinds,
        u32 palette_count, u32 aux_render_profile, u32 unknown_8A2, u32 unknown_8B,
        bool sprite_unknown_3D);

    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    GameSceneIndexedSprite sprite;
    GameSceneIndexedSprite effect;
    u8 aux_render_profile;
    u8 unk_89;
    u8 effect_mode : 2;
    u8 unk_8A_2 : 6;
    u8 unk_8B;

    void SetAnimation(u32 index);
    void SetUnknown8A2(u32 value);
    void StartEffect(u32 index, bool persistent);
    void StopEffect();
    // Canonical values are MaryEntityAuxRenderProfile. Native callers
    // store the low byte without validation.
    void SetAuxRenderProfile(u32 profile);
    void SetUnknown89(u32 value);
    void SetUnknown8B(u32 value);
    // Update sets this byte when the primary resource group changes.
    u8 GetFrameChangeFlag() const;
    bool IsAnimationPlaying() const;
    // Requires the same valid resolved range as the handle predictor.
    bool WouldAnimationWrap() const;
};

struct AActorEntity : public AEntity
{
    AActorEntity(GameObject * game_object, ActorLocation const & location, u32 arg_2, u32 arg_3);
    virtual ~AActorEntity() {}

    virtual Box GetBox() const;
    // Tick the countdown, then update the owned visual controller.
    virtual void Update(EntityUpdateContext const & context);
    virtual void UpdateWhileSuspended(EntityUpdateContext const & context);

    /* vt+34 */ virtual u32 vfunc_34();
    /* vt+38 */ virtual void SetEventScript(MaryScriptId script_id);

    bool IsOnCurrentMap() const;
    void SetMovementSpeed(i32 speed_q16);
    bool IsAnimationComplete() const;
    void ApplyMovement(ActorMovementBounds * bounds);

    void SetLocation(ActorLocation const & location);
    ActorLocation GetLocation() const;
    void SetAnimFacing(u32 facing);
    void SetAnim(u32 anim);
    // Resource index combines the base animation and raw facing byte.
    u32 GetAnimationIndex() const;
    u16 GetAnimationCountdown() const;
    bool IsAnimationCountdownZero() const;
    void SetAnimIfChanged(u32 animation);
    u16 GetAnim() const;
    void RefreshSprite(u32 sprite_anim);
    // Apply ordinary velocity with map-boundary and terrain checks.
    void ApplyWorldMovement();

    void SetFacingIfChanged(u32 facing);
    u32 GetFacing() const;
    i32 GetYSortKey() const;
    void SetObjPriority(u32 priority);
    u32 GetObjPriority() const;
    void SetYSpeedQ16(i32 speed_q16);
    i32 GetYSpeedQ16() const;
    void SetXSpeedQ16(i32 speed_q16);
    i32 GetXSpeedQ16() const;

    /* +18 */ u32 x_speed_q16;
    /* +1C */ u32 y_speed_q16;
    /* +20 */ u8 facing;
    /* +21 */ u8 unk_21; // Default OBJ priority; rendering uses its low two bits.
    /* +22 */ u16 anim_id;
    /* +24 */ u16 animation_countdown; // Remaining animation-entry metric sum.
    /* +26 */ u16 animation_reload; // Reload value, truncated to the native halfword.
    /* +28 */ ActorAxisMotion motion;
};

typedef char AActorEntitySizeCheck[sizeof(AActorEntity) == 0x30 ? 1 : -1];
typedef char AActorEntityMotionOffsetCheck[offsetof(AActorEntity, motion) == 0x28 ? 1 : -1];

// Fixed native preset: size shift 6, palette kind 0x20, default auxiliary
// rendering. No new members or alternate virtual operations.
struct DefaultEntitySpriteController : EntitySpriteController {
    DefaultEntitySpriteController(AActorEntity * entity);
};

// The world factory indexes four records at runtime state +0x524, one for
// each ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0..3. These are not saved NPC slots.
struct ScriptVisualEffectRecord {
    ActorLocation location;
    u16 animation;
    u16 script_id; // A MaryScriptId stored in the native 16-bit field.
};

struct ScriptVisualEffectActor : AActorEntity {
    ScriptVisualEffectActor(GameObject * world, ScriptVisualEffectRecord * record);
    virtual ~ScriptVisualEffectActor();
    virtual Box GetBox() const;
    virtual EntityVisualController * CreateVisualController();
    virtual u32 vfunc_34(); // Return the script ID from the borrowed record.
    virtual void SetEventScript(MaryScriptId script_id);

    // Destruction writes the current location and base animation back here.
    ScriptVisualEffectRecord * record;
};


EXTERN_C

// Sum the resolved animation's unscaled entry metrics; a null range is empty.
u32 GetActorAnimationDuration(IndexedResourceProvider * resource, u32 index);
u32 func_08032900(u32 map, u32 x, i32 y);
// Native movement commands replace the previous command on their axis.
void StartActorXMotion(AActorEntity & self, u32 target, i32 speed_q16);
void StartActorYMotion(AActorEntity & self, u32 target, i32 speed_q16);
// The command is complete exactly when its speed is zero.
bool IsActorAxisMotionComplete(AActorEntity & self);
void StartActorSpriteEffect(AActorEntity & self, u32 effect, bool persistent);
void StopActorSpriteEffect(AActorEntity & self);
void SetActorAuxRenderProfile(AActorEntity & self, u32 profile);
void func_080323F0(AActorEntity & self, u32 value);
EXTERN_C_END

// The native entry points operate directly on these actor fields. Definitions
// are reversed so the compiler's ordinary inline tail follows the ROM order.
#pragma interface "entity_actor.hh"

inline i32 AActorEntity::GetXSpeedQ16() const { return x_speed_q16; }
inline void AActorEntity::SetXSpeedQ16(i32 speed_q16) { x_speed_q16 = speed_q16; }
inline i32 AActorEntity::GetYSpeedQ16() const { return y_speed_q16; }
inline void AActorEntity::SetYSpeedQ16(i32 speed_q16) { y_speed_q16 = speed_q16; }
inline u32 AActorEntity::GetObjPriority() const { return unk_21; }
inline void AActorEntity::SetObjPriority(u32 priority) { unk_21 = priority; }
inline i32 AActorEntity::GetYSortKey() const { return 0x8000 - (y_q16 >> 16); }
inline u32 AActorEntity::GetFacing() const { return facing; }
inline void AActorEntity::SetFacingIfChanged(u32 new_facing)
{
    if (facing != new_facing)
        SetAnimFacing(new_facing);
}

inline u32 AActorEntity::GetAnimationIndex() const
{
    return anim_id + facing;
}

inline u16 AActorEntity::GetAnim() const
{
    return anim_id;
}

inline void AActorEntity::SetAnimIfChanged(u32 animation)
{
    if (anim_id != animation)
        SetAnim(animation);
}

// Base actors deliberately ignore script assignment; concrete actors override it.
inline void AActorEntity::SetEventScript(MaryScriptId script_id)
{
}

inline bool AActorEntity::IsAnimationCountdownZero() const
{
    bool zero = false;
    if (animation_countdown == 0)
        zero = true;
    return zero;
}

inline u16 AActorEntity::GetAnimationCountdown() const
{
    return animation_countdown;
}

inline void EntitySpriteController::SetAnimation(u32 index)
{
    ResolveIndexedResourceHandle(&this->sprite.handle, index);
    this->sprite.unk_3C = 1;
    this->sprite.unk_3E = 0;
    this->sprite.unk_3F = 1;
}

inline void EntitySpriteController::SetUnknown8A2(u32 value)
{
    this->unk_8A_2 = value;
}

inline void EntitySpriteController::StartEffect(u32 index, bool persistent)
{
    ResolveIndexedResourceHandle(&this->effect.handle, index);
    this->effect.unk_3C = 1;
    this->effect.unk_3E = 0;
    this->effect.unk_3F = 1;
    this->effect_mode = persistent ? ENTITY_SPRITE_EFFECT_PERSISTENT : ENTITY_SPRITE_EFFECT_UNTIL_WRAP;
}

inline void EntitySpriteController::StopEffect()
{
    this->effect_mode = ENTITY_SPRITE_EFFECT_NONE;
}

inline void EntitySpriteController::SetAuxRenderProfile(u32 profile)
{
    this->aux_render_profile = profile;
}

inline void EntitySpriteController::SetUnknown89(u32 value)
{
    this->unk_89 = value;
}

inline void EntitySpriteController::SetUnknown8B(u32 value)
{
    this->unk_8B = value;
}

inline u8 EntitySpriteController::GetFrameChangeFlag() const
{
    return this->sprite.unk_3C;
}

inline bool EntitySpriteController::IsAnimationPlaying() const
{
    IndexedResourceHandle const & animation = this->sprite.handle;
    bool playing = false;
    if (animation.metric_scaled != 0)
        playing = animation.scroll_delta != 0;
    return playing;
}

inline bool EntitySpriteController::WouldAnimationWrap() const
{
    return WouldIndexedResourceHandleWrap(&this->sprite.handle);
}

typedef char EntitySpriteControllerSizeCheck[sizeof(EntitySpriteController) == 0x8C ? 1 : -1];
typedef char DefaultEntitySpriteControllerSizeCheck[sizeof(DefaultEntitySpriteController) == 0x8C ? 1 : -1];
typedef char EntitySpriteControllerSpriteOffset[offsetof(EntitySpriteController, sprite) == 8 ? 1 : -1];
typedef char EntitySpriteControllerEffectOffset[offsetof(EntitySpriteController, effect) == 0x48 ? 1 : -1];
typedef char EntitySpriteControllerProfileOffset[offsetof(EntitySpriteController, aux_render_profile) == 0x88 ? 1 : -1];
typedef char EntitySpriteControllerUnknown89Offset[offsetof(EntitySpriteController, unk_89) == 0x89 ? 1 : -1];
typedef char EntitySpriteControllerUnknown8BOffset[offsetof(EntitySpriteController, unk_8B) == 0x8B ? 1 : -1];
typedef char ScriptVisualEffectRecordSizeCheck[sizeof(ScriptVisualEffectRecord) == 12 ? 1 : -1];
typedef char ScriptVisualEffectAnimationCheck[offsetof(ScriptVisualEffectRecord, animation) == 8 ? 1 : -1];
typedef char ScriptVisualEffectScriptCheck[offsetof(ScriptVisualEffectRecord, script_id) == 10 ? 1 : -1];
typedef char ScriptVisualEffectActorSizeCheck[sizeof(ScriptVisualEffectActor) == 0x34 ? 1 : -1];
typedef char ScriptVisualEffectActorRecordCheck[offsetof(ScriptVisualEffectActor, record) == 0x30 ? 1 : -1];


#include "entity_actor_lifetimes.hh"

struct EntityUiScreenOffset
{
    i16 x;
    i16 y;
};

extern "C" EntityUiScreenOffset const gUnk_080F1328[];


extern "C" char const gCppRuntimeError_EntityUiBeforeOffsets[];

#endif // ENTITY_ACTOR_HH
