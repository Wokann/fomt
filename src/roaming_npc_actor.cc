
#include "roaming_npc_actor.hh"

#include <new>
#include "npc_locations.hh"
#include "game_object.hh"
#include "time_of_day_types.hh"
#include FOMT_TEXT_INCLUDE(roaming_npc_actor.cc)
// These weighted behavior-timing records share the animal-table layout.
// The fourth byte remains unnamed until a caller establishes its meaning.
extern "C" ActorBehaviorTiming const gUnk_080F1538[] ALIGN(4) = {
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x32, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x64, 0x09, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
};

// The following physical ROM range is byte-identical in both revisions.
// Keep address-derived names until a native caller establishes a semantic one.
extern "C" u16 const gUnk_080F1560[] = {
    0x071C, 0x0720, 0x0724, 0x072C, 0x0728, 0x0000,
};

extern "C" ActorBehaviorTiming const gUnk_080F156C[] = {
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x2D, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x64, 0x09, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
};

extern "C" u16 const gUnk_080F15A4[] = {
    0x02AC, 0x02B0, 0x02B4, 0x02B8,
    0x02BC, 0x02C0, 0x02C4, 0x0000,
};

extern "C" ActorBehaviorTiming const gUnk_080F15B4[] = {
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x0A, 0x01, 0x02, 0x00 },
    { 0x05, 0x01, 0x04, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x05, 0x01, 0x01, 0x00 },
    { 0x05, 0x01, 0x02, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x05, 0x01, 0x02, 0x00 },
    { 0x19, 0x01, 0x02, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x0A, 0x05, 0x03, 0x00 },
    { 0x3C, 0x08, 0x04, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00 },
};

extern "C" u16 const gUnk_080F161C[] = {
    0x0379, 0x037D, 0x0381, 0x0385, 0x0389, 0x038D, 0x0391,
    0x0395, 0x0399, 0x039D, 0x03A1, 0x03A5, 0x03AA, 0x0000,
};

