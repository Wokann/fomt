#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_ExitFarmWithHeldAnimalRestriction_YouCantGoOutsideWhileRiding[] =
        "馬に乗ったまま外に出ることは\r\n"
        "できない。{Press}";

    const char gText_LocationTransition_ExitFarmWithHeldAnimalRestriction_YouCantGoOusideWhileHolding[] =
        "鶏を持ったまま外に出ることは\r\n"
        "できない。{Press}";
};

void EventScript_LocationTransition_ExitFarmWithHeldAnimalRestriction(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (IsPlayerRidingHorse() == TRUE)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationTransition_ExitFarmWithHeldAnimalRestriction_YouCantGoOutsideWhileRiding);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            SetEntityFacing(ENTITY_FARM_HORSE, FACING_UP);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RIDING_HORSE_WALK);
            SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_WALK);
            MoveEntityYTo(ENTITY_PLAYER, Y(688), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            MoveEntityYTo(ENTITY_FARM_HORSE, Y(688), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        if (IsPlayerHoldingNothing() == FALSE)
        {
            if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_CHICKEN)
            {
                TalkOpen();
                TalkAppendMessage(gText_LocationTransition_ExitFarmWithHeldAnimalRestriction_YouCantGoOusideWhileHolding);
                TalkClose();
                SetEntityFacing(ENTITY_PLAYER, FACING_UP);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
                MoveEntityYTo(ENTITY_PLAYER, Y(688), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_PLAYER);
                return;
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FOREST, X(168), Y(24));
        SetEntityPosition(ENTITY_PLAYER, X(168), Y(24), FACING_DOWN);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
