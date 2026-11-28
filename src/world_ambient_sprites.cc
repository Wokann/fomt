#include "world_ambient_construction.hh"
#include "game_object.hh"
#include "game_scene_actions.hh"
#include "actor_movement.hh"
#include "calendar.hh"
#include "random.hh"
#include <new>

WorldAmbientSprite::WorldAmbientSprite(GameObject * world, u32 animation,
    u32 secondary_sprite_flag)
    : world(world), animation(animation),
      sprite(world->vfunc_68(), animation, world, 3, 27, false),
      secondary_sprite(secondary_sprite_flag == 1
          ? new GameSceneGroupSprite(world->vfunc_68(), 0x91A, world, 2, 15)
          : nullptr)
{
}

WorldAmbientSprite::~WorldAmbientSprite()
{
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "\n"
    "\n"
    "    thumb_func_start DrawWorldAmbientSprite\n"
    "DrawWorldAmbientSprite:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #72\t@ 0x48\n"
    "    mov\tsl, r0\n"
    "    adds\tr4, r1, #0\n"
    "    mov\tr9, r2\n"
    "    mov\tr8, r3\n"
    "    ldr\tr5, [sp, #104]\t@ 0x68\n"
    "    ldr\tr6, [sp, #108]\t@ 0x6c\n"
    "    ldr\tr7, [sp, #112]\t@ 0x70\n"
    "    ldr\tr0, [r4, #0]\n"
    "    ldr\tr1, [r0, #24]\n"
    "    adds\tr0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    subs\tr5, r5, r0\n"
    "    str\tr5, [sp, #60]\t@ 0x3c\n"
    "    ldr\tr0, [r4, #0]\n"
    "    ldr\tr1, [r0, #28]\n"
    "    adds\tr0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    subs\tr0, r6, r0\n"
    "    str\tr0, [sp, #64]\t@ 0x40\n"
    "    movs\tr0, #128\t@ 0x80\n"
    "    lsls\tr0, r0, #8\n"
    "    subs\tr0, r0, r6\n"
    "    str\tr0, [sp, #68]\t@ 0x44\n"
    "    add\tr0, sp, #52\t@ 0x34\n"
    "    mov\tr1, r8\n"
    "    str\tr1, [sp, #52]\t@ 0x34\n"
    "    mov\tr3, r9\n"
    "    str\tr3, [r0, #4]\n"
    "    adds\tr5, r7, #0\n"
    "    mov\tr9, r0\n"
    "    cmp\tr5, #0\n"
    "    bge .Lambient_8\n"
    "    negs\tr7, r5\n"
    ".Lambient_8:\n"
    "    ldr\tr4, [sp, #64]\t@ 0x40\n"
    "    subs\tr4, r4, r7\n"
    "    mov\tr8, r4\n"
    "    mov\tr6, sl\n"
    "    adds\tr6, #8\n"
    "    movs\tr0, #3\n"
    "    ldr\tr7, [sp, #116]\t@ 0x74\n"
    "    ands\tr0, r7\n"
    "    lsls\tr4, r0, #2\n"
    "    orrs\tr4, r0\n"
    "    lsls\tr1, r0, #4\n"
    "    orrs\tr4, r1\n"
    "    lsls\tr0, r0, #6\n"
    "    orrs\tr4, r0\n"
    "    mov\tr0, sl\n"
    "    ldr\tr1, [r0, #48]\t@ 0x30\n"
    "    ldr\tr3, [r1, #0]\n"
    "    ldrh\tr2, [r0, #60]\t@ 0x3c\n"
    "    lsls\tr2, r2, #2\n"
    "    ldr\tr0, [r0, #52]\t@ 0x34\n"
    "    adds\tr0, r0, r2\n"
    "    ldrh\tr2, [r0, #0]\n"
    "    add\tr0, sp, #20\n"
    "    ldr\tr3, [r3, #16]\n"
    "    bl _call_via_r3\n"
    "    add\tr7, sp, #20\n"
    "    mov\tr1, r9\n"
    "    ldr\tr1, [r1, #4]\n"
    "    mov\tip, r1\n"
    "    mov\tr3, sl\n"
    "    ldr\tr2, [r3, #8]\n"
    "    ldr\tr1, [r3, #16]\n"
    "    negs\tr0, r1\n"
    "    orrs\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    bge .Lambient_10\n"
    "    ldrh\tr0, [r6, #12]\n"
    "    mov\tr1, sl\n"
    "    adds\tr1, #24\n"
    "    ldr\tr3, [sp, #68]\t@ 0x44\n"
    "    str\tr3, [sp, #0]\n"
    "    adds\tr3, r7, #0\n"
    "    str\tr3, [sp, #4]\n"
    "    str\tr2, [sp, #8]\n"
    "    str\tr0, [sp, #12]\n"
    "    str\tr1, [sp, #16]\n"
    "    mov\tr0, ip\n"
    "    ldr\tr1, [sp, #60]\t@ 0x3c\n"
    "    mov\tr2, r8\n"
    "    adds\tr3, r4, #0\n"
    "    ldr r4, .Lambient_9\n"
    "    bl _call_via_r4\n"
    "    b .Lambient_11\n"
    ".Lambient_9: .word SubmitWorldSpriteRecords\n"
    ".Lambient_10:\n"
    "    movs\tr0, #0\n"
    ".Lambient_11:\n"
    "    cmp\tr0, #0\n"
    "    beq .Lambient_14\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    mov\tr8, r0\n"
    "    cmp\tr1, #0\n"
    "    beq .Lambient_14\n"
    "    ldr\tr1, [sp, #52]\t@ 0x34\n"
    "    adds\tr2, r7, #0\n"
    "    adds\tr2, #8\n"
    "    adds\tr0, r6, #0\n"
    "    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .Lambient_12\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr1, #16\n"
    "    adds\tr0, r6, #0\n"
    "    movs\tr2, #1\n"
    "    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc\n"
    "    b .Lambient_13\n"
    ".Lambient_12:\n"
    "    adds\tr4, r6, #0\n"
    "    adds\tr4, #62\t@ 0x3e\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lambient_13\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr1, #16\n"
    "    adds\tr0, r6, #0\n"
    "    movs\tr2, #1\n"
    "    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc\n"
    "    movs\tr0, #1\n"
    "    strb\tr0, [r4, #0]\n"
    ".Lambient_13:\n"
    "    movs\tr0, #0\n"
    "    mov\tr4, r8\n"
    "    strb\tr0, [r4, #0]\n"
    ".Lambient_14:\n"
    "    mov\tr7, sl\n"
    "    ldr\tr0, [r7, #72]\t@ 0x48\n"
    "    cmp\tr0, #0\n"
    "    beq .Lambient_18\n"
    "    cmp\tr5, #0\n"
    "    blt .Lambient_18\n"
    "    adds\tr6, r0, #0\n"
    "    mov\tr5, r9\n"
    "    movs\tr0, #3\n"
    "    ldr\tr1, [sp, #116]\t@ 0x74\n"
    "    ands\tr0, r1\n"
    "    lsls\tr3, r0, #2\n"
    "    orrs\tr3, r0\n"
    "    lsls\tr1, r0, #4\n"
    "    orrs\tr3, r1\n"
    "    lsls\tr0, r0, #6\n"
    "    orrs\tr3, r0\n"
    "    adds\tr7, r6, #0\n"
    "    adds\tr7, #40\t@ 0x28\n"
    "    ldr\tr4, [r5, #4]\n"
    "    mov\tr8, r4\n"
    "    adds\tr0, r6, #0\n"
    "    ldmia\tr0!, {r2}\n"
    "    ldr\tr1, [r0, #4]\n"
    "    negs\tr0, r1\n"
    "    orrs\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    bge .Lambient_16\n"
    "    ldrh\tr0, [r6, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #16\n"
    "    ldr\tr4, [sp, #68]\t@ 0x44\n"
    "    str\tr4, [sp, #0]\n"
    "    str\tr7, [sp, #4]\n"
    "    str\tr2, [sp, #8]\n"
    "    str\tr0, [sp, #12]\n"
    "    str\tr1, [sp, #16]\n"
    "    mov\tr0, r8\n"
    "    ldr\tr1, [sp, #60]\t@ 0x3c\n"
    "    ldr\tr2, [sp, #64]\t@ 0x40\n"
    "    ldr r4, .Lambient_15\n"
    "    bl _call_via_r4\n"
    "    b .Lambient_17\n"
    "    .align 2, 0\n"
    ".Lambient_15: .word SubmitWorldSpriteRecords\n"
    ".Lambient_16:\n"
    "    movs\tr0, #0\n"
    ".Lambient_17:\n"
    "    cmp\tr0, #0\n"
    "    beq .Lambient_18\n"
    "    adds\tr4, r6, #0\n"
    "    adds\tr4, #72\t@ 0x48\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .Lambient_18\n"
    "    ldr\tr1, [r5, #0]\n"
    "    adds\tr2, r7, #0\n"
    "    adds\tr2, #8\n"
    "    adds\tr0, r6, #0\n"
    "    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr1, #16\n"
    "    adds\tr0, r6, #0\n"
    "    movs\tr2, #1\n"
    "    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r4, #0]\n"
    ".Lambient_18:\n"
    "    add\tsp, #72\t@ 0x48\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"

);

