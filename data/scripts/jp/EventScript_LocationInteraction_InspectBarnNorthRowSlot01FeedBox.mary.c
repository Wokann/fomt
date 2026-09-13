#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBarnNorthRowSlot01FeedBox[] =
        "エサ箱{Press}";
};

void EventScript_LocationInteraction_InspectBarnNorthRowSlot01FeedBox(void)
{
    int var_0;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped() && GetPlayerHeldArticleId() == ITEM_ARTICLE_ANIMAL_FODDER)
    {
        var_0 = TRUE;
    }
    if (var_0 && !IsBarnFeedTroughFilled(BARN_FEED_TROUGH_NORTH_ROW_SLOT_01))
    {
        UsePlayerHeldItem();
        FillBarnFeedTrough(BARN_FEED_TROUGH_NORTH_ROW_SLOT_01);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectBarnNorthRowSlot01FeedBox);
        TalkClose();
    }
}
