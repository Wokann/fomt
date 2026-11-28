
#include "wild_dog_actor.hh"
#include "game_object.hh"
#include "actor_runtime_data.hh"

#include <new>
#include FOMT_TEXT_INCLUDE(wild_dog_actor.cc)
#include "random.hh"
#include <stdlib.h>
#include "utility/vec2.hh"
#include "time_of_day_types.hh"
extern "C" u16 const gWildDogMotionAnimations[] = {
    0x09BF, 0x09C3, 0x09C7, 0x09CB, 0x09CF,
};

// Slot 45 owns this visiting dog. The imported ENTITY_FRISBEE name
// conflicts with the factory, livestock targeting and dog animation frames.

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

static inline Vec2 GetWildDogBoundaryPosition(u32 south)
{
    Vec2 position = south != 0 ? Vec2(264, 720) : Vec2(340, -16);
    return position;
}

void WildDogState1::Update(WildDogActor * actor, ActorMovementBounds * bounds)
{
    Unk_Actor_0809BFE8 * saved = actor->saved_model;
    WildDogDepartureState & state = saved->departure;
    u32 remaining = state.retarget_frames;
    if (remaining != 0)
        --remaining;
    u32 map = actor->GetMap();
    i32 x = actor->GetQ16X() >> 16;
    i32 y = actor->GetQ16Y() >> 16;
    Vec2 const & target = y > 352 ? Vec2(264, 720) : Vec2(340, -16);
    i32 target_x = target.x;
    i32 target_y = target.y;
    if (map == MAP_FARM && (abs(target_x - x) > 15 || abs(target_y - y) > 15)) {
        if (remaining == 0) {
            if (IsWildDogExitCorridor(x, y)) {
                u32 facing = y < target_y ? 0 : 1;
                actor->SetFacingIfChanged(facing);
            } else {
                u32 facing = actor->GetFacing();
                facing = SelectApproachFacing(x, y, target_x, target_y, *bounds, facing);
                actor->SetFacingIfChanged(facing);
            }
            remaining = RandomBelow(30) + 1;
        }
        state.retarget_frames = remaining;
    } else {
        actor->PutOutOfTown();
        u32 unused;
        SetWildDogInactiveState(*saved, unused);
    }
}

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

void WildDogActor::Update(EntityUpdateContext const & context)
{
    GameObject * world = GetGameObject();
    if (context.minute_advanced && GetMap() != MAP_FARM) {
        GameStateClock const * clock = world->GetClock();
        if (clock->calendar.time.clock_hour == 20 && clock->calendar.time.clock_minute == 0
            && clock->weather_today == WEATHER_SUNNY) {
            Vec2 position = GetWildDogBoundaryPosition(RandomBelow(2));
            u32 target = FindNearestWildDogTarget(world, MAP_FARM, position.x, position.y);
            if (target != 100 && RandomBelow(100) < 15) {
                Location const location(MAP_FARM, position.x, position.y);
                ActorLocation const actor_location(location, 1);
                SetLocation(actor_location);
                WildDogChaseState state;
                state.frames_remaining = 0;
                state.attempts_remaining = RandomBelow(8) + 3;
                state.target_entity = target;
                SetWildDogChaseState(*saved_model, state);
                RequestSound(0xAB);
            }
        }
    }
    u32 map = GetMap();
    if (map != MAP_NONE) {
        MapTerrainView const & terrain = world->GetMapTerrain(map);
        ActorMovementBounds bounds(terrain, GetBox(), 32);
        AEntity * player = GetGameObject()->GetEntity(ENTITY_PLAYER);
        if (player != nullptr && player->GetMap() == map)
            bounds.ClipAgainstBox(player->GetBox(), 0);
        AEntity * basket = GetGameObject()->GetEntity(ENTITY_BASKET);
        if (basket != nullptr && basket->GetMap() == map)
            bounds.ClipAgainstBox(basket->GetBox(), 0);
        behaviors[saved_model->behavior_state]->Update(this, &bounds);
        u32 motion = behaviors[saved_model->behavior_state]->GetMotion(this);
        u32 current_facing = facing;
        if (motion != cached_motion || current_facing != cached_facing)
            SetMovementSpeed(GetWildDogMotionSpeed(this, motion));
        if (motion != cached_motion)
            SetAnimIfChanged(GetWildDogMotionAnimation(this, motion));
        cached_motion = motion;
        cached_facing = current_facing;
        ActorMovementBounds * movement_bounds = &bounds;
        u32 movement_state = saved_model->behavior_state;
        u32 movement_facing = facing;
        if ((movement_state == WILD_DOG_STATE_DEPARTURE
                || movement_state == WILD_DOG_STATE_CHASE)
            && movement_facing <= 1 && IsWildDogExitCorridor(GetQ16X() >> 16, GetQ16Y() >> 16))
            movement_bounds = nullptr;
        ApplyMovement(movement_bounds);
    }
    sound_requested = false;
    if (animation_countdown != 0)
        --animation_countdown;
    else
        animation_countdown = animation_reload;
    EntityVisualController * visual = unk_10.Get();
    if (visual != nullptr)
        visual->Update();
}

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
