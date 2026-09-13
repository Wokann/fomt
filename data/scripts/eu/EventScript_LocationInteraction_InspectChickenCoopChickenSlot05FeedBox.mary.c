#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChickenCoopChickenSlot05FeedBox[] =
        "Feed Box{Press}";
};

void EventScript_LocationInteraction_InspectChickenCoopChickenSlot05FeedBox(void)
{
    int var_0;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped() && GetPlayerHeldArticleId() == ITEM_ARTICLE_CHICKEN_FEED)
    {
        var_0 = TRUE;
    }
    if (var_0 && !IsChickenFeedTroughFilled(CHICKEN_COOP_FEED_TROUGH_SLOT_05))
    {
        UsePlayerHeldItem();
        FillChickenFeedTrough(CHICKEN_COOP_FEED_TROUGH_SLOT_05);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectChickenCoopChickenSlot05FeedBox);
        TalkClose();
    }
}
