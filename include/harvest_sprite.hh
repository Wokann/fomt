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
extern char const gText_HarvestSpriteMiniGameAnimalHusbandryEmpty[];

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

extern u16 const gUnk_080C09D8Values[11];
extern u16 const gUnk_080C0B58Values[7];
extern char const gCppRuntimeBadAlloc_HarvestSpriteMiniGameHarvestResults[];
extern u16 const gUnk_080C3B18Values[8][2];
extern char const gText_080C38E4DigitZero[];
extern u32 const gUnk_080C3B18IndexValues[7];
extern u16 const gUnk_080C7B38Values[10];
extern u16 const gUnk_080C7B64Values[7];

enum
{
    CHICKEN_FESTIVAL_CONTESTANT_NAME_COUNT = 20,
    CHICKEN_FESTIVAL_CONTESTANT_NAME_WIDTH = 13,
};

// Direct-indexed fixed-width rows, not a pointer table.
extern char const gText_ChickenFestival_ContestantNames[CHICKEN_FESTIVAL_CONTESTANT_NAME_COUNT][CHICKEN_FESTIVAL_CONTESTANT_NAME_WIDTH];

extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Yes[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_No[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Introduction[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_FeedingInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ChickenBehaviorInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_WatchInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Start[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScorePrefix[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreSummary[];

#if defined(REGION_WESTERN)
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultPrefix[];
#endif

extern char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsAnnouncement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalRoundAnnouncement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationNo[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationYes[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Start[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Stop[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_WinnerSuffix[];
#if defined(REGION_DE)
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStartPageBreak[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStartPageBreak[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStartPageBreak[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_StartPageBreak[];
#endif
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Introduction[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Rules[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Encouragement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_CautionAtRingEdge[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_CautionLeavingRing[];

#if defined(REGION_WESTERN)
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandAgain[];
#endif

extern char const gText_HarvestSpriteMiniGame_Harvest_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Yes[];
extern char const gText_HarvestSpriteMiniGame_Harvest_No[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Introduction[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Instructions[];
extern char const gText_HarvestSpriteMiniGame_Harvest_FatigueWarning[];
extern char const gText_HarvestSpriteMiniGame_Harvest_RestInstructions[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Start[];
extern char const gText_HarvestSpriteMiniGame_Harvest_ScorePrefix[];
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreSummary[];

extern char const gText_HarvestSpriteMiniGame_Watering_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_Watering_Yes[];
extern char const gText_HarvestSpriteMiniGame_Watering_No[];
extern char const gText_HarvestSpriteMiniGame_Watering_Introduction[];
extern char const gText_HarvestSpriteMiniGame_Watering_Instructions[];
extern char const gText_HarvestSpriteMiniGame_Watering_SuccessInstructions[];
extern char const gText_HarvestSpriteMiniGame_Watering_MistakeWarning[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_Watering_Start[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScorePrefix[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreSummary[];

#if defined(REGION_WESTERN)
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreResultPrefix[];
#endif

#if defined(REGION_US) || defined(REGION_EU)
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreResultPrefix[];
#endif

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
