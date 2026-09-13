#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FamilyEvent_Elli_SpouseBirthdayDinner(void)
{
    ChangeMap(MAP_FARMHOUSE, X(304), Y(208));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(304), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLI, X(327), Y(114), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    if (VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
        {
            SetEntityPosition(ENTITY_CHILD, X(292), Y(84), FACING_DOWN);
            if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
            }
            else
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
            }
        }
        else
        {
            SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_INFANT_SLEEPING);
        }
    }
    CreateEventIcon(EVENT_ICON_SLOT_0, X(288), Y(122), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_APPLE_PIE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(304), Y(124), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_MILK_M));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_ELLI, EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice);
    if (VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerBabyGooGoo);
    }
    VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
}
