#include "actor_movement.hh"

#include "random.hh"

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

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    .align 2, 0\n"
    "\n"
    "    @ Select an index by first-byte weight on a 0..99 roll; fall back to zero.\n"
    "\n"
);

u32 SelectActorBehaviorTimingIndex(ActorBehaviorTiming const * entries,
    u32 count)
{
    u32 value = RandomBelow(100);
    u32 index = 0;
    u32 sum = entries[0].weight;

    while (value >= sum)
    {
        index++;

        if (index < count)
            sum += entries[index].weight;
        else
        {
            index = 0;
            break;
        }
    }

    return index;
}

asm_unified(
    "    .align 2, 0\n"
);


void ActorMovementBounds::RefreshDown()
{
    down_limit = max_distance;
    ClipMapTerrainMovement(terrain, box, &down_limit, 0, 0, 0);
    unk_10 = y_probe != 0 ? !IsMapTerrainBoxBlocked(terrain, box.Moved(0, down_limit + y_probe)) : false;
}

void ActorMovementBounds::RefreshUp()
{
    up_limit = -max_distance;
    ClipMapTerrainMovement(terrain, box, 0, &up_limit, 0, 0);
    unk_11 = y_probe != 0 ? !IsMapTerrainBoxBlocked(terrain, box.Moved(0, up_limit - y_probe)) : false;
}

void ActorMovementBounds::RefreshLeft()
{
    left_limit = -max_distance;
    ClipMapTerrainMovement(terrain, box, 0, 0, &left_limit, 0);
    unk_12 = x_probe != 0 ? !IsMapTerrainBoxBlocked(terrain, box.Moved(left_limit - x_probe, 0)) : false;
}

void ActorMovementBounds::RefreshRight()
{
    right_limit = max_distance;
    ClipMapTerrainMovement(terrain, box, 0, 0, 0, &right_limit);
    unk_13 = x_probe != 0 ? !IsMapTerrainBoxBlocked(terrain, box.Moved(right_limit + x_probe, 0)) : false;
}

ActorMovementBounds ActorMovementBounds::Empty()
{
    ActorMovementBounds result;
    result.unk_10 = true;
    result.unk_11 = true;
    result.unk_12 = true;
    result.unk_13 = true;
    return result;
}

void ActorMovementBounds::ClipAgainstBox(Box const & other, u32 clear_flags)
{
    if (box.x1 < other.x2 && other.x1 < box.x2) {
        i32 dy = box.y2 - other.y1;
        if (dy <= 0 && dy + GetDown() > 0) {
            down_limit = -dy;
            if (clear_flags == 1)
                unk_10 = false;
        }
        dy = box.y1 - other.y2;
        if (dy >= 0 && dy + GetUp() < 0) {
            up_limit = -dy;
            if (clear_flags == 1)
                unk_11 = false;
        }
    }
    if (box.y1 < other.y2 && other.y1 < box.y2) {
        i32 dx = box.x1 - other.x2;
        if (dx >= 0 && dx + GetLeft() < 0) {
            left_limit = -dx;
            if (clear_flags == 1)
                unk_12 = false;
        }
        dx = box.x2 - other.x1;
        if (dx <= 0 && dx + GetRight() > 0) {
            right_limit = -dx;
            if (clear_flags == 1)
                unk_13 = false;
        }
    }
}

void TerrainMovementBounds::RefreshDown()
{
    down_limit = max_distance;
    ClipMapTerrainMovementIgnoringFlag1(terrain, box, &down_limit, 0, 0, 0);
}

void TerrainMovementBounds::RefreshUp()
{
    up_limit = -max_distance;
    ClipMapTerrainMovementIgnoringFlag1(terrain, box, 0, &up_limit, 0, 0);
}

void TerrainMovementBounds::RefreshLeft()
{
    left_limit = -max_distance;
    ClipMapTerrainMovementIgnoringFlag1(terrain, box, 0, 0, &left_limit, 0);
}

void TerrainMovementBounds::RefreshRight()
{
    right_limit = max_distance;
    ClipMapTerrainMovementIgnoringFlag1(terrain, box, 0, 0, 0, &right_limit);
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
