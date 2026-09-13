#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChickenFeedStockpile_StockAmount[] =
        "鶏のエサの数\r\n"
        "　\r\n"
        "　　　　　　　　　　{Var1}コ{Press}";
};

void EventScript_LocationInteraction_InspectChickenFeedStockpile(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_COOP_STORED_CHICKEN_FEED), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectChickenFeedStockpile_StockAmount);
    TalkClose();
}
