#ifndef ACTOR_BEHAVIOR_HH
#define ACTOR_BEHAVIOR_HH

#include "prelude.h"

// Native callers select by weight and form the duration as
// 60 * base_duration + RandomBelow(60 * random_duration).
struct ActorBehaviorTiming
{
    u8 weight;
    u8 base_duration;
    u8 random_duration;
    u8 unk_03;
};

typedef char ActorBehaviorTimingSizeCheck[sizeof(ActorBehaviorTiming) == 4 ? 1 : -1];
typedef char ActorBehaviorTimingWeightCheck[offsetof(ActorBehaviorTiming, weight) == 0 ? 1 : -1];
typedef char ActorBehaviorTimingBaseDurationCheck[offsetof(ActorBehaviorTiming, base_duration) == 1 ? 1 : -1];
typedef char ActorBehaviorTimingRandomDurationCheck[offsetof(ActorBehaviorTiming, random_duration) == 2 ? 1 : -1];

// Return a table index, not an event or behavior ID. The original caller
// supplies a nonempty table; incomplete cumulative weight falls back to 0.
extern "C" u32 SelectActorBehaviorTimingIndex(ActorBehaviorTiming const * entries, u32 count);

#endif // ACTOR_BEHAVIOR_HH
