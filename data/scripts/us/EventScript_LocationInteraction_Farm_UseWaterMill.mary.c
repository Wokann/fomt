#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationInteraction_Farm_UseWaterMill(void)
{
    if (IsPlayerRidingHorse())
    {
        return;
    }
    if (!IsPlayerHoldingNothing())
    {
        switch (GetPlayerHeldItemKind())
        {
            case HELD_ITEM_KIND_DOG:
            case HELD_ITEM_KIND_CHICKEN:
            case HELD_ITEM_KIND_BASKET:
                return;
            case HELD_ITEM_KIND_ARTICLE:
                if (!CanDiscardPlayerHeldArticle() || GetPlayerHeldArticleId() == ITEM_ARTICLE_STONES || GetPlayerHeldArticleId() == ITEM_ARTICLE_BALL)
                {
                    return;
                }
                break;
            case HELD_ITEM_KIND_FOOD:
                if (GetPlayerHeldFoodId() == ITEM_FOOD_CORN)
                {
                    if (IsPlayerHeldItemWrapped() == TRUE)
                    {
                        return;
                    }
                    else
                    {
                        UsePlayerHeldItem();
                        PlaySong(AUDIO_START, AUDIO_SFX_SHIPMENT_DEPOSIT);
                        WaitFrames(10);
                        VarSet(VAR_COOP_STORED_CHICKEN_FEED, VarGet(VAR_COOP_STORED_CHICKEN_FEED) + 30);
                        return;
                    }
                }
                break;
        }
        ThrowPlayerHeldItem();
    }
}
