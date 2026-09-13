#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWithWork[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs[] =
        "ねぇねぇ。\r\n"
        "今日は何の日か、わかる？{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "結婚記念日";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YourBirthday[] =
        "ポプリの誕生日";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ItsMyBirthdayHowCanYou[] =
        "今日はポプリの誕生日！！\r\n"
        "…結婚記念日ってなーにー？{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatItsMyBirthdayTodayYou[] =
        "えーっ？？？今日、\r\n"
        "ポプリの誕生日だよ？もうっ、\r\n"
        "{NickName}のバカッ！{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouRememberedIDontKnowWhy[] =
        "覚えてくれてたんだ！そんな\r\n"
        "そぶり、見せなかったからすっ\r\n"
        "かり忘れられてると思ってた。{Press}\p"
        "…そんなわけないよね♡{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ILookMoreMatureToYou[] =
        "ポプリもちょっと大人っぽく\r\n"
        "なったかな？{Press}\p"
        "誕生日だからって、すぐには\r\n"
        "ムリか。{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatKindOfAFatherAre[] =
        "もう、ひどいパパでちゅねー。\r\n"
        "{Baby}の誕生日\r\n"
        "だって。{Press}\p"
        "今日はママの誕生日なのにね。{Press}";

    const char gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_POPURI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ItsMyBirthdayHowCanYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatItsMyBirthdayTodayYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouRememberedIDontKnowWhy);
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
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ILookMoreMatureToYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatItsMyBirthdayTodayYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_POPURI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_YouRememberedIDontKnowWhy);
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
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_ILookMoreMatureToYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_WhatKindOfAFatherAre);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
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
            TalkMessage(gText_FamilyEvent_Popuri_SpouseBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}
