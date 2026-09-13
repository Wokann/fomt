#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_EntryCheck_Carter_IveBeenWaitingForYouEverybody[] =
        "待ってましたよ。\r\n"
        "中でみなさんもお待ちです。\r\n"
        "さあ、入りましょう。{Press}";

    const char gText_FestivalEvent_MusicFestival_EntryCheck_Carter_ImSorryButYouCantBring[] =
        "困りましたね…{Press}\p"
        "今日は教会内に物の持ちこみは\r\n"
        "遠慮してもらっているん\r\n"
        "ですよ。{Press}\p"
        "申し訳ありませんが、リュック\r\n"
        "にいれるか、おいて来て\r\n"
        "もらえますか？{Press}";
};

void EventScript_FestivalEvent_MusicFestival_EntryCheck_Carter(void)
{
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    if (IsPlayerHoldingNothing())
    {
        SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
        TalkMessage(gText_FestivalEvent_MusicFestival_EntryCheck_Carter_IveBeenWaitingForYouEverybody);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_CARTER);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        CallScript(EventScript_FestivalEvent_MusicFestival_Opening);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        TalkMessage(gText_FestivalEvent_MusicFestival_EntryCheck_Carter_ImSorryButYouCantBring);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
}
