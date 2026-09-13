#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouThinkThisMealIsDifferent[] =
        "こんな料理はめずらしい？\r\n"
        "いつもは病人食みたい？{Press}\p"
        "ねぇ、今日が何の日か知って\r\n"
        "いるわよね。{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "結婚記念日";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ElliAsksForHerBirthday[] =
        "エリィの誕生日";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AnniversaryYoureJokingRightNoHusband[] =
        "…結婚記念日？今、\r\n"
        "あてずっぽうで言ったでしょ？{Press}\p"
        "いいわよっ。わたしの誕生日\r\n"
        "なんて、いちいち覚えていられ\r\n"
        "ないでしょうから。{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouAlreadyBecomingSenileAt[] =
        "こんなにわかいうちから、\r\n"
        "物忘れ？ちょっと心配になって\r\n"
        "きたわ…{Press}\p"
        "よりによって、自分の誕生日だ\r\n"
        "なんて…いい？今日は、\r\n"
        "わたしの誕生日なの。{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyDidRememberYouWerent[] =
        "わたしの誕生日？\r\n"
        "…今あてずっぽうで言った\r\n"
        "でしょ？{Press}\p"
        "ホントに覚えてたの？\r\n"
        "………うれしい！{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ICantWaitToHaveA[] =
        "はやく赤ちゃんほしいよね。\r\n"
        "わたし、子ども大好きなの♡{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ChoiceBabyBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_NoMatterHowManyBirthdaysI[] =
        "何度も誕生日をむかえる\r\n"
        "よりも、１度、子どもを産んだ\r\n"
        "方が大人になったって感じが{Press}\r\n"
        "するのよね♡{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyAreAStrangeOne[] =
        "あなたって、つくづくいい\r\n"
        "かげんな人ね。{Press}\p"
        "わたしの誕生日も覚えていな\r\n"
        "ければ、子どもの誕生日も\r\n"
        "覚えていないわけ？{Press}";

    const char gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ELLI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouThinkThisMealIsDifferent);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ElliAsksForHerBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AnniversaryYoureJokingRightNoHusband);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouAlreadyBecomingSenileAt);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ELLI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyDidRememberYouWerent);
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
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ICantWaitToHaveA);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ElliAsksForHerBirthday, gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_ChoiceBabyBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_AreYouAlreadyBecomingSenileAt);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ELLI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyDidRememberYouWerent);
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
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_NoMatterHowManyBirthdaysI);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_YouReallyAreAStrangeOne);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}
