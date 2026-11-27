#ifndef HARDWARE_VBLANK_BINDING_HH
#define HARDWARE_VBLANK_BINDING_HH

#include "prelude.h"
#include "hardware_interrupt_guard.hh"
#include "interrupt.h"

struct HardwareManagerVBlankBinding;

EXTERN_C
extern struct HardwareManagerVBlankBinding * gCurrentHardwareVBlankBinding;
EXTERN_C_END

#ifdef __cplusplus
// Restore the binding that was active before this scoped registration.
#pragma interface "hardware_vblank_binding.hh"
struct HardwareManagerBindingRestore {
    HardwareManagerVBlankBinding * previous;

    explicit HardwareManagerBindingRestore(HardwareManagerVBlankBinding * binding)
    {
        HardwareManagerVBlankBinding * old = gCurrentHardwareVBlankBinding;
        gCurrentHardwareVBlankBinding = binding;
        previous = old;
    }

#pragma interface "hardware_manager_lifetimes.hh"
    virtual ~HardwareManagerBindingRestore();
#pragma interface "hardware_vblank_binding.hh"
};

struct HardwareManagerPreviousBinding : HardwareManagerBindingRestore {
    explicit HardwareManagerPreviousBinding(HardwareManagerVBlankBinding * binding)
        : HardwareManagerBindingRestore(binding) {}
#pragma interface "hardware_manager_lifetimes.hh"
    virtual ~HardwareManagerPreviousBinding();
#pragma interface "hardware_vblank_binding.hh"
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
// The manager owns this table together with its primary and secondary base
// tables; the binding methods retain their separate physical code range.
#pragma interface "hardware_vblank_binding.hh"
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
    HardwareManagerVBlankBinding(HardwareLinkedList * const & list);
    // The real destructor entry remains native until its C++ body matches.
    virtual ~HardwareManagerVBlankBinding();
#else
    HardwareLinkVirtualFunction const * vtable;
#endif
};

#ifdef __cplusplus
#endif

#ifndef __cplusplus
#endif

EXTERN_C
// These retained cleanup entries precede the binding in the retail image.
void func_080D788C(struct HardwareLinkedList * list);
void func_080D78BC(struct HardwareLinkedList * list, u32 flags);
void RunHardwareManagerVBlankCommands(void);
void AppendHardwareVBlankCommand(struct HardwareLinkedList * list, struct HardwareLinkBase * link);
EXTERN_C_END

#endif // HARDWARE_VBLANK_BINDING_HH
