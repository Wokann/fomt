#include "harvest_sprite.hh"

#include <cstdlib>
#include <algorithm>

extern template HarvestSpriteWorkTarget const * std::find(
    HarvestSpriteWorkTarget const *, HarvestSpriteWorkTarget const *,
    HarvestSpriteWorkTarget const &);


// Positions inside MAP_HARVEST_SPRITES_HUT, in the native sprite-slot order.
// Each record's trailing byte is supplied by its four-byte type alignment.
extern "C" HarvestSpriteHutPosition const gHarvestSpriteHutPositions[7] = {
    { 200, 104, FACING_LEFT },
    { 80, 96, FACING_DOWN },
    { 160, 96, FACING_DOWN },
    { 40, 112, FACING_RIGHT },
    { 196, 168, FACING_LEFT },
    { 200, 152, FACING_LEFT },
    { 40, 152, FACING_RIGHT },
};

HarvestSprite::HarvestSprite(ActorLocation const & location)
    : Npc(location)
{
    current_task = TASK_NONE;
    work_days_left = 0;
    played_minigame = false;
    unk_1C = 0;

    task_exp[0] = 0;
    task_exp[1] = 0;
    task_exp[2] = 0;

    minigame_exp[0] = 0;
    minigame_exp[1] = 0;
    minigame_exp[2] = 0;
}

HarvestSprite::Task HarvestSprite::GetCurrentTask() const
{
    return static_cast<HarvestSprite::Task>(current_task);
}

u32 HarvestSprite::GetWorkDaysLeft() const
{
    return work_days_left;
}

u32 HarvestSprite::GetTaskExp(HarvestSprite::Task task) const
{
    if (task >= 0 && task < NUM_TASKS)
        return task_exp[task];
    else
        return 0;
}

bool HarvestSprite::HasPlayedMinigameToday() const
{
    return played_minigame;
}

u32 HarvestSprite::GetMinigameExp(HarvestSprite::Task task) const
{
    if (task >= 0 && task < NUM_TASKS)
        return minigame_exp[task];
    else
        return 0;
}

void HarvestSprite::AddTaskExp(HarvestSprite::Task task, int amount)
{
    if (task >= 0 && task < NUM_TASKS)
    {
        u32 total = task_exp[task] + amount;

        // Clamps the value between 0 and 255
        if ((int)total < 0)
            total = 0;
        else if (total > 255)
            total = 255;

        task_exp[task] = total;
    }
}

void HarvestSprite::StartTask(HarvestSprite::Task task, int days)
{
    current_task = task;
    work_days_left = days;
}

void HarvestSprite::method_0809E6EC()
{
    work_days_left = 1;
}

void HarvestSprite::SetPlayedMinigame(HarvestSprite::Task task, bool succeeded)
{
    played_minigame = true;

    if (succeeded && minigame_exp[task] != 31)
        minigame_exp[task]++;

    int task_exp;

    if (minigame_exp[task] < 6)
        task_exp = 1;
    else if (minigame_exp[task] < 11)
        task_exp = 2;
    else if (minigame_exp[task] < 17)
        task_exp = 3;
    else
        task_exp = 4;

    if (!succeeded)
        task_exp = -task_exp;

    AddTaskExp(task, task_exp);
    AddFriendship(1);
}

void HarvestSprite::TaskDayUpdate()
{
    if (work_days_left)
    {
        work_days_left--;

        if (work_days_left == 0)
            current_task = TASK_NONE;

        SubtractFriendship(2);
    }
}

void HarvestSprite::DayUpdate()
{
    Npc::DayUpdate(rand() % 100);
    played_minigame = false;
}

void HarvestSprite::method_0809E7C8(void const *)
{
    unk_1C = 0;
}

void HarvestSprite::method_0809E7D0(void const *)
{
    unk_1C = 1;
}

void HarvestSprite::method_0809E7D8(UnkBarnAnimal2C const * param)
{
    unk_20 = *param;
    unk_1C = 2;
}

void HarvestSprite::method_0809E7E4(UnkBarnAnimal2C const * param)
{
    unk_20 = *param;
    unk_1C = 3;
}

void HarvestSprite::method_0809E7F0(UnkBarnAnimal2C const * param)
{
    unk_20 = *param;
    unk_1C = 4;
}

void HarvestSprite::method_0809E7FC(void const *)
{
    unk_1C = 5;
}

ActorLocation * InitializeHarvestSpriteHutLocation(ActorLocation * location, u32 slot)
{
    // Only the six-byte position and facing are assigned. As in the other
    // native location initializers, destination padding is left untouched.
    if (slot < 7) {
        HarvestSpriteHutPosition const * positions = gHarvestSpriteHutPositions;
        HarvestSpriteHutPosition const & entry = *(positions + slot);
        Location position(MAP_HARVEST_SPRITES_HUT, entry.x, entry.y);
        u8 facing = entry.facing;
        *static_cast<Location *>(location) = position;
        location->facing = facing;
    } else {
        *static_cast<Location *>(location) = Location(MAP_HARVEST_SPRITES_HUT, 0, 0);
        location->facing = FACING_DOWN;
    }
    return location;
}

bool operator==(HarvestSpriteWorkTarget const & left, HarvestSpriteWorkTarget const & right)
{
    u32 kind = left.kind;
    if (kind != right.kind)
        return false;
    switch (kind) {
    case 0:
        return true;
    case 1:
    case 2:
        // The encoded coordinate pair occupies bits 8-23 of the first word.
        return (*reinterpret_cast<u32 const *>(&left) & 0x00FFFF00)
            == (*reinterpret_cast<u32 const *>(&right) & 0x00FFFF00);
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        return left.payload[0] == right.payload[0];
    default:
        // Preserve the native non-equality of kind 5 and out-of-range kinds.
        return false;
    }
}

bool HasHarvestSpriteWorkTarget(HarvestSpriteWorkTarget const * targets, HarvestSpriteWorkTarget const & value)
{
    HarvestSpriteWorkTarget const * end = targets + 7;
    return std::find(targets, end, value) != end;
}

void SetHarvestSpriteWorkTarget(HarvestSpriteWorkTarget * targets, u32 slot, HarvestSpriteWorkTarget const & value)
{
    // Native callers provide the slot; no bounds clamp is performed here.
    targets[slot] = value;
}

void ClearHarvestSpriteWorkTarget(HarvestSpriteWorkTarget * targets, u32 slot)
{
    // This assigns a new empty record, not an in-place clear of just the nibble.
    // Uninitialized payload/spare bits therefore follow the native temporary.
    targets[slot] = HarvestSpriteWorkTarget();
}
