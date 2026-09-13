#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_OpeningQuestion[] =
        "Good morning!\r\n"
        "Did you sleep well?\r\n"
        "Do you know what today is?{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_PlayerBirthdayChoice[] =
        "Your birthday";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice[] =
        "Our anniversary";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_SpouseBirthdayChoice[] =
        "My birthday";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse[] =
        "My birthday?!?\r\n"
        "This means you don't \r\n"
        "really remember either my{Press}\r\n"
        "birthday or our anniversary!{Press}\p"
        "So much for your present!{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse[] =
        "Of course! I knew \r\n"
        "you'd remember! You're so\r\n"
        "considerate, {NickName}.{Press}\p"
        "Here's a present for you!{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_ImmediateGiftDelivery[] =
        "Here you are, {NickName}.{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt[] =
        "I'm going to give you a \r\n"
        "present, so empty your \r\n"
        "hands, OK?{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse[] =
        "You're birthday!?\r\n"
        "That's the most insensitive \r\n"
        "thing I've ever heard!{Press}\p"
        "Now you're not getting\r\n"
        "your present anymore!{Press}";
};

void EventScript_FamilyEvent_Mary_AnniversaryDateDialogueChoice(void)
{
    int var_0;
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
    SetEntityPosition(ENTITY_MARY, X(265), Y(114), FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    if (VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
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
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_OpeningQuestion);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice3(gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_PlayerBirthdayChoice, gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice, gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_SpouseBirthdayChoice);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse);
            TalkClose();
            VarSet(VAR_MARY_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_MARY, 3000);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            if (IsPlayerHoldingNothing())
            {
                SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                TalkMessage(gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_ImmediateGiftDelivery);
                TalkClose();
                SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_GESTURE);
                WaitFrames(60);
                SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
                PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
                SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                VarSet(VAR_MARY_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                WaitFrames(60);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
                SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                TalkMessage(gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt);
                TalkClose();
                EnableScriptedNpcControl();
                SetEntityEventScript(ENTITY_MARY, EventScript_FamilyEvent_Mary_AnniversaryDeferredGiftDelivery);
                if (VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                {
                    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Mary_AnniversaryChildReaction);
                }
                VarSet(VAR_MARY_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            }
            break;
        case CHOICE_OPTION_3:
            AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse);
            TalkClose();
            VarSet(VAR_MARY_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
    }
    MarkNpcSpokenTo(CHARACTER_MARY);
}
