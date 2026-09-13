#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_DoesntThisCakeLookGoodYou[] =
        "どう？おいしそうでしょ。\r\n"
        "今日は、うでによりをかけて作\r\n"
        "りました。どうしてでしょう？{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_YourBirthday[] =
        "カレンの誕生日";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantBelieveYouWouldConfuse[] =
        "ははははっ、やだぁ。\r\n"
        "子どもの誕生日と自分の誕生日\r\n"
        "をまちがえるなんて。{Press}\p"
        "{NickName}っておかしい\r\n"
        "ヤツ！{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ThanksForThinkingAboutMeBut[] =
        "わたしより、かわいい子がいる\r\n"
        "でしょ。{Baby}が、\r\n"
        "かわいそうじゃない。{Press}{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabyIsLuckyToHaveSuch[] =
        "{Baby}くん、\r\n"
        "よかったねぇ。パパ、ちゃんと\r\n"
        "覚えていたわよ♡{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantWaitUntilHeGrows[] =
        "はやくおっきくなって、\r\n"
        "ママといっしょにお酒、\r\n"
        "のもうね。{Press}\p"
        "パパはぜんぜんのめないん\r\n"
        "だからね♡{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_KAREN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_DoesntThisCakeLookGoodYou);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_YourBirthday, gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantBelieveYouWouldConfuse);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ThanksForThinkingAboutMeBut);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_KAREN, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_BabyIsLuckyToHaveSuch);
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
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_ICantWaitUntilHeGrows);
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
                    TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
}
