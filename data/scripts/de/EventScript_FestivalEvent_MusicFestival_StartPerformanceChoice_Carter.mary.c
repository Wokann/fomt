#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImLookingForwardToHearingYou[] =
        "Ich bin gespannt, wie \r\n"
        "du Okarina spielst.{Press}\p"
        "Bist du soweit?{Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImReady[] =
        "Fertig.";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WaitAMinute[] =
        "Warte kurz.";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_CarterStartsPerformance[] =
        "OK... \r\n"
        "Wir sind soweit! {Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WhatsWrongWhenYouDoGet[] =
        "Was ist los?\r\n"
        "Sag mir Bescheid, wenn\r\n"
        "du soweit bist. {Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_YouCantPlayTheOcarinaIf[] =
        "Wenn du etwas festhältst,\r\n"
        "kannst du nicht spielen.\r\n"
        "Bitte lege es erst weg.{Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_YouArentPerformingWithUsThis[] =
        "Dieses Mal machst du \r\n"
        "nicht mit, oder?{Press}\p"
        "Lehn dich einfach zurück\r\n"
        "und genieß die Musik!{Press}";
};

void EventScript_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter(void)
{
    int var_0;
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (HasMetNpc(CHARACTER_CARTER) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    if (WasNpcSpokenToToday(CHARACTER_CARTER) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CARTER, 5);
    }
    MarkNpcSpokenTo(CHARACTER_CARTER);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    if (VarGet(VAR_MUSIC_FESTIVAL_PLAYER_PERFORMANCE_ACCEPTED) == TRUE)
    {
        if (IsPlayerHoldingNothing())
        {
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            TalkMessage(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImLookingForwardToHearingYou);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice2(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImReady, gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WaitAMinute);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_CARTER);
                    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
                    TalkMessage(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_CarterStartsPerformance);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    CallScript(EventScript_FestivalEvent_MusicFestival_PlayerPerformanceAftermath);
                    break;
                case CHOICE_OPTION_2:
                    TalkClose();
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_CARTER);
                    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
                    TalkMessage(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WhatsWrongWhenYouDoGet);
                    TalkClose();
                    break;
            }
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_YouCantPlayTheOcarinaIf);
            TalkClose();
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_YouArentPerformingWithUsThis);
        TalkClose();
        TalkOpen();
        var_0 = TalkChoice2(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImReady, gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WaitAMinute);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                TalkClose();
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
                TalkMessage(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_CarterStartsPerformance);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                CallScript(EventScript_FestivalEvent_MusicFestival_PlayerPerformanceAftermath);
                break;
            case CHOICE_OPTION_2:
                TalkClose();
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
                TalkMessage(gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WhatsWrongWhenYouDoGet);
                TalkClose();
                break;
        }
    }
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
}
