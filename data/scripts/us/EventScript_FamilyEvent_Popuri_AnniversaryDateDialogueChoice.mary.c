#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_OpeningQuestion[] =
        "Good morning!\r\n"
        "Do you know what today is?\r\n"
        "I'm so excited...!!{Press}";

    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_PlayerBirthdayChoice[] =
        "Your birthday";

    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice[] =
        "Our anniversary";

    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_SpouseBirthdayChoice[] =
        "My birthday";

    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse[] =
        "My birthday?!...\r\n"
        "I hope you're joking!\r\n"
        "Either way, now you're {Press}\r\n"
        "not getting the anniversary\r\n"
        "gift I had for you!{Press}";

    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse[] =
        "I'm so touched you\r\n"
        "remembered! I never should \r\n"
        "have doubted you in the \r\n"
        "first place. You're great!{Press}";

    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_ImmediateGiftDelivery[] =
        "Here you are, {NickName}.{Press}";

    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt[] =
        "I'm going to give you a \r\n"
        "present, so empty your \r\n"
        "hands, OK?{Press}";

    const char gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse[] =
        "Huh? What kind of a\r\n"
        "husband thinks an \r\n"
        "anniversary is his own {Press}\r\n"
        "birthday!?{Press}";
};

void EventScript_FamilyEvent_Popuri_AnniversaryDateDialogueChoice(void)
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
    SetEntityPosition(ENTITY_POPURI, X(265), Y(114), FACING_DOWN);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
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
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_OpeningQuestion);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice3(gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_PlayerBirthdayChoice, gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice, gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_SpouseBirthdayChoice);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse);
            TalkClose();
            VarSet(VAR_POPURI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_POPURI, 3000);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            if (IsPlayerHoldingNothing())
            {
                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                TalkMessage(gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_ImmediateGiftDelivery);
                TalkClose();
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_HAND_OVER_ITEM);
                WaitFrames(60);
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
                PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
                SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                VarSet(VAR_POPURI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                WaitFrames(60);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
                SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                TalkMessage(gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt);
                TalkClose();
                EnableScriptedNpcControl();
                SetEntityEventScript(ENTITY_POPURI, EventScript_FamilyEvent_Popuri_AnniversaryDeferredGiftDelivery);
                if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                {
                    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Popuri_AnniversaryChildReaction);
                }
                VarSet(VAR_POPURI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            }
            break;
        case CHOICE_OPTION_3:
            AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse);
            TalkClose();
            VarSet(VAR_POPURI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
    }
    MarkNpcSpokenTo(CHARACTER_POPURI);
}
