#include "world_ambient_construction.hh"
#include "random.hh"
#include "actor_movement.hh"
#include "calendar.hh"
#include "time_of_day_types.hh"
#include <stdlib.h>

asm(".include \"asm/macro.inc\"\n");

inline WorldAmbientKind1::WorldAmbientKind1(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x9B6 + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind2::WorldAmbientKind2(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x10 + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind3::WorldAmbientKind3(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x3DB + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind4::WorldAmbientKind4(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x806 + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind5::WorldAmbientKind5(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x202 + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
    height_q16 = 0;
}

inline WorldAmbientKind6::WorldAmbientKind6(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x2A3 + state.direction, 1)
{
    motion.direction = state.direction;
    next_position = -1;
    // The native restore path reads only the current saved nibble.
    current_position = SelectWorldAmbientSpawnPosition(this, &motion, state.current_position);
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
    vertical_offset = -8;
}

inline WorldAmbientKind7::WorldAmbientKind7(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x87B + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind8::WorldAmbientKind8(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x65C + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind9::WorldAmbientKind9(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x8F9 + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind10::WorldAmbientKind10(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x9A9 + state.direction, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind11::WorldAmbientKind11(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x8FD, 1)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind12::WorldAmbientKind12(GameObject * world,
    WorldAmbientSavedState const & state)
    : WorldAmbientSprite(world, 0x15, 0)
{
    motion.direction = state.direction;
    motion.x = state.x;
    motion.y = state.y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._18WorldAmbientEntity\n"
    "_._18WorldAmbientEntity:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, r9\n"
    "    mov r6, r8\n"
    "    push {r6, r7}\n"
    "    mov r8, r0\n"
    "    mov r9, r1\n"
    "    ldr r0, .Lambient_0_5\n"
    "    mov r1, r8\n"
    "    str r0, [r1, #20]\n"
    "    ldr r0, [r1, #16]\n"
    "    cmp r0, #0\n"
    "    beq .Lambient_0_2\n"
    "    ldr r1, [r1, #24]\n"
    "    movs r6, #0\n"
    "    ldr r7, [r0, #8]\n"
    "    cmp r6, r7\n"
    "    bcs .Lambient_0_2\n"
    "    adds r5, r1, #0\n"
    "    adds r4, r0, #0\n"
    "    adds r4, #12\n"
    ".Lambient_0_0:\n"
    "    ldr r1, [r4, #0]\n"
    "    cmp r1, #0\n"
    "    beq .Lambient_0_1\n"
    "    ldr r0, [r1, #76]\n"
    "    ldr r2, [r0, #20]\n"
    "    adds r0, r1, #0\n"
    "    adds r1, r5, #0\n"
    "    bl _call_via_r2\n"
    ".Lambient_0_1:\n"
    "    adds r5, #16\n"
    "    adds r4, #4\n"
    "    adds r6, #1\n"
    "    cmp r6, r7\n"
    "    bcc .Lambient_0_0\n"
    ".Lambient_0_2:\n"
    "    ldr r0, .Lambient_0_6\n"
    "    mov r2, r8\n"
    "    str r0, [r2, #20]\n"
    "    ldr r1, [r2, #16]\n"
    "    cmp r1, #0\n"
    "    beq .Lambient_0_3\n"
    "    ldr r0, [r1, #4]\n"
    "    ldr r2, [r0, #8]\n"
    "    adds r0, r1, #0\n"
    "    movs r1, #3\n"
    "    bl _call_via_r2\n"
    ".Lambient_0_3:\n"
    "    movs r0, #1\n"
    "    mov r1, r9\n"
    "    ands r0, r1\n"
    "    cmp r0, #0\n"
    "    beq .Lambient_0_4\n"
    "    mov r0, r8\n"
    "    bl __builtin_delete\n"
    ".Lambient_0_4:\n"
    "    pop {r3, r4}\n"
    "    mov r8, r3\n"
    "    mov r9, r4\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    ".Lambient_0_5: .word __vt_18WorldAmbientEntity\n"
    ".Lambient_0_6: .word __vt_7AEntity\n"
);

void WorldAmbientEntity::vfunc_14()
{
    AEntity::vfunc_14();
    restore_saved_records = false;
}

inline WorldAmbientSpriteController::WorldAmbientSpriteController(
    WorldAmbientEntity * owner, GameStateActorRecord * saved)
    : EntityVisualController(owner), sprites()
{
    GameObject * world = owner->GetGameObject();
    for (u32 i = 0; i < WorldAmbientSpriteOwners::CAPACITY; ++i) {
        GameStateActorRecord & record = saved[i];
        switch (record.kind) {
        case WorldAmbientKind1::KIND:
            sprites.Append(new WorldAmbientKind1(world, record.state));
            break;
        case WorldAmbientKind2::KIND:
            sprites.Append(new WorldAmbientKind2(world, record.state));
            break;
        case WorldAmbientKind3::KIND:
            sprites.Append(new WorldAmbientKind3(world, record.state));
            break;
        case WorldAmbientKind4::KIND:
            sprites.Append(new WorldAmbientKind4(world, record.state));
            break;
        case WorldAmbientKind5::KIND:
            sprites.Append(new WorldAmbientKind5(world, record.state));
            break;
        case WorldAmbientKind6::KIND:
            sprites.Append(new WorldAmbientKind6(world, record.state));
            break;
        case WorldAmbientKind7::KIND:
            sprites.Append(new WorldAmbientKind7(world, record.state));
            break;
        case WorldAmbientKind8::KIND:
            sprites.Append(new WorldAmbientKind8(world, record.state));
            break;
        case WorldAmbientKind9::KIND:
            sprites.Append(new WorldAmbientKind9(world, record.state));
            break;
        case WorldAmbientKind10::KIND:
            sprites.Append(new WorldAmbientKind10(world, record.state));
            break;
        case WorldAmbientKind11::KIND:
            sprites.Append(new WorldAmbientKind11(world, record.state));
            break;
        case WorldAmbientKind12::KIND:
            sprites.Append(new WorldAmbientKind12(world, record.state));
            break;
        }
        record.kind = 0;
    }
}

inline WorldAmbientSpriteController::WorldAmbientSpriteController(WorldAmbientEntity * owner)
    : EntityVisualController(owner), sprites()
{
    GameObject * world = owner->GetGameObject();
    u32 hour = world->GetClock()->calendar.time.clock_hour;
    u8 nighttime = hour - 6 > 11;
    PopulateWorldAmbientSprites(this, world,
        GetCalendarEffectiveSeason(world->GetClock()->calendar), nighttime);
}

EntityVisualController * WorldAmbientEntity::CreateVisualController()
{
    WorldAmbientSpriteController * result = nullptr;
    if (restore_saved_records)
        result = new WorldAmbientSpriteController(this, records);
    else
        result = new WorldAmbientSpriteController(this);
    return result;
}

void WorldAmbientKind12::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind12::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
}

void WorldAmbientKind12::Update()
{
    sprite.UpdateAnimation();
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._18WorldAmbientKind12\n"
    "_._18WorldAmbientKind12:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind11::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind11::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
}

void WorldAmbientKind11::Update()
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

asm_unified(
    ".text\n"
    "    thumb_func_start _._18WorldAmbientKind11\n"
    "_._18WorldAmbientKind11:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind10::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind10::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
}

void WorldAmbientKind10::Update()
{
    if (UpdateWorldAmbientMotion(this, &motion, 0x10000)) {
        u32 index = 0x9A9 + motion.direction;
        if (animation != index) {
            sprite.SetAnimation(index);
            animation = index;
        }
    }
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._18WorldAmbientKind10\n"
    "_._18WorldAmbientKind10:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind9::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind9::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
}

void WorldAmbientKind9::Update()
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

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind9\n"
    "_._17WorldAmbientKind9:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind8::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind8::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
}

void WorldAmbientKind8::Update()
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

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind8\n"
    "_._17WorldAmbientKind8:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind7::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind7::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
}

void WorldAmbientKind7::Update()
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

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind7\n"
    "_._17WorldAmbientKind7:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind6::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
    record.state.current_position = current_position;
    record.state.next_position = next_position;
}

void WorldAmbientKind6::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, vertical_offset, 1);
}

void WorldAmbientKind6::Update()
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
        SetAnimation(0x2A9);
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
            SetAnimation(0x2A4);
        }
        break;
    }
    motion.x = motion.x_q16 >> 16;
    motion.y = motion.y_q16 >> 16;
    sprite.UpdateAnimation();
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind6\n"
    "_._17WorldAmbientKind6:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind5::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind5::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, height_q16 >> 16, 2);
}

