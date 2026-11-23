#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0455_LocationInteraction_InspectBarnSouthRowSlot03FeedBox.mary.h"

void EventScript_0455_LocationInteraction_InspectBarnSouthRowSlot03FeedBox(void)
{
    int var_0;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped() && GetPlayerHeldArticleId() == ITEM_ARTICLE_ANIMAL_FODDER)
    {
        var_0 = TRUE;
    }
    if (var_0 && !IsBarnFeedTroughFilled(BARN_FEED_TROUGH_SOUTH_ROW_SLOT_03))
    {
        UsePlayerHeldItem();
        FillBarnFeedTrough(BARN_FEED_TROUGH_SOUTH_ROW_SLOT_03);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectBarnSouthRowSlot03FeedBox);
        TalkClose();
    }
}
