#ifndef WORLD_AMBIENT_SPRITES_HH
#define WORLD_AMBIENT_SPRITES_HH

#include "prelude.h"
#include "entity.hh"
#include "scene_sprite_indexed.hh"
#include "scene_sprite_group.hh"
#include "smart_ptr.hh"
#include "world_ambient_entity_factory.hh"
#include "world_ambient_animation.hh"

#pragma interface "world_ambient_sprites.hh"

struct GameObject;
// Three 16-byte records follow CursedToolState in the saved actor state.
// Initialization clears only each record's low nibble, not the other words.
// The ambient controller owns three of these 16-byte saved records.
// Only kind is initialized; unused bits and other fields retain their bytes.
struct GameStateActorRecord {
    GameStateActorRecord() : kind(0) {}

    /* +00 */ u32 kind : 4;
    u32 unk_00 : 28;
    /* +04 */ u32 direction;
    /* +08 */ i16 x;
    /* +0A */ i16 y;
    // Kind 6 writes both signed nibbles; restoration reads only the first.
    /* +0C */ i8 current_position : 4;
    i8 next_position : 4;
    u8 unk_0D[3];
};


struct WorldSpriteDrawBuffer;
struct HardwareDmaQueue;

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

struct WorldAmbientSpriteController : EntityVisualController {
    enum { CAPACITY = 3 };
    typedef SmartPtr<WorldAmbientSprite> SpriteOwner;

    inline WorldAmbientSpriteController(WorldAmbientEntity * owner);
    virtual ~WorldAmbientSpriteController();
    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    SpriteOwner * Data() { return reinterpret_cast<SpriteOwner *>(storage); }
    SpriteOwner * End() { return Data() + count; }

    /* +08 */ u32 count;
    // Native factories construct only the first count owners, not unused slots.
    /* +0C */ u32 storage[CAPACITY * sizeof(SpriteOwner) / sizeof(u32)];
};

// The base owns the indexed animation and an optional secondary group.
// The three pure virtual slots are supplied by the concrete ambient kinds.
struct WorldAmbientSprite {
    WorldAmbientSprite(GameObject * world, u32 animation, u32 secondary_sprite_flag);
    /* vt+08 */ virtual ~WorldAmbientSprite();
    /* vt+0C */ virtual void Update() = 0;
    /* vt+10 */ virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue) = 0;
    /* vt+14 */ virtual void SaveState(GameStateActorRecord & record) const = 0;

    void SetAnimation(u32 index)
    {
        if (animation != index) {
            sprite.SetAnimation(index);
            animation = index;
        }
    }

    /* +00 */ GameObject * world;
    /* +04 */ u16 animation;
    /* +08 */ GameSceneIndexedSprite sprite;
    /* +48 */ SmartPtr<GameSceneGroupSprite> secondary_sprite;
    /* +4C */ // vtable
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


// Kind numbers are the native saved-record discriminator, not species names.
// Species/resource identities are still unconfirmed. Each is a distinct
// concrete type with the original virtual interface and instance layout.
struct WorldAmbientKind1 : WorldAmbientSprite {
    enum { KIND = 1 };
    WorldAmbientKind1(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind1();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind2 : WorldAmbientSprite {
    enum { KIND = 2 };
    WorldAmbientKind2(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind2();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind3 : WorldAmbientSprite {
    enum { KIND = 3 };
    WorldAmbientKind3(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind3();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind4 : WorldAmbientSprite {
    enum { KIND = 4 };
    WorldAmbientKind4(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind4();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind5 : WorldAmbientSprite {
    enum { KIND = 5 };
    WorldAmbientKind5(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind5();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
    /* +64 */ i16 phase;
    /* +66 */ i16 phase_step;
    /* +68 */ i32 height_q16;
};


struct WorldAmbientKind6 : WorldAmbientSprite {
    enum { KIND = 6 };
    WorldAmbientKind6(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind6();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
    // Only target X/Y and their Q16 copies are used by this behavior.
    /* +64 */ WorldAmbientMotion target;
    /* +78 */ i8 current_position;
    /* +79 */ i8 next_position;
    /* +7C */ i32 velocity_x_q16;
    /* +80 */ i32 velocity_y_q16;
    /* +84 */ i8 vertical_offset;
    /* +86 */ i16 sound_ticks;
};


struct WorldAmbientKind7 : WorldAmbientSprite {
    enum { KIND = 7 };
    WorldAmbientKind7(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind7();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind8 : WorldAmbientSprite {
    enum { KIND = 8 };
    WorldAmbientKind8(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind8();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind9 : WorldAmbientSprite {
    enum { KIND = 9 };
    WorldAmbientKind9(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind9();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind10 : WorldAmbientSprite {
    enum { KIND = 10 };
    WorldAmbientKind10(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind10();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind11 : WorldAmbientSprite {
    enum { KIND = 11 };
    WorldAmbientKind11(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind11();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};


struct WorldAmbientKind12 : WorldAmbientSprite {
    enum { KIND = 12 };
    WorldAmbientKind12(GameObject * world, GameStateActorRecord const & record);
    virtual ~WorldAmbientKind12();
    virtual void Update();
    virtual void Draw(GameObject * world, WorldSpriteDrawBuffer * buffer,
        HardwareDmaQueue * queue);
    virtual void SaveState(GameStateActorRecord & record) const;

    /* +50 */ WorldAmbientMotion motion;
};



// World slot 84 saves exactly three ambient records. The flag chooses between
// restoring those records and generating a fresh set after vfunc_14.
struct WorldAmbientEntity : AEntity {
    WorldAmbientEntity(GameObject * world, GameStateActorRecord * records)
        : AEntity(world, Location(0, 0, 0)), records(records), restore_saved_records(true) {}

    virtual ~WorldAmbientEntity();
    virtual void vfunc_14();
    virtual EntityVisualController * CreateVisualController();

    /* +18 */ GameStateActorRecord * records;
    /* +1C */ bool restore_saved_records;
};

inline WorldAmbientSpriteController::WorldAmbientSpriteController(WorldAmbientEntity * owner)
    : EntityVisualController(owner), count(0) {}


EXTERN_C

void DrawWorldAmbientSprite(WorldAmbientSprite * self, GameObject * world,
    WorldSpriteDrawBuffer * buffer, HardwareDmaQueue * queue,
    i32 x, i32 y, i32 vertical_offset, u32 flags);
u32 SelectWorldAmbientSpawnPosition(WorldAmbientSprite * self,
    WorldAmbientMotion * motion, i8 position_index);
// Native callers test the complete r0 result, not a byte-sized bool.
u32 UpdateWorldAmbientMotion(WorldAmbientSprite * self,
    WorldAmbientMotion * motion, i32 speed_q16);
i32 GetWorldAmbientSpriteSine(WorldAmbientSprite const * self, i16 phase);
i32 GetWorldAmbientSpriteCosine(WorldAmbientSprite const * self, i16 phase);
void PlayWorldAmbientSpriteSound(WorldAmbientSprite * self, u32 song_id);
void PopulateWorldAmbientSprites(WorldAmbientSpriteController * controller,
    GameObject * world, u32 season, u8 nighttime);

EXTERN_C_END

extern "C" WorldAmbientSpawnPosition const gWorldAmbientSpawnPositions[];
extern "C" i16 const gWorldAmbientSineTable[];
extern "C" WorldAmbientSpawnWeights const gWorldAmbientDaySpawnWeights[];
extern "C" WorldAmbientSpawnWeights const gWorldAmbientNightSpawnWeights[];


#endif // WORLD_AMBIENT_SPRITES_HH
