#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChickenCoopFeedStorageEmptyNotice[] =
        "Es ist kein Futter im\r\n"
        "Hühnerfutterlager.{Press}";
};

void EventScript_LocationInteraction_InspectChickenCoopFeedStorageEmptyNotice(void)
{
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped() && GetPlayerHeldArticleId() == ITEM_ARTICLE_CHICKEN_FEED)
    {
        UsePlayerHeldItem();
        VarSet(VAR_COOP_STORED_CHICKEN_FEED, VarGet(VAR_COOP_STORED_CHICKEN_FEED) + 1);
    }
    else
    {
        if (VarGet(VAR_COOP_STORED_CHICKEN_FEED) == 0)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectChickenCoopFeedStorageEmptyNotice);
            TalkClose();
        }
        else
        {
            SetPlayerHeldArticle(ITEM_ARTICLE_CHICKEN_FEED);
            VarSet(VAR_COOP_STORED_CHICKEN_FEED, VarGet(VAR_COOP_STORED_CHICKEN_FEED) - 1);
        }
    }
}
