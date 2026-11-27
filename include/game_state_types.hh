#ifndef GAME_STATE_TYPES_HH
#define GAME_STATE_TYPES_HH

#include "prelude.h"
#include "world_ambient_sprites.hh"
#include "farm.hh"
#include "farmer_types.hh"
#include "dog.hh"
#include "more_items.hh"
#include "time_of_day_types.hh"
#include "money_account_types.hh"
#include "mine_floor.hh"
#include "cursed_tool.hh"
#include "cooking_recipe_types.hh"
#include "event_state.hh"
#include "npc_collection.hh"
#include "field_item_data.hh"
#include "actor_runtime_data.hh"
#include "map_patch_flags.hh"
#include "fishing_results_data.hh"
#include "animal_festival_ranking.hh"
#include "utility/fixed_str.hh"
#include "utility/container_algorithms.hh"

struct SramAccess;

// The save image stores these options at +0x2210. The menu keeps two
// four-byte copies at +0x198/+0x19C, one for each SRAM slot. Only the low
// four bits have verified meanings; initializing them preserves all others.
struct GameDisplayOptions {
    GameDisplayOptions();

    u32 control_scheme : 1; // 0: D-pad walks / R runs; 1: D-pad runs / R walks.
    bool show_clock : 1;
    bool show_portrait : 1;
    bool show_nameplate : 1;
    u32 unk_4 : 28;
};


// Saved at +0x2C74. IDs are raw words: the original setter does not validate
// them. The countdown starts at two, but delivery also depends on the game's
// update and event-priority paths, not an unconditional two-day guarantee.
struct TVShoppingOrderState {
    TVShoppingOrderState();

    u32 selection;
    u32 pending_item;
    u8 countdown;
};


// Saved at +0x21CC. The dispatcher keeps the received and local milestone
// bitmaps separate; initialization and copying confirm their actual sizes.
// The first two words are passed together to the link transfer. On receipt
// the scene writes the returned record value into the second saved word.
struct GameStateLinkRecord {
    GameStateLinkRecord(u32 value) : unk_00(value), unk_04(0)
    {
        fill_n_inl(received_milestones, 8, 0);
        fill_n_inl(local_milestones, 4, 0);
    }

    void SetReceivedRecordValue(u32 value) { unk_04 = value; }
    void SetReceivedMilestones(u8 const * source)
    {
        copy_n_ptrs(source, ARRAY_COUNT(received_milestones), received_milestones);
    }

    u32 unk_00;
    u32 unk_04;
    u8 received_milestones[8];
    u8 local_milestones[4];
    FixedStr<14> name_14; // Received name 0: farm (<cf>, PLACE2).
    FixedStr<14> name_24; // Received name 1: player (<cp>, PASSERBY1).
    FixedStr<14> name_34; // Received name 2: <cs>, PASSERBY2.
};



// Saved entrants occupy twelve name IDs and four eight-byte race records.
// The two bytes after the odds are native word-alignment padding.
struct HorseRaceSavedEntry {
    u8 adequacy;
    u8 affection;
    u8 contestant_name_id;
    i16 odds;
} ALIGN(4);

// Only the low 24 bits of the final word are initialized. Entrants and the
// high byte retain their native uninitialized storage until preparation.
struct HorseRaceSaveData {
    // Three rounds of four names; entries below hold only the current round.
    u8 contestant_name_ids[12];
    HorseRaceSavedEntry entries[4];
    u32 round_index : 2; // 0..2 while racing, 3 when all rounds are over.
    u32 medals : 17;
    bool power_berry_redeemed : 1;
    bool jewel_of_truth_redeemed : 1;
    u8 player_horse_entered : 1;
    bool race_cancelled : 1; // The scene resumes the event with FESTIVAL_HORSE_RACE_INTERFACE_CANCELLED.
    bool player_horse_won : 1;
    u32 unk_2C_24 : 8;
    HorseRaceSaveData() : round_index(3), medals(0),
        power_berry_redeemed(false), jewel_of_truth_redeemed(false), player_horse_entered(false),
        race_cancelled(false), player_horse_won(false) {}
};

// The initializer, copy constructor and save-summary reader agree on these
// member offsets. Unknown fields keep offset names. Initialization is recovered;
// native copying remains unresolved; destruction uses real member lifetimes.
struct GameStateSaveImage {
    GameStateSaveImage(char const *, char const *, GameDate, char const *);
    // The native constructor initializes members, then reads the SRAM record.
    // Status is cleared first; failures combine the stage and SRAM flags.
    GameStateSaveImage(SramAccess & access, u32 offset, u32 & status);
    GameStateSaveImage(GameStateSaveImage const & other);
    ~GameStateSaveImage();

    // Update tomorrow's weather and the farm/NPC/order state for the current
    // calendar day. This does not itself advance the saved calendar date.
    void DayUpdate();

    bool GetFlag0() const;
    bool GetFlag1() const;
    bool GetFlag2() const;
    bool GetFlag3() const;
    bool AllAnimalsHaveHighAffection() const;
    bool GetFlag4() const;
    u32 GetUnknown13() const;
    u32 GetUnknown18() const;
    u32 GetUnknown25() const;
    void SetFlag0();
    void SetFlag1();
    void SetFlag2();
    void SetFlag3();
    // Consume one shipping total and any pending one-settlement bonus.
    bool CollectShippingRevenue();
    void SetFlag4();
    // Native updates bound the argument at 99 before comparing, then store
    // only the field's original five, seven or six bits. Do not widen them.
    bool UpdateUnknown13(u32 value);
    bool UpdateUnknown18(u32 value);
    bool UpdateUnknown25(u32 value);

