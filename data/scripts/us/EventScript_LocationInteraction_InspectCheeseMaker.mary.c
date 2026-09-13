#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectCheeseMaker[] =
        "Cheese Maker\r\n"
        "Place Milk here to \r\n"
        "make Cheese{Press}";
};

void EventScript_LocationInteraction_InspectCheeseMaker(void)
{
    int var_0, var_1;
    var_0 = FALSE;
    if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD && !IsPlayerHeldItemWrapped())
    {
        var_1 = GetPlayerHeldFoodId();
        switch (var_1)
        {
            case ITEM_FOOD_MILK_S:
            case ITEM_FOOD_MILK_M:
            case ITEM_FOOD_MILK_L:
            case ITEM_FOOD_MILK_G:
            case ITEM_FOOD_MILK_P:
            case ITEM_FOOD_MILK_X:
                var_0 = TRUE;
                break;
        }
    }
    if (var_0)
    {
        UsePlayerHeldItem();
        switch (var_1)
        {
            case ITEM_FOOD_MILK_S:
                SetPlayerHeldFood(ITEM_FOOD_CHEESE_S);
                break;
            case ITEM_FOOD_MILK_M:
                SetPlayerHeldFood(ITEM_FOOD_CHEESE_M);
                break;
            case ITEM_FOOD_MILK_L:
                SetPlayerHeldFood(ITEM_FOOD_CHEESE_L);
                break;
            case ITEM_FOOD_MILK_G:
                SetPlayerHeldFood(ITEM_FOOD_CHEESE_G);
                break;
            case ITEM_FOOD_MILK_P:
                SetPlayerHeldFood(ITEM_FOOD_CHEESE_P);
                break;
            case ITEM_FOOD_MILK_X:
                SetPlayerHeldFood(ITEM_FOOD_CHEESE_X);
                break;
        }
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectCheeseMaker);
        TalkClose();
    }
}
