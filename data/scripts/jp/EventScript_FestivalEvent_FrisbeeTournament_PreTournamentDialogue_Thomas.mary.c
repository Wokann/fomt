#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas_NoPlayerEntryComment[] =
        "この祭りは昔から好きでね。\r\n"
        "犬がフリスビーを\r\n"
        "一生懸命追いかける姿が{Press}\r\n"
        "かわいいんだよ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas_EncouragesPlayerEntry[] =
        "おおっ、出場するんだね？\r\n"
        "応援しているよ。\r\n"
        "がんばってくれ。{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas_NoPlayerEntryComment);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas_EncouragesPlayerEntry);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
}
