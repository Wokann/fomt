#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MoonViewing_Choice_IHeardThatThisWasThe[] =
        "裏山が１番きれいに見えるって\r\n"
        "聞いて来たんだ。\r\n"
        "一緒にお月見する？{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_TodayIsMoonViewingYouKnow[] =
        "ねぇねぇ、今日はお月見\r\n"
        "なんだよ。\r\n"
        "いっしょに見ようよ。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_ImagineMeetingHereShallWeWatch[] =
        "あれ、お月見に来たの？\r\n"
        "わたしもなんだ。\r\n"
        "いっしょに見ようか？{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_TodayIsMoonViewingDayWhen[] =
        "今日は、お月見の日だから、\r\n"
        "月がとってもきれいだよ。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_TonightTheMoonWillBeFull[] =
        "こんばんは、今日はきれいな\r\n"
        "満月が出ているわよ。\r\n"
        "いっしょにお月見しない？{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_Yes[] =
        "見る";

    const char gText_FestivalEvent_MoonViewing_Choice_No[] =
        "もう休む";

    const char gText_FestivalEvent_MoonViewing_Choice_KarenAgreesToWatchTogether[] =
        "じゃ、一緒に見ようか。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_PopuriAgreesToWatchTogether[] =
        "じゃ、一緒に見よっ。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_AnnOrMaryAgreesToWatchTogether[] =
        "うん、じゃ見ようか。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_MaryAgreesToWatchTogether[] =
        "それじゃあ、見ようか。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_ElliAgreesToWatchTogether[] =
        "それじゃ、一緒に見ましょう。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_HeeHeeYouCanStayUp[] =
        "わたしは夜ふかしくらい\r\n"
        "なれてるから、ぜんぜん\r\n"
        "平気だけど？{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_EvenThoughTonightsMoonWillBe[] =
        "…せっかく今日は\r\n"
        "きれいな月が出てるのに。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_YouDidntComeToWatchThe[] =
        "お月見に来たんじゃないんだ。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_WhatAWasteItsOnlyOnce[] =
        "もったいないなぁ。\r\n"
        "１年に１度のことなのに。{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_ThatsTooBadAreYouTired[] =
        "残念ね、疲れてるの？{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_ChoiceGoToBedEarly[] =
        "今日ははやく寝よう…{Press}";
};

void EventScript_FestivalEvent_MoonViewing_Choice(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8, var_9;
    switch (VarGet(VAR_FESTIVAL_MOON_VIEWING_PARTNER_INDEX))
    {
        case FESTIVAL_MOON_VIEWING_PARTNER_KAREN:
            var_1 = CHARACTER_KAREN;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_ANN:
            var_1 = CHARACTER_ANN;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_POPURI:
            var_1 = CHARACTER_POPURI;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_MARY:
            var_1 = CHARACTER_MARY;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_ELLI:
            var_1 = CHARACTER_ELLI;
            break;
    }
    switch (var_1)
    {
        case CHARACTER_KAREN:
            var_3 = TALK_PORTRAIT_KAREN_HAPPY;
            var_4 = 74;
            var_5 = 75;
            var_6 = 76;
            var_7 = 77;
            var_8 = 78;
            var_9 = 72;
            break;
        case CHARACTER_POPURI:
            var_3 = TALK_PORTRAIT_POPURI_HAPPY;
            var_4 = 9;
            var_5 = 10;
            var_6 = 11;
            var_7 = 12;
            var_8 = 13;
            var_9 = 7;
            break;
        case CHARACTER_MARY:
            var_3 = TALK_PORTRAIT_MARY_HAPPY;
            var_4 = 105;
            var_5 = 106;
            var_6 = 107;
            var_7 = 108;
            var_8 = 109;
            var_9 = 103;
            break;
        case CHARACTER_ANN:
            var_3 = TALK_PORTRAIT_ANN_HAPPY;
            var_4 = 89;
            var_5 = 90;
            var_6 = 91;
            var_7 = 92;
            var_8 = 93;
            var_9 = 87;
            break;
        case CHARACTER_ELLI:
            var_3 = TALK_PORTRAIT_ELLI_HAPPY;
            var_4 = 123;
            var_5 = 124;
            var_6 = 125;
            var_7 = 126;
            var_8 = 127;
            var_9 = 121;
            break;
    }
    switch (var_1)
    {
        case CHARACTER_KAREN:
            var_2 = 1681;
            break;
        case CHARACTER_POPURI:
            var_2 = 559;
            break;
        case CHARACTER_MARY:
            var_2 = 2067;
            break;
        case CHARACTER_ANN:
            var_2 = 1982;
            break;
        case CHARACTER_ELLI:
            var_2 = 2180;
            break;
    }
    SetEntityFacing(var_1, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(var_1);
    switch (var_1)
    {
        case CHARACTER_KAREN:
            if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_KAREN);
            }
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            TalkMessage(gText_FestivalEvent_MoonViewing_Choice_IHeardThatThisWasThe);
            break;
        case CHARACTER_POPURI:
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            TalkMessage(gText_FestivalEvent_MoonViewing_Choice_TodayIsMoonViewingYouKnow);
            break;
        case CHARACTER_ANN:
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_ANN);
            }
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            TalkMessage(gText_FestivalEvent_MoonViewing_Choice_ImagineMeetingHereShallWeWatch);
            break;
        case CHARACTER_MARY:
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_MARY);
            }
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            TalkMessage(gText_FestivalEvent_MoonViewing_Choice_TodayIsMoonViewingDayWhen);
            break;
        case CHARACTER_ELLI:
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_ELLI);
            }
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            TalkMessage(gText_FestivalEvent_MoonViewing_Choice_TonightTheMoonWillBeFull);
            break;
    }
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FestivalEvent_MoonViewing_Choice_Yes, gText_FestivalEvent_MoonViewing_Choice_No);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(var_1, 1000);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(var_3);
            SetTalkNameplateCharacter(var_1);
            switch (var_1)
            {
                case CHARACTER_KAREN:
                    if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                    }
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_KarenAgreesToWatchTogether);
                    break;
                case CHARACTER_POPURI:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                    }
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_PopuriAgreesToWatchTogether);
                    break;
                case CHARACTER_ANN:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                    }
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_AnnOrMaryAgreesToWatchTogether);
                    break;
                case CHARACTER_MARY:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                    }
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_MaryAgreesToWatchTogether);
                    break;
                case CHARACTER_ELLI:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                    }
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_ElliAgreesToWatchTogether);
                    break;
            }
            TalkClose();
            MarkNpcSpokenTo(var_1);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_FestivalEvent_MoonViewing_PartnerDialogueAndClosing);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(var_1);
            switch (var_1)
            {
                case CHARACTER_KAREN:
                    if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                    }
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_HeeHeeYouCanStayUp);
                    break;
                case CHARACTER_POPURI:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                    }
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_EvenThoughTonightsMoonWillBe);
                    break;
                case CHARACTER_ANN:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                    }
                    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_YouDidntComeToWatchThe);
                    break;
                case CHARACTER_MARY:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                    }
                    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_WhatAWasteItsOnlyOnce);
                    break;
                case CHARACTER_ELLI:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                    }
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_ThatsTooBadAreYouTired);
                    break;
            }
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_FestivalEvent_MoonViewing_Choice_ChoiceGoToBedEarly);
            TalkClose();
            DisableScriptedNpcControl();
            ClearEntityEventScript(var_1);
            VarSet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            MarkNpcSpokenTo(var_1);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
