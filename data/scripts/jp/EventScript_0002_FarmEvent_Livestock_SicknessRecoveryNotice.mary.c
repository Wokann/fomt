#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0002_FarmEvent_Livestock_SicknessRecoveryNotice.mary.h"

void EventScript_0002_FarmEvent_Livestock_SicknessRecoveryNotice(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Livestock_SicknessRecoveryNotice);
    TalkClose();
}
