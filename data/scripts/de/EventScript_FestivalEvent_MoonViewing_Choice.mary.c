#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MoonViewing_Choice_IHeardThatThisWasThe[] =
        "Ich habe gehört, dies sei\r\n"
        "der beste Platz zum \r\n"
        "Mondansehen.{Press}\r\n"
        "Können wir zusammensitzen?{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_TodayIsMoonViewingYouKnow[] =
        "Heute schauen wir uns\r\n"
        "den Mond an. \r\n"
        "Sollen wir zusammen{Press}\r\n"
        "hingehen?{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_ImagineMeetingHereShallWeWatch[] =
        "Stell dir vor, wir \r\n"
        "treffen uns hier!\r\n"
        "Sollen wir zusammen gucken?{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_TodayIsMoonViewingDayWhen[] =
        "Heute ist die Nacht des\r\n"
        "Mondes, wenn er besonders\r\n"
        "schön aussieht. {Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_TonightTheMoonWillBeFull[] =
        "Heute wird Vollmond \r\n"
        "sein. Willst du mit \r\n"
        "mir den Mond ansehen?{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_Yes[] =
        "Ja.";

    const char gText_FestivalEvent_MoonViewing_Choice_No[] =
        "Nein.";

    const char gText_FestivalEvent_MoonViewing_Choice_Shared_KarenAndPopuriAgreeToWatchTogether[] =
        "Lass uns zusammensitzen,\r\n"
        "ja?{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_AnnOrMaryAgreesToWatchTogether[] =
        "Ok, schauen wir zusammen.{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_ElliAgreesToWatchTogether[] =
        "Gut,\r\n"
        "schauen wir zusammen.{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_HeeHeeYouCanStayUp[] =
        "Hi hii. Du kannst  \r\n"
        "nicht so lange \r\n"
        "aufbleiben?{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_EvenThoughTonightsMoonWillBe[] =
        "Obwohl der Mond heute\r\n"
        "sehr hübsch sein wird...?{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_YouDidntComeToWatchThe[] =
        "Du bist nicht gekommen, \r\n"
        "um den Mond anzusehen? {Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_WhatAWasteItsOnlyOnce[] =
        "Welche Verschwendung!\r\n"
        "Es ist nur einmal im Jahr!{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_ThatsTooBadAreYouTired[] =
        "Das ist zu schade.\r\n"
        "Bist du müde?{Press}";

    const char gText_FestivalEvent_MoonViewing_Choice_ChoiceGoToBedEarly[] =
        "Ich gehe heute \r\n"
        "früh ins Bett. {Press}";
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
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_Shared_KarenAndPopuriAgreeToWatchTogether);
                    break;
                case CHARACTER_POPURI:
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                    }
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_Shared_KarenAndPopuriAgreeToWatchTogether);
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
                    TalkMessage(gText_FestivalEvent_MoonViewing_Choice_AnnOrMaryAgreesToWatchTogether);
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
