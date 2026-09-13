#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_GooGoo[] =
        "ねぇ、仕事終わった？{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_Yes[] =
        "はい";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_No[] =
        "いいえ";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YouThinkThisMealIsDifferent[] =
        "こんな料理はめずらしい？\r\n"
        "いつもは病人食みたい？{Press}\p"
        "ねぇ、今日が何の日か\r\n"
        "知っているわよね。{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_OurAnniversary[] =
        "結婚記念日";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_MyBirthday[] =
        "自分の誕生日";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YourBirthday[] =
        "エリィの誕生日";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_OurAnniversaryYouWereJustKidding[] =
        "…結婚記念日？今、\r\n"
        "あてずっぽうで言ったでしょ？{Press}\p"
        "それにしたって、自分の誕生日\r\n"
        "くらいちゃんと覚えておかない\r\n"
        "とダメよ。{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater[] =
        "後であやまっておこう…{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_PlayerSurprisesElliForHerBirthday[] =
        "お誕生日おめでとう。\r\n"
        "どう、びっくりした？{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_ICantWaitToHaveA[] =
        "はやく赤ちゃんほしいよね。\r\n"
        "わたし、子ども大好きなの♡{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday[] =
        "楽しかった…\r\n"
        "今日はよくねむれそうだ…{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_WellMaybeIShouldntExpectYou[] =
        "はぁ、そうそう。わたしの\r\n"
        "誕生日なんていちいち覚えて\r\n"
        "ないでしょうね。{Press}\p"
        "それにしたって、自分の誕生日\r\n"
        "くらいちゃんと覚えておかない\r\n"
        "とダメよ。{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_BabySBirthday[] =
        "{Baby}の誕生日";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_NowYoureAYearOlderAnd[] =
        "１つ年をとったし、パパでも\r\n"
        "あるんだからしっかりがん\r\n"
        "ばってね♡{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YouReallyAreAStrangeOne[] =
        "あなたって、つくづく変な\r\n"
        "人ね。{Press}\p"
        "自分の誕生日も覚えていなけれ\r\n"
        "ば、この子が産まれた日も\r\n"
        "覚えていないわけ？{Press}";

    const char gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs[] =
        "早く仕事終わらせてね。\r\n"
        "今日は特別な日なんだから。{Press}";
};

void EventScript_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    MarkNpcSpokenTo(CHARACTER_ELLI);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_GooGoo);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_Yes, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YouThinkThisMealIsDifferent);
            TalkClose();
            TalkOpen();
            if (VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_OurAnniversary, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YourBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_OurAnniversaryYouWereJustKidding);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_2:
                        AddCharacterLove(CHARACTER_ELLI, 3000);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_PlayerSurprisesElliForHerBirthday);
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
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_ICantWaitToHaveA);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                    case CHOICE_OPTION_3:
                        AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_WellMaybeIShouldntExpectYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                        break;
                }
            }
            else
            {
                var_0 = TalkChoice3(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_MyBirthday, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YourBirthday, gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_BabySBirthday);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        AddCharacterLove(CHARACTER_ELLI, 3000);
                        AddNpcFriendship(CHARACTER_CHILD, 20);
                        TalkClose();
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_PlayerSurprisesElliForHerBirthday);
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
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_NowYoureAYearOlderAnd);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IHadSoMuchFunToday);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
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
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_WellMaybeIShouldntExpectYou);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
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
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_YouReallyAreAStrangeOne);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                        TalkOpen();
                        TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_IdBetterApologizeLater);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CHILD);
                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
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
            TalkMessage(gText_FamilyEvent_Elli_PlayerBirthdayDinnerDialogueChoice_HurryUpAndFinishTodayIs);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}