asm_unified(
    ".text\n"
    "    thumb_func_start Update__17WorldAmbientKind5\n"
    "Update__17WorldAmbientKind5:\n"
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

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind5\n"
    "_._17WorldAmbientKind5:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind4::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind4::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
}

void WorldAmbientKind4::Update()
{
    if (UpdateWorldAmbientMotion(this, &motion, 0x2000)) {
        u32 index = 0x806 + motion.direction;
        if (animation != index) {
            sprite.SetAnimation(index);
            animation = index;
        }
    }
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind4\n"
    "_._17WorldAmbientKind4:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind3::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind3::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 8, 2);
}

void WorldAmbientKind3::Update()
{
    if (UpdateWorldAmbientMotion(this, &motion, 0x4000)) {
        u32 index = 0x3DB + motion.direction;
        if (animation != index) {
            sprite.SetAnimation(index);
            animation = index;
        }
    }
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind3\n"
    "_._17WorldAmbientKind3:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind2::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind2::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 8, 2);
}

void WorldAmbientKind2::Update()
{
    if (UpdateWorldAmbientMotion(this, &motion, 0x8000)) {
        u32 index = 0x10 + motion.direction;
        if (animation != index) {
            sprite.SetAnimation(index);
            animation = index;
        }
    }
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind2\n"
    "_._17WorldAmbientKind2:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientKind1::SaveState(GameStateActorRecord & record) const
{
    record.kind = KIND;
    record.state.direction = motion.direction;
    record.state.x = motion.x;
    record.state.y = motion.y;
}

void WorldAmbientKind1::Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
    HardwareDmaQueue * queue)
{
    DrawWorldAmbientSprite(this, world, buffer, queue, motion.x, motion.y, 0, 2);
}

