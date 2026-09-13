#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemEvent_BasketFull[] =
        "The Basket is full.{Press}";
};

void EventScript_SystemEvent_BasketFull(void)
{
    TalkOpen();
    TalkMessage(gText_SystemEvent_BasketFull);
    TalkClose();
}
