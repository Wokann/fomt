#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBarnFeedStorageEmptyNotice[] =
        "サイロの中に\r\n"
        "１コも飼い葉が入っていない。{Press}";
};

void EventScript_LocationInteraction_InspectBarnFeedStorageEmptyNotice(void)
{
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped() && GetPlayerHeldArticleId() == ITEM_ARTICLE_ANIMAL_FODDER)
    {
        UsePlayerHeldItem();
        VarSet(VAR_BARN_STORED_FODDER, VarGet(VAR_BARN_STORED_FODDER) + 1);
    }
    else
    {
        if (VarGet(VAR_BARN_STORED_FODDER) == 0)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectBarnFeedStorageEmptyNotice);
            TalkClose();
        }
        else
        {
            SetPlayerHeldArticle(ITEM_ARTICLE_ANIMAL_FODDER);
            VarSet(VAR_BARN_STORED_FODDER, VarGet(VAR_BARN_STORED_FODDER) - 1);
        }
    }
}
