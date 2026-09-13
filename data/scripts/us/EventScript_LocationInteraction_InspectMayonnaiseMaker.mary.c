#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectMayonnaiseMaker[] =
        "Mayonnaise Maker\r\n"
        "Place Eggs here to\r\n"
        "make Mayonnaise.{Press}";
};

void EventScript_LocationInteraction_InspectMayonnaiseMaker(void)
{
    int var_0, var_1;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD && !IsPlayerHeldItemWrapped())
    {
        var_1 = GetPlayerHeldFoodId();
        switch (var_1)
        {
            case ITEM_FOOD_REGULAR_QUALITY_EGG:
            case ITEM_FOOD_GOOD_QUALITY_EGG:
            case ITEM_FOOD_HIGH_QUALITY_EGG:
            case ITEM_FOOD_GOLDEN_EGG:
            case ITEM_FOOD_P_EGG:
            case ITEM_FOOD_X_EGG:
                var_0 = TRUE;
                break;
        }
    }
    if (var_0)
    {
        UsePlayerHeldItem();
        switch (var_1)
        {
            case ITEM_FOOD_REGULAR_QUALITY_EGG:
                SetPlayerHeldFood(ITEM_FOOD_MAYONNAISE_S);
                break;
            case ITEM_FOOD_GOOD_QUALITY_EGG:
                SetPlayerHeldFood(ITEM_FOOD_MAYONNAISE_M);
                break;
            case ITEM_FOOD_HIGH_QUALITY_EGG:
                SetPlayerHeldFood(ITEM_FOOD_MAYONNAISE_L);
                break;
            case ITEM_FOOD_GOLDEN_EGG:
                SetPlayerHeldFood(ITEM_FOOD_MAYONNAISE_G);
                break;
            case ITEM_FOOD_P_EGG:
                SetPlayerHeldFood(ITEM_FOOD_MAYONNAISE_P);
                break;
            case ITEM_FOOD_X_EGG:
                SetPlayerHeldFood(ITEM_FOOD_MAYONNAISE_X);
                break;
        }
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectMayonnaiseMaker);
        TalkClose();
    }
}
