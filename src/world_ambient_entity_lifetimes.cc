#include "world_ambient_construction.hh"
#include "calendar.hh"
#include "time_of_day_types.hh"

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
