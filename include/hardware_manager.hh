#ifndef HARDWARE_MANAGER_HH
#define HARDWARE_MANAGER_HH

#include "prelude.h"
#include "hardware_interrupt_guard.hh"
#include "hardware_sound.hh"
#include "interrupt.hh"
#ifdef __cplusplus
#include "hardware_song.hh"
#endif

struct HardwareManagerVBlankBinding;

EXTERN_C
extern struct HardwareManagerVBlankBinding * gCurrentHardwareVBlankBinding;
EXTERN_C_END

#ifdef __cplusplus
// Restore the binding that was active before this scoped registration.
struct HardwareManagerBindingRestore {
    HardwareManagerVBlankBinding * previous;

    explicit HardwareManagerBindingRestore(HardwareManagerVBlankBinding * binding)
    {
        HardwareManagerVBlankBinding * old = gCurrentHardwareVBlankBinding;
        gCurrentHardwareVBlankBinding = binding;
        previous = old;
    }

    virtual ~HardwareManagerBindingRestore()
    {
        gCurrentHardwareVBlankBinding = previous;
    }
};

struct HardwareManagerPreviousBinding : HardwareManagerBindingRestore {
    explicit HardwareManagerPreviousBinding(HardwareManagerVBlankBinding * binding)
        : HardwareManagerBindingRestore(binding) {}
};
#else
struct HardwareManagerPreviousBinding {
    struct HardwareManagerVBlankBinding * previous;
    HardwareLinkVirtualFunction const * vtable;
};
#endif

// Save the previous VBlank callback and enable bit while this manager owns
// IRQ slot zero. The halfword's following two bytes are natural padding.
#ifdef __cplusplus
// The native key destructor still needs this translation unit to own its table.
#pragma interface "hardware_manager.hh"
#endif
struct HardwareManagerVBlankBinding {
    struct HardwareLinkedList * commands;
#ifdef __cplusplus
    InterruptGuard guard;
#else
    u16 enabled;
#endif
    struct HardwareManagerPreviousBinding previous;
    InterruptHandler previous_handler;
#ifdef __cplusplus
    HardwareManagerVBlankBinding(HardwareLinkedList * const & list)
        SECTION(".text.hardware_manager_vblank_binding");
    // The real destructor entry remains native until its C++ body matches.
    virtual ~HardwareManagerVBlankBinding();
#else
    HardwareLinkVirtualFunction const * vtable;
#endif
};

#ifdef __cplusplus
#pragma implementation
#endif

// The binding is a secondary base at +0x1C, not a separately owned member.
// GCC emits its adjusted destructor entry and both group tables.
struct HardwareManagerCommandGroup
#ifdef __cplusplus
    : HardwareInterruptList, HardwareManagerVBlankBinding
#endif
{
#ifdef __cplusplus
    HardwareManagerCommandGroup()
        : HardwareManagerVBlankBinding(static_cast<HardwareLinkedList *>(this)) {}
#else
    struct HardwareInterruptList commands;
    struct HardwareManagerVBlankBinding vblank;
#endif
};

struct HardwareManagerState {
    struct HardwareSoundVSyncCommand sound_vsync;
    struct HardwareInterruptList frame_commands;
    struct HardwareSoundMainCommand sound_main;
    struct HardwareManagerCommandGroup command_group;
    u8 enabled_sound_vsync;
#ifdef __cplusplus
    HardwareManagerState()
    {
        u8 & enabled = enabled_sound_vsync;
        enabled = IsHardwareSoundDmaEnabled() ^ 1;
        if (enabled != 0)
            EnableHardwareSoundVSync();
        command_group.Append(&sound_vsync);
        command_group.Append(&frame_commands);
        command_group.Append(&sound_main);
    }

    ~HardwareManagerState()
    {
        if (enabled_sound_vsync != 0)
            DisableHardwareSoundVSync();
    }
#endif
};

struct HardwareManagerOwner {
    struct HardwareManagerState * state;
#ifdef __cplusplus
    HardwareManagerOwner();
    ~HardwareManagerOwner();
#endif
};

typedef char HardwareManagerPreviousBinding_size_check[
    sizeof(struct HardwareManagerPreviousBinding) == 8 ? 1 : -1];
typedef char HardwareManagerVBlankBinding_size_check[
    sizeof(struct HardwareManagerVBlankBinding) == 0x18 ? 1 : -1];
typedef char HardwareManagerVBlankBinding_previous_offset_check[
    offsetof(struct HardwareManagerVBlankBinding, previous) == 8 ? 1 : -1];
typedef char HardwareManagerVBlankBinding_handler_offset_check[
    offsetof(struct HardwareManagerVBlankBinding, previous_handler) == 0x10 ? 1 : -1];
typedef char HardwareManagerCommandGroup_size_check[
    sizeof(struct HardwareManagerCommandGroup) == 0x34 ? 1 : -1];
typedef char HardwareManagerState_size_check[sizeof(struct HardwareManagerState) == 0x6C ? 1 : -1];
typedef char HardwareManagerState_first_list_offset_check[
    offsetof(struct HardwareManagerState, frame_commands) == 0x0C ? 1 : -1];
typedef char HardwareManagerState_link_offset_check[
    offsetof(struct HardwareManagerState, sound_main) == 0x28 ? 1 : -1];
typedef char HardwareManagerState_group_offset_check[
    offsetof(struct HardwareManagerState, command_group) == 0x34 ? 1 : -1];
typedef char HardwareManagerState_flag_offset_check[
    offsetof(struct HardwareManagerState, enabled_sound_vsync) == 0x68 ? 1 : -1];
#ifndef __cplusplus
typedef char HardwareManagerVBlankBinding_vtable_offset_check[
    offsetof(struct HardwareManagerVBlankBinding, vtable) == 0x14 ? 1 : -1];
typedef char HardwareManagerCommandGroup_vblank_offset_check[
    offsetof(struct HardwareManagerCommandGroup, vblank) == 0x1C ? 1 : -1];
typedef char HardwareManagerState_vblank_offset_check[
    offsetof(struct HardwareManagerState, command_group) +
    offsetof(struct HardwareManagerCommandGroup, vblank) == 0x50 ? 1 : -1];
#endif

EXTERN_C

struct HardwareInterruptList * GetHardwareManagerFrameCommands(struct HardwareManagerOwner const * owner);
// Retail retains a second entry for this member view.
struct HardwareInterruptList * func_08008AE8(struct HardwareManagerOwner const * owner);

void RunHardwareManagerVBlankCommands(void) SECTION(".text.hardware_manager_vblank_binding");

// Distinct retained callbacks; these are not aliases to the earlier methods.
void AppendHardwareVBlankCommand(struct HardwareLinkedList * list, struct HardwareLinkBase * link)
    SECTION(".text.hardware_manager_vblank_append");
void RemoveHardwareVBlankCommand(struct HardwareLinkedList * list, struct HardwareLinkBase * link)
    SECTION(".text.hardware_manager_vblank_after");
void SpliceHardwareVBlankCommands(struct HardwareLinkedList * list, struct HardwareLinkedList * source)
    SECTION(".text.hardware_manager_vblank_after");
void SwapHardwareVBlankCommands(struct HardwareLinkedList * list, struct HardwareLinkedList * other)
    SECTION(".text.hardware_manager_vblank_after");
EXTERN_C_END

#endif // HARDWARE_MANAGER_HH
