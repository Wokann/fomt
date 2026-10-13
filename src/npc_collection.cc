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

Npc * NpcCollection::GetNpc(u32 character_id)
{
    switch (character_id) {
    default: return nullptr;
    case CHARACTER_CHILD: return GetChild();
    case CHARACTER_LILLIA: return &lillia;
    case CHARACTER_RICK: return &rick;
    case CHARACTER_POPURI: return &popuri;
    case CHARACTER_BARLEY: return &barley;
    case CHARACTER_MAY: return &may;
    case CHARACTER_SAIBARA: return &saibara;
    case CHARACTER_GRAY: return &gray;
    case CHARACTER_DUKE: return &duke;
    case CHARACTER_MANNA: return &manna;
    case CHARACTER_BASIL: return &basil;
    case CHARACTER_ANNA: return &anna;
    case CHARACTER_MARY: return &mary;
    case CHARACTER_THOMAS: return &thomas;
    case CHARACTER_HARRIS: return &harris;
    case CHARACTER_ELLEN: return &ellen;
    case CHARACTER_STU: return &stu;
    case CHARACTER_JEFF: return &jeff;
    case CHARACTER_SASHA: return &sasha;
    case CHARACTER_KAREN: return &karen;
    case CHARACTER_DOCTOR: return &doctor;
    case CHARACTER_ELLI: return &elli;
    case CHARACTER_CARTER: return &carter;
    case CHARACTER_CLIFF: return &cliff;
    case CHARACTER_DOUG: return &doug;
    case CHARACTER_ANN: return &ann;
    case CHARACTER_KAI: return &kai;
    case CHARACTER_GOTZ: return &gotz;
    case CHARACTER_ZACK: return &zack;
    case CHARACTER_WON: return &won;
    case CHARACTER_GOURMET: return &gourmet;
    case CHARACTER_HARVEST_GODDESS: return &harvest_goddess;
    case CHARACTER_KAPPA: return &kappa;
    case CHARACTER_VAN: return &van;
    case CHARACTER_LOU_OR_RUBY: return &lou;
    case CHARACTER_STAID: return &staid;
    case CHARACTER_NAPPY: return &nappy;
    case CHARACTER_BOLD: return &bold;
    case CHARACTER_CHEF: return &chef;
    case CHARACTER_AQUA: return &aqua;
    case CHARACTER_HOGGY: return &hoggy;
    case CHARACTER_TIMID: return &timid;
    }
}

Bachelorette * NpcCollection::GetBachelorette(u32 character_id)
{
    switch (character_id) {
    default: return nullptr;
    case CHARACTER_POPURI: return &popuri;
    case CHARACTER_MARY: return &mary;
    case CHARACTER_KAREN: return &karen;
    case CHARACTER_ELLI: return &elli;
    case CHARACTER_ANN: return &ann;
    case CHARACTER_HARVEST_GODDESS: return &harvest_goddess;
    }
}

HarvestSprite * NpcCollection::GetHarvestSpriteByCharacterId(u32 character_id)
{
    switch (character_id) {
    default: return nullptr;
    case CHARACTER_STAID: return &staid;
    case CHARACTER_NAPPY: return &nappy;
    case CHARACTER_BOLD: return &bold;
    case CHARACTER_CHEF: return &chef;
    case CHARACTER_AQUA: return &aqua;
    case CHARACTER_HOGGY: return &hoggy;
    case CHARACTER_TIMID: return &timid;
    }
}

HarvestSprite * NpcCollection::GetHarvestSpriteByIndex(u32 index)
{
    switch (index) {
    default: return nullptr;
    case 0: return &staid;
    case 1: return &nappy;
    case 2: return &bold;
    case 3: return &chef;
    case 4: return &aqua;
    case 5: return &hoggy;
    case 6: return &timid;
    }
}

#if defined(REGION_JP)
HarvestSprite const * NpcCollection::GetHarvestSpriteByIndex(u32 index) const
{
    switch (index) {
    default: return nullptr;
    case 0: return &staid;
    case 1: return &nappy;
    case 2: return &bold;
    case 3: return &chef;
    case 4: return &aqua;
    case 5: return &hoggy;
    case 6: return &timid;
    }
}
#endif

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
