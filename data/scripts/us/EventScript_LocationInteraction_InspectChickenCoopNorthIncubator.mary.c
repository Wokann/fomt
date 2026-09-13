#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorEggAlreadyPresent[] =
        "There are already eggs here.\r\n"
        "Hope they hatch soon...{Press}";

    const char gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorInstructions[] =
        "Incubator\r\n"
        "If you place eggs in here,\r\n"
        "they'll hatch in a few days.{Press}";

    const char gText_LocationInteraction_InspectChickenCoopNorthIncubator_InspectChickenCoopNorthIncubatorCannotPlaceEgg[] =
        "It's already full, so you \r\n"
        "can't incubate any more.{Press}";
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
