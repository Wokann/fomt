
#include "wild_dog_actor.hh"
#include "game_object.hh"
#include "actor_runtime_data.hh"

#include <new>
#include FOMT_TEXT_INCLUDE(wild_dog_actor.cc)
#include "random.hh"
#include <stdlib.h>
extern "C" u16 const gWildDogMotionAnimations[] = {
    0x09BF, 0x09C3, 0x09C7, 0x09CB, 0x09CF,
};

// Slot 45 owns this visiting dog. The imported ENTITY_FRISBEE name
// conflicts with the factory, livestock targeting and dog animation frames.
asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);

static inline i32 SquaredPixelDistance(AEntity const & entity, i32 x, i32 y)
{
    i32 dx = (entity.GetQ16X() >> 16) - x;
    i32 dy = (entity.GetQ16Y() >> 16) - y;
    return dx * dx + dy * dy;
}

u32 FindNearestWildDogTarget(GameObject * world, u32 map, i32 x, i32 y)
{
    u32 nearest = 100;
    i32 nearest_distance = 0;
    for (i32 id = ENTITY_ANIMAL_CHICKEN_SLOT_1; id <= ENTITY_BARN_ANIMAL_SLOT_16; ++id) {
        AnimalActor * animal = static_cast<AnimalActor *>(world->GetEntity(id));
        if (animal != nullptr && animal->GetMap() == map && animal->CanBeAttackedByWildDog()) {
            i32 distance = SquaredPixelDistance(*animal, x, y);
            if (nearest == 100 || nearest_distance > distance) {
                nearest = id;
                nearest_distance = distance;
            }
        }
    }
    return nearest;
}

bool IsWildDogExitCorridor(i32 x, i32 y)
{
    if (y <= 56 && x > 0x143 && x <= 0x164)
        return true;
    if (y <= 0x27F)
        return false;
    else if (x <= 247)
        return false;
    else if (x > 280)
        return false;
    else
        return true;
}

void WildDogState0::Update(WildDogActor * actor, ActorMovementBounds * bounds)
{
}

