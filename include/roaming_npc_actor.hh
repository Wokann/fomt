#ifndef ROAMING_NPC_ACTOR_HH
#define ROAMING_NPC_ACTOR_HH

#include "entity_actor.hh"

#pragma interface "roaming_npc_actor.hh"
struct RoamingNpcActor : AActorEntity
{
    RoamingNpcActor(GameObject * game_object, ActorLocation * saved_location,
        u32 animation, u32 unk_3C);
    virtual ~RoamingNpcActor();

    virtual Box GetBox() const;
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void Update(EntityUpdateContext const & context);
    virtual u32 vfunc_34();
    /* vt+3C */ virtual void ResetLocation() = 0;
    /* vt+40 */ virtual u32 SelectNextBehavior() = 0;

    void SetRoamingSpeed(i32 speed_q16);
    bool IsVisualAnimationComplete() const;
    void ApplyRoamingMovement(ActorMovementBounds * bounds);
    void SetAvoidanceBox(Box const & box);
    void ClearAvoidanceBox();

    /* +30 */ ActorLocation * saved_location;
    /* +34 */ Box avoidance_box;
    /* +3C */ u16 unk_3C;
    /* +3E */ u16 behavior_countdown;
    /* +40 */ bool unk_40;
};


struct SouthTownRoamingNpc1 : RoamingNpcActor
{
    SouthTownRoamingNpc1(GameObject * game_object, ActorLocation * saved_location, u32 index);
    virtual EntityVisualController * CreateVisualController();
    virtual void ResetLocation();
    virtual u32 SelectNextBehavior();

    u32 GetBehaviorAnimation(u32 behavior) const;
    i32 GetBehaviorSpeed(u32 behavior) const;

    /* +44 */ u8 index : 2;
};


struct SouthTownRoamingNpc2 : RoamingNpcActor
{
    SouthTownRoamingNpc2(GameObject * game_object, ActorLocation * saved_location, u32 index);
    virtual EntityVisualController * CreateVisualController();
    virtual void ResetLocation();
    virtual u32 SelectNextBehavior();

    u32 GetBehaviorAnimation(u32 behavior) const;
    i32 GetBehaviorSpeed(u32 behavior) const;

    /* +44 */ u8 index : 2;
};


struct YodelRanchHouseRoamingNpc : RoamingNpcActor
{
    YodelRanchHouseRoamingNpc(GameObject * game_object, ActorLocation * saved_location);
    virtual EntityVisualController * CreateVisualController();
    virtual void ResetLocation();
    virtual u32 SelectNextBehavior();

    u32 GetBehaviorAnimation(u32 behavior) const;
    i32 GetBehaviorSpeed(u32 behavior) const;
};

struct InnSecondFloorRoamingNpc : RoamingNpcActor
{
    InnSecondFloorRoamingNpc(GameObject * game_object, ActorLocation * saved_location);
    virtual EntityVisualController * CreateVisualController();
    virtual void ResetLocation();
    virtual u32 SelectNextBehavior();

    u32 GetBehaviorAnimation(u32 behavior) const;
    i32 GetBehaviorSpeed(u32 behavior) const;
};


EXTERN_C

// The retained native factories allocate the original 0x48/0x44-byte objects.
// Their allocation constants must change if the corresponding type grows.
RoamingNpcActor * CreateSouthTownRoamingNpc1(GameObject * game_object,
    ActorLocation * saved_location, u32 index);
RoamingNpcActor * CreateSouthTownRoamingNpc2(GameObject * game_object,
    ActorLocation * saved_location, u32 index);
RoamingNpcActor * CreateYodelRanchHouseRoamingNpc(GameObject * game_object,
    ActorLocation * saved_location);
RoamingNpcActor * CreateInnSecondFloorRoamingNpc(GameObject * game_object,
    ActorLocation * saved_location);

EXTERN_C_END

extern "C" ActorBehaviorTiming const gUnk_080F1538[];
extern "C" u16 const gUnk_080F1560[];
extern "C" ActorBehaviorTiming const gUnk_080F156C[];
extern "C" u16 const gUnk_080F15A4[];
extern "C" ActorBehaviorTiming const gUnk_080F15B4[];
extern "C" u16 const gUnk_080F161C[];
extern "C" ActorBehaviorTiming const gUnk_080F1638[];
extern "C" u16 const gUnk_080F1644[];


extern "C" char const gCppRuntimeError_EntityUiSecond[];

#endif // ROAMING_NPC_ACTOR_HH