extern "C" ActorBehaviorTiming const gUnk_080F1638[] = {
    { 0x28, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
    { 0x1E, 0x01, 0x02, 0x00 },
};

extern "C" u16 const gUnk_080F1644[] = {
    0x0207, 0x020B, 0x020F, 0x0000,
};

RoamingNpcActor::RoamingNpcActor(GameObject * game_object,
    ActorLocation * saved_location, u32 animation, u32 unk_3C)
    : AActorEntity(game_object, *saved_location, 2, animation),
      saved_location(saved_location), avoidance_box(0, 0),
      unk_3C(unk_3C), behavior_countdown(0), unk_40(true)
{
}

RoamingNpcActor::~RoamingNpcActor()
{
    *saved_location = GetLocation();
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

void RoamingNpcActor::SetRoamingSpeed(i32 speed)
{
    i32 x_speed = 0;
    i32 y_speed = 0;
    u8 direction = facing;

    switch (direction)
    {
    case 0:
        y_speed = speed;
        break;
    case 1:
        y_speed = -speed;
        break;
    case 2:
        x_speed = -speed;
        break;
    case 3:
        x_speed = speed;
        break;
    }

    x_speed_q16 = x_speed;
    y_speed_q16 = y_speed;
}

bool RoamingNpcActor::IsVisualAnimationComplete() const
{
    EntitySpriteController * sprite = static_cast<EntitySpriteController *>(unk_10.Get());
    if (sprite != 0)
    {
        bool complete = false;
        IndexedResourceHandle const * animation = &sprite->sprite.handle;
        u32 active = 0;
        if (animation->metric_scaled != 0)
            active = animation->scroll_delta != 0;
        if (active == 0 || WouldIndexedResourceHandleWrap(animation))
            complete = true;
        return complete;
    }
    return true;
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start ApplyRoamingMovement__15RoamingNpcActorP19ActorMovementBounds\n"
    "ApplyRoamingMovement__15RoamingNpcActorP19ActorMovementBounds:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #4\n"
    "    adds\tr7, r0, #0\n"
    "    adds\tr4, r1, #0\n"
    "    ldr\tr1, [r7, #8]\n"
    "    ldr\tr2, [r7, #12]\n"
    "    ldr\tr0, [r7, #24]\n"
    "    adds\tr0, r0, r1\n"
    "    mov\tr9, r0\n"
    "    ldr\tr0, [r7, #28]\n"
    "    adds\tr0, r0, r2\n"
    "    mov\tr8, r0\n"
    "    asrs\tr1, r1, #16\n"
    "    str\tr1, [sp, #0]\n"
    "    asrs\tr6, r2, #16\n"
    "    asrs\tr0, r0, #16\n"
    "    subs\tr5, r0, r6\n"
    "    mov\tr1, r9\n"
    "    asrs\tr0, r1, #16\n"
    "    ldr\tr1, [sp, #0]\n"
    "    subs\tr1, r0, r1\n"
    "    mov\tsl, r1\n"
    "    cmp\tr5, #0\n"
    "    ble .Lus_08037182\n"
    "    ldr\tr1, [r4, #0]\n"
    "    ldr\tr0, [r4, #40]\t@ 0x28\n"
    "    cmp\tr1, r0\n"
    "    ble .Lus_08037162\n"
    "    adds\tr0, r4, #0\n"
    "    bl RefreshDown__19ActorMovementBounds\n"
    "    ldr\tr0, [r4, #0]\n"
    "    b .Lus_08037164\n"
    ".Lus_08037162:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_08037164:\n"
    "    cmp\tr5, r0\n"
    "    ble .Lus_08037182\n"
    "    ldr\tr1, [r4, #0]\n"
    "    ldr\tr0, [r4, #40]\t@ 0x28\n"
    "    cmp\tr1, r0\n"
    "    ble .Lus_0803717A\n"
    "    adds\tr0, r4, #0\n"
    "    bl RefreshDown__19ActorMovementBounds\n"
    "    ldr\tr0, [r4, #0]\n"
    "    b .Lus_0803717C\n"
    ".Lus_0803717A:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_0803717C:\n"
    "    adds\tr0, r6, r0\n"
    "    lsls\tr0, r0, #16\n"
    "    mov\tr8, r0\n"
    ".Lus_08037182:\n"
    "    cmp\tr5, #0\n"
    "    bge .Lus_080371B8\n"
    "    ldr\tr1, [r4, #4]\n"
    "    ldr\tr0, [r4, #40]\t@ 0x28\n"
    "    cmn\tr1, r0\n"
    "    bge .Lus_08037198\n"
    "    adds\tr0, r4, #0\n"
    "    bl RefreshUp__19ActorMovementBounds\n"
    "    ldr\tr0, [r4, #4]\n"
    "    b .Lus_0803719A\n"
    ".Lus_08037198:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_0803719A:\n"
    "    cmp\tr5, r0\n"
    "    bge .Lus_080371B8\n"
    "    ldr\tr1, [r4, #4]\n"
    "    ldr\tr0, [r4, #40]\t@ 0x28\n"
    "    cmn\tr1, r0\n"
    "    bge .Lus_080371B0\n"
    "    adds\tr0, r4, #0\n"
    "    bl RefreshUp__19ActorMovementBounds\n"
    "    ldr\tr0, [r4, #4]\n"
    "    b .Lus_080371B2\n"
    ".Lus_080371B0:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_080371B2:\n"
    "    adds\tr0, r6, r0\n"
    "    lsls\tr0, r0, #16\n"
    "    mov\tr8, r0\n"
    ".Lus_080371B8:\n"
    "    mov\tr0, sl\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_080371F2\n"
    "    ldr\tr1, [r4, #8]\n"
    "    ldr\tr0, [r4, #40]\t@ 0x28\n"
    "    cmn\tr1, r0\n"
    "    bge .Lus_080371D0\n"
    "    adds\tr0, r4, #0\n"
    "    bl RefreshLeft__19ActorMovementBounds\n"
    "    ldr\tr0, [r4, #8]\n"
    "    b .Lus_080371D2\n"
    ".Lus_080371D0:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_080371D2:\n"
    "    cmp\tsl, r0\n"
    "    bge .Lus_080371F2\n"
    "    ldr\tr1, [r4, #8]\n"
    "    ldr\tr0, [r4, #40]\t@ 0x28\n"
    "    cmn\tr1, r0\n"
    "    bge .Lus_080371E8\n"
    "    adds\tr0, r4, #0\n"
    "    bl RefreshLeft__19ActorMovementBounds\n"
    "    ldr\tr0, [r4, #8]\n"
    "    b .Lus_080371EA\n"
    ".Lus_080371E8:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_080371EA:\n"
    "    ldr\tr1, [sp, #0]\n"
    "    adds\tr0, r1, r0\n"
    "    lsls\tr0, r0, #16\n"
    "    mov\tr9, r0\n"
    ".Lus_080371F2:\n"
    "    mov\tr0, sl\n"
    "    cmp\tr0, #0\n"
    "    ble .Lus_0803722C\n"
    "    ldr\tr1, [r4, #12]\n"
    "    ldr\tr0, [r4, #40]\t@ 0x28\n"
    "    cmp\tr1, r0\n"
    "    ble .Lus_0803720A\n"
    "    adds\tr0, r4, #0\n"
    "    bl RefreshRight__19ActorMovementBounds\n"
    "    ldr\tr0, [r4, #12]\n"
    "    b .Lus_0803720C\n"
    ".Lus_0803720A:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_0803720C:\n"
    "    cmp\tsl, r0\n"
    "    ble .Lus_0803722C\n"
    "    ldr\tr1, [r4, #12]\n"
    "    ldr\tr0, [r4, #40]\t@ 0x28\n"
    "    cmp\tr1, r0\n"
    "    ble .Lus_08037222\n"
    "    adds\tr0, r4, #0\n"
    "    bl RefreshRight__19ActorMovementBounds\n"
    "    ldr\tr0, [r4, #12]\n"
    "    b .Lus_08037224\n"
    ".Lus_08037222:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_08037224:\n"
    "    ldr\tr1, [sp, #0]\n"
    "    adds\tr0, r1, r0\n"
    "    lsls\tr0, r0, #16\n"
    "    mov\tr9, r0\n"
    ".Lus_0803722C:\n"
    "    mov\tr0, r9\n"
    "    str\tr0, [r7, #8]\n"
    "    mov\tr1, r8\n"
    "    str\tr1, [r7, #12]\n"
    "    add\tsp, #4\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
);

void RoamingNpcActor::SetAvoidanceBox(Box const & box)
{
    avoidance_box = box;
}

void RoamingNpcActor::ClearAvoidanceBox()
{
    Box empty(0, 0);
    avoidance_box = empty;
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start Update__15RoamingNpcActorRC19EntityUpdateContext\n"
    "Update__15RoamingNpcActorRC19EntityUpdateContext:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r9\n"
    "    mov\tr6, r8\n"
    "    push\t{r6, r7}\n"
    "    sub\tsp, #96\t@ 0x60\n"
    "    adds\tr7, r0, #0\n"
    "    ldr\tr4, [r7, #0]\n"
    "    ldrh\tr0, [r7, #4]\n"
    "    mov\tr8, r0\n"
    "    ldr\tr0, [r4, #0]\n"
    "    ldr\tr1, [r0, #20]\n"
    "    adds\tr0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    cmp\tr0, r8\n"
    "    beq .Lus_0803728E\n"
    "    b .Lus_08037402\n"
    ".Lus_0803728E:\n"
    "    ldr\tr1, [r4, #0]\n"
    "    mov\tr0, sp\n"
    "    ldr\tr3, [r1, #52]\t@ 0x34\n"
    "    adds\tr1, r4, #0\n"
    "    mov\tr2, r8\n"
    "    bl _call_via_r3\n"
    "    ldr\tr1, [r7, #20]\n"
    "    add\tr0, sp, #64\t@ 0x40\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r7, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr1, [sp, #64]\t@ 0x40\n"
    "    ldr\tr2, [sp, #68]\t@ 0x44\n"
    "    str\tr1, [sp, #88]\t@ 0x58\n"
    "    str\tr2, [sp, #92]\t@ 0x5c\n"
    "    add\tr4, sp, #12\n"
    "    movs\tr2, #32\n"
    "    mov\tr9, r2\n"
    "    movs\tr5, #0\n"
    "    movs\tr1, #33\t@ 0x21\n"
    "    str\tr1, [sp, #12]\n"
    "    movs\tr0, #33\t@ 0x21\n"
    "    negs\tr0, r0\n"
    "    str\tr0, [r4, #4]\n"
    "    str\tr0, [r4, #8]\n"
    "    str\tr1, [r4, #12]\n"
    "    add\tr1, sp, #32\n"
    "    mov\tr0, sp\n"
    "    ldmia\tr0!, {r2, r3, r6}\n"
    "    stmia\tr1!, {r2, r3, r6}\n"
    "    ldr\tr0, [sp, #88]\t@ 0x58\n"
    "    ldr\tr1, [sp, #92]\t@ 0x5c\n"
    "    str\tr0, [sp, #44]\t@ 0x2c\n"
    "    str\tr1, [sp, #48]\t@ 0x30\n"
    "    mov\tr1, r9\n"
    "    str\tr1, [r4, #40]\t@ 0x28\n"
    "    str\tr5, [r4, #44]\t@ 0x2c\n"
    "    str\tr5, [r4, #48]\t@ 0x30\n"
    "    ldr\tr0, [r7, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    ldr\tr2, [r1, #64]\t@ 0x40\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr3, r0, #0\n"
    "    mov\tr9, r4\n"
    "    cmp\tr3, #0\n"
    "    beq .Lus_08037310\n"
    "    ldrh\tr0, [r3, #4]\n"
    "    cmp\tr0, r8\n"
    "    bne .Lus_08037310\n"
    "    ldr\tr1, [r3, #20]\n"
    "    add\tr4, sp, #72\t@ 0x48\n"
    "    adds\tr0, r4, #0\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    mov\tr0, r9\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #0\n"
    "    bl ClipAgainstBox__19ActorMovementBoundsRC3BoxUi\n"
    ".Lus_08037310:\n"
    "    ldr\tr0, [r7, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    ldr\tr2, [r1, #64]\t@ 0x40\n"
    "    movs\tr1, #74\t@ 0x4a\n"
    "    bl _call_via_r2\n"
    "    adds\tr3, r0, #0\n"
    "    cmp\tr3, #0\n"
    "    beq .Lus_08037340\n"
    "    ldrh\tr0, [r3, #4]\n"
    "    cmp\tr0, r8\n"
    "    bne .Lus_08037340\n"
    "    ldr\tr1, [r3, #20]\n"
    "    add\tr4, sp, #80\t@ 0x50\n"
    "    adds\tr0, r4, #0\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    mov\tr0, r9\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #0\n"
    "    bl ClipAgainstBox__19ActorMovementBoundsRC3BoxUi\n"
    ".Lus_08037340:\n"
    "    adds\tr2, r7, #0\n"
    "    adds\tr2, #52\t@ 0x34\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr0, [r2, r3]\n"
    "    movs\tr6, #52\t@ 0x34\n"
    "    ldrsh\tr1, [r7, r6]\n"
    "    subs\tr0, r0, r1\n"
    "    cmp\tr0, #0\n"
    "    ble .Lus_0803736A\n"
    "    movs\tr1, #6\n"
    "    ldrsh\tr0, [r2, r1]\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr1, [r2, r3]\n"
    "    subs\tr0, r0, r1\n"
    "    cmp\tr0, #0\n"
    "    ble .Lus_0803736A\n"
    "    mov\tr0, r9\n"
    "    adds\tr1, r2, #0\n"
    "    movs\tr2, #0\n"
    "    bl ClipAgainstBox__19ActorMovementBoundsRC3BoxUi\n"
    ".Lus_0803736A:\n"
    "    ldrh\tr4, [r7, #62]\t@ 0x3e\n"
    "    cmp\tr4, #0\n"
    "    beq .Lus_080373EC\n"
    "    ldr\tr5, [r7, #24]\n"
    "    ldr\tr6, [r7, #28]\n"
    "    cmp\tr5, #0\n"
    "    bge .Lus_08037390\n"
    "    ldr\tr1, [sp, #20]\n"
    "    ldr\tr0, [sp, #52]\t@ 0x34\n"
    "    cmn\tr1, r0\n"
    "    bge .Lus_0803738A\n"
    "    add\tr0, sp, #12\n"
    "    bl RefreshLeft__19ActorMovementBounds\n"
    "    ldr\tr0, [sp, #20]\n"
    "    b .Lus_0803738C\n"
    ".Lus_0803738A:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_0803738C:\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_080373E4\n"
    ".Lus_08037390:\n"
    "    cmp\tr5, #0\n"
    "    ble .Lus_080373AC\n"
    "    ldr\tr1, [sp, #24]\n"
    "    ldr\tr0, [sp, #52]\t@ 0x34\n"
    "    cmp\tr1, r0\n"
    "    ble .Lus_080373A6\n"
    "    add\tr0, sp, #12\n"
    "    bl RefreshRight__19ActorMovementBounds\n"
    "    ldr\tr0, [sp, #24]\n"
    "    b .Lus_080373A8\n"
    ".Lus_080373A6:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_080373A8:\n"
    "    cmp\tr0, #0\n"
    "    ble .Lus_080373E4\n"
    ".Lus_080373AC:\n"
    "    cmp\tr6, #0\n"
    "    bge .Lus_080373C8\n"
    "    ldr\tr1, [sp, #16]\n"
    "    ldr\tr0, [sp, #52]\t@ 0x34\n"
    "    cmn\tr1, r0\n"
    "    bge .Lus_080373C2\n"
    "    add\tr0, sp, #12\n"
    "    bl RefreshUp__19ActorMovementBounds\n"
    "    ldr\tr0, [sp, #16]\n"
    "    b .Lus_080373C4\n"
    ".Lus_080373C2:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_080373C4:\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_080373E4\n"
    ".Lus_080373C8:\n"
    "    cmp\tr6, #0\n"
    "    ble .Lus_080373E8\n"
    "    ldr\tr1, [sp, #12]\n"
    "    ldr\tr0, [sp, #52]\t@ 0x34\n"
    "    cmp\tr1, r0\n"
    "    ble .Lus_080373DE\n"
    "    add\tr0, sp, #12\n"
    "    bl RefreshDown__19ActorMovementBounds\n"
    "    ldr\tr0, [sp, #12]\n"
    "    b .Lus_080373E0\n"
    ".Lus_080373DE:\n"
    "    adds\tr0, r1, #0\n"
    ".Lus_080373E0:\n"
    "    cmp\tr0, #0\n"
    "    bgt .Lus_080373E8\n"
    ".Lus_080373E4:\n"
    "    movs\tr4, #0\n"
    "    b .Lus_080373F8\n"
    ".Lus_080373E8:\n"
    "    subs\tr4, #1\n"
    "    b .Lus_080373F8\n"
    ".Lus_080373EC:\n"
    "    ldr\tr0, [r7, #20]\n"
    "    ldr\tr1, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r7, #0\n"
    "    bl _call_via_r1\n"
    "    adds\tr4, r0, #0\n"
    ".Lus_080373F8:\n"
    "    strh\tr4, [r7, #62]\t@ 0x3e\n"
    "    adds\tr0, r7, #0\n"
    "    mov\tr1, r9\n"
    "    bl ApplyRoamingMovement__15RoamingNpcActorP19ActorMovementBounds\n"
    ".Lus_08037402:\n"
    "    ldrh\tr0, [r7, #36]\t@ 0x24\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_0803740C\n"
    "    subs\tr0, #1\n"
    "    b .Lus_0803740E\n"
    ".Lus_0803740C:\n"
    "    ldrh\tr0, [r7, #38]\t@ 0x26\n"
    ".Lus_0803740E:\n"
    "    strh\tr0, [r7, #36]\t@ 0x24\n"
    "    ldr\tr2, [r7, #16]\n"
    "    cmp\tr2, #0\n"
    "    beq .Lus_08037420\n"
    "    ldr\tr0, [r2, #4]\n"
    "    ldr\tr1, [r0, #12]\n"
    "    adds\tr0, r2, #0\n"
    "    bl _call_via_r1\n"
    ".Lus_08037420:\n"
    "    add\tsp, #96\t@ 0x60\n"
    "    pop\t{r3, r4}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "    .align 2, 0\n"
);

u32 RoamingNpcActor::vfunc_34()
{
    return unk_3C;
}

void RoamingNpcActor::vfunc_10()
{
    if (!unk_40)
        ResetLocation();
    behavior_countdown = 0;
    AEntity::vfunc_10();
}

void RoamingNpcActor::vfunc_14()
{
    AEntity::vfunc_14();
    unk_40 = false;
}

Box RoamingNpcActor::GetBox() const
{
    return Box(-7, -9, 7, 5, x_q16 >> 16, y_q16 >> 16);
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start SelectNextBehavior__20SouthTownRoamingNpc1\n"
    "SelectNextBehavior__20SouthTownRoamingNpc1:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    adds\tr6, r0, #0\n"
    "    ldr\tr0, [r6, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr1, r1, r2\n"
    "    ldr\tr1, [r1, #0]\n"
    "    bl _call_via_r1\n"
    "    ldrb\tr0, [r0, #10]\n"
    "    lsls\tr0, r0, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    movs\tr1, #0\n"
    "    subs\tr0, #6\n"
    "    cmp\tr0, #14\n"
    "    bls .Lus_080374B8\n"
    "    movs\tr1, #1\n"
    ".Lus_080374B8:\n"
    "    lsls\tr4, r1, #2\n"
    "    adds\tr4, r4, r1\n"
    "    lsls\tr4, r4, #2\n"
    "    ldr r0, .Lus_08037538\n"
    "    adds\tr4, r4, r0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #5\n"
    "    bl SelectActorBehaviorTimingIndex\n"
    "    lsls\tr1, r0, #2\n"
    "    adds\tr4, r4, r1\n"
    "    adds\tr7, r0, #0\n"
    "    movs\tr5, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    muls\tr0, r5\n"
    "    bl RandomBelow\n"
    "    ldrb\tr1, [r4, #1]\n"
    "    muls\tr1, r5\n"
    "    adds\tr5, r1, r0\n"
    "    movs\tr0, #4\n"
    "    bl RandomBelow\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_08037508\n"
    "    cmp\tr1, #3\n"
    "    beq .Lus_08037508\n"
    "    adds\tr4, r6, #0\n"
    "    adds\tr4, #32\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    bl GetRelativeFacing\n"
    "    adds\tr1, r0, #0\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, r1\n"
    "    beq .Lus_08037508\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetAnimFacing__12AActorEntityUi\n"
    ".Lus_08037508:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl GetBehaviorSpeed__C20SouthTownRoamingNpc1Ui\n"
    "    adds\tr1, r0, #0\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetRoamingSpeed__15RoamingNpcActori\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl GetBehaviorAnimation__C20SouthTownRoamingNpc1Ui\n"
    "    adds\tr1, r0, #0\n"
    "    ldrh\tr0, [r6, #34]\t@ 0x22\n"
    "    cmp\tr0, r1\n"
    "    beq .Lus_0803752E\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetAnim__12AActorEntityUi\n"
    ".Lus_0803752E:\n"
    "    adds\tr0, r5, #0\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    ".Lus_08037538: .word gUnk_080F1538\n"
);

EntityVisualController * SouthTownRoamingNpc1::CreateVisualController()
{
    return new EntitySpriteController(this, 2, 9, 0, 7, 0, false);
}

void SouthTownRoamingNpc1::ResetLocation()
{
    GameStateClock const & clock = *game_object->GetClock();
    u32 hour = clock.calendar.time.clock_hour;
    if (hour - 6 <= 9) {
        GameWeekday weekday = clock.calendar.GetWeekday();
        if (weekday.value != DAY_OF_WEEK_SUNDAY && clock.weather_today == WEATHER_SUNNY) {
            ActorLocation location;
            InitializeSouthTownNpcLocation1(&location, index);
            SetLocation(location);
            u32 animation = GetBehaviorAnimation(0);
            if (anim_id != animation)
                SetAnim(animation);
            return;
        }
    }
    PutOutOfTown();
}


u32 SouthTownRoamingNpc1::GetBehaviorAnimation(u32 behavior) const
{
    return gUnk_080F1560[behavior];
}

i32 SouthTownRoamingNpc1::GetBehaviorSpeed(u32 behavior) const
{
    switch (behavior)
    {
    case 1:
        return 0x8000;
    default:
        return 0;
    }
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start SelectNextBehavior__20SouthTownRoamingNpc2\n"
    "SelectNextBehavior__20SouthTownRoamingNpc2:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    adds\tr6, r0, #0\n"
    "    ldr\tr0, [r6, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr1, r1, r2\n"
    "    ldr\tr1, [r1, #0]\n"
    "    bl _call_via_r1\n"
    "    ldrb\tr0, [r0, #10]\n"
    "    lsls\tr0, r0, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    movs\tr1, #0\n"
    "    subs\tr0, #6\n"
    "    cmp\tr0, #14\n"
    "    bls .Lus_08037660\n"
    "    movs\tr1, #1\n"
    ".Lus_08037660:\n"
    "    lsls\tr4, r1, #3\n"
    "    subs\tr4, r4, r1\n"
    "    lsls\tr4, r4, #2\n"
    "    ldr r0, .Lus_080376E0\n"
    "    adds\tr4, r4, r0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #7\n"
    "    bl SelectActorBehaviorTimingIndex\n"
    "    lsls\tr1, r0, #2\n"
    "    adds\tr4, r4, r1\n"
    "    adds\tr7, r0, #0\n"
    "    movs\tr5, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    muls\tr0, r5\n"
    "    bl RandomBelow\n"
    "    ldrb\tr1, [r4, #1]\n"
    "    muls\tr1, r5\n"
    "    adds\tr5, r1, r0\n"
    "    movs\tr0, #4\n"
    "    bl RandomBelow\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_080376B0\n"
    "    cmp\tr1, #3\n"
    "    beq .Lus_080376B0\n"
    "    adds\tr4, r6, #0\n"
    "    adds\tr4, #32\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    bl GetRelativeFacing\n"
    "    adds\tr1, r0, #0\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, r1\n"
    "    beq .Lus_080376B0\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetAnimFacing__12AActorEntityUi\n"
    ".Lus_080376B0:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl GetBehaviorSpeed__C20SouthTownRoamingNpc2Ui\n"
    "    adds\tr1, r0, #0\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetRoamingSpeed__15RoamingNpcActori\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl GetBehaviorAnimation__C20SouthTownRoamingNpc2Ui\n"
    "    adds\tr1, r0, #0\n"
    "    ldrh\tr0, [r6, #34]\t@ 0x22\n"
    "    cmp\tr0, r1\n"
    "    beq .Lus_080376D6\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetAnim__12AActorEntityUi\n"
    ".Lus_080376D6:\n"
    "    adds\tr0, r5, #0\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    ".Lus_080376E0: .word gUnk_080F156C\n"
);

EntityVisualController * SouthTownRoamingNpc2::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 12, 2, 12, 0, false);
}

