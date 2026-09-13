#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_GooGoo[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs[] =
        "すごいごちそうでしょ？\r\n"
        "どうしてだか、分かる？{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "結婚記念日";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "ランの誕生日";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_SorryTryAgainItsYourOwn[] =
        "ブー、はずれ。今日は\r\n"
        "{NickName}の誕生日でした。\r\n"
        "ホントに覚えてないの？{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_ThatsRightYoureGettingOlderNow[] =
        "そうそう。もう{NickName}も\r\n"
        "大人なんだから、ピシッと\r\n"
        "がんばってよ。{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_SorryAllMyFoodIsThe[] =
        "父さんに教えてもらった\r\n"
        "メニューだから、どうしても\r\n"
        "宿屋のメニューと同じ物に{Press}\r\n"
        "なっちゃうんだよね。{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthdayGetAGripIts[] =
        "わたしの誕生日ィ？もう、\r\n"
        "しっかりしてよ。今日は、\r\n"
        "じ·ぶ·んの誕生日でしょ！{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_StopFoolingMeIKnowYou[] =
        "なにをトボけた事を言ってん\r\n"
        "の、今日は{NickName}の\r\n"
        "誕生日じゃない。{Press}";

    const char gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ANN);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_GooGoo);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_YouKnowWhatDayItIs);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_SorryTryAgainItsYourOwn);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ANN, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_ThatsRightYoureGettingOlderNow);
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
                        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_SorryAllMyFoodIsThe);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthdayGetAGripIts);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ANN, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_ThatsRightYoureGettingOlderNow);
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
                        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_SorryAllMyFoodIsThe);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_MyBirthdayGetAGripIts);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
                        AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_StopFoolingMeIKnowYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}
