#ifndef ENTITY_ACTOR_HH
#define ENTITY_ACTOR_HH

#include "prelude.h"

#include "entity.hh"

struct UnkActorEntity28
{
    UnkActorEntity28();

    /* +00 */ u32 unk_00;
};

struct AActorEntity : public AEntity
{
    AActorEntity(GameObject * game_object, ActorLocation const & location, u32 arg_2, u32 arg_3);

    /* vt+34 */ virtual u32 vfunc_34();
    /* vt+38 */ virtual void SetEventScript(MaryScriptId script_id);

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
