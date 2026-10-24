#include "prelude.h"
#pragma implementation "entity_actor.hh"
#include "entity_actor.hh"

#include <stdlib.h>

extern "C" u32 func_08032090(void * sprite, u32 anim_id); // Sprite

bool AActorEntity::IsOnCurrentMap() const
{
    return game_object->vfunc_14() == location_map;
}

void AActorEntity::SetMovementSpeed(i32 speed_q16)
{
    i32 x_speed = 0;
    i32 y_speed = 0;
    if (speed_q16 != 0) {
        fu8 direction = facing;
        switch (direction) {
        case FACING_DOWN: y_speed = speed_q16; break;
        case FACING_UP: y_speed = -speed_q16; break;
        case FACING_LEFT: x_speed = -speed_q16; break;
        case FACING_RIGHT: x_speed = speed_q16; break;
        }
    }
    x_speed_q16 = x_speed;
    y_speed_q16 = y_speed;
}

// A missing sprite or stopped traversal is complete; otherwise predict the next wrap.
bool AActorEntity::IsAnimationComplete() const
{
    EntitySpriteController * sprite = static_cast<EntitySpriteController *>(unk_10.Get());
    if (sprite != 0) {
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

void AActorEntity::ApplyMovement(ActorMovementBounds * bounds)
{
    i32 old_x_q16 = x_q16;
    i32 old_y_q16 = y_q16;
    i32 next_x_q16 = old_x_q16 + x_speed_q16;
    i32 next_y_q16 = old_y_q16 + y_speed_q16;
    if (bounds != 0) {
        ActorMovementBounds & limits = *bounds;
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
    }
    x_q16 = next_x_q16;
    y_q16 = next_y_q16;
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

    unk_28.unk_00 = 0;
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

    unk_24 = func_08032090(game_object->vfunc_68(), sprite_anim);
    unk_26 = unk_24;
}

void AActorEntity::method_08032208()
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

UnkActorEntity28::UnkActorEntity28()
    : unk_00(0)
{
}

EC void func_08032308(AActorEntity & self, u32 arg_1, i32 arg_2)
{
    i32 x = self.x_q16 >> 16;

    self.x_q16 = x << 16;

    if (arg_2 != 0 && arg_1 != x)
    {
        self.unk_28.unk_00 = abs(arg_2);
        self.unk_2C = arg_1;
        self.unk_2E = 0;
    }
    else
    {
        self.unk_28.unk_00 = 0;
    }
}

EC void func_0803233C(AActorEntity & self, u32 arg_1, i32 arg_2)
{
    i32 y = self.y_q16 >> 16;

    self.y_q16 = y << 16;

    if (arg_2 != 0 && arg_1 != y)
    {
        self.unk_28.unk_00 = abs(arg_2);
        self.unk_2C = arg_1;
        self.unk_2E = 1;
    }
    else
    {
        self.unk_28.unk_00 = 0;
    }
}

EC bool func_08032370(AActorEntity & self)
{
    return self.unk_28.unk_00 == 0;
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

EC Box func_0803240C(AActorEntity & self)
{
    return Box(self.x_q16 >> 16, self.y_q16 >> 16, 14, 9);
}

#if 0

EC void func_0803242C(AActorEntity & self, u32 arg_1)
{
    if (self.unk_24 == 0)
    {
        self.unk_24 = 0xFFFF;
    }
    else
    {
        self.unk_24 = self.unk_26;
    }

    if (self.unk_28.unk_00 != 0)
    {
        bool ip = self.unk_2E == 0;
        i32 r2 = ip ? self.x_q16 : self.y_q16;
        int r5 = r2 >> 16;
        int r7 = self.unk_2C - r5;

        if (r7 == 0)
        {
            self.unk_28.unk_00 = 0;
        }
        else
        {
            r2 = r7 > 0 ? r2 + self.unk_28.unk_00 : r2 - self.unk_28.unk_00;

            if ((r2 >> 16) != r5)
            {
                if (r7 > 0 && self.unk_2C - (r2 >> 16) > 0)
                    self.unk_28.unk_00 = 0;
                else if (r7 < 0 && self.unk_2C - (r2 >> 16) < 0)
                    self.unk_28.unk_00 = 0;
            }

            if (ip != 0)
                self.x_q16 = r2;
            else
                self.y_q16 = r2;
        }
    }

    self.AEntity::vfunc_2C(arg_1);
}

#endif

// this goes up to func_08032BB4

// Shared lazy terrain probes follow the actor operations in ROM.

void ActorMovementBounds::RefreshDown()
{
    down_limit = max_distance;
    ClipMapTerrainMovement(terrain, box, &down_limit, 0, 0, 0);
    unk_10 = y_probe != 0 ? !IsMapTerrainBoxBlocked(terrain, box.Moved(0, down_limit + y_probe)) : false;
}

void ActorMovementBounds::RefreshUp()
{
    up_limit = -max_distance;
    ClipMapTerrainMovement(terrain, box, 0, &up_limit, 0, 0);
    unk_11 = y_probe != 0 ? !IsMapTerrainBoxBlocked(terrain, box.Moved(0, up_limit - y_probe)) : false;
}

void ActorMovementBounds::RefreshLeft()
{
    left_limit = -max_distance;
    ClipMapTerrainMovement(terrain, box, 0, 0, &left_limit, 0);
    unk_12 = x_probe != 0 ? !IsMapTerrainBoxBlocked(terrain, box.Moved(left_limit - x_probe, 0)) : false;
}

void ActorMovementBounds::RefreshRight()
{
    right_limit = max_distance;
    ClipMapTerrainMovement(terrain, box, 0, 0, 0, &right_limit);
    unk_13 = x_probe != 0 ? !IsMapTerrainBoxBlocked(terrain, box.Moved(right_limit + x_probe, 0)) : false;
}

ActorMovementBounds ActorMovementBounds::Empty()
{
    ActorMovementBounds result;
    result.unk_10 = true;
    result.unk_11 = true;
    result.unk_12 = true;
    result.unk_13 = true;
    return result;
}

void ActorMovementBounds::ClipAgainstBox(Box const & other, u32 clear_flags)
{
    if (box.x1 < other.x2 && other.x1 < box.x2) {
        i32 dy = box.y2 - other.y1;
        if (dy <= 0 && dy + GetDown() > 0) {
            down_limit = -dy;
            if (clear_flags == 1)
                unk_10 = false;
        }
        dy = box.y1 - other.y2;
        if (dy >= 0 && dy + GetUp() < 0) {
            up_limit = -dy;
            if (clear_flags == 1)
                unk_11 = false;
        }
    }
    if (box.y1 < other.y2 && other.y1 < box.y2) {
        i32 dx = box.x1 - other.x2;
        if (dx >= 0 && dx + GetLeft() < 0) {
            left_limit = -dx;
            if (clear_flags == 1)
                unk_12 = false;
        }
        dx = box.x2 - other.x1;
        if (dx <= 0 && dx + GetRight() > 0) {
            right_limit = -dx;
            if (clear_flags == 1)
                unk_13 = false;
        }
    }
}
