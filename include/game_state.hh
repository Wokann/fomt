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
    u32 selection;
    u32 pending_item;
    u8 countdown;
};

typedef char TVShoppingOrderStateSizeCheck[sizeof(TVShoppingOrderState) == 12 ? 1 : -1];
typedef char TVShoppingOrderPendingCheck[offsetof(TVShoppingOrderState, pending_item) == 4 ? 1 : -1];
typedef char TVShoppingOrderCountdownCheck[offsetof(TVShoppingOrderState, countdown) == 8 ? 1 : -1];

// The initializer, copy constructor and save-summary reader agree on these
// member offsets. Unknown ranges remain explicit storage; the native save
// initializer/copy/cleanup bodies have not yet been recovered as C++.
struct GameStateSaveImage {
    u8 unk_0000[0x10];
    GameCalendar calendar;
    Farm farm;
    MoneyAccount money_account;
    Farmer farmer;
    Dog dog;
    MoreItems more_items;
    u8 unk_1CCC[0x480];
    GameEventState event_state;
    u8 unk_21CC[0x44];
    GameDisplayOptions display_options;
    CookingRecipeInventory cooking_recipes;
    u8 unk_2C1C[0x58];
    TVShoppingOrderState tv_shopping;
    u8 unk_2C80[0x1D8];
    ActorStateGrid actor_state_grid;
    u8 unk_3480[0x74];
};

typedef char GameStateSaveImageSizeCheck[sizeof(GameStateSaveImage) == 0x34F4 ? 1 : -1];
typedef char GameStateSaveImageCalendarCheck[offsetof(GameStateSaveImage, calendar) == 0x10 ? 1 : -1];
typedef char GameStateSaveImageFarmCheck[offsetof(GameStateSaveImage, farm) == 0x14 ? 1 : -1];
typedef char GameStateSaveImageMoneyCheck[offsetof(GameStateSaveImage, money_account) == 0x1AA8 ? 1 : -1];
typedef char GameStateSaveImageFarmerCheck[offsetof(GameStateSaveImage, farmer) == 0x1BD8 ? 1 : -1];
typedef char GameStateSaveImageDogCheck[offsetof(GameStateSaveImage, dog) == 0x1C70 ? 1 : -1];
typedef char GameStateSaveImageMoreItemsCheck[offsetof(GameStateSaveImage, more_items) == 0x1CA0 ? 1 : -1];
typedef char GameStateSaveImageAfterMoreItemsCheck[offsetof(GameStateSaveImage, unk_1CCC) == 0x1CCC ? 1 : -1];
typedef char GameStateSaveImageEventStateCheck[offsetof(GameStateSaveImage, event_state) == 0x214C ? 1 : -1];
typedef char GameStateSaveImageAfterEventsCheck[offsetof(GameStateSaveImage, unk_21CC) == 0x21CC ? 1 : -1];
typedef char GameStateSaveImageOptionsCheck[offsetof(GameStateSaveImage, display_options) == 0x2210 ? 1 : -1];
typedef char GameStateSaveImageCookingCheck[offsetof(GameStateSaveImage, cooking_recipes) == 0x2214 ? 1 : -1];
typedef char GameStateSaveImageAfterCookingCheck[offsetof(GameStateSaveImage, unk_2C1C) == 0x2C1C ? 1 : -1];
typedef char GameStateSaveImageShoppingCheck[offsetof(GameStateSaveImage, tv_shopping) == 0x2C74 ? 1 : -1];
typedef char GameStateSaveImageAfterShoppingCheck[offsetof(GameStateSaveImage, unk_2C80) == 0x2C80 ? 1 : -1];
typedef char GameStateSaveImageActorGridCheck[offsetof(GameStateSaveImage, actor_state_grid) == 0x2E58 ? 1 : -1];
typedef char GameStateSaveImageAfterActorGridCheck[offsetof(GameStateSaveImage, unk_3480) == 0x3480 ? 1 : -1];

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

// func_08010F54 scans the first 25 entries as packed season/day values.
extern u8 const gUnk_080F0566[];
extern char const gCppRuntimeBadAlloc_GameState[];

#endif // GAME_STATE_HH
