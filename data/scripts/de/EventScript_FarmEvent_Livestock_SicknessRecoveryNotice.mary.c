#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Livestock_SicknessRecoveryNotice[] =
        "Die Krankheit ist vorbei!{Press}";
};

void EventScript_FarmEvent_Livestock_SicknessRecoveryNotice(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Livestock_SicknessRecoveryNotice);
    TalkClose();
}
