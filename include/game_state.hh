#ifndef GAME_STATE_HH
#define GAME_STATE_HH

#include "prelude.h"
#include "farm.hh"
#include "farmer.hh"
#include "dog.hh"
#include "more_items.hh"
#include "time_of_day.hh"
#include "money_account.hh"
#include "actor_state.hh"
#include "cooking_recipe_inventory_data.hh"
#include "event_state.hh"
#include "npc_collection.hh"
#include "field_item_data.hh"
#include "actor_runtime_data.hh"
#include "fishing_results_data.hh"
#include "animal_festival_ranking.hh"
#include "utility/fixed_str.hh"

struct SramAccess;

// The save image stores these options at +0x2210. The menu keeps two
// four-byte copies at +0x198/+0x19C, one for each SRAM slot. Only the low
// four bits have verified meanings; initializing them preserves all others.
struct GameDisplayOptions {
    GameDisplayOptions();

    u32 control_scheme : 1; // 0: D-pad walks / R runs; 1: D-pad runs / R walks.
    u8 show_clock : 1;
    u8 show_portrait : 1;
    u8 show_nameplate : 1;
    u32 unk_4 : 28;
};

typedef char GameDisplayOptionsSizeCheck[sizeof(GameDisplayOptions) == 4 ? 1 : -1];

// Saved at +0x2C74. IDs are raw words: the original setter does not validate
// them. The countdown starts at two, but delivery also depends on the game's
// update and event-priority paths, not an unconditional two-day guarantee.
struct TVShoppingOrderState {
    TVShoppingOrderState();

    u32 selection;
    u32 pending_item;
    u8 countdown;
};

typedef char TVShoppingOrderStateSizeCheck[sizeof(TVShoppingOrderState) == 12 ? 1 : -1];
typedef char TVShoppingOrderPendingCheck[offsetof(TVShoppingOrderState, pending_item) == 4 ? 1 : -1];
typedef char TVShoppingOrderCountdownCheck[offsetof(TVShoppingOrderState, countdown) == 8 ? 1 : -1];

// Saved at +0x21CC. The dispatcher keeps the received and local milestone
// bitmaps separate; initialization and copying confirm their actual sizes.
// The two words and three name slots have no further verified roles yet.
struct GameStateLinkRecord {
    GameStateLinkRecord(u32 value) : unk_00(value), unk_04(0)
    {
        fill_n_inl(received_milestones, 8, 0);
        fill_n_inl(local_milestones, 4, 0);
    }

    u32 unk_00;
    u32 unk_04;
    u8 received_milestones[8];
    u8 local_milestones[4];
    FixedStr<15> name_14;
    FixedStr<15> name_24;
    FixedStr<15> name_34;
};

typedef char GameStateLinkRecordSizeCheck[sizeof(GameStateLinkRecord) == 0x44 ? 1 : -1];
typedef char GameStateLinkRecordReceivedCheck[offsetof(GameStateLinkRecord, received_milestones) == 8 ? 1 : -1];
typedef char GameStateLinkRecordLocalCheck[offsetof(GameStateLinkRecord, local_milestones) == 0x10 ? 1 : -1];
typedef char GameStateLinkRecordName14Check[offsetof(GameStateLinkRecord, name_14) == 0x14 ? 1 : -1];
typedef char GameStateLinkRecordName24Check[offsetof(GameStateLinkRecord, name_24) == 0x24 ? 1 : -1];
typedef char GameStateLinkRecordName34Check[offsetof(GameStateLinkRecord, name_34) == 0x34 ? 1 : -1];

// Three 16-byte records follow ActorStateSlots in the saved actor state.
// Initialization clears only each record's low nibble, not the other words.
struct GameStateActorRecord {
    GameStateActorRecord() : unk_00_low(0) {}

    u32 unk_00_low : 4;
    u32 unk_00_high : 28;
    u32 unk_04[3];
};

typedef char GameStateActorRecordSizeCheck[sizeof(GameStateActorRecord) == 0x10 ? 1 : -1];
typedef char GameStateActorRecordWordsCheck[offsetof(GameStateActorRecord, unk_04) == 4 ? 1 : -1];

// The saved clock has two still-unknown words followed by the calendar.
struct GameStateClock {
    u32 unk_00, unk_04;
    GameCalendar calendar;
    GameStateClock(GameCalendar const & value)
        : unk_00(0), unk_04(0), calendar(value) {}
};
typedef char GameStateClockSizeCheck[sizeof(GameStateClock) == 12 ? 1 : -1];

