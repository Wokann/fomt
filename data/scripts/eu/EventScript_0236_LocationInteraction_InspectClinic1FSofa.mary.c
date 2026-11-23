#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectClinic1FSofa_InspectionLabel[] =
// Use Sofa, as in the other sofa inspection messages.
#ifdef BUGFIX
        "Sofa{Press}";
#else
        "Sopha{Press}";
#endif
};

void EventScript_0236_LocationInteraction_InspectClinic1FSofa(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic1FSofa_InspectionLabel);
    TalkClose();
}
