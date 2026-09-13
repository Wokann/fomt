#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChickenCoopSouthIncubator_InspectChickenCoopSouthIncubatorEggAlreadyPresent[] =
        "すでに卵が置かれている。\r\n"
        "早く生まれないかな…{Press}";

    const char gText_LocationInteraction_InspectChickenCoopSouthIncubator_InspectChickenCoopSouthIncubatorInstructions[] =
        "ふか箱\r\n"
        "ここに卵を置くと何日か後に\r\n"
        "ひよこが生まれる。{Press}";

    const char gText_LocationInteraction_InspectChickenCoopSouthIncubator_InspectChickenCoopSouthIncubatorCannotPlaceEgg[] =
        "鶏がいっぱいで、\r\n"
        "これ以上ふかさせられない…{Press}";
};

void EventScript_LocationInteraction_InspectChickenCoopSouthIncubator(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
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
    if (IsIncubatorOccupied(CHICKEN_COOP_INCUBATOR_SOUTH))
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectChickenCoopSouthIncubator_InspectChickenCoopSouthIncubatorEggAlreadyPresent);
        TalkClose();
    }
    else
    {
        if (!var_0)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectChickenCoopSouthIncubator_InspectChickenCoopSouthIncubatorInstructions);
            TalkClose();
        }
        else
        {
            var_2 = VarGet(VAR_COOP_UPGRADE_LEVEL);
            if (var_2 == FARM_BUILDING_STANDARD)
            {
                var_3 = 4;
            }
            else
            {
                var_3 = 8;
            }
            var_4 = GetChickenCount();
            var_5 = FALSE;
            if (var_2 == FARM_BUILDING_UPGRADED)
            {
                if (IsIncubatorOccupied(CHICKEN_COOP_INCUBATOR_NORTH))
                {
                    var_5 = TRUE;
                }
            }
            if (var_4 + var_5 == var_3)
            {
                TalkOpen();
                TalkMessage(gText_LocationInteraction_InspectChickenCoopSouthIncubator_InspectChickenCoopSouthIncubatorCannotPlaceEgg);
                TalkClose();
            }
            else
            {
                UsePlayerHeldItem();
                BeginEggIncubation(CHICKEN_COOP_INCUBATOR_SOUTH);
            }
        }
    }
}
