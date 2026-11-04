#include "prelude.h"
#pragma implementation "hardware_manager.hh"
#include "hardware_manager.hh"
#include "gbaio.h"

void * operator new(unsigned long);
void operator delete(void *);

HardwareManagerVBlankBinding * gCurrentHardwareVBlankBinding;

HardwareManagerOwner::HardwareManagerOwner()
    : state(new HardwareManagerState)
{
}

HardwareManagerOwner::~HardwareManagerOwner()
{
    delete state;
}

void RunHardwareManagerVBlankCommands(void)
{
    HardwareLinkedList * commands = gCurrentHardwareVBlankBinding->commands;
    commands->Run();
}

HardwareManagerVBlankBinding::HardwareManagerVBlankBinding(HardwareLinkedList * const & list)
    : commands(list), guard(INTR_FLAG_VBLANK), previous(this),
      previous_handler(ExchangeInterruptHandler(0, RunHardwareManagerVBlankCommands))
{
    AcknowledgeAndEnableInterrupts(INTR_FLAG_VBLANK);
}

void AppendHardwareVBlankCommand(HardwareLinkedList * list, HardwareLinkBase * link)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    list->HardwareLinkedList::Append(link);
}

void RemoveHardwareVBlankCommand(HardwareLinkedList * list, HardwareLinkBase * link)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    list->HardwareLinkedList::Remove(link);
}

void SpliceHardwareVBlankCommands(HardwareLinkedList * list, HardwareLinkedList * source)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    list->HardwareLinkedList::Splice(source);
}

void SwapHardwareVBlankCommands(HardwareLinkedList * list, HardwareLinkedList * other)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    list->HardwareLinkedList::Swap(other);
}
