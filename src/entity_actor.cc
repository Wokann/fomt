#pragma implementation "entity_actor.hh"

#include "prelude.h"
#include "map_terrain.hh"
#include "entity_actor.hh"

#include <stdlib.h>

#include <new>
#include FOMT_TEXT_INCLUDE(entity_actor.cc)
extern "C" EntityUiScreenOffset const gUnk_080F1328[] ALIGN(1) = {
    { -3, -43 },
    { -3, -43 },
    { -3, -43 },
    { -3, -43 },
    { -3, -37 },
    { -3, -37 },
    { -3, -37 },
    { -3, -37 },
    { -3, -45 },
    { -3, -45 },
    { -3, -45 },
    { -3, -45 },
    { -3, -39 },
    { -3, -39 },
    { -8, -39 },
    { 4, -39 },
    { -3, -34 },
    { -3, -34 },
    { -3, -34 },
    { -3, -34 },
    { 12, -13 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { -6, -26 },
    { -6, -26 },
    { -6, -26 },
    { -6, -26 },
    { -5, -32 },
    { -5, -32 },
    { -5, -32 },
    { -5, -32 },
    { -6, -28 },
    { -6, -28 },
    { -6, -28 },
    { -6, -28 },
    { -5, -29 },
    { -5, -32 },
    { -13, -30 },
    { 1, -30 },
    { -5, -29 },
    { -5, -32 },
    { -11, -32 },
    { -4, -32 },
    { -5, -32 },
    { -5, -36 },
    { -14, -36 },
    { 2, -36 },
    { -4, -33 },
    { -4, -38 },
    { -14, -36 },
    { 5, -36 },
    { -4, -33 },
    { -4, -38 },
    { -10, -35 },
    { -1, -35 },
    { -4, -33 },
    { -4, -40 },
    { -15, -36 },
    { 6, -36 },
    { -4, -35 },
    { -4, -43 },
    { -16, -41 },
    { 7, -41 },
};



extern "C" u32 GetActorAnimationDuration(IndexedResourceProvider * resource, u32 index)
{
    IndexedResourceResult const & entries = resource->Resolve(index);
    u32 duration = 0;
    u32 entry = 0;
    u32 count = entries.Count();
    for (; entry < count; ++entry)
        duration += entries[entry].metric;
    return duration;
}

AActorEntity::AActorEntity(GameObject * game_object, ActorLocation const & location, u32 arg_2, u32 anim_id)
    : AEntity(game_object, location), x_speed_q16(0), y_speed_q16(0), facing(location.facing), unk_21(arg_2)
{
    SetAnim(anim_id);
}

void AActorEntity::SetLocation(ActorLocation const & location)
{
    AEntity::SetLocation(location.GetMap(), location.GetX(), location.GetY());

    fu8 new_facing = location.facing;

    if (facing != new_facing)
        SetAnimFacing(new_facing);

    motion.speed_q16 = 0;
}

ActorLocation AActorEntity::GetLocation() const
{
    return ActorLocation(AEntity::GetLocation(), facing);
}

void AActorEntity::SetAnimFacing(u32 new_facing)
{
    facing = new_facing;
    RefreshSprite(anim_id + facing);
}

void AActorEntity::SetAnim(u32 new_anim_id)
{
    anim_id = new_anim_id;
    RefreshSprite(anim_id + facing);
}

void AActorEntity::RefreshSprite(u32 sprite_anim)
{
    EntitySpriteController * ptr = static_cast<EntitySpriteController *>(unk_10.Get());

    if (ptr != nullptr)
    {
        ptr->SetAnimation(sprite_anim);
    }

    animation_countdown = GetActorAnimationDuration(game_object->vfunc_68(), sprite_anim);
    animation_reload = animation_countdown;
}

void AActorEntity::ApplyWorldMovement()
{
    if (x_speed_q16 == 0 && y_speed_q16 == 0)
        return;

    GameObject * go = game_object;

    fu16 map = location_map;

    i32 x_old_q16 = x_q16;
    i32 y_old_q16 = y_q16;
    i32 x_new_q16 = x_q16 + x_speed_q16;
    i32 y_new_q16 = y_q16 + y_speed_q16;

    if (x_new_q16 < 0)
    {
        x_new_q16 = 0;
    }
    else
    {
        i32 map_width = go->GetMapPixelWidth(map) << 16;

        if (x_new_q16 > map_width)
            x_new_q16 = map_width;
    }

    if (y_new_q16 < 0)
    {
        y_new_q16 = 0;
    }
    else
    {
        i32 map_height = go->GetMapPixelHeight(map) << 16;

        if (y_new_q16 > map_height)
            y_new_q16 = map_height;
    }

    i32 x_diff = (x_new_q16 >> 16) - (x_old_q16 >> 16);
    i32 y_diff = (y_new_q16 >> 16) - (y_old_q16 >> 16);

    Box box_a = UnkMapBox(GetBox());
    Box & box = box_a;

    MapTerrainView terrain = go->GetMapTerrain(map);

    if (IsMapTerrainBoxBlocked(terrain, box) || !IsMapTerrainBoxBlocked(terrain, box.Moved(x_diff, y_diff)))
    {
        x_q16 = x_new_q16;
        y_q16 = y_new_q16;
    }
}

ActorAxisMotion::ActorAxisMotion()
    : speed_q16(0)
{
}

EC void StartActorXMotion(AActorEntity & self, u32 target, i32 speed_q16)
{
    i32 x = self.x_q16 >> 16;

    self.x_q16 = x << 16;

    if (speed_q16 != 0 && target != x)
    {
        self.motion.speed_q16 = abs(speed_q16);
        self.motion.target_pixel = target;
        self.motion.axis = 0;
    }
    else
    {
        self.motion.speed_q16 = 0;
    }
}

EC void StartActorYMotion(AActorEntity & self, u32 target, i32 speed_q16)
{
    i32 y = self.y_q16 >> 16;

    self.y_q16 = y << 16;

    if (speed_q16 != 0 && target != y)
    {
        self.motion.speed_q16 = abs(speed_q16);
        self.motion.target_pixel = target;
        self.motion.axis = 1;
    }
    else
    {
        self.motion.speed_q16 = 0;
    }
}

EC bool IsActorAxisMotionComplete(AActorEntity & self)
{
    return self.motion.speed_q16 == 0;
}

EC void StartActorSpriteEffect(AActorEntity & self, u32 effect, bool persistent)
{
    if (self.unk_10.Get() != nullptr)
    {
        EntitySpriteController * sprite = static_cast<EntitySpriteController *>(self.unk_10.Get());
        sprite->StartEffect(effect, persistent);
    }
}

EC void StopActorSpriteEffect(AActorEntity & self)
{
    if (self.unk_10.Get() != nullptr)
    {
        static_cast<EntitySpriteController *>(self.unk_10.Get())->StopEffect();
    }
}

EC void SetActorAuxRenderProfile(AActorEntity & self, u32 profile)
{
    if (self.unk_10.Get() != nullptr)
    {
        static_cast<EntitySpriteController *>(self.unk_10.Get())->SetAuxRenderProfile(profile);
    }
}

EC void func_080323F0(AActorEntity & self, u32 value)
{
    if (self.unk_10.Get() != nullptr)
    {
        static_cast<EntitySpriteController *>(self.unk_10.Get())->SetUnknown8A2(value);
    }
}

Box AActorEntity::GetBox() const
{
    return Box(x_q16 >> 16, y_q16 >> 16, 14, 9);
}

// Suspended normal behavior still advances the commanded axis and visual.
void AActorEntity::UpdateWhileSuspended(EntityUpdateContext const & context)
{
    if (animation_countdown != 0)
        --animation_countdown;
    else
        animation_countdown = animation_reload;
    u32 speed = motion.speed_q16;
    if (speed != 0) {
        u8 horizontal = motion.axis == 0;
        i32 position = horizontal ? x_q16 : y_q16;
        i32 previous = position >> 16;
        i32 target = motion.target_pixel;
        i32 remaining = target - previous;
        i32 previous_remaining = remaining;
        if (remaining == 0) {
            motion.speed_q16 = 0;
        } else {
            i32 next = position + speed;
            if (remaining <= 0)
                next = position - speed;
            position = next;
            i32 pixel = position >> 16;
            if (pixel != previous) {
                remaining = target - pixel;
                if ((previous_remaining > 0 && remaining <= 0)
                    || (previous_remaining <= 0 && remaining >= 0)) {
                    motion.speed_q16 = 0;
                }
            }
            if (horizontal)
                x_q16 = position;
            else
                y_q16 = position;
        }
    }
    AEntity::UpdateWhileSuspended(context);
}

u32 AActorEntity::vfunc_34()
{
    return 0;
}

EntitySpriteController::EntitySpriteController(AActorEntity * owner,
    u32 size_shift, u32 palette_kind, u32 profile, u32 unknown_8A2,
    u32 unknown_8B, bool sprite_unknown_3D)
    : EntityVisualController(owner),
      sprite(owner->game_object->vfunc_68(), owner->GetAnimationIndex(),
          owner->GetGameObject(), size_shift, palette_kind, sprite_unknown_3D),
      effect(owner->game_object->vfunc_6C(), 0, owner->GetGameObject(), 2, 14, false),
      aux_render_profile(profile), unk_89(0), effect_mode(0),
      unk_8A_2(unknown_8A2), unk_8B(unknown_8B)
{
}

EntitySpriteController::EntitySpriteController(AActorEntity * owner,
    u32 size_shift, i32 const * palette_kinds, u32 palette_count, u32 profile,
    u32 unknown_8A2, u32 unknown_8B, bool sprite_unknown_3D)
    : EntityVisualController(owner),
      sprite(owner->game_object->vfunc_68(), owner->GetAnimationIndex(),
          owner->GetGameObject(), size_shift, palette_kinds, palette_count, sprite_unknown_3D),
      effect(owner->game_object->vfunc_6C(), 0, owner->GetGameObject(), 2, 14, false),
      aux_render_profile(profile), unk_89(0), effect_mode(0),
      unk_8A_2(unknown_8A2), unk_8B(unknown_8B)
{
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".thumb\n"
    ".align 2, 0\n"
    "    .global Update__22EntitySpriteController\n"
    "    .thumb_func\n"
    "Update__22EntitySpriteController:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    adds\tr4, r0, #0\n"
    "    adds\tr1, r4, #0\n"
    "    adds\tr1, #71\t@ 0x47\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_08032630\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #48\t@ 0x30\n"
    "    bl UpdateIndexedResourceHandle\n"
    "    lsls\tr0, r0, #30\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_08032634\n"
    "    adds\tr1, r4, #0\n"
    "    adds\tr1, #68\t@ 0x44\n"
    "    movs\tr0, #1\n"
    "    b .Lus_08032632\n"
    ".Lus_08032630:\n"
    "    movs\tr0, #0\n"
    ".Lus_08032632:\n"
    "    strb\tr0, [r1, #0]\n"
    ".Lus_08032634:\n"
    "    adds\tr1, r4, #0\n"
    "    adds\tr1, #138\t@ 0x8a\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr5, r0, #30\n"
    "    adds\tr6, r1, #0\n"
    "    cmp\tr5, #0\n"
    "    beq .Lus_0803268A\n"
    "    movs\tr7, #0\n"
    "    subs\tr1, #3\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_0803266A\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #112\t@ 0x70\n"
    "    bl UpdateIndexedResourceHandle\n"
    "    adds\tr2, r0, #0\n"
    "    lsls\tr0, r2, #30\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_08032666\n"
    "    adds\tr1, r4, #0\n"
    "    adds\tr1, #132\t@ 0x84\n"
    "    movs\tr0, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Lus_08032666:\n"
    "    adds\tr0, r2, #0\n"
    "    b .Lus_08032670\n"
    ".Lus_0803266A:\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    "    movs\tr0, #2\n"
    ".Lus_08032670:\n"
    "    lsls\tr0, r0, #29\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_0803267C\n"
    "    cmp\tr5, #2\n"
    "    beq .Lus_0803267C\n"
    "    movs\tr7, #1\n"
    ".Lus_0803267C:\n"
    "    cmp\tr7, #0\n"
    "    beq .Lus_0803268A\n"
    "    ldrb\tr1, [r6, #0]\n"
    "    movs\tr0, #4\n"
    "    negs\tr0, r0\n"
    "    ands\tr0, r1\n"
    "    strb\tr0, [r6, #0]\n"
    ".Lus_0803268A:\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "    .global Draw__22EntitySpriteControllerRC17EntityDrawContext\n"
    "    .thumb_func\n"
    "Draw__22EntitySpriteControllerRC17EntityDrawContext:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #80\t@ 0x50\n"
    "    adds\tr6, r0, #0\n"
    "    mov\tsl, r1\n"
    "    ldr\tr0, [r6, #0]\n"
    "    mov\tr8, r0\n"
    "    ldr\tr1, [r0, #0]\n"
    "    str\tr1, [sp, #60]\t@ 0x3c\n"
    "    movs\tr2, #10\n"
    "    ldrsh\tr1, [r0, r2]\n"
    "    mov\tr3, sl\n"
    "    movs\tr4, #12\n"
    "    ldrsh\tr0, [r3, r4]\n"
    "    subs\tr1, r1, r0\n"
    "    str\tr1, [sp, #64]\t@ 0x40\n"
    "    mov\tr0, r8\n"
    "    movs\tr2, #14\n"
    "    ldrsh\tr1, [r0, r2]\n"
    "    movs\tr4, #14\n"
    "    ldrsh\tr0, [r3, r4]\n"
    "    subs\tr0, r1, r0\n"
    "    str\tr0, [sp, #68]\t@ 0x44\n"
    "    movs\tr0, #128\t@ 0x80\n"
    "    lsls\tr0, r0, #8\n"
    "    subs\tr0, r0, r1\n"
    "    str\tr0, [sp, #72]\t@ 0x48\n"
    "    add\tr2, sp, #52\t@ 0x34\n"
    "    ldr\tr0, [r3, #0]\n"
    "    ldr\tr1, [r3, #8]\n"
    "    str\tr0, [sp, #52]\t@ 0x34\n"
    "    str\tr1, [r2, #4]\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #138\t@ 0x8a\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    lsls\tr0, r1, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_080327C2\n"
    "    cmp\tr0, #0\n"
    "    blt .Lus_080327C2\n"
    "    cmp\tr0, #2\n"
    "    bgt .Lus_080327C2\n"
    "    mov\tr0, r8\n"
    "    adds\tr0, #32\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    lsrs\tr1, r1, #2\n"
    "    lsls\tr1, r1, #4\n"
    "    lsls\tr0, r0, #2\n"
    "    ldr r2, .Lus_08032764\n"
    "    adds\tr0, r0, r2\n"
    "    adds\tr1, r1, r0\n"
    "    movs\tr2, #0\n"
    "    ldrsh\tr0, [r1, r2]\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr1, [r1, r3]\n"
    "    adds\tr5, r6, #0\n"
    "    adds\tr5, #72\t@ 0x48\n"
    "    ldr\tr4, [sp, #64]\t@ 0x40\n"
    "    adds\tr0, r4, r0\n"
    "    str\tr0, [sp, #76]\t@ 0x4c\n"
    "    ldr\tr0, [sp, #68]\t@ 0x44\n"
    "    adds\tr0, r0, r1\n"
    "    mov\tr9, r0\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #112\t@ 0x70\n"
    "    ldr\tr1, [r6, #112]\t@ 0x70\n"
    "    ldr\tr3, [r1, #0]\n"
    "    ldrh\tr2, [r0, #12]\n"
    "    lsls\tr2, r2, #2\n"
    "    ldr\tr0, [r6, #116]\t@ 0x74\n"
    "    adds\tr0, r0, r2\n"
    "    ldrh\tr2, [r0, #0]\n"
    "    add\tr0, sp, #20\n"
    "    ldr\tr3, [r3, #16]\n"
    "    bl _call_via_r3\n"
    "    add\tr7, sp, #20\n"
    "    ldr\tr3, [sp, #56]\t@ 0x38\n"
    "    ldr\tr2, [r6, #72]\t@ 0x48\n"
    "    ldr\tr1, [r6, #80]\t@ 0x50\n"
    "    negs\tr0, r1\n"
    "    orrs\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_0803276C\n"
    "    ldrh\tr0, [r5, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #88\t@ 0x58\n"
    "    ldr\tr4, [sp, #72]\t@ 0x48\n"
    "    str\tr4, [sp, #0]\n"
    "    adds\tr4, r7, #0\n"
    "    str\tr4, [sp, #4]\n"
    "    str\tr2, [sp, #8]\n"
    "    str\tr0, [sp, #12]\n"
    "    str\tr1, [sp, #16]\n"
    "    adds\tr0, r3, #0\n"
    "    ldr\tr1, [sp, #76]\t@ 0x4c\n"
    "    mov\tr2, r9\n"
    "    movs\tr3, #85\t@ 0x55\n"
    "    ldr r4, .Lus_08032768\n"
    "    bl _call_via_r4\n"
    "    b .Lus_0803276E\n"
    ".Lus_08032764: .word gUnk_080F1328\n"
    ".Lus_08032768: .word SubmitWorldSpriteRecords\n"
    ".Lus_0803276C:\n"
    "    movs\tr0, #0\n"
    ".Lus_0803276E:\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_080327C2\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    mov\tr9, r0\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_080327C2\n"
    "    ldr\tr1, [sp, #52]\t@ 0x34\n"
    "    adds\tr2, r7, #0\n"
    "    adds\tr2, #8\n"
    "    adds\tr0, r5, #0\n"
    "    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_080327A2\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr1, #16\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr2, #1\n"
    "    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc\n"
    "    b .Lus_080327BC\n"
    ".Lus_080327A2:\n"
    "    adds\tr4, r5, #0\n"
    "    adds\tr4, #62\t@ 0x3e\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_080327BC\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr1, #16\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr2, #1\n"
    "    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc\n"
    "    movs\tr0, #1\n"
    "    strb\tr0, [r4, #0]\n"
    ".Lus_080327BC:\n"
    "    movs\tr0, #0\n"
    "    mov\tr1, r9\n"
    "    strb\tr0, [r1, #0]\n"
    ".Lus_080327C2:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #139\t@ 0x8b\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, #1\n"
    "    beq .Lus_080327EC\n"
    "    cmp\tr0, #1\n"
    "    ble .Lus_080327D4\n"
    "    cmp\tr0, #2\n"
    "    beq .Lus_080327F0\n"
    ".Lus_080327D4:\n"
    "    mov\tr0, r8\n"
    "    adds\tr0, #33\t@ 0x21\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    movs\tr1, #3\n"
    "    ands\tr0, r1\n"
    "    lsls\tr4, r0, #2\n"
    "    orrs\tr4, r0\n"
    "    lsls\tr1, r0, #4\n"
    "    orrs\tr4, r1\n"
    "    lsls\tr0, r0, #6\n"
    "    orrs\tr4, r0\n"
    "    b .Lus_080327F2\n"
    ".Lus_080327EC:\n"
    "    movs\tr4, #25\n"
    "    b .Lus_080327F2\n"
    ".Lus_080327F0:\n"
    "    movs\tr4, #26\n"
    ".Lus_080327F2:\n"
    "    adds\tr5, r6, #0\n"
    "    adds\tr5, #8\n"
    "    add\tr2, sp, #52\t@ 0x34\n"
    "    mov\tr8, r2\n"
    "    ldr\tr1, [r6, #48]\t@ 0x30\n"
    "    ldr\tr3, [r1, #0]\n"
    "    ldrh\tr2, [r6, #60]\t@ 0x3c\n"
    "    lsls\tr2, r2, #2\n"
    "    ldr\tr0, [r6, #52]\t@ 0x34\n"
    "    adds\tr0, r0, r2\n"
    "    ldrh\tr2, [r0, #0]\n"
    "    add\tr0, sp, #20\n"
    "    ldr\tr3, [r3, #16]\n"
    "    bl _call_via_r3\n"
    "    add\tr7, sp, #20\n"
    "    mov\tr3, r8\n"
    "    ldr\tr3, [r3, #4]\n"
    "    mov\tr9, r3\n"
    "    ldr\tr2, [r6, #8]\n"
    "    ldr\tr1, [r6, #16]\n"
    "    negs\tr0, r1\n"
    "    orrs\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_0803284C\n"
    "    ldrh\tr0, [r5, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #24\n"
    "    ldr\tr3, [sp, #72]\t@ 0x48\n"
    "    str\tr3, [sp, #0]\n"
    "    adds\tr3, r7, #0\n"
    "    str\tr3, [sp, #4]\n"
    "    str\tr2, [sp, #8]\n"
    "    str\tr0, [sp, #12]\n"
    "    str\tr1, [sp, #16]\n"
    "    mov\tr0, r9\n"
    "    ldr\tr1, [sp, #64]\t@ 0x40\n"
    "    ldr\tr2, [sp, #68]\t@ 0x44\n"
    "    adds\tr3, r4, #0\n"
    "    ldr r4, .Lus_08032848\n"
    "    bl _call_via_r4\n"
    "    b .Lus_0803284E\n"
    ".Lus_08032848: .word SubmitWorldSpriteRecords\n"
    ".Lus_0803284C:\n"
    "    movs\tr0, #0\n"
    ".Lus_0803284E:\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_080328A4\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    mov\tr9, r0\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_080328A4\n"
    "    mov\tr4, r8\n"
    "    ldr\tr1, [r4, #0]\n"
    "    adds\tr2, r7, #0\n"
    "    adds\tr2, #8\n"
    "    adds\tr0, r5, #0\n"
    "    bl QueueTileUpload__19GameSceneSpriteBaseR16HardwareDmaQueueRC24IndexedResourceTileRange\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_08032884\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr1, #16\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr2, #1\n"
    "    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc\n"
    "    b .Lus_0803289E\n"
    ".Lus_08032884:\n"
    "    adds\tr4, r5, #0\n"
    "    adds\tr4, #62\t@ 0x3e\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_0803289E\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr1, #16\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr2, #1\n"
    "    bl UploadPalettes__19GameSceneSpriteBaseRC27IndexedResourcePaletteRangeUc\n"
    "    movs\tr0, #1\n"
    "    strb\tr0, [r4, #0]\n"
    ".Lus_0803289E:\n"
    "    movs\tr0, #0\n"
    "    mov\tr1, r9\n"
    "    strb\tr0, [r1, #0]\n"
    ".Lus_080328A4:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #136\t@ 0x88\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, #1\n"
    "    beq .Lus_080328C6\n"
    "    cmp\tr0, #1\n"
    "    bgt .Lus_080328B8\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_080328C2\n"
    "    b .Lus_080328C6\n"
    ".Lus_080328B8:\n"
    "    cmp\tr0, #2\n"
    "    beq .Lus_080328CA\n"
    "    cmp\tr0, #3\n"
    "    bne .Lus_080328C6\n"
    "    b .Lus_080328F0\n"
    ".Lus_080328C2:\n"
    "    movs\tr4, #0\n"
    "    b .Lus_080328CC\n"
    ".Lus_080328C6:\n"
    "    movs\tr4, #1\n"
    "    b .Lus_080328CC\n"
    ".Lus_080328CA:\n"
    "    movs\tr4, #2\n"
    ".Lus_080328CC:\n"
    "    ldr\tr2, [sp, #60]\t@ 0x3c\n"
    "    ldr\tr0, [r2, #0]\n"
    "    ldr\tr1, [r0, #88]\t@ 0x58\n"
    "    adds\tr0, r2, #0\n"
    "    bl _call_via_r1\n"
    "    mov\tr3, sl\n"
    "    ldr\tr1, [r3, #8]\n"
    "    adds\tr2, r6, #0\n"
    "    adds\tr2, #137\t@ 0x89\n"
    "    movs\tr3, #0\n"
    "    ldrsb\tr3, [r2, r3]\n"
    "    ldr\tr2, [sp, #68]\t@ 0x44\n"
    "    adds\tr3, r2, r3\n"
    "    str\tr4, [sp, #0]\n"
    "    ldr\tr2, [sp, #64]\t@ 0x40\n"
    "    bl Draw__C22EntityAuxiliarySpritesP21WorldSpriteDrawBufferiiUi\n"
    ".Lus_080328F0:\n"
    "    add\tsp, #80\t@ 0x50\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "\n"
);

// Horse and player renderers pass map and pixel coordinates, then store
// the result in EntitySpriteController::unk_8B. Map 2 uses the rectangle
// x=0x110..0x3BF, y=0xB0..0x24F; the visual meaning remains unresolved.
extern "C" u32 func_08032900(u32 kind, u32 x, i32 y)
{
    if (kind == 2)
    {
        x += (u32)-0x110;
        i32 limit = 0x2AF;

        if (x <= (u32)limit)
        {
            if (y > 0xAF)
            {
                limit -= 0x60;
                if (y <= limit)
                {
                    return 1;
                }
            }
        }

        return 2;
    }

    return 0;
}

// All six native methods are shared by JP, US, EU and DE.
asm_unified(
    ".text\n"
    "    .align 2, 0\n"
    "\n"
);

ScriptVisualEffectActor::ScriptVisualEffectActor(GameObject * world, ScriptVisualEffectRecord * record)
    : AActorEntity(world, record->location, 2, record->animation)
{
    this->record = record;
}

asm_unified(
    "    thumb_func_start _._23ScriptVisualEffectActor\n"
    "_._23ScriptVisualEffectActor:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #8\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr6, r1, #0\n"
    "    ldr r0, .LscriptVisual_080329AC\n"
    "    str\tr0, [r5, #20]\n"
    "    ldr\tr4, [r5, #48]\t@ 0x30\n"
    "    mov\tr0, sp\n"
    "    adds\tr1, r5, #0\n"
    "    bl GetLocation__C12AActorEntity\n"
    "    mov\tr0, sp\n"
    "    ldmia\tr0!, {r1, r2}\n"
    "    stmia\tr4!, {r1, r2}\n"
    "    ldrh\tr1, [r5, #34]\t@ 0x22\n"
    "    ldr\tr0, [r5, #48]\t@ 0x30\n"
    "    strh\tr1, [r0, #8]\n"
    "    ldr r0, .LscriptVisual_080329B0\n"
    "    str\tr0, [r5, #20]\n"
    "    ldr\tr1, [r5, #16]\n"
    "    cmp\tr1, #0\n"
    "    beq .LscriptVisual_08032994\n"
    "    ldr\tr0, [r1, #4]\n"
    "    ldr\tr2, [r0, #8]\n"
    "    adds\tr0, r1, #0\n"
    "    movs\tr1, #3\n"
    "    bl _call_via_r2\n"
    ".LscriptVisual_08032994:\n"
    "    movs\tr0, #1\n"
    "    ands\tr0, r6\n"
    "    cmp\tr0, #0\n"
    "    beq .LscriptVisual_080329A2\n"
    "    adds\tr0, r5, #0\n"
    "    bl __builtin_delete\n"
    ".LscriptVisual_080329A2:\n"
    "    add\tsp, #8\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "    .align 2, 0\n"
    ".LscriptVisual_080329AC: .word __vt_23ScriptVisualEffectActor\n"
    ".LscriptVisual_080329B0: .word __vt_7AEntity\n"
);
EntityVisualController * ScriptVisualEffectActor::CreateVisualController()
{
    return new DefaultEntitySpriteController(this);
}
u32 ScriptVisualEffectActor::vfunc_34()
{
    return record->script_id;
}

void ScriptVisualEffectActor::SetEventScript(MaryScriptId script_id)
{
    record->script_id = script_id;
}

Box ScriptVisualEffectActor::GetBox() const
{
    return Box(-7, -10, 7, 4, x_q16 >> 16, y_q16 >> 16);
}

DefaultEntitySpriteController::DefaultEntitySpriteController(AActorEntity * entity)
    : EntitySpriteController(entity, 6, 0x20, ENTITY_AUX_RENDER_DEFAULT, 0, 0, false)
{
}

void AActorEntity::Update(EntityUpdateContext const & context)
{
    if (animation_countdown != 0)
        --animation_countdown;
    else
        animation_countdown = animation_reload;
    EntityVisualController * visual = unk_10.Get();
    if (visual != nullptr)
        visual->Update();
}