u32 SelectWorldAmbientSpawnPosition(WorldAmbientSprite * self,
    WorldAmbientMotion * motion, i8 position_index)
{
    if (position_index < 0)
        position_index = RandomBelow(3);
    motion->x = gWorldAmbientSpawnPositions[2 * position_index];
    motion->y = gWorldAmbientSpawnPositions[2 * position_index + 1];
    return position_index;
}


u32 UpdateWorldAmbientMotion(WorldAmbientSprite * self,
    WorldAmbientMotion * motion, i32 speed_q16)
{
    u32 changed = 0;
    MapTerrainView const & terrain = self->world->GetMapTerrain(0);
    ActorMovementBounds limits(terrain, Box(motion->x, motion->y, 16, 16), 32);
    switch (motion->state) {
    case 0:
        break;
    case 1:
        switch (static_cast<i32>(motion->direction)) {
        case FACING_DOWN:
            if (limits.GetDown() > 1)
                motion->y_q16 += speed_q16;
            else
                motion->direction_ticks = 0;
            break;
        case FACING_UP:
            if (limits.GetUp() < -1)
                motion->y_q16 -= speed_q16;
            else
                motion->direction_ticks = 0;
            break;
        case FACING_LEFT:
            if (limits.GetLeft() < -1)
                motion->x_q16 -= speed_q16;
            else
                motion->direction_ticks = 0;
            break;
        case FACING_RIGHT:
            if (limits.GetRight() > 1) {
                motion->x_q16 += speed_q16;
                if ((motion->x_q16 >> 16) > 580) {
                    motion->x_q16 = 580 * 0x10000;
                    motion->direction_ticks = 0;
                }
            } else
                motion->direction_ticks = 0;
            break;
        default:
            motion->direction_ticks = 0;
            break;
        }
        break;
    }
    motion->x = motion->x_q16 >> 16;
    motion->y = motion->y_q16 >> 16;
    self->sprite.UpdateAnimation();
    if (--motion->direction_ticks < 0) {
        i16 relative = RandomBelow(3);
        if (relative == 3)
            motion->state = 0;
        else {
            motion->state = 1;
            motion->direction = GetRelativeFacing(motion->direction, relative);
        }
        motion->direction_ticks = RandomBelow(31) + 16;
        changed = 1;
    }
    return changed;
}

