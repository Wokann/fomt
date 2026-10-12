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
