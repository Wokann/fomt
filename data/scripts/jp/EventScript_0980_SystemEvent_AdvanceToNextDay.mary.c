#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_0980_SystemEvent_AdvanceToNextDay(void)
{
    CallScript(EventScript_0982_SystemEvent_ResetDailyWorldState);
}
