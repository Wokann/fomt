#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_Fireplace_ItsHot[] =
        "あつっ。{Press}";

    const char gText_LocationInteraction_Fireplace_FireplaceLabel[] =
        "暖炉{Press}";
};

void EventScript_LocationInteraction_Fireplace(void)
{
    int var_0, var_1, var_2;
    var_1 = VarGet(VAR_SEASON);
    var_2 = GetEntityLocation(ENTITY_PLAYER);
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing())
    {
        if (IsFireplaceLitAtLocation(var_2))
        {
            if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE)
            {
                if (CanDiscardPlayerHeldArticle())
                {
                    var_0 = TRUE;
                }
            }
            else
            {
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    var_0 = TRUE;
                }
            }
        }
        else
        {
            if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE)
            {
                if (GetPlayerHeldArticleId() == ITEM_ARTICLE_LUMBER || GetPlayerHeldArticleId() == ITEM_ARTICLE_BRANCHES)
                {
                    if (IsPlayerHeldItemWrapped() == TRUE)
                    {
                        var_0 = FALSE;
                    }
                    else
                    {
                        var_0 = TRUE;
                    }
                }
            }
        }
    }
    if (var_0)
    {
        UsePlayerHeldItem();
        if (IsFireplaceLitAtLocation(var_2))
        {
            if (var_1 == SEASON_WINTER)
            {
                ChangePlayerStaminaAndFatigue(0, mary_negated_int(-2));
            }
            else
            {
                if (var_1 == SEASON_SUMMER)
                {
                    ChangePlayerStaminaAndFatigue(0, 5);
                }
            }
            PlaySong(AUDIO_START, AUDIO_SFX_ADD_ITEM_TO_FIRE);
        }
        else
        {
            if (var_1 == SEASON_WINTER)
            {
                ChangePlayerStaminaAndFatigue(0, mary_negated_int(-5));
            }
            else
            {
                if (var_1 == SEASON_SUMMER)
                {
                    ChangePlayerStaminaAndFatigue(0, 5);
                }
            }
            PlaySong(AUDIO_START, AUDIO_SFX_LIGHT_FIREPLACE);
        }
        LightFireplaceAtLocation(var_2);
        if (RandomIntInclusive(0, 255) == 0)
        {
            WaitFrames(30);
            TalkOpen();
            TalkMessage(gText_LocationInteraction_Fireplace_ItsHot);
            TalkClose();
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_Fireplace_FireplaceLabel);
        TalkClose();
    }
}
