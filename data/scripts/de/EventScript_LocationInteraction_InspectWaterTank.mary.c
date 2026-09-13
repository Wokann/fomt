#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWaterTank_Label[] =
        "Wassertank{Press}";

    const char gText_LocationInteraction_InspectWaterTank_JewelOfTruthFound[] =
        "Im Wassertank ist ein\r\n"
        "Juwel der Wahrheit.{Press}";

    const char gText_LocationInteraction_InspectWaterTank_JewelOfTruthFoundButHandsFull[] =
        "Im Wassertank ist ein\r\n"
        "Juwel der Wahrheit.{Press}\p"
        "...Aber deine Hände sind\r\n"
        "voll, also kannst du \r\n"
        "es nicht halten.{Press}";
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
