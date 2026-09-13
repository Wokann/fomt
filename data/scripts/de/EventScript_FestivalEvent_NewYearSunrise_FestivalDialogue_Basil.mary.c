#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Basil[] =
        "Ich weiß nicht, wie es\r\n"
        "bei dir ist, aber ich hatte \r\n"
        "ein tolles Jahr.{Press}";
};

void EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Basil(void)
{
    if (HasMetNpc(CHARACTER_BASIL) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BASIL);
    }
    SetEntityFacing(ENTITY_BASIL, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_FestivalEvent_NewYearSunrise_FestivalDialogue_Basil);
    TalkClose();
    if (WasNpcSpokenToJustNow(CHARACTER_BASIL) == FALSE)
    {
        AddNpcFriendship(CHARACTER_BASIL, 5);
    }
    MarkNpcSpokenTo(CHARACTER_BASIL);
    if ((VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE || WasNpcSpokenToJustNow(CHARACTER_CLIFF)) && WasNpcSpokenToJustNow(CHARACTER_DOUG) && WasNpcSpokenToJustNow(CHARACTER_ANNA) && WasNpcSpokenToJustNow(CHARACTER_BASIL) && WasNpcSpokenToJustNow(CHARACTER_MARY) && WasNpcSpokenToJustNow(CHARACTER_SAIBARA) && WasNpcSpokenToJustNow(CHARACTER_GRAY))
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        CallScript(EventScript_FestivalEvent_NewYearSunrise_FestivalOpening_Doug);
    }
    SetEntityFacing(ENTITY_BASIL, FACING_UP);
}
