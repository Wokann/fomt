#ifndef WORLD_PROP_ENTITIES_HH
#define WORLD_PROP_ENTITIES_HH

#include "entity.hh"
#include "scene_sprite_indexed.hh"
#include "scene_sprite_group.hh"
#include "more_items.hh"

struct GameEventState;

// The moon and sunrise objects embed group sprites. Their destruction calls
// the contained sprite directly, rather than a second derived virtual table.
struct MoonViewingEffectState {
    GameSceneGroupSprite sprite;

    MoonViewingEffectState(GameObject * world)
        : sprite(world->vfunc_74(), 0, world, 6, 27) {}
};

struct NewYearSunriseEffectState {
    GameSceneGroupSprite sprite;
    i32 y_q16;
    u8 active;
    u8 unk_51;

    NewYearSunriseEffectState(GameObject * world);
};

// The copy constructor copies a complete 0x50-byte record's members, not just
// its first 0x40-byte sprite. Padding between members is not copied.
struct EventScrollingSprite {
    EventScrollingSprite(EventScrollingSprite const & other);

    GameSceneIndexedSprite sprite;
    i32 x_q16;
    i16 y;
    i32 speed_q16;
    u8 width;
    bool draw_on_next_call;

    EventScrollingSprite(GameObject * world, u32 animation, i32 x_q16,
        i16 y, i32 speed_q16, u8 width)
        : sprite(world->vfunc_7C(), animation, world, 6, 29, false),
          x_q16(x_q16), y(y), speed_q16(speed_q16), width(width),
          draw_on_next_call(true) {}
};

// Only count records are live; unused capacity owns no graphics resources.
struct EventScrollingSprites {
    enum { CAPACITY = 5 };
    u32 count;
    u32 storage[CAPACITY * sizeof(EventScrollingSprite) / sizeof(u32)];

    EventScrollingSprites(GameObject * world, bool new_year_sunrise);
    EventScrollingSprite * Data() { return reinterpret_cast<EventScrollingSprite *>(storage); }
    EventScrollingSprite * End() { return &Data()[count]; }
    void Push(EventScrollingSprite const & sprite);
    ~EventScrollingSprites()
    {
        EventScrollingSprite * last = End();
        EventScrollingSprite * first = Data();
        while (first != last) {
            first->~EventScrollingSprite();
            ++first;
        }
    }
};

struct EntityStarSparkles {
    enum { CAPACITY = 5 };
    u32 count;
    u32 storage[CAPACITY * sizeof(GameSceneIndexedSprite) / sizeof(u32)];
    bool complete[CAPACITY];

    GameSceneIndexedSprite * Data() { return reinterpret_cast<GameSceneIndexedSprite *>(storage); }
    GameSceneIndexedSprite * End() { return &Data()[count]; }
    ~EntityStarSparkles()
    {
        GameSceneIndexedSprite * last = End();
        GameSceneIndexedSprite * first = Data();
        while (first != last) {
            first->~GameSceneIndexedSprite();
            ++first;
        }
    }
};

#pragma interface "world_prop_entities.hh"

struct CoopEggEntity;

struct CoopEggVisualController : EntityVisualController {
    CoopEggVisualController(CoopEggEntity * entity);
    virtual ~CoopEggVisualController();
    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    GameSceneGroupSprite sprite;
};

struct CoopEggEntity : AEntity {
    // The world passes the Location at the beginning of Coop::Egg.
    CoopEggEntity(GameObject * world, Location const & location);
    virtual ~CoopEggEntity();
    virtual Box GetBox() const;
    virtual EntityVisualController * CreateVisualController();
};


// Retained world factories allocate 0x18 bytes; growing the type requires
// updating those actual allocation sites, not just relocating its methods.

struct Product;

struct ShippingBasketEntity;

struct ShippingBasketVisualController : EntityVisualController {
    ShippingBasketVisualController(ShippingBasketEntity * entity);
    virtual ~ShippingBasketVisualController();
    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    void StartItemBounce();

    GameSceneGroupSprite sprite;
    u8 bounce_countdown;
};

struct ShippingBasketEntity : AEntity {
    ShippingBasketEntity(GameObject * world, MoreItems * contents);
    virtual ~ShippingBasketEntity();
    virtual Box GetBox() const;
    virtual EntityVisualController * CreateVisualController();

