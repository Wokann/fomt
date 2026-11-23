#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay(void)
{
    FadeOutBGM();
    PreservePlayerLocationForNextDay();
    SetGameTime(6, 0);
    CallScript(EventScript_0980_SystemEvent_AdvanceToNextDay);
}
