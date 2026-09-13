#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWaterTank_Label[] =
        "水槽{Press}";

    const char gText_LocationInteraction_InspectWaterTank_JewelOfTruthFound[] =
        "水槽の中に\r\n"
        "『真実の玉』が落ちていた。{Press}";

    const char gText_LocationInteraction_InspectWaterTank_JewelOfTruthFoundButHandsFull[] =
        "水槽の中に\r\n"
        "『真実の玉』が落ちていた。{Press}\p"
        "…んだけど、手に物を持って\r\n"
        "いるので持てない。{Press}";
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
