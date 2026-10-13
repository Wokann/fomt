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

// func_08010F54 scans the first 25 packed season/day entries.  The final
// zero is present in the original bytes but is outside that scan.
u8 const gUnk_080F0566[] ALIGN(1) = {
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
    0,
};

// The final regional text fragment follows the native byte table.
#include FOMT_TEXT_INCLUDE(game_state_2.cc)
