#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_AfterCollection[] =
        "Kühlschrank{Press}";

    const char gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_JewelFound[] =
        "Ein Juwel der Wahrheit ist\r\n"
        "in den Kühlschrank gefallen.{Press}";

    const char gText_CollectibleEvent_MayorHouseRefrigeratorJewelOfTruth_InventoryFull[] =
        "Ein Juwel der Wahrheit ist\r\n"
        "in den Kühlschrank gefallen.{Press}\p"
        "...Aber deine Hände sind\r\n"
        "schon voll, also kannst du \r\n"
        "es nicht halten.{Press}";
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
