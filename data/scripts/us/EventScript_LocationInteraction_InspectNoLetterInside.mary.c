#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectNoLetterInside[] =
        "No letter inside.{Press}";
};

void EventScript_LocationInteraction_InspectNoLetterInside(void)
{
    int var_0;
    if (IsPlayerRidingHorse())
    {
        return;
    }
    if (GetWaitingLetterCount() == 0)
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectNoLetterInside);
        TalkClose();
    }
    else
    {
        for (var_0 = 77; var_0 <= 133; ++var_0)
        {
            if (IsLetterWaiting(var_0) == TRUE)
            {
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ShowReferencePage(var_0);
                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                MarkLetterRead(var_0);
            }
        }
        if (IsLetterWaiting(LETTER_STAFF_CREDITS) == TRUE)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ShowReferencePage(REFERENCE_PAGE_STAFF_CREDITS);
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            MarkLetterRead(LETTER_STAFF_CREDITS);
        }
        if (IsPlayerHoldingNothing() == TRUE)
        {
            if (IsLetterWaiting(LETTER_HARVEST_SPRITE_TEA_PARTY_INVITATION) == TRUE)
            {
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ShowReferencePage(REFERENCE_PAGE_HARVEST_SPRITE_TEA_PARTY_INVITATION);
                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                MarkLetterRead(LETTER_HARVEST_SPRITE_TEA_PARTY_INVITATION);
                SetPlayerHeldArticle(ITEM_ARTICLE_INVITATION);
            }
        }
    }
}
