#include "game_state.hh"
#include "unknown_types.hh"
#include "sram_proxy.hh"
#include "sram_proxy_2.hh"
#include <stdlib.h>

u32 GetNonzeroRandomValue()
{
    u32 value;
    do {
        value = rand();
    } while (value == 0);
    return value;
}

static inline u32 const & BoundDayIndex(u32 const & limit, u32 const & index)
{
    return index < limit ? index : limit;
}

// Startup placement requires all plots to be unoccupied and empty, unlike
// the weather-update placement path. Try at most 100 random coordinates.
static inline bool FindInitialSpot(Field<43, 25> const & field, u8 footprint_width, i32 (&pos)[2]) {
    bool big = footprint_width == 2;
    for (u32 attempt = 0; attempt < 100; ++attempt) {
        int x, y;
        if (big) {
            x = static_cast<u32>(rand()) % 42;
            y = static_cast<u32>(rand()) % 24;
        } else {
            x = static_cast<u32>(rand()) % 43;
            y = static_cast<u32>(rand()) % 25;
        }
        if (field.PlotAt(x, y).method_0800A78C()) continue;
        if (big) {
            if (field.PlotAt(x + 1, y).method_0800A78C()) continue;
            if (field.PlotAt(x, y + 1).method_0800A78C()) continue;
            if (field.PlotAt(x + 1, y + 1).method_0800A78C()) continue;
        }
        if (field.PlotAt(x, y).GetUnk8() != 0) continue;
        if (big) {
            if (field.PlotAt(x + 1, y).GetUnk8() != 0) continue;
            if (field.PlotAt(x, y + 1).GetUnk8() != 0) continue;
            if (field.PlotAt(x + 1, y + 1).GetUnk8() != 0) continue;
        }
        pos[0] = x;
        pos[1] = y;
        return true;
    }
    return false;
}
static inline void PutInitialItem(Field<43, 25> & field, int id) {
    i32 pos[2];
    bool found = FindInitialSpot(field, id > 0x1A ? 2 : 1, pos);
    if (found) {
        field.PlotAt(pos[0], pos[1]).method_0800A134(id, 8);
        if (id > 0x1A) {
            field.PlotAt(pos[0] + 1, pos[1]).method_0800A134(id + 1, 8);
            field.PlotAt(pos[0], pos[1] + 1).method_0800A134(id + 2, 8);
            field.PlotAt(pos[0] + 1, pos[1] + 1).method_0800A134(id + 3, 8);
        }
    }
}
GameStateSaveImage::GameStateSaveImage(char const * farm_name, char const * player_name,
    GameDate birthday, char const * dog_name)
    : flag_0(false), flag_1(false), flag_2(false), flag_3(false), flag_4(false),
      unk_13(0), unk_18(0), unk_25(0), unk_31(false), unk_32(false),
      clock(GameCalendar(1, GameDate(SEASON_SPRING, BoundDayIndex(DAY_30 - 1, DAY_01 - 1) + 1), GameTime(6, 0))),
      farm(farm_name), farmer(player_name, birthday), dog(dog_name), ball_location(MAP_NONE, 0, 0),
      link_record(GetNonzeroRandomValue()), actor_unknown_34C4(0), shooting_star_shipping_bonus(0)
{
    dog.AddAffection(50);
    for (u32 i = 0; i < 10; ++i) PutInitialItem(farm.field, 0x1F);
    for (u32 i = 0; i < 5; ++i) PutInitialItem(farm.field, 0x23);
    for (u32 i = 0; i < 10; ++i) PutInitialItem(farm.field, 0x1B);
    for (u32 i = 0; i < 300; ++i) PutInitialItem(farm.field, 0x15);
    for (u32 i = 0; i < 50; ++i) PutInitialItem(farm.field, 0x16);
    for (u32 i = 0; i < 50; ++i) PutInitialItem(farm.field, 0x17);
}

bool GameStateSaveImage::GetFlag0() const { return flag_0; }
bool GameStateSaveImage::GetFlag1() const { return flag_1; }
bool GameStateSaveImage::GetFlag2() const { return flag_2; }
bool GameStateSaveImage::GetFlag3() const { return flag_3; }

