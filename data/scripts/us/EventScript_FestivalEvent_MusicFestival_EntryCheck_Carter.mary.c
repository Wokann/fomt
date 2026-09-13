#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_EntryCheck_Carter_IveBeenWaitingForYouEverybody[] =
        "I've been waiting for you.\r\n"
        "Everybody else is already\r\n"
        "inside waiting.{Press}";

    const char gText_FestivalEvent_MusicFestival_EntryCheck_Carter_ImSorryButYouCantBring[] =
        "I'm sorry, but you can't \r\n"
        "bring any items into the\r\n"
        "Church today. {Press}\p"
        "Would you please put that\r\n"
        "in your Rucksack?{Press}";
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
        VarSet(VAR_MUSIC_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
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
