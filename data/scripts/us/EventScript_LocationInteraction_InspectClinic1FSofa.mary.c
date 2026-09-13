#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectClinic1FSofa_InspectionLabel[] =
        "Sopha{Press}";
};

void EventScript_LocationInteraction_InspectClinic1FSofa(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic1FSofa_InspectionLabel);
    TalkClose();
}