u32 WildDogState0::GetMotion(WildDogActor const * actor) const
{
    return 0;
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start Update__13WildDogState1P12WildDogActorP19ActorMovementBounds\n"
    "Update__13WildDogState1P12WildDogActorP19ActorMovementBounds:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #24\n"
    "    adds\tr5, r1, #0\n"
    "    str\tr2, [sp, #16]\n"
    "    ldr\tr0, [r5, #52]\t@ 0x34\n"
    "    mov\tr8, r0\n"
    "    mov\tr1, r8\n"
    "    adds\tr1, #16\n"
    "    str\tr1, [sp, #20]\n"
    "    mov\tr2, r8\n"
    "    ldrh\tr4, [r2, #16]\n"
    "    cmp\tr4, #0\n"
    "    beq .LwildDog_08039228\n"
    "    subs\tr4, #1\n"
    ".LwildDog_08039228:\n"
    "    ldrh\tr3, [r5, #4]\n"
    "    mov\tip, r3\n"
    "    movs\tr1, #10\n"
    "    ldrsh\tr0, [r5, r1]\n"
    "    mov\tr9, r0\n"
    "    movs\tr2, #14\n"
    "    ldrsh\tr7, [r5, r2]\n"
    "    movs\tr0, #176\t@ 0xb0\n"
    "    lsls\tr0, r0, #1\n"
    "    cmp\tr7, r0\n"
    "    ble .LwildDog_0803924A\n"
    "    add\tr3, sp, #8\n"
    "    movs\tr1, #132\t@ 0x84\n"
    "    lsls\tr1, r1, #1\n"
    "    movs\tr2, #180\t@ 0xb4\n"
    "    lsls\tr2, r2, #2\n"
    "    b .LwildDog_08039254\n"
    ".LwildDog_0803924A:\n"
    "    add\tr3, sp, #8\n"
    "    movs\tr1, #170\t@ 0xaa\n"
    "    lsls\tr1, r1, #1\n"
    "    movs\tr2, #16\n"
    "    negs\tr2, r2\n"
    ".LwildDog_08039254:\n"
    "    adds\tr0, r3, #0\n"
    "    strh\tr1, [r0, #0]\n"
    "    strh\tr2, [r3, #2]\n"
    "    add\tr1, sp, #8\n"
    "    adds\tr0, r1, #0\n"
    "    movs\tr2, #0\n"
    "    ldrsh\tr3, [r0, r2]\n"
    "    mov\tsl, r3\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr6, [r1, r3]\n"
    "    mov\tr0, ip\n"
    "    cmp\tr0, #2\n"
    "    bne .LwildDog_080392EA\n"
    "    mov\tr1, sl\n"
    "    mov\tr2, r9\n"
    "    subs\tr0, r1, r2\n"
    "    cmp\tr0, #0\n"
    "    bge .LwildDog_0803927A\n"
    "    negs\tr0, r0\n"
    ".LwildDog_0803927A:\n"
    "    cmp\tr0, #15\n"
    "    bgt .LwildDog_0803928A\n"
    "    subs\tr0, r6, r7\n"
    "    cmp\tr0, #0\n"
    "    bge .LwildDog_08039286\n"
    "    negs\tr0, r0\n"
    ".LwildDog_08039286:\n"
    "    cmp\tr0, #15\n"
    "    ble .LwildDog_080392EA\n"
    ".LwildDog_0803928A:\n"
    "    cmp\tr4, #0\n"
    "    bne .LwildDog_080392E4\n"
    "    mov\tr0, r9\n"
    "    adds\tr1, r7, #0\n"
    "    bl IsWildDogExitCorridor\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .LwildDog_080392B6\n"
    "    movs\tr1, #0\n"
    "    cmp\tr7, r6\n"
    "    blt .LwildDog_080392A4\n"
    "    movs\tr1, #1\n"
    ".LwildDog_080392A4:\n"
    "    adds\tr0, r5, #0\n"
    "    adds\tr0, #32\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, r1\n"
    "    beq .LwildDog_080392DC\n"
    "    adds\tr0, r5, #0\n"
    "    bl SetAnimFacing__12AActorEntityUi\n"
    "    b .LwildDog_080392DC\n"
    ".LwildDog_080392B6:\n"
    "    adds\tr4, r5, #0\n"
    "    adds\tr4, #32\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    ldr\tr3, [sp, #16]\n"
    "    str\tr3, [sp, #0]\n"
    "    str\tr0, [sp, #4]\n"
    "    mov\tr0, r9\n"
    "    adds\tr1, r7, #0\n"
    "    mov\tr2, sl\n"
    "    adds\tr3, r6, #0\n"
    "    bl SelectApproachFacing\n"
    "    adds\tr1, r0, #0\n"
    "    ldrb\tr0, [r4, #0]\n"
    "    cmp\tr0, r1\n"
    "    beq .LwildDog_080392DC\n"
    "    adds\tr0, r5, #0\n"
    "    bl SetAnimFacing__12AActorEntityUi\n"
    ".LwildDog_080392DC:\n"
    "    movs\tr0, #30\n"
    "    bl RandomBelow\n"
    "    adds\tr4, r0, #1\n"
    ".LwildDog_080392E4:\n"
    "    ldr\tr0, [sp, #20]\n"
    "    strh\tr4, [r0, #0]\n"
    "    b .LwildDog_080392FC\n"
    ".LwildDog_080392EA:\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #141\t@ 0x8d\n"
    "    lsls\tr1, r1, #2\n"
    "    bl SetMap__7AEntityUi\n"
    "    add\tr1, sp, #12\n"
    "    mov\tr0, r8\n"
    "    bl SetWildDogInactiveState\n"
    ".LwildDog_080392FC:\n"
    "    add\tsp, #24\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
);

u32 WildDogState1::GetMotion(WildDogActor const * actor) const
{
    return 1;
}