    // The three cottage bits are script variables 17 through 19. Offering a
    // small fish in fishing area 4 sets bit 4, which gates the first squid catch.
    /* bit 00 */ bool owns_mountain_cottage : 1;
    /* bit 01 */ bool owns_town_cottage : 1;
    /* bit 02 */ bool owns_seaside_cottage : 1;
    /* bit 03 */ bool obtained_mythic_tool : 1;
    /* bit 04 */ bool offered_small_fish_at_beach : 1;
    /* bit 05 */ u32 unk_5 : 8;
    /* bit 13 */ u32 sprite_harvesting_record : 5;
    /* bit 18 */ u16 sprite_animal_care_record : 7;
    /* bit 25 */ u8 sprite_watering_record : 6;
    /* bit 31 */ bool unk_31 : 1;
    /* bit 32 */ bool unk_32 : 1;
    // +0x05..+0x07 are natural word-alignment padding, not saved array
    // elements. Both native initialization and field copying leave them alone.
    /* 0x0008 */ GameStateClock clock;
    /* 0x0014 */ Farm farm;
    /* 0x1AA8 */ MoneyAccount money_account;
    /* 0x1BD8 */ Farmer farmer;
    /* 0x1C70 */ Dog dog;
    /* 0x1CA0 */ MoreItems more_items;
    // Dropping ITEM_ARTICLE_BALL saves an AEntity's six-byte Location here;
    // mine generation and the town map read it when the ball is not carried
    // or shelved. The following two bytes are natural alignment padding.
    /* 0x1CCC */ Location ball_location;
    /* 0x1CD4 */ NpcCollection npcs;
    /* 0x214C */ GameEventState event_state;
    /* 0x21CC */ GameStateLinkRecord link_record;
    /* 0x2210 */ GameDisplayOptions display_options;
    /* 0x2214 */ CookingRecipeInventory cooking_recipes;
    /* 0x2C1C */ HorseRaceSaveData horse_race;
    /* 0x2C4C */ AnimalFestivalOpponents animal_festival_opponents;
    /* 0x2C74 */ TVShoppingOrderState tv_shopping;
    /* 0x2C80 */ FishingRecords fishing_records;
    /* 0x2E58 */ MineFloorState mine_floor;
    /* 0x3480 */ CursedToolState cursed_tools;
    /* 0x3494 */ GameStateActorRecord actor_records[3];
    // Event-control mode also gates player stamina/fatigue action paths.
    /* 0x34C4 */ u8 scripted_npc_control;
    /* 0x34C5 */ u8 shooting_star_shipping_bonus;
    // The native initializer places this member at the next word boundary.
    // The two bytes after the preceding flags are padding, not array data.
    /* 0x34C8 */ FieldItemState field_items ALIGN(4);
    /* 0x34D8 */ MapPatchFlags map_patch_flags;
    /* 0x34DC */ Unk_Actor_0809BFE8 wild_dog;
};


// The upper word records the failed write stage; these are stage IDs, not
// independent bits. The lower word carries the SRAM service's error flags.
enum GameStateSaveWriteErrorStage {
    GAME_STATE_SAVE_WRITE_SIZE_ERROR = 1 << 16,
    GAME_STATE_SAVE_WRITE_IMAGE_ERROR = 2 << 16,
    GAME_STATE_SAVE_WRITE_CHECKSUM_ERROR = 3 << 16
};

EXTERN_C

// The save initializer stores this nonzero random value at +0x21CC. Its
// later role is unresolved; the original retry loop has no attempt limit.
u32 GetNonzeroRandomValue();

void InitializeGameDisplayOptions(struct GameDisplayOptions * options);

void InitializeTVShoppingOrderState(struct TVShoppingOrderState * state);
u32 GetTVShoppingSelection(struct TVShoppingOrderState const * state);
u32 GetTVShoppingPendingItem(struct TVShoppingOrderState const * state);
bool IsTVShoppingDeliveryReady(struct TVShoppingOrderState const * state);
// Raw assignment, including NONE or out-of-range IDs. Clearing selection can
// stall a pending order's countdown; it does not cancel that pending order.
void SetTVShoppingSelection(struct TVShoppingOrderState * state, u32 item);
// Copies selection and resets the countdown; no eligibility/price check.
void ConfirmTVShoppingOrder(struct TVShoppingOrderState * state);
// Preserve a changed selection and the countdown; always clear pending_item.
void CompleteTVShoppingDelivery(struct TVShoppingOrderState * state);
void UpdateTVShoppingDeliveryCountdown(struct TVShoppingOrderState * state);

// Unsigned byte sum modulo 2^32; a null pointer or zero count returns zero.
u32 CalculateSaveImageChecksum(u8 const * data, u32 count);
// A serialized record has a size word, the image, and a checksum word.
u32 GetSaveImageRecordSize();

// Writes the original save image and its checksum at the selected SRAM
// offset. Zero denotes success; nonzero values carry the SRAM error flags.
u32 WriteGameStateSaveImage(void const * snapshot, struct SramAccess * access, u32 offset);

EXTERN_C_END

#include "game_state_owner.hh"

inline GameStateSaveImageOwner::~GameStateSaveImageOwner()
{
    if (value != nullptr)
        delete value;
}

inline GameDisplayOptions::GameDisplayOptions()
{
    InitializeGameDisplayOptions(this);
}

inline TVShoppingOrderState::TVShoppingOrderState() { InitializeTVShoppingOrderState(this); }

#include "calendar.hh"
extern char const gCppRuntimeError_CalendarTrailer[];
extern char const gText_CalendarTrailerFallbackNone[];

// DayUpdate forces sunny weather on these packed one-based day/season dates.
// These are not the zero-based saved GameDate entries. The following byte
// before the aligned runtime text is padding, not another date or sentinel.
extern u8 const gMandatorySunnyCalendarDates[];

#endif // GAME_STATE_TYPES_HH
