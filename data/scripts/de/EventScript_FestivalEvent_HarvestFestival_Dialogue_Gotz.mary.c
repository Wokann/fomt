#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Gotz_ItDoesntMatterWhatItTastes[] =
        "Egal, wie es \r\n"
        "schmeckt! {Press}\p"
        "Es nicht zu essen, wäre\r\n"
        "Verschwendung. {Press}\p"
        "Hast du aufgegessen, \r\n"
        "{Player}? {Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Gotz_NowThatImStuffedIveGot[] =
        "Jetzt, wo ich satt bin,\r\n"
        "muss ich wieder \r\n"
        "an die Arbeit. {Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Gotz(void)
{
    if (HasMetNpc(CHARACTER_GOTZ) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOTZ);
    }
    SetEntityFacing(ENTITY_GOTZ, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_GOTZ) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOTZ, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Gotz_ItDoesntMatterWhatItTastes);
        TalkClose();
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Gotz_NowThatImStuffedIveGot);
        TalkClose();
    }
    MarkNpcSpokenTo(CHARACTER_GOTZ);
    SetEntityFacing(ENTITY_GOTZ, FACING_LEFT);
}
