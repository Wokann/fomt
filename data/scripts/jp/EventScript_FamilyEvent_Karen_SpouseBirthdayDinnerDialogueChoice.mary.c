#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_LooksGoodDoesntItItsA[] =
        "どう？おいしそうでしょ。\r\n"
        "今日は、うでによりをかけて作\r\n"
        "りました。どうしてでしょう？{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "結婚記念日";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_YourBirthday[] =
        "カレンの誕生日";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WrongItsMyBirthdayICant[] =
        "…………………………\r\n"
        "ちがうわよ。わたしの誕生日！{Press}\p"
        "あーあ、忘れられちゃった\r\n"
        "わね。{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HaHaHaICantBelieve[] =
        "ははははっ、やだぁ。\r\n"
        "自分の誕生日とわたしの誕生日\r\n"
        "をまちがえるなんて、{Press}\p"
        "{NickName}って変なヤツ！{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_ThatsRightYoullCelebrateWithMe[] =
        "そうよ、あたり！！\r\n"
        "ね、いっしょにいわって\r\n"
        "くれるでしょ？{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurAnniversaries[] =
        "でも…本当に２人の記念日は、\r\n"
        "こうやって、いっしょにすごし\r\n"
        "たいんだ。{Press}\p"
        "これからも、ずーっとね。{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_KarenLaughsAtWrongBirthdayAnswer[] =
        "ははははっ、やだぁ。\r\n"
        "自分の誕生日とわたしの誕生日\r\n"
        "をまちがえるなんて。{Press}\p"
        "{NickName}って変なヤツ！{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurFamily[] =
        "でも…本当に３人の記念日は、\r\n"
        "こうやって、いっしょにすごし\r\n"
        "たいんだ。{Press}\p"
        "これからも、ずーっとね。{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IKnowYouLoveBabyBut[] =
        "自分の子どもを愛するのはいい\r\n"
        "ことだけど、同じくらい奥さん\r\n"
        "の事も愛してちょうだい。{Press}\p"
        "今日は愛する奥さんの\r\n"
        "誕生日よ。{Press}";

    const char gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_KAREN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_LooksGoodDoesntItItsA);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WrongItsMyBirthdayICant);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HaHaHaICantBelieve);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_KAREN, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_ThatsRightYoullCelebrateWithMe);
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
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurAnniversaries);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_KarenLaughsAtWrongBirthdayAnswer);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_KAREN, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_ThatsRightYoullCelebrateWithMe);
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
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_WellWeWillCelebrateOurFamily);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IKnowYouLoveBabyBut);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
}
