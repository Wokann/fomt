#ifndef ENTITY_ACTOR_HH
#define ENTITY_ACTOR_HH

#include "prelude.h"

#include "entity.hh"

struct UnkActorEntity28
{
    UnkActorEntity28();

    /* +00 */ u32 unk_00;
};

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

struct AActorEntity : public AEntity
{
    AActorEntity(GameObject * game_object, ActorLocation const & location, u32 arg_2, u32 arg_3);

    /* vt+34 */ virtual u32 vfunc_34();
    /* vt+38 */ virtual void SetEventScript(MaryScriptId script_id);

    bool IsOnCurrentMap() const SECTION(".text.entity_actor_movement");
    void SetMovementSpeed(i32 speed_q16) SECTION(".text.entity_actor_movement");
    bool IsAnimationComplete() const SECTION(".text.entity_actor_animation_complete");
    void ApplyMovement(ActorMovementBounds * bounds) SECTION(".text.entity_actor_apply_movement");

    void SetLocation(ActorLocation const & location);
    ActorLocation GetLocation() const;
    void SetAnimFacing(u32 facing);
    void SetAnim(u32 anim);
    void RefreshSprite(u32 sprite_anim);
    void method_08032208();

    /* +18 */ u32 x_speed_q16;
    /* +1C */ u32 y_speed_q16;
    /* +20 */ u8 facing;
    /* +21 */ u8 unk_21; // Default OBJ priority; rendering uses its low two bits.
    /* +22 */ u16 anim_id;
    /* +24 */ u16 unk_24;
    /* +26 */ u16 unk_26;
    /* +28 */ UnkActorEntity28 unk_28;
    /* +2C */ u16 unk_2C;
    /* +2E */ u8 unk_2E;
};

// These native movement commands take an integer target and raw Q16.16
// speed. A new axis command replaces the actor's previous movement command.
EXTERN_C
void func_08032308(AActorEntity & self, u32 target, i32 speed_q16);
void func_0803233C(AActorEntity & self, u32 target, i32 speed_q16);
void func_08032384(AActorEntity & self, u32 effect, bool persistent);
void func_080323C8(AActorEntity & self);
void func_080323E0(AActorEntity & self, u32 profile);
EXTERN_C_END

#endif // ENTITY_ACTOR_HH
