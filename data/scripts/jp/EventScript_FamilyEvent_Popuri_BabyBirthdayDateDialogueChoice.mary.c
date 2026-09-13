#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YouDoKnowWhatDayIt[] =
        "ねぇねぇ。\r\n"
        "今日は何の日か、わかる？{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YourBirthday[] =
        "ポプリの誕生日";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YoureKiddingRightItsBabyS[] =
        "えー、何言ってるの～\r\n"
        "今日は{Baby}の誕生日\r\n"
        "でしょ？{Press}\p"
        "もうっ、{NickName}のバカ！{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_OfCourseItIsWhatYou[] =
        "そうなのぉ。…えっ？\r\n"
        "{Baby}はまだこんなもの\r\n"
        "食べられないだろうって？{Press}\p"
        "だいじょうぶ、\r\n"
        "その分ポプリが食べるから。{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_HeSeemsToBeGettingBigger[] =
        "{Baby}は男の子だから、\r\n"
        "どんどん、どんどん大きく\r\n"
        "なってほしいね。{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_POPURI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_AreYouDoneWithWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_Yes, gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YouDoKnowWhatDayIt);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice3(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_MyBirthday, gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YourBirthday, gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_BabySBirthday);
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
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YoureKiddingRightItsBabyS);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_POPURI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_2:
                    AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
                    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_YoureKiddingRightItsBabyS);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                    TalkOpen();
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IdBetterApologizeLater);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_POPURI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
                case CHOICE_OPTION_3:
                    AddCharacterLove(CHARACTER_POPURI, 3000);
                    AddNpcFriendship(CHARACTER_CHILD, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_OfCourseItIsWhatYou);
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
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_HeSeemsToBeGettingBigger);
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
                    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_IHadSoMuchFunToday);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_POPURI);
                    ClearEntityEventScript(ENTITY_CHILD);
                    VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                    break;
            }
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayDateDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}