void SouthTownRoamingNpc2::ResetLocation()
{
    GameStateClock const & clock = *game_object->GetClock();
    u32 hour = clock.calendar.time.clock_hour;
    if (hour - 6 <= 9) {
        GameWeekday weekday = clock.calendar.GetWeekday();
        if (weekday.value != DAY_OF_WEEK_MONDAY && clock.weather_today == WEATHER_SUNNY) {
            ActorLocation location;
            InitializeSouthTownNpcLocation2(&location, index);
            SetLocation(location);
            u32 animation = GetBehaviorAnimation(0);
            if (anim_id != animation)
                SetAnim(animation);
            return;
        }
    }
    PutOutOfTown();
}


u32 SouthTownRoamingNpc2::GetBehaviorAnimation(u32 behavior) const
{
    return gUnk_080F15A4[behavior];
}

i32 SouthTownRoamingNpc2::GetBehaviorSpeed(u32 behavior) const
{
    switch (behavior)
    {
    case 1:
        return 0x8000;
    default:
        return 0;
    }
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start SelectNextBehavior__25YodelRanchHouseRoamingNpc\n"
    "SelectNextBehavior__25YodelRanchHouseRoamingNpc:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    adds\tr6, r0, #0\n"
    "    ldr\tr0, [r6, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr1, r1, r2\n"
    "    ldr\tr1, [r1, #0]\n"
    "    bl _call_via_r1\n"
    "    ldrb\tr0, [r0, #10]\n"
    "    lsls\tr0, r0, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    movs\tr4, #0\n"
    "    subs\tr0, #6\n"
    "    cmp\tr0, #14\n"
    "    bls .Lus_0803780C\n"
    "    movs\tr4, #1\n"
    ".Lus_0803780C:\n"
    "    movs\tr0, #52\t@ 0x34\n"
    "    muls\tr4, r0\n"
    "    ldr r0, .Lus_08037888\n"
    "    adds\tr4, r4, r0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #13\n"
    "    bl SelectActorBehaviorTimingIndex\n"
    "    lsls\tr1, r0, #2\n"
    "    adds\tr4, r4, r1\n"
    "    adds\tr7, r0, #0\n"
    "    movs\tr5, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    muls\tr0, r5\n"
    "    bl RandomBelow\n"
    "    ldrb\tr1, [r4, #1]\n"
    "    muls\tr1, r5\n"
    "    adds\tr5, r1, r0\n"
    "    movs\tr0, #4\n"
    "    bl RandomBelow\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_0803785A\n"
    "    cmp\tr1, #3\n"
    "    beq .Lus_0803785A\n"
    "    adds\tr4, r6, #0\n"
    "    adds\tr4, #32\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    bl GetRelativeFacing\n"
    "    adds\tr1, r0, #0\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, r1\n"
    "    beq .Lus_0803785A\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetAnimFacing__12AActorEntityUi\n"
    ".Lus_0803785A:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl GetBehaviorSpeed__C25YodelRanchHouseRoamingNpcUi\n"
    "    adds\tr1, r0, #0\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetRoamingSpeed__15RoamingNpcActori\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl GetBehaviorAnimation__C25YodelRanchHouseRoamingNpcUi\n"
    "    adds\tr1, r0, #0\n"
    "    ldrh\tr0, [r6, #34]\t@ 0x22\n"
    "    cmp\tr0, r1\n"
    "    beq .Lus_08037880\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetAnim__12AActorEntityUi\n"
    ".Lus_08037880:\n"
    "    adds\tr0, r5, #0\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    ".Lus_08037888: .word gUnk_080F15B4\n"
);

