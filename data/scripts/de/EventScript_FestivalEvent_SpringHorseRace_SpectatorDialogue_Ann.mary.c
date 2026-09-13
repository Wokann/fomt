#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann_HorsesFromYodelFarmAreRacing[] =
        "Pferde der Jodel-Farm\r\n"
        "machen auch mit. {Press}\p"
        "Dieses Jahr reitet \r\n"
        "jemand anderes, sonst \r\n"
        "war es Barley. {Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann_AnnCheersForTheRace[] =
        "Schwing die Hufe! {Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann(void)
{
    if (HasMetNpc(CHARACTER_ANN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ANN);
    }
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann_HorsesFromYodelFarmAreRacing);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann_AnnCheersForTheRace);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ANN) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ANN, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ANN);
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}
