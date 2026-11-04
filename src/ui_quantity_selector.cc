#include "prelude.h"
#pragma implementation "ui_quantity_selector.hh"
#include "ui_quantity_selector.hh"
#include "game_state.hh"
#include "hardware_state_accessors.hh"
#include "hardware_dma.hh"
#include "gbaio.h"
#include "font.hh"
#include "font_draw.hh"

void UiPurchaseQuantitySelector::Configure(u32 price, u32 available, u32 new_column)
{
    row = scene->unk_10 * 2 + 4;
    column = new_column;
    unit_price = price;
    if (available > 99) maximum = 99;
    else maximum = available;
    UiSceneCorePrefix * owner = scene;
    u32 affordable = owner->save->money_account.balance / unit_price;
    if (affordable < maximum) maximum = affordable;
    Fill2DGfxTilemapRect(&owner->scroll->rows[row + 1][new_column], 0x2E, 1, 1, 0, 32);
    DrawDecimalToTilemap(quantity, &scene->scroll->rows[row + 1][new_column + 2], 0x24, 0, 32);
#if defined(REGION_JP)
    // JP draws one additional tile before the final separator.
    Fill2DGfxTilemapRect(&scene->scroll->rows[row + 1][new_column + 3], 0x30, 1, 1, 0, 32);
#endif
    Fill2DGfxTilemapRect(&scene->scroll->rows[row + 1][new_column + 4], 0x2F, 1, 1, 0, 32);
    ScrollState * scroll = scene->scroll;
    UploadScrollBufferRows(scroll, scroll->position / 8, (scroll->position + 256) / 8);
    active = true;
}

void UiPurchaseQuantitySelector::Update()
{
    // Direction buttons occupy the low byte of the repeated-key ABI word.
    bool changed = false;
    u32 previous = quantity;
    if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(scene))) & DPAD_UP) {
        ++quantity;
        if (quantity > maximum) quantity = 1;
    } else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(scene))) & DPAD_DOWN) {
        --quantity;
        if (quantity == 0) quantity = maximum;
    } else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(scene))) & DPAD_RIGHT) {
        if (quantity == maximum) quantity = 1;
        else {
            quantity += 10;
            if (quantity >= maximum) quantity = maximum;
        }
    } else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(scene))) & DPAD_LEFT) {
        if (quantity == 1) quantity = maximum;
        else if (quantity <= 11) quantity = 1;
        else quantity -= 10;
    }
    if (previous != quantity) changed = true;
    if (changed) {
        FillHardwareDma3(0x03FF03FF, &scene->scroll->rows[row + 1][column + 1], 4);
        FillHardwareDma3(0x03FF03FF, &scene->scroll->rows[row][12], 28);
        FillHardwareDma3(0x03FF03FF, &scene->scroll->rows[row + 1][12], 28);
        DrawDecimalToTilemap(quantity, &scene->scroll->rows[row + 1][column + 2], 0x24, 0, 32);
#if defined(REGION_JP)
        DrawDecimalTo2x2Tilemap(quantity * unit_price, &scene->scroll->rows[row][25], 0xA0, 0, 32);
#else
        DrawDecimalTo1x2Tilemap(quantity * unit_price, &scene->scroll->rows[row][25], 0xA0, 0, 32);
#endif
        ScrollState * scroll = scene->scroll;
        UploadScrollBufferRows(scroll, scroll->position / 8, (scroll->position + 256) / 8);
        scene->music.Start(0xCB);
    }
}

void UiPurchaseQuantitySelector::Hide()
{
    FillHardwareDma3(0x03FF03FF, &scene->scroll->rows[row + 1][column], 16);
    FillHardwareDma3(0x03FF03FF, &scene->scroll->rows[row][12], 28);
    FillHardwareDma3(0x03FF03FF, &scene->scroll->rows[row + 1][12], 28);
#if defined(REGION_JP)
    DrawDecimalTo2x2Tilemap(unit_price, &scene->scroll->rows[row][25], 0xA0, 0, 32);
#else
    DrawDecimalTo1x2Tilemap(unit_price, &scene->scroll->rows[row][25], 0xA0, 0, 32);
#endif
    ScrollState * scroll = scene->scroll;
    UploadScrollBufferRows(scroll, scroll->position / 8, (scroll->position + 256) / 8);
    active = false;
    row = 0;
    quantity = 1;
}
