#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1204_FestivalEvent_MusicFestival_EntryCheck_Carter.mary.h"

void EventScript_1204_FestivalEvent_MusicFestival_EntryCheck_Carter(void)
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
#if !defined(UNIFY_REGIONS) && (defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE))
        VarSet(VAR_MUSIC_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
#endif
        CallScript(EventScript_1205_FestivalEvent_MusicFestival_Opening);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        TalkMessage(gText_FestivalEvent_MusicFestival_EntryCheck_Carter_ImSorryButYouCantBring);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
}
