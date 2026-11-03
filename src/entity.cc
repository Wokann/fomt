#include "entity.hh"

AEntity::AEntity(GameObject * game_object, Location const & location)
    : game_object(game_object), location_map(location.map), normal_update_suspended(false), x_q16(location.x << 16), y_q16(location.y << 16)
{
}

void AEntity::vfunc_10()
{
    unk_10 = nullptr;

    if (game_object->vfunc_14() != location_map)
        return;

    unk_10 = vfunc_30();
}

void AEntity::vfunc_14()
{
    unk_10 = nullptr;
}

void AEntity::Draw(EntityDrawContext const & context)
{
    if (unk_10.Get() != nullptr)
        unk_10->Draw(context);
}

void AEntity::UpdateWhileSuspended(EntityUpdateContext const & context)
{
    if (unk_10.Get() != nullptr)
        unk_10->Update();
}

void AEntity::SetLocation(u32 map, i32 x, i32 y)
{
    SetMap(map);
    x_q16 = x << 16;
    y_q16 = y << 16;
}

Location AEntity::GetLocation() const
{
    return Location(location_map, x_q16 >> 16, y_q16 >> 16);
}

Box AEntity::GetBox() const
{
    return Box(x_q16 >> 16, y_q16 >> 16);
}

void AEntity::SetMap(u32 map)
{
    if (location_map != map)
    {
        location_map = map;
        vfunc_10();
    }
}

void AEntity::Update(EntityUpdateContext const & context)
{
    if (unk_10.Get() != nullptr)
        unk_10->Update();
}

bool AEntity::IsNormalUpdateSuspended() const
{
    return normal_update_suspended;
}

void AEntity::ResumeNormalUpdates()
{
    normal_update_suspended = false;
}

void AEntity::SuspendNormalUpdates()
{
    normal_update_suspended = true;
}
