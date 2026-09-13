#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChickenFeedStockpile_StockAmount[] =
        "Menge an Hühnerfutter\r\n"
        " \r\n"
        "       {Var1} Einheiten{Press}";
};

void EventScript_LocationInteraction_InspectChickenFeedStockpile(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_COOP_STORED_CHICKEN_FEED), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectChickenFeedStockpile_StockAmount);
    TalkClose();
}
