#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_DontGetTooUpsetImSure[] =
        "Don't get too upset!\r\n"
        "I'm sure if you practice\r\n"
        "harder you can win {Press}\r\n"
        "next year. {Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_ImSoImpressedThatYouWon[] =
        "I'm so impressed that\r\n"
        "you won! Good job!{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha_IHadntRealizedHowSmartDogs[] =
        "I hadn't realized how smart\r\n"
        "Dogs are! Now I want one\r\n"
        "of my own...{Press}";
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
