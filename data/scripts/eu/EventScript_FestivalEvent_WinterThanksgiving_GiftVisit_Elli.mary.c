#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Elli_ThisIsFromMeIHope[] =
        "This is from me. \r\n"
        "I hope you like it. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Elli_ThisIsForTheCookiesYou[] =
        "This is for the Cookies\r\n"
        "you gave me in Spring. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Elli_ICameToGiveYouSomething[] =
        "I came to give you \r\n"
        "something. {Press}";
};

void EventScript_FestivalEvent_WinterThanksgiving_GiftVisit_Elli(void)
{
    int var_0;
    VarSet(VAR_WINTER_THANKSGIVING_ELLI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    var_0 = GetEntityFacing(ENTITY_ELLI);
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (IsPlayerHoldingNothing())
    {
        if (VarGet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_ELLI) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Elli_ThisIsFromMeIHope);
            TalkClose();
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_ELLI, TRUE);
            AddCharacterLove(CHARACTER_ELLI, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_ELLI)) != X(340))
            {
                SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
                SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
                MoveEntityXTo(ENTITY_ELLI, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_ELLI);
                SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            }
            SetEntityFacing(ENTITY_ELLI, FACING_UP);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            HideEntity(ENTITY_ELLI);
            VarSet(VAR_WINTER_THANKSGIVING_ELLI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Elli_ThisIsForTheCookiesYou);
            TalkClose();
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_ELLI, TRUE);
            VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_ELLI, FALSE);
            AddCharacterLove(CHARACTER_ELLI, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_ELLI)) != X(340))
            {
                SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
                SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
                MoveEntityXTo(ENTITY_ELLI, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_ELLI);
                SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            }
            SetEntityFacing(ENTITY_ELLI, FACING_UP);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            HideEntity(ENTITY_ELLI);
            VarSet(VAR_WINTER_THANKSGIVING_ELLI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
        ShowTalkHeartIndicator(CHARACTER_ELLI);
        TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Elli_ICameToGiveYouSomething);
        TalkClose();
        VarSet(VAR_WINTER_THANKSGIVING_ELLI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    SetEntityFacing(ENTITY_ELLI, var_0);
    MarkNpcSpokenTo(CHARACTER_ELLI);
}
