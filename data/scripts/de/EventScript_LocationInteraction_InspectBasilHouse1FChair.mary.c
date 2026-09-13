#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBasilHouse1FChair[] =
        "Stuhl{Press}";
};

void EventScript_LocationInteraction_InspectBasilHouse1FChair(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectBasilHouse1FChair);
    TalkClose();
}
