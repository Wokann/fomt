#ifndef ANIMAL_ACTOR_HH
#define ANIMAL_ACTOR_HH

#include "entity_actor.hh"
#include "livestock.hh"

extern char const gCppRuntimeError_AnimalData[];
extern char const gText_AnimalDataFallbackNone[];
extern ActorBehaviorTiming const gUnk_080F0838[2][2][13];
extern u16 const gUnk_080F0908[2][13];
extern ActorBehaviorTiming const gUnk_080F093C[28];
extern u16 const gUnk_080F09AC[2][7];
extern ActorBehaviorTiming const gUnk_080F09C8[40];
extern u16 const gUnk_080F0A68[10];
extern ActorBehaviorTiming const gUnk_080F0A7C[112];
extern u16 const gUnk_080F0C3C[28];
extern ActorBehaviorTiming const gUnk_080F0C74[112];
extern u16 const gUnk_080F0E34[28];

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

typedef char AnimalActorSizeCheck[sizeof(AnimalActor) == 0x34 ? 1 : -1];
typedef char AnimalActorSoundGateCheck[offsetof(AnimalActor, sound_requested) == 0x30 ? 1 : -1];

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

    Dog * dog;
    Location * ball_location;
    i16 saved_x;
    i16 saved_y;
    u8 unk_40;
    u8 unk_41[3]; // Remaining native RAM state; not a decoded layout yet.
};

typedef char DogActorSizeCheck[sizeof(DogActor) == 0x44 ? 1 : -1];
typedef char DogActorSavedModelCheck[offsetof(DogActor, dog) == 0x34 ? 1 : -1];

// The horse selects its sprite profile from its saved growth stage.
struct HorseSpriteController : EntitySpriteController {
    HorseSpriteController(AActorEntity * entity, u32 growth_stage);
    virtual ~HorseSpriteController();
    virtual void Draw(EntityDrawContext const & context);
};

typedef char HorseSpriteControllerSizeCheck[sizeof(HorseSpriteController) == 0x8C ? 1 : -1];

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

    Horse * horse;
    i16 saved_x;
    i16 saved_y;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
};

typedef char HorseActorSizeCheck[sizeof(HorseActor) == 0x40 ? 1 : -1];
typedef char HorseActorSavedModelCheck[offsetof(HorseActor, horse) == 0x34 ? 1 : -1];

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

    Chicken * livestock;
    u8 unk_38[4]; // Native motion state; individual byte roles remain under review.
};

typedef char ChickenActorSizeCheck[sizeof(ChickenActor) == 0x3C ? 1 : -1];
typedef char ChickenActorSavedModelCheck[offsetof(ChickenActor, livestock) == 0x34 ? 1 : -1];

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

    Cow * livestock;
    u8 unk_38[4]; // Native motion state; individual byte roles remain under review.
};

typedef char CowActorSizeCheck[sizeof(CowActor) == 0x3C ? 1 : -1];
typedef char CowActorSavedModelCheck[offsetof(CowActor, livestock) == 0x34 ? 1 : -1];

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

    Sheep * livestock;
    u8 unk_38[4]; // Native motion state; individual byte roles remain under review.
};

typedef char SheepActorSizeCheck[sizeof(SheepActor) == 0x3C ? 1 : -1];
typedef char SheepActorSavedModelCheck[offsetof(SheepActor, livestock) == 0x34 ? 1 : -1];

// The native dog keeps a borrowed pointer to the saved six-byte ball location.
typedef char DogActorBallLocationCheck[offsetof(DogActor, ball_location) == 0x38 ? 1 : -1];
typedef char DogActorSavedPositionCheck[offsetof(DogActor, saved_x) == 0x3C ? 1 : -1];
typedef char HorseActorSavedPositionCheck[offsetof(HorseActor, saved_x) == 0x38 ? 1 : -1];

extern "C" bool IsDogActorCarryingBall(DogActor const * actor);
extern "C" void NotifyDogActorBallLanded(DogActor * actor, Location const & location);
extern "C" Box MakeAnimalActorBounds(i32 x, i32 y);


#endif // ANIMAL_ACTOR_HH