static inline void SelectNextWildDogState(WildDogActor * actor)
{
    Unk_Actor_0809BFE8 * saved = actor->saved_model;
    u32 target = 100;
    if (func_0809C060(*saved) != 0)
        target = FindNearestWildDogTarget(actor->GetGameObject(), actor->GetMap(),
            actor->GetQ16X() >> 16, actor->GetQ16Y() >> 16);
    else
        actor->RequestSound(0xAA);
    if (target != 100) {
        if (RandomBelow(100) < 70) {
            WildDogChaseState state;
            state.frames_remaining = 0;
            state.attempts_remaining = RandomBelow(8) + 3;
            state.target_entity = target;
            SetWildDogChaseState(*saved, state);
        } else {
            WildDogAttackPayload state;
            state.fields.frames_remaining = RandomBelow(60) + 120;
            state.fields.attacking = 0;
            state.fields.target_entity = target;
            SetWildDogAttackState(*saved, state);
        }
    } else {
        WildDogDeparturePayload state;
        state.fields.retarget_frames = 180;
        SetWildDogDepartureState(*saved, state);
    }
}

void WildDogState2::Update(WildDogActor * actor, ActorMovementBounds * bounds)
{
    Unk_Actor_0809BFE8 * saved = actor->saved_model;
    WildDogChaseState & state = saved->chase;
    GameObject * world = actor->GetGameObject();
    u32 attempts = state.attempts_remaining;
    u32 remaining = state.frames_remaining;
    if (remaining != 0) {
        --remaining;
        if (remaining == 0 && attempts != 0)
            --attempts;
    }
    AnimalActor * animal = static_cast<AnimalActor *>(world->GetEntity(state.target_entity));
    if (animal != nullptr && animal->GetMap() == actor->GetMap() && animal->CanBeAttackedByWildDog()) {
        i32 x = actor->GetQ16X() >> 16;
        i32 y = actor->GetQ16Y() >> 16;
        i32 target_x = animal->GetQ16X() >> 16;
        i32 target_y = animal->GetQ16Y() >> 16;
        if (attempts != 0 && (abs(target_x - x) > 15 || abs(target_y - y) > 15)) {
            if (remaining == 0 || (abs(state.last_target_x - x) <= 15 && abs(state.last_target_y - y) <= 15)) {
                if (IsWildDogExitCorridor(x, y)) {
                    u32 facing = y < target_y ? 0 : 1;
                    if (actor->facing != facing)
                        actor->SetAnimFacing(facing);
                } else {
                    u32 facing = actor->GetFacing();
                    facing = SelectApproachFacing(x, y, target_x, target_y, *bounds, facing);
                    actor->SetFacingIfChanged(facing);
                }
                remaining = RandomBelow(30) + 1;
                state.last_target_x = target_x;
                state.last_target_y = target_y;
            }
            state.attempts_remaining = attempts;
            state.frames_remaining = remaining;
            return;
        }
        WildDogAttackPayload attack;
        attack.fields.frames_remaining = 36;
        attack.fields.attacking = 1;
        attack.fields.target_entity = state.target_entity;
        SetWildDogAttackState(*saved, attack);
        actor->RequestSound(0xAB);
        return;
    }
    SelectNextWildDogState(actor);
}



void WildDogState3::Update(WildDogActor * actor, ActorMovementBounds * bounds)
{
    Unk_Actor_0809BFE8 * saved = actor->saved_model;
    WildDogAttackState & state = saved->attack;
    u32 remaining = state.frames_remaining;
    if (remaining != 0)
        --remaining;
    if (remaining == 0) {
        if (state.attacking != 0) {
            GameObject * world = actor->GetGameObject();
            u32 map = actor->GetMap();
            i32 x = actor->GetQ16X() >> 16;
            i32 y = actor->GetQ16Y() >> 16;
            u32 target = FindNearestWildDogTarget(world, map, x, y);
            if (target == 100)
                target = state.target_entity;
            AnimalActor * animal = static_cast<AnimalActor *>(world->GetEntity(target));
            if (animal != nullptr && animal->GetMap() == map && animal->CanBeAttackedByWildDog()) {
                i32 target_x = animal->GetQ16X() >> 16;
                i32 target_y = animal->GetQ16Y() >> 16;
                if (abs(target_x - x) <= 15 && abs(target_y - y) <= 15)
                    animal->ReactToDogAttack();
            }
            func_0809C068(*saved, 4);
            SelectNextWildDogState(actor);
            return;
        }
        remaining = 36;
        state.attacking = 1;
        actor->RequestSound(0xAB);
    }
    state.frames_remaining = remaining;
}

u32 WildDogState3::GetMotion(WildDogActor const * actor) const
{
    return actor->saved_model->attack.attacking ? 3 : 0;
}

