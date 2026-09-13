#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_OpeningQuestion[] =
        "おはようっっっ！\r\n"
        "ねぇ、今日が何の日かわかる？{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_PlayerBirthdayChoice[] =
        "ランの誕生日";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice[] =
        "結婚記念日";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_SpouseBirthdayChoice[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse[] =
        "へ？わたしの誕生日？\r\n"
        "ちがうよ…今日は結婚記念日\r\n"
        "だよ…{Press}\p"
        "はぁ～、忘れてたんだ、\r\n"
        "プレゼント用意して、起きるの\r\n"
        "まってたのに！{Press}\r\n"
        "プレゼントあげないんだから！{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse[] =
        "そうなのよ！\r\n"
        "気づいてくれたんだ♡{Press}\p"
        "{NickName}、これからも\r\n"
        "よろしくお願いします。{Press}\p"
        "あ、そうそう、日ごろのお礼に\r\n"
        "プレゼントを用意したんだ！{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_ImmediateGiftDelivery[] =
        "はい、あげる。{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt[] =
        "プレゼントあげるから、\r\n"
        "手に持ってる物しまってね。{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse[] =
        "はぁ～～～、\r\n"
        "結婚記念日くらい、おぼえて\r\n"
        "てよ！{Press}\p"
        "プレゼント用意したのに…\r\n"
        "{NickName}がそういうつもり\r\n"
        "ならあげない！{Press}";
};

void EventScript_FamilyEvent_Ann_AnniversaryDateDialogueChoice(void)
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
    SetEntityPosition(ENTITY_ANN, X(265), Y(114), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    if (VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
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
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_OpeningQuestion);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice3(gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_PlayerBirthdayChoice, gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice, gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_SpouseBirthdayChoice);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse);
            TalkClose();
            VarSet(VAR_ANN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ANN, 3000);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            if (IsPlayerHoldingNothing())
            {
                SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                TalkMessage(gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_ImmediateGiftDelivery);
                TalkClose();
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_GESTURE);
                WaitFrames(60);
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
                PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
                SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                VarSet(VAR_ANN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                WaitFrames(60);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
                SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
                TalkMessage(gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt);
                TalkClose();
                EnableScriptedNpcControl();
                SetEntityEventScript(ENTITY_ANN, EventScript_FamilyEvent_Ann_AnniversaryDeferredGiftDelivery);
                if (VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                {
                    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Ann_AnniversaryChildReaction);
                }
                VarSet(VAR_ANN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            }
            break;
        case CHOICE_OPTION_3:
            AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse);
            TalkClose();
            VarSet(VAR_ANN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
    }
    MarkNpcSpokenTo(CHARACTER_ANN);
}
