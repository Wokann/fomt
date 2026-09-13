#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_GoodTryButNoLuckThis[] =
        "よっ、残念だったな。\r\n"
        "そう、気を落とすなよ。\r\n"
        "来年もチャレンジしたら{Press}\r\n"
        "いいじゃん。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_IWasWatchingAndYouWere[] =
        "ちゃんと見ててやったぜ。\r\n"
        "優勝おめでと。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai_ICantBelieveThatDogsCan[] =
        "見てたか？スゲーよなー。\r\n"
        "犬ってあんなことも\r\n"
        "出来るんだな。{Press}";
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
