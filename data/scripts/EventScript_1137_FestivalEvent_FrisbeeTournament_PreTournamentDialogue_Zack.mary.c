#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1137_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack.mary.h"

void EventScript_1137_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_NoPlayerEntryComment);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_EncouragesPlayerEntry);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ZACK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ZACK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
}
