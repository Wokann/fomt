#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Cliff[] =
        "So much happened to me\r\n"
        "this past year. {Press}\p"
        "I feel like a new part\r\n"
        "of my life is beginning.{Press}";
};

void EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Cliff(void)
{
    if (HasMetNpc(CHARACTER_CLIFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CLIFF);
    }
    SetEntityFacing(ENTITY_CLIFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Cliff);
    TalkClose();
    if (WasNpcSpokenToJustNow(CHARACTER_CLIFF) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CLIFF, 5);
    }
    MarkNpcSpokenTo(CHARACTER_CLIFF);
    if ((VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE || WasNpcSpokenToJustNow(CHARACTER_CLIFF)) && WasNpcSpokenToJustNow(CHARACTER_DOUG) && WasNpcSpokenToJustNow(CHARACTER_ANNA) && WasNpcSpokenToJustNow(CHARACTER_BASIL) && WasNpcSpokenToJustNow(CHARACTER_MARY) && WasNpcSpokenToJustNow(CHARACTER_SAIBARA) && WasNpcSpokenToJustNow(CHARACTER_GRAY))
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        CallScript(EventScript_FestivalEvent_NewYearSunrise_FestivalOpening_Doug);
    }
    SetEntityFacing(ENTITY_CLIFF, FACING_UP);
}
