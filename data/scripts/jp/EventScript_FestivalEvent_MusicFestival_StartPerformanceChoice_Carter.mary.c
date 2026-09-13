#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImLookingForwardToHearingYou[] =
        "あなたにはオカリナを吹いて\r\n"
        "もらうんでしたね。{Press}\p"
        "楽しみにしていますよ。\r\n"
        "そろそろ、始めましょうか？{Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_ImReady[] =
        "始める";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WaitAMinute[] =
        "ちょっと待って";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_CarterStartsPerformance[] =
        "それじゃあ、\r\n"
        "みんなスタンバイして。{Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_WhatsWrongWhenYouDoGet[] =
        "どうしたんですか？\r\n"
        "始めてもよくなったら、\r\n"
        "私に声をかけてくださいね。{Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_YouCantPlayTheOcarinaIf[] =
        "ものを持っていたら楽器が\r\n"
        "吹けませんよ。\r\n"
        "ものを置いてきてくださいね。{Press}";

    const char gText_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter_YouArentPerformingWithUsThis[] =
        "今回は参加しないんでした\r\n"
        "よね。じゃあ、見学していて\r\n"
        "ください。{Press}\p"
        "きっと、楽しいと思いますよ。{Press}";
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