void WorldAmbientKind1::Update()
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

asm_unified(
    ".text\n"
    "    thumb_func_start _._17WorldAmbientKind1\n"
    "_._17WorldAmbientKind1:\n"
    "    push {lr}\n"
    "    bl _._18WorldAmbientSprite\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
);

void WorldAmbientSpriteController::Draw(EntityDrawContext const & context)
{
    GameObject * world = entity->GetGameObject();
    WorldSpriteDrawBuffer * buffer = context.buffer;
    HardwareDmaQueue * queue = context.queue;
    SpriteOwner * first = Data();
    SpriteOwner * last = End();
    while (first != last) {
        if (first->Get())
            (*first)->Draw(world, buffer, queue);
        ++first;
    }
}

void WorldAmbientSpriteController::Update()
{
    SpriteOwner * first = Data();
    SpriteOwner * last = End();
    while (first != last) {
        if (first->Get())
            (*first)->Update();
        ++first;
    }
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._28WorldAmbientSpriteController\n"
    "_._28WorldAmbientSpriteController:\n"
    "    push {r4, r5, lr}\n"
    "    sub sp, #16\n"
    "    adds r4, r0, #0\n"
    "    adds r5, r1, #0\n"
    "    ldr r0, .Lambient_7_0\n"
    "    str r0, [r4, #4]\n"
    "    ldr r0, [r4, #8]\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, r0, r4\n"
    "    adds r0, #12\n"
    "    str r0, [sp, #4]\n"
    "    adds r0, r4, #0\n"
    "    adds r0, #12\n"
    "    str r0, [sp, #12]\n"
    "    b .Lambient_7_3\n"
    "    .align 2, 0\n"
    ".Lambient_7_0: .word __vt_28WorldAmbientSpriteController\n"
    ".Lambient_7_1:\n"
    "    subs r0, r2, #4\n"
    "    ldr r1, [r0, #0]\n"
    "    cmp r1, #0\n"
    "    beq .Lambient_7_2\n"
    "    ldr r0, [r1, #76]\n"
    "    ldr r2, [r0, #8]\n"
    "    adds r0, r1, #0\n"
    "    movs r1, #3\n"
    "    bl _call_via_r2\n"
    ".Lambient_7_2:\n"
    "    ldr r0, [sp, #4]\n"
    "    subs r0, #4\n"
    "    str r0, [sp, #4]\n"
    ".Lambient_7_3:\n"
    "    ldr r2, [sp, #4]\n"
    "    ldr r0, [sp, #12]\n"
    "    movs r1, #0\n"
    "    cmp r2, r0\n"
    "    bne .Lambient_7_4\n"
    "    movs r1, #1\n"
    ".Lambient_7_4:\n"
    "    cmp r1, #0\n"
    "    beq .Lambient_7_1\n"
    "    ldr r0, .Lambient_7_6\n"
    "    str r0, [r4, #4]\n"
    "    movs r0, #1\n"
    "    ands r0, r5\n"
    "    cmp r0, #0\n"
    "    beq .Lambient_7_5\n"
    "    adds r0, r4, #0\n"
    "    bl __builtin_delete\n"
    ".Lambient_7_5:\n"
    "    add sp, #16\n"
    "    pop {r4, r5}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    ".Lambient_7_6: .word __vt_22EntityVisualController\n"
);
