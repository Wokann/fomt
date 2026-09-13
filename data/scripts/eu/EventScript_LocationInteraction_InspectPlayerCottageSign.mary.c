#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectPlayerCottageSign_CottageSign[] =
        "{Player}'s Cottage\r\n"
        "{Press}";

    const char gText_LocationInteraction_InspectPlayerCottageSign_EmptyLotSign[] =
        "Empty Lot\r\n"
        "{Press}";
};

void EventScript_LocationInteraction_InspectPlayerCottageSign(void)
{
    TalkOpen();
    if (VarGet(VAR_HAS_TOWN_COTTAGE) == TRUE)
    {
        TalkAppendMessage(gText_LocationInteraction_InspectPlayerCottageSign_CottageSign);
    }
    else
    {
        TalkAppendMessage(gText_LocationInteraction_InspectPlayerCottageSign_EmptyLotSign);
    }
    TalkClose();
}
