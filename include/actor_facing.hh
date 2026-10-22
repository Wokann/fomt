#ifndef ACTOR_FACING_HH
#define ACTOR_FACING_HH

#include "prelude.h"

struct ActorMovementBounds;

EXTERN_C

// Relative order: forward, actor-left, actor-right, back.
// Preserve the original switch fallthrough for values outside 0..3.
i32 GetRelativeFacing(i32 facing, i32 relative);

// Native implementations remain shared assembly until the C++ models match.
i32 SelectApproachFacing(i32 x, i32 y, i32 target_x, i32 target_y,
    ActorMovementBounds & limits, i32 facing);
i32 SelectRetreatFacing(i32 x, i32 y, i32 target_x, i32 target_y,
    ActorMovementBounds & limits, i32 facing);

EXTERN_C_END

#endif // ACTOR_FACING_HH
