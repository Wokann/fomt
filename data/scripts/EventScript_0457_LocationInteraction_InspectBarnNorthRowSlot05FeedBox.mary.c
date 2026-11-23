#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0457_LocationInteraction_InspectBarnNorthRowSlot05FeedBox.mary.h"

void EventScript_0457_LocationInteraction_InspectBarnNorthRowSlot05FeedBox(void)
{
    int var_0;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped() && GetPlayerHeldArticleId() == ITEM_ARTICLE_ANIMAL_FODDER)
    {
        var_0 = TRUE;
    }
    if (var_0 && !IsBarnFeedTroughFilled(BARN_FEED_TROUGH_NORTH_ROW_SLOT_05))
    {
        UsePlayerHeldItem();
        FillBarnFeedTrough(BARN_FEED_TROUGH_NORTH_ROW_SLOT_05);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectBarnNorthRowSlot05FeedBox);
        TalkClose();
    }
}
