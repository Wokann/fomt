#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_CollectibleEvent_FarmDoghouseJewelOfTruth_Description[] =
        "{Dog}の家{Press}";

    const char gText_CollectibleEvent_FarmDoghouseJewelOfTruth_JewelFound[] =
        "{Dog}の家の中に\r\n"
        "『真実の玉』が落ちていた。{Press}";

    const char gText_CollectibleEvent_FarmDoghouseJewelOfTruth_AfterCollection[] =
        "{Dog}の家の中に\r\n"
        "『真実の玉』が落ちていた。{Press}\p"
        "…んだけど、手に物を持って\r\n"
        "いるので持てない。{Press}";
};

void EventScript_CollectibleEvent_FarmDoghouseJewelOfTruth(void)
{
    if (IsPlayerRidingHorse())
    {
        return;
    }
    if (VarGet(VAR_JEWEL_OF_TRUTH_FROM_DOG_HOUSE_COLLECTED) == TRUE)
    {
        TalkOpen();
        TalkAppendMessage(gText_CollectibleEvent_FarmDoghouseJewelOfTruth_Description);
    }
    else
    {
        if (VarGet(VAR_HAS_SHELF) == TRUE)
        {
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetPlayerHeldArticle(ITEM_ARTICLE_JEWEL_OF_TRUTH);
                TalkOpen();
                TalkMessage(gText_CollectibleEvent_FarmDoghouseJewelOfTruth_JewelFound);
                VarSet(VAR_JEWEL_OF_TRUTH_FROM_DOG_HOUSE_COLLECTED, TRUE);
                VarSet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT, VarGet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT) + 1);
            }
            else
            {
                TalkOpen();
                TalkMessage(gText_CollectibleEvent_FarmDoghouseJewelOfTruth_AfterCollection);
            }
        }
        else
        {
            TalkOpen();
            TalkAppendMessage(gText_CollectibleEvent_FarmDoghouseJewelOfTruth_Description);
        }
    }
    TalkClose();
}
