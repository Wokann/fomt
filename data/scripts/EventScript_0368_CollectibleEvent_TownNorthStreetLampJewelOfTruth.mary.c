#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0368_CollectibleEvent_TownNorthStreetLampJewelOfTruth.mary.h"

void EventScript_0368_CollectibleEvent_TownNorthStreetLampJewelOfTruth(void)
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
