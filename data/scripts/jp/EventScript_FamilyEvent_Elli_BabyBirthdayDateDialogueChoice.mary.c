#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IDontUsuallyBakeCakesBut[] =
        "こんな料理はめずらしい？\r\n"
        "いつもは病人食みたい？{Press}\p"
        "ねぇ、今日が何の日か知って\r\n"
        "いるわよね。{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsMyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsYourBirthday[] =
        "エリィの誕生日";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouBecomingSenileAlreadyI[] =
        "こんなにわかいうちから、\r\n"
        "物忘れ？ちょっと心配になって\r\n"
        "きたわ…{Press}\p"
        "よりによって、自分の誕生日だ\r\n"
        "なんて…いい？今日は、\r\n"
        "{Baby}の誕生日よ。{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ImFlatteredYoureThinkingOfMe[] =
        "わたしの誕生日？\r\n"
        "今のあてずっぽうでしょう？{Press}\p"
        "自分の子どもの誕生日くらい\r\n"
        "ちゃんと覚えておいてよね。{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_OfCourseYouRememberBabyS[] =
        "かわいい息子の誕生日だもの、\r\n"
        "覚えているわよね♡{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IEnjoyWatchingHimGrowUp[] =
        "この子が大きくなっていく\r\n"
        "のが、今、１番の楽しみ\r\n"
        "だわ。{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ELLI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IDontUsuallyBakeCakesBut);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsMyBirthday, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ItsYourBirthday, gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_BabySBirthday);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_AreYouBecomingSenileAlreadyI);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_ImFlatteredYoureThinkingOfMe);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_ELLI, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_OfCourseYouRememberBabyS);
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
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IEnjoyWatchingHimGrowUp);
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
                    TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}
