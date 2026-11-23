#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0158_LocationInteraction_InspectFishFoodStorageSign.mary.h"

void EventScript_0158_LocationInteraction_InspectFishFoodStorageSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectFishFoodStorageSign);
    TalkClose();
}
