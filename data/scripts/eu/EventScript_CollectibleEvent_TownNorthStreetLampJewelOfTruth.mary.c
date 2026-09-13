#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_CollectibleEvent_TownNorthStreetLampJewelOfTruth_AfterCollection[] =
        "Street lamp{Press}";

    const char gText_CollectibleEvent_TownNorthStreetLampJewelOfTruth_JewelFound[] =
        "A Jewel of Truth is fallen\r\n"
        "beneath the street lamp.{Press}";

    const char gText_CollectibleEvent_TownNorthStreetLampJewelOfTruth_InventoryFull[] =
        "Found a Jewel of Truth \r\n"
        "beneath the street lamp.{Press}\r\n"
        "...But my hands are\r\n"
        "already full, so I \r\n"
        "can't hold it.{Press}";
};

void EventScript_CollectibleEvent_TownNorthStreetLampJewelOfTruth(void)
{
    if (VarGet(VAR_JEWEL_OF_TRUTH_FROM_STREET_LAMP_COLLECTED) == TRUE)
    {
        TalkOpen();
        TalkAppendMessage(gText_CollectibleEvent_TownNorthStreetLampJewelOfTruth_AfterCollection);
    }
    else
    {
        if (VarGet(VAR_HAS_SHELF) == TRUE)
        {
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetPlayerHeldArticle(ITEM_ARTICLE_JEWEL_OF_TRUTH);
                TalkOpen();
                TalkMessage(gText_CollectibleEvent_TownNorthStreetLampJewelOfTruth_JewelFound);
                VarSet(VAR_JEWEL_OF_TRUTH_FROM_STREET_LAMP_COLLECTED, TRUE);
                VarSet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT, VarGet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT) + 1);
            }
            else
            {
                TalkOpen();
                TalkMessage(gText_CollectibleEvent_TownNorthStreetLampJewelOfTruth_InventoryFull);
            }
        }
        else
        {
            TalkOpen();
            TalkAppendMessage(gText_CollectibleEvent_TownNorthStreetLampJewelOfTruth_AfterCollection);
        }
    }
    TalkClose();
}
