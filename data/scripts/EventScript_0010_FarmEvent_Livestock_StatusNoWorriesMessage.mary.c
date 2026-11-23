#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0010_FarmEvent_Livestock_StatusNoWorriesMessage.mary.h"

void EventScript_0010_FarmEvent_Livestock_StatusNoWorriesMessage(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Livestock_StatusNoWorriesMessage);
    TalkClose();
}
