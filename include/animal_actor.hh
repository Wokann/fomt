#ifndef ANIMAL_ACTOR_HH
#define ANIMAL_ACTOR_HH

#include "entity_actor.hh"
#include "livestock.hh"

extern char const gCppRuntimeError_AnimalData[];
extern char const gText_AnimalDataFallbackNone[];
extern ActorBehaviorTiming const gUnk_080F0838[2][2][13];
extern u16 const gDogBehaviorAnimations[2][13];
extern ActorBehaviorTiming const gUnk_080F093C[2][2][7];
extern u16 const gHorseBehaviorAnimations[2][7];
extern ActorBehaviorTiming const gUnk_080F09C8[2][2][2][5];
extern u16 const gChickenBehaviorAnimations[2][5];
extern ActorBehaviorTiming const gUnk_080F0A7C[2][4][2][7];
extern u16 const gCowBehaviorAnimations[4][7];
extern ActorBehaviorTiming const gUnk_080F0C74[2][4][2][7];
extern u16 const gSheepBehaviorAnimations[4][7];

#pragma interface "animal_actor.hh"

// All farm animals and the visiting wild dog share this 35-word interface.
// The sound gate is the only field added to AActorEntity.
struct AnimalActor : AActorEntity {
    AnimalActor(GameObject * world, ActorLocation const & location, u32 animation);
    virtual ~AnimalActor();
    virtual Box GetBox() const;
    virtual void Update(EntityUpdateContext const & context);
    void RequestSound(u32 song_id);

    /* vt+3C */ virtual void RespondToBell(Location const & origin);
    /* vt+40 */ virtual void vfunc_40();
    /* vt+44 */ virtual bool CanBeHit() const;
    /* vt+48 */ virtual bool CanReceiveCowMiraclePotion() const;
    /* vt+4C */ virtual bool CanReceiveSheepMiraclePotion() const;
    /* vt+50 */ virtual bool CanBeBrushed() const;
    /* vt+54 */ virtual bool CanBeMilked() const;
    /* vt+58 */ virtual bool CanBeSheared() const;
    /* vt+5C */ virtual bool IsSick() const;
    /* vt+60 */ virtual bool CanBeAttackedByWildDog() const;
    /* vt+64 */ virtual void ReactToToolHit();
    /* vt+68 */ virtual void StartCowPregnancy();
    /* vt+6C */ virtual void StartSheepPregnancy();
    /* vt+70 */ virtual void Brush();
    /* vt+74 */ virtual Livestock::ProductRank Milk();
    /* vt+78 */ virtual Livestock::ProductRank Shear();
    /* vt+7C */ virtual void CureSickness();
    /* vt+80 */ virtual void ReactToDogAttack();
    /* vt+84 */ virtual void RespondToPush(u32 facing, u32 frames);
    /* vt+88 */ virtual void PauseMovement(u32 frames) = 0;

    bool sound_requested;
};


struct Dog;
struct Horse;
struct Chicken;
struct Cow;
struct Sheep;

