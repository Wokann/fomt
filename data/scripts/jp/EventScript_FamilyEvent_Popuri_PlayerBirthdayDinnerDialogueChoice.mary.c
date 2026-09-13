#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWithWork[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs[] =
        "ねぇねぇ。\r\n"
        "今日は何の日か、わかる？{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "結婚記念日";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "ポプリの誕生日";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYoureSoBusy[] =
        "いそがしくて、自分の誕生日も\r\n"
        "忘れちゃうなんて。今日は、\r\n"
        "これ食べてゆっくりして♡{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis[] =
        "おめでとう！ずっと前から\r\n"
        "考えていたの。どんなふうに\r\n"
        "おいわいしようかって。{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_LetsAlwaysBeTogether[] =
        "いくつになってもずーっと、\r\n"
        "いっしょにいようね。{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HowCanYouConfuseMyBirthday[] =
        "今日は{NickName}の誕生日\r\n"
        "だよ。ポプリの誕生日とまち\r\n"
        "がえるなんて！ひどーい。{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_WhatAreYouTalkingAboutHow[] =
        "ええ？　　　　　　　　　　　\r\n"
        "んー…ポプリ{NickName}が何\r\n"
        "を考えているのか分かんない…{Press}\p"
        "今日は、自分の誕生日\r\n"
        "なんだよ？{Press}";

    const char gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_POPURI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_ICantBelieveYoureSoBusy);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis);
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
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_LetsAlwaysBeTogether);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HowCanYouConfuseMyBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HappyBirthdayIveBeenPlanningThis);
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
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_LetsAlwaysBeTogether);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HowCanYouConfuseMyBirthday);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_WhatAreYouTalkingAboutHow);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}
