#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Gray[] =
        ".....I'm so tired...{Press}";
};

void EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Gray(void)
{
    if (HasMetNpc(CHARACTER_GRAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GRAY);
    }
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Gray);
    TalkClose();
    if (WasNpcSpokenToJustNow(CHARACTER_GRAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GRAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_GRAY);
    if ((VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE || WasNpcSpokenToJustNow(CHARACTER_CLIFF)) && WasNpcSpokenToJustNow(CHARACTER_DOUG) && WasNpcSpokenToJustNow(CHARACTER_ANNA) && WasNpcSpokenToJustNow(CHARACTER_BASIL) && WasNpcSpokenToJustNow(CHARACTER_MARY) && WasNpcSpokenToJustNow(CHARACTER_SAIBARA) && WasNpcSpokenToJustNow(CHARACTER_GRAY))
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        CallScript(EventScript_FestivalEvent_NewYearSunrise_FestivalOpening_Doug);
    }
    SetEntityFacing(ENTITY_GRAY, FACING_UP);
}
