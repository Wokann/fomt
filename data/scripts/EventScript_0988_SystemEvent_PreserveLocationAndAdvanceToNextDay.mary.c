#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay(void)
{
    FadeOutBGM();
#if defined(REGION_JP)
#ifdef BUGFIX
    // Save the actual bedtime before replacing the clock with 06:00.
    PreservePlayerLocationForNextDay();
    SetGameTime(6, 0);
#else
    SetGameTime(6, 0);
    PreservePlayerLocationForNextDay();
#endif
#else
    PreservePlayerLocationForNextDay();
    SetGameTime(6, 0);
#endif
    CallScript(EventScript_0980_SystemEvent_AdvanceToNextDay);
}
