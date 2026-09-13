#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_VaseInspection[] =
        "花瓶{Press}";

    const char gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_ConfirmDiscardFlowers[] =
        "今飾ってる花を捨ててもいい？";

    const char gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_Yes[] =
        "はい";

    const char gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_No[] =
        "いいえ";
};

void EventScript_LocationInteraction_FarmhouseVaseFlowerDiscardChoice(void)
{
    int var_0, var_1, var_2;
    var_1 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped())
    {
        var_2 = GetPlayerHeldArticleId();
        switch (var_2)
        {
            case ITEM_ARTICLE_FLOWER_MOON_DROP:
            case ITEM_ARTICLE_FLOWER_PINK_CAT:
            case ITEM_ARTICLE_FLOWER_MAGIC_BLUE:
            case ITEM_ARTICLE_FLOWER_MAGIC_RED:
            case ITEM_ARTICLE_FLOWER_TOY:
                var_1 = TRUE;
                break;
        }
    }
    if (var_1)
    {
        if (IsPlayerHeldItemWrapped() == TRUE)
        {
            TalkOpen();
            TalkMessage(gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_VaseInspection);
            TalkClose();
            return;
        }
        else
        {
            if (GetVaseArticleId() != mary_negated_int(ITEM_ARTICLE_NOT_PRESENT))
            {
                TalkOpen();
                var_0 = TalkPromptChoice2(gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_ConfirmDiscardFlowers, gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_Yes, gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_No);
                TalkClose();
                switch (var_0)
                {
                    case PROMPT_CHOICE_OPTION_1:
                        UsePlayerHeldItem();
                        SetVaseArticleId(var_2);
                        break;
                    case PROMPT_CHOICE_OPTION_2:
                        return;
                    mary_dead_jump:
                }
            }
            else
            {
                UsePlayerHeldItem();
                SetVaseArticleId(var_2);
            }
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_FarmhouseVaseFlowerDiscardChoice_VaseInspection);
        TalkClose();
    }
}
