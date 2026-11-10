#ifndef HARVEST_SPRITE_HH
#define HARVEST_SPRITE_HH

#include "prelude.h"

#include "npc.hh"
#include "unknown_types.hh"

// Shared reservations used when selecting the seven sprites' work targets.
// Kind 1/2 use the first two payload bytes as a field-plot coordinate pair;
// the other comparable kinds use one target index. The rest remains opaque.
// Construction clears only the kind; all other storage keeps its old contents.
struct HarvestSpriteWorkTarget
{
    HarvestSpriteWorkTarget() { kind = 0; }

    u32 kind : 4;
    u32 : 4;
    u8 payload[7];
};

typedef char HarvestSpriteWorkTargetSizeCheck[sizeof(HarvestSpriteWorkTarget) == 8 ? 1 : -1];
typedef char HarvestSpriteWorkTargetPayloadCheck[offsetof(HarvestSpriteWorkTarget, payload) == 1 ? 1 : -1];

bool operator==(HarvestSpriteWorkTarget const & left, HarvestSpriteWorkTarget const & right);
bool HasHarvestSpriteWorkTarget(HarvestSpriteWorkTarget const * targets, HarvestSpriteWorkTarget const & value);
void SetHarvestSpriteWorkTarget(HarvestSpriteWorkTarget * targets, u32 slot, HarvestSpriteWorkTarget const & value);
void ClearHarvestSpriteWorkTarget(HarvestSpriteWorkTarget * targets, u32 slot);

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
    // Native callers pass opaque stack data. These setters do not read it;
    // retain the pointer ABI without guessing the original tag type.
    void method_0809E7C8(void const * unk_data);
    void method_0809E7D0(void const * unk_data);
    void method_0809E7D8(UnkBarnAnimal2C const * param);
    void method_0809E7E4(UnkBarnAnimal2C const * param);
    void method_0809E7F0(UnkBarnAnimal2C const * param);
    void method_0809E7FC(void const * unk_data);

    /* +14 */ u8 task_exp[3];
    /* +17 */ u8 minigame_exp[3];
    /* +1A */ u32 current_task : 2;
    /* +1A */ u32 work_days_left : 3;
    /* +1A */ bool played_minigame : 1;
    /* +1C */ u32 unk_1C;
    /* +20 */ UnkBarnAnimal2C unk_20;
};

// The hut initializer reads three bytes from each four-byte record.
// The last byte is natural record alignment, not a separate runtime field.
struct ALIGN(4) HarvestSpriteHutPosition
{
    u8 x;
    u8 y;
    u8 facing;
};

typedef char HarvestSpriteHutPositionSizeCheck[sizeof(HarvestSpriteHutPosition) == 4 ? 1 : -1];
typedef char HarvestSpriteHutPositionFacingCheck[offsetof(HarvestSpriteHutPosition, facing) == 2 ? 1 : -1];

extern "C" HarvestSpriteHutPosition const gHarvestSpriteHutPositions[7];


// Slots outside the seven native hut positions use (0, 0), facing down.
ActorLocation * InitializeHarvestSpriteHutLocation(ActorLocation * location, u32 slot);

#endif // HARVEST_SPRITE_HH
