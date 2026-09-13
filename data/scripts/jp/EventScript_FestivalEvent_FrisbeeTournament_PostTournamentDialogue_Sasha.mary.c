#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_DontGetTooUpsetImSure[] =
        "残念だったねぇ。がんばれば、\r\n"
        "きっと来年優勝できるさ。\r\n"
        "そんなに落ち込むんじゃ{Press}\r\n"
        "ないよ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_ImSoImpressedThatYouWon[] =
        "優勝なんて、すごいわね。\r\n"
        "自分のことみたいに\r\n"
        "うれしいよ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_IHadntRealizedHowSmartDogs[] =
        "やっぱり、犬ってかしこいわ。\r\n"
        "真剣に飼うこと\r\n"
        "考えようかしら…{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == TRUE)
    {
        if (VarGet(VAR_FRISBEE_TOURNAMENT_RESULT) == FESTIVAL_CONTEST_RESULT_NOT_WON)
        {
            SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_DontGetTooUpsetImSure);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_ImSoImpressedThatYouWon);
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_IHadntRealizedHowSmartDogs);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SASHA);
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
}
