#ifndef HARVEST_SPRITE_HH
#define HARVEST_SPRITE_HH

#include "prelude.h"

#include "npc.hh"
#include "unknown_types.hh"

extern u8 const gUnk_HarvestSpriteMiniGameAnimalHusbandryMatchValues[5];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandrySelectionValues[4];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues0[3];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues1[5];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues2[3];
extern u16 const gUnk_HarvestSpriteMiniGameAnimalHusbandryIndexValues3[7];
extern char const gCppRuntimeBadAlloc_HarvestSpriteMiniGameAnimalHusbandry[];
#if defined(REGION_US)
extern char const gText_HarvestSpriteMiniGameAnimalHusbandryEmpty[];
#endif

extern u16 const gUnk_HarvestSpriteMiniGameChickenFestivalValues[4][6];
extern u8 const gUnk_HarvestSpriteMiniGameChickenFestivalOffsets[4];

extern u32 const gUnk_080BAC9CValues[16];
extern u16 const gUnk_080BB890FirstValues[5];
extern u16 const gUnk_080BB890TableValues[4][4];
extern u16 const gUnk_080BB890LastValues[3];
extern u32 const gUnk_080BC288Values[16];
extern char const gCppRuntimeBadAlloc_HarvestSpriteMiniGamePostChickenFestival[];
extern char const gText_080BE728DigitZero[];
extern u32 const gUnk_080BE954Values[7];

struct HarvestSprite : public Npc
{
    enum Task
    {
        TASK_HARVEST,
        TASK_WATER,
        TASK_ANIMALS,
        TASK_NONE,

        NUM_TASKS = TASK_NONE,
    };

    HarvestSprite(ActorLocation const & location);

    Task GetCurrentTask(void) const;
    u32 GetWorkDaysLeft(void) const;
    u32 GetTaskExp(Task task) const;
    bool HasPlayedMinigameToday(void) const;
    u32 GetMinigameExp(Task task) const;
    void AddTaskExp(Task task, int amount);
    void StartTask(Task task, int days);
    void method_0809E6EC(void);
    void SetPlayedMinigame(Task task, bool succeeded);
    void TaskDayUpdate(void);
    void DayUpdate(void);
    void method_0809E7C8(void);
    void method_0809E7D0(void);
    void method_0809E7D8(UnkBarnAnimal2C const * param);
    void method_0809E7E4(UnkBarnAnimal2C const * param);
    void method_0809E7F0(UnkBarnAnimal2C const * param);
    void method_0809E7FC(void);

    /* +14 */ u8 task_exp[3];
    /* +17 */ u8 minigame_exp[3];
    /* +1A */ u32 current_task : 2;
    /* +1A */ u32 work_days_left : 3;
    /* +1A */ bool played_minigame : 1;
    /* +1C */ u32 unk_1C;
    /* +20 */ UnkBarnAnimal2C unk_20;
};

#endif // HARVEST_SPRITE_HH
