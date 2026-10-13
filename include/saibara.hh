#ifndef SAIBARA_HH
#define SAIBARA_HH

#include "npc.hh"

// Character 6 resolves to NPC-group +0xD8, save-image +0x1DAC.
struct Saibara : public Npc
{
    Saibara(ActorLocation const & location);
    u32 GetOrder() const;
    bool IsOrderComplete() const;
    bool HasCollectedAllMystrileTools() const;
    void CollectOrder();
    void PlaceOrder(u32 order, u32 days);
    void DayUpdate();

    /* +14 */ u32 order : 6;
    /* +14 */ u16 days_remaining : 3;
    /* +15 */ u16 collected_mystrile_sickle : 1;
    /* +15 */ u16 collected_mystrile_hoe : 1;
    /* +15 */ u16 collected_mystrile_axe : 1;
    /* +15 */ u16 collected_mystrile_hammer : 1;
    /* +15 */ u16 collected_mystrile_watering_can : 1;
    /* +15 */ u16 collected_mystrile_fishing_rod : 1;
};

typedef char SaibaraSizeCheck[sizeof(Saibara) == 0x18 ? 1 : -1];

#endif // SAIBARA_HH
