#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectFarmFodderStorageAmount[] =
        "飼い葉の数\r\n"
        "　\r\n"
        "　　　　　　　　　　{Var1}コ{Press}";
};

void EventScript_LocationInteraction_InspectFarmFodderStorageAmount(void)
{
    TalkOpen();
    SetTextVariableNumberFieldWidth(TEXT_VARIABLE_1, VarGet(VAR_BARN_STORED_FODDER), 3);
    TalkAppendMessage(gText_LocationInteraction_InspectFarmFodderStorageAmount);
    TalkClose();
}
