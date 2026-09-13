#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FireworksFestival_Dialogue_Cliff[] =
        "ボクの住んでいた町も、\r\n"
        "夏に花火してたよ。{Press}\p"
        "あれ、もしかして同じのを\r\n"
        "見てたのかなぁ？{Press}";
};

void EventScript_FestivalEvent_FireworksFestival_Dialogue_Cliff(void)
{
    if (HasMetNpc(CHARACTER_CLIFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CLIFF);
    }
    SetEntityFacing(ENTITY_CLIFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_FestivalEvent_FireworksFestival_Dialogue_Cliff);
    TalkClose();
    if (WasNpcSpokenToJustNow(CHARACTER_CLIFF) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CLIFF, 5);
    }
    MarkNpcSpokenTo(CHARACTER_CLIFF);
    if (WasNpcSpokenToJustNow(CHARACTER_RICK) && WasNpcSpokenToJustNow(CHARACTER_GRAY) && WasNpcSpokenToJustNow(CHARACTER_DOCTOR) && (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE || WasNpcSpokenToJustNow(CHARACTER_CLIFF)) && WasNpcSpokenToJustNow(CHARACTER_KAI) && WasNpcSpokenToJustNow(CHARACTER_KAREN) && WasNpcSpokenToJustNow(CHARACTER_ELLI) && WasNpcSpokenToJustNow(CHARACTER_ANN) && WasNpcSpokenToJustNow(CHARACTER_POPURI) && WasNpcSpokenToJustNow(CHARACTER_MARY))
    {
        VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_NONE);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        CallScript(EventScript_FestivalEvent_FireworksFestival_PostFestivalDialogue);
    }
    SetEntityFacing(ENTITY_CLIFF, FACING_RIGHT);
}
