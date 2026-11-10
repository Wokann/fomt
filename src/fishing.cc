#include "fishing.hh"

#include FOMT_TEXT_INCLUDE(fishing.cc)

u32 const gFishingCatchArticleIds[] = {
    ITEM_ARTICLE_PIRATE_TREASURE,
    ITEM_ARTICLE_FOSSIL_OF_FISH,
    ITEM_ARTICLE_WEEDS,
    ITEM_ARTICLE_MESSAGE_IN_A_BOTTLE,
    ITEM_ARTICLE_EMPTY_CAN,
    ITEM_ARTICLE_BRANCHES,
    ITEM_ARTICLE_FISH_BONES,
    ITEM_ARTICLE_BOOTS,
};

// Columns: 06-08, 09-16, 17-19, and the remaining hours.
u16 const gFishingBiteDelaySeconds[][4] = {
    { 0x0004, 0x0006, 0x0003, 0x0005 },
    { 0x0004, 0x0006, 0x0003, 0x0005 },
    { 0x0003, 0x0005, 0x0003, 0x0004 },
    { 0x0003, 0x0005, 0x0003, 0x0004 },
    { 0x0002, 0x0004, 0x0002, 0x0004 },
    { 0x0006, 0x0006, 0x0006, 0x0006 },
    { 0x000A, 0x000A, 0x000A, 0x000A },
};

u8 const gFishingCatchCategoryWeights[][5] = {
    { 0x08, 0x00, 0x05, 0x54, 0x03 },
    { 0x0A, 0x00, 0x0A, 0x50, 0x00 },
    { 0x0A, 0x00, 0x0A, 0x50, 0x00 },
    { 0x08, 0x00, 0x0F, 0x4A, 0x03 },
    { 0x07, 0x0A, 0x14, 0x3C, 0x03 },
    { 0x08, 0x00, 0x05, 0x54, 0x03 },
    { 0x61, 0x00, 0x00, 0x00, 0x03 },
};

