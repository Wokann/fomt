#include "prelude.h"
#include "ui_quantity_selector.hh"
#include "shop_common.hh"
#include "game_state.hh"
#include "hardware_context.hh"
#include "hardware_dma.hh"
#include "gbaio.h"
#include "font.hh"
#include "font_decimal.hh"
#include "font_draw.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".include \"asm/gba.inc\"\n"
    "thumb_func_start __26UiPurchaseQuantitySelectorP14ShopScreenCore\n"
    "__26UiPurchaseQuantitySelectorP14ShopScreenCore:\n"
    ".align 2, 0\n"
    "push {r4, r5, r6, r7, lr}\n"
    "mov r7, sl\n"
    "mov r6, sb\n"
    "mov r5, r8\n"
    "push {r5, r6, r7}\n"
    "sub sp, #0x20\n"
    "str r0, [sp, #0x18]\n"
    "adds r0, r1, #0\n"
    "movs r2, #0\n"
    "ldr r1, [sp, #0x18]\n"
    "str r2, [r1]\n"
    "movs r1, #0x63\n"
    "ldr r3, [sp, #0x18]\n"
    "str r1, [r3, #4]\n"
    "strb r2, [r3, #8]\n"
    "str r2, [r3, #0xc]\n"
    "str r2, [r3, #0x10]\n"
    "movs r4, #1\n"
    "str r4, [r3, #0x14]\n"
    "str r0, [r3, #0x18]\n"
    "bl GetHardwareDmaQueue\n"
    "adds r5, r0, #0\n"
    "ldr r1, .Lmenu_0_0_0060\n"
    "mov r0, sp\n"
    "ldr r2, .Lmenu_0_0_0064\n"
    "movs r3, #0xe0\n"
    "lsls r3, r3, #1\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
    "mov sl, sp\n"
    "ldr r1, [r5, #4]\n"
    "ldr r0, [r5, #0xc]\n"
    "cmp r1, r0\n"
    "beq .Lmenu_0_0_0068\n"
    "cmp r1, #0\n"
    "beq .Lmenu_0_0_0056\n"
    "adds r0, r1, #0\n"
    "mov r1, sp\n"
    "ldm r1!, {r4, r6, r7}\n"
    "stm r0!, {r4, r6, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lmenu_0_0_0056:\n"
    "ldr r0, [r5, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r5, #4]\n"
    "b .Lmenu_0_0_0130\n"
    ".align 2, 0\n"
    ".Lmenu_0_0_0060: .word gUiNumberGlyphTiles\n"
    ".Lmenu_0_0_0064: .word 0x6000480\n"
    ".Lmenu_0_0_0068:\n"
    "str r1, [sp, #0x1c]\n"
    "str r4, [sp, #0x14]\n"
    "ldr r1, [r5]\n"
    "ldr r2, [sp, #0x1c]\n"
    "subs r0, r2, r1\n"
    "asrs r4, r0, #4\n"
    "str r4, [sp, #0x10]\n"
    "add r2, sp, #0x14\n"
    "add r0, sp, #0x10\n"
    "cmp r4, #1\n"
    "bhs .Lmenu_0_0_0080\n"
    "adds r0, r2, #0\n"
    ".Lmenu_0_0_0080:\n"
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
    "beq .Lmenu_0_0_00a0\n"
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
    "mov sb, r4\n"
    "cmp r0, #0\n"
    "bne .Lmenu_0_0_009c\n"
    "mov r0, sb\n"
    "bl RetryMemoryAllocation\n"
    ".Lmenu_0_0_009c:\n"
    "ldr r1, [r5]\n"
    "b .Lmenu_0_0_00a4\n"
    ".Lmenu_0_0_00a0:\n"
    "movs r0, #0\n"
    "mov sb, r0\n"
    ".Lmenu_0_0_00a4:\n"
    "adds r4, r0, #0\n"
    "mov r8, r4\n"
    "adds r2, r1, #0\n"
    "mov r3, r8\n"
    "ldr r4, [sp, #0x1c]\n"
    "cmp r2, r4\n"
    "beq .Lmenu_0_0_00cc\n"
    ".Lmenu_0_0_00b2:\n"
    "cmp r3, #0\n"
    "beq .Lmenu_0_0_00c2\n"
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r6, r7}\n"
    "stm r0!, {r4, r6, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lmenu_0_0_00c2:\n"
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
    "ldr r6, [sp, #0x1c]\n"
    "cmp r2, r6\n"
    "bne .Lmenu_0_0_00b2\n"
    ".Lmenu_0_0_00cc:\n"
    "adds r4, r3, #0\n"
    "ldr r0, [sp, #0x14]\n"
    "cmp r0, #1\n"
    "bne .Lmenu_0_0_00e8\n"
    "cmp r4, #0\n"
    "beq .Lmenu_0_0_00e4\n"
    "adds r0, r4, #0\n"
    "mov r1, sl\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lmenu_0_0_00e4:\n"
    "adds r4, #0x10\n"
    "b .Lmenu_0_0_010a\n"
    ".Lmenu_0_0_00e8:\n"
    "adds r3, r0, #0\n"
    "adds r2, r4, #0\n"
    "cmp r3, #0\n"
    "beq .Lmenu_0_0_0108\n"
    ".Lmenu_0_0_00f0:\n"
    "cmp r2, #0\n"
    "beq .Lmenu_0_0_0100\n"
    "adds r0, r2, #0\n"
    "mov r1, sl\n"
    "ldm r1!, {r4, r6, r7}\n"
    "stm r0!, {r4, r6, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lmenu_0_0_0100:\n"
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
    "bne .Lmenu_0_0_00f0\n"
    ".Lmenu_0_0_0108:\n"
    "adds r4, r2, #0\n"
    ".Lmenu_0_0_010a:\n"
    "ldr r2, [r5, #4]\n"
    "ldr r1, [r5]\n"
    "adds r0, r1, #0\n"
    "cmp r1, r2\n"
    "beq .Lmenu_0_0_011a\n"
    ".Lmenu_0_0_0114:\n"
    "adds r0, #0x10\n"
    "cmp r0, r2\n"
    "bne .Lmenu_0_0_0114\n"
    ".Lmenu_0_0_011a:\n"
    "cmp r1, #0\n"
    "beq .Lmenu_0_0_0124\n"
    "adds r0, r1, #0\n"
    "bl free\n"
    ".Lmenu_0_0_0124:\n"
    "mov r0, sb\n"
    "add r0, r8\n"
    "mov r1, r8\n"
    "str r1, [r5]\n"
    "str r4, [r5, #4]\n"
    "str r0, [r5, #0xc]\n"
    ".Lmenu_0_0_0130:\n"
    "ldr r0, [sp, #0x18]\n"
    "add sp, #0x20\n"
    "pop {r3, r4, r5}\n"
    "mov r8, r3\n"
    "mov sb, r4\n"
    "mov sl, r5\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r1}\n"
    "bx r1\n"
    ".align 2, 0\n"
);


void UiPurchaseQuantitySelector::Configure(u32 price, u32 available, u32 new_column)
{
    row = scene->selected_row * 2 + 4;
    column = new_column;
    unit_price = price;
    if (available > 99) maximum = 99;
    else maximum = available;
    ShopScreenCore * owner = scene;
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
