#pragma implementation "entity_actor.hh"

#include "prelude.h"
#include "map_terrain.hh"
#include "entity_actor.hh"
#include "entity_auxiliary_sprites.hh"

#include <stdlib.h>

#include <new>
#include FOMT_TEXT_INCLUDE(entity_actor.cc)
extern "C" EntitySpriteEffectOffset const gEntitySpriteEffectOffsets[][4] ALIGN(1) = {
    { { -3, -43 }, { -3, -43 }, { -3, -43 }, { -3, -43 } },
    { { -3, -37 }, { -3, -37 }, { -3, -37 }, { -3, -37 } },
    { { -3, -45 }, { -3, -45 }, { -3, -45 }, { -3, -45 } },
    { { -3, -39 }, { -3, -39 }, { -8, -39 }, { 4, -39 } },
    { { -3, -34 }, { -3, -34 }, { -3, -34 }, { -3, -34 } },
    { { 12, -13 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { -6, -26 }, { -6, -26 }, { -6, -26 }, { -6, -26 } },
    { { -5, -32 }, { -5, -32 }, { -5, -32 }, { -5, -32 } },
    { { -6, -28 }, { -6, -28 }, { -6, -28 }, { -6, -28 } },
    { { -5, -29 }, { -5, -32 }, { -13, -30 }, { 1, -30 } },
    { { -5, -29 }, { -5, -32 }, { -11, -32 }, { -4, -32 } },
    { { -5, -32 }, { -5, -36 }, { -14, -36 }, { 2, -36 } },
    { { -4, -33 }, { -4, -38 }, { -14, -36 }, { 5, -36 } },
    { { -4, -33 }, { -4, -38 }, { -10, -35 }, { -1, -35 } },
    { { -4, -33 }, { -4, -40 }, { -15, -36 }, { 6, -36 } },
    { { -4, -35 }, { -4, -43 }, { -16, -41 }, { 7, -41 } },
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
        static_cast<EntitySpriteController *>(self.unk_10.Get())->SetEffectOffsetKind(value);
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
    u32 size_shift, u32 palette_kind, u32 profile, u32 effect_offset_kind,
    u32 unknown_8B, bool sprite_unknown_3D)
    : EntityVisualController(owner),
      sprite(owner->game_object->vfunc_68(), owner->GetAnimationIndex(),
          owner->GetGameObject(), size_shift, palette_kind, sprite_unknown_3D),
      effect(owner->game_object->vfunc_6C(), 0, owner->GetGameObject(), 2, 14, false),
      aux_render_profile(profile), unk_89(0), effect_mode(0),
      effect_offset_kind(effect_offset_kind), unk_8B(unknown_8B)
{
}

EntitySpriteController::EntitySpriteController(AActorEntity * owner,
    u32 size_shift, i32 const * palette_kinds, u32 palette_count, u32 profile,
    u32 effect_offset_kind, u32 unknown_8B, bool sprite_unknown_3D)
    : EntityVisualController(owner),
      sprite(owner->game_object->vfunc_68(), owner->GetAnimationIndex(),
          owner->GetGameObject(), size_shift, palette_kinds, palette_count, sprite_unknown_3D),
      effect(owner->game_object->vfunc_6C(), 0, owner->GetGameObject(), 2, 14, false),
      aux_render_profile(profile), unk_89(0), effect_mode(0),
      effect_offset_kind(effect_offset_kind), unk_8B(unknown_8B)
{
}

void EntitySpriteController::Update()
{
    sprite.UpdateAnimation();
    u32 mode = effect_mode;
    if (mode != ENTITY_SPRITE_EFFECT_NONE) {
        if (effect.UpdateAnimation().flags.wrapped && mode != ENTITY_SPRITE_EFFECT_PERSISTENT)
            StopEffect();
    }
}

void EntitySpriteController::Draw(EntityDrawContext const & context)
{
    AActorEntity * actor = static_cast<AActorEntity *>(entity);
    GameObject * world = actor->GetGameObject();
    i32 x = (actor->GetQ16X() >> 16) - context.camera_x;
    i32 y = (actor->GetQ16Y() >> 16) - context.camera_y;
    u32 sort_key = 0x8000 - (actor->GetQ16Y() >> 16);
    GameSceneSpriteDrawContext sprites(context.queue, context.buffer);
    switch (static_cast<i32>(effect_mode)) {
    case ENTITY_SPRITE_EFFECT_NONE: break;
    case ENTITY_SPRITE_EFFECT_UNTIL_WRAP:
    case ENTITY_SPRITE_EFFECT_PERSISTENT: {
        EntitySpriteEffectOffset const & offset = gEntitySpriteEffectOffsets[effect_offset_kind][actor->GetFacing()];
        effect.Draw(sprites, x + offset.x, y + offset.y, 0x55, sort_key);
        break;
    }
    }
    u32 priorities;
    switch (static_cast<i32>(unk_8B)) {
    case 0:
    default: {
        u32 priority = actor->GetObjPriority() & 3;
        priorities = priority | (priority << 2) | (priority << 4) | (priority << 6);
        break;
    }
    case 1: priorities = 0x19; break;
    case 2: priorities = 0x1A; break;
    }
    sprite.Draw(sprites, x, y, priorities, sort_key);

    u32 profile;
    switch (static_cast<i32>(aux_render_profile)) {
    case ENTITY_AUX_RENDER_DISABLED: return;
    case ENTITY_AUX_RENDER_SMALL_ANIMAL: profile = 0; break;
    default:
    case ENTITY_AUX_RENDER_DEFAULT: profile = 1; break;
    case ENTITY_AUX_RENDER_LIVESTOCK: profile = 2; break;
    }
    world->GetEntityAuxiliarySprites()->Draw(context.buffer, x, y + unk_89, profile);
}


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

ScriptVisualEffectActor::ScriptVisualEffectActor(GameObject * world, ScriptVisualEffectRecord * record)
    : AActorEntity(world, record->location, 2, record->animation)
{
    this->record = record;
}

ScriptVisualEffectActor::~ScriptVisualEffectActor()
{
    record->location = GetLocation();
    record->animation = GetAnim();
}

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
