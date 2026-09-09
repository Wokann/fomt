#include "harvest_sprite.hh"

#include <cstdlib>

#if defined(REGION_JP)
#include "data/text/jp/harvest_sprite_1.cc"
#else
#include "data/text/us/harvest_sprite_1.cc"
#endif

// These fixed tables are read by the still-native Animal Husbandry minigame
// code.  Their precise gameplay roles are not decoded yet; names retain the
// known table access shape and owning minigame only.
u8 const gUnk_HarvestSpriteMiniGameAnimalHusbandryMatchValues[5] = {
        0x48, 0x60, 0x78, 0x90, 0xA8,
    };

u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandrySelectionValues[4] = {
        0x0424, 0x0422, 0x0423, 0x0428,
    };
u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues0[3] = {
        1, 0, 0,
    };
u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues1[5] = {
        0x071D, 0x0725, 0x0731, 0x0721, 0x0720,
    };
u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues2[3] = {
        0, 0, 5,
    };
u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues3[7] = {
        0x2A, 0x36, 0x2C, 0x2E, 0x30, 0x32, 0x34,
    };

#if defined(REGION_JP)
#include "data/text/jp/harvest_sprite_2.cc"
#else
#include "data/text/us/harvest_sprite_2.cc"
#endif

// The native Chicken Festival code selects a row with a twelve-byte stride,
// then adds one of these four byte offsets to the selected u16 value.  JP
// places the table at a two-byte (rather than four-byte) boundary.
u16 const gUnk_HarvestSpriteMiniGameChickenFestivalValues[4][6] ALIGN(2) = {
        { 0x071C, 0x0720, 0x0724, 0x0728, 0x072C, 0x0730 },
        { 0x06EA, 0x06EE, 0x06F2, 0x06F6, 0x06FA, 0x06FE },
        { 0x0703, 0x0707, 0x070B, 0x070F, 0x0713, 0x0717 },
        { 0x06D1, 0x06D5, 0x06D9, 0x06DD, 0x06E1, 0x06E5 },
    };

u8 const gUnk_HarvestSpriteMiniGameChickenFestivalOffsets[4] = {
        1, 3, 0, 2,
};

#if defined(REGION_JP)
#include "data/text/jp/harvest_sprite_3.cc"
#else
#include "data/text/us/harvest_sprite_3.cc"
#endif

// This contiguous group is consumed by several still-native minigame and UI
// routines.  The individual table shapes below follow their exact accesses;
// unresolved gameplay meanings deliberately retain gUnk names.
u32 const gUnk_080BAC9CValues[16] = {
        0x4B, 0x28, 0xC8, 0x72, 0xCD, 0x30, 0x5A, 0x92,
        0x24, 0x7D, 0x78, 0x16, 0x78, 0x8E, 0x3A, 0x50,
    };

u16 const gUnk_080BB890FirstValues[5] ALIGN(2) = {
        0x09A1, 0x07B4, 0x08C2, 0x0230, 0x09F2,
    };
u16 const gUnk_080BB890TableValues[4][4] ALIGN(2) = {
        { 0x0192, 0x01CA, 0x019A, 0x01C2 },
        { 0x0641, 0x063D, 0x0639, 0x0641 },
        { 0x064D, 0x0649, 0x0645, 0x064D },
        { 0x0635, 0x0631, 0x062D, 0x0635 },
    };
u16 const gUnk_080BB890LastValues[3] ALIGN(2) = {
        0x0216, 0x0222, 0,
    };

u32 const gUnk_080BC288Values[16] = {
        0x4B, 0x28, 0xC8, 0x72, 0xCD, 0x30, 0x5A, 0x92,
        0x24, 0x7D, 0x78, 0x16, 0x78, 0x8E, 0x3A, 0x50,
    };

char const gCppRuntimeBadAlloc_HarvestSpriteMiniGamePostChickenFestival[] =
    "bad_alloc";

#if defined(REGION_JP)
char const gText_080BE728DigitZero[] =
    "０";
#else
char const gText_080BE728DigitZero[] =
    "0";
#endif

u32 const gUnk_080BE954Values[7] = {
        4, 0, 1, 6, 3, 2, 5,
};

#if defined(REGION_JP)
#include "data/text/jp/harvest_sprite_4.cc"
#else
#include "data/text/us/harvest_sprite_4.cc"
#endif

// JP begins this native halfword lookup at a byte-aligned address.  Preserve
// that physical layout explicitly; the US native code is the decoded caller.
u16 const gUnk_080C09D8Values[11] ALIGN(1) = {
        0x03FE, 0x0402, 0x0406, 0x03F6, 0x040A, 0x040E,
        0x0412, 0x03FA, 0x0416, 0x041A, 0x041E,
    };

u16 const gUnk_080C0B58Values[7] ALIGN(2) = {
        0x2A, 0x36, 0x2C, 0x2E, 0x30, 0x32, 0x34,
    };

char const gCppRuntimeBadAlloc_HarvestSpriteMiniGameHarvestResults[] =
    "bad_alloc";

u16 const gUnk_080C3B18Values[8][2] ALIGN(4) = {
        { 0x033C, 0x0078 }, { 0x043C, 0x0078 },
        { 0x0532, 0x005A }, { 0x0632, 0x005A },
        { 0x0728, 0x003C }, { 0x0828, 0x003C },
        { 0x091E, 0x001E }, { 0x0A1E, 0x001E },
    };

#if defined(REGION_JP)
char const gText_080C38E4DigitZero[] =
    "０";
#else
char const gText_080C38E4DigitZero[] =
    "0";
#endif

u32 const gUnk_080C3B18IndexValues[7] = {
        4, 0, 1, 6, 3, 2, 5,
};

#if defined(REGION_JP)
#include "data/text/jp/harvest_sprite_5.cc"
#else
#include "data/text/us/harvest_sprite_5.cc"
#endif

u16 const gUnk_080C7B38Values[10] = {
        0x03E2, 0x03E3, 0x03E1, 0x03E0, 0x03E6,
        0x03E7, 0x03E5, 0x03E4, 0x03F0, 0x03E1,
    };

u16 const gUnk_080C7B64Values[7] = {
        0x2A, 0x36, 0x2C, 0x2E, 0x30, 0x32, 0x34,
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