// Every present animal must have affection >= 200. Missing horse, chicken,
// cow or sheep slots are ignored; the dog is always checked. Do not return
// early: the native routine visits every slot even after a failed check.
bool GameStateSaveImage::AllAnimalsHaveHighAffection() const
{
    bool result = true;
    if (dog.GetAffection() < 200)
        result = false;

    Horse const * horse = farm.GetHorse();
    if (horse != nullptr && horse->GetAffection() < 200)
        result = false;

    for (u32 i = 0; i < farm.coop.GetCapacity(); ++i) {
        Chicken const * chicken = farm.coop.GetChicken(i);
        if (chicken != nullptr && chicken->GetAffection() < 200)
            result = false;
    }

    for (u32 i = 0; i < farm.barn.GetCapacity(); ++i) {
        Animal const * animal = farm.barn.GetCow(i);
        if (animal == nullptr)
            animal = farm.barn.GetSheep(i);
        if (animal != nullptr && animal->GetAffection() < 200)
            result = false;
    }
    return result;
}

bool GameStateSaveImage::GetFlag4() const { return flag_4; }
u32 GameStateSaveImage::GetUnknown13() const { return unk_13; }
u32 GameStateSaveImage::GetUnknown18() const { return unk_18; }
u32 GameStateSaveImage::GetUnknown25() const { return unk_25; }
void GameStateSaveImage::SetFlag0() { flag_0 = true; }
void GameStateSaveImage::SetFlag1() { flag_1 = true; }
void GameStateSaveImage::SetFlag2() { flag_2 = true; }
void GameStateSaveImage::SetFlag3() { flag_3 = true; }

bool GameStateSaveImage::CollectShippingRevenue()
{
    u32 value = farm.shipping_bin.GetValueShipped();
    AddMoneyToAccount(&money_account, value);
    // The shooting-star wish doubles this settlement, even if it is zero.
    // Consume the pending bonus here; do not change product prices.
    if (shooting_star_shipping_bonus != 0) {
        AddMoneyToAccount(&money_account, value);
        shooting_star_shipping_bonus = 0;
    }
    farm.shipping_bin.ResetValueShipped();
    return value != 0;
}

void GameStateSaveImage::SetFlag4() { flag_4 = true; }

bool GameStateSaveImage::UpdateUnknown13(u32 value)
{
    if (value > 99) value = 99;
    if (unk_13 < value) {
        unk_13 = value;
        return true;
    }
    return false;
}

bool GameStateSaveImage::UpdateUnknown18(u32 value)
{
    if (value > 99) value = 99;
    if (unk_18 < value) {
        unk_18 = value;
        return true;
    }
    return false;
}

bool GameStateSaveImage::UpdateUnknown25(u32 value)
{
    if (value > 99) value = 99;
    if (unk_25 < value) {
        unk_25 = value;
        return true;
    }
    return false;
}

void InitializeGameDisplayOptions(GameDisplayOptions * options)
{
    options->control_scheme = 0;
    options->show_clock = 1;
    options->show_portrait = 1;
    options->show_nameplate = 1;
}

void InitializeTVShoppingOrderState(TVShoppingOrderState * state)
{
    state->selection = TV_SHOPPING_ITEM_NONE;
    state->pending_item = TV_SHOPPING_ITEM_NONE;
    state->countdown = 0;
}

u32 GetTVShoppingSelection(TVShoppingOrderState const * state)
{
    return state->selection;
}

u32 GetTVShoppingPendingItem(TVShoppingOrderState const * state)
{
    return state->pending_item;
}

bool IsTVShoppingDeliveryReady(TVShoppingOrderState const * state)
{
    return state->pending_item != TV_SHOPPING_ITEM_NONE && state->countdown == 0;
}

void SetTVShoppingSelection(TVShoppingOrderState * state, u32 item)
{
    state->selection = item;
}

void ConfirmTVShoppingOrder(TVShoppingOrderState * state)
{
    state->pending_item = state->selection;
    state->countdown = 2;
}

