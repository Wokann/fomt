#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Karen_ThisIsFromMeIHope[] =
        "This is from me. \r\n"
        "I hope you like it. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Karen_ThisIsForTheCookiesYou[] =
        "This is for the Cookies\r\n"
        "you gave me in Spring. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Karen_ICameToGiveYouSomething[] =
        "I came to give you \r\n"
        "something. {Press}";
};

void EventScript_FestivalEvent_WinterThanksgiving_GiftVisit_Karen(void)
{
    int var_0;
    VarSet(VAR_WINTER_THANKSGIVING_KAREN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    var_0 = GetEntityFacing(ENTITY_KAREN);
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    if (IsPlayerHoldingNothing())
    {
        if (VarGet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_KAREN) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Karen_ThisIsFromMeIHope);
            TalkClose();
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_KAREN, TRUE);
            AddCharacterLove(CHARACTER_KAREN, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_KAREN)) != X(340))
            {
                SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
                SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
                MoveEntityXTo(ENTITY_KAREN, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_KAREN);
                SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            }
            SetEntityFacing(ENTITY_KAREN, FACING_UP);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityYTo(ENTITY_KAREN, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            HideEntity(ENTITY_KAREN);
            VarSet(VAR_WINTER_THANKSGIVING_KAREN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Karen_ThisIsForTheCookiesYou);
            TalkClose();
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_KAREN, TRUE);
            VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_KAREN, FALSE);
            AddCharacterLove(CHARACTER_KAREN, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_KAREN)) != X(340))
            {
                SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
                SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
                MoveEntityXTo(ENTITY_KAREN, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_KAREN);
                SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            }
            SetEntityFacing(ENTITY_KAREN, FACING_UP);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityYTo(ENTITY_KAREN, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            HideEntity(ENTITY_KAREN);
            VarSet(VAR_WINTER_THANKSGIVING_KAREN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Karen_ICameToGiveYouSomething);
        TalkClose();
        VarSet(VAR_WINTER_THANKSGIVING_KAREN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    SetEntityFacing(ENTITY_KAREN, var_0);
    MarkNpcSpokenTo(CHARACTER_KAREN);
}
