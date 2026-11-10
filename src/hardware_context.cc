#include "prelude.h"
#include "hardware_context.hh"
#include "hardware_manager.hh"
#include "hardware_sprite_buffer.hh"
#include "gbaio.h"

#include <new>

HardwareContext::HardwareContext()
{
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, 0, 0x20);
    u16 status = state->display.status;
    status |= DISPSTAT_VBLANK_INTR;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareContext::HardwareContext(HardwareInputRepeatParameters const & input)
{
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, 0, 0x20);
    u16 status = state->display.status;
    status |= DISPSTAT_VBLANK_INTR;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareContext::HardwareContext(HardwareSpriteBufferParameters const & buffer)
{
    struct HardwareCoreState * state = new HardwareCoreState(30, 4, buffer);
    u16 status = state->display.status;
    status |= DISPSTAT_VBLANK_INTR;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareContext::HardwareContext(HardwareInputRepeatParameters const & input,
    HardwareSpriteBufferParameters const & buffer)
{
    struct HardwareCoreState * state = new HardwareCoreState(input.delay, input.interval, buffer);
    u16 status = state->display.status;
    status |= DISPSTAT_VBLANK_INTR;
    state->display.status = status;
    REG_DISPSTAT = status;
    this->state = state;
}

HardwareContext::~HardwareContext()
{
    delete state;
}

// These frame operations retain their native instruction order until the
// C++ shadow update and command initialization reproduce the same schedule.
// Member offsets remain checked against HardwareCoreState in the header.
asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start EnableHardwareForcedBlank\n"
    "EnableHardwareForcedBlank:\n"
    "    push {r4, lr}\n"
    "    sub sp, #16\n"
    "    ldr r4, [r0]\n"
    "    adds r3, r4, #0\n"
    "    adds r3, #0x34\n"
    "    movs r2, #0\n"
    "    ldrh r0, [r4, #0x34]\n"
    "    movs r1, #" STRINGIFY(DISPCNT_FORCED_BLANK) "\n"
    "    orrs r0, r1\n"
    "    strh r0, [r4, #0x34]\n"
    "    str r2, [sp]\n"
    "    str r2, [sp, #4]\n"
    "    ldr r0, .LEnableForcedBlankCommandTable\n"
    "    str r0, [sp, #8]\n"
    "    str r3, [sp, #12]\n"
    "    movs r0, #0x92\n"
    "    lsls r0, r0, #3\n"
    "    adds r4, r4, r0\n"
    "    adds r0, r4, #0\n"
    "    bl GetHardwareManagerFrameCommands\n"
    "    ldr r1, [r0, #8]\n"
    "    ldr r2, [r1, #16]\n"
    "    mov r1, sp\n"
    "    bl _call_via_r2\n"
    "    adds r0, r4, #0\n"
    "    bl WaitForHardwareVBlank\n"
    "    mov r0, sp\n"
    "    movs r1, #2\n"
    "    bl func_080098AC\n"
    "    add sp, #16\n"
    "    pop {r4}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
    ".LEnableForcedBlankCommandTable: .word __vt_22HardwareDisplayCommand\n"
    "thumb_func_start DisableHardwareForcedBlank\n"
    "DisableHardwareForcedBlank:\n"
    "    push {r4, lr}\n"
    "    sub sp, #16\n"
    "    ldr r4, [r0]\n"
    "    adds r3, r4, #0\n"
    "    adds r3, #0x34\n"
    "    movs r2, #0\n"
    "    ldrh r1, [r4, #0x34]\n"
    "    ldr r0, .LDisableForcedBlankMask\n"
    "    ands r0, r1\n"
    "    strh r0, [r4, #0x34]\n"
    "    str r2, [sp]\n"
    "    str r2, [sp, #4]\n"
    "    ldr r0, .LDisableForcedBlankCommandTable\n"
    "    str r0, [sp, #8]\n"
    "    str r3, [sp, #12]\n"
    "    movs r0, #0x92\n"
    "    lsls r0, r0, #3\n"
    "    adds r4, r4, r0\n"
    "    adds r0, r4, #0\n"
    "    bl GetHardwareManagerFrameCommands\n"
    "    ldr r1, [r0, #8]\n"
    "    ldr r2, [r1, #16]\n"
    "    mov r1, sp\n"
    "    bl _call_via_r2\n"
    "    adds r0, r4, #0\n"
    "    bl WaitForHardwareVBlank\n"
    "    mov r0, sp\n"
    "    movs r1, #2\n"
    "    bl func_080098AC\n"
    "    add sp, #16\n"
    "    pop {r4}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
    ".LDisableForcedBlankMask: .word 0xFFFF & ~" STRINGIFY(DISPCNT_FORCED_BLANK) "\n"
    ".LDisableForcedBlankCommandTable: .word __vt_22HardwareDisplayCommand\n"
);

void UpdateHardwareFrame(struct HardwareContext * owner)
{
    struct HardwareCoreState * state = owner->state;
    HardwareDisplayCommand display(&state->display);
    HardwareSpriteBufferCommand sprite(&state->sprite_buffer);
    HardwareDmaQueueCommand dma(&state->dma_queue);
    HardwareLinkedList commands;

    func_08009940(&commands, &state->links);
    func_08009940(&commands, &display);
    func_08009940(&commands, &dma);
    func_08009940(&commands, &sprite);

    HardwareManagerOwner * manager = &state->manager;
    GetHardwareManagerFrameCommands(manager)->Append(&commands);
    WaitForHardwareVBlank(manager);
    GetHardwareManagerFrameCommands(manager)->Remove(&commands);

    // The list and commands unlink in reverse construction order at scope exit.
}

void UpdateHardwareInput(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    UpdateHardwareKeyRepeat(&state->input);
}

u32 GetHardwareHeldKeys(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return state->input.held;
}

u32 GetHardwarePressedKeys(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return state->input.pressed;
}

u32 GetHardwareRepeatedKeys(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return state->input.repeated;
}

struct HardwareCoreState * GetHardwareCoreState(void * const * state_slot)
{
    return static_cast<HardwareCoreState *>(*state_slot);
}

void SetHardwareRepeatDelay(void * const * state_slot, u16 value)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    SetHardwareKeyRepeatDelay(&state->input, value);
}

void SetHardwareRepeatInterval(void * const * state_slot, u16 value)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    SetHardwareKeyRepeatInterval(&state->input, value);
}

u16 GetHardwareRepeatDelay(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return state->input.repeat_delay;
}

u16 GetHardwareRepeatInterval(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return state->input.repeat_interval;
}

struct HardwareDmaQueue * GetHardwareDmaQueue(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return &state->dma_queue;
}

struct HardwareDisplayState * GetHardwareDisplayState(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return &state->display;
}

struct HardwareSpriteBufferState * GetHardwareSpriteBuffer(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return &state->sprite_buffer;
}

struct HardwareDmaQueue * func_08008928(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return &state->dma_queue;
}

struct HardwareDisplayState * func_08008930(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return &state->display;
}

struct HardwareSpriteBufferState * func_08008938(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return &state->sprite_buffer;
}

struct HardwareLinkedList * GetHardwareCommandList(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return &state->links;
}

struct HardwareInterruptList * GetHardwareInterruptList(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return GetHardwareManagerFrameCommands(&state->manager);
}

struct HardwareLinkedList * func_08008960(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return &state->links;
}

struct HardwareInterruptList * func_0800896C(void * const * state_slot)
{
    struct HardwareCoreState * state = static_cast<HardwareCoreState *>(*state_slot);
    return GetHardwareManagerFrameCommands(&state->manager);
}