FishingCatchConfiguration const gFishingCatchConfigurations[] = {
    { 0x00, 0x00, {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 6, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x00, 0x00, {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 6, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x00, 0x00, {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
    } },
    { 0x00, 0x00, {
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x00, 0x00, {
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
    } },
    { 0x00, 0x00, {
        { -8, -8, -8, -8, -8, -8, -8 },
        { -8, -8, -8, -8, -8, -8, -8 },
        { -8, -8, -8, -8, -8, -8, -8 },
        { -8, -8, -8, -8, -8, -8, -8 },
    } },
    { 0x00, 0x00, {
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
    } },
    { 0x00, 0x00, {
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
        { 8, 8, 8, 8, 8, 8, 8 },
    } },
    { 0x14, 0x28, {
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
        { 0, 0, 0, 0, 3, 0, 0 },
    } },
    { 0x14, 0x28, {
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
    } },
    { 0x0A, 0x0F, {
        { 1, 1, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
    } },
    { 0x0A, 0x19, {
        { -1, -1, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
        { -1, -1, 0, 0, 0, 0, 0 },
    } },
    { 0x14, 0x28, {
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
    } },
    { 0x0F, 0x19, {
        { 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0 },
    } },
    { 0x0F, 0x32, {
        { 0, 4, 0, 0, 0, 0, 0 },
        { 0, 4, 0, 0, 0, 0, 0 },
        { 0, 4, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x0F, 0x23, {
        { 0, 0, 2, 2, 0, 0, 0 },
        { 0, 0, 2, 2, 0, 0, 0 },
        { 0, 0, 2, 2, 0, 0, 0 },
        { 0, 0, 2, 2, 0, 0, 0 },
    } },
    { 0x32, 0x64, {
        { 0, 0, 0, -5, 0, 0, 0 },
        { 0, 0, 0, 5, 0, 0, 0 },
        { 0, 0, 0, 5, 0, 0, 0 },
        { 0, 0, 0, -5, 0, 0, 0 },
    } },
    { 0x07, 0x0F, {
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
    } },
    { 0x46, 0x5A, {
        { 0, 0, 0, 0, -5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x28, 0x3C, {
        { 0, 0, 0, 0, -4, 0, 0 },
        { 0, 0, 0, 0, -4, 0, 0 },
        { 0, 0, 0, 0, 4, 0, 0 },
        { 0, 0, 0, 0, 4, 0, 0 },
    } },
    { 0x14, 0x1E, {
        { 0, 0, 0, 0, -2, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, -2, 0, 0 },
        { 0, 0, 0, 0, 2, 0, 0 },
    } },
    { 0x07, 0x14, {
        { 0, 0, 1, 1, 0, 0, 0 },
        { 0, 0, 1, -1, 0, 0, 0 },
        { 0, 0, 1, 1, 0, 0, 0 },
        { 0, 0, -1, -1, 0, 0, 0 },
    } },
    { 0x0A, 0x1E, {
        { 0, 0, 2, 2, 0, 0, 0 },
        { 0, 0, 2, 2, 0, 0, 0 },
        { 0, 0, 2, 2, 0, 0, 0 },
        { 0, 0, -2, -2, 0, 0, 0 },
    } },
    { 0x32, 0x46, {
        { 0, 0, 0, 0, -4, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 4, 0, 0 },
        { 0, 0, 0, 0, 4, 0, 0 },
    } },
    { 0x32, 0x64, {
        { 0, 0, 0, 5, 0, 0, 0 },
        { 0, 0, 0, 5, 0, 0, 0 },
        { 0, 0, 0, 5, 0, 0, 0 },
        { 0, 0, 0, 5, 0, 0, 0 },
    } },
    { 0x1E, 0x46, {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, -4, 0, 0, 0 },
        { 0, 0, 0, 4, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x1E, 0x32, {
        { 0, 0, 0, 0, -4, 0, 0 },
        { 0, 0, 0, 0, -4, 0, 0 },
        { 0, 0, 0, 0, 4, 0, 0 },
        { 0, 0, 0, 0, 4, 0, 0 },
    } },
    { 0x14, 0x28, {
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x50, 0x64, {
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, -5, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
    } },
    { 0x14, 0x28, {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x64, 0xB4, {
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, -5, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x50, 0x64, {
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, -5, 0, 0 },
    } },
    { 0x1E, 0x32, {
        { 0, 0, 0, 0, -4, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 4, 0, 0 },
    } },
    { 0x05, 0x0C, {
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, -1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x0F, 0x19, {
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, -1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
    } },
    { 0x32, 0x64, {
        { 5, 5, 0, 0, 0, 0, 0 },
        { 5, 5, 0, 0, 0, 0, 0 },
        { 5, 5, 0, 0, 0, 0, 0 },
        { 5, 5, 0, 0, 0, 0, 0 },
    } },
    { 0x0F, 0x1E, {
        { 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, -1, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0 },
    } },
    { 0x32, 0x64, {
        { 0, 0, 0, 5, 0, 0, 0 },
        { 0, 0, 0, 5, 0, 0, 0 },
        { 0, 0, 0, 5, 0, 0, 0 },
        { 0, 0, 0, 5, 0, 0, 0 },
    } },
    { 0x0A, 0x14, {
        { 0, 0, 0, 0, -1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, -1, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0 },
    } },
    { 0x3C, 0x50, {
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
    } },
    { 0x28, 0x32, {
        { 0, 0, 0, 0, -4, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 4, 0, 0 },
    } },
    { 0x1E, 0x32, {
        { 4, 4, 4, 4, 0, 0, 0 },
        { 4, 4, 4, 4, 0, 0, 0 },
        { 4, 4, 4, 4, 0, 0, 0 },
        { -4, -4, -4, -4, 0, 0, 0 },
    } },
    { 0x50, 0x64, {
        { 0, 0, 0, 0, -5, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
    } },
    { 0x0F, 0x19, {
        { 1, 1, 1, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0 },
        { -1, -1, -1, -1, 0, 0, 0 },
    } },
    { 0x19, 0x32, {
        { 4, 0, 4, 0, 0, 0, 0 },
        { 4, 0, 4, 0, 0, 0, 0 },
        { 4, 0, 4, 0, 0, 0, 0 },
        { 4, 0, 4, 0, 0, 0, 0 },
    } },
    { 0x14, 0x28, {
        { 0, 0, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
        { 0, 0, 0, 0, -3, 0, 0 },
    } },
    { 0x96, 0xFA, {
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
    } },
    { 0x96, 0xFA, {
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 0 },
        { 0, 0, 0, 0, -5, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x14, 0x1E, {
        { 0, 0, 0, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 2, 0, 0 },
    } },
    { 0x14, 0x1E, {
        { 0, 0, 0, 0, 2, 0, 0 },
        { 0, 0, 0, 0, -2, 0, 0 },
        { 0, 0, 0, 0, -2, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x14, 0x1E, {
        { 0, 2, 0, 0, 0, 0, 0 },
        { 0, -2, 0, 0, 0, 0, 0 },
        { 0, 2, 0, 0, 0, 0, 0 },
        { 0, -2, 0, 0, 0, 0, 0 },
    } },
    { 0x28, 0x50, {
        { 0, 0, -5, -5, 0, 0, 0 },
        { 0, 0, 5, 5, 0, 0, 0 },
        { 0, 0, 5, 5, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x0A, 0x0F, {
        { 0, 0, -1, -1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, -1, -1, 0, 0, 0 },
        { 0, 0, 1, 1, 0, 0, 0 },
    } },
    { 0x96, 0x96, {
        { 0, 0, 0, 6, 0, 0, 0 },
        { 0, 0, 0, 6, 0, 0, 0 },
        { 0, 0, 0, 6, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x64, 0x64, {
        { 0, 0, 0, 0, 6, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 6, 0, 0 },
    } },
    { 0x78, 0x78, {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 6 },
    } },
    { 0x50, 0x50, {
        { 6, 0, 0, 0, 0, 0, 0 },
        { 6, 0, 0, 0, 0, 0, 0 },
        { 6, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
    } },
    { 0x9B, 0x9B, {
        { 0, 0, 0, 0, 0, 6, 0 },
        { 0, 0, 0, 0, 0, 6, 0 },
        { 0, 0, 0, 0, 0, 6, 0 },
        { 0, 0, 0, 0, 0, 6, 0 },
    } },
    { 0x32, 0x32, {
        { 0, 0, 0, 0, 6, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 6, 0, 0 },
    } },
};

#include "game_state.hh"

#include <stdlib.h>

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start GetFishingAttemptParameters\n"
    "GetFishingAttemptParameters:\n"
    "    push {r4, r5, lr}\n"
    "    sub sp, #8\n"
    "    adds r5, r0, #0\n"
    "    adds r0, r1, #0\n"
    "    adds r4, r2, #0\n"
    "    bl GetFishingArea\n"
    "    str r0, [sp, #4]\n"
    "    cmp r0, #7\n"
    "    bne .Lscalar_7_0\n"
    "    movs r0, #0\n"
    "    str r0, [sp, #0]\n"
    "    b .Lscalar_7_5\n"
    ".Lscalar_7_0:\n"
    "    movs r1, #3\n"
    "    ldrh r0, [r4, #0]\n"
    "    lsls r2, r0, #27\n"
    "    lsrs r0, r2, #3\n"
    "    movs r3, #250\n"
    "    lsls r3, r3, #24\n"
    "    adds r0, r0, r3\n"
    "    lsrs r0, r0, #24\n"
    "    cmp r0, #2\n"
    "    bhi .Lscalar_7_1\n"
    "    movs r1, #0\n"
    "    b .Lscalar_7_3\n"
    ".Lscalar_7_1:\n"
    "    lsrs r0, r2, #3\n"
    "    movs r3, #247\n"
    "    lsls r3, r3, #24\n"
    "    adds r0, r0, r3\n"
    "    lsrs r0, r0, #24\n"
    "    cmp r0, #7\n"
    "    bhi .Lscalar_7_2\n"
    "    movs r1, #1\n"
    "    b .Lscalar_7_3\n"
    ".Lscalar_7_2:\n"
    "    lsrs r0, r2, #3\n"
    "    movs r2, #239\n"
    "    lsls r2, r2, #24\n"
    "    adds r0, r0, r2\n"
    "    lsrs r0, r0, #24\n"
    "    cmp r0, #2\n"
    "    bhi .Lscalar_7_3\n"
    "    movs r1, #2\n"
    ".Lscalar_7_3:\n"
    "    ldr r2, .Lscalar_7_6\n"
    "    lsls r1, r1, #1\n"
    "    ldr r0, [sp, #4]\n"
    "    lsls r0, r0, #3\n"
    "    adds r1, r1, r0\n"
    "    adds r1, r1, r2\n"
    "    ldrh r0, [r1, #0]\n"
    "    lsls r1, r0, #4\n"
    "    subs r1, r1, r0\n"
    "    lsls r1, r1, #18\n"
    "    lsrs r1, r1, #16\n"
    "    ldr r2, .Lscalar_7_7\n"
    "    ldr r0, [sp, #0]\n"
    "    ands r0, r2\n"
    "    orrs r0, r1\n"
    "    str r0, [sp, #0]\n"
    "    movs r4, #0\n"
    "    bl rand\n"
    "    asrs r0, r0, #8\n"
    "    ldr r1, [sp, #4]\n"
    "    cmp r1, #6\n"
    "    bgt .Lscalar_7_4\n"
    "    cmp r1, #0\n"
    "    blt .Lscalar_7_4\n"
    "    movs r1, #6\n"
    "    bl __modsi3\n"
    "    adds r4, r0, #5\n"
    ".Lscalar_7_4:\n"
    "    lsls r0, r4, #1\n"
    "    adds r0, r0, r4\n"
    "    lsls r0, r0, #17\n"
    "    ldr r2, .Lscalar_7_8\n"
    "    ldr r1, [sp, #0]\n"
    "    ands r1, r2\n"
    "    orrs r1, r0\n"
    "    str r1, [sp, #0]\n"
    ".Lscalar_7_5:\n"
    "    ldr r0, [sp, #0]\n"
    "    ldr r1, [sp, #4]\n"
    "    str r0, [r5, #0]\n"
    "    str r1, [r5, #4]\n"
    "    adds r0, r5, #0\n"
    "    add sp, #8\n"
    "    pop {r4, r5}\n"
    "    pop {r2}\n"
    "    bx r2\n"
    ".Lscalar_7_6: .word gFishingBiteDelaySeconds\n"
    ".Lscalar_7_7: .word 0xffff0000\n"
    ".Lscalar_7_8: .word 0x0000ffff\n"
);

asm_unified(
    ".text\n"
    "thumb_func_start SelectFishingCatch\n"
    "SelectFishingCatch:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, r9\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    sub sp, #164\n"
    "    str r0, [sp, #144]\n"
    "    str r1, [sp, #148]\n"
    "    mov r9, r3\n"
    "    lsls r2, r2, #24\n"
    "    lsrs r2, r2, #24\n"
    "    str r2, [sp, #152]\n"
    "    movs r7, #0\n"
    "    mov r5, sp\n"
    "    ldr r0, .Lscalar_8_3\n"
    "    str r0, [sp, #0]\n"
    "    movs r4, #0\n"
    "    strh r7, [r5, #4]\n"
    "    add r0, sp, #8\n"
    "    bl __12RucksackItem\n"
    "    strb r4, [r5, #12]\n"
    "    strb r4, [r5, #13]\n"
    "    movs r0, #59\n"
    "    str r0, [sp, #16]\n"
    "    strb r4, [r5, #20]\n"
    "    movs r6, #0\n"
    "    bl rand\n"
    "    asrs r0, r0, #8\n"
    "    movs r1, #100\n"
    "    bl __modsi3\n"
    "    movs r4, #0\n"
    "    movs r3, #0\n"
    "    ldr r1, .Lscalar_8_4\n"
    "    lsls r0, r0, #24\n"
    "    asrs r5, r0, #24\n"
    "    ldr r2, [sp, #148]\n"
    "    lsls r0, r2, #2\n"
    "    adds r0, r0, r2\n"
    "    adds r1, r0, r1\n"
    ".Lscalar_8_0:\n"
    "    ldrb r2, [r1, #0]\n"
    "    movs r0, #0\n"
    "    ldrsb r0, [r1, r0]\n"
    "    cmp r0, #0\n"
    "    ble .Lscalar_8_1\n"
    "    lsls r0, r4, #24\n"
    "    asrs r0, r0, #24\n"
    "    adds r0, r0, r2\n"
    "    lsls r0, r0, #24\n"
    "    lsrs r4, r0, #24\n"
    "    asrs r0, r0, #24\n"
    "    cmp r5, r0\n"
    "    blt .Lscalar_8_5\n"
    ".Lscalar_8_1:\n"
    "    adds r1, #1\n"
    "    adds r3, #1\n"
    "    cmp r3, #4\n"
    "    ble .Lscalar_8_0\n"
    ".Lscalar_8_2:\n"
    "    movs r5, #0\n"
    "    movs r2, #0\n"
    "    lsls r0, r6, #24\n"
    "    asrs r0, r0, #24\n"
    "    cmp r0, #2\n"
    "    beq .Lscalar_8_8\n"
    "    cmp r0, #2\n"
    "    bgt .Lscalar_8_6\n"
    "    cmp r0, #1\n"
    "    beq .Lscalar_8_7\n"
    "    b .Lscalar_8_11\n"
    ".Lscalar_8_3: .word gText_Fishing_NoCatch\n"
    ".Lscalar_8_4: .word gFishingCatchCategoryWeights\n"
    ".Lscalar_8_5:\n"
    "    lsls r0, r3, #24\n"
    "    lsrs r6, r0, #24\n"
    "    b .Lscalar_8_2\n"
    ".Lscalar_8_6:\n"
    "    cmp r0, #3\n"
    "    beq .Lscalar_8_9\n"
    "    cmp r0, #4\n"
    "    beq .Lscalar_8_10\n"
    "    b .Lscalar_8_11\n"
    ".Lscalar_8_7:\n"
    "    movs r2, #3\n"
    "    b .Lscalar_8_12\n"
    ".Lscalar_8_8:\n"
    "    movs r5, #4\n"
    "    movs r2, #7\n"
    "    b .Lscalar_8_12\n"
    ".Lscalar_8_9:\n"
    "    movs r5, #8\n"
    "    movs r2, #52\n"
    "    b .Lscalar_8_12\n"
    ".Lscalar_8_10:\n"
    "    movs r5, #53\n"
    "    movs r2, #58\n"
    "    b .Lscalar_8_12\n"
    ".Lscalar_8_11:\n"
    "    movs r7, #1\n"
    "    negs r7, r7\n"
    ".Lscalar_8_12:\n"
    "    movs r0, #1\n"
    "    negs r0, r0\n"
    "    cmp r7, r0\n"
    "    bne .Lscalar_8_13\n"
    "    b .Lscalar_8_74\n"
    ".Lscalar_8_13:\n"
    "    movs r3, #0\n"
    "    mov sl, r3\n"
    "    movs r7, #0\n"
    "    movs r4, #0\n"
    "    mov r8, r4\n"
    "    movs r1, #0\n"
    "    mov r0, sp\n"
    "    adds r0, #24\n"
    "    str r0, [sp, #160]\n"
    "    mov r3, sp\n"
    "    adds r3, #72\n"
    "    str r3, [sp, #156]\n"
    "    adds r2, #1\n"
    "    mov ip, r2\n"
    "    adds r4, r0, #0\n"
    "    movs r2, #0\n"
    ".Lscalar_8_14:\n"
    "    adds r0, r4, r1\n"
    "    strb r2, [r0, #0]\n"
    "    adds r0, r3, r1\n"
    "    strb r2, [r0, #0]\n"
    "    adds r1, #1\n"
    "    cmp r1, #44\n"
    "    ble .Lscalar_8_14\n"
    "    adds r4, r5, #0\n"
    "    cmp r4, ip\n"
    "    bge .Lscalar_8_32\n"
    "    mov r1, r9\n"
    "    ldrb r0, [r1, #17]\n"
    "    lsls r0, r0, #30\n"
    "    lsrs r5, r0, #30\n"
    "    lsls r3, r4, #5\n"
    ".Lscalar_8_15:\n"
    "    cmp r5, #1\n"
    "    beq .Lscalar_8_19\n"
    "    cmp r5, #1\n"
    "    bgt .Lscalar_8_16\n"
    "    cmp r5, #0\n"
    "    beq .Lscalar_8_17\n"
    "    b .Lscalar_8_25\n"
    ".Lscalar_8_16:\n"
    "    cmp r5, #2\n"
    "    beq .Lscalar_8_21\n"
    "    cmp r5, #3\n"
    "    beq .Lscalar_8_23\n"
    "    b .Lscalar_8_25\n"
    ".Lscalar_8_17:\n"
    "    ldr r2, .Lscalar_8_18\n"
    "    b .Lscalar_8_24\n"
    "    .align 2, 0\n"
    ".Lscalar_8_18: .word gFishingCatchConfigurations + 2\n"
    ".Lscalar_8_19:\n"
    "    ldr r0, .Lscalar_8_20\n"
    "    adds r0, r0, r3\n"
    "    mov r8, r0\n"
    "    b .Lscalar_8_25\n"
    ".Lscalar_8_20: .word gFishingCatchConfigurations + 2 + 7 * 1\n"
    ".Lscalar_8_21:\n"
    "    ldr r1, .Lscalar_8_22\n"
    "    adds r1, r1, r3\n"
    "    mov r8, r1\n"
    "    b .Lscalar_8_25\n"
    ".Lscalar_8_22: .word gFishingCatchConfigurations + 2 + 7 * 2\n"
    ".Lscalar_8_23:\n"
    "    ldr r2, .Lscalar_8_29\n"
    ".Lscalar_8_24:\n"
    "    adds r2, r2, r3\n"
    "    mov r8, r2\n"
    ".Lscalar_8_25:\n"
    "    ldr r0, [sp, #148]\n"
    "    add r0, r8\n"
    "    ldrb r2, [r0, #0]\n"
    "    movs r1, #0\n"
    "    ldrsb r1, [r0, r1]\n"
    "    adds r6, r0, #0\n"
    "    cmp r1, #0\n"
    "    beq .Lscalar_8_31\n"
    "    cmp r1, #0\n"
    "    bge .Lscalar_8_26\n"
    "    negs r0, r1\n"
    "    lsls r0, r0, #24\n"
    "    lsrs r2, r0, #24\n"
    ".Lscalar_8_26:\n"
    "    lsls r0, r2, #24\n"
    "    movs r1, #255\n"
    "    lsls r1, r1, #24\n"
    "    adds r0, r0, r1\n"
    "    lsrs r2, r0, #24\n"
    "    ldr r0, [sp, #152]\n"
    "    cmp r0, #6\n"
    "    beq .Lscalar_8_27\n"
    "    cmp r2, #7\n"
    "    bne .Lscalar_8_28\n"
    ".Lscalar_8_27:\n"
    "    ldr r2, [sp, #152]\n"
    ".Lscalar_8_28:\n"
    "    lsls r0, r2, #24\n"
    "    asrs r0, r0, #24\n"
    "    ldr r1, [sp, #152]\n"
    "    cmp r1, r0\n"
    "    bne .Lscalar_8_31\n"
    "    movs r0, #0\n"
    "    ldrsb r0, [r6, r0]\n"
    "    cmp r0, #0\n"
    "    ble .Lscalar_8_30\n"
    "    lsls r0, r7, #24\n"
    "    asrs r0, r0, #24\n"
    "    ldr r2, [sp, #156]\n"
    "    adds r1, r2, r0\n"
    "    strb r4, [r1, #0]\n"
    "    adds r0, #1\n"
    "    lsls r0, r0, #24\n"
    "    lsrs r7, r0, #24\n"
    "    b .Lscalar_8_31\n"
    "    .align 2, 0\n"
    ".Lscalar_8_29: .word gFishingCatchConfigurations + 2 + 7 * 3\n"
    ".Lscalar_8_30:\n"
    "    cmp r0, #0\n"
    "    bge .Lscalar_8_31\n"
    "    mov r1, sl\n"
    "    lsls r0, r1, #24\n"
    "    asrs r0, r0, #24\n"
    "    ldr r2, [sp, #160]\n"
    "    adds r1, r2, r0\n"
    "    strb r4, [r1, #0]\n"
    "    adds r0, #1\n"
    "    lsls r0, r0, #24\n"
    "    lsrs r0, r0, #24\n"
    "    mov sl, r0\n"
    ".Lscalar_8_31:\n"
    "    adds r3, #32\n"
    "    adds r4, #1\n"
    "    cmp r4, ip\n"
    "    blt .Lscalar_8_15\n"
    ".Lscalar_8_32:\n"
    "    cmp r7, #0\n"
    "    bne .Lscalar_8_33\n"
    "    mov r3, sl\n"
    "    cmp r3, #0\n"
    "    bne .Lscalar_8_33\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_33:\n"
    "    lsls r0, r7, #24\n"
    "    cmp r0, #0\n"
    "    ble .Lscalar_8_35\n"
    "    mov r4, sl\n"
    "    lsls r0, r4, #24\n"
    "    cmp r0, #0\n"
    "    ble .Lscalar_8_35\n"
    "    bl rand\n"
    "    asrs r0, r0, #8\n"
    "    movs r1, #100\n"
    "    bl __modsi3\n"
    "    cmp r0, #69\n"
    "    bgt .Lscalar_8_34\n"
    "    movs r0, #0\n"
    "    mov sl, r0\n"
    "    b .Lscalar_8_35\n"
    ".Lscalar_8_34:\n"
    "    movs r7, #0\n"
    ".Lscalar_8_35:\n"
    "    lsls r0, r7, #24\n"
    "    asrs r1, r0, #24\n"
    "    mov r2, sl\n"
    "    lsls r0, r2, #24\n"
    "    asrs r0, r0, #24\n"
    "    cmp r1, r0\n"
    "    ble .Lscalar_8_36\n"
    "    adds r7, r1, #0\n"
    "    ldr r3, [sp, #156]\n"
    "    mov r8, r3\n"
    "    b .Lscalar_8_37\n"
    ".Lscalar_8_36:\n"
    "    adds r7, r0, #0\n"
    "    ldr r4, [sp, #160]\n"
    "    mov r8, r4\n"
    ".Lscalar_8_37:\n"
    "    cmp r7, #1\n"
    "    ble .Lscalar_8_38\n"
    "    bl rand\n"
    "    asrs r0, r0, #8\n"
    "    adds r1, r7, #0\n"
    "    bl __modsi3\n"
    "    adds r7, r0, #0\n"
    "    b .Lscalar_8_39\n"
    ".Lscalar_8_38:\n"
    "    movs r7, #0\n"
    ".Lscalar_8_39:\n"
    "    mov r1, r8\n"
    "    adds r0, r1, r7\n"
    "    movs r7, #0\n"
    "    ldrsb r7, [r0, r7]\n"
    "    subs r0, r7, #2\n"
    "    cmp r0, #56\n"
    "    bls .Lscalar_8_40\n"
    "    b .Lscalar_8_73\n"
    ".Lscalar_8_40:\n"
    "    lsls r0, r0, #2\n"
    "    ldr r1, .Lscalar_8_41\n"
    "    adds r0, r0, r1\n"
    "    ldr r0, [r0, #0]\n"
    "    mov pc, r0\n"
    "    .align 2, 0\n"
    ".Lscalar_8_41: .word .Lscalar_8_42\n"
    ".Lscalar_8_42: .word .Lscalar_8_43\n"
    "    .word .Lscalar_8_45\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_73\n"
    "    .word .Lscalar_8_47\n"
    "    .word .Lscalar_8_58\n"
    "    .word .Lscalar_8_61\n"
    "    .word .Lscalar_8_62\n"
    "    .word .Lscalar_8_66\n"
    "    .word .Lscalar_8_71\n"
    ".Lscalar_8_43:\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    movs r1, #2\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_8_44\n"
    "    b .Lscalar_8_73\n"
    ".Lscalar_8_44:\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_45:\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    movs r1, #3\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_8_46\n"
    "    b .Lscalar_8_73\n"
    ".Lscalar_8_46:\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_47:\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    movs r1, #53\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_48\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_48:\n"
    "    add r1, sp, #120\n"
    "    strh r0, [r1, #0]\n"
    "    ldrh r2, [r1, #18]\n"
    "    ldr r0, .Lscalar_8_55\n"
    "    ands r0, r2\n"
    "    strh r0, [r1, #18]\n"
    "    ldrb r2, [r1, #19]\n"
    "    movs r0, #17\n"
    "    negs r0, r0\n"
    "    ands r0, r2\n"
    "    strb r0, [r1, #19]\n"
    "    mov r2, sp\n"
    "    adds r2, #122\n"
    "    movs r3, #0\n"
    "    add r0, sp, #136\n"
    ".Lscalar_8_49:\n"
    "    strh r3, [r0, #0]\n"
    "    subs r0, #2\n"
    "    cmp r0, r2\n"
    "    bge .Lscalar_8_49\n"
    "    movs r6, #0\n"
    "    movs r5, #0\n"
    "    ldr r0, .Lscalar_8_56\n"
    "    add r0, r9\n"
    "    ldrb r0, [r0, #0]\n"
    "    cmp r6, r0\n"
    "    bge .Lscalar_8_53\n"
    "    adds r4, r1, #0\n"
    ".Lscalar_8_50:\n"
    "    ldr r0, .Lscalar_8_57\n"
    "    add r0, r9\n"
    "    adds r1, r4, #0\n"
    "    adds r2, r5, #0\n"
    "    bl CopyRecipe__C22CookingRecipeInventoryP19CookingRecipeRecordUi\n"
    "    ldrh r0, [r4, #0]\n"
    "    cmp r0, #122\n"
    "    beq .Lscalar_8_51\n"
    "    cmp r0, #122\n"
    "    blt .Lscalar_8_52\n"
    "    cmp r0, #129\n"
    "    bgt .Lscalar_8_52\n"
    "    cmp r0, #128\n"
    "    blt .Lscalar_8_52\n"
    ".Lscalar_8_51:\n"
    "    ldrb r1, [r4, #19]\n"
    "    movs r0, #16\n"
    "    ands r0, r1\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_52\n"
    "    adds r6, #1\n"
    ".Lscalar_8_52:\n"
    "    adds r5, #1\n"
    "    ldr r0, .Lscalar_8_56\n"
    "    add r0, r9\n"
    "    ldrb r0, [r0, #0]\n"
    "    cmp r5, r0\n"
    "    blt .Lscalar_8_50\n"
    ".Lscalar_8_53:\n"
    "    cmp r6, #2\n"
    "    ble .Lscalar_8_54\n"
    "    b .Lscalar_8_73\n"
    ".Lscalar_8_54:\n"
    "    b .Lscalar_8_72\n"
    "    .align 2, 0\n"
    ".Lscalar_8_55: .word 0xfffff000\n"
    ".Lscalar_8_56: .word 0x00002c1a\n"
    ".Lscalar_8_57: .word 0x00002214\n"
    ".Lscalar_8_58:\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    movs r1, #54\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_59\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_59:\n"
    "    mov r2, r9\n"
    "    ldrb r0, [r2, #18]\n"
    "    lsls r0, r0, #27\n"
    "    lsrs r0, r0, #3\n"
    "    movs r3, #248\n"
    "    lsls r3, r3, #24\n"
    "    adds r0, r0, r3\n"
    "    lsrs r0, r0, #24\n"
    "    cmp r0, #11\n"
    "    bls .Lscalar_8_60\n"
    "    b .Lscalar_8_73\n"
    ".Lscalar_8_60:\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_61:\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    movs r1, #55\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_73\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_62:\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    movs r1, #56\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_8_72\n"
    "    movs r5, #0\n"
    "    mov r4, r9\n"
    "    adds r4, #84\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #61\n"
    "    bl IsDisplayEnabled__C11ShippingBini\n"
    "    lsls r0, r0, #24\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_63\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #61\n"
    "    bl GetAmountShipped__C11ShippingBini\n"
    "    adds r5, r0, #0\n"
    ".Lscalar_8_63:\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #62\n"
    "    bl IsDisplayEnabled__C11ShippingBini\n"
    "    lsls r0, r0, #24\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_64\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #62\n"
    "    bl GetAmountShipped__C11ShippingBini\n"
    "    adds r5, r5, r0\n"
    ".Lscalar_8_64:\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #63\n"
    "    bl IsDisplayEnabled__C11ShippingBini\n"
    "    lsls r0, r0, #24\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_65\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #63\n"
    "    bl GetAmountShipped__C11ShippingBini\n"
    "    adds r5, r5, r0\n"
    ".Lscalar_8_65:\n"
    "    cmp r5, #199\n"
    "    bhi .Lscalar_8_73\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_66:\n"
    "    movs r5, #178\n"
    "    lsls r5, r5, #6\n"
    "    add r5, r9\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #57\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_8_72\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #53\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    negs r1, r0\n"
    "    orrs r1, r0\n"
    "    lsrs r4, r1, #31\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #54\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_67\n"
    "    adds r4, #1\n"
    ".Lscalar_8_67:\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #55\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_68\n"
    "    adds r0, r4, #1\n"
    "    lsls r0, r0, #24\n"
    "    lsrs r4, r0, #24\n"
    ".Lscalar_8_68:\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #56\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_69\n"
    "    adds r0, r4, #1\n"
    "    lsls r0, r0, #24\n"
    "    lsrs r4, r0, #24\n"
    ".Lscalar_8_69:\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #58\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_70\n"
    "    adds r0, r4, #1\n"
    "    lsls r0, r0, #24\n"
    "    lsrs r4, r0, #24\n"
    ".Lscalar_8_70:\n"
    "    cmp r4, #4\n"
    "    bhi .Lscalar_8_73\n"
    "    b .Lscalar_8_72\n"
    ".Lscalar_8_71:\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    movs r1, #58\n"
    "    bl GetCatchCount__C14FishingRecordsUi\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_8_72\n"
    "    mov r0, r9\n"
    "    bl GetFlag4__C18GameStateSaveImage\n"
    "    lsls r0, r0, #24\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_8_73\n"
    ".Lscalar_8_72:\n"
    "    movs r7, #1\n"
    "    negs r7, r7\n"
    ".Lscalar_8_73:\n"
    "    movs r0, #1\n"
    "    negs r0, r0\n"
    "    cmp r7, r0\n"
    "    beq .Lscalar_8_74\n"
    "    cmp r7, #7\n"
    "    bgt .Lscalar_8_77\n"
    "    cmp r7, #2\n"
    "    beq .Lscalar_8_76\n"
    "    add r4, sp, #140\n"
    "    ldr r1, .Lscalar_8_75\n"
    "    lsls r0, r7, #2\n"
    "    adds r0, r0, r1\n"
    "    ldr r5, [r0, #0]\n"
    "    adds r0, r4, #0\n"
    "    adds r1, r5, #0\n"
    "    bl __7ArticleUi\n"
    "    ldrb r1, [r4, #0]\n"
    "    ldr r0, [sp, #160]\n"
    "    bl __12RucksackItemG7Article\n"
    "    ldr r0, [sp, #24]\n"
    "    str r0, [sp, #8]\n"
    "    mov r4, sp\n"
    "    adds r4, #141\n"
    "    adds r0, r4, #0\n"
    "    adds r1, r5, #0\n"
    "    bl __7ArticleUi\n"
    "    adds r0, r4, #0\n"
    "    bl GetName__C7Article\n"
    "    str r0, [sp, #0]\n"
    ".Lscalar_8_74:\n"
    "    mov r1, sp\n"
    "    movs r0, #0\n"
    "    strh r0, [r1, #4]\n"
    "    b .Lscalar_8_82\n"
    ".Lscalar_8_75: .word gFishingCatchArticleIds\n"
    ".Lscalar_8_76:\n"
    "    mov r1, sp\n"
    "    movs r4, #0\n"
    "    movs r0, #1\n"
    "    strb r0, [r1, #12]\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    movs r1, #2\n"
    "    bl GetName__C14FishingRecordsUi\n"
    "    str r0, [sp, #0]\n"
    "    mov r0, sp\n"
    "    strh r4, [r0, #4]\n"
    "    b .Lscalar_8_82\n"
    ".Lscalar_8_77:\n"
    "    mov r2, sp\n"
    "    ldr r1, .Lscalar_8_79\n"
    "    lsls r0, r7, #5\n"
    "    adds r0, r0, r1\n"
    "    ldrb r1, [r0, #0]\n"
    "    strh r1, [r2, #4]\n"
    "    ldrb r1, [r0, #1]\n"
    "    mov r0, sp\n"
    "    ldrh r0, [r0, #4]\n"
    "    subs r6, r1, r0\n"
    "    cmp r6, #0\n"
    "    ble .Lscalar_8_78\n"
    "    bl rand\n"
    "    mov r5, sp\n"
    "    mov r4, sp\n"
    "    asrs r0, r0, #8\n"
    "    adds r1, r6, #1\n"
    "    bl __modsi3\n"
    "    ldrh r1, [r4, #4]\n"
    "    adds r1, r1, r0\n"
    "    strh r1, [r5, #4]\n"
    ".Lscalar_8_78:\n"
    "    movs r1, #162\n"
    "    mov r0, sp\n"
    "    ldrh r0, [r0, #4]\n"
    "    cmp r0, #25\n"
    "    bhi .Lscalar_8_80\n"
    "    movs r1, #160\n"
    "    b .Lscalar_8_81\n"
    ".Lscalar_8_79: .word gFishingCatchConfigurations\n"
    ".Lscalar_8_80:\n"
    "    cmp r0, #49\n"
    "    bhi .Lscalar_8_81\n"
    "    movs r1, #161\n"
    ".Lscalar_8_81:\n"
    "    add r4, sp, #28\n"
    "    adds r0, r4, #0\n"
    "    bl __4FoodUi\n"
    "    ldrb r1, [r4, #0]\n"
    "    mov r0, sp\n"
    "    adds r0, #29\n"
    "    ldrb r0, [r0, #0]\n"
    "    lsls r0, r0, #8\n"
    "    orrs r0, r1\n"
    "    mov r1, sp\n"
    "    adds r1, #30\n"
    "    ldrb r1, [r1, #0]\n"
    "    lsls r1, r1, #16\n"
    "    orrs r1, r0\n"
    "    ldr r0, [sp, #160]\n"
    "    bl __12RucksackItemG4Food\n"
    "    ldr r0, [sp, #24]\n"
    "    str r0, [sp, #8]\n"
    "    movs r0, #178\n"
    "    lsls r0, r0, #6\n"
    "    add r0, r9\n"
    "    adds r1, r7, #0\n"
    "    bl GetName__C14FishingRecordsUi\n"
    "    str r0, [sp, #0]\n"
    "    cmp r7, #52\n"
    "    ble .Lscalar_8_82\n"
    "    mov r1, sp\n"
    "    movs r0, #1\n"
    "    strb r0, [r1, #13]\n"
    "    str r7, [sp, #16]\n"
    ".Lscalar_8_82:\n"
    "    movs r0, #1\n"
    "    negs r0, r0\n"
    "    cmp r7, r0\n"
    "    beq .Lscalar_8_84\n"
    "    movs r4, #178\n"
    "    lsls r4, r4, #6\n"
    "    add r4, r9\n"
    "    adds r0, r4, #0\n"
    "    adds r1, r7, #0\n"
    "    bl GetMaximumSize__C14FishingRecordsUi\n"
    "    movs r5, #0\n"
    "    cmp r0, #0\n"
    "    bne .Lscalar_8_83\n"
    "    movs r5, #1\n"
    ".Lscalar_8_83:\n"
    "    mov r0, sp\n"
    "    ldrh r2, [r0, #4]\n"
    "    adds r0, r4, #0\n"
    "    adds r1, r7, #0\n"
    "    bl RegisterCatch__14FishingRecordsUiUi\n"
    "    lsls r0, r0, #24\n"
    "    lsrs r0, r0, #24\n"
    "    cmp r5, #0\n"
    "    bne .Lscalar_8_84\n"
    "    cmp r0, #0\n"
    "    beq .Lscalar_8_84\n"
    "    mov r1, sp\n"
    "    movs r0, #1\n"
    "    strb r0, [r1, #20]\n"
    ".Lscalar_8_84:\n"
    "    ldr r1, [sp, #144]\n"
    "    mov r0, sp\n"
    "    ldmia r0!, {r2, r3, r4}\n"
    "    stmia r1!, {r2, r3, r4}\n"
    "    ldmia r0!, {r2, r3, r4}\n"
    "    stmia r1!, {r2, r3, r4}\n"
    "    ldr r0, [sp, #144]\n"
    "    add sp, #164\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov r9, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r1}\n"
    "    bx r1\n"
    "    .align 2, 0\n"
);
