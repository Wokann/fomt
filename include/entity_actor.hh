#ifndef ENTITY_ACTOR_HH
#define ENTITY_ACTOR_HH

#include "prelude.h"

#include "entity.hh"

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

// Lazily cached pixel-distance limits for an actor collision box.
// The four flag bytes are preserved without assigning an unverified gameplay meaning.
struct ActorMovementBounds
{
    i32 down_limit;
    i32 up_limit;
    i32 left_limit;
    i32 right_limit;
    bool unk_10;
    bool unk_11;
    bool unk_12;
    bool unk_13;
    MapTerrainView terrain;
    Box box;
    i32 max_distance;
    i32 x_probe;
    i32 y_probe;

    ActorMovementBounds()
        : down_limit(0), up_limit(0), left_limit(0), right_limit(0),
          unk_10(false), unk_11(false), unk_12(false), unk_13(false),
          terrain(0, 0, 0), box(0, 0), max_distance(1), x_probe(0), y_probe(0) {}
    static ActorMovementBounds Empty() SECTION(".text.actor_movement_bounds");

    // Clip against another box; a value of 1 also clears the affected probe flags.
    void ClipAgainstBox(Box const & other, u32 clear_flags) SECTION(".text.actor_movement_bounds");

    void RefreshDown() SECTION(".text.actor_movement_bounds");
    void RefreshUp() SECTION(".text.actor_movement_bounds");
    void RefreshLeft() SECTION(".text.actor_movement_bounds");
    void RefreshRight() SECTION(".text.actor_movement_bounds");
    // Probe flags refresh the same lazy cache as their distance getters.
    bool GetDownProbeFlag() {
        if (down_limit > max_distance)
            RefreshDown();
        return unk_10;
    }
    bool GetUpProbeFlag() {
        if (up_limit < -max_distance)
            RefreshUp();
        return unk_11;
    }
    bool GetLeftProbeFlag() {
        if (left_limit < -max_distance)
            RefreshLeft();
        return unk_12;
    }
    bool GetRightProbeFlag() {
        if (right_limit > max_distance)
            RefreshRight();
        return unk_13;
    }

    i32 GetDown() {
        i32 cached = down_limit;
        if (cached > max_distance) {
            RefreshDown();
            return down_limit;
        }
        return cached;
    }
    i32 GetUp() {
        i32 cached = up_limit;
        if (cached < -max_distance) {
            RefreshUp();
            return up_limit;
        }
        return cached;
    }
    i32 GetLeft() {
        i32 cached = left_limit;
        if (cached < -max_distance) {
            RefreshLeft();
            return left_limit;
        }
        return cached;
    }
    i32 GetRight() {
        i32 cached = right_limit;
        if (cached > max_distance) {
            RefreshRight();
            return right_limit;
        }
        return cached;
    }
};

typedef char ActorMovementBoundsSizeCheck[sizeof(ActorMovementBounds) == 0x34 ? 1 : -1];
typedef char ActorMovementBoundsTerrainCheck[offsetof(ActorMovementBounds, terrain) == 0x14 ? 1 : -1];
typedef char ActorMovementBoundsBoxCheck[offsetof(ActorMovementBounds, box) == 0x20 ? 1 : -1];
typedef char ActorMovementBoundsDistanceCheck[offsetof(ActorMovementBounds, max_distance) == 0x28 ? 1 : -1];
typedef char ActorMovementBoundsFlagsCheck[offsetof(ActorMovementBounds, unk_10) == 0x10 ? 1 : -1];
typedef char ActorMovementBoundsXProbeCheck[offsetof(ActorMovementBounds, x_probe) == 0x2C ? 1 : -1];
typedef char ActorMovementBoundsYProbeCheck[offsetof(ActorMovementBounds, y_probe) == 0x30 ? 1 : -1];

#pragma interface "entity_actor.hh"
struct AActorEntity : public AEntity
{
    AActorEntity(GameObject * game_object, ActorLocation const & location, u32 arg_2, u32 arg_3);

    virtual Box GetBox() const;
    // Tick the countdown, then update the owned visual controller.
    virtual void Update(EntityUpdateContext const & context) SECTION(".text.entity_actor_update");
    virtual void UpdateWhileSuspended(EntityUpdateContext const & context);

    /* vt+34 */ virtual u32 vfunc_34() SECTION(".text.entity_actor_default_no_action");
    /* vt+38 */ virtual void SetEventScript(MaryScriptId script_id) SECTION(".text.entity_actor_animation_status");

    bool IsOnCurrentMap() const SECTION(".text.entity_actor_movement");
    void SetMovementSpeed(i32 speed_q16) SECTION(".text.entity_actor_movement");
    bool IsAnimationComplete() const SECTION(".text.entity_actor_animation_complete");
    void ApplyMovement(ActorMovementBounds * bounds) SECTION(".text.entity_actor_apply_movement");

    void SetLocation(ActorLocation const & location);
    ActorLocation GetLocation() const;
    void SetAnimFacing(u32 facing);
    void SetAnim(u32 anim);
    // Resource index combines the base animation and raw facing byte.
    u32 GetAnimationIndex() const SECTION(".text.entity_actor_animation_index");
    u16 GetAnimationCountdown() const SECTION(".text.entity_actor_animation_status");
    bool IsAnimationCountdownZero() const SECTION(".text.entity_actor_animation_status");
    void SetAnimIfChanged(u32 animation) SECTION(".text.entity_actor_animation_status");
    u16 GetAnim() const SECTION(".text.entity_actor_animation_status");
    void RefreshSprite(u32 sprite_anim);
    // Apply ordinary velocity with map-boundary and terrain checks.
    void ApplyWorldMovement();

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

#pragma implementation

EXTERN_C

// Sum the resolved animation's unscaled entry metrics; a null range is empty.
u32 GetActorAnimationDuration(IndexedResourceProvider * resource, u32 index);
// Native movement commands replace the previous command on their axis.
void StartActorXMotion(AActorEntity & self, u32 target, i32 speed_q16);
void StartActorYMotion(AActorEntity & self, u32 target, i32 speed_q16);
// The command is complete exactly when its speed is zero.
bool IsActorAxisMotionComplete(AActorEntity & self);
void StartActorSpriteEffect(AActorEntity & self, u32 effect, bool persistent);
void StopActorSpriteEffect(AActorEntity & self);
void SetActorAuxRenderProfile(AActorEntity & self, u32 profile);
EXTERN_C_END

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

#endif // ENTITY_ACTOR_HH
