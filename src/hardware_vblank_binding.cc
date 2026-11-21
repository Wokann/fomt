#include "prelude.h"
#include "hardware_vblank_binding.hh"
#include "gbaio.h"

HardwareManagerVBlankBinding * gCurrentHardwareVBlankBinding;

void func_080D788C(struct HardwareLinkedList * list)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    func_08009984(list);
}

// This retained cleanup installs the HardwareInterruptList table before
// base cleanup. Its original emitting unit is still unknown; keep the native
// ABI body until its relationship to the earlier destructor is recovered.
void func_080D78BC(struct HardwareLinkedList * list, u32 flags)
{
    *reinterpret_cast<void ***>(reinterpret_cast<u8 *>(list) + 8) =
        reinterpret_cast<void **>(__vt_21HardwareInterruptList);
    // This retained cleanup calls the original clear entry, not its copy.
    func_0800956C(list);
    func_080098DC(list, flags);
}

void RunHardwareManagerVBlankCommands(void)
{
    HardwareLinkedList * commands = gCurrentHardwareVBlankBinding->commands;
    commands->Run();
}

HardwareManagerVBlankBinding::HardwareManagerVBlankBinding(HardwareLinkedList * const & list)
    : commands(list), guard(INTR_FLAG_VBLANK), previous(this),
      previous_handler(ExchangeInterruptHandler(IRQ_INDEX_VBLANK, RunHardwareManagerVBlankCommands))
{
    AcknowledgeAndEnableInterrupts(INTR_FLAG_VBLANK);
}

asm_unified(
    "    .include \"asm/macro.inc\"\n"
    "    .include \"asm/gba.inc\"\n"
    "    .text\n"
    "    .thumb\n"
    "    .align 2, 0\n"
    "\n"
    "    @ HardwareManagerVBlankBinding::~HardwareManagerVBlankBinding().\n"
    "    @ The C++ lifetime model is known; two instruction operands still differ.\n"
    "    thumb_func_start _._28HardwareManagerVBlankBinding\n"
    "_._28HardwareManagerVBlankBinding:\n"
    "    push {r4, r5, lr}\n"
    "    adds r4, r0, #0\n"
    "    adds r5, r1, #0\n"
    "    ldr r0, .LVBlankBindingVTable\n"
    "    str r0, [r4, #0x14]\n"
    "    movs r0, #INTR_FLAG_VBLANK\n"
    "    bl DisableInterrupts\n"
    "    ldr r1, [r4, #0x10]\n"
    "    movs r0, #IRQ_INDEX_VBLANK\n"
    "    bl ExchangeInterruptHandler\n"
    "    ldr r0, .LVBlankRestoreVTable\n"
    "    str r0, [r4, #0x0c]\n"
    "    ldr r1, .LVBlankCurrentBinding\n"
    "    ldr r0, [r4, #8]\n"
    "    str r0, [r1]\n"
    "    ldrh r0, [r4, #4]\n"
    "    cmp r0, #0\n"
    "    beq .LVBlankInterruptRestored\n"
    "    bl EnableInterrupts\n"
    ".LVBlankInterruptRestored:\n"
    "    movs r0, #1\n"
    "    ands r5, r0\n"
    "    cmp r5, #0\n"
    "    beq .LVBlankBindingDestroyed\n"
    "    adds r0, r4, #0\n"
    "    bl __builtin_delete\n"
    ".LVBlankBindingDestroyed:\n"
    "    pop {r4, r5}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
    ".LVBlankBindingVTable: .word __vt_28HardwareManagerVBlankBinding\n"
    ".LVBlankRestoreVTable: .word __vt_29HardwareManagerBindingRestore\n"
    ".LVBlankCurrentBinding: .word gCurrentHardwareVBlankBinding\n"
);

void AppendHardwareVBlankCommand(HardwareLinkedList * list, HardwareLinkBase * link)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    list->HardwareLinkedList::Append(link);
}