// Only the low 24 bits of the final word are initialized. The preceding
// eleven words and the high byte retain the native uninitialized storage.
struct GameStateUnknown2C1C {
    u32 unk_00[11];
    u32 unk_2C_00 : 2;
    u32 unk_2C_02 : 17;
    bool unk_2C_19 : 1;
    bool unk_2C_20 : 1;
    bool unk_2C_21 : 1;
    bool unk_2C_22 : 1;
    bool unk_2C_23 : 1;
    u32 unk_2C_24 : 8;
    GameStateUnknown2C1C() : unk_2C_00(3), unk_2C_02(0),
        unk_2C_19(false), unk_2C_20(false), unk_2C_21(false),
        unk_2C_22(false), unk_2C_23(false) {}
};
typedef char GameStateUnknown2C1CSizeCheck[sizeof(GameStateUnknown2C1C) == 0x30 ? 1 : -1];

extern "C" void func_0809C4E4(u32 &);
struct GameStateUnknown34D8 {
    u32 value;
    GameStateUnknown34D8() { func_0809C4E4(value); }
};
typedef char GameStateUnknown34D8SizeCheck[sizeof(GameStateUnknown34D8) == 4 ? 1 : -1];

// The initializer, copy constructor and save-summary reader agree on these
// member offsets. Unknown fields keep offset names. Initialization is recovered;
// native copy/cleanup bodies have not yet been recovered as C++.
struct GameStateSaveImage {
    GameStateSaveImage(char const *, char const *, GameDate, char const *);

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

    // Verified by initialization, the native bit readers and setters. The
    // flags and three bounded fields are not assigned gameplay names yet.
    /* bit 00 */ bool flag_0 : 1;
    /* bit 01 */ bool flag_1 : 1;
    /* bit 02 */ bool flag_2 : 1;
    /* bit 03 */ bool flag_3 : 1;
    /* bit 04 */ bool flag_4 : 1;
    /* bit 05 */ u32 unk_5 : 8;
    /* bit 13 */ u32 unk_13 : 5;
    /* bit 18 */ u16 unk_18 : 7;
    /* bit 25 */ u8 unk_25 : 6;
    /* bit 31 */ bool unk_31 : 1;
    /* bit 32 */ bool unk_32 : 1;
    u8 unk_05[3];
    GameStateClock clock;
    Farm farm;
    MoneyAccount money_account;
    Farmer farmer;
    Dog dog;
    MoreItems more_items;
    // Dropping ITEM_ARTICLE_BALL saves an AEntity's six-byte Location here;
    // mine generation and the town map read it when the ball is not carried
    // or shelved. The following two bytes are natural alignment padding.
    Location ball_location;
    NpcCollection npcs;
    GameEventState event_state;
    GameStateLinkRecord link_record;
    GameDisplayOptions display_options;
    CookingRecipeInventory cooking_recipes;
    GameStateUnknown2C1C unk_2C1C;
    AnimalFestivalOpponents animal_festival_opponents;
    TVShoppingOrderState tv_shopping;
    FishingRecords fishing_records;
    ActorStateGrid actor_state_grid;
    ActorStateSlots actor_slots;
    GameStateActorRecord actor_records[3];
    u8 actor_unknown_34C4;
    u8 shooting_star_shipping_bonus;
    // The native initializer places this member at the next word boundary.
    // The two bytes after the preceding flags are padding, not array data.
    FieldItemState field_items ALIGN(4);
    GameStateUnknown34D8 unk_34D8;
    Unk_Actor_0809BFE8 unk_34DC;
};

