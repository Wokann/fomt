#include "npc_collection.hh"
#include "data_schedules.hh"
#include "npc_schedule_data.hh"

static inline ActorLocation InitialNpcLocation()
{
    return ActorLocation(Location(MAP_NONE, 0, 0), FACING_DOWN);
}

NpcCollection::NpcCollection()
    : unk_00_0(0), unk_00_6(0), unk_01_5(0), unk_02_5(false),
      unk_02_6(0), has_child(false), unk_03_2(0),
      wedding_date(),
      lillia(InitialNpcLocation()),
      rick(InitialNpcLocation()),
      popuri(InitialNpcLocation()),
      barley(InitialNpcLocation()),
      may(InitialNpcLocation()),
      saibara(InitialNpcLocation()),
      gray(InitialNpcLocation()),
      duke(InitialNpcLocation()),
      manna(InitialNpcLocation()),
      basil(InitialNpcLocation()),
      anna(InitialNpcLocation()),
      mary(InitialNpcLocation()),
      thomas(InitialNpcLocation()),
      harris(InitialNpcLocation()),
      ellen(InitialNpcLocation()),
      stu(InitialNpcLocation()),
      jeff(InitialNpcLocation()),
      sasha(InitialNpcLocation()),
      karen(InitialNpcLocation()),
      doctor(InitialNpcLocation()),
      elli(InitialNpcLocation()),
      carter(InitialNpcLocation()),
      cliff(InitialNpcLocation()),
      doug(InitialNpcLocation()),
      ann(InitialNpcLocation()),
      kai(InitialNpcLocation()),
      gotz(InitialNpcLocation()),
      zack(InitialNpcLocation()),
      won(InitialNpcLocation()),
      gourmet(InitialNpcLocation()),
      harvest_goddess(InitialNpcLocation()),
      kappa(InitialNpcLocation()),
      van(InitialNpcLocation()),
      lou(InitialNpcLocation()),
      staid(InitialNpcLocation()),
      nappy(InitialNpcLocation()),
      bold(InitialNpcLocation()),
      chef(InitialNpcLocation()),
      aqua(InitialNpcLocation()),
      hoggy(InitialNpcLocation()),
      timid(InitialNpcLocation())
{
    days_since_pregnancy_event = 0;
    unk_474 = 0;
    // The remaining state bits, child walking bit and object padding are not cleared.
}

u32 NpcCollection::GetPartnerCharacterId() const
{
    if (popuri.GetPlayerEventCount() > 4) return CHARACTER_POPURI;
    if (mary.GetPlayerEventCount() > 4) return CHARACTER_MARY;
    if (karen.GetPlayerEventCount() > 4) return CHARACTER_KAREN;
    if (elli.GetPlayerEventCount() > 4) return CHARACTER_ELLI;
    if (ann.GetPlayerEventCount() > 4) return CHARACTER_ANN;
    if (harvest_goddess.GetPlayerEventCount() > 4) return CHARACTER_HARVEST_GODDESS;
    return 0;
}

u32 NpcCollection::GetSpouseCharacterId() const
{
    if (popuri.GetPlayerEventCount() > 5) return CHARACTER_POPURI;
    if (mary.GetPlayerEventCount() > 5) return CHARACTER_MARY;
    if (karen.GetPlayerEventCount() > 5) return CHARACTER_KAREN;
    if (elli.GetPlayerEventCount() > 5) return CHARACTER_ELLI;
    if (ann.GetPlayerEventCount() > 5) return CHARACTER_ANN;
    if (harvest_goddess.GetPlayerEventCount() > 5) return CHARACTER_HARVEST_GODDESS;
    return 0;
}

bool NpcCollection::IsMarried() const
{
    return GetSpouseCharacterId() != 0;
}

void NpcCollection::SetWeddingDate(WeddingDate const & date)
{
    wedding_date = date;
}

WeddingDate const & NpcCollection::GetWeddingDate() const
{
    return wedding_date;
}

// Visit the original 31 scheduled NPCs in order. Other collection members
// are intentionally absent; the child joins only when has_child is set.
void NpcCollection::InitializeSchedules(GameStateSaveImage const & state)
{
#if defined(REGION_JP)
    lillia.InitializeSchedule(gUnk_080F2068, &state);
#else
    lillia.InitializeSchedule(gUnk_080F280C, &state);
#endif
    rick.InitializeSchedule(ScheduleInfo_Unk_080F1A80, &state);
    popuri.InitializeSchedule(gUnk_080F1FC0, &state);
    barley.InitializeSchedule(gUnk_080F8678.descriptor, &state);
    may.InitializeSchedule(gUnk_080F81BC.descriptor, &state);
    saibara.InitializeSchedule(gUnk_080F77FC.descriptor, &state);
    gray.InitializeSchedule(gUnk_080F7294.descriptor, &state);
    duke.InitializeSchedule(gUnk_080F6370.descriptor, &state);
    manna.InitializeSchedule(gUnk_080F66C4.descriptor, &state);
    basil.InitializeSchedule(gUnk_080F49C0.descriptor, &state);
    anna.InitializeSchedule(gUnk_080F5540.descriptor, &state);
    mary.InitializeSchedule(gUnk_080F4D74.descriptor, &state);
    thomas.InitializeSchedule(gUnk_080F59CC.descriptor, &state);
    harris.InitializeSchedule(gUnk_080F6B4C.descriptor, &state);
    ellen.InitializeSchedule(gUnk_080F33B8.descriptor, &state);
    stu.InitializeSchedule(gUnk_080F61FC.descriptor, &state);
    jeff.InitializeSchedule(gUnk_080F3408.descriptor, &state);
    sasha.InitializeSchedule(gUnk_080F3FD8.descriptor, &state);
    karen.InitializeSchedule(gUnk_080F35E4.descriptor, &state);
#if defined(REGION_JP)
    doctor.InitializeSchedule(ScheduleInfo_Unk_080F286C, &state);
#else
    doctor.InitializeSchedule(gUnk_080F3010, &state);
#endif
    elli.InitializeSchedule(gUnk_080F5D94.descriptor, &state);
    carter.InitializeSchedule(gUnk_080F6DE8.descriptor, &state);
#if defined(REGION_JP)
    cliff.InitializeSchedule(ScheduleInfo_Unk_080F2354, &state);
#else
    cliff.InitializeSchedule(gUnk_080F2AF8, &state);
#endif
    doug.InitializeSchedule(gUnk_080F42F0.descriptor, &state);
    ann.InitializeSchedule(gUnk_080F43DC.descriptor, &state);
    kai.InitializeSchedule(gUnk_080F6FF8.descriptor, &state);
    gotz.InitializeSchedule(gUnk_080F7B40.descriptor, &state);
#if defined(REGION_JP)
    zack.InitializeSchedule(ScheduleInfo_Unk_080F261C, &state);
#else
    zack.InitializeSchedule(gUnk_080F2DC0, &state);
#endif
    won.InitializeSchedule(gUnk_080F597C.descriptor, &state);
    van.InitializeSchedule(gUnk_080F6B10.descriptor, &state);
    lou.InitializeSchedule(gUnk_080F4974.descriptor, &state);
    Child * current_child = GetChild();
    if (current_child != nullptr) {
#if defined(REGION_JP)
        current_child->InitializeSchedule(gUnk_080F221C, &state);
#else
        current_child->InitializeSchedule(gUnk_080F29C0, &state);
#endif
    }
}

Child * NpcCollection::GetChild()
{
    return has_child ? &child : nullptr;
}
