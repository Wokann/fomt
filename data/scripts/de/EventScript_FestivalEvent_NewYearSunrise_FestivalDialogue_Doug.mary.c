#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Doug[] =
        "Das Jahr ist so\r\n"
        "schnell vergangen!{Press}";
};

void EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Doug(void)
{
    if (HasMetNpc(CHARACTER_DOUG) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Doug);
    TalkClose();
    if (WasNpcSpokenToJustNow(CHARACTER_DOUG) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOUG, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DOUG);
    if ((VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE || WasNpcSpokenToJustNow(CHARACTER_CLIFF)) && WasNpcSpokenToJustNow(CHARACTER_DOUG) && WasNpcSpokenToJustNow(CHARACTER_ANNA) && WasNpcSpokenToJustNow(CHARACTER_BASIL) && WasNpcSpokenToJustNow(CHARACTER_MARY) && WasNpcSpokenToJustNow(CHARACTER_SAIBARA) && WasNpcSpokenToJustNow(CHARACTER_GRAY))
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        CallScript(EventScript_FestivalEvent_NewYearSunrise_FestivalOpening_Doug);
    }
    SetEntityFacing(ENTITY_DOUG, FACING_UP);
}
