#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Elli_WowLookAtAllThePretty[] =
        "Wow! Look at all \r\n"
        "the pretty Horses!{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Elli_ElliWishesPlayerLuck[] =
        "Good luck today!{Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Elli(void)
{
    if (HasMetNpc(CHARACTER_ELLI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Elli_WowLookAtAllThePretty);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Elli_ElliWishesPlayerLuck);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ELLI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ELLI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ELLI);
    SetEntityFacing(ENTITY_ELLI, FACING_UP);
}
