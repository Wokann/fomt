#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemEvent_BasketFull[] =
        "カゴがいっぱいだ…{Press}";
};

void EventScript_SystemEvent_BasketFull(void)
{
    TalkOpen();
    TalkMessage(gText_SystemEvent_BasketFull);
    TalkClose();
}
