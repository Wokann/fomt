#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_FiftiethAnniversaryMountainCottageGift_Announcement[] =
        "Good morning, {NickName}.\r\n"
        "Today is our 50th wedding \r\n"
        "anniversary!{Press}\p"
        "I hope you didn't forget!\r\n"
        "Guess what my gift is?\r\n"
        "Actually...It's a Cottage {Press}\p"
        "in the mountains!\r\n"
        "How did I pay for it?\r\n"
        "Don't worry about that!{Press}";

    const char gText_FamilyEvent_Karen_FiftiethAnniversaryMountainCottageGift_VisitSuggestion[] =
        "Be sure and go look at it\r\n"
        "later, OK?{Press}";
};

void EventScript_FamilyEvent_Karen_FiftiethAnniversaryMountainCottageGift(void)
{
    ChangeMap(MAP_FARMHOUSE, X(265), Y(138));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(265), Y(138), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAREN, X(265), Y(114), FACING_DOWN);
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
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_KAREN_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_FiftiethAnniversaryMountainCottageGift_Announcement);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_FiftiethAnniversaryMountainCottageGift_VisitSuggestion);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_KAREN);
    VarSet(VAR_KAREN_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_COMPLETED);
    BuildMountainCottage();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
    SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