i32 GetWorldAmbientSpriteSine(WorldAmbientSprite const * self, i16 phase)
{
    return gWorldAmbientSineTable[phase];
}

i32 GetWorldAmbientSpriteCosine(WorldAmbientSprite const * self, i16 phase)
{
    return gWorldAmbientSineTable[(phase + 64) & 0xFF];
}

void PlayWorldAmbientSpriteSound(WorldAmbientSprite * self, u32 song_id)
{
    GameSceneSongPlayerPool const & pool = self->world->GetSongPlayerPool();
    FindActorSoundPlayer(pool)->Start(static_cast<u16>(song_id));
}

inline WorldAmbientKind1::WorldAmbientKind1(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x9B6, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind2::WorldAmbientKind2(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x10, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind3::WorldAmbientKind3(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x3DB, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind4::WorldAmbientKind4(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x806, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind5::WorldAmbientKind5(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x202, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
    height_q16 = 0;
}

inline WorldAmbientKind6::WorldAmbientKind6(GameObject * world)
    : WorldAmbientSprite(world, 0x2A4, 1)
{
    motion.direction = FACING_DOWN;
    current_position = SelectWorldAmbientSpawnPosition(this, &motion, -1);
    next_position = -1;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
    vertical_offset = -8;
}

inline WorldAmbientKind7::WorldAmbientKind7(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x87B, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind8::WorldAmbientKind8(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x65C, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind9::WorldAmbientKind9(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x8F9, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind10::WorldAmbientKind10(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x9A9, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind11::WorldAmbientKind11(GameObject * world, i32 x, i32 y)
    : WorldAmbientSprite(world, 0x8FD, 1)
{
    motion.direction = FACING_DOWN;
    motion.x = x;
    motion.y = y;
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

inline WorldAmbientKind12::WorldAmbientKind12(GameObject * world)
    : WorldAmbientSprite(world, 0x15, 0)
{
    motion.direction = FACING_DOWN;
    SelectWorldAmbientSpawnPosition(this, &motion, -1);
    motion.direction_ticks = 0;
    motion.state = 0;
    motion.x_q16 = motion.x * 0x10000;
    motion.y_q16 = motion.y * 0x10000;
}

void PopulateWorldAmbientSprites(WorldAmbientSpriteController * controller,
    GameObject * world, u32 season, u8 nighttime)
{
    WorldAmbientSpawnWeights const * table = gWorldAmbientNightSpawnWeights;
    if (!nighttime)
        table = gWorldAmbientDaySpawnWeights;
    i32 table_count = 4;
    if (!nighttime)
        table_count = 10;
    i16 roll = RandomBelow(99);
    i32 kind = 0;
    i32 count = 0;
    i32 season_index = 0;
    switch (static_cast<i32>(season)) {
    case SEASON_SPRING: season_index = 0; break;
    case SEASON_SUMMER: season_index = 1; break;
    case SEASON_FALL: season_index = 2; break;
    case SEASON_WINTER: season_index = 3; break;
    }
    for (i32 i = 0; i < table_count; ++i) {
        if (roll < table[i].season_weight[season_index]) {
            kind = i;
            count = table[i].count_limit;
            break;
        }
        roll -= table[i].season_weight[season_index];
    }
    if (kind && nighttime)
        kind += 9;
    if (count > 1)
        count = RandomBelow(count - 1) + 1;
    for (; count > 0; --count) {
        i32 x = RandomBelow(392) + 184;
        i32 y;
        if (x <= 239)
            y = RandomBelow(56) + 496;
        else
            y = RandomBelow(48) + 552;
        switch (kind) {
        case WorldAmbientKind1::KIND:
            controller->sprites.Append(new WorldAmbientKind1(world, x, y));
            break;
        case WorldAmbientKind2::KIND:
            controller->sprites.Append(new WorldAmbientKind2(world, x, y));
            break;
        case WorldAmbientKind3::KIND:
            controller->sprites.Append(new WorldAmbientKind3(world, x, y));
            break;
        case WorldAmbientKind4::KIND:
            controller->sprites.Append(new WorldAmbientKind4(world, x, y));
            break;
        case WorldAmbientKind5::KIND:
            controller->sprites.Append(new WorldAmbientKind5(world, x, y));
            break;
        case WorldAmbientKind6::KIND:
            controller->sprites.Append(new WorldAmbientKind6(world));
            break;
        case WorldAmbientKind7::KIND:
            controller->sprites.Append(new WorldAmbientKind7(world, x, y));
            break;
        case WorldAmbientKind8::KIND:
            controller->sprites.Append(new WorldAmbientKind8(world, x, y));
            break;
        case WorldAmbientKind9::KIND:
            controller->sprites.Append(new WorldAmbientKind9(world, x, y));
            break;
        case WorldAmbientKind10::KIND:
            controller->sprites.Append(new WorldAmbientKind10(world, x, y));
            break;
        case WorldAmbientKind11::KIND:
            controller->sprites.Append(new WorldAmbientKind11(world, x, y));
            break;
        case WorldAmbientKind12::KIND:
            controller->sprites.Append(new WorldAmbientKind12(world));
            break;
        }
    }
}

// Interleaved X/Y halfwords, indexed as 2 * position and 2 * position + 1.
extern "C" i16 const gWorldAmbientSpawnPositions[] ALIGN(2) = {
    180, 428,
    164, 652,
    420, 668,
    252, 628,
};

// One signed Q8.8 sine cycle; the cosine lookup advances the index by 64.
extern "C" i16 const gWorldAmbientSineTable[] = {
    0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80, 86, 92,
    97, 103, 109, 115, 120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171, 176,
    181, 185, 189, 193, 197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231, 234,
    236, 238, 241, 243, 244, 246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255,
    256, 255, 255, 255, 254, 254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238,
    236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205, 201, 197, 193, 189, 185,
    181, 176, 171, 167, 162, 157, 152, 147, 142, 136, 131, 126, 120, 115, 109, 103,
    97, 92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12, 6,
    0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62, -68, -74, -80, -86, -92,
    -97, -103, -109, -115, -120, -126, -131, -136, -142, -147, -152, -157, -162, -167, -171, -176,
    -181, -185, -189, -193, -197, -201, -205, -209, -212, -216, -219, -222, -225, -228, -231, -234,
    -236, -238, -241, -243, -244, -246, -248, -249, -251, -252, -253, -254, -254, -255, -255, -255,
    -256, -255, -255, -255, -254, -254, -253, -252, -251, -249, -248, -246, -244, -243, -241, -238,
    -236, -234, -231, -228, -225, -222, -219, -216, -212, -209, -205, -201, -197, -193, -189, -185,
    -181, -176, -171, -167, -162, -157, -152, -147, -142, -136, -131, -126, -120, -115, -109, -103,
    -97, -92, -86, -80, -74, -68, -62, -56, -49, -43, -37, -31, -25, -18, -12, -6,
};

// Native selection currently traverses 10 daytime records and 4 nighttime
// records. Their addresses relocate; changing these counts also requires
// updating the selector, whose implementation still retains those bounds.
extern "C" WorldAmbientSpawnWeights const gWorldAmbientDaySpawnWeights[] ALIGN(1) = {
    { { 40, 20, 30, 60 }, 0 },
    { { 10, 10, 20, 0 }, 1 },
    { { 0, 5, 0, 0 }, 1 },
    { { 0, 0, 30, 0 }, 3 },
    { { 5, 5, 0, 0 }, 3 },
    { { 30, 10, 0, 0 }, 3 },
    { { 0, 30, 0, 0 }, 3 },
    { { 5, 10, 5, 0 }, 1 },
    { { 0, 0, 10, 20 }, 1 },
    { { 10, 10, 5, 20 }, 1 },
};

extern "C" WorldAmbientSpawnWeights const gWorldAmbientNightSpawnWeights[] ALIGN(1) = {
    { { 90, 60, 30, 100 }, 0 },
    { { 10, 15, 0, 0 }, 1 },
    { { 0, 0, 70, 0 }, 3 },
    { { 0, 25, 0, 0 }, 3 },
};

// These independent trailing copies still need their original emitters.
