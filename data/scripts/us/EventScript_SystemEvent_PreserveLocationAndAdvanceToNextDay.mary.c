#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay(void)
{
    FadeOutBGM();
    PreservePlayerLocationForNextDay();
    SetGameTime(6, 0);
    CallScript(EventScript_SystemEvent_AdvanceToNextDay);
}
