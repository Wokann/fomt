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

// This native subobject's full class hierarchy is not yet recovered.
struct HardwareManagerPreviousBinding {
    struct HardwareManagerVBlankBinding * previous;
    HardwareLinkVirtualFunction const * vtable;
};

// Save the previous VBlank callback and enable bit while this manager owns
// IRQ slot zero. The halfword's following two bytes are natural padding.
#ifdef __cplusplus
// Its virtual destructor is defined in native assembly, so explicitly own
// this class's table here rather than relying on C++ key-function inference.
#pragma interface "hardware_manager.hh"
#endif
struct HardwareManagerVBlankBinding {
    struct HardwareLinkedList * commands;
    u16 enabled;
    struct HardwareManagerPreviousBinding previous;
    InterruptHandler previous_handler;
#ifdef __cplusplus
    HardwareManagerVBlankBinding(HardwareLinkedList * const & list)
        asm("func_080D78F8") SECTION(".text.hardware_manager_vblank_binding");
    // This virtual destructor's body is still the original Thumb assembly.
    virtual ~HardwareManagerVBlankBinding() asm("func_080D7944");
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
    struct HardwareSoundVSyncCommand unk_00;
    struct HardwareInterruptList unk_0C;
    struct HardwareSoundMainCommand unk_28;
    struct HardwareManagerCommandGroup command_group;
    u8 unk_68;
#ifdef __cplusplus
    HardwareManagerState()
    {
        u8 & enabled = unk_68;
        enabled = func_08008D9C() ^ 1;
        if (enabled != 0)
            func_08008D84();
        command_group.Append(&unk_00);
        command_group.Append(&unk_0C);
        command_group.Append(&unk_28);
    }

    ~HardwareManagerState()
    {
        if (unk_68 != 0)
            func_08008D90();
    }
#endif
};

struct HardwareManagerOwner {
    struct HardwareManagerState * state;
#ifdef __cplusplus
    HardwareManagerOwner() asm("func_08008980");
    ~HardwareManagerOwner() asm("func_08008A68");
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
    offsetof(struct HardwareManagerState, unk_0C) == 0x0C ? 1 : -1];
typedef char HardwareManagerState_link_offset_check[
    offsetof(struct HardwareManagerState, unk_28) == 0x28 ? 1 : -1];
typedef char HardwareManagerState_group_offset_check[
    offsetof(struct HardwareManagerState, command_group) == 0x34 ? 1 : -1];
typedef char HardwareManagerState_flag_offset_check[
    offsetof(struct HardwareManagerState, unk_68) == 0x68 ? 1 : -1];
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

extern struct HardwareManagerVBlankBinding * gUnk_03000410;
extern HardwareLinkVirtualFunction const vtable_unk_080E5B48[];
extern HardwareLinkVirtualFunction const vtable_unk_080E5B54[];

struct HardwareManagerOwner * func_08008980(struct HardwareManagerOwner * owner);
void func_08008A68(struct HardwareManagerOwner * owner, u32 flags);
void func_080D78E0(void) SECTION(".text.hardware_manager_vblank_binding");
struct HardwareManagerVBlankBinding * func_080D78F8(
    struct HardwareManagerVBlankBinding * binding, struct HardwareLinkedList * const * list);
void func_080D7944(struct HardwareManagerVBlankBinding * binding, u32 flags);

// Distinct retained callbacks; these are not aliases to the earlier methods.
void func_080D7990(struct HardwareLinkedList * list, struct HardwareLinkBase * link)
    SECTION(".text.hardware_manager_vblank_append");
void func_080D79F8(struct HardwareLinkedList * list, struct HardwareLinkBase * link)
    SECTION(".text.hardware_manager_vblank_after");
void func_080D7A34(struct HardwareLinkedList * list, struct HardwareLinkedList * source)
    SECTION(".text.hardware_manager_vblank_after");
void func_080D7A70(struct HardwareLinkedList * list, struct HardwareLinkedList * other)
    SECTION(".text.hardware_manager_vblank_after");
void func_080D7AAC(struct HardwareManagerPreviousBinding * binding, u32 flags)
    SECTION(".text.hardware_manager_binding_cleanup");
void func_080D7B04(struct HardwareManagerPreviousBinding * binding, u32 flags)
    SECTION(".text.hardware_manager_cleanup_after");

EXTERN_C_END

#endif // HARDWARE_MANAGER_HH
