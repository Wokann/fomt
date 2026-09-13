#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_JewelFound[] =
        "本棚の中に\r\n"
        "『真実の玉』が落ちていた。{Press}";

    const char gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_InventoryFull[] =
        "本棚の中に\r\n"
        "『真実の玉』が落ちていた。{Press}\p"
        "…んだけど、手に物を持って\r\n"
        "いるので持てない。{Press}";

    const char gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_AfterCollection[] =
        "本棚\r\n"
        "{Press}";
};

void EventScript_CollectibleEvent_Library2FBookshelfJewelOfTruth(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_JEWEL_OF_TRUTH_FROM_BOOKSHELF_COLLECTED) == TRUE)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ShowReferencePage(REFERENCE_PAGE_SHIPPING_PRICES);
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            if (VarGet(VAR_HAS_SHELF) == TRUE)
            {
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    SetPlayerHeldArticle(ITEM_ARTICLE_JEWEL_OF_TRUTH);
                    TalkOpen();
                    TalkMessage(gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_JewelFound);
                    TalkClose();
                    VarSet(VAR_JEWEL_OF_TRUTH_FROM_BOOKSHELF_COLLECTED, TRUE);
                    VarSet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT, VarGet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT) + 1);
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_InventoryFull);
                    TalkClose();
                }
            }
            else
            {
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ShowReferencePage(REFERENCE_PAGE_SHIPPING_PRICES);
                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_AfterCollection);
        TalkClose();
    }
}