EntityVisualController * YodelRanchHouseRoamingNpc::CreateVisualController()
{
    return new EntitySpriteController(this, 2, 27, 0, 8, 0, false);
}

void YodelRanchHouseRoamingNpc::ResetLocation()
{
    ActorLocation location;
    InitializeYodelRanchHouseNpcLocation(&location);
    SetLocation(location);
    u32 animation = GetBehaviorAnimation(0);
    if (anim_id != animation)
        SetAnim(animation);
}

u32 YodelRanchHouseRoamingNpc::GetBehaviorAnimation(u32 behavior) const
{
    return gUnk_080F161C[behavior];
}

i32 YodelRanchHouseRoamingNpc::GetBehaviorSpeed(u32 behavior) const
{
    switch (behavior) {
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    default:
        return 0;
    case 1:
        return 0x8000;
    case 2:
    case 11:
        return 0x10000;
    }
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start SelectNextBehavior__24InnSecondFloorRoamingNpc\n"
    "SelectNextBehavior__24InnSecondFloorRoamingNpc:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    adds\tr6, r0, #0\n"
    "    ldr r5, .Lus_080379D4\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #3\n"
    "    bl SelectActorBehaviorTimingIndex\n"
    "    lsls\tr4, r0, #2\n"
    "    adds\tr4, r4, r5\n"
    "    adds\tr7, r0, #0\n"
    "    movs\tr5, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r4, #2]\n"
    "    muls\tr0, r5\n"
    "    bl RandomBelow\n"
    "    ldrb\tr1, [r4, #1]\n"
    "    muls\tr1, r5\n"
    "    adds\tr5, r1, r0\n"
    "    movs\tr0, #4\n"
    "    bl RandomBelow\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_080379A4\n"
    "    cmp\tr1, #3\n"
    "    beq .Lus_080379A4\n"
    "    adds\tr4, r6, #0\n"
    "    adds\tr4, #32\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    bl GetRelativeFacing\n"
    "    adds\tr1, r0, #0\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, r1\n"
    "    beq .Lus_080379A4\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetAnimFacing__12AActorEntityUi\n"
    ".Lus_080379A4:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl GetBehaviorSpeed__C24InnSecondFloorRoamingNpcUi\n"
    "    adds\tr1, r0, #0\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetRoamingSpeed__15RoamingNpcActori\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl GetBehaviorAnimation__C24InnSecondFloorRoamingNpcUi\n"
    "    adds\tr1, r0, #0\n"
    "    ldrh\tr0, [r6, #34]\t@ 0x22\n"
    "    cmp\tr0, r1\n"
    "    beq .Lus_080379CA\n"
    "    adds\tr0, r6, #0\n"
    "    bl SetAnim__12AActorEntityUi\n"
    ".Lus_080379CA:\n"
    "    adds\tr0, r5, #0\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    ".Lus_080379D4: .word gUnk_080F1638\n"
);
EntityVisualController * InnSecondFloorRoamingNpc::CreateVisualController()
{
    return new EntitySpriteController(this, 2, 27, 0, 8, 0, false);
}
asm_unified(
);