void WildDogState4::Update(WildDogActor * actor, ActorMovementBounds * bounds)
{
    AnimalReactionPayload & state = actor->saved_model->reaction;
    GameObject & world = *actor->GetGameObject();
    u32 remaining = state.bits.frames_remaining;
    if (remaining != 0)
        --remaining;
    AnimalReactionPayload::WordBits const flags = state.word_bits;
    u32 retreat = flags.retreat_frames;
    if (retreat != 0)
        --retreat;
    u32 retarget = state.bits.retarget_frames;
    if (retarget != 0)
        --retarget;
    if (remaining != 0) {
        AEntity * target = world.GetEntity(flags.target_is_dog ? ENTITY_FARM_DOG : ENTITY_PLAYER);
        if (target != nullptr && target->GetMap() == actor->GetMap()) {
            if (retarget == 0) {
                i32 x = actor->GetQ16X() >> 16;
                i32 y = actor->GetQ16Y() >> 16;
                i32 target_x = target->GetQ16X() >> 16;
                i32 target_y = target->GetQ16Y() >> 16;
                u32 facing = actor->GetFacing();
                facing = SelectRetreatFacing(x, y, target_x, target_y, *bounds, facing);
                actor->SetFacingIfChanged(facing);
                retarget = RandomBelow(30) + 1;
            }
            state.bits.frames_remaining = remaining;
            state.bits.retreat_frames = retreat;
            state.bits.retarget_frames = retarget;
            return;
        }
    }
    StopActorSpriteEffect(*actor);
    SelectNextWildDogState(actor);
}



u32 WildDogState4::GetMotion(WildDogActor const * actor) const
{
    return 2;
}

WildDogActor::WildDogActor(GameObject * world, Unk_Actor_0809BFE8 * saved)
    : AnimalActor(world, Actor(*saved).location, 0x9C7), saved_model(saved)
{
    behaviors[0] = new WildDogState0();
    behaviors[1] = new WildDogState1();
    behaviors[2] = new WildDogState2();
    behaviors[3] = new WildDogState3();
    behaviors[4] = new WildDogState4();

    u32 motion = behaviors[saved_model->behavior_state]->GetMotion(this);

    SetMovementSpeed(GetWildDogMotionSpeed(this, motion));
    SetAnimIfChanged(GetWildDogMotionAnimation(this, motion));

    cached_motion = motion;
    cached_facing = facing;
}

WildDogActor::~WildDogActor()
{
    saved_model->SetLocation(GetLocation());
}

EntityVisualController * WildDogActor::CreateVisualController()
{
    return new EntitySpriteController(this, 2, 27, 0, 8, 0, false);
}

void WildDogActor::PauseMovement(u32 frames)
{
}

