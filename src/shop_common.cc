#include "obj_palette_collection.hh"
// Native display updates retain the real descriptor queue's inline expansion.
#include "hardware_dma_queue.hh"
#include "shop_common.hh"
#include "shop_resource_slots.hh"
#include "gbaio.h"
#include "hardware_dma.hh"
#include "font_decimal.hh"
#include "game_state_types.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".include \"asm/gba.inc\"\n"
    ".align 2, 0\n"
    "thumb_func_start __14ShopScreenCoreP18GameStateSaveImage\n"
    "__14ShopScreenCoreP18GameStateSaveImage:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "mov r7, sl\n"
    "mov r6, sb\n"
    "mov r5, r8\n"
    "push {r5, r6, r7}\n"
    "sub sp, #0x58\n"
    "adds r7, r0, #0\n"
    "adds r4, r1, #0\n"
    "bl __15HardwareContext\n"
    "ldr r0, .Lshop_common_03b8\n"
    "str r0, [r7, #4]\n"
    "str r4, [r7, #8]\n"
    "movs r4, #0\n"
    "strh r4, [r7, #0xc]\n"
    "str r4, [r7, #0x10]\n"
    "movs r6, #1\n"
    "rsbs r6, r6, #0\n"
    "str r6, [r7, #0x14]\n"
    "adds r0, r7, #0\n"
    "adds r0, #0x18\n"
    "movs r1, #1\n"
    "bl __23HardwareMusicPlayerSlotUc\n"
    "str r4, [r7, #0x1c]\n"
    "str r4, [r7, #0x20]\n"
    "movs r1, #0xa9\n"
    "lsls r1, r1, #2\n"
    "adds r0, r7, r1\n"
    "str r4, [r0]\n"
    "add r0, sp, #0xc\n"
    "bl __17ObjTileCollection\n"
    "add r5, sp, #0x10\n"
    "adds r0, r5, #0\n"
    "bl __20ObjPaletteCollection\n"
    "movs r1, #0xd2\n"
    "lsls r1, r1, #2\n"
    "adds r0, r7, r1\n"
    "str r4, [sp]\n"
    "add r1, sp, #0xc\n"
    "str r1, [sp, #4]\n"
    "str r5, [sp, #8]\n"
    "movs r1, #0\n"
    "movs r2, #0x1c\n"
    "movs r3, #0\n"
    "bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection\n"
    "adds r0, r5, #0\n"
    "movs r1, #2\n"
    "bl _._20ObjPaletteCollection\n"
    "add r0, sp, #0xc\n"
    "movs r1, #2\n"
    "bl _._17ObjTileCollection\n"
    "movs r0, #0xd5\n"
    "lsls r0, r0, #2\n"
    "adds r4, r7, r0\n"
    "adds r0, r4, #0\n"
    "bl InitializeObjTilePoolOwner\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl AllocateObjTileHandle\n"
    "str r0, [r4, #4]\n"
    "movs r1, #0xd7\n"
    "lsls r1, r1, #2\n"
    "adds r4, r7, r1\n"
    "adds r0, r4, #0\n"
    "bl ConstructObjPalettePoolOwner\n"
    "adds r0, r4, #0\n"
    "bl AllocateObjPaletteHandle\n"
    "str r0, [r4, #4]\n"
    "movs r0, #0xd9\n"
    "lsls r0, r0, #2\n"
    "adds r4, r7, r0\n"
    "adds r0, r4, #0\n"
    "bl InitializeObjTilePoolOwner\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl AllocateObjTileHandle\n"
    "str r0, [r4, #4]\n"
    "movs r1, #0xdb\n"
    "lsls r1, r1, #2\n"
    "adds r4, r7, r1\n"
    "adds r0, r4, #0\n"
    "bl ConstructObjPalettePoolOwner\n"
    "adds r0, r4, #0\n"
    "bl AllocateObjPaletteHandle\n"
    "str r0, [r4, #4]\n"
    "movs r0, #0xdd\n"
    "lsls r0, r0, #2\n"
    "adds r4, r7, r0\n"
    "adds r0, r4, #0\n"
    "bl InitializeObjTilePoolOwner\n"
    "adds r0, r4, #0\n"
    "movs r1, #1\n"
    "bl AllocateObjTileHandle\n"
    "str r0, [r4, #4]\n"
    "movs r1, #0xdf\n"
    "lsls r1, r1, #2\n"
    "adds r4, r7, r1\n"
    "adds r0, r4, #0\n"
    "bl InitializeObjTilePoolOwner\n"
    "adds r0, r4, #0\n"
    "movs r1, #1\n"
    "bl AllocateObjTileHandle\n"
    "str r0, [r4, #4]\n"
    "movs r0, #0xe1\n"
    "lsls r0, r0, #2\n"
    "adds r4, r7, r0\n"
    "adds r0, r4, #0\n"
    "bl ConstructObjPalettePoolOwner\n"
    "adds r0, r4, #0\n"
    "bl AllocateObjPaletteHandle\n"
    "str r0, [r4, #4]\n"
    "movs r1, #0xe3\n"
    "lsls r1, r1, #2\n"
    "adds r4, r7, r1\n"
    "adds r0, r4, #0\n"
    "bl InitializeObjTilePoolOwner\n"
    "adds r0, r4, #0\n"
    "movs r1, #1\n"
    "bl AllocateObjTileHandle\n"
    "str r0, [r4, #4]\n"
    "movs r0, #0xe5\n"
    "lsls r0, r0, #2\n"
    "adds r4, r7, r0\n"
    "adds r0, r4, #0\n"
    "bl InitializeObjTilePoolOwner\n"
    "adds r0, r4, #0\n"
    "movs r1, #1\n"
    "bl AllocateObjTileHandle\n"
    "str r0, [r4, #4]\n"
    "movs r1, #0xe7\n"
    "lsls r1, r1, #2\n"
    "adds r4, r7, r1\n"
    "adds r0, r4, #0\n"
    "bl ConstructObjPalettePoolOwner\n"
    "adds r0, r4, #0\n"
    "bl AllocateObjPaletteHandle\n"
    "str r0, [r4, #4]\n"
    "movs r0, #0xe9\n"
    "lsls r0, r0, #2\n"
    "adds r4, r7, r0\n"
    "movs r5, #8\n"
    "mov r1, sp\n"
    "adds r1, #0x14\n"
    "str r1, [sp, #0x50]\n"
    "movs r0, #0\n"
    "mov r8, r0\n"
    ".Lshop_common_0158:\n"
    "adds r0, r4, #0\n"
    "bl InitializeObjTilePoolOwner\n"
    "mov r1, r8\n"
    "str r1, [r4, #4]\n"
    "adds r4, #8\n"
    "subs r5, #1\n"
    "cmp r5, r6\n"
    "bne .Lshop_common_0158\n"
    "movs r0, #0xfb\n"
    "lsls r0, r0, #2\n"
    "adds r4, r7, r0\n"
    "movs r5, #8\n"
    "movs r1, #0xad\n"
    "lsls r1, r1, #3\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #0x48]\n"
    "ldr r0, .Lshop_common_03bc\n"
    "adds r0, r0, r7\n"
    "mov sl, r0\n"
    "movs r1, #0xb3\n"
    "lsls r1, r1, #3\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #0x20]\n"
    "movs r0, #0xb4\n"
    "lsls r0, r0, #3\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #0x28]\n"
    "ldr r1, .Lshop_common_03c0\n"
    "adds r1, r1, r7\n"
    "mov sb, r1\n"
    "movs r0, #0xba\n"
    "lsls r0, r0, #3\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #0x34]\n"
    "movs r1, #0xbb\n"
    "lsls r1, r1, #3\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #0x38]\n"
    "ldr r0, .Lshop_common_03c4\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #0x3c]\n"
    "movs r1, #0xc1\n"
    "lsls r1, r1, #3\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #0x40]\n"
    "movs r0, #0xc2\n"
    "lsls r0, r0, #3\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #0x44]\n"
    "ldr r1, .Lshop_common_03c8\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #0x4c]\n"
    "movs r0, #0xc8\n"
    "lsls r0, r0, #3\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #0x54]\n"
    "movs r1, #0xc9\n"
    "lsls r1, r1, #3\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #0x1c]\n"
    "ldr r0, .Lshop_common_03cc\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #0x24]\n"
    "movs r1, #0xcc\n"
    "lsls r1, r1, #3\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #0x2c]\n"
    "ldr r0, .Lshop_common_03d0\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #0x30]\n"
    "movs r1, #0\n"
    "mov r8, r1\n"
    "movs r6, #1\n"
    "rsbs r6, r6, #0\n"
    ".Lshop_common_01ee:\n"
    "adds r0, r4, #0\n"
    "bl ConstructObjPalettePoolOwner\n"
    "mov r0, r8\n"
    "str r0, [r4, #4]\n"
    "adds r4, #8\n"
    "subs r5, #1\n"
    "cmp r5, r6\n"
    "bne .Lshop_common_01ee\n"
    "ldr r1, .Lshop_common_03d4\n"
    "adds r0, r7, r1\n"
    "movs r5, #0\n"
    "movs r4, #0\n"
    "strh r4, [r0]\n"
    "adds r1, #4\n"
    "adds r0, r7, r1\n"
    "str r7, [sp, #0x14]\n"
    "ldr r1, [sp, #0x50]\n"
    "bl __15UiVCountBindingRCP14ShopScreenCore\n"
    "ldr r0, .Lshop_common_03d8\n"
    "adds r6, r7, r0\n"
    "ldr r1, .Lshop_common_03dc\n"
    "adds r0, r6, #0\n"
    "bl __22IndexedResourceArchivePCUc\n"
    "ldr r1, .Lshop_common_03e0\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #0x18]\n"
    "ldr r1, .Lshop_common_03e4\n"
    "ldr r0, [sp, #0x18]\n"
    "bl __22IndexedResourceArchivePCUc\n"
    "ldr r0, .Lshop_common_03e8\n"
    "adds r0, r0, r7\n"
    "mov r8, r0\n"
    "ldr r1, .Lshop_common_03ec\n"
    "bl __22IndexedResourceArchivePCUc\n"
    "ldr r1, .Lshop_common_03f0\n"
    "adds r0, r7, r1\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "ldr r0, [sp, #0x48]\n"
    "adds r1, r6, #0\n"
    "movs r2, #0\n"
    "movs r3, #0x80\n"
    "lsls r3, r3, #1\n"
    "bl __21IndexedResourceHandleP23IndexedResourceProviderUii\n"
    "mov r0, sl\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "strh r4, [r0, #4]\n"
    "strh r4, [r0, #6]\n"
    "strh r4, [r0, #8]\n"
    "str r4, [r0, #0xc]\n"
    "strb r5, [r0, #0x10]\n"
    "strb r5, [r0, #0x11]\n"
    "str r4, [r0, #0x14]\n"
    "strb r5, [r0, #0x18]\n"
    "ldr r1, [sp, #0x20]\n"
    "strb r5, [r1]\n"
    "ldr r1, .Lshop_common_03f4\n"
    "adds r0, r7, r1\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "ldr r0, [sp, #0x28]\n"
    "adds r1, r6, #0\n"
    "movs r2, #1\n"
    "movs r3, #0x80\n"
    "lsls r3, r3, #1\n"
    "bl __21IndexedResourceHandleP23IndexedResourceProviderUii\n"
    "mov r0, sb\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "strh r4, [r0, #4]\n"
    "strh r4, [r0, #6]\n"
    "strh r4, [r0, #8]\n"
    "str r4, [r0, #0xc]\n"
    "strb r5, [r0, #0x10]\n"
    "strb r5, [r0, #0x11]\n"
    "str r4, [r0, #0x14]\n"
    "strb r5, [r0, #0x18]\n"
    "ldr r1, [sp, #0x34]\n"
    "strb r5, [r1]\n"
    "ldr r1, .Lshop_common_03f8\n"
    "adds r0, r7, r1\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "ldr r0, [sp, #0x38]\n"
    "mov r1, r8\n"
    "movs r2, #0\n"
    "movs r3, #0x80\n"
    "lsls r3, r3, #1\n"
    "bl __21IndexedResourceHandleP23IndexedResourceProviderUii\n"
    "ldr r0, [sp, #0x3c]\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "strh r4, [r0, #4]\n"
    "strh r4, [r0, #6]\n"
    "strh r4, [r0, #8]\n"
    "str r4, [r0, #0xc]\n"
    "strb r5, [r0, #0x10]\n"
    "strb r5, [r0, #0x11]\n"
    "str r4, [r0, #0x14]\n"
    "strb r5, [r0, #0x18]\n"
    "ldr r1, [sp, #0x40]\n"
    "strb r5, [r1]\n"
    "ldr r1, .Lshop_common_03fc\n"
    "adds r0, r7, r1\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "ldr r0, [sp, #0x44]\n"
    "mov r1, r8\n"
    "movs r2, #1\n"
    "movs r3, #0x80\n"
    "lsls r3, r3, #1\n"
    "bl __21IndexedResourceHandleP23IndexedResourceProviderUii\n"
    "ldr r0, [sp, #0x4c]\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "strh r4, [r0, #4]\n"
    "strh r4, [r0, #6]\n"
    "strh r4, [r0, #8]\n"
    "str r4, [r0, #0xc]\n"
    "strb r5, [r0, #0x10]\n"
    "strb r5, [r0, #0x11]\n"
    "str r4, [r0, #0x14]\n"
    "strb r5, [r0, #0x18]\n"
    "ldr r1, [sp, #0x54]\n"
    "strb r5, [r1]\n"
    "ldr r0, .Lshop_common_0400\n"
    "adds r6, r7, r0\n"
    "movs r0, #0xc\n"
    "strh r0, [r6]\n"
    "movs r0, #0x28\n"
    "ldr r1, [sp, #0x1c]\n"
    "str r0, [r1]\n"
    "ldr r0, [sp, #0x24]\n"
    "ldr r1, [sp, #0x18]\n"
    "movs r2, #0\n"
    "movs r3, #0x80\n"
    "lsls r3, r3, #1\n"
    "bl __21IndexedResourceHandleP23IndexedResourceProviderUii\n"
    "ldr r0, [sp, #0x2c]\n"
    "strh r4, [r0]\n"
    "strh r4, [r0, #2]\n"
    "strh r4, [r0, #4]\n"
    "strh r4, [r0, #6]\n"
    "strh r4, [r0, #8]\n"
    "str r4, [r0, #0xc]\n"
    "strb r5, [r0, #0x10]\n"
    "strb r5, [r0, #0x11]\n"
    "str r4, [r0, #0x14]\n"
    "strb r5, [r0, #0x18]\n"
    "movs r0, #1\n"
    "ldr r1, [sp, #0x30]\n"
    "strb r0, [r1]\n"
    "str r4, [r6, #0x3c]\n"
    "ldr r1, .Lshop_common_0404\n"
    "adds r0, r7, r1\n"
    "adds r1, r7, #0\n"
    "bl __26UiPurchaseQuantitySelectorP14ShopScreenCore\n"
    "movs r1, #0xd4\n"
    "lsls r1, r1, #3\n"
    "adds r0, r7, r1\n"
    "strb r5, [r0]\n"
    "adds r1, #1\n"
    "adds r0, r7, r1\n"
    "strb r5, [r0]\n"
    "adds r1, #1\n"
    "adds r0, r7, r1\n"
    "strb r5, [r0]\n"
    "adds r1, #1\n"
    "adds r0, r7, r1\n"
    "strb r5, [r0]\n"
    "movs r0, #0\n"
    "mov r8, r0\n"
    "movs r1, #0xea\n"
    "lsls r1, r1, #2\n"
    "adds r6, r7, r1\n"
    ".Lshop_common_0364:\n"
    "mov r0, r8\n"
    "lsls r5, r0, #3\n"
    "adds r4, r5, r7\n"
    "movs r1, #0xe9\n"
    "lsls r1, r1, #2\n"
    "adds r4, r4, r1\n"
    "ldr r1, [r6]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjTileHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl AllocateObjTileHandle\n"
    "str r0, [r6]\n"
    "adds r5, r5, r7\n"
    "movs r0, #0xfb\n"
    "lsls r0, r0, #2\n"
    "adds r5, r5, r0\n"
    "ldr r1, [r6, #0x48]\n"
    "adds r0, r5, #0\n"
    "bl ReleaseObjPaletteHandle\n"
    "adds r0, r5, #0\n"
    "bl AllocateObjPaletteHandle\n"
    "str r0, [r6, #0x48]\n"
    "adds r6, #8\n"
    "movs r1, #1\n"
    "add r8, r1\n"
    "mov r0, r8\n"
    "cmp r0, #8\n"
    "ble .Lshop_common_0364\n"
    "adds r0, r7, #0\n"
    "add sp, #0x58\n"
    "pop {r3, r4, r5}\n"
    "mov r8, r3\n"
    "mov sb, r4\n"
    "mov sl, r5\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r1}\n"
    "bx r1\n"
#if defined(REGION_JP)
    ".Lshop_common_03b8: .word __vt_14ShopScreenCore\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".align 2, 0\n"
    ".Lshop_common_03b8: .word __vt_14ShopScreenCore\n"
#endif
    ".Lshop_common_03bc: .word 0x57c\n"
    ".Lshop_common_03c0: .word 0x5b4\n"
    ".Lshop_common_03c4: .word 0x5ec\n"
    ".Lshop_common_03c8: .word 0x624\n"
    ".Lshop_common_03cc: .word 0x64c\n"
    ".Lshop_common_03d0: .word 0x67c\n"
    ".Lshop_common_03d4: .word 0x434\n"
    ".Lshop_common_03d8: .word 0x4d4\n"
    ".Lshop_common_03dc: .word gUnk_08527094\n"
    ".Lshop_common_03e0: .word 0x504\n"
    ".Lshop_common_03e4: .word gUiHandCursorArchive\n"
    ".Lshop_common_03e8: .word 0x534\n"
#if defined(REGION_JP)
    ".Lshop_common_03ec: .word gUnk_084D9690\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_03ec: .word gUnk_087536E4\n"
#endif
    ".Lshop_common_03f0: .word 0x564\n"
    ".Lshop_common_03f4: .word 0x59c\n"
    ".Lshop_common_03f8: .word 0x5d4\n"
    ".Lshop_common_03fc: .word 0x60c\n"
    ".Lshop_common_0400: .word 0x644\n"
    ".Lshop_common_0404: .word 0x684\n"
    "thumb_func_start _._14ShopScreenCore\n"
    "_._14ShopScreenCore:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "mov r7, sb\n"
    "mov r6, r8\n"
    "push {r6, r7}\n"
    "adds r5, r0, #0\n"
    "mov sb, r1\n"
    "ldr r0, .Lshop_common_05e4\n"
    "str r0, [r5, #4]\n"
    "ldr r0, .Lshop_common_05e8\n"
    "adds r4, r5, r0\n"
    "ldrh r1, [r4]\n"
    "movs r0, #0\n"
    "bl SetInterruptNestingMask\n"
    "ldr r1, .Lshop_common_05ec\n"
    "adds r0, r5, r1\n"
    "ldr r1, .Lshop_common_05f0\n"
    "str r1, [r0]\n"
    "ldr r2, .Lshop_common_05f4\n"
    "adds r0, r5, r2\n"
    "str r1, [r0]\n"
    "subs r2, #0x30\n"
    "adds r0, r5, r2\n"
    "str r1, [r0]\n"
    "movs r1, #0x87\n"
    "lsls r1, r1, #3\n"
    "adds r0, r5, r1\n"
    "movs r1, #2\n"
    "bl _._15UiVCountBinding\n"
    "movs r2, #0xfb\n"
    "lsls r2, r2, #2\n"
    "adds r0, r5, r2\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_046a\n"
    "cmp r0, r4\n"
    "beq .Lshop_common_046a\n"
    "adds r6, r0, #0\n"
    ".Lshop_common_0454:\n"
    "subs r4, #8\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjPaletteHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._19ObjPalettePoolOwner\n"
    "cmp r6, r4\n"
    "bne .Lshop_common_0454\n"
    ".Lshop_common_046a:\n"
    "movs r1, #0xe9\n"
    "lsls r1, r1, #2\n"
    "adds r0, r5, r1\n"
    "adds r7, r5, #0\n"
    "adds r7, #0x20\n"
    "movs r2, #0x24\n"
    "adds r2, r2, r5\n"
    "mov r8, r2\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_04a2\n"
    "adds r1, #0x48\n"
    "adds r4, r5, r1\n"
    "cmp r0, r4\n"
    "beq .Lshop_common_04a2\n"
    "movs r2, #0xe9\n"
    "lsls r2, r2, #2\n"
    "adds r6, r5, r2\n"
    ".Lshop_common_048c:\n"
    "subs r4, #8\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjTileHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._16ObjTilePoolOwner\n"
    "cmp r6, r4\n"
    "bne .Lshop_common_048c\n"
    ".Lshop_common_04a2:\n"
    "movs r0, #0xe7\n"
    "lsls r0, r0, #2\n"
    "adds r4, r5, r0\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjPaletteHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._19ObjPalettePoolOwner\n"
    "movs r1, #0xe5\n"
    "lsls r1, r1, #2\n"
    "adds r4, r5, r1\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjTileHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._16ObjTilePoolOwner\n"
    "movs r2, #0xe3\n"
    "lsls r2, r2, #2\n"
    "adds r4, r5, r2\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjTileHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._16ObjTilePoolOwner\n"
    "movs r0, #0xe1\n"
    "lsls r0, r0, #2\n"
    "adds r4, r5, r0\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjPaletteHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._19ObjPalettePoolOwner\n"
    "movs r1, #0xdf\n"
    "lsls r1, r1, #2\n"
    "adds r4, r5, r1\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjTileHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._16ObjTilePoolOwner\n"
    "movs r2, #0xdd\n"
    "lsls r2, r2, #2\n"
    "adds r4, r5, r2\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjTileHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._16ObjTilePoolOwner\n"
    "movs r0, #0xdb\n"
    "lsls r0, r0, #2\n"
    "adds r4, r5, r0\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjPaletteHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._19ObjPalettePoolOwner\n"
    "movs r1, #0xd9\n"
    "lsls r1, r1, #2\n"
    "adds r4, r5, r1\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjTileHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._16ObjTilePoolOwner\n"
    "movs r2, #0xd7\n"
    "lsls r2, r2, #2\n"
    "adds r4, r5, r2\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjPaletteHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._19ObjPalettePoolOwner\n"
    "movs r0, #0xd5\n"
    "lsls r0, r0, #2\n"
    "adds r4, r5, r0\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl ReleaseObjTileHandle\n"
    "adds r0, r4, #0\n"
    "movs r1, #2\n"
    "bl _._16ObjTilePoolOwner\n"
    "movs r1, #0xd2\n"
    "lsls r1, r1, #2\n"
    "adds r0, r5, r1\n"
    "movs r1, #2\n"
    "bl _._12UiStateOwner\n"
    "ldr r0, [r5, #0x20]\n"
    "lsls r0, r0, #4\n"
    "adds r0, #4\n"
    "adds r1, r7, r0\n"
    "mov r0, r8\n"
    "cmp r0, r1\n"
    "beq .Lshop_common_059e\n"
    ".Lshop_common_0598:\n"
    "adds r0, #0x10\n"
    "cmp r0, r1\n"
    "bne .Lshop_common_0598\n"
    ".Lshop_common_059e:\n"
    "ldr r0, [r5, #0x1c]\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_05d0\n"
    "adds r4, r0, #0\n"
    "adds r0, #0x28\n"
    "movs r1, #2\n"
    "bl _._25ScrollBufferUploadCommand\n"
    "adds r0, r4, #0\n"
    "adds r0, #0x18\n"
    "ldr r2, [r0, #4]\n"
    "ldr r1, [r4, #0x18]\n"
    "cmp r1, r2\n"
    "beq .Lshop_common_05c0\n"
    ".Lshop_common_05ba:\n"
    "adds r1, #0x40\n"
    "cmp r1, r2\n"
    "bne .Lshop_common_05ba\n"
    ".Lshop_common_05c0:\n"
    "ldr r0, [r0]\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_05ca\n"
    "bl free\n"
    ".Lshop_common_05ca:\n"
    "adds r0, r4, #0\n"
    "bl __builtin_delete\n"
    ".Lshop_common_05d0:\n"
    "adds r0, r5, #0\n"
    "mov r1, sb\n"
    "bl _._15HardwareContext\n"
    "pop {r3, r4}\n"
    "mov r8, r3\n"
    "mov sb, r4\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r0}\n"
    "bx r0\n"
#if defined(REGION_JP)
    ".Lshop_common_05e4: .word __vt_14ShopScreenCore\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".align 2, 0\n"
    ".Lshop_common_05e4: .word __vt_14ShopScreenCore\n"
#endif
    ".Lshop_common_05e8: .word 0x434\n"
    ".Lshop_common_05ec: .word 0x534\n"
    ".Lshop_common_05f0: .word __vt_23IndexedResourceProvider\n"
    ".Lshop_common_05f4: .word 0x504\n"
);

void DrawShopMoney(ShopScreenCore * shop)
{
    FillHardwareDma3(0x3FF03FF,
        reinterpret_cast<void *>(VRAM + 0xFF8A), 0x28);
    FillHardwareDma3(0x3FF03FF,
        reinterpret_cast<void *>(VRAM + 0xFFCA), 0x28);

    u32 const balance = shop->save->money_account.balance;

#if defined(REGION_JP)
    DrawDecimalTo2x2Tilemap(balance,
        reinterpret_cast<u16 *>(VRAM + 0xFFB2), 0xA0, 0, 0x20);
#else
    DrawDecimalTo1x2Tilemap(balance,
        reinterpret_cast<u16 *>(VRAM + 0xFFB2), 0xA0, 0, 0x20);
#endif
}

asm_unified(
    "    .align 2, 0\n"
    "thumb_func_start InitializeShopScreenDisplay\n"
    "InitializeShopScreenDisplay:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "mov r7, sl\n"
    "mov r6, sb\n"
    "mov r5, r8\n"
    "push {r5, r6, r7}\n"
#if defined(REGION_JP)
    "sub sp, #384\n"
    "mov sl, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "sub sp, #324\n"
    "adds r7, r0, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "add r2, sp, #12\n"
    "movs r3, #226\n"
    "lsls r3, r3, #5\n"
    "adds r1, r3, #0\n"
    "strh r1, [r2, #0]\n"
    "strh r1, [r0, #8]\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "add r2, sp, #12\n"
#if defined(REGION_JP)
    "ldr r4, .Lshop_common_085c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, .Lshop_common_0858\n"
#endif
    "adds r1, r4, #0\n"
    "strh r1, [r2, #0]\n"
    "strh r1, [r0, #10]\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "add r2, sp, #12\n"
#if defined(REGION_JP)
    "ldr r5, .Lshop_common_0860\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, .Lshop_common_085c\n"
#endif
    "adds r1, r5, #0\n"
    "strh r1, [r2, #0]\n"
    "strh r1, [r0, #12]\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "add r2, sp, #12\n"
#if defined(REGION_JP)
    "movs r7, #250\n"
    "lsls r7, r7, #5\n"
    "adds r1, r7, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r6, #250\n"
    "lsls r6, r6, #5\n"
    "adds r1, r6, #0\n"
#endif
    "strh r1, [r2, #0]\n"
    "strh r1, [r0, #14]\n"
    "movs r4, #1\n"
    "negs r4, r4\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0864\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_0860\n"
#endif
    "mov sb, r0\n"
    "movs r5, #128\n"
    "lsls r5, r5, #4\n"
    "adds r0, r4, #0\n"
    "mov r1, sb\n"
    "adds r2, r5, #0\n"
    "bl FillHardwareDma3\n"
#if defined(REGION_JP)
    "ldr r6, .Lshop_common_0868\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r6, .Lshop_common_0864\n"
#endif
    "adds r0, r4, #0\n"
    "adds r1, r6, #0\n"
    "adds r2, r5, #0\n"
    "bl FillHardwareDma3\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_086c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_0868\n"
#endif
    "adds r0, r4, #0\n"
    "adds r2, r5, #0\n"
    "bl FillHardwareDma3\n"
    "movs r1, #192\n"
    "lsls r1, r1, #19\n"
    "mov r8, r1\n"
    "movs r2, #128\n"
    "lsls r2, r2, #8\n"
    "movs r0, #0\n"
    "bl FillHardwareDma3\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "add r1, sp, #12\n"
    "movs r3, #242\n"
    "lsls r3, r3, #5\n"
    "adds r2, r3, #0\n"
    "strh r2, [r1, #0]\n"
    "movs r4, #0\n"
    "strh r2, [r0, #0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0870\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_086c\n"
#endif
    "ldr r0, [r0, #0]\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_0874\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_0870\n"
#endif
    "ldr r2, [r1, #0]\n"
    "mov r1, r8\n"
    "bl CopyHardwareDma3\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0878\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_0874\n"
#endif
    "adds r1, r6, #0\n"
    "adds r2, r5, #0\n"
    "bl FillHardwareDma3\n"
    "movs r0, #3\n"
    "str r0, [sp, #0]\n"
    "str r4, [sp, #4]\n"
    "str r4, [sp, #8]\n"
    "adds r0, r6, #0\n"
    "movs r1, #0\n"
    "movs r2, #0\n"
    "movs r3, #30\n"
    "bl DrawUiTextWindowBorder\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_087c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_0878\n"
#endif
    "ldr r0, [r0, #0]\n"
    "movs r1, #160\n"
    "lsls r1, r1, #19\n"
    "movs r2, #32\n"
    "bl CopyHardwareDma3\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0880\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_087c\n"
#endif
    "mov r1, sb\n"
    "adds r2, r5, #0\n"
    "bl FillHardwareDma3\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "add r2, sp, #12\n"
#if defined(REGION_JP)
    "ldr r4, .Lshop_common_0884\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, .Lshop_common_0880\n"
#endif
    "adds r1, r4, #0\n"
    "strh r1, [r2, #0]\n"
    "strh r1, [r0, #30]\n"
    "movs r5, #0\n"
#if defined(REGION_JP)
    "mov sb, r5\n"
    "movs r7, #130\n"
    "lsls r7, r7, #1\n"
    "add r7, sp\n"
    "mov r8, r7\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sl, r5\n"
    "add r6, sp, #196\n"
    "mov r8, r6\n"
#endif
    "mov r0, sp\n"
    "adds r0, #20\n"
#if defined(REGION_JP)
    "str r0, [sp, #320]\n"
    "movs r1, #132\n"
    "lsls r1, r1, #1\n"
    "add r1, sp\n"
    "str r1, [sp, #360]\n"
    "movs r2, #134\n"
    "lsls r2, r2, #1\n"
    "add r2, sp\n"
    "str r2, [sp, #364]\n"
    "mov r3, sp\n"
    "adds r3, #148\n"
    "str r3, [sp, #328]\n"
    "mov r4, sp\n"
    "adds r4, #164\n"
    "str r4, [sp, #332]\n"
    "mov r5, sp\n"
    "adds r5, #180\n"
    "str r5, [sp, #336]\n"
    "mov r7, sp\n"
    "adds r7, #196\n"
    "str r7, [sp, #344]\n"
    "adds r0, #192\n"
    "str r0, [sp, #348]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [sp, #304]\n"
#endif
    "mov r1, sp\n"
#if defined(REGION_JP)
    "adds r1, #228\n"
    "str r1, [sp, #352]\n"
    "mov r2, sp\n"
    "adds r2, #244\n"
    "str r2, [sp, #356]\n"
    "ldr r5, .Lshop_common_0888\n"
    "movs r7, #2\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r1, #200\n"
    "str r1, [sp, #284]\n"
    "adds r2, #192\n"
    "str r2, [sp, #288]\n"
    "mov r3, sp\n"
    "adds r3, #84\n"
    "str r3, [sp, #256]\n"
    "mov r4, sp\n"
    "adds r4, #100\n"
    "str r4, [sp, #260]\n"
    "mov r5, sp\n"
    "adds r5, #116\n"
    "str r5, [sp, #264]\n"
    "mov r6, sp\n"
    "adds r6, #132\n"
    "str r6, [sp, #268]\n"
    "adds r0, #128\n"
    "str r0, [sp, #272]\n"
    "subs r1, #36\n"
    "str r1, [sp, #276]\n"
    "subs r2, #24\n"
    "str r2, [sp, #280]\n"
    "movs r3, #1\n"
    "mov sb, r3\n"
    "ldr r5, .Lshop_common_0884\n"
#endif
    "mov r6, r8\n"
#if defined(REGION_JP)
    "ldr r4, .Lshop_common_088c\n"
    ".Lshop_common_078e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, .Lshop_common_0888\n"
    ".Lshop_common_0782:\n"
#endif
    "ldrh r1, [r4, #0]\n"
#if defined(REGION_JP)
    "strh r7, [r6, #0]\n"
    "mov r3, r8\n"
    "strh r7, [r3, #2]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r0, sb\n"
    "strh r0, [r6, #0]\n"
    "movs r3, #2\n"
    "mov r2, r8\n"
    "strh r3, [r2, #2]\n"
#endif
    "ldr r0, [r6, #0]\n"
    "str r1, [sp, #0]\n"
    "movs r1, #0\n"
    "str r1, [sp, #4]\n"
#if defined(REGION_JP)
    "movs r2, #1\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r2, sb\n"
#endif
    "str r2, [sp, #8]\n"
    "add r1, sp, #20\n"
    "movs r2, #0\n"
    "movs r3, #0\n"
    "bl DrawCharacterGlyphTo2DGfxBufferExt\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #320]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [sp, #304]\n"
#endif
    "adds r1, r5, #0\n"
#if defined(REGION_JP)
    "movs r2, #128\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r2, #64\n"
#endif
    "bl CopyHardwareDma3\n"
#if defined(REGION_JP)
    "adds r5, #128\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r5, #64\n"
#endif
    "adds r4, #2\n"
    "movs r3, #1\n"
#if defined(REGION_JP)
    "add sb, r3\n"
    "mov r0, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add sl, r3\n"
    "mov r0, sl\n"
#endif
    "cmp r0, #9\n"
#if defined(REGION_JP)
    "ble .Lshop_common_078e\n"
    "movs r0, #210\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_0782\n"
    "movs r1, #210\n"
    "lsls r1, r1, #2\n"
    "adds r0, r7, r1\n"
#endif
    "bl func_08050D5C\n"
    "movs r4, #2\n"
    "movs r6, #0\n"
#if defined(REGION_JP)
    "add r0, sp, #264\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #200\n"
#endif
    "strh r4, [r0, #0]\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #360]\n"
    "strh r4, [r1, #2]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, [sp, #284]\n"
    "strh r4, [r2, #2]\n"
#endif
    "ldr r0, [r0, #0]\n"
#if defined(REGION_JP)
    "ldr r5, .Lshop_common_0890\n"
    "add r5, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r3, .Lshop_common_088c\n"
    "adds r5, r7, r3\n"
#endif
    "adds r1, r5, #0\n"
    "movs r2, #0\n"
    "bl Clear2DGfxBuffer\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_0894\n"
    "movs r2, #1\n"
    "mov r8, r2\n"
    "add r0, sp, #268\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_0890\n"
    "movs r0, #1\n"
    "mov sb, r0\n"
    "add r0, sp, #204\n"
#endif
    "strh r4, [r0, #0]\n"
#if defined(REGION_JP)
    "ldr r3, [sp, #364]\n"
    "strh r4, [r3, #2]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, [sp, #288]\n"
    "strh r4, [r2, #2]\n"
#endif
    "ldr r0, [r0, #0]\n"
    "str r1, [sp, #0]\n"
    "str r6, [sp, #4]\n"
#if defined(REGION_JP)
    "str r2, [sp, #8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r3, sb\n"
    "str r3, [sp, #8]\n"
#endif
    "adds r1, r5, #0\n"
    "movs r2, #0\n"
    "movs r3, #0\n"
    "bl DrawStringTo2DGfxBufferExt\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDmaQueue\n"
#if defined(REGION_JP)
    "adds r6, r0, #0\n"
    "add r0, sp, #148\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [sp, #312]\n"
    "add r0, sp, #84\n"
#endif
    "adds r1, r5, #0\n"
#if defined(REGION_JP)
    "ldr r2, .Lshop_common_0898\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, .Lshop_common_0894\n"
#endif
    "movs r3, #128\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "ldr r4, [sp, #328]\n"
    "mov sb, r4\n"
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #12]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, [sp, #256]\n"
    "mov sl, r4\n"
    "ldr r5, [sp, #312]\n"
    "ldr r1, [r5, #4]\n"
    "ldr r0, [r5, #12]\n"
#endif
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_08a4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_08a0\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0838\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0834\n"
#endif
    "adds r0, r1, #0\n"
    "adds r1, r4, #0\n"
#if defined(REGION_JP)
    "ldmia r1!, {r2, r5, r7}\n"
    "stmia r0!, {r2, r5, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldmia r1!, {r2, r3, r6}\n"
    "stmia r0!, {r2, r3, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0838:\n"
    "ldr r0, [r6, #4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0834:\n"
    "ldr r4, [sp, #312]\n"
    "ldr r0, [r4, #4]\n"
#endif
    "adds r0, #16\n"
#if defined(REGION_JP)
    "str r0, [r6, #4]\n"
    "mov r3, sl\n"
    "adds r3, #28\n"
    "str r3, [sp, #324]\n"
    "movs r4, #202\n"
    "lsls r4, r4, #3\n"
    "add r4, sl\n"
    "str r4, [sp, #372]\n"
    "ldr r5, .Lshop_common_089c\n"
    "add r5, sl\n"
    "str r5, [sp, #340]\n"
    "ldr r7, .Lshop_common_08a0\n"
    "add r7, sl\n"
    "str r7, [sp, #368]\n"
    "b .Lshop_common_0996\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [r4, #4]\n"
    "adds r5, r7, #0\n"
    "adds r5, #28\n"
    "str r5, [sp, #308]\n"
    "movs r6, #202\n"
    "lsls r6, r6, #3\n"
    "adds r6, r7, r6\n"
    "str r6, [sp, #300]\n"
    "ldr r0, .Lshop_common_0898\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #292]\n"
    "ldr r1, .Lshop_common_089c\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #296]\n"
    "b .Lshop_common_0994\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_085c: .word 0x1d42\n"
    ".Lshop_common_0860: .word 0x3e41\n"
    ".Lshop_common_0864: .word VRAM + 0xe800\n"
    ".Lshop_common_0868: .word VRAM + 0xf000\n"
    ".Lshop_common_086c: .word VRAM + 0xf800\n"
    ".Lshop_common_0870: .word gUiSharedTiles\n"
    ".Lshop_common_0874: .word gUiSharedTileByteCount\n"
    ".Lshop_common_0878: .word 0x30003\n"
    ".Lshop_common_087c: .word gUiSharedPalette\n"
    ".Lshop_common_0880: .word 0x3ff03ff\n"
    ".Lshop_common_0884: .word 0x1eb\n"
    ".Lshop_common_0888: .word VRAM + 0x1400\n"
    ".Lshop_common_088c: .word gShopDigitGlyphs\n"
    ".Lshop_common_0890: .word 0x454\n"
    ".Lshop_common_0894: .word gText_ShopCommon_GoldUnit\n"
    ".Lshop_common_0898: .word VRAM + 0x400\n"
    ".Lshop_common_089c: .word 0x56c\n"
    ".Lshop_common_08a0: .word 0x5dc\n"
    ".Lshop_common_08a4:\n"
    "str r1, [sp, #376]\n"
    "add r1, sp, #276\n"
    "mov r0, r8\n"
    "str r0, [r1, #0]\n"
    "ldr r0, [r6, #0]\n"
    "ldr r2, [sp, #376]\n"
    "subs r0, r2, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0858: .word 0x1d42\n"
    ".Lshop_common_085c: .word 0x3e41\n"
    ".Lshop_common_0860: .word VRAM + 0xe800\n"
    ".Lshop_common_0864: .word VRAM + 0xf000\n"
    ".Lshop_common_0868: .word VRAM + 0xf800\n"
    ".Lshop_common_086c: .word gUiSharedTiles\n"
    ".Lshop_common_0870: .word gUiSharedTileByteCount\n"
    ".Lshop_common_0874: .word 0x30003\n"
    ".Lshop_common_0878: .word gUiSharedPalette\n"
    ".Lshop_common_087c: .word 0x3ff03ff\n"
    ".Lshop_common_0880: .word 0x1eb\n"
    ".Lshop_common_0884: .word VRAM + 0x1400\n"
    ".Lshop_common_0888: .word gShopDigitGlyphs\n"
    ".Lshop_common_088c: .word 0x454\n"
    ".Lshop_common_0890: .word gText_ShopCommon_GoldUnit\n"
    ".Lshop_common_0894: .word VRAM + 0x400\n"
    ".Lshop_common_0898: .word 0x56c\n"
    ".Lshop_common_089c: .word 0x5dc\n"
    ".Lshop_common_08a0:\n"
    "mov r8, r1\n"
    "add r1, sp, #212\n"
    "mov r2, sb\n"
    "str r2, [r1, #0]\n"
    "ldr r3, [sp, #312]\n"
    "ldr r0, [r3, #0]\n"
    "mov r4, r8\n"
    "subs r0, r4, r0\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "add r0, sp, #272\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #208\n"
#endif
    "str r4, [r0, #0]\n"
#if defined(REGION_JP)
    "adds r2, r1, #0\n"
    "ldr r0, [r1, #0]\n"
    "add r1, sp, #272\n"
    "cmp r4, r0\n"
    "bhs .Lshop_common_08c4\n"
    "adds r1, r2, #0\n"
    ".Lshop_common_08c4:\n"
    "ldr r0, [r1, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, [r1, #0]\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_08be\n"
    "adds r0, r1, #0\n"
    ".Lshop_common_08be:\n"
    "ldr r0, [r0, #0]\n"
#endif
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_08e2\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_08dc\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_08e6\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_08e0\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_08e6\n"
    ".Lshop_common_08e2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_08e0\n"
    ".Lshop_common_08dc:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_08e6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_08e0:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #380]\n"
    "ldr r2, [r6, #0]\n"
    "adds r3, r5, #0\n"
    "mov r4, sl\n"
    "adds r4, #28\n"
    "str r4, [sp, #324]\n"
    "movs r5, #202\n"
    "lsls r5, r5, #3\n"
    "add r5, sl\n"
    "str r5, [sp, #372]\n"
    "ldr r7, .Lshop_common_0948\n"
    "add r7, sl\n"
    "str r7, [sp, #340]\n"
    "ldr r0, .Lshop_common_094c\n"
    "add r0, sl\n"
    "str r0, [sp, #368]\n"
    "ldr r1, [sp, #376]\n"
    "cmp r2, r1\n"
    "beq .Lshop_common_0928\n"
    ".Lshop_common_090e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #316]\n"
    "ldr r5, [sp, #312]\n"
    "ldr r2, [r5, #0]\n"
    "ldr r3, [sp, #316]\n"
    "adds r6, r7, #0\n"
    "adds r6, #28\n"
    "str r6, [sp, #308]\n"
    "movs r0, #202\n"
    "lsls r0, r0, #3\n"
    "adds r0, r7, r0\n"
    "str r0, [sp, #300]\n"
    "ldr r1, .Lshop_common_093c\n"
    "adds r1, r7, r1\n"
    "str r1, [sp, #292]\n"
    "ldr r4, .Lshop_common_0940\n"
    "adds r4, r7, r4\n"
    "str r4, [sp, #296]\n"
    "cmp r2, r8\n"
    "beq .Lshop_common_0920\n"
    ".Lshop_common_0908:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_091e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0918\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
#if defined(REGION_JP)
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldmia r1!, {r4, r5, r6}\n"
    "stmia r0!, {r4, r5, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_091e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0918:\n"
#endif
    "adds r2, #16\n"
    "adds r3, #16\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #376]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_090e\n"
    ".Lshop_common_0928:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "cmp r2, r8\n"
    "bne .Lshop_common_0908\n"
    ".Lshop_common_0920:\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "add r0, sp, #276\n"
    "ldr r0, [r0, #0]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_0950\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #212]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_0944\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0942\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0938\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, sl\n"
    "ldmia r1!, {r2, r3, r6}\n"
    "stmia r0!, {r2, r3, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0942:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0938:\n"
#endif
    "adds r5, #16\n"
#if defined(REGION_JP)
    "b .Lshop_common_0972\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_096c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_0948: .word 0x56c\n"
    ".Lshop_common_094c: .word 0x5dc\n"
    ".Lshop_common_0950:\n"
    "adds r3, r0, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_093c: .word 0x56c\n"
    ".Lshop_common_0940: .word 0x5dc\n"
    ".Lshop_common_0944:\n"
    "mov r8, r1\n"
#endif
    "adds r2, r5, #0\n"
#if defined(REGION_JP)
    "cmp r3, #0\n"
    "beq .Lshop_common_0970\n"
    ".Lshop_common_0958:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "cmp r1, #0\n"
    "beq .Lshop_common_096a\n"
    ".Lshop_common_094c:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0968\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_095c\n"
#endif
    "adds r0, r2, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, sl\n"
    "ldmia r1!, {r4, r5, r6}\n"
    "stmia r0!, {r4, r5, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0968:\n"
    "subs r3, #1\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_095c:\n"
    "movs r0, #1\n"
    "negs r0, r0\n"
    "add r8, r0\n"
#endif
    "adds r2, #16\n"
#if defined(REGION_JP)
    "cmp r3, #0\n"
    "bne .Lshop_common_0958\n"
    ".Lshop_common_0970:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
    "cmp r1, #0\n"
    "bne .Lshop_common_094c\n"
    ".Lshop_common_096a:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_0972:\n"
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_096c:\n"
    "ldr r3, [sp, #312]\n"
    "ldr r2, [r3, #4]\n"
    "ldr r0, [r3, #0]\n"
#endif
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0982\n"
    ".Lshop_common_097c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_097e\n"
    ".Lshop_common_0978:\n"
#endif
    "adds r1, #16\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_097c\n"
    ".Lshop_common_0982:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_0978\n"
    ".Lshop_common_097e:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_098a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0986\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_098a:\n"
    "ldr r0, [sp, #380]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #380]\n"
    "str r7, [r6, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0986:\n"
    "ldr r0, [sp, #316]\n"
    "add r0, sb\n"
    "ldr r4, [sp, #316]\n"
    "ldr r6, [sp, #312]\n"
    "str r4, [r6, #0]\n"
#endif
    "str r5, [r6, #4]\n"
    "str r0, [r6, #12]\n"
#if defined(REGION_JP)
    ".Lshop_common_0996:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0994:\n"
#endif
    "ldr r0, .Lshop_common_09fc\n"
    "movs r1, #0\n"
    "str r1, [sp, #0]\n"
    "movs r1, #32\n"
    "str r1, [sp, #4]\n"
    "movs r2, #2\n"
    "movs r3, #2\n"
    "bl Fill2DGfxTilemapRect\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl DrawShopMoney\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
#if defined(REGION_JP)
    "movs r0, #213\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r1, #213\n"
    "lsls r1, r1, #2\n"
    "adds r0, r7, r1\n"
#endif
    "ldr r1, [r0, #4]\n"
    "bl GetObjTileIndex\n"
    "adds r2, r0, #0\n"
#if defined(REGION_JP)
    "adds r6, r4, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r4, [sp, #312]\n"
#endif
    "ldr r1, .Lshop_common_0a00\n"
    "lsls r2, r2, #5\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0a04\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #148\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r3, .Lshop_common_0a04\n"
    "adds r2, r2, r3\n"
    "add r0, sp, #84\n"
#endif
    "movs r3, #128\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #328]\n"
    "mov sb, r1\n"
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #12]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, [sp, #256]\n"
    "mov sl, r4\n"
    "ldr r5, [sp, #312]\n"
    "ldr r1, [r5, #4]\n"
    "ldr r0, [r5, #12]\n"
#endif
    "cmp r1, r0\n"
    "beq .Lshop_common_0a08\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_09f2\n"
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #328]\n"
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r1, r4, #0\n"
    "ldmia r1!, {r2, r3, r6}\n"
    "stmia r0!, {r2, r3, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_09f2:\n"
#if defined(REGION_JP)
    "ldr r0, [r6, #4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, [sp, #312]\n"
    "ldr r0, [r4, #4]\n"
#endif
    "adds r0, #16\n"
#if defined(REGION_JP)
    "str r0, [r6, #4]\n"
    "b .Lshop_common_0ad6\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [r4, #4]\n"
    "b .Lshop_common_0ada\n"
#endif
    ".align 2, 0\n"
    ".Lshop_common_09fc: .word VRAM + 0xffb4\n"
    ".Lshop_common_0a00: .word gFarmStatusCreatureIcon11Tiles\n"
    ".Lshop_common_0a04: .word OBJ_VRAM0\n"
    ".Lshop_common_0a08:\n"
#if defined(REGION_JP)
    "str r1, [sp, #376]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r8, r1\n"
#endif
    "movs r0, #1\n"
#if defined(REGION_JP)
    "add r1, sp, #284\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #220\n"
#endif
    "str r0, [r1, #0]\n"
#if defined(REGION_JP)
    "ldr r0, [r6, #0]\n"
    "ldr r5, [sp, #376]\n"
    "subs r0, r5, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, [sp, #312]\n"
    "ldr r0, [r5, #0]\n"
    "mov r6, r8\n"
    "subs r0, r6, r0\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "add r0, sp, #280\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #216\n"
#endif
    "str r4, [r0, #0]\n"
#if defined(REGION_JP)
    "adds r2, r1, #0\n"
    "ldr r0, [r1, #0]\n"
    "add r1, sp, #280\n"
    "cmp r4, r0\n"
    "bhs .Lshop_common_0a28\n"
    "adds r1, r2, #0\n"
    ".Lshop_common_0a28:\n"
    "ldr r0, [r1, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, [r1, #0]\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_0a26\n"
    "adds r0, r1, #0\n"
    ".Lshop_common_0a26:\n"
    "ldr r0, [r0, #0]\n"
#endif
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0a46\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0a44\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_0a4a\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_0a48\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_0a4a\n"
    ".Lshop_common_0a46:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_0a48\n"
    ".Lshop_common_0a44:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_0a4a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_0a48:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #380]\n"
    "ldr r2, [r6, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #316]\n"
    "ldr r0, [sp, #312]\n"
    "ldr r2, [r0, #0]\n"
#endif
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #376]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_0a72\n"
    ".Lshop_common_0a58:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "cmp r2, r8\n"
    "beq .Lshop_common_0a6e\n"
    ".Lshop_common_0a56:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0a68\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0a66\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
#if defined(REGION_JP)
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldmia r1!, {r4, r5, r6}\n"
    "stmia r0!, {r4, r5, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0a68:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0a66:\n"
#endif
    "adds r2, #16\n"
    "adds r3, #16\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #376]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_0a58\n"
    ".Lshop_common_0a72:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "cmp r2, r8\n"
    "bne .Lshop_common_0a56\n"
    ".Lshop_common_0a6e:\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "add r0, sp, #284\n"
    "ldr r0, [r0, #0]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_0a90\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #220]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_0a8a\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0a8c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0a86\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, sl\n"
#endif
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0a8c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0a86:\n"
#endif
    "adds r5, #16\n"
    "b .Lshop_common_0ab2\n"
#if defined(REGION_JP)
    ".Lshop_common_0a90:\n"
    "adds r3, r0, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0a8a:\n"
    "mov r8, r1\n"
#endif
    "adds r2, r5, #0\n"
#if defined(REGION_JP)
    "cmp r3, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "cmp r1, #0\n"
#endif
    "beq .Lshop_common_0ab0\n"
#if defined(REGION_JP)
    ".Lshop_common_0a98:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0a92:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0aa8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0aa2\n"
#endif
    "adds r0, r2, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, sl\n"
    "ldmia r1!, {r3, r5, r6}\n"
    "stmia r0!, {r3, r5, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0aa8:\n"
    "subs r3, #1\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0aa2:\n"
    "movs r4, #1\n"
    "negs r4, r4\n"
    "add r8, r4\n"
#endif
    "adds r2, #16\n"
#if defined(REGION_JP)
    "cmp r3, #0\n"
    "bne .Lshop_common_0a98\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r5, r8\n"
    "cmp r5, #0\n"
    "bne .Lshop_common_0a92\n"
#endif
    ".Lshop_common_0ab0:\n"
    "adds r5, r2, #0\n"
    ".Lshop_common_0ab2:\n"
#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r6, [sp, #312]\n"
#endif
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6, #0]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0ac2\n"
    ".Lshop_common_0abc:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0ac4\n"
    ".Lshop_common_0abe:\n"
#endif
    "adds r1, #16\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_0abc\n"
    ".Lshop_common_0ac2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_0abe\n"
    ".Lshop_common_0ac4:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0aca\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0acc\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_0aca:\n"
    "ldr r0, [sp, #380]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #380]\n"
    "str r7, [r6, #0]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #12]\n"
    ".Lshop_common_0ad6:\n"
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0acc:\n"
    "ldr r0, [sp, #316]\n"
    "add r0, sb\n"
    "ldr r1, [sp, #316]\n"
    "ldr r2, [sp, #312]\n"
    "str r1, [r2, #0]\n"
    "str r5, [r2, #4]\n"
    "str r0, [r2, #12]\n"
    ".Lshop_common_0ada:\n"
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
#if defined(REGION_JP)
    "movs r0, #215\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r3, #215\n"
    "lsls r3, r3, #2\n"
    "adds r0, r7, r3\n"
#endif
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "adds r2, r0, #0\n"
#if defined(REGION_JP)
    "adds r6, r4, #0\n"
    "ldr r1, .Lshop_common_0b24\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r4, [sp, #312]\n"
    "ldr r1, .Lshop_common_0b2c\n"
#endif
    "lsls r2, r2, #5\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0b28\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #148\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, .Lshop_common_0b30\n"
    "adds r2, r2, r4\n"
    "add r0, sp, #84\n"
#endif
    "movs r3, #32\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #328]\n"
    "mov sb, r1\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, [sp, #256]\n"
    "mov sl, r5\n"
    "ldr r6, [sp, #312]\n"
#endif
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #12]\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0b2c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0b34\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0b1a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0b20\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #328]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r1, r5, #0\n"
#endif
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0b1a:\n"
    "ldr r0, [r6, #4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0b20:\n"
    "ldr r5, [sp, #312]\n"
    "ldr r0, [r5, #4]\n"
#endif
    "adds r0, #16\n"
#if defined(REGION_JP)
    "str r0, [r6, #4]\n"
    "b .Lshop_common_0bfa\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [r5, #4]\n"
    "b .Lshop_common_0c06\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_0b24: .word gFarmStatusCreatureIcon11Palette\n"
    ".Lshop_common_0b28: .word OBJ_PLTT\n"
    ".Lshop_common_0b2c:\n"
    "str r1, [sp, #376]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0b2c: .word gFarmStatusCreatureIcon11Palette\n"
    ".Lshop_common_0b30: .word OBJ_PLTT\n"
    ".Lshop_common_0b34:\n"
    "mov r8, r1\n"
#endif
    "movs r0, #1\n"
#if defined(REGION_JP)
    "add r1, sp, #292\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #228\n"
#endif
    "str r0, [r1, #0]\n"
#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r6, [sp, #312]\n"
#endif
    "ldr r0, [r6, #0]\n"
#if defined(REGION_JP)
    "ldr r5, [sp, #376]\n"
    "subs r0, r5, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r2, r8\n"
    "subs r0, r2, r0\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "add r0, sp, #288\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #224\n"
#endif
    "str r4, [r0, #0]\n"
#if defined(REGION_JP)
    "adds r2, r1, #0\n"
    "ldr r0, [r1, #0]\n"
    "add r1, sp, #288\n"
    "cmp r4, r0\n"
    "bhs .Lshop_common_0b4c\n"
    "adds r1, r2, #0\n"
    ".Lshop_common_0b4c:\n"
    "ldr r0, [r1, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, [r1, #0]\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_0b52\n"
    "adds r0, r1, #0\n"
    ".Lshop_common_0b52:\n"
    "ldr r0, [r0, #0]\n"
#endif
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0b6a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0b70\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_0b6e\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_0b74\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_0b6e\n"
    ".Lshop_common_0b6a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_0b74\n"
    ".Lshop_common_0b70:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_0b6e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_0b74:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #380]\n"
    "ldr r2, [r6, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #316]\n"
    "ldr r3, [sp, #312]\n"
    "ldr r2, [r3, #0]\n"
#endif
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #376]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_0b96\n"
    ".Lshop_common_0b7c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "cmp r2, r8\n"
    "beq .Lshop_common_0b9a\n"
    ".Lshop_common_0b82:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0b8c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0b92\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
#if defined(REGION_JP)
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldmia r1!, {r4, r5, r6}\n"
    "stmia r0!, {r4, r5, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0b8c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0b92:\n"
#endif
    "adds r2, #16\n"
    "adds r3, #16\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #376]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_0b7c\n"
    ".Lshop_common_0b96:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "cmp r2, r8\n"
    "bne .Lshop_common_0b82\n"
    ".Lshop_common_0b9a:\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "add r0, sp, #292\n"
    "ldr r0, [r0, #0]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_0bb4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #228]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_0bb6\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0bb0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0bb2\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, sl\n"
#endif
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0bb0:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0bb2:\n"
#endif
    "adds r5, #16\n"
#if defined(REGION_JP)
    "b .Lshop_common_0bd6\n"
    ".Lshop_common_0bb4:\n"
    "adds r3, r0, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_0bde\n"
    ".Lshop_common_0bb6:\n"
    "mov r8, r1\n"
#endif
    "adds r2, r5, #0\n"
#if defined(REGION_JP)
    "cmp r3, #0\n"
    "beq .Lshop_common_0bd4\n"
    ".Lshop_common_0bbc:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "cmp r1, #0\n"
    "beq .Lshop_common_0bdc\n"
    ".Lshop_common_0bbe:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0bcc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0bce\n"
#endif
    "adds r0, r2, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, sl\n"
    "ldmia r1!, {r3, r5, r6}\n"
    "stmia r0!, {r3, r5, r6}\n"
#endif
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0bcc:\n"
    "subs r3, #1\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0bce:\n"
    "movs r4, #1\n"
    "negs r4, r4\n"
    "add r8, r4\n"
#endif
    "adds r2, #16\n"
#if defined(REGION_JP)
    "cmp r3, #0\n"
    "bne .Lshop_common_0bbc\n"
    ".Lshop_common_0bd4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r5, r8\n"
    "cmp r5, #0\n"
    "bne .Lshop_common_0bbe\n"
    ".Lshop_common_0bdc:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_0bd6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0bde:\n"
    "ldr r6, [sp, #312]\n"
#endif
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6, #0]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0be6\n"
    ".Lshop_common_0be0:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0bf0\n"
    ".Lshop_common_0bea:\n"
#endif
    "adds r1, #16\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_0be0\n"
    ".Lshop_common_0be6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_0bea\n"
    ".Lshop_common_0bf0:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0bee\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0bf8\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_0bee:\n"
    "ldr r0, [sp, #380]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #380]\n"
    "str r7, [r6, #0]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #12]\n"
    ".Lshop_common_0bfa:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0bf8:\n"
    "ldr r0, [sp, #316]\n"
    "add r0, sb\n"
    "ldr r1, [sp, #316]\n"
    "ldr r2, [sp, #312]\n"
    "str r1, [r2, #0]\n"
    "str r5, [r2, #4]\n"
    "str r0, [r2, #12]\n"
    ".Lshop_common_0c06:\n"
#endif
    "movs r0, #76\n"
    "bl __builtin_new\n"
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareInterruptList\n"
    "adds r4, r0, #0\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "adds r3, r0, #0\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0d24\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_0d30\n"
#endif
    "str r0, [sp, #0]\n"
    "adds r0, r5, #0\n"
    "movs r1, #100\n"
    "adds r2, r4, #0\n"
    "bl __11ScrollStateUiP18HardwareLinkedListP20HardwareDisplayStatePUc\n"
#if defined(REGION_JP)
    "ldr r6, [sp, #324]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r6, [sp, #308]\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
    "ldr r4, [r0, #28]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, [r7, #28]\n"
#endif
    "cmp r5, r4\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0c5c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0c66\n"
#endif
    "cmp r4, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0c5c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0c66\n"
#endif
    "adds r0, r4, #0\n"
    "adds r0, #40\n"
    "movs r1, #2\n"
    "bl _._25ScrollBufferUploadCommand\n"
    "adds r0, r4, #0\n"
    "adds r0, #24\n"
    "ldr r2, [r0, #4]\n"
    "ldr r1, [r4, #24]\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0c4c\n"
    ".Lshop_common_0c46:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0c56\n"
    ".Lshop_common_0c50:\n"
#endif
    "adds r1, #64\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_0c46\n"
    ".Lshop_common_0c4c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_0c50\n"
    ".Lshop_common_0c56:\n"
#endif
    "ldr r0, [r0, #0]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0c56\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0c60\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_0c56:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0c60:\n"
#endif
    "adds r0, r4, #0\n"
    "bl __builtin_delete\n"
#if defined(REGION_JP)
    ".Lshop_common_0c5c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0c66:\n"
#endif
    "str r5, [r6, #0]\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "ldrh r1, [r0, #4]\n"
    "movs r2, #32\n"
    "orrs r1, r2\n"
    "strh r1, [r0, #4]\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDisplayState\n"
    "ldrh r1, [r0, #4]\n"
    "movs r3, #184\n"
    "lsls r3, r3, #5\n"
    "adds r2, r3, #0\n"
    "orrs r1, r2\n"
    "strh r1, [r0, #4]\n"
    "movs r0, #4\n"
    "bl AcknowledgeAndEnableInterrupts\n"
    "movs r0, #0\n"
    "movs r1, #4\n"
    "bl SetInterruptNestingMask\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_0d28\n"
    "add r1, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, .Lshop_common_0d34\n"
    "adds r1, r7, r4\n"
#endif
    "strh r0, [r1, #0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0d2c\n"
    "add r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, .Lshop_common_0d38\n"
    "adds r0, r7, r5\n"
#endif
    "movs r2, #232\n"
    "strh r2, [r0, #0]\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_0d30\n"
    "add r1, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r6, .Lshop_common_0d3c\n"
    "adds r1, r7, r6\n"
#endif
    "movs r0, #24\n"
    "strh r0, [r1, #0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0d34\n"
    "add r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_0d40\n"
    "adds r0, r7, r1\n"
#endif
    "strh r2, [r0, #0]\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_0d38\n"
    "add r1, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, .Lshop_common_0d44\n"
    "adds r1, r7, r2\n"
#endif
    "movs r0, #96\n"
    "strh r0, [r1, #0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0d3c\n"
    "add r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r3, .Lshop_common_0d48\n"
    "adds r0, r7, r3\n"
#endif
    "ldr r1, [r0, #0]\n"
    "ldr r3, [r1, #0]\n"
    "ldrh r2, [r0, #12]\n"
    "lsls r2, r2, #2\n"
#if defined(REGION_JP)
    "ldr r4, [sp, #372]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, [sp, #300]\n"
#endif
    "ldr r0, [r4, #0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0, #0]\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #332]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [sp, #260]\n"
#endif
    "ldr r3, [r3, #16]\n"
    "bl _call_via_r3\n"
#if defined(REGION_JP)
    "mov r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r7, #0\n"
#endif
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #336]\n"
    "ldr r5, [r7, #0]\n"
    "movs r0, #219\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, [sp, #116]\n"
    "movs r6, #219\n"
    "lsls r6, r6, #2\n"
    "adds r0, r7, r6\n"
#endif
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "adds r2, r0, #0\n"
#if defined(REGION_JP)
    "ldr r0, [r7, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [sp, #116]\n"
#endif
    "movs r3, #0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0cf0\n"
    "ldrh r3, [r7, #4]\n"
    ".Lshop_common_0cf0:\n"
    "adds r6, r4, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0cfa\n"
    "ldr r0, [sp, #264]\n"
    "ldrh r3, [r0, #4]\n"
    ".Lshop_common_0cfa:\n"
    "str r4, [sp, #312]\n"
#endif
    "lsls r2, r2, #5\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_0d40\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #148\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_0d4c\n"
    "adds r2, r2, r1\n"
    "add r0, sp, #84\n"
#endif
    "adds r1, r5, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #328]\n"
    "mov sb, r1\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, [sp, #256]\n"
    "mov sl, r2\n"
    "ldr r1, [r4, #4]\n"
    "ldr r0, [r4, #12]\n"
    "cmp r1, r0\n"
    "beq .Lshop_common_0d50\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_0d26\n"
    "adds r0, r1, #0\n"
    "adds r1, r2, #0\n"
    "ldmia r1!, {r3, r4, r5}\n"
    "stmia r0!, {r3, r4, r5}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0d26:\n"
    "ldr r6, [sp, #312]\n"
    "ldr r0, [r6, #4]\n"
    "adds r0, #16\n"
    "str r0, [r6, #4]\n"
    "b .Lshop_common_0e22\n"
    ".align 2, 0\n"
    ".Lshop_common_0d30: .word VRAM + 0xe800\n"
    ".Lshop_common_0d34: .word 0x434\n"
    ".Lshop_common_0d38: .word 0x564\n"
    ".Lshop_common_0d3c: .word 0x566\n"
    ".Lshop_common_0d40: .word 0x59c\n"
    ".Lshop_common_0d44: .word 0x59e\n"
    ".Lshop_common_0d48: .word 0x64c\n"
    ".Lshop_common_0d4c: .word OBJ_PLTT\n"
    ".Lshop_common_0d50:\n"
    "mov r8, r1\n"
    "movs r0, #1\n"
    "add r1, sp, #236\n"
    "str r0, [r1, #0]\n"
    "ldr r2, [sp, #312]\n"
    "ldr r0, [r2, #0]\n"
    "mov r3, r8\n"
    "subs r0, r3, r0\n"
    "asrs r4, r0, #4\n"
    "add r0, sp, #232\n"
    "str r4, [r0, #0]\n"
    "ldr r2, [r1, #0]\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_0d6e\n"
    "adds r0, r1, #0\n"
    ".Lshop_common_0d6e:\n"
    "ldr r0, [r0, #0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0d8c\n"
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
    "mov sb, r4\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_0d90\n"
    "mov r0, sb\n"
    "bl RetryMemoryAllocation\n"
    "b .Lshop_common_0d90\n"
    ".Lshop_common_0d8c:\n"
    "movs r0, #0\n"
    "mov sb, r0\n"
    ".Lshop_common_0d90:\n"
    "adds r5, r0, #0\n"
    "str r5, [sp, #316]\n"
    "ldr r4, [sp, #312]\n"
    "ldr r2, [r4, #0]\n"
    "adds r3, r5, #0\n"
    "cmp r2, r8\n"
    "beq .Lshop_common_0db6\n"
    ".Lshop_common_0d9e:\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_0dae\n"
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldmia r1!, {r4, r5, r6}\n"
    "stmia r0!, {r4, r5, r6}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0dae:\n"
    "adds r2, #16\n"
    "adds r3, #16\n"
    "cmp r2, r8\n"
    "bne .Lshop_common_0d9e\n"
    ".Lshop_common_0db6:\n"
    "adds r5, r3, #0\n"
    "ldr r1, [sp, #236]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_0dd2\n"
    "cmp r5, #0\n"
    "beq .Lshop_common_0dce\n"
    "adds r0, r5, #0\n"
    "mov r1, sl\n"
    "ldmia r1!, {r2, r3, r6}\n"
    "stmia r0!, {r2, r3, r6}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0dce:\n"
    "adds r5, #16\n"
    "b .Lshop_common_0dfa\n"
    ".Lshop_common_0dd2:\n"
    "mov r8, r1\n"
    "adds r2, r5, #0\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_0df8\n"
    ".Lshop_common_0dda:\n"
    "cmp r2, #0\n"
    "beq .Lshop_common_0dea\n"
    "adds r0, r2, #0\n"
    "mov r1, sl\n"
    "ldmia r1!, {r4, r5, r6}\n"
    "stmia r0!, {r4, r5, r6}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0dea:\n"
    "movs r0, #1\n"
    "negs r0, r0\n"
    "add r8, r0\n"
    "adds r2, #16\n"
    "mov r1, r8\n"
    "cmp r1, #0\n"
    "bne .Lshop_common_0dda\n"
    ".Lshop_common_0df8:\n"
    "adds r5, r2, #0\n"
    ".Lshop_common_0dfa:\n"
    "ldr r3, [sp, #312]\n"
    "ldr r2, [r3, #4]\n"
    "ldr r0, [r3, #0]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
    "beq .Lshop_common_0e0c\n"
    ".Lshop_common_0e06:\n"
    "adds r1, #16\n"
    "cmp r1, r2\n"
    "bne .Lshop_common_0e06\n"
    ".Lshop_common_0e0c:\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0e14\n"
    "bl free\n"
    ".Lshop_common_0e14:\n"
    "ldr r0, [sp, #316]\n"
    "add r0, sb\n"
    "ldr r4, [sp, #316]\n"
    "ldr r6, [sp, #312]\n"
    "str r4, [r6, #0]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #12]\n"
    ".Lshop_common_0e22:\n"
    "movs r1, #173\n"
    "lsls r1, r1, #3\n"
    "adds r0, r7, r1\n"
    "ldr r1, [r0, #0]\n"
    "ldr r3, [r1, #0]\n"
    "ldrh r2, [r0, #12]\n"
    "lsls r2, r2, #2\n"
    "ldr r4, [sp, #292]\n"
    "ldr r0, [r4, #0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0, #0]\n"
    "ldr r0, [sp, #268]\n"
    "ldr r3, [r3, #16]\n"
    "bl _call_via_r3\n"
    "adds r0, r7, #0\n"
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
    "ldr r6, [sp, #272]\n"
    "ldr r5, [r6, #0]\n"
    "movs r1, #225\n"
    "lsls r1, r1, #2\n"
    "adds r0, r7, r1\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "adds r2, r0, #0\n"
    "ldr r0, [r6, #0]\n"
    "movs r3, #0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0e64\n"
    "ldrh r3, [r6, #4]\n"
    ".Lshop_common_0e64:\n"
    "str r4, [sp, #312]\n"
    "lsls r2, r2, #5\n"
    "ldr r4, .Lshop_common_0e9c\n"
    "adds r2, r2, r4\n"
    "add r0, sp, #84\n"
    "adds r1, r5, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
    "ldr r5, [sp, #256]\n"
    "mov sl, r5\n"
    "ldr r6, [sp, #312]\n"
#endif
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #12]\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0d44\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0ea0\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0d1c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0e92\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #328]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r1, r5, #0\n"
#endif
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0d1c:\n"
    "ldr r0, [r6, #4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0e92:\n"
    "ldr r5, [sp, #312]\n"
    "ldr r0, [r5, #4]\n"
#endif
    "adds r0, #16\n"
#if defined(REGION_JP)
    "str r0, [r6, #4]\n"
    "b .Lshop_common_0e12\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [r5, #4]\n"
    "b .Lshop_common_0f72\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_0d24: .word VRAM + 0xe800\n"
    ".Lshop_common_0d28: .word 0x434\n"
    ".Lshop_common_0d2c: .word 0x564\n"
    ".Lshop_common_0d30: .word 0x566\n"
    ".Lshop_common_0d34: .word 0x59c\n"
    ".Lshop_common_0d38: .word 0x59e\n"
    ".Lshop_common_0d3c: .word 0x64c\n"
    ".Lshop_common_0d40: .word OBJ_PLTT\n"
    ".Lshop_common_0d44:\n"
    "str r1, [sp, #376]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_0e9c: .word OBJ_PLTT\n"
    ".Lshop_common_0ea0:\n"
    "mov r8, r1\n"
#endif
    "movs r0, #1\n"
#if defined(REGION_JP)
    "add r1, sp, #300\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #244\n"
#endif
    "str r0, [r1, #0]\n"
#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r6, [sp, #312]\n"
#endif
    "ldr r0, [r6, #0]\n"
#if defined(REGION_JP)
    "ldr r5, [sp, #376]\n"
    "subs r0, r5, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r2, r8\n"
    "subs r0, r2, r0\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "add r0, sp, #296\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #240\n"
#endif
    "str r4, [r0, #0]\n"
#if defined(REGION_JP)
    "adds r2, r1, #0\n"
    "ldr r0, [r1, #0]\n"
    "add r1, sp, #296\n"
    "cmp r4, r0\n"
    "bhs .Lshop_common_0d64\n"
    "adds r1, r2, #0\n"
    ".Lshop_common_0d64:\n"
    "ldr r0, [r1, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, [r1, #0]\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_0ebe\n"
    "adds r0, r1, #0\n"
    ".Lshop_common_0ebe:\n"
    "ldr r0, [r0, #0]\n"
#endif
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0d82\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_0edc\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_0d86\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_0ee0\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_0d86\n"
    ".Lshop_common_0d82:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_0ee0\n"
    ".Lshop_common_0edc:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_0d86:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_0ee0:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #380]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #316]\n"
    "ldr r3, [sp, #312]\n"
    "ldr r2, [r3, #0]\n"
    "adds r3, r5, #0\n"
    "cmp r2, r8\n"
    "beq .Lshop_common_0f06\n"
    ".Lshop_common_0eee:\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_0efe\n"
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldmia r1!, {r4, r5, r6}\n"
    "stmia r0!, {r4, r5, r6}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0efe:\n"
    "adds r2, #16\n"
    "adds r3, #16\n"
    "cmp r2, r8\n"
    "bne .Lshop_common_0eee\n"
    ".Lshop_common_0f06:\n"
    "adds r5, r3, #0\n"
    "ldr r1, [sp, #244]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_0f22\n"
    "cmp r5, #0\n"
    "beq .Lshop_common_0f1e\n"
    "adds r0, r5, #0\n"
    "mov r1, sl\n"
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0f1e:\n"
    "adds r5, #16\n"
    "b .Lshop_common_0f4a\n"
    ".Lshop_common_0f22:\n"
    "mov r8, r1\n"
    "adds r2, r5, #0\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_0f48\n"
    ".Lshop_common_0f2a:\n"
    "cmp r2, #0\n"
    "beq .Lshop_common_0f3a\n"
    "adds r0, r2, #0\n"
    "mov r1, sl\n"
    "ldmia r1!, {r3, r5, r6}\n"
    "stmia r0!, {r3, r5, r6}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0f3a:\n"
    "movs r4, #1\n"
    "negs r4, r4\n"
    "add r8, r4\n"
    "adds r2, #16\n"
    "mov r5, r8\n"
    "cmp r5, #0\n"
    "bne .Lshop_common_0f2a\n"
    ".Lshop_common_0f48:\n"
    "adds r5, r2, #0\n"
    ".Lshop_common_0f4a:\n"
    "ldr r6, [sp, #312]\n"
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6, #0]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
    "beq .Lshop_common_0f5c\n"
    ".Lshop_common_0f56:\n"
    "adds r1, #16\n"
    "cmp r1, r2\n"
    "bne .Lshop_common_0f56\n"
    ".Lshop_common_0f5c:\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0f64\n"
    "bl free\n"
    ".Lshop_common_0f64:\n"
    "ldr r0, [sp, #316]\n"
    "add r0, sb\n"
    "ldr r1, [sp, #316]\n"
    "ldr r2, [sp, #312]\n"
    "str r1, [r2, #0]\n"
    "str r5, [r2, #4]\n"
    "str r0, [r2, #12]\n"
    ".Lshop_common_0f72:\n"
    "movs r3, #187\n"
    "lsls r3, r3, #3\n"
    "adds r0, r7, r3\n"
    "ldr r1, [r0, #0]\n"
    "ldr r3, [r1, #0]\n"
    "ldrh r2, [r0, #12]\n"
    "lsls r2, r2, #2\n"
    "ldr r4, [sp, #296]\n"
    "ldr r0, [r4, #0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0, #0]\n"
    "ldr r0, [sp, #276]\n"
    "ldr r3, [r3, #16]\n"
    "bl _call_via_r3\n"
    "adds r0, r7, #0\n"
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
    "ldr r6, [sp, #280]\n"
    "ldr r5, [r6, #0]\n"
    "movs r1, #231\n"
    "lsls r1, r1, #2\n"
    "adds r0, r7, r1\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "adds r2, r0, #0\n"
    "ldr r0, [r6, #0]\n"
    "movs r3, #0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0fb4\n"
    "ldrh r3, [r6, #4]\n"
    ".Lshop_common_0fb4:\n"
    "adds r6, r4, #0\n"
    "lsls r2, r2, #5\n"
    "ldr r4, .Lshop_common_0fe8\n"
    "adds r2, r2, r4\n"
    "add r0, sp, #84\n"
    "adds r1, r5, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
    "ldr r5, [sp, #256]\n"
    "mov r8, r5\n"
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #12]\n"
    "cmp r1, r0\n"
    "beq .Lshop_common_0fec\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_0fe0\n"
    "adds r0, r1, #0\n"
    "mov r1, r8\n"
    "ldmia r1!, {r2, r3, r7}\n"
    "stmia r0!, {r2, r3, r7}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0fe0:\n"
    "ldr r0, [r6, #4]\n"
    "adds r0, #16\n"
    "str r0, [r6, #4]\n"
    "b .Lshop_common_10b8\n"
    ".align 2, 0\n"
    ".Lshop_common_0fe8: .word OBJ_PLTT\n"
    ".Lshop_common_0fec:\n"
    "str r1, [sp, #320]\n"
    "movs r0, #1\n"
    "add r1, sp, #252\n"
    "str r0, [r1, #0]\n"
    "ldr r0, [r6, #0]\n"
    "ldr r4, [sp, #320]\n"
    "subs r0, r4, r0\n"
    "asrs r4, r0, #4\n"
    "add r0, sp, #248\n"
    "str r4, [r0, #0]\n"
    "ldr r2, [r1, #0]\n"
    "mov sl, r1\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_100a\n"
    "mov r0, sl\n"
    ".Lshop_common_100a:\n"
    "ldr r0, [r0, #0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1028\n"
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
    "mov sb, r4\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_102c\n"
    "mov r0, sb\n"
    "bl RetryMemoryAllocation\n"
    "b .Lshop_common_102c\n"
    ".Lshop_common_1028:\n"
    "movs r0, #0\n"
    "mov sb, r0\n"
    ".Lshop_common_102c:\n"
    "adds r5, r0, #0\n"
    "str r5, [sp, #316]\n"
#endif
    "ldr r2, [r6, #0]\n"
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #376]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_0dae\n"
    ".Lshop_common_0d94:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, [sp, #320]\n"
    "cmp r2, r5\n"
    "beq .Lshop_common_1054\n"
    ".Lshop_common_103a:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0da4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_104a\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0da4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_104a:\n"
#endif
    "adds r2, #16\n"
    "adds r3, #16\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #376]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_0d94\n"
    ".Lshop_common_0dae:\n"
    "adds r5, r3, #0\n"
    "add r0, sp, #300\n"
    "ldr r0, [r0, #0]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_0dcc\n"
    "cmp r5, #0\n"
    "beq .Lshop_common_0dc8\n"
    "adds r0, r5, #0\n"
    "mov r1, sb\n"
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0dc8:\n"
    "adds r5, #16\n"
    "b .Lshop_common_0dee\n"
    ".Lshop_common_0dcc:\n"
    "adds r3, r0, #0\n"
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_0dec\n"
    ".Lshop_common_0dd4:\n"
    "cmp r2, #0\n"
    "beq .Lshop_common_0de4\n"
    "adds r0, r2, #0\n"
    "mov r1, sb\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0de4:\n"
    "subs r3, #1\n"
    "adds r2, #16\n"
    "cmp r3, #0\n"
    "bne .Lshop_common_0dd4\n"
    ".Lshop_common_0dec:\n"
    "adds r5, r2, #0\n"
    ".Lshop_common_0dee:\n"
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6, #0]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
    "beq .Lshop_common_0dfe\n"
    ".Lshop_common_0df8:\n"
    "adds r1, #16\n"
    "cmp r1, r2\n"
    "bne .Lshop_common_0df8\n"
    ".Lshop_common_0dfe:\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0e06\n"
    "bl free\n"
    ".Lshop_common_0e06:\n"
    "ldr r0, [sp, #380]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #380]\n"
    "str r7, [r6, #0]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #12]\n"
    ".Lshop_common_0e12:\n"
    "movs r0, #173\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldr r1, [r0, #0]\n"
    "ldr r3, [r1, #0]\n"
    "ldrh r2, [r0, #12]\n"
    "lsls r2, r2, #2\n"
    "ldr r4, [sp, #340]\n"
    "ldr r0, [r4, #0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0, #0]\n"
    "ldr r0, [sp, #344]\n"
    "ldr r3, [r3, #16]\n"
    "bl _call_via_r3\n"
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
    "ldr r7, [sp, #348]\n"
    "ldr r5, [r7, #0]\n"
    "movs r0, #225\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "adds r2, r0, #0\n"
    "ldr r0, [r7, #0]\n"
    "movs r3, #0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0e54\n"
    "ldrh r3, [r7, #4]\n"
    ".Lshop_common_0e54:\n"
    "adds r6, r4, #0\n"
    "lsls r2, r2, #5\n"
    "ldr r0, .Lshop_common_0e88\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #148\n"
    "adds r1, r5, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
    "ldr r1, [sp, #328]\n"
    "mov sb, r1\n"
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #12]\n"
    "cmp r1, r0\n"
    "beq .Lshop_common_0e8c\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_0e80\n"
    "adds r0, r1, #0\n"
    "ldr r1, [sp, #328]\n"
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0e80:\n"
    "ldr r0, [r6, #4]\n"
    "adds r0, #16\n"
    "str r0, [r6, #4]\n"
    "b .Lshop_common_0f5a\n"
    ".align 2, 0\n"
    ".Lshop_common_0e88: .word OBJ_PLTT\n"
    ".Lshop_common_0e8c:\n"
    "str r1, [sp, #376]\n"
    "movs r0, #1\n"
    "add r1, sp, #308\n"
    "str r0, [r1, #0]\n"
    "ldr r0, [r6, #0]\n"
    "ldr r5, [sp, #376]\n"
    "subs r0, r5, r0\n"
    "asrs r4, r0, #4\n"
    "add r0, sp, #304\n"
    "str r4, [r0, #0]\n"
    "adds r2, r1, #0\n"
    "ldr r0, [r1, #0]\n"
    "add r1, sp, #304\n"
    "cmp r4, r0\n"
    "bhs .Lshop_common_0eac\n"
    "adds r1, r2, #0\n"
    ".Lshop_common_0eac:\n"
    "ldr r0, [r1, #0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0eca\n"
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
    "mov r8, r4\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_0ece\n"
    "mov r0, r8\n"
    "bl RetryMemoryAllocation\n"
    "b .Lshop_common_0ece\n"
    ".Lshop_common_0eca:\n"
    "movs r0, #0\n"
    "mov r8, r0\n"
    ".Lshop_common_0ece:\n"
    "adds r5, r0, #0\n"
    "str r5, [sp, #380]\n"
    "ldr r2, [r6, #0]\n"
    "adds r3, r5, #0\n"
    "ldr r7, [sp, #376]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #320]\n"
#endif
    "cmp r2, r7\n"
#if defined(REGION_JP)
    "beq .Lshop_common_0ef6\n"
    ".Lshop_common_0edc:\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_0eec\n"
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0eec:\n"
    "adds r2, #16\n"
    "adds r3, #16\n"
    "ldr r0, [sp, #376]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_0edc\n"
    ".Lshop_common_0ef6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_103a\n"
    ".Lshop_common_1054:\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "add r0, sp, #308\n"
    "ldr r0, [r0, #0]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_0f14\n"
    "cmp r5, #0\n"
    "beq .Lshop_common_0f10\n"
    "adds r0, r5, #0\n"
    "mov r1, sb\n"
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0f10:\n"
    "adds r5, #16\n"
    "b .Lshop_common_0f36\n"
    ".Lshop_common_0f14:\n"
    "adds r3, r0, #0\n"
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_0f34\n"
    ".Lshop_common_0f1c:\n"
    "cmp r2, #0\n"
    "beq .Lshop_common_0f2c\n"
    "adds r0, r2, #0\n"
    "mov r1, sb\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_0f2c:\n"
    "subs r3, #1\n"
    "adds r2, #16\n"
    "cmp r3, #0\n"
    "bne .Lshop_common_0f1c\n"
    ".Lshop_common_0f34:\n"
    "adds r5, r2, #0\n"
    ".Lshop_common_0f36:\n"
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6, #0]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
    "beq .Lshop_common_0f46\n"
    ".Lshop_common_0f40:\n"
    "adds r1, #16\n"
    "cmp r1, r2\n"
    "bne .Lshop_common_0f40\n"
    ".Lshop_common_0f46:\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0f4e\n"
    "bl free\n"
    ".Lshop_common_0f4e:\n"
    "ldr r0, [sp, #380]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #380]\n"
    "str r7, [r6, #0]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #12]\n"
    ".Lshop_common_0f5a:\n"
    "movs r0, #187\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldr r1, [r0, #0]\n"
    "ldr r3, [r1, #0]\n"
    "ldrh r2, [r0, #12]\n"
    "lsls r2, r2, #2\n"
    "ldr r4, [sp, #368]\n"
    "ldr r0, [r4, #0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0, #0]\n"
    "ldr r0, [sp, #352]\n"
    "ldr r3, [r3, #16]\n"
    "bl _call_via_r3\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif
    "mov r0, sl\n"
#if defined(REGION_JP)
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
    "ldr r7, [sp, #356]\n"
    "ldr r5, [r7, #0]\n"
    "movs r0, #231\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "adds r2, r0, #0\n"
    "ldr r0, [r7, #0]\n"
    "movs r3, #0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_0f9c\n"
    "ldrh r3, [r7, #4]\n"
    ".Lshop_common_0f9c:\n"
    "adds r6, r4, #0\n"
    "lsls r2, r2, #5\n"
    "ldr r0, .Lshop_common_0fd0\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #148\n"
    "adds r1, r5, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
    "ldr r1, [sp, #328]\n"
    "mov r8, r1\n"
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #12]\n"
    "cmp r1, r0\n"
    "beq .Lshop_common_0fd4\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_0fc8\n"
    "adds r0, r1, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [r0, #0]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_1072\n"
    "cmp r5, #0\n"
    "beq .Lshop_common_106e\n"
    "adds r0, r5, #0\n"
#endif
    "mov r1, r8\n"
    "ldmia r1!, {r2, r3, r4}\n"
    "stmia r0!, {r2, r3, r4}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_0fc8:\n"
    "ldr r0, [r6, #4]\n"
    "adds r0, #16\n"
    "str r0, [r6, #4]\n"
    "b .Lshop_common_109e\n"
    ".align 2, 0\n"
    ".Lshop_common_0fd0: .word OBJ_PLTT\n"
    ".Lshop_common_0fd4:\n"
    "mov sl, r1\n"
    "movs r0, #1\n"
    "add r1, sp, #316\n"
    "str r0, [r1, #0]\n"
    "ldr r0, [r6, #0]\n"
    "mov r5, sl\n"
    "subs r0, r5, r0\n"
    "asrs r4, r0, #4\n"
    "add r0, sp, #312\n"
    "str r4, [r0, #0]\n"
    "adds r2, r1, #0\n"
    "ldr r0, [r1, #0]\n"
    "add r1, sp, #312\n"
    "cmp r4, r0\n"
    "bhs .Lshop_common_0ff4\n"
    "adds r1, r2, #0\n"
    ".Lshop_common_0ff4:\n"
    "ldr r0, [r1, #0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1012\n"
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
    "mov sb, r4\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_1016\n"
    "mov r0, sb\n"
    "bl RetryMemoryAllocation\n"
    "b .Lshop_common_1016\n"
    ".Lshop_common_1012:\n"
    "movs r0, #0\n"
    "mov sb, r0\n"
    ".Lshop_common_1016:\n"
    "adds r5, r0, #0\n"
    "str r5, [sp, #380]\n"
    "ldr r2, [r6, #0]\n"
    "adds r3, r5, #0\n"
    "cmp r2, sl\n"
    "beq .Lshop_common_103a\n"
    ".Lshop_common_1022:\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_1032\n"
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_1032:\n"
    "adds r2, #16\n"
    "adds r3, #16\n"
    "cmp r2, sl\n"
    "bne .Lshop_common_1022\n"
    ".Lshop_common_103a:\n"
    "adds r5, r3, #0\n"
    "add r0, sp, #316\n"
    "ldr r0, [r0, #0]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_1058\n"
    "cmp r5, #0\n"
    "beq .Lshop_common_1054\n"
    "adds r0, r5, #0\n"
    "mov r1, r8\n"
    "ldmia r1!, {r2, r3, r7}\n"
    "stmia r0!, {r2, r3, r7}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
    ".Lshop_common_1054:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_106e:\n"
#endif
    "adds r5, #16\n"
#if defined(REGION_JP)
    "b .Lshop_common_107a\n"
    ".Lshop_common_1058:\n"
    "adds r3, r0, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1094\n"
    ".Lshop_common_1072:\n"
    "adds r3, r1, #0\n"
#endif
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1078\n"
    ".Lshop_common_1060:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1092\n"
    ".Lshop_common_107a:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1070\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_108a\n"
#endif
    "adds r0, r2, #0\n"
    "mov r1, r8\n"
    "ldmia r1!, {r4, r5, r7}\n"
    "stmia r0!, {r4, r5, r7}\n"
    "ldr r1, [r1, #0]\n"
    "str r1, [r0, #0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1070:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_108a:\n"
#endif
    "subs r3, #1\n"
    "adds r2, #16\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1060\n"
    ".Lshop_common_1078:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_107a\n"
    ".Lshop_common_1092:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_107a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1094:\n"
#endif
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6, #0]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_108a\n"
    ".Lshop_common_1084:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_10a4\n"
    ".Lshop_common_109e:\n"
#endif
    "adds r1, #16\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1084\n"
    ".Lshop_common_108a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_109e\n"
    ".Lshop_common_10a4:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1092\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_10ac\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_1092:\n"
    "ldr r0, [sp, #380]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_10ac:\n"
    "ldr r0, [sp, #316]\n"
#endif
    "add r0, sb\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #380]\n"
    "str r1, [r6, #0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #316]\n"
    "str r7, [r6, #0]\n"
#endif
    "str r5, [r6, #4]\n"
    "str r0, [r6, #12]\n"
#if defined(REGION_JP)
    ".Lshop_common_109e:\n"
    "add sp, #384\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_10b8:\n"
    "add sp, #324\n"
#endif
    "pop {r3, r4, r5}\n"
    "mov r8, r3\n"
    "mov sb, r4\n"
    "mov sl, r5\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r0}\n"
    "bx r0\n"
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".align 2, 0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif
    "thumb_func_start UpdateShopInputState\n"
    "UpdateShopInputState:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "adds r4, r0, #0\n"
    "movs r7, #0x28\n"
    "cmp r1, #1\n"
#if defined(REGION_JP)
    "beq .Lshop_common_10d0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_10e8\n"
#endif
    "cmp r1, #1\n"
#if defined(REGION_JP)
    "blo .Lshop_common_10d0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "blo .Lshop_common_10e8\n"
#endif
    "cmp r1, #2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_10ca\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_10e2\n"
#endif
    "cmp r1, #3\n"
#if defined(REGION_JP)
    "beq .Lshop_common_10ce\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_10e6\n"
#endif
    "movs r7, #0x58\n"
#if defined(REGION_JP)
    "b .Lshop_common_10d0\n"
    ".Lshop_common_10ca:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_10e8\n"
    ".Lshop_common_10e2:\n"
#endif
    "movs r7, #0x38\n"
#if defined(REGION_JP)
    "b .Lshop_common_10d0\n"
    ".Lshop_common_10ce:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_10e8\n"
    ".Lshop_common_10e6:\n"
#endif
    "movs r7, #0x48\n"
#if defined(REGION_JP)
    ".Lshop_common_10d0:\n"
    "ldr r0, .Lshop_common_1150\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_10e8:\n"
    "ldr r0, .Lshop_common_1168\n"
#endif
    "adds r1, r4, r0\n"
    "ldrb r0, [r1]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_10e6\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_10fe\n"
#endif
    "movs r2, #0xd4\n"
    "lsls r2, r2, #3\n"
    "adds r0, r4, r2\n"
    "ldrb r0, [r0]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_10fc\n"
    ".Lshop_common_10e6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1114\n"
    ".Lshop_common_10fe:\n"
#endif
    "adds r0, r4, #0\n"
    "bl GetHardwarePressedKeys\n"
    "movs r1, #1\n"
    "ands r0, r1\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_10fe\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1116\n"
#endif
    "movs r0, #0xd4\n"
    "lsls r0, r0, #3\n"
    "adds r1, r4, r0\n"
    "movs r0, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_10fc:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1114:\n"
#endif
    "strb r0, [r1]\n"
#if defined(REGION_JP)
    ".Lshop_common_10fe:\n"
    "ldr r2, .Lshop_common_1154\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1116:\n"
    "ldr r2, .Lshop_common_116c\n"
#endif
    "adds r1, r4, r2\n"
    "ldrb r0, [r1]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1112\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_112a\n"
#endif
    "subs r2, #1\n"
    "adds r0, r4, r2\n"
    "ldrb r0, [r0]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1126\n"
    ".Lshop_common_1112:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_113e\n"
    ".Lshop_common_112a:\n"
#endif
    "adds r0, r4, #0\n"
    "bl GetHardwarePressedKeys\n"
    "movs r1, #2\n"
    "ands r0, r1\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1128\n"
    "ldr r0, .Lshop_common_1158\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1140\n"
    "ldr r0, .Lshop_common_1170\n"
#endif
    "adds r1, r4, r0\n"
    "movs r0, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_1126:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_113e:\n"
#endif
    "strb r0, [r1]\n"
#if defined(REGION_JP)
    ".Lshop_common_1128:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1140:\n"
#endif
    "adds r0, r4, #0\n"
    "bl GetHardwareHeldKeys\n"
    "lsls r0, r0, #0x10\n"
    "lsrs r5, r0, #0x10\n"
    "movs r2, #0xd0\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "ldr r0, [r1]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_116a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1182\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "ble .Lshop_common_115c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_1174\n"
#endif
    "ldrh r0, [r4, #0xc]\n"
    "adds r0, #4\n"
    "strh r0, [r4, #0xc]\n"
    "ldr r0, [r1]\n"
    "subs r0, #1\n"
#if defined(REGION_JP)
    "b .Lshop_common_1166\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_117e\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_1150: .word 0x6a1\n"
    ".Lshop_common_1154: .word 0x6a3\n"
    ".Lshop_common_1158: .word 0x6a2\n"
    ".Lshop_common_115c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1168: .word 0x6a1\n"
    ".Lshop_common_116c: .word 0x6a3\n"
    ".Lshop_common_1170: .word 0x6a2\n"
    ".Lshop_common_1174:\n"
#endif
    "ldrh r0, [r4, #0xc]\n"
    "subs r0, #4\n"
    "strh r0, [r4, #0xc]\n"
    "ldr r0, [r1]\n"
    "adds r0, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_1166:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_117e:\n"
#endif
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_12f2\n"
    ".Lshop_common_116a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_130a\n"
    ".Lshop_common_1182:\n"
#endif
    "movs r6, #0\n"
    "adds r0, r4, #0\n"
    "bl GetHardwareRepeatedKeys\n"
    "movs r1, #0x40\n"
    "ands r0, r1\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1184\n"
    "ldr r0, .Lshop_common_11a4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_119c\n"
    "ldr r0, .Lshop_common_11bc\n"
#endif
    "ands r0, r5\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1184\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_119c\n"
#endif
    "movs r6, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_1184:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_119c:\n"
#endif
    "cmp r6, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1228\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1240\n"
#endif
    "movs r0, #0xd4\n"
    "lsls r0, r0, #3\n"
    "adds r5, r4, r0\n"
    "ldrb r3, [r5]\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_11ac\n"
    "ldr r1, .Lshop_common_11a8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_11c4\n"
    "ldr r1, .Lshop_common_11c0\n"
#endif
    "adds r0, r4, r1\n"
    "movs r2, #0\n"
    "movs r1, #1\n"
    "strb r1, [r0]\n"
    "strb r2, [r5]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_11a4: .word 0x3bf\n"
    ".Lshop_common_11a8: .word 0x6a1\n"
    ".Lshop_common_11ac:\n"
    "ldr r2, .Lshop_common_11c8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_11bc: .word 0x3bf\n"
    ".Lshop_common_11c0: .word 0x6a1\n"
    ".Lshop_common_11c4:\n"
    "ldr r2, .Lshop_common_11e0\n"
#endif
    "adds r0, r4, r2\n"
    "strb r3, [r0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_11cc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_11e4\n"
#endif
    "adds r5, r4, r0\n"
    "ldrb r2, [r5]\n"
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_11d4\n"
    "ldr r2, .Lshop_common_11d0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_11ec\n"
    "ldr r2, .Lshop_common_11e8\n"
#endif
    "adds r1, r4, r2\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
    "strb r3, [r5]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_11c8: .word 0x6a1\n"
    ".Lshop_common_11cc: .word 0x6a2\n"
    ".Lshop_common_11d0: .word 0x6a3\n"
    ".Lshop_common_11d4:\n"
    "ldr r1, .Lshop_common_11f8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_11e0: .word 0x6a1\n"
    ".Lshop_common_11e4: .word 0x6a2\n"
    ".Lshop_common_11e8: .word 0x6a3\n"
    ".Lshop_common_11ec:\n"
    "ldr r1, .Lshop_common_1210\n"
#endif
    "adds r0, r4, r1\n"
    "strb r2, [r0]\n"
    "movs r0, #0xc9\n"
    "lsls r0, r0, #3\n"
    "adds r1, r4, r0\n"
    "ldr r0, [r1]\n"
    "cmp r0, #0x28\n"
#if defined(REGION_JP)
    "ble .Lshop_common_120e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_1226\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_11fc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1214\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "ble .Lshop_common_1208\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_1220\n"
#endif
    "cmp r0, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1200\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1218\n"
#endif
    "cmp r0, #0x58\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1204\n"
    "b .Lshop_common_1208\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_121c\n"
    "b .Lshop_common_1220\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_11f8: .word 0x6a3\n"
    ".Lshop_common_11fc:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1210: .word 0x6a3\n"
    ".Lshop_common_1214:\n"
#endif
    "movs r0, #0x28\n"
#if defined(REGION_JP)
    "b .Lshop_common_1206\n"
    ".Lshop_common_1200:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_121e\n"
    ".Lshop_common_1218:\n"
#endif
    "movs r0, #0x38\n"
#if defined(REGION_JP)
    "b .Lshop_common_1206\n"
    ".Lshop_common_1204:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_121e\n"
    ".Lshop_common_121c:\n"
#endif
    "movs r0, #0x48\n"
#if defined(REGION_JP)
    ".Lshop_common_1206:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_121e:\n"
#endif
    "str r0, [r1]\n"
#if defined(REGION_JP)
    ".Lshop_common_1208:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1220:\n"
#endif
    "ldr r0, [r4, #0x10]\n"
    "subs r0, #1\n"
#if defined(REGION_JP)
    "b .Lshop_common_12ba\n"
    ".Lshop_common_120e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_12d2\n"
    ".Lshop_common_1226:\n"
#endif
    "movs r1, #0xc\n"
    "ldrsh r0, [r4, r1]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "ble .Lshop_common_12d4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_12ec\n"
#endif
    "movs r2, #0xd0\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "movs r0, #4\n"
    "rsbs r0, r0, #0\n"
    "str r0, [r1]\n"
    "ldr r0, [r4, #0x10]\n"
    "subs r0, #1\n"
#if defined(REGION_JP)
    "b .Lshop_common_12e6\n"
    ".Lshop_common_1228:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_12fe\n"
    ".Lshop_common_1240:\n"
#endif
    "movs r6, #0\n"
    "adds r0, r4, #0\n"
    "bl GetHardwareRepeatedKeys\n"
    "movs r1, #0x80\n"
    "ands r0, r1\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1242\n"
    "ldr r0, .Lshop_common_1294\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_125a\n"
    "ldr r0, .Lshop_common_12ac\n"
#endif
    "ands r0, r5\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1242\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_125a\n"
#endif
    "movs r6, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_1242:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_125a:\n"
#endif
    "cmp r6, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_12fe\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1316\n"
#endif
    "movs r0, #0xd4\n"
    "lsls r0, r0, #3\n"
    "adds r3, r4, r0\n"
    "ldrb r2, [r3]\n"
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1254\n"
    "b .Lshop_common_1674\n"
    ".Lshop_common_1254:\n"
    "ldr r1, .Lshop_common_1298\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_126c\n"
    "b .Lshop_common_168c\n"
    ".Lshop_common_126c:\n"
    "ldr r1, .Lshop_common_12b0\n"
#endif
    "adds r0, r4, r1\n"
    "strb r2, [r0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_129c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_12b4\n"
#endif
    "adds r3, r4, r0\n"
    "ldrb r1, [r3]\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1266\n"
    "b .Lshop_common_169c\n"
    ".Lshop_common_1266:\n"
    "ldr r2, .Lshop_common_12a0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_127e\n"
    "b .Lshop_common_16b4\n"
    ".Lshop_common_127e:\n"
    "ldr r2, .Lshop_common_12b8\n"
#endif
    "adds r0, r4, r2\n"
    "strb r1, [r0]\n"
    "ldr r0, [r4, #0x1c]\n"
    "movs r1, #0xe\n"
    "ldrsh r0, [r0, r1]\n"
    "subs r0, #0xa0\n"
    "lsls r0, r0, #0x10\n"
    "lsrs r2, r0, #0x10\n"
    "movs r0, #0xc9\n"
    "lsls r0, r0, #3\n"
    "adds r1, r4, r0\n"
    "ldr r0, [r1]\n"
    "cmp r0, r7\n"
#if defined(REGION_JP)
    "bge .Lshop_common_12c8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bge .Lshop_common_12e0\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_12ae\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_12c6\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_12a4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_12bc\n"
#endif
    "cmp r0, #0x28\n"
#if defined(REGION_JP)
    "beq .Lshop_common_12aa\n"
    "b .Lshop_common_12b6\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_12c2\n"
    "b .Lshop_common_12ce\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_1294: .word 0x37f\n"
    ".Lshop_common_1298: .word 0x6a1\n"
    ".Lshop_common_129c: .word 0x6a2\n"
    ".Lshop_common_12a0: .word 0x6a3\n"
    ".Lshop_common_12a4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_12ac: .word 0x37f\n"
    ".Lshop_common_12b0: .word 0x6a1\n"
    ".Lshop_common_12b4: .word 0x6a2\n"
    ".Lshop_common_12b8: .word 0x6a3\n"
    ".Lshop_common_12bc:\n"
#endif
    "cmp r0, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_12b2\n"
    "b .Lshop_common_12b6\n"
    ".Lshop_common_12aa:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_12ca\n"
    "b .Lshop_common_12ce\n"
    ".Lshop_common_12c2:\n"
#endif
    "movs r0, #0x38\n"
#if defined(REGION_JP)
    "b .Lshop_common_12b4\n"
    ".Lshop_common_12ae:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_12cc\n"
    ".Lshop_common_12c6:\n"
#endif
    "movs r0, #0x48\n"
#if defined(REGION_JP)
    "b .Lshop_common_12b4\n"
    ".Lshop_common_12b2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_12cc\n"
    ".Lshop_common_12ca:\n"
#endif
    "movs r0, #0x58\n"
#if defined(REGION_JP)
    ".Lshop_common_12b4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_12cc:\n"
#endif
    "str r0, [r1]\n"
#if defined(REGION_JP)
    ".Lshop_common_12b6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_12ce:\n"
#endif
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_12ba:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_12d2:\n"
#endif
    "str r0, [r4, #0x10]\n"
    "adds r0, r4, #0\n"
    "adds r0, #0x18\n"
    "movs r1, #0xcb\n"
    "bl Start__23HardwareMusicPlayerSlotUs\n"
#if defined(REGION_JP)
    "b .Lshop_common_12f2\n"
    ".Lshop_common_12c8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_130a\n"
    ".Lshop_common_12e0:\n"
#endif
    "movs r0, #0xc\n"
    "ldrsh r1, [r4, r0]\n"
    "lsls r0, r2, #0x10\n"
    "asrs r0, r0, #0x10\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "blt .Lshop_common_12d8\n"
    ".Lshop_common_12d4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "blt .Lshop_common_12f0\n"
    ".Lshop_common_12ec:\n"
#endif
    "strh r2, [r4, #0xc]\n"
#if defined(REGION_JP)
    "b .Lshop_common_12f2\n"
    ".Lshop_common_12d8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_130a\n"
    ".Lshop_common_12f0:\n"
#endif
    "movs r2, #0xd0\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "movs r0, #4\n"
    "str r0, [r1]\n"
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_12e6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_12fe:\n"
#endif
    "str r0, [r4, #0x10]\n"
    "adds r0, r4, #0\n"
    "adds r0, #0x18\n"
    "movs r1, #0xcb\n"
    "bl Start__23HardwareMusicPlayerSlotUs\n"
#if defined(REGION_JP)
    ".Lshop_common_12f2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_130a:\n"
#endif
    "ldr r0, [r4, #0x1c]\n"
    "movs r2, #0xc\n"
    "ldrsh r1, [r4, r2]\n"
    "bl SetScrollPosition\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_12fe:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_1316:\n"
#endif
    "movs r6, #0\n"
    "adds r0, r4, #0\n"
    "bl GetHardwareRepeatedKeys\n"
    "movs r1, #0x10\n"
    "ands r0, r1\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1318\n"
    "ldr r0, .Lshop_common_136c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1330\n"
    "ldr r0, .Lshop_common_1384\n"
#endif
    "ands r0, r5\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1318\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1330\n"
#endif
    "movs r6, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_1318:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1330:\n"
#endif
    "cmp r6, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_131e\n"
    "b .Lshop_common_1488\n"
    ".Lshop_common_131e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1336\n"
    "b .Lshop_common_14a0\n"
    ".Lshop_common_1336:\n"
#endif
    "movs r0, #0xd4\n"
    "lsls r0, r0, #3\n"
    "adds r3, r4, r0\n"
    "ldrb r2, [r3]\n"
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_132c\n"
    "b .Lshop_common_1674\n"
    ".Lshop_common_132c:\n"
    "ldr r1, .Lshop_common_1370\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1344\n"
    "b .Lshop_common_168c\n"
    ".Lshop_common_1344:\n"
    "ldr r1, .Lshop_common_1388\n"
#endif
    "adds r0, r4, r1\n"
    "strb r2, [r0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_1374\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_138c\n"
#endif
    "adds r3, r4, r0\n"
    "ldrb r1, [r3]\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_133e\n"
    "b .Lshop_common_169c\n"
    ".Lshop_common_133e:\n"
    "ldr r2, .Lshop_common_1378\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1356\n"
    "b .Lshop_common_16b4\n"
    ".Lshop_common_1356:\n"
    "ldr r2, .Lshop_common_1390\n"
#endif
    "adds r0, r4, r2\n"
    "strb r1, [r0]\n"
    "ldr r0, [r4, #0x1c]\n"
    "movs r1, #0xe\n"
    "ldrsh r0, [r0, r1]\n"
    "subs r0, #0xa0\n"
    "lsls r0, r0, #0x10\n"
    "lsrs r3, r0, #0x10\n"
    "movs r0, #0xc9\n"
    "lsls r0, r0, #3\n"
    "adds r2, r4, r0\n"
    "ldr r1, [r2]\n"
    "cmp r1, #0x47\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_141e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1436\n"
#endif
    "cmp r1, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1386\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_139e\n"
#endif
    "cmp r1, #0x38\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_137c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1394\n"
#endif
    "cmp r1, #0x28\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1382\n"
    "b .Lshop_common_138e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_139a\n"
    "b .Lshop_common_13a6\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_136c: .word 0x3ef\n"
    ".Lshop_common_1370: .word 0x6a1\n"
    ".Lshop_common_1374: .word 0x6a2\n"
    ".Lshop_common_1378: .word 0x6a3\n"
    ".Lshop_common_137c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1384: .word 0x3ef\n"
    ".Lshop_common_1388: .word 0x6a1\n"
    ".Lshop_common_138c: .word 0x6a2\n"
    ".Lshop_common_1390: .word 0x6a3\n"
    ".Lshop_common_1394:\n"
#endif
    "cmp r1, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_138a\n"
    "b .Lshop_common_138e\n"
    ".Lshop_common_1382:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_13a2\n"
    "b .Lshop_common_13a6\n"
    ".Lshop_common_139a:\n"
#endif
    "movs r0, #0x38\n"
#if defined(REGION_JP)
    "b .Lshop_common_138c\n"
    ".Lshop_common_1386:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_13a4\n"
    ".Lshop_common_139e:\n"
#endif
    "movs r0, #0x48\n"
#if defined(REGION_JP)
    "b .Lshop_common_138c\n"
    ".Lshop_common_138a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_13a4\n"
    ".Lshop_common_13a2:\n"
#endif
    "movs r0, #0x58\n"
#if defined(REGION_JP)
    ".Lshop_common_138c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_13a4:\n"
#endif
    "str r0, [r2]\n"
#if defined(REGION_JP)
    ".Lshop_common_138e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_13a6:\n"
#endif
    "movs r1, #0xc9\n"
    "lsls r1, r1, #3\n"
    "adds r2, r4, r1\n"
    "ldr r1, [r2]\n"
    "cmp r1, r7\n"
#if defined(REGION_JP)
    "ble .Lshop_common_13c0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_13d8\n"
#endif
    "cmp r1, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_13ae\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_13c6\n"
#endif
    "cmp r1, #0x38\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_13a4\n"
    "b .Lshop_common_1744\n"
    ".Lshop_common_13a4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_13bc\n"
    "b .Lshop_common_175c\n"
    ".Lshop_common_13bc:\n"
#endif
    "cmp r1, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_13b4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_13cc\n"
#endif
    "cmp r1, #0x58\n"
#if defined(REGION_JP)
    "beq .Lshop_common_13ba\n"
    "b .Lshop_common_1744\n"
    ".Lshop_common_13ae:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_13d2\n"
    "b .Lshop_common_175c\n"
    ".Lshop_common_13c6:\n"
#endif
    "movs r0, #0x28\n"
    "str r0, [r2]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_13b4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_13cc:\n"
#endif
    "movs r0, #0x38\n"
    "str r0, [r2]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_13ba:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_13d2:\n"
#endif
    "movs r0, #0x48\n"
    "str r0, [r2]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_13c0:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_13d8:\n"
#endif
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #1\n"
    "str r0, [r4, #0x10]\n"
    "cmp r1, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_13de\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_13f6\n"
#endif
    "cmp r1, #0x38\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_13d4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_13ec\n"
#endif
    "cmp r1, #0x28\n"
#if defined(REGION_JP)
    "beq .Lshop_common_13da\n"
    "b .Lshop_common_13e6\n"
    ".Lshop_common_13d4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_13f2\n"
    "b .Lshop_common_13fe\n"
    ".Lshop_common_13ec:\n"
#endif
    "cmp r1, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_13e2\n"
    "b .Lshop_common_13e6\n"
    ".Lshop_common_13da:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_13fa\n"
    "b .Lshop_common_13fe\n"
    ".Lshop_common_13f2:\n"
#endif
    "movs r0, #0x38\n"
#if defined(REGION_JP)
    "b .Lshop_common_13e4\n"
    ".Lshop_common_13de:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_13fc\n"
    ".Lshop_common_13f6:\n"
#endif
    "movs r0, #0x48\n"
#if defined(REGION_JP)
    "b .Lshop_common_13e4\n"
    ".Lshop_common_13e2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_13fc\n"
    ".Lshop_common_13fa:\n"
#endif
    "movs r0, #0x58\n"
#if defined(REGION_JP)
    ".Lshop_common_13e4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_13fc:\n"
#endif
    "str r0, [r2]\n"
#if defined(REGION_JP)
    ".Lshop_common_13e6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_13fe:\n"
#endif
    "movs r2, #0xc9\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "ldr r0, [r1]\n"
    "cmp r0, r7\n"
#if defined(REGION_JP)
    "ble .Lshop_common_1418\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_1430\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1406\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_141e\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_13fc\n"
    "b .Lshop_common_1580\n"
    ".Lshop_common_13fc:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1414\n"
    "b .Lshop_common_1598\n"
    ".Lshop_common_1414:\n"
#endif
    "cmp r0, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_140c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1424\n"
#endif
    "cmp r0, #0x58\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1412\n"
    "b .Lshop_common_1580\n"
    ".Lshop_common_1406:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_142a\n"
    "b .Lshop_common_1598\n"
    ".Lshop_common_141e:\n"
#endif
    "movs r0, #0x28\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1580\n"
    ".Lshop_common_140c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1598\n"
    ".Lshop_common_1424:\n"
#endif
    "movs r0, #0x38\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1580\n"
    ".Lshop_common_1412:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1598\n"
    ".Lshop_common_142a:\n"
#endif
    "movs r0, #0x48\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1580\n"
    ".Lshop_common_1418:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1598\n"
    ".Lshop_common_1430:\n"
#endif
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #1\n"
#if defined(REGION_JP)
    "b .Lshop_common_157e\n"
    ".Lshop_common_141e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1596\n"
    ".Lshop_common_1436:\n"
#endif
    "cmp r1, #0x48\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1452\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_146a\n"
#endif
    "movs r0, #0x58\n"
    "str r0, [r2]\n"
    "cmp r0, r7\n"
#if defined(REGION_JP)
    "ble .Lshop_common_142e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_1446\n"
#endif
    "str r1, [r2]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1580\n"
    ".Lshop_common_142e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1598\n"
    ".Lshop_common_1446:\n"
#endif
    "movs r0, #0xc\n"
    "ldrsh r1, [r4, r0]\n"
    "lsls r0, r3, #0x10\n"
    "asrs r0, r0, #0x10\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "blt .Lshop_common_1442\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "blt .Lshop_common_145a\n"
#endif
    "strh r3, [r4, #0xc]\n"
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #1\n"
#if defined(REGION_JP)
    "b .Lshop_common_157e\n"
    ".Lshop_common_1442:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1596\n"
    ".Lshop_common_145a:\n"
#endif
    "movs r2, #0xd0\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "movs r0, #4\n"
    "str r0, [r1]\n"
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #2\n"
#if defined(REGION_JP)
    "b .Lshop_common_157e\n"
    ".Lshop_common_1452:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1596\n"
    ".Lshop_common_146a:\n"
#endif
    "movs r0, #0xc\n"
    "ldrsh r1, [r4, r0]\n"
    "lsls r0, r3, #0x10\n"
    "asrs r0, r0, #0x10\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "bge .Lshop_common_1554\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bge .Lshop_common_156c\n"
#endif
    "movs r2, #0xc\n"
    "ldrsh r1, [r4, r2]\n"
    "subs r0, #0x10\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "blt .Lshop_common_1478\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "blt .Lshop_common_1490\n"
#endif
    "movs r0, #0xd0\n"
    "lsls r0, r0, #3\n"
    "adds r1, r4, r0\n"
    "movs r0, #4\n"
    "str r0, [r1]\n"
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #1\n"
#if defined(REGION_JP)
    "b .Lshop_common_157e\n"
    ".Lshop_common_1478:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1596\n"
    ".Lshop_common_1490:\n"
#endif
    "movs r2, #0xd0\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "movs r0, #8\n"
    "str r0, [r1]\n"
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #2\n"
#if defined(REGION_JP)
    "b .Lshop_common_157e\n"
    ".Lshop_common_1488:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1596\n"
    ".Lshop_common_14a0:\n"
#endif
    "movs r6, #0\n"
    "adds r0, r4, #0\n"
    "bl GetHardwareRepeatedKeys\n"
    "movs r1, #0x20\n"
    "ands r0, r1\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_14a2\n"
    "ldr r0, .Lshop_common_14d0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_14ba\n"
    "ldr r0, .Lshop_common_14e8\n"
#endif
    "ands r0, r5\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_14a2\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_14ba\n"
#endif
    "movs r6, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_14a2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_14ba:\n"
#endif
    "cmp r6, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_158c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_15a4\n"
#endif
    "movs r0, #0xd4\n"
    "lsls r0, r0, #3\n"
    "adds r3, r4, r0\n"
    "ldrb r2, [r3]\n"
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_14b4\n"
    "b .Lshop_common_1674\n"
    ".Lshop_common_14b4:\n"
    "ldr r1, .Lshop_common_14d4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_14cc\n"
    "b .Lshop_common_168c\n"
    ".Lshop_common_14cc:\n"
    "ldr r1, .Lshop_common_14ec\n"
#endif
    "adds r0, r4, r1\n"
    "strb r2, [r0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_14d8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_14f0\n"
#endif
    "adds r5, r4, r0\n"
    "ldrb r3, [r5]\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_14dc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_14f4\n"
#endif
    "adds r0, #1\n"
    "adds r1, r4, r0\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
    "strb r2, [r5]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_14d0: .word 0x3df\n"
    ".Lshop_common_14d4: .word 0x6a1\n"
    ".Lshop_common_14d8: .word 0x6a2\n"
    ".Lshop_common_14dc:\n"
    "ldr r1, .Lshop_common_14f8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_14e8: .word 0x3df\n"
    ".Lshop_common_14ec: .word 0x6a1\n"
    ".Lshop_common_14f0: .word 0x6a2\n"
    ".Lshop_common_14f4:\n"
    "ldr r1, .Lshop_common_1510\n"
#endif
    "adds r0, r4, r1\n"
    "strb r3, [r0]\n"
    "movs r2, #0xc9\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "ldr r0, [r1]\n"
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "ble .Lshop_common_152a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_1542\n"
#endif
    "cmp r0, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_14fc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1514\n"
#endif
    "cmp r0, #0x58\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1500\n"
    "b .Lshop_common_1504\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1518\n"
    "b .Lshop_common_151c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_14f8: .word 0x6a3\n"
    ".Lshop_common_14fc:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1510: .word 0x6a3\n"
    ".Lshop_common_1514:\n"
#endif
    "movs r0, #0x38\n"
#if defined(REGION_JP)
    "b .Lshop_common_1502\n"
    ".Lshop_common_1500:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_151a\n"
    ".Lshop_common_1518:\n"
#endif
    "movs r0, #0x48\n"
#if defined(REGION_JP)
    ".Lshop_common_1502:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_151a:\n"
#endif
    "str r0, [r1]\n"
#if defined(REGION_JP)
    ".Lshop_common_1504:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_151c:\n"
#endif
    "movs r0, #0xc9\n"
    "lsls r0, r0, #3\n"
    "adds r1, r4, r0\n"
    "ldr r0, [r1]\n"
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_151e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1536\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "ble .Lshop_common_157a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_1592\n"
#endif
    "cmp r0, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1522\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_153a\n"
#endif
    "cmp r0, #0x58\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1526\n"
    "b .Lshop_common_157a\n"
    ".Lshop_common_151e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_153e\n"
    "b .Lshop_common_1592\n"
    ".Lshop_common_1536:\n"
#endif
    "movs r0, #0x28\n"
#if defined(REGION_JP)
    "b .Lshop_common_1578\n"
    ".Lshop_common_1522:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1590\n"
    ".Lshop_common_153a:\n"
#endif
    "movs r0, #0x38\n"
#if defined(REGION_JP)
    "b .Lshop_common_1578\n"
    ".Lshop_common_1526:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1590\n"
    ".Lshop_common_153e:\n"
#endif
    "movs r0, #0x48\n"
#if defined(REGION_JP)
    "b .Lshop_common_1578\n"
    ".Lshop_common_152a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1590\n"
    ".Lshop_common_1542:\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "bne .Lshop_common_154c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1564\n"
#endif
    "movs r0, #0x28\n"
    "str r0, [r1]\n"
    "movs r1, #0xc\n"
    "ldrsh r0, [r4, r1]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_1540\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1558\n"
#endif
    "ldr r0, [r4, #0x10]\n"
    "subs r0, #1\n"
#if defined(REGION_JP)
    "b .Lshop_common_157e\n"
    ".Lshop_common_1540:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1596\n"
    ".Lshop_common_1558:\n"
#endif
    "movs r2, #0xd0\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "movs r0, #4\n"
    "rsbs r0, r0, #0\n"
#if defined(REGION_JP)
    "b .Lshop_common_1578\n"
    ".Lshop_common_154c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1590\n"
    ".Lshop_common_1564:\n"
#endif
    "movs r1, #0xc\n"
    "ldrsh r0, [r4, r1]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_1558\n"
    ".Lshop_common_1554:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1570\n"
    ".Lshop_common_156c:\n"
#endif
    "strh r3, [r4, #0xc]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_1558:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_1570:\n"
#endif
    "cmp r0, #0x10\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_156e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1586\n"
#endif
    "movs r2, #0xd0\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "movs r0, #4\n"
    "rsbs r0, r0, #0\n"
    "str r0, [r1]\n"
    "ldr r0, [r4, #0x10]\n"
    "subs r0, #1\n"
#if defined(REGION_JP)
    "b .Lshop_common_157e\n"
    ".Lshop_common_156e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1596\n"
    ".Lshop_common_1586:\n"
#endif
    "movs r0, #0xd0\n"
    "lsls r0, r0, #3\n"
    "adds r1, r4, r0\n"
    "movs r0, #8\n"
    "rsbs r0, r0, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_1578:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1590:\n"
#endif
    "str r0, [r1]\n"
#if defined(REGION_JP)
    ".Lshop_common_157a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1592:\n"
#endif
    "ldr r0, [r4, #0x10]\n"
    "subs r0, #2\n"
#if defined(REGION_JP)
    ".Lshop_common_157e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1596:\n"
#endif
    "str r0, [r4, #0x10]\n"
#if defined(REGION_JP)
    ".Lshop_common_1580:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1598:\n"
#endif
    "adds r0, r4, #0\n"
    "adds r0, #0x18\n"
    "movs r1, #0xcb\n"
    "bl Start__23HardwareMusicPlayerSlotUs\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_158c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_15a4:\n"
#endif
    "movs r6, #0\n"
    "adds r0, r4, #0\n"
    "bl GetHardwareRepeatedKeys\n"
    "lsrs r0, r0, #8\n"
    "movs r1, #1\n"
    "ands r1, r0\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_15a8\n"
    "ldr r0, .Lshop_common_15c0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_15c0\n"
    "ldr r0, .Lshop_common_15d8\n"
#endif
    "ands r0, r5\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_15a8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_15c0\n"
#endif
    "movs r6, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_15a8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_15c0:\n"
#endif
    "cmp r6, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1646\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_165e\n"
#endif
    "movs r1, #0xd4\n"
    "lsls r1, r1, #3\n"
    "adds r3, r4, r1\n"
    "ldrb r2, [r3]\n"
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_15c8\n"
    "ldr r2, .Lshop_common_15c4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_15e0\n"
    "ldr r2, .Lshop_common_15dc\n"
#endif
    "adds r0, r4, r2\n"
#if defined(REGION_JP)
    "b .Lshop_common_1678\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1690\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_15c0: .word 0x2ff\n"
    ".Lshop_common_15c4: .word 0x6a1\n"
    ".Lshop_common_15c8:\n"
    "ldr r1, .Lshop_common_15f8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_15d8: .word 0x2ff\n"
    ".Lshop_common_15dc: .word 0x6a1\n"
    ".Lshop_common_15e0:\n"
    "ldr r1, .Lshop_common_1610\n"
#endif
    "adds r0, r4, r1\n"
    "strb r2, [r0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_15fc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_1614\n"
#endif
    "adds r3, r4, r0\n"
    "ldrb r1, [r3]\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_169c\n"
    "ldr r2, .Lshop_common_1600\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_16b4\n"
    "ldr r2, .Lshop_common_1618\n"
#endif
    "adds r0, r4, r2\n"
    "strb r1, [r0]\n"
    "ldr r0, [r4, #0x1c]\n"
    "movs r1, #0xe\n"
    "ldrsh r0, [r0, r1]\n"
    "subs r0, #0xa0\n"
    "lsls r0, r0, #0x10\n"
    "movs r2, #0xc\n"
    "ldrsh r1, [r4, r2]\n"
    "lsrs r2, r0, #0x10\n"
    "asrs r0, r0, #0x10\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "blt .Lshop_common_1604\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "blt .Lshop_common_161c\n"
#endif
    "strh r2, [r4, #0xc]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_15f8: .word 0x6a1\n"
    ".Lshop_common_15fc: .word 0x6a2\n"
    ".Lshop_common_1600: .word 0x6a3\n"
    ".Lshop_common_1604:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1610: .word 0x6a1\n"
    ".Lshop_common_1614: .word 0x6a2\n"
    ".Lshop_common_1618: .word 0x6a3\n"
    ".Lshop_common_161c:\n"
#endif
    "movs r1, #0xd0\n"
    "lsls r1, r1, #3\n"
    "adds r0, r4, r1\n"
    "movs r1, #4\n"
    "str r1, [r0]\n"
    "adds r0, r4, #0\n"
    "adds r0, #0x18\n"
    "movs r1, #0xcb\n"
    "bl Start__23HardwareMusicPlayerSlotUs\n"
    "movs r2, #0xc9\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "ldr r0, [r1]\n"
    "cmp r0, #0x28\n"
#if defined(REGION_JP)
    "ble .Lshop_common_163e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ble .Lshop_common_1656\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1638\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1650\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_162e\n"
    "b .Lshop_common_1744\n"
    ".Lshop_common_162e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1646\n"
    "b .Lshop_common_175c\n"
    ".Lshop_common_1646:\n"
#endif
    "cmp r0, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_16fe\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1716\n"
#endif
    "cmp r0, #0x58\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1704\n"
    "b .Lshop_common_1744\n"
    ".Lshop_common_1638:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_171c\n"
    "b .Lshop_common_175c\n"
    ".Lshop_common_1650:\n"
#endif
    "movs r0, #0x28\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_163e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_1656:\n"
#endif
    "ldr r0, [r4, #0x10]\n"
    "adds r0, #1\n"
    "str r0, [r4, #0x10]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_1646:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_165e:\n"
#endif
    "movs r6, #0\n"
    "adds r0, r4, #0\n"
    "bl GetHardwareRepeatedKeys\n"
    "lsrs r0, r0, #8\n"
    "movs r1, #2\n"
    "ands r1, r0\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1662\n"
    "ldr r0, .Lshop_common_1684\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_167a\n"
    "ldr r0, .Lshop_common_169c\n"
#endif
    "ands r0, r5\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1662\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_167a\n"
#endif
    "movs r6, #1\n"
#if defined(REGION_JP)
    ".Lshop_common_1662:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_167a:\n"
#endif
    "adds r3, r6, #0\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1718\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1730\n"
#endif
    "movs r0, #0xd4\n"
    "lsls r0, r0, #3\n"
    "adds r3, r4, r0\n"
    "ldrb r2, [r3]\n"
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_168c\n"
    ".Lshop_common_1674:\n"
    "ldr r1, .Lshop_common_1688\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_16a4\n"
    ".Lshop_common_168c:\n"
    "ldr r1, .Lshop_common_16a0\n"
#endif
    "adds r0, r4, r1\n"
#if defined(REGION_JP)
    ".Lshop_common_1678:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1690:\n"
#endif
    "movs r2, #0\n"
    "movs r1, #1\n"
    "strb r1, [r0]\n"
    "strb r2, [r3]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_1684: .word 0x1ff\n"
    ".Lshop_common_1688: .word 0x6a1\n"
    ".Lshop_common_168c:\n"
    "ldr r1, .Lshop_common_16a8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_169c: .word 0x1ff\n"
    ".Lshop_common_16a0: .word 0x6a1\n"
    ".Lshop_common_16a4:\n"
    "ldr r1, .Lshop_common_16c0\n"
#endif
    "adds r0, r4, r1\n"
    "strb r2, [r0]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_16ac\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_16c4\n"
#endif
    "adds r3, r4, r0\n"
    "ldrb r1, [r3]\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_16b0\n"
    ".Lshop_common_169c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_16c8\n"
    ".Lshop_common_16b4:\n"
#endif
    "adds r0, #1\n"
    "adds r1, r4, r0\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
    "strb r2, [r3]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_16a8: .word 0x6a1\n"
    ".Lshop_common_16ac: .word 0x6a2\n"
    ".Lshop_common_16b0:\n"
    "ldr r2, .Lshop_common_16c4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_16c0: .word 0x6a1\n"
    ".Lshop_common_16c4: .word 0x6a2\n"
    ".Lshop_common_16c8:\n"
    "ldr r2, .Lshop_common_16dc\n"
#endif
    "adds r0, r4, r2\n"
    "strb r1, [r0]\n"
    "movs r2, #0xc\n"
    "ldrsh r0, [r4, r2]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_16c8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_16e0\n"
#endif
    "strh r1, [r4, #0xc]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_16c4: .word 0x6a3\n"
    ".Lshop_common_16c8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_16dc: .word 0x6a3\n"
    ".Lshop_common_16e0:\n"
#endif
    "movs r1, #0xd0\n"
    "lsls r1, r1, #3\n"
    "adds r0, r4, r1\n"
    "movs r1, #4\n"
    "rsbs r1, r1, #0\n"
    "str r1, [r0]\n"
    "adds r0, r4, #0\n"
    "adds r0, #0x18\n"
    "movs r1, #0xcb\n"
    "bl Start__23HardwareMusicPlayerSlotUs\n"
    "movs r2, #0xc9\n"
    "lsls r2, r2, #3\n"
    "adds r1, r4, r2\n"
    "ldr r0, [r1]\n"
    "cmp r0, #0x57\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_1710\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1728\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1704\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_171c\n"
#endif
    "cmp r0, #0x38\n"
#if defined(REGION_JP)
    "bgt .Lshop_common_16f8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bgt .Lshop_common_1710\n"
#endif
    "cmp r0, #0x28\n"
#if defined(REGION_JP)
    "beq .Lshop_common_16fe\n"
    "b .Lshop_common_1744\n"
    ".Lshop_common_16f8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1716\n"
    "b .Lshop_common_175c\n"
    ".Lshop_common_1710:\n"
#endif
    "cmp r0, #0x48\n"
#if defined(REGION_JP)
    "beq .Lshop_common_170a\n"
    "b .Lshop_common_1744\n"
    ".Lshop_common_16fe:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1722\n"
    "b .Lshop_common_175c\n"
    ".Lshop_common_1716:\n"
#endif
    "movs r0, #0x38\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_1704:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_171c:\n"
#endif
    "movs r0, #0x48\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_170a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_1722:\n"
#endif
    "movs r0, #0x58\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_1710:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_1728:\n"
#endif
    "ldr r0, [r4, #0x10]\n"
    "subs r0, #1\n"
    "str r0, [r4, #0x10]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_1718:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_1730:\n"
#endif
    "movs r0, #0xd4\n"
    "lsls r0, r0, #3\n"
    "adds r2, r4, r0\n"
    "ldrb r5, [r2]\n"
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1730\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1748\n"
#endif
    "adds r0, #1\n"
    "adds r1, r4, r0\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
    "strb r3, [r2]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1744\n"
    ".Lshop_common_1730:\n"
    "ldr r1, .Lshop_common_174c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_175c\n"
    ".Lshop_common_1748:\n"
    "ldr r1, .Lshop_common_1764\n"
#endif
    "adds r2, r4, r1\n"
    "ldrb r0, [r2]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1744\n"
    "ldr r0, .Lshop_common_1750\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_175c\n"
    "ldr r0, .Lshop_common_1768\n"
#endif
    "adds r1, r4, r0\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
    "strb r5, [r2]\n"
#if defined(REGION_JP)
    ".Lshop_common_1744:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_175c:\n"
#endif
    "pop {r4, r5, r6, r7}\n"
    "pop {r0}\n"
    "bx r0\n"
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_174c: .word 0x6a2\n"
    ".Lshop_common_1750: .word 0x6a3\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1764: .word 0x6a2\n"
    ".Lshop_common_1768: .word 0x6a3\n"
#endif
    "thumb_func_start UpdateShopScreenDisplay\n"
    "UpdateShopScreenDisplay:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "mov r7, sl\n"
    "mov r6, sb\n"
    "mov r5, r8\n"
    "push {r5, r6, r7}\n"
#if defined(REGION_JP)
    "sub sp, #0xd8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "sub sp, #0xf8\n"
#endif
    "mov sl, r0\n"
    "movs r0, #1\n"
#if defined(REGION_JP)
    "str r0, [sp, #0xa4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [sp, #0xb8]\n"
#endif
    "mov r0, sl\n"
    "bl GetHardwareSpriteBuffer\n"
    "adds r5, r0, #0\n"
    "movs r0, #0xd5\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjTileIndex\n"
    "adds r4, r0, #0\n"
    "movs r0, #0xd7\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "str r0, [sp]\n"
    "movs r0, #0\n"
    "str r0, [sp, #4]\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xa4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0xb8]\n"
#endif
    "str r1, [sp, #8]\n"
    "str r0, [sp, #0xc]\n"
#if defined(REGION_JP)
    "add r6, sp, #0x5c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r6, sp, #0x68\n"
#endif
    "adds r0, r6, #0\n"
    "movs r1, #0x10\n"
    "movs r2, #4\n"
    "adds r3, r4, #0\n"
    "bl InitializeMosaicSpriteOam\n"
    "ldrb r2, [r5]\n"
    "cmp r2, #0x7f\n"
#if defined(REGION_JP)
    "bhi .Lshop_common_17ba\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bhi .Lshop_common_17d2\n"
#endif
    "lsls r0, r2, #3\n"
    "adds r0, #4\n"
    "adds r0, r5, r0\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0x5c]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0x68]\n"
#endif
    "str r1, [r0]\n"
    "ldrh r1, [r6, #4]\n"
    "strh r1, [r0, #4]\n"
    "adds r0, r2, #1\n"
    "strb r0, [r5]\n"
#if defined(REGION_JP)
    ".Lshop_common_17ba:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_17d2:\n"
#endif
    "movs r2, #0xd2\n"
    "lsls r2, r2, #2\n"
    "add r2, sl\n"
    "mov r8, r2\n"
    "mov r0, r8\n"
    "bl GetState__C12UiStateOwner\n"
    "movs r1, #0xd3\n"
    "lsls r1, r1, #2\n"
    "add r1, sl\n"
    "str r0, [r1]\n"
    "mov r0, sl\n"
    "bl GetHardwareCoreState\n"
    "mov sb, r0\n"
    "mov r0, sl\n"
    "bl GetHardwareSpriteBuffer\n"
    "adds r6, r0, #0\n"
    "mov r0, sl\n"
    "bl GetHardwareDisplayState\n"
    "adds r5, r0, #0\n"
    "mov r0, sl\n"
    "bl GetHardwareCommandList\n"
    "adds r4, r0, #0\n"
    "mov r0, sl\n"
    "bl GetHardwareInterruptList\n"
    "mov r1, sl\n"
    "adds r1, #0x18\n"
    "str r4, [sp]\n"
    "str r0, [sp, #4]\n"
    "str r1, [sp, #8]\n"
    "mov r0, r8\n"
    "mov r1, sb\n"
    "adds r2, r6, #0\n"
    "adds r3, r5, #0\n"
    "bl Update__C12UiStateOwnerP18HardwareInputStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot\n"
    "movs r1, #0xd4\n"
    "lsls r1, r1, #2\n"
    "add r1, sl\n"
    "str r0, [r1]\n"
    "movs r3, #0\n"
#if defined(REGION_JP)
    "str r3, [sp, #0xa4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r3, [sp, #0xb8]\n"
#endif
    "cmp r0, #3\n"
#if defined(REGION_JP)
    "bne .Lshop_common_182a\n"
    "ldr r0, .Lshop_common_1908\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1842\n"
    "ldr r0, .Lshop_common_194c\n"
#endif
    "add r0, sl\n"
    "ldrb r0, [r0, #8]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_182a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1842\n"
#endif
    "movs r4, #1\n"
#if defined(REGION_JP)
    "str r4, [sp, #0xa4]\n"
    ".Lshop_common_182a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r4, [sp, #0xb8]\n"
    ".Lshop_common_1842:\n"
#endif
    "mov r5, sl\n"
#if defined(REGION_JP)
    "ldr r3, [r5, #0x20]\n"
    "mov r6, sp\n"
    "adds r6, #0x20\n"
    "str r6, [sp, #0xb8]\n"
    "cmp r3, #0\n"
    "bne .Lshop_common_183a\n"
    "b .Lshop_common_1b5a\n"
    ".Lshop_common_183a:\n"
    "movs r7, #0\n"
    "mov r8, r7\n"
    "adds r5, #0x20\n"
    "str r5, [sp, #0xbc]\n"
    "mov r0, sl\n"
    "movs r1, #0xc\n"
    "ldrsh r4, [r0, r1]\n"
    "adds r2, r3, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [r5, #0x20]\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_184c\n"
    "b .Lshop_common_1d80\n"
    ".Lshop_common_184c:\n"
    "movs r4, #0\n"
    "str r0, [sp, #0xbc]\n"
    "movs r7, #0xc\n"
    "ldrsh r0, [r5, r7]\n"
    "adds r2, r0, #0\n"
    "subs r2, #8\n"
    "mov r0, sp\n"
    "adds r0, #0x28\n"
    "str r0, [sp, #0xdc]\n"
    "ldr r1, [sp, #0xbc]\n"
    "cmp r4, r1\n"
    "bhs .Lshop_common_1882\n"
    "movs r3, #0x24\n"
    "ldrsh r0, [r5, r3]\n"
    "cmp r0, r2\n"
    "bge .Lshop_common_1882\n"
#endif
    "mov r1, sl\n"
    "adds r1, #0x24\n"
#if defined(REGION_JP)
    ".Lshop_common_184e:\n"
    "movs r5, #0\n"
    "ldrsh r0, [r1, r5]\n"
    "adds r0, #8\n"
    "cmp r0, r4\n"
    "bge .Lshop_common_1862\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1870:\n"
#endif
    "adds r1, #0x10\n"
#if defined(REGION_JP)
    "movs r6, #1\n"
    "add r8, r6\n"
    "cmp r8, r2\n"
    "blo .Lshop_common_184e\n"
    ".Lshop_common_1862:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r4, #1\n"
    "ldr r5, [sp, #0xbc]\n"
    "cmp r4, r5\n"
    "bhs .Lshop_common_1882\n"
#endif
    "movs r7, #0\n"
#if defined(REGION_JP)
    "str r7, [sp, #0xa8]\n"
    "cmp r8, r3\n"
    "blo .Lshop_common_186c\n"
    "b .Lshop_common_1b5a\n"
    ".Lshop_common_186c:\n"
    "mov r0, r8\n"
    "lsls r1, r0, #4\n"
    "adds r0, r1, #4\n"
    "ldr r2, [sp, #0xbc]\n"
    "adds r5, r2, r0\n"
    "movs r4, #0\n"
    "ldrsh r2, [r5, r4]\n"
    "mov r6, sl\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldrsh r0, [r1, r7]\n"
    "cmp r0, r2\n"
    "blt .Lshop_common_1870\n"
    ".Lshop_common_1882:\n"
    "movs r0, #0\n"
    "str r0, [sp, #0xd0]\n"
    "str r0, [sp, #0x14]\n"
    "movs r0, #0x18\n"
    "bl malloc\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_1898\n"
    "movs r0, #0x18\n"
    "bl RetryMemoryAllocation\n"
    ".Lshop_common_1898:\n"
    "str r0, [sp, #0x14]\n"
    "ldr r1, [sp, #0xd0]\n"
    "str r1, [sp, #0x18]\n"
    "str r1, [sp, #0x1c]\n"
    "strb r1, [r0]\n"
    "ldr r3, [sp, #0xd0]\n"
    "str r3, [r0, #4]\n"
    "ldr r0, [sp, #0x14]\n"
    "str r0, [r0, #8]\n"
    "ldr r0, [sp, #0x14]\n"
    "str r0, [r0, #0xc]\n"
    "movs r5, #0\n"
    "str r5, [sp, #0xd4]\n"
    "str r5, [sp, #0x2c]\n"
    "movs r0, #0x18\n"
    "bl malloc\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_18c4\n"
    "movs r0, #0x18\n"
    "bl RetryMemoryAllocation\n"
    ".Lshop_common_18c4:\n"
    "str r0, [sp, #0x2c]\n"
    "ldr r7, [sp, #0xd4]\n"
    "ldr r1, [sp, #0xdc]\n"
    "str r7, [r1, #8]\n"
    "str r7, [sp, #0x34]\n"
    "strb r7, [r0]\n"
    "ldr r3, [sp, #0xd4]\n"
    "str r3, [r0, #4]\n"
    "ldr r0, [sp, #0x2c]\n"
    "str r0, [r0, #8]\n"
    "ldr r0, [sp, #0x2c]\n"
    "str r0, [r0, #0xc]\n"
    "mov r5, sl\n"
#endif
    "movs r7, #0xc\n"
#if defined(REGION_JP)
    "ldrsh r0, [r6, r7]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldrsh r0, [r5, r7]\n"
#endif
    "adds r0, #0x68\n"
#if defined(REGION_JP)
    "str r1, [sp, #0xcc]\n"
    "mov r1, r8\n"
    "adds r1, #1\n"
    "str r1, [sp, #0xc4]\n"
    "cmp r2, r0\n"
    "ble .Lshop_common_1890\n"
    "b .Lshop_common_1b50\n"
    ".Lshop_common_1890:\n"
    "ldr r2, [sp, #0xa8]\n"
    "lsls r4, r2, #3\n"
    "adds r0, r4, r6\n"
    "movs r3, #0xe9\n"
    "lsls r3, r3, #2\n"
    "adds r0, r0, r3\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [sp, #0xc0]\n"
    "ldr r0, [sp, #0xbc]\n"
    "cmp r4, r0\n"
    "blo .Lshop_common_18ee\n"
    "b .Lshop_common_1d2a\n"
    ".Lshop_common_18ee:\n"
    "mov r1, sl\n"
    "adds r1, #0x20\n"
    "lsls r2, r4, #4\n"
    "adds r0, r2, #4\n"
    "adds r0, r1, r0\n"
    "movs r3, #0\n"
    "ldrsh r0, [r0, r3]\n"
    "str r1, [sp, #0xe0]\n"
    "str r2, [sp, #0xec]\n"
    "ldr r5, [sp, #0xc0]\n"
    "cmp r0, r5\n"
    "ble .Lshop_common_1908\n"
    "b .Lshop_common_1d2a\n"
    ".Lshop_common_1908:\n"
    "mov r7, sp\n"
    "adds r7, #0x20\n"
    "str r7, [sp, #0xcc]\n"
    "mov r0, sp\n"
    "adds r0, #0x24\n"
    "str r0, [sp, #0xd8]\n"
    "mov r1, sp\n"
    "adds r1, #0x7c\n"
    "str r1, [sp, #0xe8]\n"
    ".Lshop_common_191a:\n"
    "ldr r0, [sp, #0xec]\n"
    "adds r0, #4\n"
    "ldr r2, [sp, #0xe0]\n"
    "adds r0, r2, r0\n"
    "str r0, [sp, #0xc4]\n"
    "ldr r0, [r0, #8]\n"
    "str r0, [sp, #0x70]\n"
    "ldr r3, [sp, #0x14]\n"
    "ldr r1, [r3, #4]\n"
    "adds r4, #1\n"
    "str r4, [sp, #0xe4]\n"
    "adds r5, r3, #0\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_1956\n"
    "adds r4, r0, #0\n"
    ".Lshop_common_1938:\n"
    "movs r2, #0\n"
    "ldr r0, [r1, #0x10]\n"
    "cmp r0, r4\n"
    "bhs .Lshop_common_1942\n"
    "movs r2, #1\n"
    ".Lshop_common_1942:\n"
    "cmp r2, #0\n"
    "bne .Lshop_common_1950\n"
    "adds r3, r1, #0\n"
    "ldr r1, [r3, #8]\n"
    "b .Lshop_common_1952\n"
    ".align 2, 0\n"
    ".Lshop_common_194c: .word 0x684\n"
    ".Lshop_common_1950:\n"
    "ldr r1, [r1, #0xc]\n"
    ".Lshop_common_1952:\n"
    "cmp r1, #0\n"
    "bne .Lshop_common_1938\n"
    ".Lshop_common_1956:\n"
    "ldr r4, [sp, #0xcc]\n"
    "str r3, [r4]\n"
    "movs r2, #0\n"
    "str r5, [sp, #0x24]\n"
    "movs r1, #0\n"
    "ldr r0, [sp, #0x20]\n"
    "cmp r0, r5\n"
    "bne .Lshop_common_1968\n"
    "movs r1, #1\n"
    ".Lshop_common_1968:\n"
    "cmp r1, #0\n"
    "bne .Lshop_common_1974\n"
    "ldr r1, [sp, #0x70]\n"
    "ldr r0, [r0, #0x10]\n"
    "cmp r1, r0\n"
    "bhs .Lshop_common_197c\n"
    ".Lshop_common_1974:\n"
    "ldr r5, [sp, #0xd0]\n"
    "cmp r5, #8\n"
    "bgt .Lshop_common_197c\n"
    "movs r2, #1\n"
    ".Lshop_common_197c:\n"
    "cmp r2, #0\n"
    "bne .Lshop_common_1982\n"
    "b .Lshop_common_1ad6\n"
    ".Lshop_common_1982:\n"
    "ldr r0, [sp, #0x20]\n"
    "str r0, [sp, #0x3c]\n"
    "add r1, sp, #0x48\n"
    "ldr r0, [sp, #0x70]\n"
    "str r0, [sp, #0x48]\n"
    "ldr r7, [sp, #0xd0]\n"
    "str r7, [sp, #0x4c]\n"
    "adds r0, r1, #0\n"
    "movs r2, #8\n"
    "bl memcpy\n"
    "ldr r0, [sp, #0x48]\n"
    "str r0, [sp, #0x40]\n"
    "ldr r0, [sp, #0x4c]\n"
    "str r0, [sp, #0x44]\n"
    "ldr r0, [sp, #0x3c]\n"
    "str r0, [sp, #0x50]\n"
    "add r0, sp, #0x38\n"
    "add r1, sp, #0x10\n"
    "add r2, sp, #0x50\n"
    "add r3, sp, #0x40\n"
    "bl InsertShopResourceSlotWithHint\n"
    "add r4, sp, #0x38\n"
    "lsls r0, r7, #3\n"
    "add r0, sl\n"
    "movs r1, #0xe9\n"
    "lsls r1, r1, #2\n"
    "adds r0, r0, r1\n"
#endif
    "ldr r1, [r0, #4]\n"
    "bl GetObjTileIndex\n"
#if defined(REGION_JP)
    "str r0, [sp, #0xac]\n"
    "add r4, sl\n"
    "movs r6, #0xfb\n"
    "lsls r6, r6, #2\n"
    "adds r4, r4, r6\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl GetObjPaletteBank\n"
    "str r0, [sp, #0xb0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [sp, #0xc8]\n"
#endif
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
    "adds r6, r0, #0\n"
#if defined(REGION_JP)
    "ldr r1, [r5, #8]\n"
    "ldr r7, [sp, #0xac]\n"
    "lsls r2, r7, #5\n"
    "ldr r0, .Lshop_common_190c\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #0x10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0x70]\n"
    "ldr r3, [sp, #0xc8]\n"
    "lsls r2, r3, #5\n"
    "ldr r5, .Lshop_common_1a00\n"
    "adds r2, r2, r5\n"
    "adds r0, r4, #0\n"
#endif
    "movs r3, #0x80\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "mov r1, sp\n"
    "adds r1, #0x10\n"
    "str r1, [sp, #0xb4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #0xc]\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1910\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1a04\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_18ee\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_19f8\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x10\n"
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, sb\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
#endif
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_18ee:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_19f8:\n"
#endif
    "ldr r0, [r6, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r6, #4]\n"
#if defined(REGION_JP)
    "ldr r5, [sp, #0xb0]\n"
    "lsls r5, r5, #5\n"
    "mov r8, r5\n"
    "mov r6, sp\n"
    "adds r6, #0x74\n"
    "str r6, [sp, #0xc0]\n"
    "ldr r7, [sp, #0xa8]\n"
    "adds r7, #1\n"
    "str r7, [sp, #0xc8]\n"
    "b .Lshop_common_19ec\n"
    ".Lshop_common_1908: .word 0x684\n"
    ".Lshop_common_190c: .word 0x6010000\n"
    ".Lshop_common_1910:\n"
    "str r1, [sp, #0xd0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1ace\n"
    ".align 2, 0\n"
    ".Lshop_common_1a00: .word OBJ_VRAM0\n"
    ".Lshop_common_1a04:\n"
    "str r1, [sp, #0xf0]\n"
#endif
    "movs r0, #1\n"
#if defined(REGION_JP)
    "str r0, [sp, #0x68]\n"
    "ldr r0, [r6]\n"
    "subs r0, r1, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r0, [sp, #0x78]\n"
    "ldr r1, [r6]\n"
    "ldr r4, [sp, #0xf0]\n"
    "subs r0, r4, r1\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "str r4, [sp, #0x64]\n"
    "add r1, sp, #0x68\n"
    "add r0, sp, #0x64\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r4, [sp, #0x74]\n"
    "add r2, sp, #0x78\n"
    "add r0, sp, #0x74\n"
#endif
    "cmp r4, #1\n"
#if defined(REGION_JP)
    "bhs .Lshop_common_1928\n"
    "adds r0, r1, #0\n"
    ".Lshop_common_1928:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bhs .Lshop_common_1a1e\n"
    "adds r0, r2, #0\n"
    ".Lshop_common_1a1e:\n"
#endif
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1946\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1a3e\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov sb, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r8, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_194a\n"
    "mov r0, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1a3a\n"
    "mov r0, r8\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_194a\n"
    ".Lshop_common_1946:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1a3a:\n"
    "ldr r1, [r6]\n"
    "b .Lshop_common_1a42\n"
    ".Lshop_common_1a3e:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov sb, r0\n"
    ".Lshop_common_194a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r8, r0\n"
    ".Lshop_common_1a42:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #0xd4]\n"
    "ldr r2, [r6]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #0xf4]\n"
    "adds r2, r1, #0\n"
#endif
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "mov r4, r8\n"
    "adds r4, #1\n"
    "str r4, [sp, #0xc4]\n"
    "ldr r5, [sp, #0xb0]\n"
    "lsls r5, r5, #5\n"
    "mov r8, r5\n"
    "mov r7, sp\n"
    "adds r7, #0x74\n"
    "str r7, [sp, #0xc0]\n"
    "ldr r0, [sp, #0xa8]\n"
    "adds r0, #1\n"
    "str r0, [sp, #0xc8]\n"
    "ldr r1, [sp, #0xd0]\n"
    "cmp r2, r1\n"
    "beq .Lshop_common_198a\n"
    ".Lshop_common_1970:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, [sp, #0xf0]\n"
    "cmp r2, r5\n"
    "beq .Lshop_common_1a6a\n"
    ".Lshop_common_1a50:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1980\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1a60\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1980:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1a60:\n"
#endif
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0xd0]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_1970\n"
    ".Lshop_common_198a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0xf0]\n"
    "cmp r2, r7\n"
    "bne .Lshop_common_1a50\n"
    ".Lshop_common_1a6a:\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0x68]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [sp, #0x78]\n"
#endif
    "cmp r0, #1\n"
#if defined(REGION_JP)
    "bne .Lshop_common_19a6\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1a86\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_19a2\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1a82\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xb4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, sb\n"
#endif
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_19a2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1a82:\n"
#endif
    "adds r5, #0x10\n"
#if defined(REGION_JP)
    "b .Lshop_common_19c8\n"
    ".Lshop_common_19a6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1aa8\n"
    ".Lshop_common_1a86:\n"
#endif
    "adds r3, r0, #0\n"
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_19c6\n"
    ".Lshop_common_19ae:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1aa6\n"
    ".Lshop_common_1a8e:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_19be\n"
    "adds r0, r2, #0\n"
    "ldr r1, [sp, #0xb4]\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lshop_common_19be:\n"
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
    "bne .Lshop_common_19ae\n"
    ".Lshop_common_19c6:\n"
    "adds r5, r2, #0\n"
    ".Lshop_common_19c8:\n"
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
    "beq .Lshop_common_19d8\n"
    ".Lshop_common_19d2:\n"
    "adds r1, #0x10\n"
    "cmp r1, r2\n"
    "bne .Lshop_common_19d2\n"
    ".Lshop_common_19d8:\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_19e0\n"
    "bl free\n"
    ".Lshop_common_19e0:\n"
    "ldr r0, [sp, #0xd4]\n"
    "add r0, sb\n"
    "ldr r7, [sp, #0xd4]\n"
    "str r7, [r6]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #0xc]\n"
    ".Lshop_common_19ec:\n"
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
    "ldr r1, [sp, #0xcc]\n"
    "adds r1, #4\n"
    "ldr r2, [sp, #0xbc]\n"
    "adds r1, r2, r1\n"
    "adds r6, r0, #0\n"
    "ldr r1, [r1, #0xc]\n"
    "ldr r2, .Lshop_common_1a30\n"
    "add r2, r8\n"
    "add r0, sp, #0x10\n"
    "movs r3, #0x20\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
    "add r3, sp, #0x10\n"
    "mov sb, r3\n"
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #0xc]\n"
    "cmp r1, r0\n"
    "beq .Lshop_common_1a34\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_1a26\n"
    "adds r0, r1, #0\n"
    "add r1, sp, #0x10\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lshop_common_1a26:\n"
    "ldr r0, [r6, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r6, #4]\n"
    "b .Lshop_common_1af8\n"
    ".align 2, 0\n"
    ".Lshop_common_1a30: .word 0x5000200\n"
    ".Lshop_common_1a34:\n"
    "str r1, [sp, #0xd0]\n"
    "movs r0, #1\n"
    "str r0, [sp, #0x70]\n"
    "ldr r0, [r6]\n"
    "subs r0, r1, r0\n"
    "asrs r4, r0, #4\n"
    "str r4, [sp, #0x6c]\n"
    "add r1, sp, #0x70\n"
    "add r0, sp, #0x6c\n"
    "cmp r4, #1\n"
    "bhs .Lshop_common_1a4c\n"
    "adds r0, r1, #0\n"
    ".Lshop_common_1a4c:\n"
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1a6a\n"
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
    "mov r8, r4\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_1a6e\n"
    "mov r0, r8\n"
    "bl RetryMemoryAllocation\n"
    "b .Lshop_common_1a6e\n"
    ".Lshop_common_1a6a:\n"
    "movs r0, #0\n"
    "mov r8, r0\n"
    ".Lshop_common_1a6e:\n"
    "adds r5, r0, #0\n"
    "str r5, [sp, #0xd4]\n"
    "ldr r2, [r6]\n"
    "adds r3, r5, #0\n"
    "ldr r4, [sp, #0xd0]\n"
    "cmp r2, r4\n"
    "beq .Lshop_common_1a96\n"
    ".Lshop_common_1a7c:\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_1a8c\n"
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lshop_common_1a8c:\n"
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
    "ldr r5, [sp, #0xd0]\n"
    "cmp r2, r5\n"
    "bne .Lshop_common_1a7c\n"
    ".Lshop_common_1a96:\n"
    "adds r5, r3, #0\n"
    "ldr r0, [sp, #0x70]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_1ab2\n"
    "cmp r5, #0\n"
    "beq .Lshop_common_1aae\n"
    "adds r0, r5, #0\n"
    "mov r1, sb\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lshop_common_1aae:\n"
    "adds r5, #0x10\n"
    "b .Lshop_common_1ad4\n"
    ".Lshop_common_1ab2:\n"
    "adds r3, r0, #0\n"
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_1ad2\n"
    ".Lshop_common_1aba:\n"
    "cmp r2, #0\n"
    "beq .Lshop_common_1aca\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1a9e\n"
#endif
    "adds r0, r2, #0\n"
    "mov r1, sb\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1aca:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1a9e:\n"
#endif
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1aba\n"
    ".Lshop_common_1ad2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1a8e\n"
    ".Lshop_common_1aa6:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_1ad4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1aa8:\n"
#endif
    "ldr r2, [r6, #4]\n"
#if defined(REGION_JP)
    "ldr r0, [r6]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
    "beq .Lshop_common_1ae4\n"
    ".Lshop_common_1ade:\n"
    "adds r1, #0x10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [r6]\n"
    "adds r0, r1, #0\n"
#endif
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1ade\n"
    ".Lshop_common_1ae4:\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1aec\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1ab8\n"
    ".Lshop_common_1ab2:\n"
    "adds r0, #0x10\n"
    "cmp r0, r2\n"
    "bne .Lshop_common_1ab2\n"
    ".Lshop_common_1ab8:\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_1ac2\n"
    "adds r0, r1, #0\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_1aec:\n"
    "ldr r0, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1ac2:\n"
    "ldr r0, [sp, #0xf4]\n"
#endif
    "add r0, r8\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xd4]\n"
    "str r1, [r6]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0xf4]\n"
    "str r7, [r6]\n"
#endif
    "str r5, [r6, #4]\n"
    "str r0, [r6, #0xc]\n"
#if defined(REGION_JP)
    ".Lshop_common_1af8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1ace:\n"
    "ldr r0, [sp, #0xd0]\n"
    "adds r0, #1\n"
    "str r0, [sp, #0xd0]\n"
    "b .Lshop_common_1aec\n"
    ".Lshop_common_1ad6:\n"
    "ldr r0, [sp, #0x20]\n"
    "ldr r0, [r0, #0x14]\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "movs r1, #0xe9\n"
    "lsls r1, r1, #2\n"
    "adds r0, r0, r1\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjTileIndex\n"
    "str r0, [sp, #0xc8]\n"
    ".Lshop_common_1aec:\n"
    "ldr r2, [sp, #0xc4]\n"
    "ldr r0, [r2, #0xc]\n"
    "str r0, [sp, #0x7c]\n"
    "ldr r6, [sp, #0xd8]\n"
    "ldr r3, [sp, #0x2c]\n"
    "ldr r1, [r3, #4]\n"
    "adds r5, r3, #0\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_1b1c\n"
    "ldr r7, [sp, #0xe8]\n"
    "ldr r4, [r7]\n"
    ".Lshop_common_1b02:\n"
    "movs r2, #0\n"
    "ldr r0, [r1, #0x10]\n"
    "cmp r0, r4\n"
    "bhs .Lshop_common_1b0c\n"
    "movs r2, #1\n"
    ".Lshop_common_1b0c:\n"
    "cmp r2, #0\n"
    "bne .Lshop_common_1b16\n"
    "adds r3, r1, #0\n"
    "ldr r1, [r3, #8]\n"
    "b .Lshop_common_1b18\n"
    ".Lshop_common_1b16:\n"
    "ldr r1, [r1, #0xc]\n"
    ".Lshop_common_1b18:\n"
    "cmp r1, #0\n"
    "bne .Lshop_common_1b02\n"
    ".Lshop_common_1b1c:\n"
    "str r3, [r6]\n"
    "movs r2, #0\n"
    "str r5, [sp, #0x38]\n"
    "movs r1, #0\n"
    "ldr r0, [sp, #0x24]\n"
    "cmp r0, r5\n"
    "bne .Lshop_common_1b2c\n"
    "movs r1, #1\n"
    ".Lshop_common_1b2c:\n"
    "cmp r1, #0\n"
    "bne .Lshop_common_1b38\n"
    "ldr r1, [sp, #0x7c]\n"
    "ldr r0, [r0, #0x10]\n"
    "cmp r1, r0\n"
    "bhs .Lshop_common_1b40\n"
    ".Lshop_common_1b38:\n"
    "ldr r0, [sp, #0xd4]\n"
    "cmp r0, #8\n"
    "bgt .Lshop_common_1b40\n"
    "movs r2, #1\n"
    ".Lshop_common_1b40:\n"
    "cmp r2, #0\n"
    "bne .Lshop_common_1b46\n"
    "b .Lshop_common_1c9a\n"
    ".Lshop_common_1b46:\n"
    "ldr r0, [sp, #0x24]\n"
    "str r0, [sp, #0x40]\n"
    "add r1, sp, #0x4c\n"
    "ldr r0, [sp, #0x7c]\n"
    "str r0, [sp, #0x4c]\n"
    "ldr r2, [sp, #0xd4]\n"
    "str r2, [sp, #0x50]\n"
    "adds r0, r1, #0\n"
    "movs r2, #8\n"
    "bl memcpy\n"
    "ldr r0, [sp, #0x4c]\n"
    "str r0, [sp, #0x44]\n"
    "ldr r0, [sp, #0x50]\n"
    "str r0, [sp, #0x48]\n"
    "ldr r0, [sp, #0x40]\n"
    "str r0, [sp, #0x54]\n"
    "add r0, sp, #0x3c\n"
    "add r1, sp, #0x28\n"
    "add r2, sp, #0x54\n"
    "add r3, sp, #0x44\n"
    "bl InsertShopResourceSlotWithHint\n"
    "add r4, sp, #0x3c\n"
    "ldr r3, [sp, #0xd4]\n"
    "lsls r0, r3, #3\n"
    "add r0, sl\n"
    "movs r5, #0xfb\n"
    "lsls r5, r5, #2\n"
    "adds r0, r0, r5\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "mov sb, r0\n"
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
    "adds r6, r0, #0\n"
    "ldr r1, [sp, #0x7c]\n"
    "mov r7, sb\n"
    "lsls r2, r7, #5\n"
    "ldr r0, .Lshop_common_1bc4\n"
    "adds r2, r2, r0\n"
    "adds r0, r4, #0\n"
    "movs r3, #0x20\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #0xc]\n"
    "cmp r1, r0\n"
    "beq .Lshop_common_1bc8\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_1bbc\n"
    "adds r0, r1, #0\n"
    "add r1, sp, #0x3c\n"
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lshop_common_1bbc:\n"
    "ldr r0, [r6, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r6, #4]\n"
    "b .Lshop_common_1c92\n"
    ".align 2, 0\n"
    ".Lshop_common_1bc4: .word OBJ_PLTT\n"
    ".Lshop_common_1bc8:\n"
    "str r1, [sp, #0xf0]\n"
    "movs r0, #1\n"
    "str r0, [sp, #0x84]\n"
    "ldr r1, [r6]\n"
    "ldr r5, [sp, #0xf0]\n"
    "subs r0, r5, r1\n"
    "asrs r4, r0, #4\n"
    "str r4, [sp, #0x80]\n"
    "add r2, sp, #0x84\n"
    "add r0, sp, #0x80\n"
    "cmp r4, #1\n"
    "bhs .Lshop_common_1be2\n"
    "adds r0, r2, #0\n"
    ".Lshop_common_1be2:\n"
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1c02\n"
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
    "mov r8, r4\n"
    "cmp r0, #0\n"
    "bne .Lshop_common_1bfe\n"
    "mov r0, r8\n"
    "bl RetryMemoryAllocation\n"
    ".Lshop_common_1bfe:\n"
    "ldr r1, [r6]\n"
    "b .Lshop_common_1c06\n"
    ".Lshop_common_1c02:\n"
    "movs r0, #0\n"
    "mov r8, r0\n"
    ".Lshop_common_1c06:\n"
    "adds r5, r0, #0\n"
    "str r5, [sp, #0xf4]\n"
    "adds r2, r1, #0\n"
    "adds r3, r5, #0\n"
    "ldr r7, [sp, #0xf0]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_1c2e\n"
    ".Lshop_common_1c14:\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_1c24\n"
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lshop_common_1c24:\n"
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
    "ldr r0, [sp, #0xf0]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_1c14\n"
    ".Lshop_common_1c2e:\n"
    "adds r5, r3, #0\n"
    "ldr r0, [sp, #0x84]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_1c4a\n"
    "cmp r5, #0\n"
    "beq .Lshop_common_1c46\n"
    "adds r0, r5, #0\n"
    "add r1, sp, #0x3c\n"
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lshop_common_1c46:\n"
    "adds r5, #0x10\n"
    "b .Lshop_common_1c6c\n"
    ".Lshop_common_1c4a:\n"
    "adds r3, r0, #0\n"
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
    "beq .Lshop_common_1c6a\n"
    ".Lshop_common_1c52:\n"
    "cmp r2, #0\n"
    "beq .Lshop_common_1c62\n"
    "adds r0, r2, #0\n"
    "add r1, sp, #0x3c\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lshop_common_1c62:\n"
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
    "bne .Lshop_common_1c52\n"
    ".Lshop_common_1c6a:\n"
    "adds r5, r2, #0\n"
    ".Lshop_common_1c6c:\n"
    "ldr r2, [r6, #4]\n"
    "ldr r1, [r6]\n"
    "adds r0, r1, #0\n"
    "cmp r1, r2\n"
    "beq .Lshop_common_1c7c\n"
    ".Lshop_common_1c76:\n"
    "adds r0, #0x10\n"
    "cmp r0, r2\n"
    "bne .Lshop_common_1c76\n"
    ".Lshop_common_1c7c:\n"
    "cmp r1, #0\n"
    "beq .Lshop_common_1c86\n"
    "adds r0, r1, #0\n"
    "bl free\n"
    ".Lshop_common_1c86:\n"
    "ldr r0, [sp, #0xf4]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #0xf4]\n"
    "str r7, [r6]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #0xc]\n"
    ".Lshop_common_1c92:\n"
    "ldr r0, [sp, #0xd4]\n"
    "adds r0, #1\n"
    "str r0, [sp, #0xd4]\n"
    "b .Lshop_common_1cb0\n"
    ".Lshop_common_1c9a:\n"
    "ldr r0, [sp, #0x24]\n"
    "ldr r0, [r0, #0x14]\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "movs r1, #0xfb\n"
    "lsls r1, r1, #2\n"
    "adds r0, r0, r1\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
    "mov sb, r0\n"
    ".Lshop_common_1cb0:\n"
    "ldr r2, [sp, #0xc8]\n"
    "cmp r2, #0\n"
    "blt .Lshop_common_1d0c\n"
    "mov r3, sb\n"
    "cmp r3, #0\n"
    "blt .Lshop_common_1d0c\n"
#endif
    "mov r0, sl\n"
    "bl GetHardwareSpriteBuffer\n"
#if defined(REGION_JP)
    "adds r4, r0, #0\n"
    "ldr r1, [sp, #0xcc]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r5, r0, #0\n"
    "ldr r1, [sp, #0xec]\n"
#endif
    "adds r1, #4\n"
#if defined(REGION_JP)
    "ldr r2, [sp, #0xbc]\n"
    "adds r1, r2, r1\n"
    "movs r3, #0\n"
    "ldrsh r2, [r1, r3]\n"
    "mov r5, sl\n"
    "movs r6, #0xc\n"
    "ldrsh r0, [r5, r6]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, [sp, #0xe0]\n"
    "adds r1, r4, r1\n"
    "movs r7, #0\n"
    "ldrsh r2, [r1, r7]\n"
    "mov r3, sl\n"
    "movs r4, #0xc\n"
    "ldrsh r0, [r3, r4]\n"
#endif
    "subs r2, r2, r0\n"
    "ldr r1, [r1, #4]\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0xb0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r7, sb\n"
#endif
    "str r7, [sp]\n"
    "movs r0, #2\n"
    "str r0, [sp, #4]\n"
    "movs r0, #1\n"
    "str r0, [sp, #8]\n"
    "movs r0, #0\n"
    "str r0, [sp, #0xc]\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0xc0]\n"
    "ldr r3, [sp, #0xac]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r4, sp, #0x88\n"
    "adds r0, r4, #0\n"
    "ldr r3, [sp, #0xc8]\n"
#endif
    "bl InitializeMosaicSpriteOam\n"
#if defined(REGION_JP)
    "ldrb r2, [r4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldrb r2, [r5]\n"
#endif
    "cmp r2, #0x7f\n"
#if defined(REGION_JP)
    "bhi .Lshop_common_1b48\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bhi .Lshop_common_1d0c\n"
#endif
    "lsls r1, r2, #3\n"
    "adds r1, #4\n"
#if defined(REGION_JP)
    "adds r1, r4, r1\n"
    "ldr r0, [sp, #0x74]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r1, r5, r1\n"
    "ldr r0, [sp, #0x88]\n"
#endif
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "ldr r3, [sp, #0xc0]\n"
    "ldrh r0, [r3, #4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldrh r0, [r4, #4]\n"
#endif
    "strh r0, [r1, #4]\n"
    "adds r0, r2, #1\n"
#if defined(REGION_JP)
    "strb r0, [r4]\n"
    ".Lshop_common_1b48:\n"
    "ldr r4, [sp, #0xc8]\n"
    "str r4, [sp, #0xa8]\n"
    "mov r5, sl\n"
    "ldr r3, [r5, #0x20]\n"
    ".Lshop_common_1b50:\n"
    "ldr r6, [sp, #0xc4]\n"
    "mov r8, r6\n"
    "cmp r8, r3\n"
    "bhs .Lshop_common_1b5a\n"
    "b .Lshop_common_186c\n"
    ".Lshop_common_1b5a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strb r0, [r5]\n"
    ".Lshop_common_1d0c:\n"
    "ldr r4, [sp, #0xe4]\n"
    "ldr r0, [sp, #0xbc]\n"
    "cmp r4, r0\n"
    "bhs .Lshop_common_1d2a\n"
    "lsls r0, r4, #4\n"
    "adds r1, r0, #4\n"
    "ldr r2, [sp, #0xe0]\n"
    "adds r1, r2, r1\n"
    "movs r3, #0\n"
    "ldrsh r1, [r1, r3]\n"
    "str r0, [sp, #0xec]\n"
    "ldr r5, [sp, #0xc0]\n"
    "cmp r1, r5\n"
    "bgt .Lshop_common_1d2a\n"
    "b .Lshop_common_191a\n"
    ".Lshop_common_1d2a:\n"
    "ldr r0, [sp, #0x30]\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1d4c\n"
    "ldr r0, [sp, #0x2c]\n"
    "ldr r1, [r0, #4]\n"
    "ldr r0, [sp, #0xdc]\n"
    "bl EraseShopResourceSlotNodes\n"
    "ldr r0, [sp, #0x2c]\n"
    "str r0, [r0, #8]\n"
    "ldr r0, [sp, #0x2c]\n"
    "movs r1, #0\n"
    "str r1, [r0, #4]\n"
    "ldr r0, [sp, #0x2c]\n"
    "str r0, [r0, #0xc]\n"
    "ldr r7, [sp, #0xdc]\n"
    "str r1, [r7, #8]\n"
    ".Lshop_common_1d4c:\n"
    "ldr r0, [sp, #0x2c]\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1d56\n"
    "bl free\n"
    ".Lshop_common_1d56:\n"
    "ldr r0, [sp, #0x18]\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1d76\n"
    "ldr r0, [sp, #0x14]\n"
    "ldr r1, [r0, #4]\n"
    "add r0, sp, #0x10\n"
    "bl EraseShopResourceSlotNodes\n"
    "ldr r0, [sp, #0x14]\n"
    "str r0, [r0, #8]\n"
    "ldr r0, [sp, #0x14]\n"
    "movs r1, #0\n"
    "str r1, [r0, #4]\n"
    "ldr r0, [sp, #0x14]\n"
    "str r0, [r0, #0xc]\n"
    "str r1, [sp, #0x18]\n"
    ".Lshop_common_1d76:\n"
    "ldr r0, [sp, #0x14]\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1d80\n"
    "bl free\n"
    ".Lshop_common_1d80:\n"
    "add r1, sp, #0x10\n"
#endif
    "movs r2, #0\n"
    "movs r0, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0xb8]\n"
    "strh r0, [r7]\n"
    "strh r0, [r7, #2]\n"
    "strh r0, [r7, #4]\n"
    "strh r0, [r7, #6]\n"
    "strh r0, [r7, #8]\n"
    "str r0, [r7, #0xc]\n"
    "strb r2, [r7, #0x10]\n"
    "strb r2, [r7, #0x11]\n"
    "str r0, [r7, #0x14]\n"
    "strb r2, [r7, #0x18]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strh r0, [r1]\n"
    "strh r0, [r1, #2]\n"
    "strh r0, [r1, #4]\n"
    "strh r0, [r1, #6]\n"
    "strh r0, [r1, #8]\n"
    "str r0, [sp, #0x1c]\n"
    "strb r2, [r1, #0x10]\n"
    "strb r2, [r1, #0x11]\n"
    "str r0, [sp, #0x24]\n"
    "strb r2, [r1, #0x18]\n"
#endif
    "mov r0, sl\n"
    "movs r3, #0xc\n"
    "ldrsh r1, [r0, r3]\n"
    "ldr r0, [r0, #0x1c]\n"
    "movs r4, #0xe\n"
    "ldrsh r0, [r0, r4]\n"
    "subs r0, #0xa0\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "blt .Lshop_common_1b90\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "blt .Lshop_common_1db6\n"
#endif
    "movs r0, #0xba\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "strb r2, [r0]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1b9a\n"
    ".Lshop_common_1b90:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1dc0\n"
    ".Lshop_common_1db6:\n"
#endif
    "movs r1, #0xba\n"
    "lsls r1, r1, #3\n"
    "add r1, sl\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
#if defined(REGION_JP)
    ".Lshop_common_1b9a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1dc0:\n"
#endif
    "mov r5, sl\n"
#if defined(REGION_JP)
    "movs r6, #0xc\n"
    "ldrsh r1, [r5, r6]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r7, #0xc\n"
    "ldrsh r1, [r5, r7]\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1bae\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1dd4\n"
#endif
    "movs r0, #0xb3\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "strb r1, [r0]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1bb8\n"
    ".Lshop_common_1bae:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1dde\n"
    ".Lshop_common_1dd4:\n"
#endif
    "movs r1, #0xb3\n"
    "lsls r1, r1, #3\n"
    "add r1, sl\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
#if defined(REGION_JP)
    ".Lshop_common_1bb8:\n"
    "ldr r3, .Lshop_common_1c08\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1dde:\n"
    "ldr r3, .Lshop_common_1e30\n"
#endif
    "add r3, sl\n"
    "ldrb r1, [r3, #8]\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1c1c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1e44\n"
#endif
    "movs r0, #0xc1\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "movs r1, #1\n"
    "strb r1, [r0]\n"
    "movs r0, #0xc8\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "strb r1, [r0]\n"
    "ldr r0, [r3, #0x10]\n"
    "adds r0, #2\n"
    "lsls r0, r0, #3\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_1c0c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_1e34\n"
#endif
    "add r1, sl\n"
    "strh r0, [r1]\n"
    "movs r2, #0xc9\n"
    "lsls r2, r2, #3\n"
    "add r2, sl\n"
    "ldr r0, [r2]\n"
    "subs r0, #8\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_1c10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_1e38\n"
#endif
    "add r1, sl\n"
    "strh r0, [r1]\n"
    "ldr r0, [r3, #0x10]\n"
    "adds r0, #2\n"
    "lsls r0, r0, #3\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_1c14\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_1e3c\n"
#endif
    "add r1, sl\n"
    "strh r0, [r1]\n"
    "ldr r0, [r2]\n"
    "adds r0, #8\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_1c18\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, .Lshop_common_1e40\n"
#endif
    "add r1, sl\n"
    "strh r0, [r1]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1c2c\n"
    ".Lshop_common_1c08: .word 0x684\n"
    ".Lshop_common_1c0c: .word 0x5d4\n"
    ".Lshop_common_1c10: .word 0x5d6\n"
    ".Lshop_common_1c14: .word 0x60c\n"
    ".Lshop_common_1c18: .word 0x60e\n"
    ".Lshop_common_1c1c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1e54\n"
    ".align 2, 0\n"
    ".Lshop_common_1e30: .word 0x684\n"
    ".Lshop_common_1e34: .word 0x5d4\n"
    ".Lshop_common_1e38: .word 0x5d6\n"
    ".Lshop_common_1e3c: .word 0x60c\n"
    ".Lshop_common_1e40: .word 0x60e\n"
    ".Lshop_common_1e44:\n"
#endif
    "movs r0, #0xc1\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "strb r1, [r0]\n"
    "movs r0, #0xc8\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "strb r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1c2c:\n"
    "ldr r0, .Lshop_common_1d28\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1e54:\n"
    "ldr r0, .Lshop_common_1f54\n"
#endif
    "add r0, sl\n"
    "ldrb r0, [r0]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1c38\n"
    "b .Lshop_common_1dfe\n"
    ".Lshop_common_1c38:\n"
    "ldr r7, [sp, #0xa4]\n"
    "cmp r7, #0\n"
    "beq .Lshop_common_1c46\n"
    "ldr r0, .Lshop_common_1d2c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1e60\n"
    "b .Lshop_common_2028\n"
    ".Lshop_common_1e60:\n"
    "ldr r0, [sp, #0xb8]\n"
    "cmp r0, #0\n"
    "beq .Lshop_common_1e6e\n"
    "ldr r0, .Lshop_common_1f58\n"
#endif
    "add r0, sl\n"
    "bl UpdateIndexedResourceHandle\n"
#if defined(REGION_JP)
    ".Lshop_common_1c46:\n"
    "add r6, sp, #0x3c\n"
    "ldr r0, .Lshop_common_1d2c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1e6e:\n"
    "add r6, sp, #0x2c\n"
    "ldr r0, .Lshop_common_1f58\n"
#endif
    "add r0, sl\n"
    "ldr r1, [r0]\n"
    "ldr r3, [r1]\n"
    "ldrh r2, [r0, #0xc]\n"
    "movs r0, #0xca\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "lsls r2, r2, #2\n"
    "ldr r0, [r0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0]\n"
    "adds r0, r6, #0\n"
    "ldr r3, [r3, #0x10]\n"
    "bl _call_via_r3\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
#endif
    "movs r0, #0xcc\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldm r0!, {r2, r3, r4}\n"
    "stm r1!, {r2, r3, r4}\n"
    "ldm r0!, {r2, r5, r7}\n"
    "stm r1!, {r2, r5, r7}\n"
    "ldr r0, [r0]\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_1d30\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_1f5c\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "ldr r3, [sp, #0xb8]\n"
    "strh r0, [r3]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strh r0, [r1]\n"
#endif
    "movs r0, #0xc9\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
#if defined(REGION_JP)
    "ldr r0, [r0]\n"
    "strh r0, [r3, #2]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [r0]\n"
    "add r0, sp, #0x10\n"
    "strh r1, [r0, #2]\n"
#endif
    "movs r4, #1\n"
#if defined(REGION_JP)
    "movs r5, #1\n"
    "mov r8, r5\n"
    "mov r7, r8\n"
    "strh r7, [r3, #8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r3, #1\n"
    "mov sb, r3\n"
    "mov r5, sb\n"
    "strh r5, [r0, #8]\n"
#endif
    "movs r0, #0xdb\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
#endif
    "strh r0, [r1, #4]\n"
    "movs r5, #0xd9\n"
    "lsls r5, r5, #2\n"
    "add r5, sl\n"
    "ldr r1, [r5, #4]\n"
    "adds r0, r5, #0\n"
    "bl GetObjTileIndex\n"
#if defined(REGION_JP)
    "ldr r2, [sp, #0xb8]\n"
    "strh r0, [r2, #6]\n"
    "strb r4, [r2, #0x18]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "strh r0, [r1, #6]\n"
    "adds r0, r1, #0\n"
    "strb r4, [r0, #0x18]\n"
#endif
    "mov r0, sl\n"
    "bl GetHardwareSpriteBuffer\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0x3c]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0x2c]\n"
#endif
    "movs r2, #0\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1cce\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1efa\n"
#endif
    "ldrh r2, [r6, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_1cce:\n"
    "ldr r3, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1efa:\n"
    "add r3, sp, #0x10\n"
#endif
    "bl DrawIndexedResourceSprites\n"
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0x34]\n"
#endif
    "ldr r1, [r5, #4]\n"
    "adds r0, r5, #0\n"
    "bl GetObjTileIndex\n"
    "adds r2, r0, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x44\n"
    "ldr r0, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x34\n"
    "ldr r0, [sp, #0x34]\n"
#endif
    "movs r3, #0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1cf4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1f20\n"
#endif
    "ldrh r3, [r1, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_1cf4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1f20:\n"
#endif
    "adds r6, r4, #0\n"
    "lsls r2, r2, #5\n"
#if defined(REGION_JP)
    "ldr r4, .Lshop_common_1d34\n"
    "adds r2, r2, r4\n"
    "add r0, sp, #0x10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_1f60\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #0x58\n"
#endif
    "adds r1, r7, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "add r5, sp, #0x10\n"
    "mov sb, r5\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x58\n"
    "mov r8, r1\n"
#endif
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #0xc]\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1d38\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1f64\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1d20\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1f4c\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x10\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
#endif
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1d20:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1f4c:\n"
#endif
    "ldr r0, [r6, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r6, #4]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1dfe\n"
    ".Lshop_common_1d28: .word 0x67c\n"
    ".Lshop_common_1d2c: .word 0x64c\n"
    ".Lshop_common_1d30: .word 0x644\n"
    ".Lshop_common_1d34: .word 0x6010000\n"
    ".Lshop_common_1d38:\n"
    "str r1, [sp, #0xd0]\n"
    "mov r4, r8\n"
    "str r4, [sp, #0x80]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2028\n"
    ".align 2, 0\n"
    ".Lshop_common_1f54: .word 0x67c\n"
    ".Lshop_common_1f58: .word 0x64c\n"
    ".Lshop_common_1f5c: .word 0x644\n"
    ".Lshop_common_1f60: .word OBJ_VRAM0\n"
    ".Lshop_common_1f64:\n"
    "str r1, [sp, #0xf0]\n"
    "add r1, sp, #0x94\n"
    "mov r5, sb\n"
    "str r5, [r1]\n"
#endif
    "ldr r0, [r6]\n"
#if defined(REGION_JP)
    "adds r5, r1, #0\n"
    "subs r0, r5, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0xf0]\n"
    "subs r0, r7, r0\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "str r4, [sp, #0x7c]\n"
    "add r1, sp, #0x80\n"
    "add r0, sp, #0x7c\n"
    "cmp r4, #1\n"
    "bhs .Lshop_common_1d52\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #0x90\n"
    "str r4, [r0]\n"
    "ldr r2, [r1]\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_1f80\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_1d52:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1f80:\n"
#endif
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1d70\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1f9e\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1d74\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1fa2\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_1d74\n"
    ".Lshop_common_1d70:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1fa2\n"
    ".Lshop_common_1f9e:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_1d74:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_1fa2:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #0xf4]\n"
#endif
    "ldr r2, [r6]\n"
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0xd0]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_1d9c\n"
    ".Lshop_common_1d82:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_1fc0\n"
    ".Lshop_common_1fac:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1d92\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1fbc\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1d92:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1fbc:\n"
#endif
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0xd0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1fc0:\n"
    "ldr r0, [sp, #0xf0]\n"
#endif
    "cmp r2, r0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1d82\n"
    ".Lshop_common_1d9c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1fac\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0x80]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_1db8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0x94]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_1fe2\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1db4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1fde\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
#endif
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1db4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1fde:\n"
#endif
    "adds r5, #0x10\n"
#if defined(REGION_JP)
    "b .Lshop_common_1dda\n"
    ".Lshop_common_1db8:\n"
    "adds r3, r0, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2004\n"
    ".Lshop_common_1fe2:\n"
    "adds r3, r1, #0\n"
#endif
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1dd8\n"
    ".Lshop_common_1dc0:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2002\n"
    ".Lshop_common_1fea:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1dd0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_1ffa\n"
#endif
    "adds r0, r2, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
#endif
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1dd0:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_1ffa:\n"
#endif
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1dc0\n"
    ".Lshop_common_1dd8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_1fea\n"
    ".Lshop_common_2002:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_1dda:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2004:\n"
#endif
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1dea\n"
    ".Lshop_common_1de4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2014\n"
    ".Lshop_common_200e:\n"
#endif
    "adds r1, #0x10\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1de4\n"
    ".Lshop_common_1dea:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_200e\n"
    ".Lshop_common_2014:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1df2\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_201c\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_1df2:\n"
    "ldr r0, [sp, #0xd4]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_201c:\n"
    "ldr r0, [sp, #0xf4]\n"
    "add r0, sb\n"
    "ldr r7, [sp, #0xf4]\n"
#endif
    "str r7, [r6]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #0xc]\n"
#if defined(REGION_JP)
    ".Lshop_common_1dfe:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2028:\n"
#endif
    "movs r0, #0xb3\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldrb r0, [r0]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1e0c\n"
    "b .Lshop_common_1fd6\n"
    ".Lshop_common_1e0c:\n"
    "ldr r0, [sp, #0xa4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2036\n"
    "b .Lshop_common_2200\n"
    ".Lshop_common_2036:\n"
    "ldr r0, [sp, #0xb8]\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1e1c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2046\n"
#endif
    "movs r0, #0xad\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "bl UpdateIndexedResourceHandle\n"
#if defined(REGION_JP)
    ".Lshop_common_1e1c:\n"
    "add r6, sp, #0x3c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2046:\n"
    "add r6, sp, #0x2c\n"
#endif
    "movs r0, #0xad\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldr r1, [r0]\n"
    "ldr r3, [r1]\n"
    "ldrh r2, [r0, #0xc]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_1efc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_2128\n"
#endif
    "add r0, sl\n"
    "lsls r2, r2, #2\n"
    "ldr r0, [r0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0]\n"
    "adds r0, r6, #0\n"
    "ldr r3, [r3, #0x10]\n"
    "bl _call_via_r3\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xb8]\n"
    "ldr r0, .Lshop_common_1f00\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_212c\n"
#endif
    "add r0, sl\n"
    "ldm r0!, {r2, r3, r4}\n"
    "stm r1!, {r2, r3, r4}\n"
    "ldm r0!, {r2, r5, r7}\n"
    "stm r1!, {r2, r5, r7}\n"
    "ldr r0, [r0]\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_1f04\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_2130\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "ldr r3, [sp, #0xb8]\n"
    "strh r0, [r3]\n"
    "ldr r0, .Lshop_common_1f08\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strh r0, [r1]\n"
    "ldr r0, .Lshop_common_2134\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "strh r0, [r3, #2]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strh r0, [r1, #2]\n"
    "adds r0, r1, #0\n"
#endif
    "movs r4, #1\n"
#if defined(REGION_JP)
    "movs r5, #1\n"
    "mov r8, r5\n"
    "mov r7, r8\n"
    "strh r7, [r3, #8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r3, #1\n"
    "mov sb, r3\n"
    "mov r5, sb\n"
    "strh r5, [r0, #8]\n"
#endif
    "movs r0, #0xe1\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
#endif
    "strh r0, [r1, #4]\n"
    "movs r5, #0xdd\n"
    "lsls r5, r5, #2\n"
    "add r5, sl\n"
    "ldr r1, [r5, #4]\n"
    "adds r0, r5, #0\n"
    "bl GetObjTileIndex\n"
#if defined(REGION_JP)
    "ldr r2, [sp, #0xb8]\n"
    "strh r0, [r2, #6]\n"
    "strb r4, [r2, #0x18]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "strh r0, [r1, #6]\n"
    "adds r0, r1, #0\n"
    "strb r4, [r0, #0x18]\n"
#endif
    "mov r0, sl\n"
    "bl GetHardwareSpriteBuffer\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0x3c]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0x2c]\n"
#endif
    "movs r2, #0\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1ea0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_20ce\n"
#endif
    "ldrh r2, [r6, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_1ea0:\n"
    "ldr r3, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_20ce:\n"
    "add r3, sp, #0x10\n"
#endif
    "bl DrawIndexedResourceSprites\n"
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0x34]\n"
#endif
    "ldr r1, [r5, #4]\n"
    "adds r0, r5, #0\n"
    "bl GetObjTileIndex\n"
    "adds r2, r0, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x44\n"
    "ldr r0, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x34\n"
    "ldr r0, [sp, #0x34]\n"
#endif
    "movs r3, #0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1ec6\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_20f4\n"
#endif
    "ldrh r3, [r1, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_1ec6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_20f4:\n"
#endif
    "adds r6, r4, #0\n"
    "lsls r2, r2, #5\n"
#if defined(REGION_JP)
    "ldr r4, .Lshop_common_1f0c\n"
    "adds r2, r2, r4\n"
    "add r0, sp, #0x10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_2138\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #0x4c\n"
#endif
    "adds r1, r7, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "add r5, sp, #0x10\n"
    "mov sb, r5\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x4c\n"
    "mov r8, r1\n"
#endif
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #0xc]\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1f10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_213c\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1ef2\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2120\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x10\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
#endif
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1ef2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2120:\n"
#endif
    "ldr r0, [r6, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r6, #4]\n"
#if defined(REGION_JP)
    "b .Lshop_common_1fd6\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2200\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_1efc: .word 0x56c\n"
    ".Lshop_common_1f00: .word 0x57c\n"
    ".Lshop_common_1f04: .word 0x564\n"
    ".Lshop_common_1f08: .word 0x566\n"
    ".Lshop_common_1f0c: .word 0x6010000\n"
    ".Lshop_common_1f10:\n"
    "str r1, [sp, #0xd0]\n"
    "mov r4, r8\n"
    "str r4, [sp, #0x88]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2128: .word 0x56c\n"
    ".Lshop_common_212c: .word 0x57c\n"
    ".Lshop_common_2130: .word 0x564\n"
    ".Lshop_common_2134: .word 0x566\n"
    ".Lshop_common_2138: .word OBJ_VRAM0\n"
    ".Lshop_common_213c:\n"
    "str r1, [sp, #0xf0]\n"
    "add r1, sp, #0x9c\n"
    "mov r5, sb\n"
    "str r5, [r1]\n"
#endif
    "ldr r0, [r6]\n"
#if defined(REGION_JP)
    "adds r5, r1, #0\n"
    "subs r0, r5, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0xf0]\n"
    "subs r0, r7, r0\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "str r4, [sp, #0x84]\n"
    "add r1, sp, #0x88\n"
    "add r0, sp, #0x84\n"
    "cmp r4, #1\n"
    "bhs .Lshop_common_1f2a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #0x98\n"
    "str r4, [r0]\n"
    "ldr r2, [r1]\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_2158\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_1f2a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2158:\n"
#endif
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1f48\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2176\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1f4c\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_217a\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_1f4c\n"
    ".Lshop_common_1f48:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_217a\n"
    ".Lshop_common_2176:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_1f4c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_217a:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #0xf4]\n"
#endif
    "ldr r2, [r6]\n"
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0xd0]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_1f74\n"
    ".Lshop_common_1f5a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2198\n"
    ".Lshop_common_2184:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1f6a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2194\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1f6a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2194:\n"
#endif
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0xd0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2198:\n"
    "ldr r0, [sp, #0xf0]\n"
#endif
    "cmp r2, r0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1f5a\n"
    ".Lshop_common_1f74:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2184\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0x88]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_1f90\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0x9c]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_21ba\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1f8c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_21b6\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
#endif
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1f8c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_21b6:\n"
#endif
    "adds r5, #0x10\n"
#if defined(REGION_JP)
    "b .Lshop_common_1fb2\n"
    ".Lshop_common_1f90:\n"
    "adds r3, r0, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_21dc\n"
    ".Lshop_common_21ba:\n"
    "adds r3, r1, #0\n"
#endif
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1fb0\n"
    ".Lshop_common_1f98:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_21da\n"
    ".Lshop_common_21c2:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1fa8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_21d2\n"
#endif
    "adds r0, r2, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
#endif
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_1fa8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_21d2:\n"
#endif
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1f98\n"
    ".Lshop_common_1fb0:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_21c2\n"
    ".Lshop_common_21da:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_1fb2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_21dc:\n"
#endif
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1fc2\n"
    ".Lshop_common_1fbc:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_21ec\n"
    ".Lshop_common_21e6:\n"
#endif
    "adds r1, #0x10\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1fbc\n"
    ".Lshop_common_1fc2:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_21e6\n"
    ".Lshop_common_21ec:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1fca\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_21f4\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_1fca:\n"
    "ldr r0, [sp, #0xd4]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_21f4:\n"
    "ldr r0, [sp, #0xf4]\n"
    "add r0, sb\n"
    "ldr r7, [sp, #0xf4]\n"
#endif
    "str r7, [r6]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #0xc]\n"
#if defined(REGION_JP)
    ".Lshop_common_1fd6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2200:\n"
#endif
    "movs r0, #0xba\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldrb r0, [r0]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_1fe4\n"
    "b .Lshop_common_21b0\n"
    ".Lshop_common_1fe4:\n"
    "ldr r0, [sp, #0xa4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_220e\n"
    "b .Lshop_common_23d8\n"
    ".Lshop_common_220e:\n"
    "ldr r0, [sp, #0xb8]\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_1ff4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_221e\n"
#endif
    "movs r0, #0xb4\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "bl UpdateIndexedResourceHandle\n"
#if defined(REGION_JP)
    ".Lshop_common_1ff4:\n"
    "add r6, sp, #0x3c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_221e:\n"
    "add r6, sp, #0x2c\n"
#endif
    "movs r0, #0xb4\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldr r1, [r0]\n"
    "ldr r3, [r1]\n"
    "ldrh r2, [r0, #0xc]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_20d4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_2300\n"
#endif
    "add r0, sl\n"
    "lsls r2, r2, #2\n"
    "ldr r0, [r0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0]\n"
    "adds r0, r6, #0\n"
    "ldr r3, [r3, #0x10]\n"
    "bl _call_via_r3\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xb8]\n"
    "ldr r0, .Lshop_common_20d8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_2304\n"
#endif
    "add r0, sl\n"
    "ldm r0!, {r2, r3, r4}\n"
    "stm r1!, {r2, r3, r4}\n"
    "ldm r0!, {r2, r5, r7}\n"
    "stm r1!, {r2, r5, r7}\n"
    "ldr r0, [r0]\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_20dc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_2308\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "ldr r3, [sp, #0xb8]\n"
    "strh r0, [r3]\n"
    "ldr r0, .Lshop_common_20e0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strh r0, [r1]\n"
    "ldr r0, .Lshop_common_230c\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "strh r0, [r3, #2]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strh r0, [r1, #2]\n"
    "adds r0, r1, #0\n"
#endif
    "movs r4, #1\n"
#if defined(REGION_JP)
    "movs r5, #1\n"
    "mov r8, r5\n"
    "mov r7, r8\n"
    "strh r7, [r3, #8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r3, #1\n"
    "mov sb, r3\n"
    "mov r5, sb\n"
    "strh r5, [r0, #8]\n"
#endif
    "movs r0, #0xe1\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
#endif
    "strh r0, [r1, #4]\n"
    "movs r5, #0xdf\n"
    "lsls r5, r5, #2\n"
    "add r5, sl\n"
    "ldr r1, [r5, #4]\n"
    "adds r0, r5, #0\n"
    "bl GetObjTileIndex\n"
#if defined(REGION_JP)
    "ldr r2, [sp, #0xb8]\n"
    "strh r0, [r2, #6]\n"
    "strb r4, [r2, #0x18]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "strh r0, [r1, #6]\n"
    "adds r0, r1, #0\n"
    "strb r4, [r0, #0x18]\n"
#endif
    "mov r0, sl\n"
    "bl GetHardwareSpriteBuffer\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0x3c]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0x2c]\n"
#endif
    "movs r2, #0\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2078\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_22a6\n"
#endif
    "ldrh r2, [r6, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_2078:\n"
    "ldr r3, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_22a6:\n"
    "add r3, sp, #0x10\n"
#endif
    "bl DrawIndexedResourceSprites\n"
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
    "adds r4, r0, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0x34]\n"
#endif
    "ldr r1, [r5, #4]\n"
    "adds r0, r5, #0\n"
    "bl GetObjTileIndex\n"
    "adds r2, r0, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x44\n"
    "ldr r0, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x34\n"
    "ldr r0, [sp, #0x34]\n"
#endif
    "movs r3, #0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_209e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_22cc\n"
#endif
    "ldrh r3, [r1, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_209e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_22cc:\n"
#endif
    "adds r6, r4, #0\n"
    "lsls r2, r2, #5\n"
#if defined(REGION_JP)
    "ldr r4, .Lshop_common_20e4\n"
    "adds r2, r2, r4\n"
    "add r0, sp, #0x10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_2310\n"
    "adds r2, r2, r0\n"
    "add r0, sp, #0x4c\n"
#endif
    "adds r1, r7, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "add r5, sp, #0x10\n"
    "mov sb, r5\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x4c\n"
    "mov r8, r1\n"
#endif
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #0xc]\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_20e8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2314\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_20ca\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_22f8\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x10\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
#endif
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_20ca:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_22f8:\n"
#endif
    "ldr r0, [r6, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r6, #4]\n"
#if defined(REGION_JP)
    "b .Lshop_common_21b0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_23d8\n"
#endif
    ".align 2, 0\n"
#if defined(REGION_JP)
    ".Lshop_common_20d4: .word 0x5a4\n"
    ".Lshop_common_20d8: .word 0x5b4\n"
    ".Lshop_common_20dc: .word 0x59c\n"
    ".Lshop_common_20e0: .word 0x59e\n"
    ".Lshop_common_20e4: .word 0x6010000\n"
    ".Lshop_common_20e8:\n"
    "str r1, [sp, #0xd0]\n"
    "add r0, sp, #0x90\n"
    "mov r4, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2300: .word 0x5a4\n"
    ".Lshop_common_2304: .word 0x5b4\n"
    ".Lshop_common_2308: .word 0x59c\n"
    ".Lshop_common_230c: .word 0x59e\n"
    ".Lshop_common_2310: .word OBJ_VRAM0\n"
    ".Lshop_common_2314:\n"
    "str r1, [sp, #0xf0]\n"
    "add r1, sp, #0xa4\n"
    "mov r5, sb\n"
    "str r5, [r1]\n"
    "ldr r0, [r6]\n"
    "ldr r7, [sp, #0xf0]\n"
    "subs r0, r7, r0\n"
    "asrs r4, r0, #4\n"
    "add r0, sp, #0xa0\n"
#endif
    "str r4, [r0]\n"
#if defined(REGION_JP)
    "ldr r1, [r6]\n"
    "ldr r5, [sp, #0xd0]\n"
    "subs r1, r5, r1\n"
    "asrs r4, r1, #4\n"
    "str r4, [sp, #0x8c]\n"
    "ldr r1, [r0]\n"
    "add r2, sp, #0x8c\n"
    "cmp r4, r1\n"
    "bhs .Lshop_common_2104\n"
    "adds r2, r0, #0\n"
    ".Lshop_common_2104:\n"
    "ldr r0, [r2]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r2, [r1]\n"
    "cmp r4, r2\n"
    "bhs .Lshop_common_2330\n"
    "adds r0, r1, #0\n"
    ".Lshop_common_2330:\n"
    "ldr r0, [r0]\n"
#endif
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2122\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_234e\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_2126\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2352\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_2126\n"
    ".Lshop_common_2122:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2352\n"
    ".Lshop_common_234e:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_2126:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_2352:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #0xf4]\n"
#endif
    "ldr r2, [r6]\n"
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0xd0]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_214e\n"
    ".Lshop_common_2134:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2370\n"
    ".Lshop_common_235c:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2144\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_236c\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_2144:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_236c:\n"
#endif
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0xd0]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2370:\n"
    "ldr r0, [sp, #0xf0]\n"
#endif
    "cmp r2, r0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_2134\n"
    ".Lshop_common_214e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_235c\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0x90]\n"
    "cmp r0, #1\n"
    "bne .Lshop_common_216a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0xa4]\n"
    "cmp r1, #1\n"
    "bne .Lshop_common_2392\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2166\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_238e\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
#endif
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_2166:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_238e:\n"
#endif
    "adds r5, #0x10\n"
#if defined(REGION_JP)
    "b .Lshop_common_218c\n"
    ".Lshop_common_216a:\n"
    "adds r3, r0, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_23b4\n"
    ".Lshop_common_2392:\n"
    "adds r3, r1, #0\n"
#endif
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_218a\n"
    ".Lshop_common_2172:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_23b2\n"
    ".Lshop_common_239a:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2182\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_23aa\n"
#endif
    "adds r0, r2, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
#endif
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_2182:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_23aa:\n"
#endif
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_2172\n"
    ".Lshop_common_218a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_239a\n"
    ".Lshop_common_23b2:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_218c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_23b4:\n"
#endif
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_219c\n"
    ".Lshop_common_2196:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_23c4\n"
    ".Lshop_common_23be:\n"
#endif
    "adds r1, #0x10\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_2196\n"
    ".Lshop_common_219c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_23be\n"
    ".Lshop_common_23c4:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_21a4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_23cc\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_21a4:\n"
    "ldr r0, [sp, #0xd4]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_23cc:\n"
    "ldr r0, [sp, #0xf4]\n"
    "add r0, sb\n"
    "ldr r7, [sp, #0xf4]\n"
#endif
    "str r7, [r6]\n"
    "str r5, [r6, #4]\n"
    "str r0, [r6, #0xc]\n"
#if defined(REGION_JP)
    ".Lshop_common_21b0:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_23d8:\n"
#endif
    "movs r0, #0xc8\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldrb r0, [r0]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_21be\n"
    "b .Lshop_common_2384\n"
    ".Lshop_common_21be:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_23e6\n"
    "b .Lshop_common_25b0\n"
    ".Lshop_common_23e6:\n"
#endif
    "movs r4, #0xc2\n"
    "lsls r4, r4, #3\n"
    "add r4, sl\n"
    "adds r0, r4, #0\n"
    "bl UpdateIndexedResourceHandle\n"
#if defined(REGION_JP)
    "add r5, sp, #0x3c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r5, sp, #0x2c\n"
#endif
    "ldr r1, [r4]\n"
    "ldr r3, [r1]\n"
    "ldrh r2, [r4, #0xc]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_22a8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_24d4\n"
#endif
    "add r0, sl\n"
    "lsls r2, r2, #2\n"
    "ldr r0, [r0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0]\n"
    "adds r0, r5, #0\n"
    "ldr r3, [r3, #0x10]\n"
    "bl _call_via_r3\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0xb8]\n"
    "ldr r0, .Lshop_common_22ac\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_24d8\n"
#endif
    "add r0, sl\n"
    "ldm r0!, {r2, r3, r4}\n"
    "stm r1!, {r2, r3, r4}\n"
#if defined(REGION_JP)
    "ldm r0!, {r2, r6, r7}\n"
    "stm r1!, {r2, r6, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldm r0!, {r2, r3, r7}\n"
    "stm r1!, {r2, r3, r7}\n"
#endif
    "ldr r0, [r0]\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_22b0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_24dc\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "movs r1, #0\n"
    "ldr r3, [sp, #0xb8]\n"
    "strh r0, [r3]\n"
    "ldr r0, .Lshop_common_22b4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r2, #0\n"
    "strh r0, [r1]\n"
    "ldr r0, .Lshop_common_24e0\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "strh r0, [r3, #2]\n"
    "strh r1, [r3, #8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strh r0, [r1, #2]\n"
    "adds r0, r1, #0\n"
    "strh r2, [r0, #8]\n"
#endif
    "movs r0, #0xe7\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
#if defined(REGION_JP)
    "ldr r4, [sp, #0xb8]\n"
    "strh r0, [r4, #4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "strh r0, [r1, #4]\n"
#endif
    "movs r4, #0xe5\n"
    "lsls r4, r4, #2\n"
    "add r4, sl\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl GetObjTileIndex\n"
#if defined(REGION_JP)
    "ldr r6, [sp, #0xb8]\n"
    "strh r0, [r6, #6]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "strh r0, [r1, #6]\n"
    "adds r0, r1, #0\n"
#endif
    "movs r7, #1\n"
#if defined(REGION_JP)
    "mov r8, r7\n"
    "mov r0, r8\n"
    "strb r0, [r6, #0x18]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r7\n"
    "mov r1, sb\n"
    "strb r1, [r0, #0x18]\n"
#endif
    "mov r0, sl\n"
    "bl GetHardwareSpriteBuffer\n"
    "adds r3, r0, #0\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0x3c]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [sp, #0x2c]\n"
#endif
    "adds r1, r0, #0\n"
    "movs r2, #0\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_224c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2478\n"
#endif
    "ldrh r2, [r5, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_224c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2478:\n"
#endif
    "adds r0, r3, #0\n"
#if defined(REGION_JP)
    "ldr r3, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r3, sp, #0x10\n"
#endif
    "bl DrawIndexedResourceSprites\n"
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "ldr r7, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0x34]\n"
#endif
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
    "bl GetObjTileIndex\n"
    "adds r2, r0, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x44\n"
    "ldr r0, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x34\n"
    "ldr r0, [sp, #0x34]\n"
#endif
    "movs r3, #0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2274\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_24a0\n"
#endif
    "ldrh r3, [r1, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_2274:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_24a0:\n"
#endif
    "adds r6, r5, #0\n"
    "lsls r2, r2, #5\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_22b8\n"
    "adds r2, r2, r1\n"
    "add r0, sp, #0x10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, .Lshop_common_24e4\n"
    "adds r2, r2, r4\n"
    "add r0, sp, #0x4c\n"
#endif
    "adds r1, r7, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "add r2, sp, #0x10\n"
    "mov sb, r2\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r5, sp, #0x4c\n"
    "mov r8, r5\n"
#endif
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #0xc]\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_22bc\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_24e8\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_22a0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_24cc\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x10\n"
    "ldm r1!, {r3, r4, r5}\n"
    "stm r0!, {r3, r4, r5}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
#endif
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_22a0:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_24cc:\n"
#endif
    "ldr r0, [r6, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r6, #4]\n"
#if defined(REGION_JP)
    "b .Lshop_common_2384\n"
    ".Lshop_common_22a8: .word 0x614\n"
    ".Lshop_common_22ac: .word 0x624\n"
    ".Lshop_common_22b0: .word 0x60c\n"
    ".Lshop_common_22b4: .word 0x60e\n"
    ".Lshop_common_22b8: .word 0x6010000\n"
    ".Lshop_common_22bc:\n"
    "str r1, [sp, #0xd0]\n"
    "add r1, sp, #0x98\n"
    "mov r7, r8\n"
    "str r7, [r1]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_25b0\n"
    ".align 2, 0\n"
    ".Lshop_common_24d4: .word 0x614\n"
    ".Lshop_common_24d8: .word 0x624\n"
    ".Lshop_common_24dc: .word 0x60c\n"
    ".Lshop_common_24e0: .word 0x60e\n"
    ".Lshop_common_24e4: .word OBJ_VRAM0\n"
    ".Lshop_common_24e8:\n"
    "str r1, [sp, #0xf0]\n"
    "add r1, sp, #0xac\n"
    "mov r4, sb\n"
    "str r4, [r1]\n"
#endif
    "ldr r0, [r6]\n"
#if defined(REGION_JP)
    "ldr r2, [sp, #0xd0]\n"
    "subs r0, r2, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, [sp, #0xf0]\n"
    "subs r0, r5, r0\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "add r0, sp, #0x94\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #0xa8\n"
#endif
    "str r4, [r0]\n"
    "ldr r2, [r1]\n"
    "cmp r4, r2\n"
#if defined(REGION_JP)
    "bhs .Lshop_common_22d8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bhs .Lshop_common_2504\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_22d8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2504:\n"
#endif
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_22f6\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2522\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_22fa\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2526\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_22fa\n"
    ".Lshop_common_22f6:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2526\n"
    ".Lshop_common_2522:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_22fa:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_2526:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #0xf4]\n"
#endif
    "ldr r2, [r6]\n"
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "ldr r4, [sp, #0xd0]\n"
    "cmp r2, r4\n"
    "beq .Lshop_common_2322\n"
    ".Lshop_common_2308:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0xf0]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_254e\n"
    ".Lshop_common_2534:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2318\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2544\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_2318:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2544:\n"
#endif
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
#if defined(REGION_JP)
    "ldr r5, [sp, #0xd0]\n"
    "cmp r2, r5\n"
    "bne .Lshop_common_2308\n"
    ".Lshop_common_2322:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [sp, #0xf0]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_2534\n"
    ".Lshop_common_254e:\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "ldr r1, [sp, #0x98]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r1, [sp, #0xac]\n"
#endif
    "cmp r1, #1\n"
#if defined(REGION_JP)
    "bne .Lshop_common_233e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_256a\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_233a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2566\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
#endif
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_233a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2566:\n"
#endif
    "adds r5, #0x10\n"
#if defined(REGION_JP)
    "b .Lshop_common_2360\n"
    ".Lshop_common_233e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_258c\n"
    ".Lshop_common_256a:\n"
#endif
    "adds r3, r1, #0\n"
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_235e\n"
    ".Lshop_common_2346:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_258a\n"
    ".Lshop_common_2572:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2356\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2582\n"
#endif
    "adds r0, r2, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
#endif
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_2356:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2582:\n"
#endif
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_2346\n"
    ".Lshop_common_235e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2572\n"
    ".Lshop_common_258a:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_2360:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_258c:\n"
#endif
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2370\n"
    ".Lshop_common_236a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_259c\n"
    ".Lshop_common_2596:\n"
#endif
    "adds r1, #0x10\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_236a\n"
    ".Lshop_common_2370:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2596\n"
    ".Lshop_common_259c:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2378\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_25a4\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_2378:\n"
    "ldr r0, [sp, #0xd4]\n"
    "add r0, r8\n"
    "ldr r1, [sp, #0xd4]\n"
    "str r1, [r6]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_25a4:\n"
    "ldr r0, [sp, #0xf4]\n"
    "add r0, sb\n"
    "ldr r7, [sp, #0xf4]\n"
    "str r7, [r6]\n"
#endif
    "str r5, [r6, #4]\n"
    "str r0, [r6, #0xc]\n"
#if defined(REGION_JP)
    ".Lshop_common_2384:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_25b0:\n"
#endif
    "movs r0, #0xc1\n"
    "lsls r0, r0, #3\n"
    "add r0, sl\n"
    "ldrb r0, [r0]\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_2392\n"
    "b .Lshop_common_2558\n"
    ".Lshop_common_2392:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_25be\n"
    "b .Lshop_common_278c\n"
    ".Lshop_common_25be:\n"
#endif
    "movs r4, #0xbb\n"
    "lsls r4, r4, #3\n"
    "add r4, sl\n"
    "adds r0, r4, #0\n"
    "bl UpdateIndexedResourceHandle\n"
#if defined(REGION_JP)
    "add r6, sp, #0x3c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r5, sp, #0x2c\n"
#endif
    "ldr r1, [r4]\n"
    "ldr r3, [r1]\n"
    "ldrh r2, [r4, #0xc]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_2478\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, .Lshop_common_26ac\n"
#endif
    "add r0, sl\n"
    "lsls r2, r2, #2\n"
    "ldr r0, [r0]\n"
    "adds r0, r0, r2\n"
    "ldrh r2, [r0]\n"
#if defined(REGION_JP)
    "adds r0, r6, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r0, r5, #0\n"
#endif
    "ldr r3, [r3, #0x10]\n"
    "bl _call_via_r3\n"
#if defined(REGION_JP)
    "ldr r4, [sp, #0xb8]\n"
    "adds r1, r4, #0\n"
    "ldr r0, .Lshop_common_247c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_26b0\n"
#endif
    "add r0, sl\n"
#if defined(REGION_JP)
    "ldm r0!, {r2, r3, r5}\n"
    "stm r1!, {r2, r3, r5}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldm r0!, {r2, r3, r4}\n"
    "stm r1!, {r2, r3, r4}\n"
#endif
    "ldm r0!, {r2, r3, r7}\n"
    "stm r1!, {r2, r3, r7}\n"
    "ldr r0, [r0]\n"
    "str r0, [r1]\n"
#if defined(REGION_JP)
    "ldr r0, .Lshop_common_2480\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "ldr r0, .Lshop_common_26b4\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "movs r1, #0\n"
    "strh r0, [r4]\n"
    "ldr r0, .Lshop_common_2484\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "movs r2, #0\n"
    "strh r0, [r1]\n"
    "ldr r0, .Lshop_common_26b8\n"
#endif
    "add r0, sl\n"
    "ldrh r0, [r0]\n"
#if defined(REGION_JP)
    "strh r0, [r4, #2]\n"
    "strh r1, [r4, #8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "strh r0, [r1, #2]\n"
    "adds r0, r1, #0\n"
    "strh r2, [r0, #8]\n"
#endif
    "movs r0, #0xe7\n"
    "lsls r0, r0, #2\n"
    "add r0, sl\n"
    "ldr r1, [r0, #4]\n"
    "bl GetObjPaletteBank\n"
#if defined(REGION_JP)
    "strh r0, [r4, #4]\n"
    "movs r5, #0xe3\n"
    "lsls r5, r5, #2\n"
    "add r5, sl\n"
    "ldr r1, [r5, #4]\n"
    "adds r0, r5, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "strh r0, [r1, #4]\n"
    "movs r4, #0xe3\n"
    "lsls r4, r4, #2\n"
    "add r4, sl\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
#endif
    "bl GetObjTileIndex\n"
#if defined(REGION_JP)
    "strh r0, [r4, #6]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x10\n"
    "strh r0, [r1, #6]\n"
    "adds r0, r1, #0\n"
#endif
    "movs r7, #1\n"
#if defined(REGION_JP)
    "mov r8, r7\n"
    "mov r0, r8\n"
    "strb r0, [r4, #0x18]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r7\n"
    "mov r1, sb\n"
    "strb r1, [r0, #0x18]\n"
#endif
    "mov r0, sl\n"
    "bl GetHardwareSpriteBuffer\n"
    "adds r3, r0, #0\n"
#if defined(REGION_JP)
    "ldr r0, [sp, #0x3c]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [sp, #0x2c]\n"
#endif
    "adds r1, r0, #0\n"
    "movs r2, #0\n"
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_241c\n"
    "ldrh r2, [r6, #4]\n"
    ".Lshop_common_241c:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2650\n"
    "ldrh r2, [r5, #4]\n"
    ".Lshop_common_2650:\n"
#endif
    "adds r0, r3, #0\n"
#if defined(REGION_JP)
    "ldr r3, [sp, #0xb8]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r3, sp, #0x10\n"
#endif
    "bl DrawIndexedResourceSprites\n"
    "mov r0, sl\n"
    "bl GetHardwareDmaQueue\n"
#if defined(REGION_JP)
    "adds r4, r0, #0\n"
    "ldr r7, [sp, #0x44]\n"
    "ldr r1, [r5, #4]\n"
    "adds r0, r5, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "adds r5, r0, #0\n"
    "ldr r7, [sp, #0x34]\n"
    "ldr r1, [r4, #4]\n"
    "adds r0, r4, #0\n"
#endif
    "bl GetObjTileIndex\n"
    "adds r2, r0, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x44\n"
    "ldr r0, [sp, #0x44]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r1, sp, #0x34\n"
    "ldr r0, [sp, #0x34]\n"
#endif
    "movs r3, #0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2444\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2678\n"
#endif
    "ldrh r3, [r1, #4]\n"
#if defined(REGION_JP)
    ".Lshop_common_2444:\n"
    "adds r6, r4, #0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2678:\n"
    "adds r6, r5, #0\n"
#endif
    "lsls r2, r2, #5\n"
#if defined(REGION_JP)
    "ldr r1, .Lshop_common_2488\n"
    "adds r2, r2, r1\n"
    "add r0, sp, #0x10\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r4, .Lshop_common_26bc\n"
    "adds r2, r2, r4\n"
    "add r0, sp, #0x4c\n"
#endif
    "adds r1, r7, #0\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
#if defined(REGION_JP)
    "add r2, sp, #0x10\n"
    "mov sb, r2\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r5, sp, #0x4c\n"
    "mov r8, r5\n"
#endif
    "ldr r1, [r6, #4]\n"
    "ldr r0, [r6, #0xc]\n"
    "cmp r1, r0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_248c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_26c0\n"
#endif
    "cmp r1, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2470\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_26a4\n"
#endif
    "adds r0, r1, #0\n"
#if defined(REGION_JP)
    "add r1, sp, #0x10\n"
    "ldm r1!, {r3, r4, r5}\n"
    "stm r0!, {r3, r4, r5}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
#endif
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_2470:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_26a4:\n"
#endif
    "ldr r0, [r6, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r6, #4]\n"
#if defined(REGION_JP)
    "b .Lshop_common_2558\n"
    ".Lshop_common_2478: .word 0x5dc\n"
    ".Lshop_common_247c: .word 0x5ec\n"
    ".Lshop_common_2480: .word 0x5d4\n"
    ".Lshop_common_2484: .word 0x5d6\n"
    ".Lshop_common_2488: .word 0x6010000\n"
    ".Lshop_common_248c:\n"
    "str r1, [sp, #0xd0]\n"
    "add r1, sp, #0xa0\n"
    "mov r7, r8\n"
    "str r7, [r1]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_278c\n"
    ".align 2, 0\n"
    ".Lshop_common_26ac: .word 0x5dc\n"
    ".Lshop_common_26b0: .word 0x5ec\n"
    ".Lshop_common_26b4: .word 0x5d4\n"
    ".Lshop_common_26b8: .word 0x5d6\n"
    ".Lshop_common_26bc: .word OBJ_VRAM0\n"
    ".Lshop_common_26c0:\n"
    "str r1, [sp, #0xf0]\n"
    "add r1, sp, #0xb4\n"
    "mov r4, sb\n"
    "str r4, [r1]\n"
#endif
    "ldr r0, [r6]\n"
#if defined(REGION_JP)
    "ldr r2, [sp, #0xd0]\n"
    "subs r0, r2, r0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r5, [sp, #0xf0]\n"
    "subs r0, r5, r0\n"
#endif
    "asrs r4, r0, #4\n"
#if defined(REGION_JP)
    "add r0, sp, #0x9c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "add r0, sp, #0xb0\n"
#endif
    "str r4, [r0]\n"
    "ldr r2, [r1]\n"
    "mov sl, r1\n"
    "cmp r4, r2\n"
#if defined(REGION_JP)
    "bhs .Lshop_common_24aa\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bhs .Lshop_common_26de\n"
#endif
    "mov r0, sl\n"
#if defined(REGION_JP)
    ".Lshop_common_24aa:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_26de:\n"
#endif
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_24c8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_26fc\n"
#endif
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
#if defined(REGION_JP)
    "mov r8, r4\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r4\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_24cc\n"
    "mov r0, r8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2700\n"
    "mov r0, sb\n"
#endif
    "bl RetryMemoryAllocation\n"
#if defined(REGION_JP)
    "b .Lshop_common_24cc\n"
    ".Lshop_common_24c8:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2700\n"
    ".Lshop_common_26fc:\n"
#endif
    "movs r0, #0\n"
#if defined(REGION_JP)
    "mov r8, r0\n"
    ".Lshop_common_24cc:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov sb, r0\n"
    ".Lshop_common_2700:\n"
#endif
    "adds r5, r0, #0\n"
#if defined(REGION_JP)
    "str r5, [sp, #0xd4]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "str r5, [sp, #0xf4]\n"
#endif
    "ldr r2, [r6]\n"
    "adds r3, r5, #0\n"
#if defined(REGION_JP)
    "ldr r4, [sp, #0xd0]\n"
    "cmp r2, r4\n"
    "beq .Lshop_common_24f4\n"
    ".Lshop_common_24da:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r7, [sp, #0xf0]\n"
    "cmp r2, r7\n"
    "beq .Lshop_common_2728\n"
    ".Lshop_common_270e:\n"
#endif
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_24ea\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_271e\n"
#endif
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_24ea:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_271e:\n"
#endif
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
#if defined(REGION_JP)
    "ldr r5, [sp, #0xd0]\n"
    "cmp r2, r5\n"
    "bne .Lshop_common_24da\n"
    ".Lshop_common_24f4:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "ldr r0, [sp, #0xf0]\n"
    "cmp r2, r0\n"
    "bne .Lshop_common_270e\n"
    ".Lshop_common_2728:\n"
#endif
    "adds r5, r3, #0\n"
#if defined(REGION_JP)
    "mov r7, sl\n"
    "ldr r1, [r7]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r2, sl\n"
    "ldr r1, [r2]\n"
#endif
    "cmp r1, #1\n"
#if defined(REGION_JP)
    "bne .Lshop_common_2512\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2746\n"
#endif
    "cmp r5, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_250e\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2742\n"
#endif
    "adds r0, r5, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
    "ldm r1!, {r2, r3, r4}\n"
    "stm r0!, {r2, r3, r4}\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
    "ldm r1!, {r3, r4, r7}\n"
    "stm r0!, {r3, r4, r7}\n"
#endif
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_250e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2742:\n"
#endif
    "adds r5, #0x10\n"
#if defined(REGION_JP)
    "b .Lshop_common_2534\n"
    ".Lshop_common_2512:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "b .Lshop_common_2768\n"
    ".Lshop_common_2746:\n"
#endif
    "adds r3, r1, #0\n"
    "adds r2, r5, #0\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2532\n"
    ".Lshop_common_251a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2766\n"
    ".Lshop_common_274e:\n"
#endif
    "cmp r2, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_252a\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_275e\n"
#endif
    "adds r0, r2, #0\n"
#if defined(REGION_JP)
    "mov r1, sb\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "mov r1, r8\n"
#endif
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
#if defined(REGION_JP)
    ".Lshop_common_252a:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_275e:\n"
#endif
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
#if defined(REGION_JP)
    "bne .Lshop_common_251a\n"
    ".Lshop_common_2532:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_274e\n"
    ".Lshop_common_2766:\n"
#endif
    "adds r5, r2, #0\n"
#if defined(REGION_JP)
    ".Lshop_common_2534:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2768:\n"
#endif
    "ldr r2, [r6, #4]\n"
    "ldr r0, [r6]\n"
    "adds r1, r0, #0\n"
    "cmp r0, r2\n"
#if defined(REGION_JP)
    "beq .Lshop_common_2544\n"
    ".Lshop_common_253e:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2778\n"
    ".Lshop_common_2772:\n"
#endif
    "adds r1, #0x10\n"
    "cmp r1, r2\n"
#if defined(REGION_JP)
    "bne .Lshop_common_253e\n"
    ".Lshop_common_2544:\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "bne .Lshop_common_2772\n"
    ".Lshop_common_2778:\n"
#endif
    "cmp r0, #0\n"
#if defined(REGION_JP)
    "beq .Lshop_common_254c\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "beq .Lshop_common_2780\n"
#endif
    "bl free\n"
#if defined(REGION_JP)
    ".Lshop_common_254c:\n"
    "ldr r0, [sp, #0xd4]\n"
    "add r0, r8\n"
    "ldr r7, [sp, #0xd4]\n"
    "str r7, [r6]\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_2780:\n"
    "ldr r0, [sp, #0xf4]\n"
    "add r0, sb\n"
    "ldr r1, [sp, #0xf4]\n"
    "str r1, [r6]\n"
#endif
    "str r5, [r6, #4]\n"
    "str r0, [r6, #0xc]\n"
#if defined(REGION_JP)
    ".Lshop_common_2558:\n"
    "add sp, #0xd8\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    ".Lshop_common_278c:\n"
    "add sp, #0xf8\n"
#endif
    "pop {r3, r4, r5}\n"
    "mov r8, r3\n"
    "mov sb, r4\n"
    "mov sl, r5\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r0}\n"
    "bx r0\n"
);


static inline void SetUiVCountCompare(u16 line)
{
    // Preserve the status bits, then install the next comparison line.
    REG_DISPSTAT &= 0xFF;
    REG_DISPSTAT |= line << 8;
}

extern "C" void UpdateUiVCount(ShopScreenCore * core)
{
    // The original handler reads only the low byte of VCOUNT.
    switch (REG(u8, &REG_VCOUNT)) {
    case 23:
        while ((REG_DISPSTAT & DISPSTAT_HBLANK) == 0) {}
        REG_BG2CNT = BGCNT_PRIORITY(3) | BGCNT_MOSAIC | BGCNT_SCREENBASE(30) | BGCNT_WRAP;
        SetUiVCountCompare(159);
        break;
    case 159:
        REG_BG2CNT = BGCNT_PRIORITY(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(30) | BGCNT_WRAP;
        SetUiVCountCompare(23);
        break;
    }
}

#if defined(REGION_JP)
u16 const gShopDigitGlyphs[10] = {
        0x824F, 0x8250, 0x8251, 0x8252, 0x8253,
        0x8254, 0x8255, 0x8256, 0x8257, 0x8258,
    };
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
u16 const gShopDigitGlyphs[10] = {
        0x0030, 0x0031, 0x0032, 0x0033, 0x0034,
        0x0035, 0x0036, 0x0037, 0x0038, 0x0039,
    };
#endif

#include FOMT_TEXT_INCLUDE(shop_common_1.cc)

char const * const gShopCommonQuantitySuffixTextRef =
    gText_ShopCommon_QuantitySuffix;

#include FOMT_TEXT_INCLUDE(shop_common_2.cc)

char const * const gShopCommonOwnedQuantityLabelTextRef =
    gText_ShopCommon_OwnedQuantityLabel;