    void AppendItem(Product const & product);
    bool IsFull() const;
    static Box GetBoxAt(i32 x, i32 y);
    MoreItems * contents;
};


// The retained world factory allocates 0x1C bytes. Native drawing and item
// insertion still access the verified fields directly.

struct DogBallEntity;

struct DogBallVisualController : EntityVisualController {
    DogBallVisualController(DogBallEntity * entity);
    virtual ~DogBallVisualController();
    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    void SetAnimation(u32 index);

    GameSceneIndexedSprite sprite;
};

struct DogBallEntity : AEntity {
    DogBallEntity(GameObject * world, Location * saved_location);
    virtual ~DogBallEntity();
    virtual Box GetBox() const;
    virtual void Update(EntityUpdateContext const & context);
    virtual void UpdateWhileSuspended(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();

    void Throw(u32 direction);
    bool IsInFlight() const;
    bool IsCarried() const;
    void UpdateFlight();
    i32 GetHeight() const;
    void SetCarriedPosition(i32 x_q16, i32 y_q16, u32 dog_animation, u32 direction);
    void UpdateCarriedAnimation(u32 dog_animation, u32 direction);
    void StopBeingCarried();

    /* +18 */ Location * saved_location;
    /* +1C */ i32 height_q16;
    /* +20 */ i32 vertical_velocity_q16;
    /* +24 */ u8 throw_direction;
    /* +25 */ bool in_flight;
    /* +26 */ bool carried;
    /* +28 */ u16 animation;
};


// The retained world factory allocates 0x2C bytes. The native constructor
// leaves velocity/direction untouched until Throw initializes them.

struct EntityEventEffectHost : AEntity {
    EntityEventEffectHost(GameObject * world, GameEventState * event_state);
    virtual ~EntityEventEffectHost();
    virtual EntityVisualController * CreateVisualController();

    GameEventState * event_state;
};

struct EntityEventEffectController : EntityVisualController {
    EntityEventEffectController(EntityEventEffectHost * host);
    virtual ~EntityEventEffectController();
    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    SmartPtr<MoonViewingEffectState> moon;
    SmartPtr<NewYearSunriseEffectState> sunrise;
    SmartPtr<EntityStarSparkles> sparkles;
    SmartPtr<EventScrollingSprites> scrolling_sprites;
};


extern "C" void CreateEntityNewYearSunriseEffect(AEntity * entity);
extern "C" void PlayEntityNewYearSunriseEffect(AEntity * entity);
extern "C" bool IsEntityNewYearSunriseEffectComplete(AEntity * entity);
extern "C" void DestroyEntityNewYearSunriseEffect(AEntity * entity);
extern "C" void PlayEntityStarSparkleEffect(AEntity * entity);
extern "C" bool HasEntityStarSparkleEffect(AEntity * entity);

extern "C" void CreateControllerNewYearSunriseEffect(EntityEventEffectController & controller);
extern "C" void PlayControllerNewYearSunriseEffect(EntityEventEffectController & controller);
extern "C" bool IsControllerNewYearSunriseEffectComplete(EntityEventEffectController & controller);
extern "C" void DestroyControllerNewYearSunriseEffect(EntityEventEffectController & controller);
extern "C" void PlayControllerStarSparkleEffect(EntityEventEffectController * controller);
extern "C" bool HasControllerStarSparkleEffect(EntityEventEffectController * controller);

// Retained native factories still use the verified 0x1C/0x18/0x14C sizes;
// changing these object layouts also requires updating their allocation sites.

// These retained member implementations follow the ordinary entity methods.
// The old frontend emits implemented inline members in reverse definition order.





// The native coordinate records are only halfword-aligned.
struct EntityEventSparklePosition {
    u16 x;
    u16 y;
} PACKED;

extern "C" EntityEventSparklePosition const gEntityEventSparklePositions[];
extern "C" u8 const gEntityEventScrollingHeights[];
extern "C" u32 const gEntityEventScrollingSpeeds[];
extern "C" u16 const gUnk_080F1684[][4];


extern "C" char const gCppRuntimeError_EntityUiThird[];

#endif // WORLD_PROP_ENTITIES_HH
