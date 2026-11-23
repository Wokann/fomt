#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0506_LocationInteraction_InspectPoultryFarmYodelFarmForest.mary.h"

void EventScript_0506_LocationInteraction_InspectPoultryFarmYodelFarmForest(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectPoultryFarmYodelFarmForest);
    TalkClose();
}
