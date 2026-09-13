#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Livestock_StatusNoWorriesMessage[] =
        "You seem like you don't\r\n"
        "have any worries.{Press}";
};

void EventScript_FarmEvent_Livestock_StatusNoWorriesMessage(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Livestock_StatusNoWorriesMessage);
    TalkClose();
}
