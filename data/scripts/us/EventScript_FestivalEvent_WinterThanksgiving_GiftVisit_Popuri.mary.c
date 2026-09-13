#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Popuri_ThisIsFromMeIHope[] =
        "This is from me. \r\n"
        "I hope you like it. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Popuri_ThisIsForTheCookiesYou[] =
        "This is for the Cookies\r\n"
        "you gave me in Spring. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Popuri_ICameToGiveYouSomething[] =
        "I came to give you \r\n"
        "something. {Press}";
};

void EventScript_FestivalEvent_WinterThanksgiving_GiftVisit_Popuri(void)
{
    int var_0;
    VarSet(VAR_WINTER_THANKSGIVING_POPURI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    var_0 = GetEntityFacing(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    if (IsPlayerHoldingNothing())
    {
        if (VarGet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_POPURI) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Popuri_ThisIsFromMeIHope);
            TalkClose();
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_HAND_OVER_ITEM);
            WaitFrames(60);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_POPURI, TRUE);
            AddCharacterLove(CHARACTER_POPURI, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_POPURI)) != X(340))
            {
                SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
                MoveEntityXTo(ENTITY_POPURI, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_POPURI);
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            }
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            HideEntity(ENTITY_POPURI);
            VarSet(VAR_WINTER_THANKSGIVING_POPURI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Popuri_ThisIsForTheCookiesYou);
            TalkClose();
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_HAND_OVER_ITEM);
            WaitFrames(60);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_POPURI, TRUE);
            VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_POPURI, FALSE);
            AddCharacterLove(CHARACTER_POPURI, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_POPURI)) != X(340))
            {
                SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
                MoveEntityXTo(ENTITY_POPURI, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_POPURI);
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            }
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            HideEntity(ENTITY_POPURI);
            VarSet(VAR_WINTER_THANKSGIVING_POPURI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Popuri_ICameToGiveYouSomething);
        TalkClose();
        VarSet(VAR_WINTER_THANKSGIVING_POPURI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    SetEntityFacing(ENTITY_POPURI, var_0);
    MarkNpcSpokenTo(CHARACTER_POPURI);
}
