#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorEggAlreadyPresent[] =
        "すでに卵が置かれている。\r\n"
        "早く生まれないかな…{Press}";

    const char gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorInstructions[] =
        "ふか箱\r\n"
        "ここに卵を置くと何日か後に\r\n"
        "ひよこが生まれる。{Press}";

    const char gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorCannotPlaceEgg[] =
        "鶏がいっぱいで、\r\n"
        "これ以上ふかさせれられない…{Press}";
};

void EventScript_LocationInteraction_InspectChickenCoopNorthIncubator(void)
{
    int var_0, var_1, var_2, var_3, var_4;
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
    if (IsIncubatorOccupied(CHICKEN_COOP_INCUBATOR_NORTH))
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorEggAlreadyPresent);
        TalkClose();
    }
    else
    {
        if (!var_0)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorInstructions);
            TalkClose();
        }
        else
        {
            var_2 = 8;
            var_3 = GetChickenCount();
            var_4 = FALSE;
            if (IsIncubatorOccupied(CHICKEN_COOP_INCUBATOR_SOUTH))
            {
                var_4 = TRUE;
            }
            if (var_3 + var_4 == var_2)
            {
                TalkOpen();
                TalkMessage(gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorCannotPlaceEgg);
                TalkClose();
            }
            else
            {
                UsePlayerHeldItem();
                BeginEggIncubation(CHICKEN_COOP_INCUBATOR_NORTH);
            }
        }
    }
}
