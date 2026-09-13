#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectYarnMakerPlaceWoolInHere[] =
        "Yarn Maker\r\n"
        "Place Wool in here to \r\n"
        "make Yarn.{Press}";
};

void EventScript_LocationInteraction_InspectYarnMakerPlaceWoolInHere(void)
{
    int var_0, var_1;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && !IsPlayerHeldItemWrapped())
    {
        var_1 = GetPlayerHeldArticleId();
        switch (var_1)
        {
            case ITEM_ARTICLE_WOOL_S:
            case ITEM_ARTICLE_WOOL_M:
            case ITEM_ARTICLE_WOOL_L:
            case ITEM_ARTICLE_WOOL_G:
            case ITEM_ARTICLE_WOOL_P:
            case ITEM_ARTICLE_WOOL_X:
                var_0 = TRUE;
                break;
        }
    }
    if (var_0)
    {
        UsePlayerHeldItem();
        switch (var_1)
        {
            case ITEM_ARTICLE_WOOL_S:
                SetPlayerHeldArticle(ITEM_ARTICLE_YARN_S);
                break;
            case ITEM_ARTICLE_WOOL_M:
                SetPlayerHeldArticle(ITEM_ARTICLE_YARN_M);
                break;
            case ITEM_ARTICLE_WOOL_L:
                SetPlayerHeldArticle(ITEM_ARTICLE_YARN_L);
                break;
            case ITEM_ARTICLE_WOOL_G:
                SetPlayerHeldArticle(ITEM_ARTICLE_YARN_G);
                break;
            case ITEM_ARTICLE_WOOL_P:
                SetPlayerHeldArticle(ITEM_ARTICLE_YARN_P);
                break;
            case ITEM_ARTICLE_WOOL_X:
                SetPlayerHeldArticle(ITEM_ARTICLE_YARN_X);
                break;
        }
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectYarnMakerPlaceWoolInHere);
        TalkClose();
    }
}
