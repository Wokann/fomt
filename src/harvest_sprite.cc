#include "harvest_sprite.hh"

#include <cstdlib>

// These fixed tables are read by the still-native Animal Husbandry minigame
// code.  Their precise gameplay roles are not decoded yet; names retain the
// known table access shape and owning minigame only.
u8 const gUnk_HarvestSpriteMiniGameAnimalHusbandryMatchValues[5]
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry_match_values") = {
        0x48, 0x60, 0x78, 0x90, 0xA8,
    };

u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandrySelectionValues[4]
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry_u16_tables") = {
        0x0424, 0x0422, 0x0423, 0x0428,
    };
u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues0[3]
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry_u16_tables") = {
        1, 0, 0,
    };
u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues1[5]
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry_u16_tables") = {
        0x071D, 0x0725, 0x0731, 0x0721, 0x0720,
    };
u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues2[3]
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry_u16_tables") = {
        0, 0, 5,
    };
u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues3[7]
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry_u16_tables") = {
        0x2A, 0x36, 0x2C, 0x2E, 0x30, 0x32, 0x34,
    };

char const gCppRuntimeBadAlloc_HarvestSpriteMiniGameAnimalHusbandry[]
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry_runtime") =
        "bad_alloc";

#if defined(REGION_US)
// The native US exception path deliberately takes this final NUL byte's
// address rather than the adjacent "bad_alloc" string.  Model it as the
// actual empty string it is, while leaving the intervening bytes as linker
// padding.
char const gText_HarvestSpriteMiniGameAnimalHusbandryEmpty[]
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry_runtime_empty") =
        "";
#endif

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

void HarvestSprite::method_0809E7C8()
{
    unk_1C = 0;
}

void HarvestSprite::method_0809E7D0()
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

void HarvestSprite::method_0809E7FC()
{
    unk_1C = 5;
}
