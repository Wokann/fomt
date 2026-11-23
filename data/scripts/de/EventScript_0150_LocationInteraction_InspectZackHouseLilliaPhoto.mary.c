#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0150_LocationInteraction_InspectZackHouseLilliaPhoto.mary.h"

void EventScript_0150_LocationInteraction_InspectZackHouseLilliaPhoto(void)
{
    TalkOpen();
    if (HasMetNpc(CHARACTER_LILLIA) == FALSE)
    {
        TalkAppendMessage(gText_LocationInteraction_InspectZackHouseLilliaPhoto_UnidentifiedBeforeMeetingLillia);
    }
    else
    {
        TalkAppendMessage(gText_LocationInteraction_InspectZackHouseLilliaPhoto_IdentifiesLilliaAfterMeeting);
    }
    TalkClose();
}
