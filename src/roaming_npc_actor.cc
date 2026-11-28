
#pragma implementation "roaming_npc_actor.cc"
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

void RoamingNpcActor::ApplyRoamingMovement(ActorMovementBounds * bounds)
{
    ActorMovementBounds & limits = *bounds;
    i32 old_x_q16 = x_q16;
    i32 old_y_q16 = y_q16;
    i32 next_x_q16 = old_x_q16 + x_speed_q16;
    i32 next_y_q16 = old_y_q16 + y_speed_q16;
    i32 old_x = old_x_q16 >> 16;
    i32 old_y = old_y_q16 >> 16;
    i32 dy = (next_y_q16 >> 16) - old_y;
    i32 dx = (next_x_q16 >> 16) - old_x;
    if (dy > 0 && dy > limits.GetDown())
        next_y_q16 = (old_y + limits.GetDown()) << 16;
    if (dy < 0 && dy < limits.GetUp())
        next_y_q16 = (old_y + limits.GetUp()) << 16;
    if (dx < 0 && dx < limits.GetLeft())
        next_x_q16 = (old_x + limits.GetLeft()) << 16;
    if (dx > 0 && dx > limits.GetRight())
        next_x_q16 = (old_x + limits.GetRight()) << 16;
    x_q16 = next_x_q16;
    y_q16 = next_y_q16;
}

void RoamingNpcActor::SetAvoidanceBox(Box const & box)
{
    avoidance_box = box;
}

void RoamingNpcActor::ClearAvoidanceBox()
{
    Box empty(0, 0);
    avoidance_box = empty;
}

void RoamingNpcActor::Update(EntityUpdateContext const & context)
{
    GameObject * world = game_object;
    u32 map = GetMap();
    if (world->vfunc_14() == map) {
        MapTerrainView const & terrain = world->GetMapTerrain(map);
        Box const & box = GetBox();
        ActorMovementBounds bounds(terrain, box, 32);
        AEntity * player = game_object->GetEntity(ENTITY_PLAYER);
        if (player != nullptr && player->GetMap() == map)
            bounds.ClipAgainstBox(player->GetBox(), 0);
        AEntity * basket = game_object->GetEntity(ENTITY_BASKET);
        if (basket != nullptr && basket->GetMap() == map)
            bounds.ClipAgainstBox(basket->GetBox(), 0);
        Box const & avoidance = avoidance_box;
        if (avoidance.x2 - avoidance.x1 > 0 && avoidance.y2 - avoidance.y1 > 0)
            bounds.ClipAgainstBox(avoidance, 0);
        u32 remaining = behavior_countdown;
        if (remaining != 0) {
            i32 dx = x_speed_q16;
            i32 dy = y_speed_q16;
            if ((dx < 0 && bounds.GetLeft() >= 0)
                || (dx > 0 && bounds.GetRight() <= 0)
                || (dy < 0 && bounds.GetUp() >= 0)
                || (dy > 0 && bounds.GetDown() <= 0))
                remaining = 0;
            else
                --remaining;
        } else {
            remaining = SelectNextBehavior();
        }
        behavior_countdown = remaining;
        ApplyRoamingMovement(&bounds);
    }
    if (animation_countdown != 0)
        --animation_countdown;
    else
        animation_countdown = animation_reload;
    if (unk_10.Get() != nullptr)
        unk_10->Update();
}

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

#pragma interface "roaming_npc_actor.cc"
inline SouthTownRoamingNpc1::SouthTownRoamingNpc1(GameObject * game_object,
    ActorLocation * saved_location, u32 index)
    : RoamingNpcActor(game_object, saved_location, ANIMATION_CHICKEN_IDLE, 0),
      index(index)
{
    SetAvoidanceBox(Box(0, 0, 56, 16, 352, 216));
}


inline SouthTownRoamingNpc2::SouthTownRoamingNpc2(GameObject * game_object,
    ActorLocation * saved_location, u32 index)
    : RoamingNpcActor(game_object, saved_location, ANIMATION_COW_IDLE, 11),
      index(index)
{
    SetAvoidanceBox(Box(0, 0, 328, 8, 920, 288));
}


inline YodelRanchHouseRoamingNpc::YodelRanchHouseRoamingNpc(GameObject * game_object,
    ActorLocation * saved_location)
    : RoamingNpcActor(game_object, saved_location, 0x379, 12)
{
}


inline InnSecondFloorRoamingNpc::InnSecondFloorRoamingNpc(GameObject * game_object,
    ActorLocation * saved_location)
    : RoamingNpcActor(game_object, saved_location, 0x207, 10)
{
}


RoamingNpcActor * CreateSouthTownRoamingNpc1(GameObject * game_object,
    ActorLocation * saved_location, u32 index)
{
    return new SouthTownRoamingNpc1(game_object, saved_location, index);
}

RoamingNpcActor * CreateSouthTownRoamingNpc2(GameObject * game_object,
    ActorLocation * saved_location, u32 index)
{
    return new SouthTownRoamingNpc2(game_object, saved_location, index);
}

RoamingNpcActor * CreateYodelRanchHouseRoamingNpc(GameObject * game_object,
    ActorLocation * saved_location)
{
    return new YodelRanchHouseRoamingNpc(game_object, saved_location);
}

RoamingNpcActor * CreateInnSecondFloorRoamingNpc(GameObject * game_object,
    ActorLocation * saved_location)
{
    return new InnSecondFloorRoamingNpc(game_object, saved_location);
}
