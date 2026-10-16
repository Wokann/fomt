#ifndef HARDWARE_MANAGER_HH
#define HARDWARE_MANAGER_HH

#include "prelude.h"
#include "hardware_linked_list.hh"
#include "interrupt.hh"

struct HardwareManagerVBlankBinding;

// The eight-byte subobject restores the previous binding when destroyed.
// Its original table is separate from the enclosing binding's table.
struct HardwareManagerPreviousBinding {
    struct HardwareManagerVBlankBinding * previous;
    HardwareLinkVirtualFunction const * vtable;
};

// Save the previous VBlank callback and enable bit while this manager owns
// IRQ slot zero. The halfword's following two bytes are natural padding.
struct HardwareManagerVBlankBinding {
    struct HardwareLinkedList * commands;
    u16 enabled;
    struct HardwareManagerPreviousBinding previous;
    InterruptHandler previous_handler;
    HardwareLinkVirtualFunction const * vtable;
#ifdef __cplusplus
    HardwareManagerVBlankBinding(HardwareLinkedList * const & list)
        asm("func_080D78F8") SECTION(".text.hardware_manager_vblank_binding");
    // Native cleanup also restores the previous callback and IRQ enable bit.
    ~HardwareManagerVBlankBinding() asm("func_080D7944");
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
typedef char HardwareManagerVBlankBinding_vtable_offset_check[
    offsetof(struct HardwareManagerVBlankBinding, vtable) == 0x14 ? 1 : -1];

// The manager's second list is immediately followed by its VBlank binding.
// Keep this verified storage composition without guessing C++ inheritance.
struct HardwareManagerCommandGroup {
    struct HardwareLinkedList commands;
    struct HardwareManagerVBlankBinding vblank;
};

typedef char HardwareManagerCommandGroup_size_check[
    sizeof(struct HardwareManagerCommandGroup) == 0x34 ? 1 : -1];
typedef char HardwareManagerCommandGroup_vblank_offset_check[
    offsetof(struct HardwareManagerCommandGroup, vblank) == 0x1C ? 1 : -1];

// The constructor allocates 0x6C bytes. The earlier nodes and lists still
// need their full types established; the second command group is at +0x34.
struct HardwareManagerState {
    u8 unk_00[0x34];
    struct HardwareManagerCommandGroup command_group;
    u8 unk_68;
    u8 unk_69[3];
};

typedef char HardwareManagerState_size_check[sizeof(struct HardwareManagerState) == 0x6C ? 1 : -1];
typedef char HardwareManagerState_vblank_offset_check[
    offsetof(struct HardwareManagerState, command_group) +
    offsetof(struct HardwareManagerCommandGroup, vblank) == 0x50 ? 1 : -1];

struct HardwareManagerOwner {
    struct HardwareManagerState * state;
#ifdef __cplusplus
    HardwareManagerOwner() asm("func_08008980");
    ~HardwareManagerOwner() asm("func_08008A68");
#endif
};

EXTERN_C

extern struct HardwareManagerVBlankBinding * gUnk_03000410;

struct HardwareManagerOwner * func_08008980(struct HardwareManagerOwner * owner);
void func_08008A68(struct HardwareManagerOwner * owner, u32 flags);
void func_080D78E0(void) SECTION(".text.hardware_manager_vblank_binding");
struct HardwareManagerVBlankBinding * func_080D78F8(
    struct HardwareManagerVBlankBinding * binding, struct HardwareLinkedList * const * list);
// This original destructor entry remains explicit Thumb assembly.
void func_080D7944(struct HardwareManagerVBlankBinding * binding, u32 flags);
// The original base and derived tables retain distinct cleanup entries.
void func_080D7AAC(struct HardwareManagerPreviousBinding * binding, u32 flags)
    SECTION(".text.hardware_manager_binding_cleanup");
void func_080D7AD4(struct HardwareManagerCommandGroup * group, u32 flags)
    SECTION(".text.hardware_manager_binding_cleanup");
void func_080D7B04(struct HardwareManagerPreviousBinding * binding, u32 flags)
    SECTION(".text.hardware_manager_binding_cleanup");

EXTERN_C_END

#endif // HARDWARE_MANAGER_HH
