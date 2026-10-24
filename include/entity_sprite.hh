#ifndef ENTITY_SPRITE_HH
#define ENTITY_SPRITE_HH

#include "resource_handle.hh"

// Partial actor-owned sprite layout. The native class identity and
// unresolved virtual slots remain unknown; do not infer ownership or
// a complete native allocation size from this borrowed state view.
struct UnknownEntityThingBase
{
    virtual ~UnknownEntityThingBase();
    virtual void vfunc_0C();
    virtual void vfunc_10(u32 dummy);

    /* +00 */ int * dummy;
    /* +04 */ // vtable
};

struct UnknownEntityThing : public UnknownEntityThingBase
{
    /* +08 */ STRUCT_PAD(0x08, 0x30);
    /* +30 */ IndexedResourceHandle sprite_animator;
    /* +44 */ u8 unk_44;
    /* +45 */ u8 unk_45;
    /* +46 */ u8 unk_46;
    /* +47 */ u8 unk_47;

    // The following fields may belong to a derived native sprite class.

    /* +48 */ STRUCT_PAD(0x48, 0x70);

    /* +70 */ IndexedResourceHandle sprite_animator_70;
    /* +84 */ u8 unk_84;
    /* +85 */ STRUCT_PAD(0x85, 0x86);
    /* +86 */ u8 unk_86;
    /* +87 */ u8 unk_87;
    /* +88 */ u8 unk_88;
    /* +89 */ STRUCT_PAD(0x89, 0x8A);
    /* +8A */ u8 unk_8A_0 : 2;
    /* +8A */ u8 unk_8A_2 : 6;
};

typedef char EntitySpriteAnimationOffsetCheck[offsetof(UnknownEntityThing, sprite_animator) == 0x30 ? 1 : -1];
typedef char EntitySecondSpriteAnimationOffsetCheck[offsetof(UnknownEntityThing, sprite_animator_70) == 0x70 ? 1 : -1];

EXTERN_C

// Neither query changes the animation. Wrap prediction requires the
// same valid resolved entry range as WouldIndexedResourceHandleWrap.
bool WouldEntitySpriteAnimationWrap(UnknownEntityThing const * sprite);
// A zero metric or a zero signed traversal step means stopped.
bool IsEntitySpriteAnimationPlaying(UnknownEntityThing const * sprite);

EXTERN_C_END

#endif // ENTITY_SPRITE_HH
