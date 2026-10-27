#include "hardware_display_commands.hh"

#include "hardware_display_state.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_nested_accessors.hh"

// These C commands initialize the existing ABI view and clean it up explicitly.
void EnableHardwareForcedBlank(struct HardwareBootstrap * owner)
{
    struct HardwareCoreState * state = owner->state;
    u16 * control = (u16 *)&state->display.control;
    struct HardwareDisplayCommand command;
    u32 zero = 0;
    *control |= 0x80;
    command.previous_slot = (struct HardwareLink **)zero;
    command.next = (struct HardwareLink *)zero;
    command.vtable = &__vt_22HardwareDisplayCommand;
    command.display = &state->display;
    {
        struct HardwareManagerOwner * manager = &state->manager;
        struct HardwareLinkedList * list = &func_08008AE0(manager)->list;
        list->vtable->append(list, (struct HardwareLinkBase *)&command);
        func_08008AF0(manager);
    }
    func_080098AC(&command, 2);
}

void DisableHardwareForcedBlank(struct HardwareBootstrap * owner)
{
    struct HardwareCoreState * state = owner->state;
    u16 * control = (u16 *)&state->display.control;
    struct HardwareDisplayCommand command;
    u32 zero = 0;
    *control &= 0xFF7F;
    command.previous_slot = (struct HardwareLink **)zero;
    command.next = (struct HardwareLink *)zero;
    command.vtable = &__vt_22HardwareDisplayCommand;
    command.display = &state->display;
    {
        struct HardwareManagerOwner * manager = &state->manager;
        struct HardwareLinkedList * list = &func_08008AE0(manager)->list;
        list->vtable->append(list, (struct HardwareLinkBase *)&command);
        func_08008AF0(manager);
    }
    func_080098AC(&command, 2);
}