void CompleteTVShoppingDelivery(TVShoppingOrderState * state)
{
    if (state->pending_item == state->selection)
        state->selection = TV_SHOPPING_ITEM_NONE;
    state->pending_item = TV_SHOPPING_ITEM_NONE;
}

void UpdateTVShoppingDeliveryCountdown(TVShoppingOrderState * state)
{
    if (state->selection != TV_SHOPPING_ITEM_NONE &&
        state->pending_item != TV_SHOPPING_ITEM_NONE && state->countdown != 0)
        --state->countdown;
}

u32 CalculateSaveImageChecksum(u8 const * data, u32 count)
{
    u32 sum = 0;
    if (data != nullptr && count != 0) {
        u8 const * cursor = data;
        do {
            sum += *cursor++;
        } while (--count != 0);
    }
    return sum;
}

u32 GetSaveImageRecordSize()
{
    return sizeof(GameStateSaveImage) + 2 * sizeof(u32);
}

u32 WriteGameStateSaveImage(void const * image, SramAccess * access, u32 offset)
{
    u32 const record_offset = offset;
    u32 const size = sizeof(GameStateSaveImage);
    u32 error;
    u32 stage;
    u32 checksum;

    if (static_cast<u8>(func_080006A4(access, offset, &size, sizeof(size))) == 0) {
        error = gUnk_03000400;
        stage = GAME_STATE_SAVE_WRITE_SIZE_ERROR;
        goto failed;
    }

    offset += sizeof(size);
    if (static_cast<u8>(func_080006A4(access, offset, image, size)) == 0) {
        error = gUnk_03000400;
        stage = GAME_STATE_SAVE_WRITE_IMAGE_ERROR;
        goto failed;
    }

    offset = record_offset + sizeof(size) + sizeof(GameStateSaveImage);
    checksum = CalculateSaveImageChecksum(static_cast<u8 const *>(image), size);
    if (static_cast<u8>(func_080006A4(access, offset, &checksum, sizeof(checksum))) != 0)
        return 0;

    error = gUnk_03000400;
    stage = GAME_STATE_SAVE_WRITE_CHECKSUM_ERROR;
failed:
    return error | stage;
}

// Calendar text begins this physical rodata block.
#include FOMT_TEXT_INCLUDE(game_state_1.cc)

// DayUpdate compares tomorrow with these 25 one-based calendar dates before
// choosing random weather. The next object's alignment supplies the gap.
u8 const gMandatorySunnyCalendarDates[] ALIGN(1) = {
    SEASON_SPRING | DAY_01 << 2,
    SEASON_SPRING | DAY_17 << 2,
    SEASON_SPRING | DAY_18 << 2,
    SEASON_SPRING | DAY_21 << 2,
    SEASON_SPRING | DAY_22 << 2,
    SEASON_SPRING | DAY_30 << 2,
    SEASON_SUMMER | DAY_01 << 2,
    SEASON_SUMMER | DAY_06 << 2,
    SEASON_SUMMER | DAY_07 << 2,
    SEASON_SUMMER | DAY_19 << 2,
    SEASON_SUMMER | DAY_20 << 2,
    SEASON_SUMMER | DAY_24 << 2,
    SEASON_FALL | DAY_02 << 2,
    SEASON_FALL | DAY_03 << 2,
    SEASON_FALL | DAY_08 << 2,
    SEASON_FALL | DAY_09 << 2,
    SEASON_FALL | DAY_13 << 2,
    SEASON_FALL | DAY_17 << 2,
    SEASON_FALL | DAY_18 << 2,
    SEASON_FALL | DAY_20 << 2,
    SEASON_FALL | DAY_21 << 2,
    SEASON_FALL | DAY_30 << 2,
    SEASON_WINTER | DAY_14 << 2,
    SEASON_WINTER | DAY_24 << 2,
    SEASON_WINTER | DAY_30 << 2,
};

// The final regional text fragment follows the native byte table.
#include FOMT_TEXT_INCLUDE(game_state_2.cc)
