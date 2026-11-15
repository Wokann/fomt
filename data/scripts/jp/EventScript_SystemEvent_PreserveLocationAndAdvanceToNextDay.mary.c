#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay(void)
{
    FadeOutBGM();
#ifdef BUGFIX
    // Save the actual bedtime before replacing the clock with 06:00.
    PreservePlayerLocationForNextDay();
    SetGameTime(6, 0);
#else
    SetGameTime(6, 0);
    PreservePlayerLocationForNextDay();
#endif
    CallScript(EventScript_SystemEvent_AdvanceToNextDay);
}
