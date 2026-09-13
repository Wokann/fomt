#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_NoPlayerEntryComment[] =
        "オレは毎年、\r\n"
        "フリスビー大会をはじめてから\r\n"
        "海開きが楽しみでな。{Press}\p"
        "出場する犬は、知っている犬\r\n"
        "ばっかりなんだよ。{Press}\p"
        "出荷業をやっているといろんな\r\n"
        "家に回るからな。\r\n"
        "どの犬が優勝しても{Press}\r\n"
        "うれしいもんだぜ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_EncouragesPlayerEntry[] =
        "優勝めざしてがんばれよ！{Press}";
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
