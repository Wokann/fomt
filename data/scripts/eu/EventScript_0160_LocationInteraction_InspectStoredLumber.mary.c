#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0160_LocationInteraction_InspectStoredLumber.mary.h"

void EventScript_0160_LocationInteraction_InspectStoredLumber(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_STORED_LUMBER), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectStoredLumber_StockAmount);
    TalkClose();
}
