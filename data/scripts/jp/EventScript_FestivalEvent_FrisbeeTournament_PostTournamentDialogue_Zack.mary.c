#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_DontGetTooUpsetTheresAlways[] =
        "気を落とすなよ。\r\n"
        "また、来年出場してくれ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_GreatJobYouMustHavePracticed[] =
        "よかったなぁ。\r\n"
        "相当、練習したんだろ？\r\n"
        "来年も出ろよ！{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_TheTournamentIsAlwaysSoFun[] =
        "今年も、盛り上がったぜー。\r\n"
        "来年は出場しろよ！{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == TRUE)
    {
        if (VarGet(VAR_FRISBEE_TOURNAMENT_RESULT) == FESTIVAL_CONTEST_RESULT_NOT_WON)
        {
            SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_DontGetTooUpsetTheresAlways);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_GreatJobYouMustHavePracticed);
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_TheTournamentIsAlwaysSoFun);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ZACK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ZACK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
}
