#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_DontGetTooUpsetTheresAlways[] =
        "Don't get too upset.\r\n"
        "There's always next year!{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_GreatJobYouMustHavePracticed[] =
        "Great job! You must have\r\n"
        "practiced a lot! I look\r\n"
        "forward to seeing you {Press}\r\n"
        "next year, too! {Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack_TheTournamentIsAlwaysSoFun[] =
        "The Tournament is always so\r\n"
        "fun to watch. Come out\r\n"
        "next year, too! {Press}";
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
