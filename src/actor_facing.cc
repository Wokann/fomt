#include "actor_facing.hh"

#include "entity_actor.hh"
#include "fomt_constants.hh"
#include "random.hh"

extern "C" Box GetActorInteractionBounds(AActorEntity const & actor, i32 facing)
{
    switch (facing) {
    case FACING_UP:
        return Box(-4, -20, 4, 2, actor.x_q16 >> 16, actor.y_q16 >> 16);
    case FACING_DOWN:
        return Box(-4, -6, 4, 18, actor.x_q16 >> 16, actor.y_q16 >> 16);
    case FACING_LEFT:
        return Box(-20, -14, 4, 2, actor.x_q16 >> 16, actor.y_q16 >> 16);
    case FACING_RIGHT:
        return Box(-4, -14, 20, 2, actor.x_q16 >> 16, actor.y_q16 >> 16);
    default:
        return Box(0, 0);
    }
}

extern "C" i32 GetRelativeFacing(i32 facing, i32 relative)
{
    // Relative order is forward, left, right, back. Invalid relative values
    // intentionally fall through to the next outer case, as in the original.
    switch (facing) {
    case FACING_DOWN:
        switch (relative) {
        case 0: return FACING_DOWN;
        case 1: return FACING_RIGHT;
        case 2: return FACING_LEFT;
        case 3: return FACING_UP;
        }
    case FACING_UP:
        switch (relative) {
        case 0: return FACING_UP;
        case 1: return FACING_LEFT;
        case 2: return FACING_RIGHT;
        case 3: return FACING_DOWN;
        }
    case FACING_LEFT:
        switch (relative) {
        case 0: return FACING_LEFT;
        case 1: return FACING_DOWN;
        case 2: return FACING_UP;
        case 3: return FACING_RIGHT;
        }
    case FACING_RIGHT:
        switch (relative) {
        case 0: return FACING_RIGHT;
        case 1: return FACING_UP;
        case 2: return FACING_DOWN;
        case 3: return FACING_LEFT;
        }
    }
    return facing;
}

extern "C" i32 SelectApproachFacing(i32 x, i32 y, i32 target_x, i32 target_y,
    ActorMovementBounds & limits, i32 facing)
{
    i32 dx = target_x - x;
    i32 dy = target_y - y;
    i32 abs_x = dx >= 0 ? dx : -dx;
    i32 abs_y = dy >= 0 ? dy : -dy;
    // Bias towards an axis only when its displacement exceeds the 3:2 ratio.
    i32 axis_bias = 0;
    if (abs_x * 2 > abs_y * 3)
        axis_bias = 1;
    else if (abs_x * 3 < abs_y * 2)
        axis_bias = -1;
    i32 choices[4];
    i32 best_score = 0x7FFFFFFF;
    u32 choice_count = 0;
    for (i32 next_relative = 0; next_relative < 4; ++next_relative) {
        i32 relative = next_relative;
        i32 direction = GetRelativeFacing(facing, relative);
        bool wrong_direction = true;
        bool dominant_axis = false;
        bool blocked = true;
        switch (direction) {
        case FACING_DOWN:
            wrong_direction = dy <= 0;
            dominant_axis = axis_bias < 0;
            blocked = limits.GetDown() == 0 && !limits.GetDownProbeFlag();
            break;
        case FACING_UP:
            wrong_direction = dy >= 0;
            dominant_axis = axis_bias < 0;
            blocked = limits.GetUp() == 0 && !limits.GetUpProbeFlag();
            break;
        case FACING_LEFT:
            wrong_direction = dx >= 0;
            dominant_axis = axis_bias > 0;
            blocked = limits.GetLeft() == 0 && !limits.GetLeftProbeFlag();
            break;
        case FACING_RIGHT:
            wrong_direction = dx <= 0;
            dominant_axis = axis_bias > 0;
            blocked = limits.GetRight() == 0 && !limits.GetRightProbeFlag();
            break;
        }
        i32 sign = wrong_direction ? 1 : -1;
        i32 penalty = blocked ? 8 : 0;
        i32 order_penalty;
        switch (relative) {
        case 0: order_penalty = 0; break;
        case 1:
        case 2: order_penalty = 1; break;
        case 3:
        default: order_penalty = 2; break;
        }
        i32 score = penalty + (dominant_axis ? sign * 2 : sign) + order_penalty;
        if (score == best_score) {
            choices[choice_count++] = direction;
        } else if (score < best_score) {
            choices[0] = direction;
            choice_count = 1;
            best_score = score;
        }
    }
    return choices[choice_count > 1 ? RandomBelow(choice_count) : 0];
}

extern "C" i32 SelectRetreatFacing(i32 x, i32 y, i32 target_x, i32 target_y,
    ActorMovementBounds & limits, i32 facing)
{
    i32 dx = target_x - x;
    i32 dy = target_y - y;
    i32 abs_x = dx >= 0 ? dx : -dx;
    i32 abs_y = dy >= 0 ? dy : -dy;
    i32 axis_bias = 0;
    if (abs_x * 2 > abs_y * 3)
        axis_bias = 1;
    else if (abs_x * 3 < abs_y * 2)
        axis_bias = -1;
    i32 choices[4];
    i32 best_score = 0x7FFFFFFF;
    u32 choice_count = 0;
    for (i32 next_relative = 0; next_relative < 4; ++next_relative) {
        i32 relative = next_relative;
        i32 direction = GetRelativeFacing(facing, relative);
        bool wrong_direction = true;
        bool dominant_axis = false;
        bool blocked = true;
        switch (direction) {
        case FACING_DOWN:
            wrong_direction = dy <= 0;
            dominant_axis = axis_bias < 0;
            blocked = limits.GetDown() == 0 && !limits.GetDownProbeFlag();
            break;
        case FACING_UP:
            wrong_direction = dy >= 0;
            dominant_axis = axis_bias < 0;
            blocked = limits.GetUp() == 0 && !limits.GetUpProbeFlag();
            break;
        case FACING_LEFT:
            wrong_direction = dx >= 0;
            dominant_axis = axis_bias > 0;
            blocked = limits.GetLeft() == 0 && !limits.GetLeftProbeFlag();
            break;
        case FACING_RIGHT:
            wrong_direction = dx <= 0;
            dominant_axis = axis_bias > 0;
            blocked = limits.GetRight() == 0 && !limits.GetRightProbeFlag();
            break;
        }
        i32 sign = wrong_direction ? -1 : 1;
        i32 penalty = blocked ? 8 : 0;
        i32 order_penalty;
        switch (relative) {
        case 0: order_penalty = 0; break;
        case 1:
        case 2: order_penalty = 1; break;
        case 3:
        default: order_penalty = 2; break;
        }
        i32 score = penalty + (dominant_axis ? sign * 2 : sign) + order_penalty;
        if (score == best_score) {
            choices[choice_count++] = direction;
        } else if (score < best_score) {
            choices[0] = direction;
            choice_count = 1;
            best_score = score;
        }
    }
    return choices[choice_count > 1 ? RandomBelow(choice_count) : 0];
}
