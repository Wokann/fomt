#ifndef WORLD_AMBIENT_TYPES_HH
#define WORLD_AMBIENT_TYPES_HH

#include "prelude.h"
#include "smart_ptr.hh"

// Restoring constructors receive the state following the saved kind word.
struct WorldAmbientSavedState {
    /* +00 */ u32 direction;
    /* +04 */ i16 x;
    /* +06 */ i16 y;
    /* +08 */ i8 current_position : 4;
    i8 next_position : 4;
    u8 unk_09[3];
};

// Three 16-byte records follow CursedToolState in the saved actor state.
// Initialization clears only each record's low nibble, not the other words.
// The ambient controller owns three of these 16-byte saved records.
// Only kind is initialized; unused bits and other fields retain their bytes.
struct GameStateActorRecord {
    GameStateActorRecord() : kind(0) {}

    /* +00 */ u32 kind : 4;
    u32 unk_00 : 28;
    /* +04 */ WorldAmbientSavedState state;
};


// The ambient-sprite position selector reads consecutive X/Y halfwords.
struct WorldAmbientSpawnPosition {
    i16 x;
    i16 y;
}
    PACKED ALIGN(2)
;

// The selector uses a five-byte stride: four seasonal weights, then its count
// parameter. A parameter above 1 produces 1 + RandomBelow(parameter - 1).
struct WorldAmbientSpawnWeights {
    u8 season_weight[4];
    u8 count_limit;
} PACKED;

struct WorldAmbientSprite;
struct WorldAmbientEntity;

// The controller embeds a count-prefixed container. Its unused capacity
// is storage; only the counted owners are constructed and destroyed.
struct WorldAmbientSpriteOwners {
    enum { CAPACITY = 3 };
    typedef SmartPtr<WorldAmbientSprite> Owner;

    WorldAmbientSpriteOwners() : count(0) {}
    Owner * Data() { return reinterpret_cast<Owner *>(storage); }
    Owner * End()
    {
        return reinterpret_cast<Owner *>(reinterpret_cast<u8 *>(this)
            + (offsetof(WorldAmbientSpriteOwners, storage) + count * sizeof(Owner)));
    }
    Owner & operator[](u32 index)
    {
        return *reinterpret_cast<Owner *>(reinterpret_cast<u8 *>(this)
            + (offsetof(WorldAmbientSpriteOwners, storage) + index * sizeof(Owner)));
    }
    inline void Append(WorldAmbientSprite * sprite);

    u32 count;
    u32 storage[CAPACITY * sizeof(Owner) / sizeof(u32)];
};

// Used at +0x50 by the moving ambient kinds. Native consumers retain these
// field offsets and their fixed allocation sizes while the derived types
// are being recovered.
struct WorldAmbientMotion {
    WorldAmbientMotion() {}
    WorldAmbientMotion(u32 direction, i16 x, i16 y)
        : direction(direction), x(x), y(y), direction_ticks(0), state(0) {
        x_q16 = x * 0x10000;
        y_q16 = y * 0x10000;
    }

    /* +00 */ u32 direction;
    /* +04 */ i16 x;
    /* +06 */ i16 y;
    /* +08 */ i32 x_q16;
    /* +0C */ i32 y_q16;
    /* +10 */ i16 direction_ticks;
    /* +12 */ i8 state; // States depend on the concrete kind.
};


#endif // WORLD_AMBIENT_TYPES_HH
