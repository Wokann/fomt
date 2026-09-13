#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectEmptyLumberStorage_Label[] =
        "Woodbin{Press}";

    const char gText_LocationInteraction_InspectEmptyLumberStorage_TheresNoLumberInTheWoodbin[] =
        "There's no Lumber\r\n"
        "in the Woodbin.{Press}";
};

void EventScript_LocationInteraction_InspectEmptyLumberStorage(void)
{
    int var_0;
    var_0 = VarGet(VAR_STORED_LUMBER);
    if (IsPlayerRidingHorse())
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectEmptyLumberStorage_Label);
        TalkClose();
        return;
    }
    if (IsPlayerHoldingNothing())
    {
        if (var_0 == 0)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectEmptyLumberStorage_TheresNoLumberInTheWoodbin);
            TalkClose();
        }
        else
        {
            SetPlayerHeldArticle(ITEM_ARTICLE_LUMBER);
            VarSet(VAR_STORED_LUMBER, var_0 - 1);
        }
    }
    else
    {
        if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && GetPlayerHeldArticleId() == ITEM_ARTICLE_LUMBER)
        {
            if (IsPlayerHeldItemWrapped() == TRUE)
            {
                return;
            }
            else
            {
                UsePlayerHeldItem();
                VarSet(VAR_STORED_LUMBER, var_0 + 1);
            }
        }
        else
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectEmptyLumberStorage_Label);
            TalkClose();
        }
    }
}
