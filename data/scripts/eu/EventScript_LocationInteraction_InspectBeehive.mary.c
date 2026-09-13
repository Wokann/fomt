#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBeehive[] =
        "Bee Nest\r\n"
        "Check everyday to \r\n"
        "find some honey.{Press}";
};

void EventScript_LocationInteraction_InspectBeehive(void)
{
    if (!IsPlayerRidingHorse() && IsPlayerHoldingNothing() && VarGet(VAR_BEEHIVE_HONEY_AVAILABLE))
    {
        VarSet(VAR_BEEHIVE_HONEY_AVAILABLE, FALSE);
        SetPlayerHeldFood(ITEM_FOOD_HONEY);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectBeehive);
        TalkClose();
    }
}
