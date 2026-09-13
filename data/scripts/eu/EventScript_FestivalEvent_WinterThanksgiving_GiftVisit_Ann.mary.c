#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Ann_ThisIsFromMeIHope[] =
        "This is from me. \r\n"
        "I hope you like it. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Ann_ThisIsForTheCookiesYou[] =
        "This is for the Cookies\r\n"
        "you gave me in Spring. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Ann_ICameToGiveYouSomething[] =
        "I came to give you \r\n"
        "something. {Press}";
};

void EventScript_FestivalEvent_WinterThanksgiving_GiftVisit_Ann(void)
{
    int var_0;
    VarSet(VAR_WINTER_THANKSGIVING_ANN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    var_0 = GetEntityFacing(ENTITY_ANN);
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    if (IsPlayerHoldingNothing())
    {
        if (VarGet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_ANN) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Ann_ThisIsFromMeIHope);
            TalkClose();
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_ANN, TRUE);
            AddCharacterLove(CHARACTER_ANN, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_ANN)) != X(340))
            {
                SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
                MoveEntityXTo(ENTITY_ANN, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_ANN);
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            }
            SetEntityFacing(ENTITY_ANN, FACING_UP);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
            MoveEntityYTo(ENTITY_ANN, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ANN);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            HideEntity(ENTITY_ANN);
            VarSet(VAR_WINTER_THANKSGIVING_ANN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Ann_ThisIsForTheCookiesYou);
            TalkClose();
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_ANN, TRUE);
            VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_ANN, FALSE);
            AddCharacterLove(CHARACTER_ANN, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_ANN)) != X(340))
            {
                SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
                MoveEntityXTo(ENTITY_ANN, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_ANN);
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            }
            SetEntityFacing(ENTITY_ANN, FACING_UP);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
            MoveEntityYTo(ENTITY_ANN, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ANN);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            HideEntity(ENTITY_ANN);
            VarSet(VAR_WINTER_THANKSGIVING_ANN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
        ShowTalkHeartIndicator(CHARACTER_ANN);
        TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Ann_ICameToGiveYouSomething);
        TalkClose();
        VarSet(VAR_WINTER_THANKSGIVING_ANN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    SetEntityFacing(ENTITY_ANN, var_0);
    MarkNpcSpokenTo(CHARACTER_ANN);
}
