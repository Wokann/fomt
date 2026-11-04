#include "hardware_display_commands.hh"
#include "gbaio.h"

#include "hardware_display_state.hh"
#include "hardware_context.hh"
#include "hardware_state_accessors.hh"
#include "hardware_manager.hh"

// These C commands initialize the existing ABI view and clean it up explicitly.
void EnableHardwareForcedBlank(struct HardwareContext * owner)
{
    struct HardwareCoreState * state = owner->state;
    u16 * control = (u16 *)&state->display.control;
    struct HardwareDisplayCommand command;
    u32 zero = 0;
    *control |= DISPCNT_FORCED_BLANK;
    command.previous_slot = (struct HardwareLink **)zero;
    command.next = (struct HardwareLink *)zero;
    command.vtable = &__vt_22HardwareDisplayCommand;
    command.display = &state->display;
    {
        struct HardwareManagerOwner * manager = &state->manager;
        struct HardwareLinkedList * list = &GetHardwareManagerFrameCommands(manager)->list;
        list->vtable->append(list, (struct HardwareLinkBase *)&command);
        WaitForHardwareVBlank(manager);
    }
    func_080098AC(&command, 2);
}

void DisableHardwareForcedBlank(struct HardwareContext * owner)
{
    struct HardwareCoreState * state = owner->state;
    u16 * control = (u16 *)&state->display.control;
    struct HardwareDisplayCommand command;
    u32 zero = 0;
    *control &= (u16)~DISPCNT_FORCED_BLANK;
    command.previous_slot = (struct HardwareLink **)zero;
    command.next = (struct HardwareLink *)zero;
    command.vtable = &__vt_22HardwareDisplayCommand;
    command.display = &state->display;
    {
        struct HardwareManagerOwner * manager = &state->manager;
        struct HardwareLinkedList * list = &GetHardwareManagerFrameCommands(manager)->list;
        list->vtable->append(list, (struct HardwareLinkBase *)&command);
        WaitForHardwareVBlank(manager);
    }
    func_080098AC(&command, 2);
}
