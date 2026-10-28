#include "npc_collection.hh"
#include "game_state.hh"
#include "data_schedules.hh"
#include "npc_schedule.hh"

#include <algorithm>
#include <stdlib.h>

static inline ActorLocation InitialNpcLocation()
{
    return ActorLocation(Location(MAP_NONE, 0, 0), FACING_DOWN);
}

NpcCollection::NpcCollection()
    : unk_00_0(0), unk_00_6(0), library_second_floor_visit_count(0), library_second_floor_visited_today(false),
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

NpcCollection::NpcCollection(NpcCollection const & other)
    : unk_00_0(other.unk_00_0),
      unk_00_6(other.unk_00_6),
      library_second_floor_visit_count(other.library_second_floor_visit_count),
      library_second_floor_visited_today(other.library_second_floor_visited_today),
      unk_02_6(other.unk_02_6),
      has_child(other.has_child),
      unk_03_2(other.unk_03_2),
      child(other.child),
      wedding_date(other.wedding_date),
      locations(other.locations),
      lillia(other.lillia),
      rick(other.rick),
      popuri(other.popuri),
      barley(other.barley),
      may(other.may),
      saibara(other.saibara),
      gray(other.gray),
      duke(other.duke),
      manna(other.manna),
      basil(other.basil),
      anna(other.anna),
      mary(other.mary),
      thomas(other.thomas),
      harris(other.harris),
      ellen(other.ellen),
      stu(other.stu),
      jeff(other.jeff),
      sasha(other.sasha),
      karen(other.karen),
      doctor(other.doctor),
      elli(other.elli),
      carter(other.carter),
      cliff(other.cliff),
      doug(other.doug),
      ann(other.ann),
      kai(other.kai),
      gotz(other.gotz),
      zack(other.zack),
      won(other.won),
      gourmet(other.gourmet),
      harvest_goddess(other.harvest_goddess),
      kappa(other.kappa),
      van(other.van),
      lou(other.lou),
      staid(other.staid),
      nappy(other.nappy),
      bold(other.bold),
      chef(other.chef),
      aqua(other.aqua),
      hoggy(other.hoggy),
      timid(other.timid),
      work_targets(other.work_targets),
      days_since_pregnancy_event(other.days_since_pregnancy_event),
      unk_474(other.unk_474)
{
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

void NpcCollection::AddUnk00_0(u32 amount)
{
    unk_00_0 = std::min(unk_00_0 + amount, 63u);
}

void NpcCollection::AddUnk00_6(u32 amount)
{
    unk_00_6 = std::min(unk_00_6 + amount, 127u);
}

void NpcCollection::RecordLibrarySecondFloorVisit()
{
    if (!library_second_floor_visited_today) {
        library_second_floor_visit_count = std::min(library_second_floor_visit_count + 1, 255u);
        library_second_floor_visited_today = true;
    }
}

ActorLocation * NpcCollection::GetSouthTownNpcLocation1(u32 slot)
{
    switch (slot) {
    case 0:
    default: return &locations.south_town_1_0;
    case 1: return &locations.south_town_1_1;
    case 2: return &locations.south_town_1_2;
    }
}

ActorLocation * NpcCollection::GetSouthTownNpcLocation2(u32 slot)
{
    switch (slot) {
    case 0:
    default: return &locations.south_town_2_0;
    case 1: return &locations.south_town_2_1;
    case 2: return &locations.south_town_2_2;
    }
}

ActorLocation * NpcCollection::GetYodelRanchHouseNpcLocation()
{
    return &locations.yodel_ranch_house;
}

ActorLocation * NpcCollection::GetInnSecondFloorNpcLocation()
{
    return &locations.inn_second_floor;
}

static inline void ResetHarvestSpriteForDay(HarvestSprite & sprite, u32 slot)
{
    sprite.DayUpdate();
    ActorLocation location;
    InitializeHarvestSpriteHutLocation(&location, slot);
    sprite.SetLocation(location);
    // Preserve the native zero-initialized opaque argument to the state setter.
    u32 unk_data = 0;
    sprite.method_0809E7C8(&unk_data);
}

void NpcCollection::DayUpdate(GameStateClock const & clock, GameEventState const & events,
    Farmer const & farmer, Farm const & farm)
{
    library_second_floor_visited_today = false;
    u32 spouse = GetSpouseCharacterId();
    bool married = spouse != 0;
    lillia.DayUpdate(rand() % 100);
    rick.DayUpdate(rand() % 100);
    if (popuri.GetRivalEventCount() <= 4 || clock.calendar.date.season == SEASON_SUMMER)
        popuri.DayUpdate(married, rand() % 100);
    barley.DayUpdate(rand() % 100);
    may.DayUpdate(rand() % 100);
    saibara.DayUpdate();
    gray.DayUpdate(rand() % 100);
    duke.DayUpdate(rand() % 100);
    manna.DayUpdate(rand() % 100);
    basil.DayUpdate(rand() % 100);
    anna.DayUpdate(rand() % 100);
    mary.DayUpdate(married, rand() % 100);
    thomas.DayUpdate(rand() % 100);
    harris.DayUpdate(rand() % 100);
    ellen.DayUpdate(rand() % 100);
    stu.DayUpdate(rand() % 100);
    jeff.DayUpdate(rand() % 100);
    sasha.DayUpdate(rand() % 100);
    karen.DayUpdate(married, rand() % 100);
    doctor.DayUpdate(rand() % 100);
    elli.DayUpdate(married, rand() % 100);
    carter.DayUpdate(rand() % 100);
    cliff.DayUpdate(rand() % 100);
    doug.DayUpdate(rand() % 100);
    ann.DayUpdate(married, rand() % 100);
    if (clock.calendar.date.season == SEASON_SUMMER) {
        // Preserve the original second addition when Kai's friendship increases.
        u32 old_friendship = kai.GetFriendship();
        kai.DayUpdate(rand() % 100);
        if (kai.GetFriendship() > old_friendship)
            kai.AddFriendship(kai.GetFriendship() - old_friendship);
    }
    gotz.DayUpdate();
    zack.DayUpdate(rand() % 100);
    won.DayUpdate(rand() % 100);
    gourmet.DayUpdate(rand() % 100);
    harvest_goddess.DayUpdate(married, rand() % 100);
    kappa.DayUpdate(rand() % 100);
    if (events.van_introduction_event_state == 2)
        van.Npc::DayUpdate(rand() % 100);
    if (events.lou_or_ruby_introduction_event_state == 2)
        lou.DayUpdate(rand() % 100);
    if (has_child)
        child.DayUpdate();

    ResetHarvestSpriteForDay(staid, 0);
    ClearHarvestSpriteWorkTarget(work_targets.values, 0);
    ResetHarvestSpriteForDay(nappy, 1);
    ClearHarvestSpriteWorkTarget(work_targets.values, 1);
    ResetHarvestSpriteForDay(bold, 2);
    ClearHarvestSpriteWorkTarget(work_targets.values, 2);
    ResetHarvestSpriteForDay(chef, 3);
    ClearHarvestSpriteWorkTarget(work_targets.values, 3);
    ResetHarvestSpriteForDay(aqua, 4);
    ClearHarvestSpriteWorkTarget(work_targets.values, 4);
    ResetHarvestSpriteForDay(hoggy, 5);
    ClearHarvestSpriteWorkTarget(work_targets.values, 5);
    ResetHarvestSpriteForDay(timid, 6);
    ClearHarvestSpriteWorkTarget(work_targets.values, 6);

    if (events.popuri_pregnancy_event_state == 2 || events.ann_pregnancy_event_state == 2
        || events.elli_pregnancy_event_state == 2 || events.karen_pregnancy_event_state == 2
        || events.mary_pregnancy_event_state == 2 || events.harvest_goddess_pregnancy_event_state == 2) {
        // The native check is equality, not a clamp for larger saved values.
        if (days_since_pregnancy_event != 60)
            ++days_since_pregnancy_event;
    }

    if (popuri.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_POPURI)) {
        if (farm.coop.CountChickens() == 8) {
            u32 affection = 0;
            for (u32 slot = 0; slot < 8; ++slot) {
                Chicken const * chicken = farm.coop.GetChicken(slot);
                if (chicken != nullptr)
                    affection += chicken->GetAffection();
            }
            affection /= 8;
            while (popuri.method_0809E4BC() <= 4
                && affection >= gUnk_BacheloretteLoveThresholds00[popuri.method_0809E4BC()]) {
                popuri.AddLove(2500);
                popuri.method_0809E550();
            }
        }
    }
    if (mary.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_MARY)) {
        u32 value = library_second_floor_visit_count;
        while (mary.method_0809E4BC() <= 4
            && value >= gUnk_BacheloretteLoveThresholds01[mary.method_0809E4BC()]) {
            mary.AddLove(2500);
            mary.method_0809E550();
        }
    }
    if (karen.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_KAREN)) {
        u32 value = unk_00_6;
        while (karen.method_0809E4BC() <= 4
            && value >= gUnk_BacheloretteLoveThresholds02[karen.method_0809E4BC()]) {
            karen.AddLove(2500);
            karen.method_0809E550();
        }
    }
    if (elli.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_ELLI)) {
        u32 value = func_0800E970(farmer);
        while (elli.method_0809E4BC() <= 4
            && value >= gUnk_BacheloretteLoveThresholds03[elli.method_0809E4BC()]) {
            elli.AddLove(2500);
            elli.method_0809E550();
        }
    }
    if (ann.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_ANN)) {
        u32 value = unk_00_0;
        while (ann.method_0809E4BC() <= 4
            && value >= gUnk_BacheloretteLoveThresholds04[ann.method_0809E4BC()]) {
            ann.AddLove(2500);
            ann.method_0809E550();
        }
    }

    if (unk_02_6 <= 4) {
        u32 friendship = 0;
        u32 count = 0;
        for (u32 id = 0; id <= CHARACTER_TIMID; ++id) {
            switch (id) {
            case CHARACTER_CLIFF:
            case CHARACTER_KAI:
            case CHARACTER_GOURMET:
            case CHARACTER_VAN:
            case CHARACTER_LOU_OR_RUBY:
            case CHARACTER_CHILD:
                break;
            default:
                Npc * npc = GetNpc(id);
                if (npc != nullptr) {
                    friendship += npc->GetFriendship();
                    ++count;
                }
                break;
            }
        }
        u32 average = friendship / count;
        while (unk_02_6 <= 4 && average >= gUnk_BacheloretteLoveThresholds05[unk_02_6]) {
            if (!married || spouse == CHARACTER_POPURI) popuri.AddLove(2500);
            if (!married || spouse == CHARACTER_MARY) mary.AddLove(2500);
            if (!married || spouse == CHARACTER_KAREN) karen.AddLove(2500);
            if (!married || spouse == CHARACTER_ELLI) elli.AddLove(2500);
            if (!married || spouse == CHARACTER_ANN) ann.AddLove(2500);
            if (!married || spouse == CHARACTER_HARVEST_GODDESS) harvest_goddess.AddLove(2500);
            ++unk_02_6;
        }
    }
    ActorLocation location;
    InitializeSouthTownNpcLocation1(&location, 0);
    locations.south_town_1_0 = location;
    InitializeSouthTownNpcLocation1(&location, 1);
    locations.south_town_1_1 = location;
    InitializeSouthTownNpcLocation1(&location, 2);
    locations.south_town_1_2 = location;
    InitializeSouthTownNpcLocation2(&location, 0);
    locations.south_town_2_0 = location;
    InitializeSouthTownNpcLocation2(&location, 1);
    locations.south_town_2_1 = location;
    InitializeSouthTownNpcLocation2(&location, 2);
    locations.south_town_2_2 = location;
    InitializeYodelRanchHouseNpcLocation(&location);
    locations.yodel_ranch_house = location;
    InitializeInnSecondFloorNpcLocation(&location);
    locations.inn_second_floor = location;
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

Child const * NpcCollection::GetChild() const
{
    return has_child ? &child : nullptr;
}
