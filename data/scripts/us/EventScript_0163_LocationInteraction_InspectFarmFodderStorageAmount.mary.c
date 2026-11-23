#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0163_LocationInteraction_InspectFarmFodderStorageAmount.mary.h"

void EventScript_0163_LocationInteraction_InspectFarmFodderStorageAmount(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_BARN_STORED_FODDER), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectFarmFodderStorageAmount);
    TalkClose();
}
