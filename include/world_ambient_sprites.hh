#ifndef WORLD_AMBIENT_SPRITES_HH
#define WORLD_AMBIENT_SPRITES_HH

#include "prelude.h"
#include "entity.hh"
#include "scene_sprite_indexed.hh"
#include "scene_sprite_group.hh"
#include "smart_ptr.hh"
#include "world_ambient_types.hh"
#include "random.hh"
#include "actor_movement.hh"
#include <stdlib.h>
#include "world_ambient_entity_factory.hh"
#include "world_ambient_animation.hh"

#pragma interface "world_ambient_sprites.hh"

struct GameObject;


struct WorldSpriteDrawBuffer;
struct HardwareDmaQueue;

struct WorldAmbientSpriteController : EntityVisualController {
    typedef WorldAmbientSpriteOwners::Owner SpriteOwner;

    inline WorldAmbientSpriteController(WorldAmbientEntity * owner);
    inline WorldAmbientSpriteController(WorldAmbientEntity * owner, GameStateActorRecord * saved);
    virtual ~WorldAmbientSpriteController();
    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    inline SpriteOwner * Data();
    inline SpriteOwner * End();

    /* +08 */ WorldAmbientSpriteOwners sprites;
};

// The base owns the indexed animation and an optional secondary group.
// The three pure virtual slots are supplied by the concrete ambient kinds.
struct WorldAmbientSprite {
    WorldAmbientSprite(GameObject * world, u32 animation, u32 secondary_sprite_flag);
    /* vt+08 */ virtual ~WorldAmbientSprite();
    /* vt+0C */ virtual void Update() = 0;
    /* vt+10 */ virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue) = 0;
    /* vt+14 */ virtual void SaveState(GameStateActorRecord & record) const = 0;

    /* +00 */ GameObject * world;
    /* +04 */ u16 animation;
    /* +08 */ GameSceneIndexedSprite sprite;
    /* +48 */ SmartPtr<GameSceneGroupSprite> secondary_sprite;
    /* +4C */ // vtable
};


EXTERN_C

void DrawWorldAmbientSprite(WorldAmbientSprite * self, GameObject * world,
    WorldSpriteDrawBuffer * buffer, HardwareDmaQueue * queue,
    i32 x, i32 y, i32 vertical_offset, u32 flags);
u32 SelectWorldAmbientSpawnPosition(WorldAmbientSprite * self,
    WorldAmbientMotion * motion, i8 position_index);
// Native callers test the complete r0 result, not a byte-sized bool.
u32 UpdateWorldAmbientMotion(WorldAmbientSprite * self,
    WorldAmbientMotion * motion, i32 speed_q16);
i32 GetWorldAmbientSpriteSine(WorldAmbientSprite const * self, i16 phase);
i32 GetWorldAmbientSpriteCosine(WorldAmbientSprite const * self, i16 phase);
void PlayWorldAmbientSpriteSound(WorldAmbientSprite * self, u32 song_id);
void PopulateWorldAmbientSprites(WorldAmbientSpriteController * controller,
    GameObject * world, u32 season, u8 nighttime);

EXTERN_C_END

// Shared by the standalone animation entry and the inlined kind updates.
static inline void ApplyWorldAmbientSpriteAnimation(WorldAmbientSprite * self, u32 index)
{
    if (self->animation != index) {
        self->sprite.SetAnimation(index);
        self->animation = index;
    }
}

