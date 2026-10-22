#include "prelude.h"
#pragma implementation "hardware_manager.hh"
#include "hardware_manager.hh"

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
    : commands(list), guard(1), previous(this),
      previous_handler(ExchangeInterruptHandler(0, RunHardwareManagerVBlankCommands))
{
    AcknowledgeAndEnableInterrupts(1);
}

void AppendHardwareVBlankCommand(HardwareLinkedList * list, HardwareLinkBase * link)
{
    InterruptGuard guard(1);
    list->HardwareLinkedList::Append(link);
}

void RemoveHardwareVBlankCommand(HardwareLinkedList * list, HardwareLinkBase * link)
{
    InterruptGuard guard(1);
    list->HardwareLinkedList::Remove(link);
}

void SpliceHardwareVBlankCommands(HardwareLinkedList * list, HardwareLinkedList * source)
{
    InterruptGuard guard(1);
    list->HardwareLinkedList::Splice(source);
}

void SwapHardwareVBlankCommands(HardwareLinkedList * list, HardwareLinkedList * other)
{
    InterruptGuard guard(1);
    list->HardwareLinkedList::Swap(other);
}
