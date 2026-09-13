#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectStoredLumber_StockAmount[] =
        "資材の数\r\n"
        "　\r\n"
        "　　　　　　　　　　{Var1}本{Press}";
};

void EventScript_LocationInteraction_InspectStoredLumber(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_STORED_LUMBER), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectStoredLumber_StockAmount);
    TalkClose();
}