typedef char GameStateSaveImageSizeCheck[sizeof(GameStateSaveImage) == 0x34F4 ? 1 : -1];
typedef char GameStateSaveImageUnknown05Check[offsetof(GameStateSaveImage, unk_05) == 5 ? 1 : -1];
typedef char GameStateSaveImageUnknown08Check[offsetof(GameStateSaveImage, clock) == 8 ? 1 : -1];
typedef char GameStateSaveImageUnknown0CCheck[offsetof(GameStateSaveImage, clock) + offsetof(GameStateClock, unk_04) == 12 ? 1 : -1];
typedef char GameStateSaveImageCalendarCheck[offsetof(GameStateSaveImage, clock) + offsetof(GameStateClock, calendar) == 0x10 ? 1 : -1];
typedef char GameStateSaveImageFarmCheck[offsetof(GameStateSaveImage, farm) == 0x14 ? 1 : -1];
typedef char GameStateSaveImageMoneyCheck[offsetof(GameStateSaveImage, money_account) == 0x1AA8 ? 1 : -1];
typedef char GameStateSaveImageFarmerCheck[offsetof(GameStateSaveImage, farmer) == 0x1BD8 ? 1 : -1];
typedef char GameStateSaveImageDogCheck[offsetof(GameStateSaveImage, dog) == 0x1C70 ? 1 : -1];
typedef char GameStateSaveImageMoreItemsCheck[offsetof(GameStateSaveImage, more_items) == 0x1CA0 ? 1 : -1];
typedef char GameStateSaveImageBallLocationCheck[offsetof(GameStateSaveImage, ball_location) == 0x1CCC ? 1 : -1];
typedef char GameStateSaveImageNpcCollectionCheck[offsetof(GameStateSaveImage, npcs) == 0x1CD4 ? 1 : -1];
typedef char GameStateSaveImageChildCheck[offsetof(GameStateSaveImage, npcs) + offsetof(NpcCollection, child) == 0x1CD8 ? 1 : -1];
typedef char GameStateSaveImageEventStateCheck[offsetof(GameStateSaveImage, event_state) == 0x214C ? 1 : -1];
typedef char GameStateSaveImageLinkRecordCheck[offsetof(GameStateSaveImage, link_record) == 0x21CC ? 1 : -1];
typedef char GameStateSaveImageReceivedMilestonesCheck[offsetof(GameStateSaveImage, link_record) + offsetof(GameStateLinkRecord, received_milestones) == 0x21D4 ? 1 : -1];
typedef char GameStateSaveImageLocalMilestonesCheck[offsetof(GameStateSaveImage, link_record) + offsetof(GameStateLinkRecord, local_milestones) == 0x21DC ? 1 : -1];
typedef char GameStateSaveImageOptionsCheck[offsetof(GameStateSaveImage, display_options) == 0x2210 ? 1 : -1];
typedef char GameStateSaveImageCookingCheck[offsetof(GameStateSaveImage, cooking_recipes) == 0x2214 ? 1 : -1];
typedef char GameStateSaveImageAfterCookingCheck[offsetof(GameStateSaveImage, unk_2C1C) == 0x2C1C ? 1 : -1];
typedef char GameStateSaveImageUnknown2C48Check[offsetof(GameStateSaveImage, unk_2C1C) + sizeof(((GameStateUnknown2C1C *) 0)->unk_00) == 0x2C48 ? 1 : -1];
typedef char GameStateSaveImageAnimalFestivalOpponentsCheck[offsetof(GameStateSaveImage, animal_festival_opponents) == 0x2C4C ? 1 : -1];
typedef char GameStateSaveImageShoppingCheck[offsetof(GameStateSaveImage, tv_shopping) == 0x2C74 ? 1 : -1];
typedef char GameStateSaveImageFishingRecordsCheck[offsetof(GameStateSaveImage, fishing_records) == 0x2C80 ? 1 : -1];
typedef char GameStateSaveImageActorGridCheck[offsetof(GameStateSaveImage, actor_state_grid) == 0x2E58 ? 1 : -1];
typedef char GameStateSaveImageActorStateCheck[offsetof(GameStateSaveImage, actor_slots) == 0x3480 ? 1 : -1];
typedef char GameStateSaveImageActorRecordsCheck[offsetof(GameStateSaveImage, actor_records) == 0x3494 ? 1 : -1];
typedef char GameStateSaveImageActorUnknown44Check[offsetof(GameStateSaveImage, actor_unknown_34C4) == 0x34C4 ? 1 : -1];
typedef char GameStateSaveImageShippingBonusCheck[offsetof(GameStateSaveImage, shooting_star_shipping_bonus) == 0x34C5 ? 1 : -1];
typedef char GameStateSaveImageFieldItemsCheck[offsetof(GameStateSaveImage, field_items) == 0x34C8 ? 1 : -1];
typedef char GameStateSaveImageTailWordCheck[offsetof(GameStateSaveImage, unk_34D8) == 0x34D8 ? 1 : -1];
typedef char GameStateSaveImageTailActorCheck[offsetof(GameStateSaveImage, unk_34DC) == 0x34DC ? 1 : -1];

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

// Initializes and reads a save image into the supplied allocation. The
// status output is zero on success; the complete image layout is unresolved.
void * func_08011650(void * object, struct SramAccess * access, u32 offset,
    u32 * status);
// Copy-construction into existing storage and the original destructor ABI.
// Destructor flag bit zero requests deallocation after member cleanup.
void * func_080D4178(void * object, void const * source);
void func_080D4480(void * object, u32 flags);

EXTERN_C_END

inline GameDisplayOptions::GameDisplayOptions()
{
    InitializeGameDisplayOptions(this);
}

inline TVShoppingOrderState::TVShoppingOrderState() { InitializeTVShoppingOrderState(this); }

#if defined(REGION_JP)
extern char const gText_Calendar_SeasonNames[4][3];
extern char const gText_Calendar_WeekdayNames[7][3];
#else
extern char const gText_Calendar_SeasonNames[4][7];
extern char const gText_Calendar_WeekdayNames[7][5];
#endif

extern char const gText_Calendar_None[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer00[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer01[];
extern char const gCppRuntimeError_CalendarTrailer[];
extern char const gText_CalendarTrailerFallbackNone[];
extern char const gCppRuntimeBadAlloc_CalendarTrailer02[];

// DayUpdate forces sunny weather on these packed one-based day/season dates.
// These are not the zero-based saved GameDate entries. The following byte
// before the aligned runtime text is padding, not another date or sentinel.
extern u8 const gMandatorySunnyCalendarDates[];
extern char const gCppRuntimeBadAlloc_GameState[];

#endif // GAME_STATE_HH
