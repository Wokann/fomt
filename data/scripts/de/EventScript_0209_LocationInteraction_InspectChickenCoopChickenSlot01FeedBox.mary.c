#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0209_LocationInteraction_InspectChickenCoopChickenSlot01FeedBox.mary.h"

void EventScript_0209_LocationInteraction_InspectChickenCoopChickenSlot01FeedBox(void)
{
    int var_0;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped() && GetPlayerHeldArticleId() == ITEM_ARTICLE_CHICKEN_FEED)
    {
        var_0 = TRUE;
    }
    if (var_0 && !IsChickenFeedTroughFilled(CHICKEN_COOP_FEED_TROUGH_SLOT_01))
    {
        UsePlayerHeldItem();
        FillChickenFeedTrough(CHICKEN_COOP_FEED_TROUGH_SLOT_01);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectChickenCoopChickenSlot01FeedBox);
        TalkClose();
    }
}
