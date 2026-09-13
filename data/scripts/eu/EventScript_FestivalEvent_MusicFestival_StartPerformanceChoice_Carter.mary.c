#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImLookingForwardToHearingYou[] =
        "I'm looking forward to \r\n"
        "hearing you play Ocarina.{Press}\p"
        "Are you ready yet?{Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImReady[] =
        "I'm ready.";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WaitAMinute[] =
        "Wait a minute.";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_CarterStartsPerformance[] =
        "OK... \r\n"
        "Everyone, we're on! {Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WhatsWrongWhenYouDoGet[] =
        "What's wrong? When you\r\n"
        "do get ready, just \r\n"
        "let me know. {Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_YouCantPlayTheOcarinaIf[] =
        "You can't play the Ocarina\r\n"
        "if you're holding anything.\r\n"
        "Please put that down first. {Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_YouArentPerformingWithUsThis[] =
        "You aren't performing with \r\n"
        "us this time, right? {Press}\p"
        "Just sit back and enjoy\r\n"
        "the music!{Press}";
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
