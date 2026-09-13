#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_ExitFarmWithRidingRestrictionAndKaiReturnDispatch_YouCantGoOutsideWhileRiding[] =
        "You can't go outside\r\n"
        "while riding a horse!{Press}";

    const char gText_LocationTransition_ExitFarmWithRidingRestrictionAndKaiReturnDispatch_YouCantGoOutsideWhileHolding[] =
        "You can't go outside while\r\n"
        "holding a chicken.{Press}";
};

void EventScript_LocationTransition_ExitFarmWithRidingRestrictionAndKaiReturnDispatch(void)
{
    int var_0, var_1, var_2, var_3;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (IsPlayerRidingHorse() == TRUE)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationTransition_ExitFarmWithRidingRestrictionAndKaiReturnDispatch_YouCantGoOutsideWhileRiding);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            SetEntityFacing(ENTITY_FARM_HORSE, FACING_DOWN);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RIDING_HORSE_WALK);
            SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_WALK);
            MoveEntityYTo(ENTITY_PLAYER, Y(64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            MoveEntityYTo(ENTITY_FARM_HORSE, Y(64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        if (IsPlayerHoldingNothing() == FALSE)
        {
            if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_CHICKEN)
            {
                TalkOpen();
                TalkAppendMessage(gText_LocationTransition_ExitFarmWithRidingRestrictionAndKaiReturnDispatch_YouCantGoOutsideWhileHolding);
                TalkClose();
                SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
                MoveEntityYTo(ENTITY_PLAYER, Y(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_PLAYER);
                return;
            }
        }
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_2 = VarGet(VAR_HOUR);
        var_3 = VarGet(VAR_YEAR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_SOUTH_SIDE_TOWN, X(104), Y(496));
        SetEntityPosition(ENTITY_PLAYER, X(104), Y(496), FACING_UP);
        if (VarGet(VAR_KAI_RETURNS_FOR_SUMMER_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == 1 && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_30 && (var_2 >= 9 && var_2 < 19) && GetEntityLocation(ENTITY_LILLIA) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_RICK) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_POPURI) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_BARLEY) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_GRAY) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_SAIBARA) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_SASHA) != MAP_SOUTH_SIDE_TOWN)
        {
            VarSet(VAR_KAI_RETURNS_FOR_SUMMER_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_NPCEvent_Kai_ReturnsForSummer);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
