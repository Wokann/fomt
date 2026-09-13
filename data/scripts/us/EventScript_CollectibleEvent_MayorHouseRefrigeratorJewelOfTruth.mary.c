#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_AfterCollection[] =
        "Refrigerator{Press}";

    const char gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_JewelFound[] =
        "There's a Jewel of Truth\r\n"
        "fallen in the Refrigerator.{Press}";

    const char gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_InventoryFull[] =
        "There's a Jewel of Truth\r\n"
        "fallen in the Refrigerator.{Press}\p"
        "...But your hands are\r\n"
        "already full, so you \r\n"
        "can't hold it.{Press}";
};

void EventScript_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth(void)
{
    if (VarGet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT) == 8)
    {
        if (VarGet(VAR_JEWEL_OF_TRUTH_FROM_REFRIGERATOR_COLLECTED) == TRUE)
        {
            TalkOpen();
            TalkAppendMessage(gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_AfterCollection);
        }
        else
        {
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetPlayerHeldArticle(ITEM_ARTICLE_JEWEL_OF_TRUTH);
                TalkOpen();
                TalkMessage(gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_JewelFound);
                TalkClose();
                VarSet(VAR_JEWEL_OF_TRUTH_FROM_REFRIGERATOR_COLLECTED, TRUE);
                VarSet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT, VarGet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT) + 1);
                CallScript(EventScript_AchievementEvent_Collection_JewelsOfTruthExchange);
            }
            else
            {
                TalkOpen();
                TalkMessage(gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_InventoryFull);
            }
        }
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_AfterCollection);
    }
    TalkClose();
}