void InnSecondFloorRoamingNpc::ResetLocation()
{
    ActorLocation location;
    InitializeInnSecondFloorNpcLocation(&location);
    SetLocation(location);
    u32 animation = GetBehaviorAnimation(0);
    if (anim_id != animation)
        SetAnim(animation);
}

u32 InnSecondFloorRoamingNpc::GetBehaviorAnimation(u32 behavior) const
{
    return gUnk_080F1644[behavior];
}

i32 InnSecondFloorRoamingNpc::GetBehaviorSpeed(u32 behavior) const
{
    switch (behavior)
    {
    case 1:
        return 0x8000;
    default:
        return 0;
    }
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start CreateSouthTownRoamingNpc1\n"
    "CreateSouthTownRoamingNpc1:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    mov\tr6, r8\n"
    "    push\t{r6}\n"
    "    sub\tsp, #12\n"
    "    adds\tr6, r0, #0\n"
    "    mov\tr8, r1\n"
    "    adds\tr4, r2, #0\n"
    "    movs\tr0, #72\t@ 0x48\n"
    "    bl __builtin_new\n"
    "    adds\tr5, r0, #0\n"
    "    movs\tr0, #0\n"
    "    str\tr0, [sp, #0]\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr1, r6, #0\n"
    "    mov\tr2, r8\n"
    "    ldr r3, .Lus_08037AC8\n"
    "    bl __15RoamingNpcActorP10GameObjectP13ActorLocationUiUi\n"
    "    ldr r0, .Lus_08037ACC\n"
    "    str\tr0, [r5, #20]\n"
    "    adds\tr2, r5, #0\n"
    "    adds\tr2, #68\t@ 0x44\n"
    "    movs\tr0, #3\n"
    "    ands\tr4, r0\n"
    "    ldrb\tr1, [r2, #0]\n"
    "    movs\tr0, #4\n"
    "    negs\tr0, r0\n"
    "    ands\tr0, r1\n"
    "    orrs\tr0, r4\n"
    "    strb\tr0, [r2, #0]\n"
    "    add\tr2, sp, #4\n"
    "    movs\tr1, #176\t@ 0xb0\n"
    "    lsls\tr1, r1, #1\n"
    "    movs\tr3, #216\t@ 0xd8\n"
    "    adds\tr0, r2, #0\n"
    "    strh\tr1, [r0, #0]\n"
    "    strh\tr3, [r2, #2]\n"
    "    adds\tr1, #56\t@ 0x38\n"
    "    strh\tr1, [r2, #4]\n"
    "    movs\tr0, #232\t@ 0xe8\n"
    "    strh\tr0, [r2, #6]\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr1, r2, #0\n"
    "    bl SetAvoidanceBox__15RoamingNpcActorRC3Box\n"
    "    adds\tr0, r5, #0\n"
    "    add\tsp, #12\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    ".Lus_08037AC8: .word 0x0000071C\n"
    ".Lus_08037ACC: .word __vt_20SouthTownRoamingNpc1\n"
    "    thumb_func_start CreateSouthTownRoamingNpc2\n"
    "CreateSouthTownRoamingNpc2:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    mov\tr6, r8\n"
    "    push\t{r6}\n"
    "    sub\tsp, #12\n"
    "    adds\tr6, r0, #0\n"
    "    mov\tr8, r1\n"
    "    adds\tr4, r2, #0\n"
    "    movs\tr0, #72\t@ 0x48\n"
    "    bl __builtin_new\n"
    "    adds\tr5, r0, #0\n"
    "    movs\tr0, #11\n"
    "    str\tr0, [sp, #0]\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr1, r6, #0\n"
    "    mov\tr2, r8\n"
    "    movs\tr3, #171\t@ 0xab\n"
    "    lsls\tr3, r3, #2\n"
    "    bl __15RoamingNpcActorP10GameObjectP13ActorLocationUiUi\n"
    "    ldr r0, .Lus_08037B44\n"
    "    str\tr0, [r5, #20]\n"
    "    adds\tr2, r5, #0\n"
    "    adds\tr2, #68\t@ 0x44\n"
    "    movs\tr0, #3\n"
    "    ands\tr4, r0\n"
    "    ldrb\tr1, [r2, #0]\n"
    "    movs\tr0, #4\n"
    "    negs\tr0, r0\n"
    "    ands\tr0, r1\n"
    "    orrs\tr0, r4\n"
    "    strb\tr0, [r2, #0]\n"
    "    add\tr3, sp, #4\n"
    "    movs\tr1, #230\t@ 0xe6\n"
    "    lsls\tr1, r1, #2\n"
    "    movs\tr2, #144\t@ 0x90\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r3, #0\n"
    "    strh\tr1, [r0, #0]\n"
    "    strh\tr2, [r3, #2]\n"
    "    movs\tr0, #164\t@ 0xa4\n"
    "    lsls\tr0, r0, #1\n"
    "    adds\tr1, r1, r0\n"
    "    strh\tr1, [r3, #4]\n"
    "    adds\tr2, #8\n"
    "    strh\tr2, [r3, #6]\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr1, r3, #0\n"
    "    bl SetAvoidanceBox__15RoamingNpcActorRC3Box\n"
    "    adds\tr0, r5, #0\n"
    "    add\tsp, #12\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    ".Lus_08037B44: .word __vt_20SouthTownRoamingNpc2\n"
    "    thumb_func_start CreateYodelRanchHouseRoamingNpc\n"
    "CreateYodelRanchHouseRoamingNpc:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr6, r1, #0\n"
    "    movs\tr0, #68\t@ 0x44\n"
    "    bl __builtin_new\n"
    "    adds\tr4, r0, #0\n"
    "    movs\tr0, #12\n"
    "    str\tr0, [sp, #0]\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr2, r6, #0\n"
    "    ldr r3, .Lus_08037B78\n"
    "    bl __15RoamingNpcActorP10GameObjectP13ActorLocationUiUi\n"
    "    ldr r0, .Lus_08037B7C\n"
    "    str\tr0, [r4, #20]\n"
    "    adds\tr0, r4, #0\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    ".Lus_08037B78: .word 0x00000379\n"
    ".Lus_08037B7C: .word __vt_25YodelRanchHouseRoamingNpc\n"
    "    thumb_func_start CreateInnSecondFloorRoamingNpc\n"
    "CreateInnSecondFloorRoamingNpc:\n"
    "    push\t{r4, r5, r6, lr}\n"
    "    sub\tsp, #4\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr6, r1, #0\n"
    "    movs\tr0, #68\t@ 0x44\n"
    "    bl __builtin_new\n"
    "    adds\tr4, r0, #0\n"
    "    movs\tr0, #10\n"
    "    str\tr0, [sp, #0]\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr1, r5, #0\n"
    "    adds\tr2, r6, #0\n"
    "    ldr r3, .Lus_08037BB0\n"
    "    bl __15RoamingNpcActorP10GameObjectP13ActorLocationUiUi\n"
    "    ldr r0, .Lus_08037BB4\n"
    "    str\tr0, [r4, #20]\n"
    "    adds\tr0, r4, #0\n"
    "    add\tsp, #4\n"
    "    pop\t{r4, r5, r6}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    ".Lus_08037BB0: .word 0x00000207\n"
    ".Lus_08037BB4: .word __vt_24InnSecondFloorRoamingNpc\n"
);

InnSecondFloorRoamingNpc::InnSecondFloorRoamingNpc(GameObject * game_object,
    ActorLocation * saved_location)
    : RoamingNpcActor(game_object, saved_location, 0x207, 10)
{
}

YodelRanchHouseRoamingNpc::YodelRanchHouseRoamingNpc(GameObject * game_object,
    ActorLocation * saved_location)
    : RoamingNpcActor(game_object, saved_location, 0x379, 12)
{
}

SouthTownRoamingNpc2::SouthTownRoamingNpc2(GameObject * game_object,
    ActorLocation * saved_location, u32 index)
    : RoamingNpcActor(game_object, saved_location, ANIMATION_COW_IDLE, 11),
      index(index)
{
    SetAvoidanceBox(Box(0, 0, 328, 8, 920, 288));
}

SouthTownRoamingNpc1::SouthTownRoamingNpc1(GameObject * game_object,
    ActorLocation * saved_location, u32 index)
    : RoamingNpcActor(game_object, saved_location, ANIMATION_CHICKEN_IDLE, 0),
      index(index)
{
    SetAvoidanceBox(Box(0, 0, 56, 16, 352, 216));
}
