#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0221_LocationInteraction_InspectChickenFeedStockpile.mary.h"

void EventScript_0221_LocationInteraction_InspectChickenFeedStockpile(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_COOP_STORED_CHICKEN_FEED), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectChickenFeedStockpile_StockAmount);
    TalkClose();
}
