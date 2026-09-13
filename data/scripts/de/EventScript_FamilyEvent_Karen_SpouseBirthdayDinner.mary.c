#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FamilyEvent_Karen_SpouseBirthdayDinner(void)
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
    SetEntityPosition(ENTITY_KAREN, X(327), Y(114), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
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
    CreateEventIcon(EVENT_ICON_SLOT_0, X(288), Y(123), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(304), Y(127), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_WINE));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_KAREN, EventScript_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice);
    if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Karen_SpouseBirthdayDinnerBabyBabbles);
    }
    VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
}
