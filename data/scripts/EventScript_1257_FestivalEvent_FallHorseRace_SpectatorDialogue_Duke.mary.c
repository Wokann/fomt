#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1257_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke.mary.h"

void EventScript_1257_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke(void)
{
    if (HasMetNpc(CHARACTER_DUKE) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DUKE);
    }
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke_HaveYouPlacedYourBetWith);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke_IllBeBettingOnYouSo);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DUKE) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DUKE, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
}