asm_unified(
    "    .align 2, 0\n"
    "    thumb_func_start Update__12WildDogActorRC19EntityUpdateContext\n"
    "Update__12WildDogActorRC19EntityUpdateContext:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #112\t@ 0x70\n"
    "    adds\tr7, r0, #0\n"
    "    ldr\tr0, [r7, #0]\n"
    "    mov\tsl, r0\n"
    "    ldrb\tr0, [r1, #4]\n"
    "    cmp\tr0, #0\n"
    "    bne .LwildDog_08039A7A\n"
    "    b .LwildDog_08039BAC\n"
    ".LwildDog_08039A7A:\n"
    "    ldrh\tr0, [r7, #4]\n"
    "    cmp\tr0, #2\n"
    "    bne .LwildDog_08039A82\n"
    "    b .LwildDog_08039BAC\n"
    ".LwildDog_08039A82:\n"
    "    mov\tr1, sl\n"
    "    ldr\tr0, [r1, #0]\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r0, r2\n"
    "    ldr\tr1, [r0, #0]\n"
    "    mov\tr0, sl\n"
    "    bl _call_via_r1\n"
    "    adds\tr2, r0, #0\n"
    "    ldrh\tr1, [r2, #10]\n"
    "    ldr r0, .LwildDog_08039AC0\n"
    "    ands\tr0, r1\n"
    "    cmp\tr0, #20\n"
    "    beq .LwildDog_08039AA2\n"
    "    b .LwildDog_08039BAC\n"
    ".LwildDog_08039AA2:\n"
    "    ldr\tr0, [r2, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .LwildDog_08039AAA\n"
    "    b .LwildDog_08039BAC\n"
    ".LwildDog_08039AAA:\n"
    "    movs\tr0, #2\n"
    "    bl RandomBelow\n"
    "    cmp\tr0, #0\n"
    "    beq .LwildDog_08039AC4\n"
    "    add\tr0, sp, #68\t@ 0x44\n"
    "    movs\tr1, #132\t@ 0x84\n"
    "    lsls\tr1, r1, #1\n"
    "    movs\tr2, #180\t@ 0xb4\n"
    "    lsls\tr2, r2, #2\n"
    "    b .LwildDog_08039ACE\n"
    ".LwildDog_08039AC0: .word 0x000007FF\n"
    ".LwildDog_08039AC4:\n"
    "    add\tr0, sp, #68\t@ 0x44\n"
    "    movs\tr1, #170\t@ 0xaa\n"
    "    lsls\tr1, r1, #1\n"
    "    movs\tr2, #16\n"
    "    negs\tr2, r2\n"
    ".LwildDog_08039ACE:\n"
    "    strh\tr1, [r0, #0]\n"
    "    strh\tr2, [r0, #2]\n"
    "    ldr\tr0, [sp, #68]\t@ 0x44\n"
    "    str\tr0, [sp, #72]\t@ 0x48\n"
    "    add\tr4, sp, #72\t@ 0x48\n"
    "    movs\tr3, #0\n"
    "    ldrsh\tr2, [r4, r3]\n"
    "    movs\tr6, #2\n"
    "    ldrsh\tr3, [r4, r6]\n"
    "    mov\tr0, sl\n"
    "    movs\tr1, #2\n"
    "    bl FindNearestWildDogTarget\n"
    "    str\tr0, [sp, #108]\t@ 0x6c\n"
    "    cmp\tr0, #100\t@ 0x64\n"
    "    beq .LwildDog_08039BAC\n"
    "    movs\tr0, #100\t@ 0x64\n"
    "    bl RandomBelow\n"
    "    cmp\tr0, #14\n"
    "    bhi .LwildDog_08039BAC\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr6, [r4, r0]\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr1, [r4, r2]\n"
    "    mov\tr8, r1\n"
    "    mov\tr3, sp\n"
    "    movs\tr2, #2\n"
    "    ldrh\tr1, [r3, #0]\n"
    "    ldr r4, .LwildDog_08039D18\n"
    "    adds\tr0, r4, #0\n"
    "    ands\tr0, r1\n"
    "    orrs\tr0, r2\n"
    "    strh\tr0, [r3, #0]\n"
    "    lsls\tr6, r6, #16\n"
    "    lsrs\tr1, r6, #16\n"
    "    movs\tr0, #63\t@ 0x3f\n"
    "    mov\tr9, r0\n"
    "    ands\tr1, r0\n"
    "    lsls\tr1, r1, #2\n"
    "    ldrb\tr5, [r3, #1]\n"
    "    movs\tr2, #3\n"
    "    adds\tr0, r2, #0\n"
    "    ands\tr0, r5\n"
    "    orrs\tr0, r1\n"
    "    strb\tr0, [r3, #1]\n"
    "    lsrs\tr6, r6, #22\n"
    "    ldrh\tr1, [r3, #2]\n"
    "    adds\tr0, r4, #0\n"
    "    ands\tr0, r1\n"
    "    orrs\tr0, r6\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr1, r8\n"
    "    lsls\tr1, r1, #16\n"
    "    mov\tr8, r1\n"
    "    lsrs\tr0, r1, #16\n"
    "    mov\tr6, r9\n"
    "    ands\tr0, r6\n"
    "    lsls\tr0, r0, #2\n"
    "    ldrb\tr1, [r3, #3]\n"
    "    ands\tr2, r1\n"
    "    orrs\tr2, r0\n"
    "    strb\tr2, [r3, #3]\n"
    "    mov\tr0, r8\n"
    "    lsrs\tr0, r0, #22\n"
    "    mov\tr8, r0\n"
    "    ldrh\tr0, [r3, #4]\n"
    "    ands\tr4, r0\n"
    "    mov\tr1, r8\n"
    "    orrs\tr4, r1\n"
    "    strh\tr4, [r3, #4]\n"
    "    add\tr4, sp, #8\n"
    "    movs\tr5, #1\n"
    "    adds\tr0, r4, #0\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #6\n"
    "    bl memcpy\n"
    "    strb\tr5, [r4, #6]\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r4, #0\n"
    "    bl SetLocation__12AActorEntityRC13ActorLocation\n"
    "    ldr r1, .LwildDog_08039D1C\n"
    "    ldr\tr0, [sp, #76]\t@ 0x4c\n"
    "    ands\tr0, r1\n"
    "    str\tr0, [sp, #76]\t@ 0x4c\n"
    "    movs\tr0, #8\n"
    "    bl RandomBelow\n"
    "    adds\tr0, #3\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #8\n"
    "    ldr r3, .LwildDog_08039D20\n"
    "    add\tr1, sp, #76\t@ 0x4c\n"
    "    ldr\tr2, [r1, #4]\n"
    "    ands\tr2, r3\n"
    "    orrs\tr2, r0\n"
    "    ldr\tr6, [sp, #108]\t@ 0x6c\n"
    "    lsls\tr3, r6, #24\n"
    "    ldr r0, .LwildDog_08039D24\n"
    "    ands\tr2, r0\n"
    "    orrs\tr2, r3\n"
    "    str\tr2, [r1, #4]\n"
    "    ldr\tr0, [r7, #52]\t@ 0x34\n"
    "    bl SetWildDogChaseState\n"
    "    adds\tr0, r7, #0\n"
    "    movs\tr1, #171\t@ 0xab\n"
    "    bl RequestSound__11AnimalActorUi\n"
    ".LwildDog_08039BAC:\n"
    "    ldrh\tr5, [r7, #4]\n"
    "    movs\tr0, #141\t@ 0x8d\n"
    "    lsls\tr0, r0, #2\n"
    "    cmp\tr5, r0\n"
    "    bne .LwildDog_08039BB8\n"
    "    b .LwildDog_08039D06\n"
    ".LwildDog_08039BB8:\n"
    "    mov\tr0, sl\n"
    "    ldr\tr1, [r0, #0]\n"
    "    mov\tr0, sp\n"
    "    ldr\tr3, [r1, #52]\t@ 0x34\n"
    "    mov\tr1, sl\n"
    "    adds\tr2, r5, #0\n"
    "    bl _call_via_r3\n"
    "    ldr\tr1, [r7, #20]\n"
    "    add\tr0, sp, #84\t@ 0x54\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r7, #0\n"
    "    bl _call_via_r2\n"
    "    add\tr4, sp, #16\n"
    "    movs\tr1, #32\n"
    "    mov\tr8, r1\n"
    "    movs\tr2, #0\n"
    "    mov\tr9, r2\n"
    "    movs\tr1, #33\t@ 0x21\n"
    "    str\tr1, [sp, #16]\n"
    "    movs\tr0, #33\t@ 0x21\n"
    "    negs\tr0, r0\n"
    "    str\tr0, [r4, #4]\n"
    "    str\tr0, [r4, #8]\n"
    "    str\tr1, [r4, #12]\n"
    "    add\tr1, sp, #36\t@ 0x24\n"
    "    mov\tr0, sp\n"
    "    ldmia\tr0!, {r2, r3, r6}\n"
    "    stmia\tr1!, {r2, r3, r6}\n"
    "    ldr\tr0, [sp, #84]\t@ 0x54\n"
    "    ldr\tr1, [sp, #88]\t@ 0x58\n"
    "    str\tr0, [sp, #48]\t@ 0x30\n"
    "    str\tr1, [sp, #52]\t@ 0x34\n"
    "    mov\tr3, r8\n"
    "    str\tr3, [r4, #40]\t@ 0x28\n"
    "    mov\tr6, r9\n"
    "    str\tr6, [r4, #44]\t@ 0x2c\n"
    "    str\tr6, [r4, #48]\t@ 0x30\n"
    "    ldr\tr0, [r7, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    ldr\tr2, [r1, #64]\t@ 0x40\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr3, r0, #0\n"
    "    mov\tr8, r4\n"
    "    cmp\tr3, #0\n"
    "    beq .LwildDog_08039C38\n"
    "    ldrh\tr0, [r3, #4]\n"
    "    cmp\tr0, r5\n"
    "    bne .LwildDog_08039C38\n"
    "    ldr\tr1, [r3, #20]\n"
    "    add\tr4, sp, #92\t@ 0x5c\n"
    "    adds\tr0, r4, #0\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    mov\tr0, r8\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #0\n"
    "    bl ClipAgainstBox__19ActorMovementBoundsRC3BoxUi\n"
    ".LwildDog_08039C38:\n"
    "    ldr\tr0, [r7, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    ldr\tr2, [r1, #64]\t@ 0x40\n"
    "    movs\tr1, #74\t@ 0x4a\n"
    "    bl _call_via_r2\n"
    "    adds\tr3, r0, #0\n"
    "    cmp\tr3, #0\n"
    "    beq .LwildDog_08039C68\n"
    "    ldrh\tr0, [r3, #4]\n"
    "    cmp\tr0, r5\n"
    "    bne .LwildDog_08039C68\n"
    "    ldr\tr1, [r3, #20]\n"
    "    add\tr4, sp, #100\t@ 0x64\n"
    "    adds\tr0, r4, #0\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r3, #0\n"
    "    bl _call_via_r2\n"
    "    mov\tr0, r8\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #0\n"
    "    bl ClipAgainstBox__19ActorMovementBoundsRC3BoxUi\n"
    ".LwildDog_08039C68:\n"
    "    ldr\tr0, [r7, #52]\t@ 0x34\n"
    "    ldr\tr0, [r0, #12]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r7\n"
    "    ldr\tr0, [r0, #56]\t@ 0x38\n"
    "    ldr\tr1, [r0, #0]\n"
    "    ldr\tr3, [r1, #8]\n"
    "    adds\tr1, r7, #0\n"
    "    mov\tr2, r8\n"
    "    bl _call_via_r3\n"
    "    ldr\tr0, [r7, #52]\t@ 0x34\n"
    "    ldr\tr0, [r0, #12]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r7\n"
    "    ldr\tr0, [r0, #56]\t@ 0x38\n"
    "    ldr\tr1, [r0, #0]\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r7, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #32\n"
    "    ldrb\tr5, [r0, #0]\n"
    "    ldr\tr1, [r7, #76]\t@ 0x4c\n"
    "    adds\tr6, r0, #0\n"
    "    cmp\tr4, r1\n"
    "    bne .LwildDog_08039CA8\n"
    "    ldr\tr0, [r7, #80]\t@ 0x50\n"
    "    cmp\tr5, r0\n"
    "    beq .LwildDog_08039CB8\n"
    ".LwildDog_08039CA8:\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r4, #0\n"
    "    bl GetWildDogMotionSpeed\n"
    "    adds\tr1, r0, #0\n"
    "    adds\tr0, r7, #0\n"
    "    bl SetMovementSpeed__12AActorEntityi\n"
    ".LwildDog_08039CB8:\n"
    "    ldr\tr0, [r7, #76]\t@ 0x4c\n"
    "    cmp\tr4, r0\n"
    "    beq .LwildDog_08039CD4\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r4, #0\n"
    "    bl GetWildDogMotionAnimation\n"
    "    adds\tr1, r0, #0\n"
    "    ldrh\tr0, [r7, #34]\t@ 0x22\n"
    "    cmp\tr0, r1\n"
    "    beq .LwildDog_08039CD4\n"
    "    adds\tr0, r7, #0\n"
    "    bl SetAnim__12AActorEntityUi\n"
    ".LwildDog_08039CD4:\n"
    "    str\tr4, [r7, #76]\t@ 0x4c\n"
    "    str\tr5, [r7, #80]\t@ 0x50\n"
    "    mov\tr4, r8\n"
    "    ldr\tr0, [r7, #52]\t@ 0x34\n"
    "    ldr\tr0, [r0, #12]\n"
    "    ldrb\tr1, [r6, #0]\n"
    "    subs\tr0, #1\n"
    "    cmp\tr0, #1\n"
    "    bhi .LwildDog_08039CFE\n"
    "    cmp\tr1, #1\n"
    "    bhi .LwildDog_08039CFE\n"
    "    movs\tr1, #10\n"
    "    ldrsh\tr0, [r7, r1]\n"
    "    movs\tr2, #14\n"
    "    ldrsh\tr1, [r7, r2]\n"
    "    bl IsWildDogExitCorridor\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .LwildDog_08039CFE\n"
    "    movs\tr4, #0\n"
    ".LwildDog_08039CFE:\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr1, r4, #0\n"
    "    bl ApplyMovement__12AActorEntityP19ActorMovementBounds\n"
    ".LwildDog_08039D06:\n"
    "    adds\tr1, r7, #0\n"
    "    adds\tr1, #48\t@ 0x30\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    "    ldrh\tr0, [r7, #36]\t@ 0x24\n"
    "    cmp\tr0, #0\n"
    "    beq .LwildDog_08039D28\n"
    "    subs\tr0, #1\n"
    "    b .LwildDog_08039D2A\n"
    ".LwildDog_08039D18: .word 0xFFFFFC00\n"
    ".LwildDog_08039D1C: .word 0xFFFF0000\n"
    ".LwildDog_08039D20: .word 0xFF00FFFF\n"
    ".LwildDog_08039D24: .word 0x00FFFFFF\n"
    ".LwildDog_08039D28:\n"
    "    ldrh\tr0, [r7, #38]\t@ 0x26\n"
    ".LwildDog_08039D2A:\n"
    "    strh\tr0, [r7, #36]\t@ 0x24\n"
    "    ldr\tr2, [r7, #16]\n"
    "    cmp\tr2, #0\n"
    "    beq .LwildDog_08039D3C\n"
    "    ldr\tr0, [r2, #4]\n"
    "    ldr\tr1, [r0, #12]\n"
    "    adds\tr0, r2, #0\n"
    "    bl _call_via_r1\n"
    ".LwildDog_08039D3C:\n"
    "    add\tsp, #112\t@ 0x70\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
);

u32 GetWildDogMotionAnimation(WildDogActor const * actor, u32 motion)
{
    return gWildDogMotionAnimations[motion];
}

i32 GetWildDogMotionSpeed(WildDogActor const * actor, u32 motion)
{
    switch (motion) {
    case 1:
        return ENTITY_MOVE_SPEED_Q16_HALF_PIXEL_PER_FRAME;
    case 2:
        return ENTITY_MOVE_SPEED_Q16_1_PIXEL_PER_FRAME;
    case 0:
    case 3:
    case 4:
    default:
        return 0;
    }
}

bool WildDogActor::CanBeHit() const
{
    return saved_model->behavior_state != WILD_DOG_STATE_REACTION;
}

void WildDogActor::ReactToToolHit()
{
    if (saved_model->behavior_state == WILD_DOG_STATE_DEPARTURE)
        return;

    AnimalReactionPayload payload;

    payload.bits.frames_remaining = 240 + RandomBelow(120);
    payload.bits.retreat_frames = 0x3C;
    payload.bits.target_is_dog = 0;
    payload.bits.retarget_frames = 0;

    SetWildDogReactionState(*saved_model, payload);
    func_0809C068(*saved_model, 15);

    StartActorSpriteEffect(*this, 2, false);

    RequestSound(0xAA);
}

void WildDogActor::ReactToDogAttack()
{
    if (saved_model->behavior_state == WILD_DOG_STATE_DEPARTURE)
        return;

    AnimalReactionPayload payload;

    payload.bits.frames_remaining = 240 + RandomBelow(120);
    payload.bits.retreat_frames = 0x3C;
    payload.bits.target_is_dog = 1;
    payload.bits.retarget_frames = 0;

    SetWildDogReactionState(*saved_model, payload);
    func_0809C068(*saved_model, 4);

    StartActorSpriteEffect(*this, 2, false);

    RequestSound(0xAA);
}

u32 WildDogState2::GetMotion(WildDogActor const * actor) const
{
    return 2;
}

WildDogBehavior * GetCurrentWildDogBehavior(WildDogActor const * actor)
{
    return actor->behaviors[actor->saved_model->behavior_state].Get();
}
