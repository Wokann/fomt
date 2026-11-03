#ifndef ENTITY_HH
#define ENTITY_HH

#include "prelude.h"

#include "actor.hh" // TODO: move Location
#include "smart_ptr.hh"
#include "unknown_types.hh"
#include "entity_sprite.hh"

// The scene supplies the input object; the world adds a zero-or-one minute tick.
// Native world/entity callers copy this pointer word and read the flag at +4.
struct HardwareInputState;
struct EntityUpdateContext {
    HardwareInputState * input;
    bool minute_advanced;

    EntityUpdateContext(HardwareInputState * state, bool advanced)
        : input(state), minute_advanced(advanced) {}
};

typedef char EntityUpdateContextSizeCheck[sizeof(EntityUpdateContext) == 8 ? 1 : -1];
typedef char EntityUpdateContextMinuteCheck[offsetof(EntityUpdateContext, minute_advanced) == 4 ? 1 : -1];

// The world supplies shared queues/buffer and two signed camera pixels.
struct HardwareDmaQueue;
struct HardwareDisplayState;
struct WorldSpriteDrawBuffer;
struct EntityDrawContext {
    HardwareDmaQueue * queue;
    HardwareDisplayState * display;
    WorldSpriteDrawBuffer * buffer;
    i16 camera_x;
    i16 camera_y;
};
typedef char EntityDrawContextSizeCheck[sizeof(EntityDrawContext) == 16 ? 1 : -1];
typedef char EntityDrawBufferCheck[offsetof(EntityDrawContext, buffer) == 8 ? 1 : -1];
typedef char EntityDrawCameraCheck[offsetof(EntityDrawContext, camera_x) == 12 ? 1 : -1];

struct AEntity
{
    AEntity(GameObject * game_object, Location const & location);

    /* vt+08 */ virtual ~AEntity() {}
    /* vt+0C */ virtual Box GetBox() const;
    /* vt+10 */ virtual void vfunc_10();
    /* vt+14 */ virtual void vfunc_14();
    /* vt+18 */ virtual void Update(EntityUpdateContext const & context);
    /* vt+1C */ virtual void Draw(EntityDrawContext const & context);
    /* vt+20 */ virtual void SuspendNormalUpdates();
    /* vt+24 */ virtual void ResumeNormalUpdates();
    /* vt+28 */ virtual bool IsNormalUpdateSuspended() const;
    /* vt+2C */ virtual void UpdateWhileSuspended(EntityUpdateContext const & context);
    /* vt+30 */ virtual EntityVisualController * vfunc_30() = 0;

    void SetLocation(u32 map, i32 x, i32 y);
    Location GetLocation() const;
    void SetMap(u32 map);

    i32 GetQ16X() const { return x_q16; }
    void SetQ16X(i32 x_q16) { this->x_q16 = x_q16; }
    i32 GetQ16Y() const { return y_q16; }
    void SetQ16Y(i32 y_q16) { this->y_q16 = y_q16; }
    void SetLocation(Location const & location) { SetLocation(location.map, location.x, location.y); }
    u32 GetMap() const { return location_map; }
    void PutOutOfTown() { SetMap(MAP_NONE); }
    GameObject * GetGameObject() const { return game_object; }

    /* +00 */ GameObject * game_object;
    /* +04 */ u16 location_map;
    /* +06 */ bool normal_update_suspended;
    /* +08 */ i32 x_q16;
    /* +0C */ i32 y_q16;
    /* +10 */ SmartPtr<EntityVisualController> unk_10;
    /* +14 */ // vtable
};

typedef char AEntityNormalUpdateFlagCheck[offsetof(AEntity, normal_update_suspended) == 6 ? 1 : -1];

#endif // ENTITY_HH
