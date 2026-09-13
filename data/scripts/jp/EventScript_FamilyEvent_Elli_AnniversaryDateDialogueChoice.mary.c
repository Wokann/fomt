#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_OpeningQuestion[] =
        "おはよう。\r\n"
        "ねぇ、今日っていつもとちがう\r\n"
        "日って思わない？{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_PlayerBirthdayChoice[] =
        "エリィの誕生日";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice[] =
        "結婚記念日";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_SpouseBirthdayChoice[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse[] =
        "ええ～！！ちがうわよ？\r\n"
        "今日は結婚記念日なのよ。{Press}\p"
        "こんな大事なことをまちがえる\r\n"
        "なんて…プレゼントもある\r\n"
        "のに…{Press}\p"
        "そんなハクジョウな人には\r\n"
        "あげません！{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse[] =
        "そうよ。忘れたかと思ったわ。\r\n"
        "それじゃ、改めて…これからも\r\n"
        "末永くよろしくお願いします。{Press}\p"
        "わたしから{NickName}に\r\n"
        "プレゼントがあるの。\r\n"
        "受け取ってくれるかな。{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_ImmediateGiftDelivery[] =
        "はい、{NickName}。{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt[] =
        "プレゼントあげるから、\r\n"
        "手に持ってる物しまってね。{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse[] =
        "やだっ、自分の誕生日って\r\n"
        "本気で言ってるの？\r\n"
        "体の具合は大丈夫？{Press}\p"
        "熱があるんじゃないかしら…\r\n"
        "今日は結婚記念日なんだけど、\r\n"
        "それどころじゃないわね。{Press}\r\n"
        "今日は安静にしててね。{Press}";
};

void EventScript_FamilyEvent_Elli_AnniversaryDateDialogueChoice(void)
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
    SetEntityPosition(ENTITY_ELLI, X(265), Y(114), FACING_DOWN);
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
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_OpeningQuestion);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice3(gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_PlayerBirthdayChoice, gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice, gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_SpouseBirthdayChoice);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse);
            TalkClose();
            VarSet(VAR_ELLI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ELLI, 3000);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            if (IsPlayerHoldingNothing())
            {
                SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                TalkMessage(gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_ImmediateGiftDelivery);
                TalkClose();
                SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
                WaitFrames(60);
                SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
                PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
                SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                VarSet(VAR_ELLI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                WaitFrames(60);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
                SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
                TalkMessage(gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt);
                TalkClose();
                EnableScriptedNpcControl();
                SetEntityEventScript(ENTITY_ELLI, EventScript_FamilyEvent_Elli_AnniversaryDeferredGiftDelivery);
                if (VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                {
                    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Elli_AnniversaryChildReaction);
                }
                VarSet(VAR_ELLI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            }
            break;
        case CHOICE_OPTION_3:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse);
            TalkClose();
            VarSet(VAR_ELLI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
    }
    MarkNpcSpokenTo(CHARACTER_ELLI);
}
