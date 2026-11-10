#include "prelude.h"

#pragma implementation "ui_vcount.hh"
#include "ui_vcount.hh"
#include "shop_common.hh"
#include "gbaio.h"

extern "C" {
ShopScreenCore * const * gUiVCountContext;
}

extern "C" void HandleUiVCountInterrupt()
{
    UpdateUiVCount(*gUiVCountContext);
}

UiVCountBinding::UiVCountBinding(ShopScreenCore * const & input)
    : value(input), guard(INTR_FLAG_VCOUNT), context(value),
      previous_handler(ExchangeInterruptHandler(IRQ_INDEX_VCOUNT, HandleUiVCountInterrupt))
{
    AcknowledgeAndEnableInterrupts(INTR_FLAG_VCOUNT);
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start _._15UiVCountBinding\n"
    "_._15UiVCountBinding:\n"
    "    push {r4, r5, lr}\n"
    "    adds r4, r0, #0\n"
    "    adds r5, r1, #0\n"
    "    ldr r0, .Lcleanup_2_2\n"
    "    str r0, [r4, #20]\n"
    "    movs r0, #4\n"
    "    bl DisableInterrupts\n"
    "    ldr r1, [r4, #16]\n"
    "    movs r0, #2\n"
    "    bl ExchangeInterruptHandler\n"
    "    ldr r0, .Lcleanup_2_3\n"
    "    str r0, [r4, #12]\n"
    "    ldr r1, .Lcleanup_2_4\n"
    "    ldr r0, [r4, #8]\n"
    "    str r0, [r1, #0]\n"
    "    ldrh r0, [r4, #4]\n"
    "    cmp r0, #0\n"
    "    beq .Lcleanup_2_0\n"
    "    bl EnableInterrupts\n"
    ".Lcleanup_2_0:\n"
    "    movs r0, #1\n"
    "    ands r0, r5\n"
    "    cmp r0, #0\n"
    "    beq .Lcleanup_2_1\n"
    "    adds r0, r4, #0\n"
    "    bl __builtin_delete\n"
    ".Lcleanup_2_1:\n"
    "    pop {r4, r5}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    ".Lcleanup_2_2: .word __vt_15UiVCountBinding\n"
    ".Lcleanup_2_3: .word __vt_20UiVCountContextScope\n"
    ".Lcleanup_2_4: .word gUiVCountContext\n"
);
