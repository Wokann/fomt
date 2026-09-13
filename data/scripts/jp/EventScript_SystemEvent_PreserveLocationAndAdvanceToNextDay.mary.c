#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay(void)
{
    FadeOutBGM();
    SetGameTime(6, 0);
    PreservePlayerLocationForNextDay();
    CallScript(EventScript_SystemEvent_AdvanceToNextDay);
}
