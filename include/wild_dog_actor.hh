#ifndef WILD_DOG_ACTOR_HH
#define WILD_DOG_ACTOR_HH

#include "animal_actor.hh"

struct GameObject;
struct EntityUpdateContext;
struct EntityVisualController;
struct ActorMovementBounds;
struct Unk_Actor_0809BFE8;
struct WildDogActor;

// Behavior objects only contain their vptr. Native ownership frees them
// directly; there is no virtual destructor slot in these four-word tables.
struct WildDogBehavior {
    virtual void Update(WildDogActor * actor, ActorMovementBounds * bounds) = 0;
    virtual u32 GetMotion(WildDogActor const * actor) const = 0;
};

#pragma interface "wild_dog_actor.hh"

// The visiting dog shares the animal interface. The saved model is borrowed;
// the native constructor and destructor own the five behavior objects.
struct WildDogActor : AnimalActor {
    WildDogActor(GameObject * world, Unk_Actor_0809BFE8 * saved);
    virtual ~WildDogActor();
    virtual void Update(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();
    virtual bool CanBeHit() const;
    virtual void ReactToToolHit();
    virtual void ReactToDogAttack();
    virtual void PauseMovement(u32 frames);

    Unk_Actor_0809BFE8 * saved_model;
    WildDogBehavior * behaviors[5];
    u32 cached_motion;
    u32 cached_facing;
};

// Indexed by saved state +0x0C; the number is the native state ID.
struct WildDogState0 : WildDogBehavior {
    virtual void Update(WildDogActor * actor, ActorMovementBounds * bounds);
    virtual u32 GetMotion(WildDogActor const * actor) const;
};

// Indexed by saved state +0x0C; the number is the native state ID.
struct WildDogState1 : WildDogBehavior {
    virtual void Update(WildDogActor * actor, ActorMovementBounds * bounds);
    virtual u32 GetMotion(WildDogActor const * actor) const;
};

// Indexed by saved state +0x0C; the number is the native state ID.
struct WildDogState2 : WildDogBehavior {
    virtual void Update(WildDogActor * actor, ActorMovementBounds * bounds);
    virtual u32 GetMotion(WildDogActor const * actor) const;
};

// Indexed by saved state +0x0C; the number is the native state ID.
struct WildDogState3 : WildDogBehavior {
    virtual void Update(WildDogActor * actor, ActorMovementBounds * bounds);
    virtual u32 GetMotion(WildDogActor const * actor) const;
};

// Indexed by saved state +0x0C; the number is the native state ID.
struct WildDogState4 : WildDogBehavior {
    virtual void Update(WildDogActor * actor, ActorMovementBounds * bounds);
    virtual u32 GetMotion(WildDogActor const * actor) const;
};

typedef char WildDogActorSizeCheck[sizeof(WildDogActor) == 0x54 ? 1 : -1];
typedef char WildDogActorModelCheck[offsetof(WildDogActor, saved_model) == 0x34 ? 1 : -1];
typedef char WildDogActorBehaviorsCheck[offsetof(WildDogActor, behaviors) == 0x38 ? 1 : -1];
typedef char WildDogActorMotionCheck[offsetof(WildDogActor, cached_motion) == 0x4C ? 1 : -1];
typedef char WildDogActorFacingCheck[offsetof(WildDogActor, cached_facing) == 0x50 ? 1 : -1];


typedef char WildDogBehaviorSizeCheck[sizeof(WildDogBehavior) == 4 ? 1 : -1];

EXTERN_C

// Scans animal slots 46..69 on the requested map, requiring virtual slot
// 0x60 to succeed; returns the nearest by squared distance, or 100 if absent.
u32 FindNearestWildDogTarget(GameObject * world, u32 map, i32 x, i32 y);
bool IsWildDogExitCorridor(i32 x, i32 y);
u32 GetWildDogMotionAnimation(WildDogActor const * actor, u32 motion);
i32 GetWildDogMotionSpeed(WildDogActor const * actor, u32 motion);
WildDogBehavior * GetCurrentWildDogBehavior(WildDogActor const * actor);

EXTERN_C_END

extern "C" u16 const gWildDogMotionAnimations[];


extern "C" char const gCppRuntimeError_EntityUiFourth[];

#endif // WILD_DOG_ACTOR_HH
