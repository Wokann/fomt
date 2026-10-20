#ifndef NPC_COLLECTION_HH
#define NPC_COLLECTION_HH

#include "bachelorette.hh"
#include "child.hh"
#include "gotz.hh"
#include "harvest_sprite.hh"
#include "npc_locations.hh"
#include "saibara.hh"
#include "time_of_day.hh"
#include "van.hh"

// Eight saved preset positions, distinct from each character's own location.
// Their character associations are not yet established.
struct NpcCollectionLocations
{
    NpcCollectionLocations();

    /* +00 */ ActorLocation south_town_1_0;
    /* +08 */ ActorLocation south_town_1_1;
    /* +10 */ ActorLocation south_town_1_2;
    /* +18 */ ActorLocation south_town_2_0;
    /* +20 */ ActorLocation south_town_2_1;
    /* +28 */ ActorLocation south_town_2_2;
    /* +30 */ ActorLocation yodel_ranch_house;
    /* +38 */ ActorLocation inn_second_floor;
};

inline NpcCollectionLocations::NpcCollectionLocations()
{
    InitializeSouthTownNpcLocation1(&south_town_1_0, 0);
    InitializeSouthTownNpcLocation1(&south_town_1_1, 1);
    InitializeSouthTownNpcLocation1(&south_town_1_2, 2);
    InitializeSouthTownNpcLocation2(&south_town_2_0, 0);
    InitializeSouthTownNpcLocation2(&south_town_2_1, 1);
    InitializeSouthTownNpcLocation2(&south_town_2_2, 2);
    InitializeYodelRanchHouseNpcLocation(&yodel_ranch_house);
    InitializeInnSecondFloorNpcLocation(&inn_second_floor);
}

// The wedding-date readers use the same year encoding as GameCalendar and
// the zero-based packed date. The native setter copies one aligned word;
// the final two bytes are padding, not a verified clock or another field.
struct ALIGN(4) WeddingDate
{
    u8 encoded_year;
    GameDate date;

    WeddingDate() : encoded_year(0), date(SEASON_SPRING, 0) {}

    u32 GetYear() const { return EncodedGameYear(encoded_year).GetYear(); }
};

typedef char WeddingDateSizeCheck[sizeof(WeddingDate) == 4 ? 1 : -1];
typedef char WeddingDateDateCheck[offsetof(WeddingDate, date) == 1 ? 1 : -1];

// Saved at GameStateSaveImage +0x1CD4. The character-ID resolver independently
// verifies these named members; construction order follows physical storage.
struct GameStateSaveImage;
struct GameStateClock;
struct GameEventState;
struct Farmer;
struct Farm;

struct NpcCollection
{
    NpcCollection();

    // IDs are the canonical Mary character IDs. Unsupported IDs return null;
    // the child is available only when has_child is set. Sprite slots are 0-6.
    Npc * GetNpc(u32 character_id);
    Bachelorette * GetBachelorette(u32 character_id);
    HarvestSprite * GetHarvestSpriteByCharacterId(u32 character_id);
    HarvestSprite * GetHarvestSpriteByIndex(u32 index);
#if defined(REGION_JP)
    // JP emits a separate read-only slot lookup used by minigame queries.
    HarvestSprite const * GetHarvestSpriteByIndex(u32 index) const;
#endif

    // Preserve the native candidate priority and the two distinct event counts.
    // A zero result means no matching candidate, not CHARACTER_PLAYER.
    u32 GetPartnerCharacterId() const;
    u32 GetSpouseCharacterId() const;
    bool IsMarried() const;

    Child * GetChild();

    // Preserve native unsigned addition and the individual field ceilings.
    // The counter meanings are not established; do not infer them from size.
    void AddUnk00_0(u32 amount);
    void AddUnk00_6(u32 amount);
    // Map-entry counter, once per DayUpdate reset; it feeds Mary's visit bonus.
    void RecordLibrarySecondFloorVisit();

    // South-town slots 1 and 2 select their entries; all other values use 0.
    ActorLocation * GetSouthTownNpcLocation1(u32 slot);
    ActorLocation * GetSouthTownNpcLocation2(u32 slot);
    ActorLocation * GetYodelRanchHouseNpcLocation();
    ActorLocation * GetInnSecondFloorNpcLocation();

    void InitializeSchedules(GameStateSaveImage const & state);

    void DayUpdate(GameStateClock const & clock, GameEventState const & events,
        Farmer const & farmer, Farm const & farm);

    void SetWeddingDate(WeddingDate const & date);
    WeddingDate const & GetWeddingDate() const;

