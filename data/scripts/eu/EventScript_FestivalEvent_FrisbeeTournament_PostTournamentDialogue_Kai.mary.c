#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_GoodTryButNoLuckThis[] =
        "Good try, but no luck \r\n"
        "this year. {Press}\r\n"
        "Don't be too hard on \r\n"
        "yourself. {Press}\r\n"
        "There's always next year!{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_IWasWatchingAndYouWere[] =
        "I was watching, and\r\n"
        "you were fabulous! \r\n"
        "Congratulations! {Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_ICantBelieveThatDogsCan[] =
        "I can't believe that dogs\r\n"
        "can do such amazing things!{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai(void)
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
