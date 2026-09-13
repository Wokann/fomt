#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectParasol[] =
        "Parasol{Press}";
};

void EventScript_LocationInteraction_InspectParasol(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectParasol);
    TalkClose();
}
