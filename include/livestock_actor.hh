#ifndef LIVESTOCK_ACTOR_HH
#define LIVESTOCK_ACTOR_HH

#include "entity_actor.hh"

#pragma interface "livestock_actor.hh"

struct Livestock;

// Verified common virtual interface/payload of live chickens, cows and sheep.
// This is a partial native prefix, never an allocatable/full-size model.
struct LivestockActor : AActorEntity {
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    /* vt+5C */ virtual bool IsSick() const = 0;
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    // Also clears unhappiness and its duration, but only when that flag is set.
    /* vt+7C */ virtual void CureSickness() = 0;

    u32 unk_30;
    Livestock * livestock;
protected:
    LivestockActor();
};

struct ChickenActor : LivestockActor {
    virtual bool IsSick() const;
    virtual void CureSickness();
private:
    ChickenActor();
};

struct CowActor : LivestockActor {
    virtual bool IsSick() const;
    virtual void CureSickness();
private:
    CowActor();
};

struct SheepActor : LivestockActor {
    virtual bool IsSick() const;
    virtual void CureSickness();
private:
    SheepActor();
};

typedef char LivestockActorBaseSizeCheck[sizeof(AActorEntity) == 0x30 ? 1 : -1];
typedef char LivestockActorModelOffsetCheck[offsetof(LivestockActor, livestock) == 0x34 ? 1 : -1];

#endif // LIVESTOCK_ACTOR_HH
