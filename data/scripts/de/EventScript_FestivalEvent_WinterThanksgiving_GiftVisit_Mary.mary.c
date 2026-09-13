#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Mary_ThisIsFromMeIHope[] =
        "Das ist von mir. \r\n"
        "Ich hoffe, es gefällt dir.{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Mary_ThisIsForTheCookiesYou[] =
        "Das ist für die Kekse,\r\n"
        "den du mir im Frühling \r\n"
        "gegeben hast. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_GiftVisit_Mary_ICameToGiveYouSomething[] =
        "Ich komme, um dir etwas\r\n"
        "zu geben. {Press}";
};

void EventScript_FestivalEvent_WinterThanksgiving_GiftVisit_Mary(void)
{
    int var_0;
    VarSet(VAR_WINTER_THANKSGIVING_MARY_VISIT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    var_0 = GetEntityFacing(ENTITY_MARY);
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_MARY);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    if (IsPlayerHoldingNothing())
    {
        if (VarGet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_MARY) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Mary_ThisIsFromMeIHope);
            TalkClose();
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_MARY, TRUE);
            AddCharacterLove(CHARACTER_MARY, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_MARY)) != X(340))
            {
                SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
                SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
                MoveEntityXTo(ENTITY_MARY, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_MARY);
                SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            }
            SetEntityFacing(ENTITY_MARY, FACING_UP);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityYTo(ENTITY_MARY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            HideEntity(ENTITY_MARY);
            VarSet(VAR_WINTER_THANKSGIVING_MARY_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Mary_ThisIsForTheCookiesYou);
            TalkClose();
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_YELLOW_MIN)
            {
                SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE_CAKE);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_YELLOW_MIN)
                {
                    SetPlayerHeldWrappedFood(ITEM_FOOD_CHOCOLATE);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_MARY, TRUE);
            VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_MARY, FALSE);
            AddCharacterLove(CHARACTER_MARY, 1000);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            if (X(GetEntityX(ENTITY_MARY)) != X(340))
            {
                SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
                SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
                MoveEntityXTo(ENTITY_MARY, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_MARY);
                SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            }
            SetEntityFacing(ENTITY_MARY, FACING_UP);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityYTo(ENTITY_MARY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            HideEntity(ENTITY_MARY);
            VarSet(VAR_WINTER_THANKSGIVING_MARY_VISIT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            RefreshAllNpcSchedules();
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_FestivalEvent_WinterThanksgiving_GiftVisit_Mary_ICameToGiveYouSomething);
        TalkClose();
        VarSet(VAR_WINTER_THANKSGIVING_MARY_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    SetEntityFacing(ENTITY_MARY, var_0);
    MarkNpcSpokenTo(CHARACTER_MARY);
}
