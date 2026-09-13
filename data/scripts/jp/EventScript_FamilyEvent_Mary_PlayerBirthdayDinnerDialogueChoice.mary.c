#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWorking[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_DoesThisGiveYouAnyIdeas[] =
        "これ見て、何か思わない？{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "結婚記念日";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "マリーの誕生日";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HaSometimesYouReallyAreLike[] =
        "おもしろい事言うのね。\r\n"
        "あなた見ているとあきないわ。\r\n"
        "ホントに小説の主人公みたい。{Press}\p"
        "お誕生日、おめでとう！{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_WereYouPretendingToForgetJust[] =
        "もしかして、わたしが忘れて\r\n"
        "いるんじゃないかって思って\r\n"
        "いたんじゃない？{Press}\p"
        "気がつかないふりするの、\r\n"
        "大変だったのよ。{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday[] =
        "わたし、パパとママの結婚\r\n"
        "記念日と自分の誕生日が同じで\r\n"
        "つまらなかったのよねぇ…{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYouMixUp[] =
        "自分の誕生日と、わたしの\r\n"
        "誕生日をまちがうなんて、\r\n"
        "おかしい。{Press}\p"
        "やっぱり{NickName}って、\r\n"
        "おかしいね。{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HaveYouForgottenYourOwnBirthday[] =
        "自分の誕生日を忘れたの？\r\n"
        "{NickName}がいるから、\r\n"
        "{Baby}がここにいる{Press}\r\n"
        "のよ。{Press}\p"
        "今度変なこと言ったら、おこる\r\n"
        "からね。{Press}";

    const char gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_MARY);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWorking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_DoesThisGiveYouAnyIdeas);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HaSometimesYouReallyAreLike);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_MARY, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_WereYouPretendingToForgetJust);
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
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYouMixUp);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_MARY, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_WereYouPretendingToForgetJust);
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
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ItsNoFunHavingYourBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYouMixUp);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HaveYouForgottenYourOwnBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_MARY);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_FamilyEvent_Mary_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
}
