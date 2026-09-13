#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBarnSouthPregnantAnimalFeedBox[] =
        "Pregnant animal Feed Box\r\n"
        "Put Feed for pregnant\r\n"
        "animals here.{Press}";
};

void EventScript_LocationInteraction_InspectBarnSouthPregnantAnimalFeedBox(void)
{
    int var_0;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped() && GetPlayerHeldArticleId() == ITEM_ARTICLE_ANIMAL_FODDER)
    {
        var_0 = TRUE;
    }
    if (var_0 && !IsBarnFeedTroughFilled(BARN_PREGNANCY_FEED_TROUGH_SOUTH))
    {
        UsePlayerHeldItem();
        FillBarnFeedTrough(BARN_PREGNANCY_FEED_TROUGH_SOUTH);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectBarnSouthPregnantAnimalFeedBox);
        TalkClose();
    }
}
