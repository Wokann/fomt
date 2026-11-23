#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0461_LocationInteraction_InspectBarnStoredFodderAmount.mary.h"

void EventScript_0461_LocationInteraction_InspectBarnStoredFodderAmount(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_BARN_STORED_FODDER), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectBarnStoredFodderAmount);
    TalkClose();
}
