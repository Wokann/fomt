#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1213_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter.mary.h"

void EventScript_1213_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter(void)
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
                    CallScript(EventScript_1215_FestivalEvent_MusicFestival_PlayerPerformanceAftermath);
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
                CallScript(EventScript_1215_FestivalEvent_MusicFestival_PlayerPerformanceAftermath);
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
