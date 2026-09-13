#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Livestock_SicknessRecoveryNotice[] =
        "The sickness is gone!{Press}";
};

void EventScript_FarmEvent_Livestock_SicknessRecoveryNotice(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Livestock_SicknessRecoveryNotice);
    TalkClose();
}
