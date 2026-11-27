#ifndef ACTOR_MOVEMENT_HH
#define ACTOR_MOVEMENT_HH

#include "unknown_types.hh"
#include "map_terrain.hh"


// Native callers select by weight and form the duration as
// 60 * base_duration + RandomBelow(60 * random_duration).
struct ActorBehaviorTiming
{
    u8 weight;
    u8 base_duration;
    u8 random_duration;
    u8 unk_03;
};


// Return a table index, not an event or behavior ID. The original caller
// supplies a nonempty table; incomplete cumulative weight falls back to 0.
extern "C" u32 SelectActorBehaviorTimingIndex(ActorBehaviorTiming const * entries, u32 count);

// Lazily cached pixel-distance limits for an actor collision box.
// The four flag bytes are preserved without assigning an unverified gameplay meaning.
struct ActorMovementBounds
{
    i32 down_limit;
    i32 up_limit;
    i32 left_limit;
    i32 right_limit;
    bool unk_10;
    bool unk_11;
    bool unk_12;
    bool unk_13;
    MapTerrainView terrain;
    Box box;
    i32 max_distance;
    i32 x_probe;
    i32 y_probe;

    ActorMovementBounds()
        : down_limit(0), up_limit(0), left_limit(0), right_limit(0),
          unk_10(false), unk_11(false), unk_12(false), unk_13(false),
          terrain(0, 0, 0), box(0, 0), max_distance(1), x_probe(0), y_probe(0) {}
    // Native movement probes fill the four flag bytes only when refreshed.
    ActorMovementBounds(MapTerrainView const & terrain, Box const & box, i32 max_distance)
        : down_limit(max_distance + 1), up_limit(-max_distance - 1),
          left_limit(-max_distance - 1), right_limit(max_distance + 1),
          terrain(terrain), box(box), max_distance(max_distance), x_probe(0), y_probe(0) {}
    static ActorMovementBounds Empty();

    // Clip against another box; a value of 1 also clears the affected probe flags.
    void ClipAgainstBox(Box const & other, u32 clear_flags);

    void RefreshDown();
    void RefreshUp();
    void RefreshLeft();
    void RefreshRight();
    // Probe flags refresh the same lazy cache as their distance getters.
    bool GetDownProbeFlag() {
        if (down_limit > max_distance)
            RefreshDown();
        return unk_10;
    }
    bool GetUpProbeFlag() {
        if (up_limit < -max_distance)
            RefreshUp();
        return unk_11;
    }
    bool GetLeftProbeFlag() {
        if (left_limit < -max_distance)
            RefreshLeft();
        return unk_12;
    }
    bool GetRightProbeFlag() {
        if (right_limit > max_distance)
            RefreshRight();
        return unk_13;
    }

    i32 GetDown() {
        i32 cached = down_limit;
        if (cached > max_distance) {
            RefreshDown();
            return down_limit;
        }
        return cached;
    }
    i32 GetUp() {
        i32 cached = up_limit;
        if (cached < -max_distance) {
            RefreshUp();
            return up_limit;
        }
        return cached;
    }
    i32 GetLeft() {
        i32 cached = left_limit;
        if (cached < -max_distance) {
            RefreshLeft();
            return left_limit;
        }
        return cached;
    }
    i32 GetRight() {
        i32 cached = right_limit;
        if (cached > max_distance) {
            RefreshRight();
            return right_limit;
        }
        return cached;
    }
};


// Cached signed pixel-distance limits that test terrain bit 0 only.
// This is the separate 0x28-byte layout, not ActorMovementBounds.
struct TerrainMovementBounds
{
    i32 down_limit;
    i32 up_limit;
    i32 left_limit;
    i32 right_limit;
    MapTerrainView terrain;
    Box box;
    i32 max_distance;

    void RefreshDown();
    void RefreshUp();
    void RefreshLeft();
    void RefreshRight();
};


EXTERN_C

// Relative order: forward, actor-left, actor-right, back.
// Preserve the original switch fallthrough for values outside 0..3.
i32 GetRelativeFacing(i32 facing, i32 relative);

// Score four directions against target displacement and cached movement bounds.
// Prefer the lowest score, breaking tied choices with RandomBelow.
i32 SelectApproachFacing(i32 x, i32 y, i32 target_x, i32 target_y,
    ActorMovementBounds & limits, i32 facing);
i32 SelectRetreatFacing(i32 x, i32 y, i32 target_x, i32 target_y,
    ActorMovementBounds & limits, i32 facing);

EXTERN_C_END

#endif // ACTOR_MOVEMENT_HH