// Kind numbers are the native saved-record discriminator, not species names.
// Species/resource identities are still unconfirmed. Each is a distinct
// concrete type with the original virtual interface and instance layout.
struct WorldAmbientKind1 : WorldAmbientSprite {
    enum { KIND = 1 };
    WorldAmbientKind1(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind1(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        if (UpdateWorldAmbientMotion(this, &motion, 0x8000)) {
            if (motion.state == 0) {
                u32 index = 0x9B6 + motion.direction;
                if (animation != index) {
                    sprite.SetAnimation(index);
                    animation = index;
                }
            } else {
                u32 index = 0x9BA + motion.direction;
                if (animation != index) {
                    sprite.SetAnimation(index);
                    animation = index;
                }
            }
        }
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind2 : WorldAmbientSprite {
    enum { KIND = 2 };
    WorldAmbientKind2(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind2(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        if (UpdateWorldAmbientMotion(this, &motion, 0x8000)) {
            u32 index = 0x10 + motion.direction;
            if (animation != index) {
                sprite.SetAnimation(index);
                animation = index;
            }
        }
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 8, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind3 : WorldAmbientSprite {
    enum { KIND = 3 };
    WorldAmbientKind3(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind3(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        if (UpdateWorldAmbientMotion(this, &motion, 0x4000)) {
            u32 index = 0x3DB + motion.direction;
            if (animation != index) {
                sprite.SetAnimation(index);
                animation = index;
            }
        }
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 8, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind4 : WorldAmbientSprite {
    enum { KIND = 4 };
    WorldAmbientKind4(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind4(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        if (UpdateWorldAmbientMotion(this, &motion, 0x2000)) {
            u32 index = 0x806 + motion.direction;
            if (animation != index) {
                sprite.SetAnimation(index);
                animation = index;
            }
        }
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind5 : WorldAmbientSprite {
    enum { KIND = 5 };
    WorldAmbientKind5(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind5(GameObject * world, i32 x, i32 y);
    virtual NAKED void Update()
    {
        asm_unified(
            "    push {r4, r5, r6, r7, lr}\n"
            "    mov r7, r9\n"
            "    mov r6, r8\n"
            "    push {r6, r7}\n"
            "    adds r6, r0, #0\n"
            "    adds r5, r6, #0\n"
            "    adds r5, #98\n"
            "    movs r4, #0\n"
            "    ldrsb r4, [r5, r4]\n"
            "    cmp r4, #1\n"
            "    beq .Lambient_4_5\n"
            "    cmp r4, #1\n"
            "    bgt .Lambient_4_0\n"
            "    cmp r4, #0\n"
            "    beq .Lambient_4_2\n"
            "    adds r4, r6, #0\n"
            "    adds r4, #96\n"
            "    movs r0, #71\n"
            "    adds r0, r0, r6\n"
            "    mov r8, r0\n"
            "    b .Lambient_4_13\n"
            ".Lambient_4_0:\n"
            "    cmp r4, #2\n"
            "    bne .Lambient_4_1\n"
            "    b .Lambient_4_11\n"
            ".Lambient_4_1:\n"
            "    adds r4, r6, #0\n"
            "    adds r4, #96\n"
            "    movs r1, #71\n"
            "    adds r1, r1, r6\n"
            "    mov r8, r1\n"
            "    b .Lambient_4_13\n"
            ".Lambient_4_2:\n"
            "    bl rand\n"
            "    asrs r0, r0, #8\n"
            "    movs r1, #1\n"
            "    ands r0, r1\n"
            "    adds r0, #1\n"
            "    strb r0, [r5, #0]\n"
            "    adds r5, r0, #0\n"
            "    cmp r5, #1\n"
            "    bne .Lambient_4_3\n"
            "    movs r0, #4\n"
            "    bl RandomBelow\n"
            "    lsls r0, r0, #8\n"
            "    movs r2, #128\n"
            "    lsls r2, r2, #1\n"
            "    adds r0, r0, r2\n"
            "    adds r4, r6, #0\n"
            "    adds r4, #96\n"
            "    strh r0, [r4, #0]\n"
            "    bl rand\n"
            "    asrs r0, r0, #8\n"
            "    ands r0, r5\n"
            "    lsls r0, r0, #11\n"
            "    adds r1, r6, #0\n"
            "    adds r1, #100\n"
            "    strh r0, [r1, #0]\n"
            "    b .Lambient_4_4\n"
            ".Lambient_4_3:\n"
            "    movs r0, #2\n"
            "    bl RandomBelow\n"
            "    lsls r1, r0, #4\n"
            "    subs r1, r1, r0\n"
            "    lsls r1, r1, #2\n"
            "    adds r1, #180\n"
            "    adds r0, r6, #0\n"
            "    adds r0, #96\n"
            "    strh r1, [r0, #0]\n"
            "    adds r4, r0, #0\n"
            ".Lambient_4_4:\n"
            "    movs r0, #2\n"
            "    bl RandomBelow\n"
            "    lsls r0, r0, #2\n"
            "    adds r0, #12\n"
            "    adds r1, r6, #0\n"
            "    adds r1, #102\n"
            "    strh r0, [r1, #0]\n"
            "    movs r3, #71\n"
            "    adds r3, r3, r6\n"
            "    mov r8, r3\n"
            "    b .Lambient_4_13\n"
            ".Lambient_4_5:\n"
            "    adds r1, r6, #0\n"
            "    adds r1, #100\n"
            "    ldrh r0, [r1, #0]\n"
            "    movs r7, #255\n"
            "    lsls r7, r7, #4\n"
            "    ands r7, r0\n"
            "    mov r9, r1\n"
            "    cmp r7, #0\n"
            "    bne .Lambient_4_7\n"
            "    ldr r5, .Lambient_4_6\n"
            "    ldrh r0, [r6, #4]\n"
            "    movs r1, #71\n"
            "    adds r1, r1, r6\n"
            "    mov r8, r1\n"
            "    cmp r0, r5\n"
            "    beq .Lambient_4_9\n"
            "    adds r0, r6, #0\n"
            "    adds r0, #48\n"
            "    adds r1, r5, #0\n"
            "    bl ResolveIndexedResourceHandle\n"
            "    adds r0, r6, #0\n"
            "    adds r0, #68\n"
            "    strb r4, [r0, #0]\n"
            "    adds r0, #2\n"
            "    strb r7, [r0, #0]\n"
            "    mov r2, r8\n"
            "    strb r4, [r2, #0]\n"
            "    b .Lambient_4_8\n"
            "    .align 2, 0\n"
            ".Lambient_4_6: .word 0x00000205\n"
            ".Lambient_4_7:\n"
            "    movs r0, #128\n"
            "    lsls r0, r0, #4\n"
            "    movs r3, #71\n"
            "    adds r3, r3, r6\n"
            "    mov r8, r3\n"
            "    cmp r7, r0\n"
            "    bne .Lambient_4_9\n"
            "    movs r5, #129\n"
            "    lsls r5, r5, #2\n"
            "    ldrh r0, [r6, #4]\n"
            "    cmp r0, r5\n"
            "    beq .Lambient_4_9\n"
            "    adds r0, r6, #0\n"
            "    adds r0, #48\n"
            "    adds r1, r5, #0\n"
            "    bl ResolveIndexedResourceHandle\n"
            "    adds r0, r6, #0\n"
            "    adds r0, #68\n"
            "    movs r1, #0\n"
            "    strb r4, [r0, #0]\n"
            "    adds r0, #2\n"
            "    strb r1, [r0, #0]\n"
            "    mov r0, r8\n"
            "    strb r4, [r0, #0]\n"
            ".Lambient_4_8:\n"
            "    strh r5, [r6, #4]\n"
            ".Lambient_4_9:\n"
            "    mov r2, r9\n"
            "    ldrh r1, [r2, #0]\n"
            "    lsls r1, r1, #16\n"
            "    asrs r1, r1, #20\n"
            "    movs r5, #255\n"
            "    ands r1, r5\n"
            "    adds r0, r6, #0\n"
            "    bl GetWorldAmbientSpriteSine\n"
            "    adds r4, r0, #0\n"
            "    lsls r4, r4, #16\n"
            "    asrs r4, r4, #16\n"
            "    mov r3, r9\n"
            "    ldrh r1, [r3, #0]\n"
            "    lsls r1, r1, #16\n"
            "    asrs r1, r1, #20\n"
            "    lsls r1, r1, #1\n"
            "    ands r1, r5\n"
            "    adds r0, r6, #0\n"
            "    bl GetWorldAmbientSpriteCosine\n"
            "    lsls r0, r0, #16\n"
            "    adds r1, r6, #0\n"
            "    adds r1, #102\n"
            "    ldrh r1, [r1, #0]\n"
            "    mov r2, r9\n"
            "    ldrh r2, [r2, #0]\n"
            "    adds r1, r1, r2\n"
            "    mov r3, r9\n"
            "    strh r1, [r3, #0]\n"
            "    lsls r4, r4, #6\n"
            "    ldr r2, [r6, #88]\n"
            "    adds r2, r2, r4\n"
            "    str r2, [r6, #88]\n"
            "    asrs r0, r0, #10\n"
            "    ldr r1, [r6, #92]\n"
            "    adds r1, r1, r0\n"
            "    str r1, [r6, #92]\n"
            "    asrs r2, r2, #16\n"
            "    adds r0, r6, #0\n"
            "    adds r0, #84\n"
            "    strh r2, [r0, #0]\n"
            "    ldr r0, [r6, #92]\n"
            "    asrs r0, r0, #16\n"
            "    adds r1, r6, #0\n"
            "    adds r1, #86\n"
            "    strh r0, [r1, #0]\n"
            "    ldr r1, [r6, #104]\n"
            "    ldr r0, .Lambient_4_10\n"
            "    adds r4, r6, #0\n"
            "    adds r4, #96\n"
            "    cmp r1, r0\n"
            "    bgt .Lambient_4_13\n"
            "    movs r2, #128\n"
            "    lsls r2, r2, #6\n"
            "    adds r0, r1, r2\n"
            "    b .Lambient_4_12\n"
            "    .align 2, 0\n"
            ".Lambient_4_10: .word 0x0007ffff\n"
            ".Lambient_4_11:\n"
            "    ldr r0, [r6, #104]\n"
            "    adds r4, r6, #0\n"
            "    adds r4, #96\n"
            "    movs r3, #71\n"
            "    adds r3, r3, r6\n"
            "    mov r8, r3\n"
            "    cmp r0, #0\n"
            "    ble .Lambient_4_13\n"
            "    ldr r1, .Lambient_4_15\n"
            "    adds r0, r0, r1\n"
            ".Lambient_4_12:\n"
            "    str r0, [r6, #104]\n"
            ".Lambient_4_13:\n"
            "    ldrh r0, [r4, #0]\n"
            "    subs r0, #1\n"
            "    movs r1, #0\n"
            "    strh r0, [r4, #0]\n"
            "    lsls r0, r0, #16\n"
            "    cmp r0, #0\n"
            "    bge .Lambient_4_14\n"
            "    adds r0, r6, #0\n"
            "    adds r0, #98\n"
            "    strb r1, [r0, #0]\n"
            ".Lambient_4_14:\n"
            "    mov r2, r8\n"
            "    ldrb r0, [r2, #0]\n"
            "    cmp r0, #0\n"
            "    bne .Lambient_4_16\n"
            "    adds r0, r6, #0\n"
            "    adds r0, #48\n"
            "    bl UpdateIndexedResourceHandle\n"
            "    lsls r0, r0, #30\n"
            "    cmp r0, #0\n"
            "    bge .Lambient_4_17\n"
            "    adds r1, r6, #0\n"
            "    adds r1, #68\n"
            "    movs r0, #1\n"
            "    strb r0, [r1, #0]\n"
            "    b .Lambient_4_17\n"
            "    .align 2, 0\n"
            ".Lambient_4_15: .word 0xffffe000\n"
            ".Lambient_4_16:\n"
            "    mov r3, r8\n"
            "    strb r1, [r3, #0]\n"
            ".Lambient_4_17:\n"
            "    pop {r3, r4}\n"
            "    mov r8, r3\n"
            "    mov r9, r4\n"
            "    pop {r4, r5, r6, r7}\n"
            "    pop {r0}\n"
            "    bx r0\n"
        );
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, height_q16 >> 16, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
    /* +64 */ i16 phase;
    /* +66 */ i16 phase_step;
    /* +68 */ i32 height_q16;
};


struct WorldAmbientKind6 : WorldAmbientSprite {
    enum { KIND = 6 };
    WorldAmbientKind6(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind6(GameObject * world);
    virtual void Update()
    {
        switch (motion.state) {
        case 0:
            motion.direction_ticks = (RandomBelow(2) + 30) * 60;
            sound_ticks = 0;
            motion.state = 1;
            break;
        case 1:
            if (--motion.direction_ticks < 0) {
                motion.state = 2;
            } else if (motion.direction_ticks > 360) {
                if (--sound_ticks <= 0) {
                    sound_ticks = 360;
                    if ((rand() >> 4) & 3)
                        PlayWorldAmbientSpriteSound(this, 206);
                }
            }
            break;
        case 2: {
            if (next_position == -1)
                next_position = (current_position + 1) & 3;
            SelectWorldAmbientSpawnPosition(this, &target, next_position);
            target.x_q16 = target.x * 65536;
            target.y_q16 = target.y * 65536;
            velocity_x_q16 = target.x_q16 - motion.x_q16;
            velocity_y_q16 = target.y_q16 - motion.y_q16;
            i32 x_velocity = velocity_x_q16;
            i32 y_velocity = velocity_y_q16;
            i32 x_steps = abs(x_velocity) >> 17;
            i32 y_steps = abs(y_velocity) >> 17;
            if (x_steps > y_steps) {
                if (x_velocity < 0)
                    motion.direction = FACING_LEFT;
                else
                    motion.direction = FACING_RIGHT;
                velocity_x_q16 /= x_steps;
                velocity_y_q16 /= x_steps;
                motion.direction_ticks = x_steps;
            } else {
                if (y_velocity < 0)
                    motion.direction = FACING_UP;
                else
                    motion.direction = FACING_DOWN;
                velocity_x_q16 /= y_steps;
                velocity_y_q16 /= y_steps;
                motion.direction_ticks = y_steps;
            }
            ApplyWorldAmbientSpriteAnimation(this, 0x2A9);
            motion.state = 3;
            vertical_offset = 8;
        }
        case 3:
            motion.x_q16 += velocity_x_q16;
            motion.y_q16 += velocity_y_q16;
            if (--motion.direction_ticks <= 0) {
                current_position = next_position;
                next_position = -1;
                motion.x_q16 = target.x_q16;
                motion.y_q16 = target.y_q16;
                motion.state = 0;
                vertical_offset = -8;
                ApplyWorldAmbientSpriteAnimation(this, 0x2A4);
            }
            break;
        }
        motion.x = motion.x_q16 >> 16;
        motion.y = motion.y_q16 >> 16;
        sprite.UpdateAnimation();
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, vertical_offset, 1);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
        record.state.current_position = current_position;
        record.state.next_position = next_position;
    }

    /* +50 */ WorldAmbientMotion motion;
    // Only target X/Y and their Q16 copies are used by this behavior.
    /* +64 */ WorldAmbientMotion target;
    /* +78 */ i8 current_position;
    /* +79 */ i8 next_position;
    /* +7C */ i32 velocity_x_q16;
    /* +80 */ i32 velocity_y_q16;
    /* +84 */ i8 vertical_offset;
    /* +86 */ i16 sound_ticks;
};


struct WorldAmbientKind7 : WorldAmbientSprite {
    enum { KIND = 7 };
    WorldAmbientKind7(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind7(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        if (UpdateWorldAmbientMotion(this, &motion, 0x8000)) {
            if (motion.state == 0) {
                u32 index = 0x877 + motion.direction;
                if (animation != index) {
                    sprite.SetAnimation(index);
                    animation = index;
                }
            } else {
                u32 index = 0x87B + motion.direction;
                if (animation != index) {
                    sprite.SetAnimation(index);
                    animation = index;
                }
            }
        }
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind8 : WorldAmbientSprite {
    enum { KIND = 8 };
    WorldAmbientKind8(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind8(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        if (UpdateWorldAmbientMotion(this, &motion, 0x8000)) {
            if (motion.state == 0) {
                u32 index = 0x658 + motion.direction;
                if (animation != index) {
                    sprite.SetAnimation(index);
                    animation = index;
                }
            } else {
                u32 index = 0x65C + motion.direction;
                if (animation != index) {
                    sprite.SetAnimation(index);
                    animation = index;
                }
            }
        }
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind9 : WorldAmbientSprite {
    enum { KIND = 9 };
    WorldAmbientKind9(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind9(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        GameObject * game = world;
        AEntity * player = game->GetEntity(0);
        if (player != nullptr) {
            i32 player_x = player->GetQ16X() >> 16;
            i32 player_y = player->GetQ16Y() >> 16;
            i32 dx = player_x - motion.x;
            if (dx < 0)
                dx = -dx;
            if (dx < 16) {
                i32 dy = player_y - motion.y;
                if (dy < 0)
                    dy = -dy;
                if (dy < 16) {
                    MapTerrainView terrain = game->GetMapTerrain(0);
                    Box box(motion.x, motion.y, 16, 16);
                    ActorMovementBounds bounds(terrain, box, 32);
                    u32 old_direction = motion.direction;
                    motion.direction = SelectRetreatFacing(motion.x, motion.y,
                        player_x, player_y, bounds, old_direction);
                    if (old_direction != motion.direction || motion.state == 0) {
                        u32 index = 0x8F9 + motion.direction;
                        if (animation != index) {
                            sprite.SetAnimation(index);
                            animation = index;
                        }
                    }
                    motion.state = 1;
                    motion.direction_ticks = 60;
                }
            }
        }
        if (UpdateWorldAmbientMotion(this, &motion, 0x8000)) {
            if (motion.state == 0) {
                u32 index = 0x8F5 + motion.direction;
                if (animation != index) {
                    sprite.SetAnimation(index);
                    animation = index;
                }
            } else {
                u32 index = 0x8F9 + motion.direction;
                if (animation != index) {
                    sprite.SetAnimation(index);
                    animation = index;
                }
            }
        }
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind10 : WorldAmbientSprite {
    enum { KIND = 10 };
    WorldAmbientKind10(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind10(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        if (UpdateWorldAmbientMotion(this, &motion, 0x10000)) {
            u32 index = 0x9A9 + motion.direction;
            if (animation != index) {
                sprite.SetAnimation(index);
                animation = index;
            }
        }
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind11 : WorldAmbientSprite {
    enum { KIND = 11 };
    WorldAmbientKind11(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind11(GameObject * world, i32 x, i32 y);
    virtual void Update()
    {
        switch (motion.state) {
        case 0:
            if ((rand() >> 4) & 3)
                PlayWorldAmbientSpriteSound(this, 0xCF);
            motion.direction_ticks = (RandomBelow(2) + 6) * 60;
            motion.state = 1;
            break;
        case 1:
            if (--motion.direction_ticks < 0)
                motion.state = 0;
            break;
        }
        sprite.UpdateAnimation();
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind12 : WorldAmbientSprite {
    enum { KIND = 12 };
    WorldAmbientKind12(GameObject * world, WorldAmbientSavedState const & state);
    inline WorldAmbientKind12(GameObject * world);
    virtual void Update()
    {
        sprite.UpdateAnimation();
    }
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue)
    {
        DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
    }
    virtual void SaveState(GameStateActorRecord & record) const
    {
        record.kind = KIND;
        record.state.direction = motion.direction;
        record.state.x = motion.x;
        record.state.y = motion.y;
    }

    /* +50 */ WorldAmbientMotion motion;
};



// World slot 84 saves exactly three ambient records. The flag chooses between
// restoring those records and generating a fresh set after vfunc_14.
struct WorldAmbientEntity : AEntity {
    inline WorldAmbientEntity(GameObject * world, GameStateActorRecord * records);

    virtual ~WorldAmbientEntity();
    virtual void vfunc_14();
    virtual EntityVisualController * CreateVisualController();

    /* +18 */ GameStateActorRecord * records;
    /* +1C */ bool restore_saved_records;
};




extern "C" WorldAmbientSpawnPosition const gWorldAmbientSpawnPositions[];
extern "C" i16 const gWorldAmbientSineTable[];
extern "C" WorldAmbientSpawnWeights const gWorldAmbientDaySpawnWeights[];
extern "C" WorldAmbientSpawnWeights const gWorldAmbientNightSpawnWeights[];


#endif // WORLD_AMBIENT_SPRITES_HH
