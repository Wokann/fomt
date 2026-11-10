#ifndef HARDWARE_MANAGER_HH
#define HARDWARE_MANAGER_HH

#include "prelude.h"
#include "hardware_vblank_binding.hh"
#include "hardware_sound.hh"
#include "interrupt.h"

// The binding is a secondary base at +0x1C, not a separately owned member.
// GCC emits its adjusted destructor entry and both group tables.
#ifdef __cplusplus
#pragma interface "hardware_manager.hh"
#endif
struct HardwareManagerCommandGroup
#ifdef __cplusplus
    : HardwareInterruptList, HardwareManagerVBlankBinding
#endif
{
#ifdef __cplusplus
    HardwareManagerCommandGroup()
        : HardwareManagerVBlankBinding(static_cast<HardwareLinkedList *>(this)) {}
    virtual ~HardwareManagerCommandGroup();
#else
    struct HardwareInterruptList commands;
    struct HardwareManagerVBlankBinding vblank;
#endif
};
#ifdef __cplusplus
#include "hardware_manager_lifetimes.hh"
#endif

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

EXTERN_C_END

#endif // HARDWARE_MANAGER_HH
