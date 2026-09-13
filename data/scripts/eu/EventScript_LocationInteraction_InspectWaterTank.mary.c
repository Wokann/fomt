#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWaterTank_Label[] =
        "Water Tank{Press}";

    const char gText_LocationInteraction_InspectWaterTank_JewelOfTruthFound[] =
        "Inside the water tank is\r\n"
        "a Jewel of Truth.{Press}";

    const char gText_LocationInteraction_InspectWaterTank_JewelOfTruthFoundButHandsFull[] =
        "Inside the water tank is\r\n"
        "a Jewel of Truth.{Press}\p"
        "...But, your hands are full,\r\n"
        "so you can't hold it.{Press}";
};

void EventScript_LocationInteraction_InspectWaterTank(void)
{
    if (IsPlayerRidingHorse())
    {
        return;
    }
    if (VarGet(VAR_JEWEL_OF_TRUTH_FROM_WATER_TANK_COLLECTED) == TRUE)
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectWaterTank_Label);
    }
    else
    {
        if (VarGet(VAR_HAS_SHELF) == TRUE)
        {
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetPlayerHeldArticle(ITEM_ARTICLE_JEWEL_OF_TRUTH);
                TalkOpen();
                TalkMessage(gText_LocationInteraction_InspectWaterTank_JewelOfTruthFound);
                VarSet(VAR_JEWEL_OF_TRUTH_FROM_WATER_TANK_COLLECTED, TRUE);
                VarSet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT, VarGet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT) + 1);
            }
            else
            {
                TalkOpen();
                TalkMessage(gText_LocationInteraction_InspectWaterTank_JewelOfTruthFoundButHandsFull);
            }
        }
        else
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectWaterTank_Label);
        }
    }
    TalkClose();
}
