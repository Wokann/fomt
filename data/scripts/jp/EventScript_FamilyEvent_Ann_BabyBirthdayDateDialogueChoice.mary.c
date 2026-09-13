#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_TodayIsASpecialDayYou[] =
        "すごいごちそうでしょ？\r\n"
        "どうしてだか、分かる？{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_YourBirthday[] =
        "ランの誕生日";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HowCanYouForgetYourOwn[] =
        "ムッ。今日はね、わたしたちの\r\n"
        "大事な大事な{Baby}\r\n"
        "ちゃんの誕生日だよ！{Press}\p"
        "忘れてたなぁ！{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouSureYoureNotWorking[] =
        "{NickName}、だいじょうぶ？\r\n"
        "仕事のしすぎだよ。ほら、\r\n"
        "これ食べて。{Press}\p"
        "ねぇ、ホントは分かって\r\n"
        "いるんでしょ？{Baby}の\r\n"
        "誕生日だって。{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_OfCourseYouWouldRememberBaby[] =
        "そうよね。\r\n"
        "大事な{Baby}ちゃんの\r\n"
        "誕生日だもん。{Press}\r\n"
        "わすれるわけないよね。{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AYearGoesSoQuicklyI[] =
        "１年って本当にはやいんだね。\r\n"
        "来年は、この子どんなふうに\r\n"
        "なっているんだろう。{Press}\p"
        "へへっ、ちょっと気がはやすぎ\r\n"
        "るか。{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ANN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_TodayIsASpecialDayYou);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_YourBirthday, gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HowCanYouForgetYourOwn);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AreYouSureYoureNotWorking);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_ANN, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_OfCourseYouWouldRememberBaby);
                    TalkClose();
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
                    WaitFrames(60);
                    if (IsPlayerHoldingNothing())
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    }
                    else
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                    }
                    WaitFrames(60);
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_AYearGoesSoQuicklyI);
                    TalkClose();
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
                    WaitFrames(60);
                    if (IsPlayerHoldingNothing())
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    }
                    else
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                    }
                    WaitFrames(60);
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}
