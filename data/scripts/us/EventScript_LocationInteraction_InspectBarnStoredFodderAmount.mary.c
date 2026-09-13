#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBarnStoredFodderAmount[] =
        "Amount of Animal Fodder\r\n"
        "　\r\n"
        "　　　　　　　{Var1}bushels{Press}";
};

void EventScript_LocationInteraction_InspectBarnStoredFodderAmount(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_BARN_STORED_FODDER), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectBarnStoredFodderAmount);
    TalkClose();
}
