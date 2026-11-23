#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1143_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai.mary.h"

void EventScript_1143_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai(void)
{
    if (HasMetNpc(CHARACTER_KAI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAI);
    }
    SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == TRUE)
    {
        if (VarGet(VAR_FRISBEE_TOURNAMENT_RESULT) == FESTIVAL_CONTEST_RESULT_NOT_WON)
        {
            SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAI);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_GoodTryButNoLuckThis);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAI);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_IWasWatchingAndYouWere);
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_ICantBelieveThatDogsCan);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_KAI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_KAI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_KAI);
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
}
