#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_JewelFound[] =
        "Ein Juwel der Wahrheit\r\n"
        "ist ins Regal gefallen.{Press}";

    const char gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_InventoryFull[] =
        "Ein Juwel der Wahrheit\r\n"
        "ist ins Regal gefallen.{Press}\p"
        "...Aber deine Hände sind\r\n"
        "schon voll, also kannst du \r\n"
        "es nicht halten.{Press}";

    const char gText_CollectibleEvent_Library2FBookshelfJewelOfTruth_AfterCollection[] =
        "Bücherregal\r\n"
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
