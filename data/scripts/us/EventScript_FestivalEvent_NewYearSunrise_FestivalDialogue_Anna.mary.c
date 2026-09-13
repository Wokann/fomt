#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Anna[] =
        "Good evening. \r\n"
        "The first sunrise of the\r\n"
        "year is beautiful here. {Press}";
};

void EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Anna(void)
{
    if (HasMetNpc(CHARACTER_ANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Anna);
    TalkClose();
    if (WasNpcSpokenToJustNow(CHARACTER_ANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ANNA);
    if ((VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE || WasNpcSpokenToJustNow(CHARACTER_CLIFF)) && WasNpcSpokenToJustNow(CHARACTER_DOUG) && WasNpcSpokenToJustNow(CHARACTER_ANNA) && WasNpcSpokenToJustNow(CHARACTER_BASIL) && WasNpcSpokenToJustNow(CHARACTER_MARY) && WasNpcSpokenToJustNow(CHARACTER_SAIBARA) && WasNpcSpokenToJustNow(CHARACTER_GRAY))
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        CallScript(EventScript_FestivalEvent_NewYearSunrise_FestivalOpening_Doug);
    }
    SetEntityFacing(ENTITY_ANNA, FACING_UP);
}
