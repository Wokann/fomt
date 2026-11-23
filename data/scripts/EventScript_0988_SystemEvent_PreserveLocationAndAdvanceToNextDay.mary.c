#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay(void)
{
    FadeOutBGM();
#if defined(BUGFIX) || defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    // Save the actual bedtime before replacing the clock with 06:00.
    PreservePlayerLocationForNextDay();
    SetGameTime(6, 0);
#elif defined(REGION_JP)
    SetGameTime(6, 0);
    PreservePlayerLocationForNextDay();
#endif
    CallScript(EventScript_0980_SystemEvent_AdvanceToNextDay);
}
