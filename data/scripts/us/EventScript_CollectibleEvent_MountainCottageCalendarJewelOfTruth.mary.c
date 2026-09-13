#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_CollectibleEvent_MountainCottageCalendarJewelOfTruth_JewelFound[] =
        "A Jewel of Truth is\r\n"
        "fallen behind the calendar.{Press}";

    const char gText_CollectibleEvent_MountainCottageCalendarJewelOfTruth_InventoryFull[] =
        "A Jewel of Truth is\r\n"
        "fallen behind the calendar.{Press}\p"
        "...But your hands are\r\n"
        "already full, so you \r\n"
        "can't hold it.{Press}";
};

void EventScript_CollectibleEvent_MountainCottageCalendarJewelOfTruth(void)
{
    if (VarGet(VAR_JEWEL_OF_TRUTH_FROM_CALENDAR_COLLECTED) == TRUE)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        OpenCalendar();
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
                TalkMessage(gText_CollectibleEvent_MountainCottageCalendarJewelOfTruth_JewelFound);
                VarSet(VAR_JEWEL_OF_TRUTH_FROM_CALENDAR_COLLECTED, TRUE);
                TalkClose();
                VarSet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT, VarGet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT) + 1);
            }
            else
            {
                TalkOpen();
                TalkMessage(gText_CollectibleEvent_MountainCottageCalendarJewelOfTruth_InventoryFull);
                TalkClose();
            }
        }
        else
        {
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            OpenCalendar();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
    }
}
