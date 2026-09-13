#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai_IWasWonderingWhatAllThe[] =
        "外がうるさいと思ったら、\r\n"
        "フリスビー大会か。{Press}\p"
        "犬がフリスビーを\r\n"
        "キャッチするんだよな。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai_YoureCompetingTooIllBeWatching[] =
        "おっ、エントリーしたんだ。\r\n"
        "見てやるから、がんばれよ。{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai(void)
{
    if (HasMetNpc(CHARACTER_KAI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAI);
    }
    SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai_IWasWonderingWhatAllThe);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai_YoureCompetingTooIllBeWatching);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_KAI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_KAI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_KAI);
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
}
