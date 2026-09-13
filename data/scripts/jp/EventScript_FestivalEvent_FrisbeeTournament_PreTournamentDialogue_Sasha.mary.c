#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha_ICantBelieveDogsCanLearn[] =
        "犬ってかしこいわよね。\r\n"
        "ちゃんと訓練すれば、\r\n"
        "色々なことが{Press}\r\n"
        "出来るみたいだし…\r\n"
        "うちも犬を飼ってみようかね。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha_GoodLuckPlayer[] =
        "出場するんだってね。\r\n"
        "がんばるんだよ！{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha_ICantBelieveDogsCanLearn);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha_GoodLuckPlayer);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SASHA);
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
}