struct DogActor : AnimalActor {
    DogActor(GameObject * world, Dog * saved, Location * ball_location);
    virtual ~DogActor();
    virtual Box GetBox() const;
    virtual void Update(EntityUpdateContext const & context);
    virtual void UpdateWhileSuspended(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();
    virtual bool CanBeHit() const;
    virtual void ReactToToolHit();
    virtual void PauseMovement(u32 frames);
    void RespondToCall(Location const & origin);
    void UpdateBehavior();
    void DropBall();
    u32 GetBehaviorAnimation(u32 behavior) const;
    i32 GetBehaviorMoveSpeed(u32 behavior) const;
    void SetBehavior(u32 behavior, u32 direction);
    u32 GetBehavior() const;

    Dog * dog;
    Location * ball_location;
    i16 saved_x;
    i16 saved_y;
    bool unk_40;
    u8 last_behavior;
    u8 unk_42[2];
};


// The horse selects its sprite profile from its saved growth stage.
struct HorseSpriteController : EntitySpriteController {
    HorseSpriteController(AActorEntity * entity, u32 growth_stage);
    virtual ~HorseSpriteController();
    virtual void Draw(EntityDrawContext const & context);
};


struct HorseActor : AnimalActor {
    HorseActor(GameObject * world, Horse * saved);
    virtual ~HorseActor();
    virtual void Update(EntityUpdateContext const & context);
    virtual void UpdateWhileSuspended(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();
    virtual void vfunc_40();
    virtual bool CanBeBrushed() const;
    virtual void Brush();
    virtual void RespondToPush(u32 facing, u32 frames);
    virtual void PauseMovement(u32 frames);
    void RespondToCall(Location const & origin);
    void BeginRiding();
    void EndRiding();
    i32 GetBehaviorMoveSpeed(u32 behavior) const;
    u32 GetBehaviorAnimation(u32 behavior) const;
    u32 GetBehavior() const;
    void SetBehavior(u32 behavior, u32 direction);

    Horse * horse;
    i16 jump_target_x;
    i16 jump_target_y;
    u8 last_behavior;
    u8 jump_in_progress;
    u8 rider_mounted;
};


struct ChickenActor : AnimalActor {
    ChickenActor(GameObject * world, Chicken * saved);
    virtual ~ChickenActor();
    virtual Box GetBox() const;
    virtual void Update(EntityUpdateContext const & context);
    virtual void UpdateWhileSuspended(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();
    virtual bool CanBeHit() const;
    virtual bool IsSick() const;
    virtual bool CanBeAttackedByWildDog() const;
    virtual void ReactToToolHit();
    virtual void CureSickness();
    virtual void ReactToDogAttack();
    virtual void PauseMovement(u32 frames);
    void UpdateBehavior(EntityUpdateContext const & context);
    u32 GetBehaviorAnimation(u32 behavior) const;
    i32 GetBehaviorMoveSpeed(u32 behavior) const;
    void SetBehavior(u32 behavior, u32 direction);
    u32 GetBehavior() const;

    Chicken * livestock;
    u8 last_behavior;
    u8 unk_39[3];
};


struct CowActor : AnimalActor {
    CowActor(GameObject * world, Cow * saved);
    virtual ~CowActor();
    virtual void Update(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();
    virtual void RespondToBell(Location const & origin);
    virtual void vfunc_40();
    virtual bool CanBeHit() const;
    virtual bool CanReceiveCowMiraclePotion() const;
    virtual bool CanBeBrushed() const;
    virtual bool CanBeMilked() const;
    virtual bool IsSick() const;
    virtual bool CanBeAttackedByWildDog() const;
    virtual void ReactToToolHit();
    virtual void StartCowPregnancy();
    virtual void Brush();
    virtual Livestock::ProductRank Milk();
    virtual void CureSickness();
    virtual void ReactToDogAttack();
    virtual void RespondToPush(u32 facing, u32 frames);
    virtual void PauseMovement(u32 frames);
    u32 GetBehaviorAnimation(u32 behavior) const;
    i32 GetBehaviorMoveSpeed(u32 behavior) const;
    u32 GetBehavior() const;
    void SetBehavior(u32 behavior, u32 direction);

    Cow * livestock;
    u8 last_behavior;
    u8 unk_39[3];
};


struct SheepActor : AnimalActor {
    SheepActor(GameObject * world, Sheep * saved);
    virtual ~SheepActor();
    virtual void Update(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();
    virtual void RespondToBell(Location const & origin);
    virtual void vfunc_40();
    virtual bool CanBeHit() const;
    virtual bool CanReceiveSheepMiraclePotion() const;
    virtual bool CanBeBrushed() const;
    virtual bool CanBeSheared() const;
    virtual bool IsSick() const;
    virtual bool CanBeAttackedByWildDog() const;
    virtual void ReactToToolHit();
    virtual void StartSheepPregnancy();
    virtual void Brush();
    virtual Livestock::ProductRank Shear();
    virtual void CureSickness();
    virtual void ReactToDogAttack();
    virtual void RespondToPush(u32 facing, u32 frames);
    virtual void PauseMovement(u32 frames);
    u32 GetBehaviorAnimation(u32 behavior) const;
    i32 GetBehaviorMoveSpeed(u32 behavior) const;
    u32 GetBehavior() const;
    void SetBehavior(u32 behavior, u32 direction);

    Sheep * livestock;
    u8 last_behavior;
    u8 unk_39[3];
};


// The native dog keeps a borrowed pointer to the saved six-byte ball location.

extern "C" bool IsDogActorCarryingBall(DogActor const * actor);
extern "C" void NotifyDogActorBallLanded(DogActor * actor, Location const & location);
extern "C" Box MakeAnimalActorBounds(i32 x, i32 y);


#pragma interface "animal_actor_lifetimes.hh"

inline AnimalActor::~AnimalActor()
{
}

#endif // ANIMAL_ACTOR_HH