    /* +000 */ u32 unk_00_0 : 6;
    /* +000 */ u32 unk_00_6 : 7;
    /* +001 */ u32 library_second_floor_visit_count : 8;
    /* +002 */ bool library_second_floor_visited_today : 1;
    /* +002 */ u32 unk_02_6 : 3;
    /* +003 */ bool has_child : 1;
    /* +003 */ u32 unk_03_2 : 3;
    /* +003 */ u32 : 3;
    /* +004 */ Child child;
    /* +02C */ WeddingDate wedding_date;
    /* +030 */ NpcCollectionLocations locations;
    /* +070 */ Npc lillia;
    /* +084 */ Npc rick;
    /* +098 */ Bachelorette popuri;
    /* +0B0 */ Npc barley;
    /* +0C4 */ Npc may;
    /* +0D8 */ Saibara saibara;
    /* +0F0 */ Npc gray;
    /* +104 */ Npc duke;
    /* +118 */ Npc manna;
    /* +12C */ Npc basil;
    /* +140 */ Npc anna;
    /* +154 */ Bachelorette mary;
    /* +16C */ Npc thomas;
    /* +180 */ Npc harris;
    /* +194 */ Npc ellen;
    /* +1A8 */ Npc stu;
    /* +1BC */ Npc jeff;
    /* +1D0 */ Npc sasha;
    /* +1E4 */ Bachelorette karen;
    /* +1FC */ Npc doctor;
    /* +210 */ Bachelorette elli;
    /* +228 */ Npc carter;
    /* +23C */ Npc cliff;
    /* +250 */ Npc doug;
    /* +264 */ Bachelorette ann;
    /* +27C */ Npc kai;
    /* +290 */ Gotz gotz;
    /* +2A8 */ Npc zack;
    /* +2BC */ Npc won;
    /* +2D0 */ Npc gourmet;
    /* +2E4 */ Bachelorette harvest_goddess;
    /* +2FC */ Npc kappa;
    /* +310 */ Van van;
    /* +328 */ Npc lou;
    /* +33C */ HarvestSprite staid;
    /* +360 */ HarvestSprite nappy;
    /* +384 */ HarvestSprite bold;
    /* +3A8 */ HarvestSprite chef;
    /* +3CC */ HarvestSprite aqua;
    /* +3F0 */ HarvestSprite hoggy;
    /* +414 */ HarvestSprite timid;
    /* +438 */ HarvestSpriteWorkTarget work_targets[7];
    /* +470 */ u32 days_since_pregnancy_event;
    /* +474 */ u8 unk_474;
};

typedef char NpcCollectionLocationsSizeCheck[sizeof(NpcCollectionLocations) == 0x40 ? 1 : -1];
typedef char NpcCollectionSizeCheck[sizeof(NpcCollection) == 0x478 ? 1 : -1];
typedef char NpcCollectionChildCheck[offsetof(NpcCollection, child) == 4 ? 1 : -1];
typedef char NpcCollectionWeddingDateCheck[offsetof(NpcCollection, wedding_date) == 0x2C ? 1 : -1];
typedef char NpcCollectionLocationsCheck[offsetof(NpcCollection, locations) == 0x30 ? 1 : -1];
typedef char NpcCollectionLilliaCheck[offsetof(NpcCollection, lillia) == 0x70 ? 1 : -1];
typedef char NpcCollectionSaibaraCheck[offsetof(NpcCollection, saibara) == 0xD8 ? 1 : -1];
typedef char NpcCollectionGotzCheck[offsetof(NpcCollection, gotz) == 0x290 ? 1 : -1];
typedef char NpcCollectionVanCheck[offsetof(NpcCollection, van) == 0x310 ? 1 : -1];
typedef char NpcCollectionSpritesCheck[offsetof(NpcCollection, staid) == 0x33C ? 1 : -1];
typedef char NpcCollectionWorkTargetsCheck[offsetof(NpcCollection, work_targets) == 0x438 ? 1 : -1];
typedef char NpcCollectionPregnancyCounterCheck[offsetof(NpcCollection, days_since_pregnancy_event) == 0x470 ? 1 : -1];
typedef char NpcCollectionLastByteCheck[offsetof(NpcCollection, unk_474) == 0x474 ? 1 : -1];

// Native character-name resolver; its dispatch body remains in assembly.
extern "C" char const * func_0809FE3C(NpcCollection * collection, u32 character_id);

// Existing native child construction; a saved calendar date is passed by reference.
extern "C" void func_080A05E8(NpcCollection & npcs, GameDate const & date);

#endif // NPC_COLLECTION_HH
