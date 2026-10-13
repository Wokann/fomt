#ifndef GOTZ_HH
#define GOTZ_HH

#include "npc.hh"

// Character 27 resolves to NPC-group +0x290, save-image +0x1F64.
struct Gotz : public Npc
{
    Gotz(ActorLocation const & location);
    u32 GetConstruction() const;
    bool IsConstructionComplete() const;
    bool IsConstructionOrderedToday() const;
    void OrderConstruction(u32 type);
    void FinishConstruction();
    void DayUpdate();
    void UpdateConstructionWorksite();

    /* +14 */ u32 construction : 4;
    /* +14 */ u8 days_remaining : 3;
    /* +14 */ bool ordered_today : 1;
    /* +15 */ bool at_construction_worksite : 1;
};

typedef char GotzSizeCheck[sizeof(Gotz) == 0x18 ? 1 : -1];

#endif // GOTZ_HH
