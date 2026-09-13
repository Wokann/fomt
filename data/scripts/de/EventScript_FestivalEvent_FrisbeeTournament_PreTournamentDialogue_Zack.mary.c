#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_NoPlayerEntryComment[] =
        "Ich freue mich auf den\r\n"
        "Strandtag, umso mehr seit\r\n"
        "es das Frisbeeturnier {Press}\r\n"
        "gibt. Von meinen \r\n"
        "Runden kenne ich \r\n"
        "alle Hunde. {Press}\p"
        "Ich freue mich, wer \r\n"
        "immer auch gewinnt!{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_EncouragesPlayerEntry[] =
        "Viel Glück an alle \r\n"
        "Teilnehmer! {Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack(void)
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
